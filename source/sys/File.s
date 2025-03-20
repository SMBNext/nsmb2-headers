.arm
.align 4


@ Unable to locate non-inlined version of this

.global _Z9CloseFilePv
_Z9CloseFilePv:
    cmp     r0, #0
    beq     _Z9CloseFilePv_error
    ldr     r1, [r0]
    ldr     r1, [r1,#0x30]
    bx      r1

_Z9CloseFilePv_error:
    bx      lr
