.arm
.align 4

.macro SVC_BEGIN name
	.section .text.\name, "ax", %progbits
	.global \name
	.type \name, %function
	.align 2
	.cfi_startproc
\name:
.endm

.macro SVC_END
	.cfi_endproc
.endm

.macro LOADER_SVC_BEGIN name
	.pushsection mw_loader_section.\name, "ax", %progbits
	.global \name
	.type \name, %function
	.align 2
	.cfi_startproc
\name:
.endm

.macro LOADER_SVC_END
	.cfi_endproc
	.popsection
.endm

SVC_BEGIN svcCloseHandle
	svc 0x23
	bx  lr
SVC_END

SVC_BEGIN svcGetSystemTick
	svc 0x28
	bx  lr
SVC_END

SVC_BEGIN svcSendSyncRequest
	svc 0x32
	bx  lr
SVC_END

LOADER_SVC_BEGIN svcOpenProcess
	push {r0}
	svc 0x33
	pop  {r2}
	str  r1, [r2]
	bx  lr
LOADER_SVC_END

SVC_BEGIN svcBreak
	svc 0x3C
	bx  lr
SVC_END

SVC_BEGIN svcOutputDebugString
	svc 0x3D
	bx  lr
SVC_END 

LOADER_SVC_BEGIN svcControlProcessMemory
	push {r4-r5}
	ldr r4, [sp, #0x8]
	ldr r5, [sp, #0xC]
	svc 0x70
	pop  {r4-r5}
	bx  lr
LOADER_SVC_END 
