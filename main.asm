section .text
global _start

extern println
extern create_student
extern free_student

extern strcpy

_start:
  push ebp
  mov ebp, esp

  sub esp, 0x0b

  push MSG
  call println

  push addr
  push name
  push 0
  call create_student

  mov DWORD [ebp - 4], eax
  add eax, 4
  mov DWORD [ebp - 8], eax
  add eax, 64
  mov DWORD [ebp - 12], eax

  push DWORD [ebp - 8]
  call println

  push DWORD [ebp - 12]
  call println

  push DWORD [ebp - 4]
  call free_student

  mov esp, ebp
  pop ebp

  mov eax, 1
  mov ebx, 0
  int 0x80


section .data
MSG: db 'Hello, World!', 0, 0xa
name: db 'Mitch', 0
addr: db '2065 South State Road 3', 0
mitch: times 132 db 0