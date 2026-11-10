#pragma once

#include "enemy/Enemy.h"
#include "gfx/AnimModel.h"
#include "sys/Allocator.h"

class BeansKuribo : public Enemy    // Size: 0x10D0
{
public:
    bool checkPlayerInput(PlayerBase* player);

public:
    /* 0x1060 */  HeapAllocator allocator;      //
    /* 0x1068 */  Resource* resource;           //
    /* 0x106C */  AnimModelBase* modelA;        //
    /* 0x1070 */  AnimModelBase* modelB;        // gold model
    /* 0x1074 */  f32 bobOffset;                //
    /* 0x1078 */  f32 bobSpeed;                 //
    /* 0x107C */  u32 hopCount;                 //
    /* 0x1080 */  u32 detatchCounter;           //
    /* 0x1084 */  u32 lastJumpPressMask;        //
    /* 0x1088 */  u32 jumpPressCount;           //
    /* 0x108C */  u32 lastPressMask;            //
    /* 0x1090 */  u32 altPressCount;            // tracks alternating preses within the shakeoff time window
    /* 0x1094 */  u32 shakeWindowTimer;         //
    /* 0x1098 */  u32 facePlayerOnLand;         // set after a big hop
    /* 0x109C */  u16 mgrIndex;                 // index into BeansKuriboMgr, -1 while not attached
    /* 0x109E */                                // padding
    /* 0x109F */                                // padding
    /* 0x10A0 */  u32 orbitAngle;               //
    /* 0x10A4 */  u8 attatchedPlayerId;         //
    /* 0x10A5 */  u8 bobFlip;                   //
    /* 0x10A6 */                                // padding
    /* 0x10A7 */                                // padding
    /* 0x10A8 */  f32 modelScale;               // set to 1.1 every frame
    /* 0x10AC */  f32 walkSpeed;                // init to 0.4
    /* 0x10B0 */  f32 hopSpeed;                 // init to 1.5
    /* 0x10B4 */  f32 bigHopSpeed;              // init to 2.5
    /* 0x10B8 */  f32 shakeWindow;              // init to 60.0
    /* 0x10BC */  f32 altPressThreshold;        // init to 8.0
    /* 0x10C0 */  f32 jumpPressThreshold;       // init to 3.0
    /* 0x10C4 */  u32 modelSwapTimer;           //
    /* 0x10C8 */  s32 modelSwapAngle;           //
    /* 0x10CC */  bool useModelB;               //
    /* 0x10CD */  bool wasTailHit;              //
    /* 0x10CE */                                // padding
    /* 0x10CF */                                // padding
};
size_assert(BeansKuribo, 0x10D0);
