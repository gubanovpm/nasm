extern printf
extern scanf

section .data
fmt_printf   :   db "%d ", 0
fmt_scanf    :   db "%d",  0
N : dq 0
i : dq 0

section .bss
array1 : resq 64
array2 : resq 64

section .text
    global main
main:
    push rbp

    ; Ввод количества элементов
;    lea rdi, [fmt_scanf]
;    lea rsi, [N] ; N
;    xor rax, rax
;    call scanf
	
	mov rbx, 8
	mov [N], rbx

    ; Считывание элеметов первого массива
    xor rbx, rbx
loop_scanf_1: 

    lea rdi, [fmt_scanf]
    lea rsi, [array1 + 8 * rbx]
    xor rax, rax
    call scanf

    add rbx, 1
    cmp rbx, [N]
    jne loop_scanf_1
    ; конец считывания первого массива
	; Считывание элеметов второго массива
    xor rbx, rbx
loop_scanf_2: 

    lea rdi, [fmt_scanf]
    lea rsi, [array2 + 8 * rbx]
    xor rax, rax
    call scanf

    add rbx, 1
    cmp rbx, [N]
    jne loop_scanf_2
    ; конец считывания второго массива
	
    ; Сумма
    xor rbx, rbx
	
loop_sum:
	mov rsi, [array1 + 8 * rbx]
	mov rdi, [array2 + 8 * rbx]
	add rsi, rdi
	
	cmp rsi, 127
	jl	next_it
	
	mov rsi, 127
	
next_it:
	mov [array1 + 8 * rbx], rsi
	inc rbx
	cmp rbx, [N]
	jne loop_sum

    ; Вывод элеметов
    xor rbx, rbx

loop_printf:

    lea rdi, [fmt_printf]
    mov rsi, [array1 + 8 * rbx]
    xor rax, rax
    call printf

    add rbx, 1
    cmp rbx, [N]
    jne loop_printf
    ; Вышли из цикла


    pop rbp
    xor rax, rax
    ret
