#pragma once

#include "actors/ActorMultiState.h"
#include "actors/ActorUniqueID.h"
#include "sys/Allocator.h"

class Model;

// Size: 0x10B0
class LiftTenbin : public ActorMultiState
{
public:
    /* 0x0FEC */  HeapAllocator allocator;
    /* 0x0FF4 */  Model* modelKassha1;
    /* 0x0FF8 */  Model* modelKassha2;
    /* 0x0FFC */  Model* modelLineA1;
    /* 0x1000 */  Model* modelLineA2;
    /* 0x1004 */  Model* modelLineB;
    /* 0x1008 */  u32 _1008[3];
    /* 0x1014 */  Vec3f linePointA;
    /* 0x1020 */  Vec3f linePointB;
    /* 0x102C */  Vec3f linePointMid;
    /* 0x1038 */  Vec3f lineScaleA;
    /* 0x1044 */  Vec3f lineScaleB;
    /* 0x1050 */  Vec3f lineScaleC;
    /* 0x105C */  void (*drawFunc)();
    /* 0x1060 */  u32 drawFuncId;
    /* 0x1064 */  ActorUniqueID stepIds[4];
    /* 0x1074 */  f32 maxDropY;                 // Nybble 9 * 16 - 8, max drop of the first step
    /* 0x1078 */  f32 distanceX;                // Nybble 11 * 16, horizontal distance between the two steps
    /* 0x107C */  f32 maxDropSecondY;           // Max drop of the second step
    /* 0x1080 */  f32 dropY;                    // Clamped to [0.0f, maxDropSecondY]. First step hangs by this, second by maxDropSecondY - this
    /* 0x1084 */  f32 dropSpeed;
    /* 0x1088 */  u32 _1088;
    /* 0x108C */  s32 isPulleyActive;
    /* 0x1090 */  s32 _1090;
    /* 0x1094 */  s32 stepCount;
    /* 0x1098 */  s32 _1098;
    /* 0x109C */  bool noSteps;
    /* 0x109D */  u8 _109D[3];          
    /* 0x10A0 */  s16 stepWidth;                // Nybble 17 + 3, length of each step
    /* 0x10A2 */  u8 _10A2[2];          
    /* 0x10A4 */  s32 ropeRotation;         
    /* 0x10A8 */  u8 stepMoveMode;          
    /* 0x10A9 */  u8 _10A9;         
    /* 0x10AA */  u8 kasshaType;                // Nybble 16
    /* 0x10AB */  u8 _10AB;
    /* 0x10AC */  u32 _10AC;

};

size_assert(LiftTenbin, 0x10B0);
