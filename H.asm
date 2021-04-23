;default rel
extern printf
extern scanf

section .data
fmt_printf :   db "%d", 10, 0
fmt_scanf  :   db "%d%d", 0
num1 : dq 0
num2 : dq 0

section .text
    global main
main:
    push rbp

    lea rdi, [fmt_scanf]
    lea rsi, [num1]
    lea rdx, [num2]
    xor rax, rax 
    call scanf

    pop rbp
    
    mov rbx, [num1]
    mov rcx, [num2]
    xor rax, rax
    cmp rbx, 0
    je label_printf
    cmp rcx, 0
    je label_printf

ewklid:
    cmp rbx, rcx
    je label_exit
    jg label_big
    mov r8, rcx
    mov rcx, rbx
    mov rbx, r8
label_big:
    sub rbx,rcx
    jmp ewklid
label_exit:
    mov rax, [num1]
    mov rcx, [num2]
    imul rcx
    cdq
    idiv rbx
label_printf:
    push rbp
    lea rdi, [fmt_printf]
    mov rsi, rax
    xor rax, rax
    call printf

    pop rbp    

    xor rax, rax
    ret