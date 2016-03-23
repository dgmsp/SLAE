original.nasm

global _start
section .text
_start:

xor eax,eax
mov al,0x4

xor ebx,ebx
mov bl,0x1

xor edx,edx
push edx

push 0x0a202020
push 0x54454e2e
push 0x45425554
push 0x59544952
push 0x55434553
push 0x2e575757

mov ecx,esp
mov dl,0x18   
int 0x80

xor eax,eax
mov al,0x1

int 0x80
