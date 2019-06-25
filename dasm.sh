for c_file in *.c; do
  gcc -m32 -S -masm=intel "$c_file"
done