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

SVC_BEGIN svcBreak
	svc 0x3C
	bx  lr
SVC_END

SVC_BEGIN svcOutputDebugString
	svc 0x3D
	bx  lr
SVC_END 
