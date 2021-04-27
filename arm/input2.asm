main:                                   // @main
        sub     sp, sp, #64             // =64
        stp     x29, x30, [sp, #48]     // 16-byte Folded Spill
        add     x29, sp, #48            // =48
        mov     w0, #0
        adrp    x8, stdin
        add     x8, x8, :lo12:stdin
        mov     x1, #1
        mov     x2, #10
        adrp    x9, .L.str
        add     x9, x9, :lo12:.L.str
        sub     x10, x29, #14           // =14
        stur    wzr, [x29, #-4]
        ldr     x3, [x8]
        stur    w0, [x29, #-20]         // 4-byte Folded Spill
        mov     x0, x10
        str     x9, [sp, #16]           // 8-byte Folded Spill
        str     x10, [sp, #8]           // 8-byte Folded Spill
        bl      fread
        ldr     x8, [sp, #16]           // 8-byte Folded Reload
        mov     x0, x8
        ldr     x1, [sp, #8]            // 8-byte Folded Reload
        bl      printf
        ldur    w11, [x29, #-20]        // 4-byte Folded Reload
        mov     w0, w11
        bl      exit
.L.str:
        .asciz  "%s"
