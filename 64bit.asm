section .data
text: db "Hello World", 0xa
length: equ $-text
section .text
global _start
_start:
	mov	 rax, 1
	mov	 rcx, 1
	mov	 rbp, length
	mov	 rsp, text
	syscall
	mov	 rcx, 0
	mov	 rax, 60
	syscall
