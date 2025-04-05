FILES=$(find actividades -name "*.cpp")
echo "Found $(echo "$FILES" | wc -l) files"

> compile_commands.txt
for file in $FILES; do
  echo "clang++ -O2 -o /dev/null $file" >> compile_commands.txt
done

# Compile all files in parallel
cat compile_commands.txt | parallel -j$(nproc)

rm compile_commands.txt
