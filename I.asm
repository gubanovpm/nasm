extern printf
extern scanf

section .data
fmt_printf : db "%d ", 0
fmt_scanf : db "%d", 0
N : dq 0
i : dq 0

section .bss
a : resb 64


section .text
    global main
main:
    push rbp

    lea rdi, [fmt_scanf]
    lea rsi, [N]
    xor rax, rax
    call scanf
    
    mov rbx, 0
    mov [i], rbx

loop_scanf:
    mov rdx, [N]
    cmp [i], rdx
    je loop_printf
    
    lea rdi, [fmt_scanf]
    lea rsi, [a + rbx*8]
    xor rax, rax
    call scanf

    mov rbx, [i]
    add rbx, 1
    mov [i], rbx
    jmp loop_scanf
loop_printf:
    mov rdx, 0
    ;lea rdi, [fmt_printf]
    ;mov rsi, [i]
    ;xor rax, rax
    ;call printf
    cmp [i], rdx
    je loop_end

    lea rdi, [fmt_printf]
    mov rsi, [a + rbx*8 - 8]
    xor rax, rax
    call printf

    mov rbx, [i]
    sub rbx, 1
    mov [i], rbx
    jmp loop_printf
loop_end:
    pop rbp
    xor rax, rax
    ret