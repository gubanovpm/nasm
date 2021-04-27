main:                                   // @main
        sub     sp, sp, #32             // =32
        stp     x29, x30, [sp, #16]     // 16-byte Folded Spill
        add     x29, sp, #16            // =16
        mov     w0, #0
        adrp    x8, .L.str
        add     x8, x8, :lo12:.L.str
        stur    wzr, [x29, #-4]
        str     w0, [sp, #8]            // 4-byte Folded Spill
        mov     x0, x8
        bl      printf
        ldr     w9, [sp, #8]            // 4-byte Folded Reload
        mov     w0, w9
        bl      exit
.L.str:
        .asciz  "Hell, Word!"
