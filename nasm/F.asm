global main

extern exit
extern puts
extern scanf
extern printf

section .text
main
push dword b
push dword a
push dword msg1
call scanf
add esp, 12
 
mov eax, [a]
mov ebx, [b]
cmp eax, ebx
jle L1
mov eax, ebx

L1:
push eax
push dword msg2
call printf
add esp, 8
 
push dword 0
call exit
 
ret

section .data
msg1 : db '%d%d', 0
msg2 : db '%d', 0
 
a dd 0
b dd 0
