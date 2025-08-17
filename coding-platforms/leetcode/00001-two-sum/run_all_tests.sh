#!/bin/bash
set -e

TEST_FILE="test.cpp"
OUT_DIR="./bin"
CXX="${CXX:-g++}"

mkdir -p "$OUT_DIR"

# Globals set by find_gtest
GTEST_INCLUDE_DIR=""
GTEST_LIB_DIR=""
GTEST_LIB_FILES=()   # full paths to .a/.so/.dylib if found
GTEST_LIB_FLAGS=()   # -L/-l fallback if needed

# helper: add lib file if it exists
add_lib_file() {
  local dir="$1" base="$2"
  for ext in .a .dylib .so; do
    if [ -f "$dir/lib${base}${ext}" ]; then
      GTEST_LIB_FILES+=("$dir/lib${base}${ext}")
      return 0
    fi
  done
  return 1
}

# try to populate GTEST_INCLUDE_DIR + GTEST_LIB_DIR + GTEST_LIB_FILES/GTEST_LIB_FLAGS
find_gtest() {
  # 0) If user provides a root, use it
  if [ -n "$GTEST_ROOT" ]; then
    local prefix="$GTEST_ROOT"
    if [ -d "$prefix/include/gtest" ] && [ -d "$prefix/lib" ]; then
      GTEST_INCLUDE_DIR="$prefix/include"
      GTEST_LIB_DIR="$prefix/lib"
    fi
  fi

  # 1) pkg-config (works on some distros)
  if [ -z "$GTEST_INCLUDE_DIR" ] && command -v pkg-config >/dev/null 2>&1; then
    if pkg-config --exists gtest 2>/dev/null; then
      # gtest cflags/libs
      local cf; cf=$(pkg-config --cflags gtest 2>/dev/null || true)
      local lf; lf=$(pkg-config --libs gtest 2>/dev/null || true)
      # try gmock too (optional)
      if pkg-config --exists gmock 2>/dev/null; then
        cf+=" $(pkg-config --cflags gmock 2>/dev/null || true)"
        lf+=" $(pkg-config --libs gmock 2>/dev/null || true)"
      fi
      # Derive include dir from cflags if possible
      for tok in $cf; do
        case "$tok" in
          -I*) cand="${tok#-I}"; if [ -d "$cand/gtest" ]; then GTEST_INCLUDE_DIR="$cand"; fi ;;
        esac
      done
      # Try to extract a -L path for libdir
      for tok in $lf; do
        case "$tok" in
          -L*) GTEST_LIB_DIR="${tok#-L}"; break ;;
        esac
      done
      if [ -n "$GTEST_INCLUDE_DIR" ] && [ -n "$GTEST_LIB_DIR" ]; then
        GTEST_LIB_FLAGS=($lf -pthread)
        echo "📦 Found GoogleTest via pkg-config"
        echo "--------------------------"
        return 0
      fi
    fi
  fi

  # 2) Homebrew (preferred exact match of include ↔ lib)
  try_brew() {
    if command -v brew >/dev/null 2>&1; then
      local bp; bp=$(brew --prefix googletest 2>/dev/null || true)
      if [ -n "$bp" ] && [ -d "$bp/include/gtest" ] && [ -d "$bp/lib" ]; then
        GTEST_INCLUDE_DIR="$bp/include"
        GTEST_LIB_DIR="$bp/lib"
      fi
    fi
  }
  [ -z "$GTEST_INCLUDE_DIR" ] && try_brew

  # 3) Scan common Cellar/roots (Intel + Apple Silicon), then MacPorts, vcpkg
  scan_roots() {
    local roots=(
      /usr/local/Cellar/googletest
      /opt/homebrew/Cellar/googletest
      /usr/local
      /usr
      /opt/local
      /opt
    )
    for r in "${roots[@]}"; do
      [ -d "$r" ] || continue
      # Prefer Cellar exact matches
      if [[ "$r" == *Cellar/googletest* ]]; then
        # choose latest version if multiple
        local latest=""
        if [ -d "$r" ] && ls -1d "$r"/* >/dev/null 2>&1; then
          latest=$(ls -1d "$r"/* 2>/dev/null | sort -V | tail -n1)
        fi
        local prefix="${latest:-$r}"
        if [ -d "$prefix/include/gtest" ] && [ -d "$prefix/lib" ]; then
          GTEST_INCLUDE_DIR="$prefix/include"
          GTEST_LIB_DIR="$prefix/lib"
          return 0
        fi
      fi
      # Generic check
      if [ -z "$GTEST_INCLUDE_DIR" ] && [ -d "$r/include/gtest" ]; then
        # derive a close lib dir
        local p="$(dirname "$(dirname "$r/include/gtest")")"
        if [ -d "$p/lib" ]; then
          GTEST_INCLUDE_DIR="$p/include"
          GTEST_LIB_DIR="$p/lib"
          return 0
        fi
      fi
    done
    return 1
  }
  [ -z "$GTEST_INCLUDE_DIR" ] && scan_roots >/dev/null 2>&1 || true

  # 4) vcpkg (env var)
  if [ -z "$GTEST_INCLUDE_DIR" ] && [ -n "$VCPKG_ROOT" ] && [ -d "$VCPKG_ROOT" ]; then
    # pick first installed triplet with gtest
    local inc; inc=$(find "$VCPKG_ROOT/installed" -maxdepth 2 -type d -path "*/include/gtest" 2>/dev/null | head -n1)
    if [ -n "$inc" ]; then
      GTEST_INCLUDE_DIR="$(dirname "$inc")"
      GTEST_LIB_DIR="$(echo "$inc" | sed 's/\/include\/gtest$/\/lib/')"
    fi
  fi

  # 5) System libdirs if we at least saw includes somewhere
  if [ -z "$GTEST_LIB_DIR" ] && [ -n "$GTEST_INCLUDE_DIR" ]; then
    for d in \
      "$(dirname "$(dirname "$GTEST_INCLUDE_DIR")")/lib" \
      /usr/local/lib /usr/lib /usr/lib64 /usr/lib/x86_64-linux-gnu /opt/local/lib; do
      if [ -d "$d" ]; then GTEST_LIB_DIR="$d"; break; fi
    done
  fi

  # If still nothing usable, fail
  if [ -z "$GTEST_INCLUDE_DIR" ] || [ -z "$GTEST_LIB_DIR" ]; then
    return 1
  fi

  # Ignore false positives from Python site-packages
  case "$GTEST_INCLUDE_DIR" in
    *site-packages*|*dist-packages*)
      return 1
    ;;
  esac

  # Prefer explicit archives if available (best on macOS/Homebrew)
  GTEST_LIB_FILES=()
  add_lib_file "$GTEST_LIB_DIR" gmock       || true
  add_lib_file "$GTEST_LIB_DIR" gtest       || true
  # Choose one *_main if available (prefer gtest_main)
  add_lib_file "$GTEST_LIB_DIR" gtest_main  || add_lib_file "$GTEST_LIB_DIR" gmock_main || true

  if [ "${#GTEST_LIB_FILES[@]}" -gt 0 ]; then
    return 0
  fi

  # Fallback to -L/-l flags
  GTEST_LIB_FLAGS=(-L"$GTEST_LIB_DIR" -lgmock -lgtest -lgtest_main)
  return 0
}

