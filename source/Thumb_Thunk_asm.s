.arm

.macro thumb_thunk name address
    .global \name
    \name:
        push    {r4, lr}
        ldr     r4, =(\address+1)
        blx     r4
        pop     {r4, pc}
.endm

thumb_thunk vsnprintf           0x00100048
thumb_thunk __cxa_guard_acquire 0x00100492
thumb_thunk tolower             0x001006C4
thumb_thunk atoi                0x00100764
thumb_thunk strtol              0x00100780
thumb_thunk wcscpy              0x001009F4
thumb_thunk wcsncpy             0x00100A06
thumb_thunk wcsncmp             0x00100A22
thumb_thunk wcslen              0x00100A4A
thumb_thunk __cxa_pure_virtual  0x00100ECE
