section .text
global _start

extern println
extern create_student
extern free_student
extern perform_asm_tests
extern is_palindrome
extern to_string
extern is_anagram

extern strcpy
extern snprintf

; Macro to check status of boolean 1 or 0 value and print results with println function
; @param #1 --> register or memory location to check status
; @param #2 --> name identifying the thing which the status is being checked for
; @param #3 --> success message, should be a string of ascii chars
; @param #4 --> failure message, should be a string of ascii chars
%macro print_success_fail 4
  cmp %1, 1          
  je .print_is_%2
  jmp .print_not_%2

.print_is_%2:
  push %3
  call println
  jmp .past_print_%2
.print_not_%2:
  push %4
  call println
.past_print_%2:
%endmacro

_test_to_string:
	push ebp
	mov ebp, esp

	push 2
	push 765
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

  print_success_fail eax, palindrome, SUCCESS, FAIL

  push anagram_test2
  push anagram_test1
  call is_anagram

  print_success_fail eax, anagram, anagram_msg_success, anagram_msg_fail


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
anagram_msg_success: db 'The strings are anagrams', 0, 0xa
anagram_msg_fail: db 'The strings are not anagrams', 0, 0xa
buf: times 64 db 0
format: db '%d', 0
anagram_test1: db 'Listen', 0
anagram_test2: db 'siLeNt', 0