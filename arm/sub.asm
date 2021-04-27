main:                                   // @main
        sub     sp, sp, #48             // =48
        stp     x29, x30, [sp, #32]     // 16-byte Folded Spill
        add     x29, sp, #32            // =32
        mov     w0, #0
        adrp    x8, .L.str
        add     x8, x8, :lo12:.L.str
        adrp    x9, .L.str.1
        add     x9, x9, :lo12:.L.str.1
        sub     x1, x29, #8             // =8
        sub     x2, x29, #12            // =12
        stur    wzr, [x29, #-4]
        str     w0, [sp, #16]           // 4-byte Folded Spill
        mov     x0, x8
        str     x9, [sp, #8]            // 8-byte Folded Spill
        bl      __isoc99_scanf
        ldur    w10, [x29, #-8]
        ldur    w11, [x29, #-12]
        subs    w1, w10, w11
        ldr     x8, [sp, #8]            // 8-byte Folded Reload
        mov     x0, x8
        bl      printf
        ldr     w10, [sp, #16]          // 4-byte Folded Reload
        mov     w0, w10
        bl      exit
.L.str:
        .asciz  "%d%d"

.L.str.1:
        .asciz  "%d\n"