if ! find_gtest; then
  echo "❌ GoogleTest not found."
  echo "👉 Please install it (e.g. 'brew install googletest' or 'sudo apt install libgtest-dev')."
  echo "   On macOS/Homebrew (Intel path like yours): /usr/local/Cellar/googletest/<ver>/{include,lib}"
  exit 1
fi

echo "✅ Using:"
echo "   include: $GTEST_INCLUDE_DIR"
echo "   libdir : $GTEST_LIB_DIR"
if [ "${#GTEST_LIB_FILES[@]}" -gt 0 ]; then
  echo "   libs   :"
  for f in "${GTEST_LIB_FILES[@]}"; do echo "            $f"; done
else
  echo "   flags  : ${GTEST_LIB_FLAGS[*]}"
fi
echo "--------------------------"

CXXFLAGS=(-std=c++17 -I"$GTEST_INCLUDE_DIR")
LDFLAGS=(-pthread)
if [ "${#GTEST_LIB_FILES[@]}" -gt 0 ]; then
  LDFLAGS+=("${GTEST_LIB_FILES[@]}")
else
  LDFLAGS+=("${GTEST_LIB_FLAGS[@]}")
fi

# Build + run every solution
shopt -s nullglob
for SOL in sol*.cpp; do
  BASENAME="${SOL%.cpp}"
  OUT="$OUT_DIR/$BASENAME"

  echo "🛠️  Compiling $SOL + $TEST_FILE → $OUT"
  set -x
  "$CXX" "${CXXFLAGS[@]}" "$SOL" "$TEST_FILE" -o "$OUT" "${LDFLAGS[@]}"
  { set +x; } 2>/dev/null

  echo "--------------------------"
  echo "🚀 Running tests for $BASENAME"
  "$OUT"
  echo "✅ Done with $BASENAME"
  echo "===================================================="
done

# #!/bin/bash

# set -e

# TEST_FILE="test.cpp"
# OUT_DIR="./bin"

# # Paths to GTest (adjust if needed)
# GTEST_INCLUDE="/usr/local/Cellar/googletest/1.17.0/include"
# GTEST_LIB="/usr/local/Cellar/googletest/1.17.0/lib"

# mkdir -p "$OUT_DIR"

# # Loop over each solution file
# for SOL in sol*.cpp; do
#     [ -e "$SOL" ] || continue  # Skip if no match

#     BASENAME="${SOL%.cpp}"
#     OUT="$OUT_DIR/$BASENAME"

#     echo "🛠️  Compiling $SOL + $TEST_FILE → $OUT"
#     g++ -std=c++17 "$SOL" "$TEST_FILE" \
#         -I"$GTEST_INCLUDE" \
#         -L"$GTEST_LIB" -lgmock -lgtest_main -lgtest -pthread \
#         -o "$OUT"

#     echo "🚀 Running tests for $BASENAME"
#     "$OUT"
#     echo "✅ Done with $BASENAME"
#     echo "--------------------------"
# done
