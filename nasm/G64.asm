section .data
fmt_printf    :   db "%s", 0
msg_NO    :   db "NO", 0
msg_YES    :   db "YES", 0
fmt_scanf    :   db "%llu", 0  
var1   :   dq  0
var2   :   dq  0

global main
extern exit
extern puts
extern scanf
extern printf

section .text
main
    push rbp

    lea rdi, [fmt_scanf]
    lea rsi, [var1]
    ;lea rsi, [var2]
    xor rax, rax 
    call scanf

    lea rdi, [fmt_scanf]
    lea rsi, [var2]
    xor rax, rax
    call scanf

    mov rcx, [var1]
    mov rbx, [var2]
    add rcx, rbx

    jc label_perepol
    mov rdi, fmt_printf
    mov rsi, msg_NO
    jmp label_printf

label_perepol:
    mov rdi, fmt_printf
    mov rsi, msg_YES

label_printf:
    xor rax, rax
    call printf

    pop rbp

    xor rax, rax
    ret
