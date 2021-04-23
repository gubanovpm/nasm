extern printf
extern scanf

section .data
fmt_printf   :   db "%lld ", 0
;fmt_printf2  :   db "----------", 10, 0
fmt_scanf    :   db "%lld",  0
N : dq 0
i : dq 0
;array : dq -2, -3, 4, 5, -1


section .bss
array : resq 64

section .text
    global main
main:
    push rbp

    ; Ввод кол-ичества элементов
    lea rdi, [fmt_scanf]
    lea rsi, [N] ; N
    xor rax, rax
    call scanf

    ; Считывание элеметов массива
    xor rbx, rbx
loop_scanf: 

    lea rdi, [fmt_scanf]
    lea rsi, [array + rbx*8]
    xor rax, rax
    call scanf

    add rbx, 1
    cmp rbx, [N]
    jne loop_scanf
    ; Вышли из цикла
    
    ; Сортировка
    xor rbx, rbx
loop_sotr_outer:
    mov [i], rbx
    xor rbx, rbx

    xor r8, r8
    xor r9, r9
        
    loop_sort_inside:
        mov r8, [N]
        sub r8, [i]
        sub r8, 1
        cmp rbx, r8
        jge L_end   ; for (j = 0; j < n - i - 1; j++)
        
        mov r8, [array + rbx*8]     ; r8 = a[j]
        mov r9, [array + rbx*8 + 8] ; r9 = a[j + 1]
        cmp r8, r9 ; if(a[j] > a[j + 1])
        jle L_litle

        mov [array + rbx*8 + 8], r8 ; a[j + 1] = a[j]
        mov r8, r9  ; r8 = a[j + 1]
        mov [array + rbx*8], r8 ; a[j] = a[j + 1]
        
    L_litle:
        add rbx, 1
        jmp loop_sort_inside
L_end:
    mov rbx, [i]
    add rbx, 1
    mov r8, [N]
    sub r8, 1
    cmp rbx, r8
    jne loop_sotr_outer

    ; Вывод элеметов
    xor rbx, rbx

loop_printf:

    lea rdi, [fmt_printf]
    mov rsi, [array + rbx*8]
    xor rax, rax
    call printf

    add rbx, 1
    cmp rbx, [N]
    jne loop_printf
    ; Вышли из цикла


    pop rbp
    xor rax, rax
    ret