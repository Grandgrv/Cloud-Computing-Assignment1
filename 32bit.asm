section .data
text db "Hello World", 0xa
length equ $-text
section .text
global _start
_start:
mov eax, 4
mov ebx, 1
mov edx, length
mov ecx, text
int 80h
mov ebx, 0
mov eax, 1
int 80h
