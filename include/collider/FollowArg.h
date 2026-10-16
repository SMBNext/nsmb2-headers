#pragma once

#include "math/Vec.h"
#include "types.h"

// Size: 0x10
struct FollowArg
{
    FollowArg() :
        positionPtr(nullptr),
        prevPositionPtr(nullptr),
        layerPtr(nullptr),
        playerNumPtr(nullptr) { }

    /* 0x0 */  Vec3f* positionPtr;      // Pointer to the position value being followed.
    /* 0x4 */  Vec3f* prevPositionPtr;  // Pointer to the previous frame position value being followed.
    /* 0x8 */  u8* layerPtr;            // Pointer to the layer being followed.
    /* 0xC */  s8* playerNumPtr;        // Pointer to the playerNum being followed.
};

size_assert(FollowArg, 0x10);
