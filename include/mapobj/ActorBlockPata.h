#pragma once

#include "actors/ActorBlockBase.h"
#include "actors/ActorMultiState.h"
#include "gfx/Animation.h"
#include "gfx/AnimModelBase.h"
#include "sys/Allocator.h"

// Size: 0x14B8
class ActorBlockPata : public ActorBlockBase
{
public:
    /* 0x1450 */  AnimModelBase* model;
    /* 0x1454 */  Resource* resource;
    /* 0x1458 */  AnimBase* materialAnim;
    /* 0x145C */  HeapAllocator allocator;
    /* 0x1464 */  sead::Vector3f flyPos;
    /* 0x1470 */  sead::Vector3f flySpeed;
    /* 0x147C */  s32 sineAngleX;
    /* 0x1480 */  s32 yBobbingAngle;
    /* 0x1484 */  u32 useModel;
    /* 0x1488 */  Direction moveDirection;
    /* 0x1489 */  bool isNearView;
    /* 0x148A */
    /* 0x148B */
    /* 0x148C */  FStateStateMgr<ActorMultiState> flyStateMgr;
    /* 0x14B4 */  u32 _14B4;
};

size_assert(ActorBlockPata, 0x14B8);
