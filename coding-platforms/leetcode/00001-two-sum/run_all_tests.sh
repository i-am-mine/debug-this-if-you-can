#!/bin/bash

set -e

TEST_FILE="test.cpp"
OUT_DIR="./bin"

# Paths to GTest (adjust if needed)
GTEST_INCLUDE="/usr/local/Cellar/googletest/1.17.0/include"
GTEST_LIB="/usr/local/Cellar/googletest/1.17.0/lib"

mkdir -p "$OUT_DIR"

# Loop over each solution file
for SOL in sol*.cpp; do
    [ -e "$SOL" ] || continue  # Skip if no match

    BASENAME="${SOL%.cpp}"
    OUT="$OUT_DIR/$BASENAME"

    echo "🛠️  Compiling $SOL + $TEST_FILE → $OUT"
    g++ -std=c++17 "$SOL" "$TEST_FILE" \
        -I"$GTEST_INCLUDE" \
        -L"$GTEST_LIB" -lgmock -lgtest_main -lgtest -pthread \
        -o "$OUT"

    echo "🚀 Running tests for $BASENAME"
    "$OUT"
    echo "✅ Done with $BASENAME"
    echo "--------------------------"
done
