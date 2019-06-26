for c_file in *.c; do
  gcc -O0 -m32 -S -masm=intel "$c_file"
done