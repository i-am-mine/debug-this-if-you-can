#!/bin/bash

files=(
"100000 1000 arrays_100k.bin"
"1000000 50000 arrays_1M.bin"
"10000000 300000 arrays_10M.bin"
"100000000 6000000 arrays_100M.bin"
)

# Compile once
g++ -std=c++17 -O2 -o generate_binary generate_binary.cpp

for spec in "${files[@]}"; do
    read -r n k filename <<< "$spec"

    # Estimate size: (8+8) + n*4*2 bytes
    size_bytes=$((16 + n*4*2))
    if [ $size_bytes -ge $((1024*1024*1024)) ]; then
        size_hr=$(echo "scale=2; $size_bytes/1024/1024/1024" | bc)
        unit="GB"
    else
        size_hr=$(echo "scale=2; $size_bytes/1024/1024" | bc)
        unit="MB"
    fi

    echo "You are about to create binary file '$filename' with n=$n, k=$k, estimated size ~$size_hr $unit"
    read -p "Do you want to continue? (y/n): " ans
    if [[ "$ans" == "y" || "$ans" == "Y" ]]; then
        ./generate_binary "$n" "$k" "$filename"
    else
        echo "Skipping $filename"
    fi
done
