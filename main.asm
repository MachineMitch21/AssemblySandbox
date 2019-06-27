section .text
global _start

extern println
extern create_student
extern free_student
extern perform_asm_tests
extern is_palindrome
extern to_string

extern strcpy
extern snprintf

_test_to_string:
	push ebp
	mov ebp, esp

	push 10
	push 1543
	push buf
	call to_string

	push buf
	call println

	mov esp, ebp
	pop ebp
	ret

_start:
  push ebp
  mov ebp, esp

  sub esp, 0x0b	;	12

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

  push PALINDROME
  call is_palindrome

  ; push eax
  ; push format
  ; push 64
  ; push buf
  ; call snprintf
  ; push buf
  ; call println
  cmp eax, 1          ; did our is_palindrome function find the PALINDROME str to be a palindrome??
  jmp .print_is_palindrom
  jmp .print_not_palindrome

.print_is_palindrom:
  push SUCCESS
  call println
  jmp .past_print_palindrome
.print_not_palindrome:
  push FAIL
  call println
.past_print_palindrome:

	call _test_to_string

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
PALINDROME: db 'hANnAh', 0
SUCCESS: db 'The string is a palindrome', 0, 0xa
FAIL: db 'The string is not a palindrome', 0, 0xa
buf: times 64 db 0
format: db '%d', 0