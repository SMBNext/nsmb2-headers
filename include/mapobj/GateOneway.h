#pragma once

#include "actors/ActorState.h"
#include "collider/RectCollider.h"
#include "sead/seadMathCalcCommon.h"
#include "sys/Allocator.h"
#include "types.h"
#include "utility/Direction.h"

class ActorBase;
class ActorBgCollisionCheck;
class BgCollision;
class Model;
class Resource;

// Size: 0x1280
class GateOneway : public ActorState
{
public:
    enum class SwingDirection : u8
    {
        cRightToDown = 0,
        cLeftToDown = 1,
        cRightToUp = 2,
        cLeftToUp = 3,
        cUpToLeft = 4,
        cDownToLeft = 5,
        cUpToRight = 6,
        cDownToRight = 7,
    };

    /* 0xFE8 */  Model* model;
    /* 0xFEC */  Resource* resource;
    /* 0xFF0 */  HeapAllocator allocator;
    /* 0xFF8 */  RectCollider collider;
    /* 0x1268 */ s32 _1268;
    /* 0x126C */ s32 _126C;
    /* 0x1270 */ s32 _1270;
    /* 0x1274 */ s32 _1274;
    /* 0x1278 */ u8 _1278;
    /* 0x1279 */ u8 _1279;
    /* 0x127A */ SwingDirection swingDirection;
    /* 0x127B */ bool fastOpen;
    /* 0x127C */ s32 length;

};
size_assert(GateOneway, 0x1280);
