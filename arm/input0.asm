.data
msg:
    .byte 0,0,0,0,0,0,0,0,0,0
    len =  10
    len_1 = 0
.text
.global _start
_start:
    /* read */
    mov x0, #0
    mov x2, #10
    ldr x1, =msg
    mov x8, #63
    svc #0

    /* our len */
    mov x3, #0
mark_1:
    add x3, x3, #1
    ldr x4, [x1]
    add x1, x1, #1
    cmp x4, #0
    bne mark_1
    sub x3, x3, #1

    /* write */
    mov x0, #1
    ldr x1, =msg
    mov x2, x3
    mov x8, #64
    svc #0

    /* exit */
    mov x0, #0
    mov x8, #93
    svc #0
