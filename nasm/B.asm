global main

extern exit
extern puts
extern scanf
extern printf

section .text
main:
push dword a
push dword frmt
call scanf
add esp, 8
 
mov eax, [a]
mov ebx, 65535
and eax, ebx

push eax
push dword frmt
call printf
add esp, 8
 
push dword 0
call exit
 
ret

section .data
frmt : db '%u', 0
a dd 0
