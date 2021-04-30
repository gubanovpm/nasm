global main

extern exit
extern puts
extern scanf
extern printf

section .text

main:

push dword b
push dword a
push dword msg1
call scanf
add esp, 12

fld dword [a]
fld dword [b]
fdivp

fstp qword[c]

push dword [c+4]
push dword [c]

push dword msg2
call printf
add esp, 12

push dword 0
call exit

ret

section .data
msg1 : db "%f%f",0
msg2 : db "%f",0xA, 0

section .bss
a resd 1
b resd 1
c resd 1
