.text
.align 4

.global ProfileResTableR0
ProfileResTableR0:
    ldr     r0, =ResTable
    bx      lr

.global ProfileResTableR2
ProfileResTableR2:
    ldr     r2, =ResTable
    bx      lr

.global ProfileResTableR9
ProfileResTableR9:
    ldrgt   r9, =ResTable
    bx      lr


.global ProfileSoundActorKindsR7
ProfileSoundActorKindsR7:
    ldr     r7, =ProfileSoundActorKinds
    bx      lr


.global ActorInfosR0
ActorInfosR0:
    ldr     r0, =ActorInfos
    bx      lr

.global ActorInfosR1
ActorInfosR1:
    ldr     r1, =ActorInfos
    bx      lr

.global ActorInfosR2
ActorInfosR2:
    ldr     r2, =ActorInfos
    bx      lr

.global ActorInfosR4
ActorInfosR4:
    ldr     r4, =ActorInfos
    bx      lr

.global ActorInfosR10
ActorInfosR10:
    ldr     r10, =ActorInfos
    bx      lr

.global ActorInfosR11
ActorInfosR11:
    ldr     r11, =ActorInfos
    bx      lr

.global ActorInfosR2S
ActorInfosR2S:
    ldr     r2, =ActorInfos
    b       0x00403784


.global NumProfiles2R0
NumProfiles2R0:
    ldr     r0, =numProfiles2
    bx      lr

.global NumProfiles2R8
NumProfiles2R8:
    ldr     r8, =numProfiles2
    bx      lr
