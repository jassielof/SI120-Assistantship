#!/bin/bash

set -e

# Find all .cpp files
FILES=$(find actividades -name "*.cpp")
echo "Found $(echo "$FILES" | wc -l) files"

# Create a compilation commands file
> compile_commands.txt
for file in $FILES; do
  echo "clang++ -O2 -o /dev/null $file" >> compile_commands.txt
done

# Compile all files in parallel
batcat compile_commands.txt | parallel -j$(nproc)

rm compile_commands.txt
