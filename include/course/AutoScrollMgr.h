#pragma once

#include "course/Course.h"

// Size: 0x1C
class AutoScrollMgr
{
public:

    // Size: 0xC
    struct Unk10
    {
        /* 0x0 */  u8 _0;
        /* 0x4 */  u32 _4;
        /* 0x8 */  u32 _8;
    };

    // Size: 0x8
    struct Neighbors
    {
        /* 0x0 */  u32 nextID;
        /* 0x4 */  u32 prevID;
    };

    // Size: 0x8
    struct PathInfo
    {
        /* 0x0 */  Course::Path* path;
        /* 0x4 */  Course::PathNode** pathNodes;
    };

    // Size: 0x50
    struct Unk14
    {
        /* 0x00 */  Course* course;
        /* 0x04 */  PathInfo pathInfo;
        /* 0x0C */  u8 _C;
        /* 0x0D */  u8 _D;
        /* 0x0E */  bool isEnabled;
        /* 0x0F */  u8 _F;
        /* 0x10 */  f32 curSpeed;
        /* 0x14 */  Neighbors neighbors;
        /* 0x1C */  Vec2f currentPos;
        /* 0x24 */  Vec2f nextPos;
        /* 0x2C */  Vec2f prevPos;
        /* 0x34 */  u32 _34;
        /* 0x38 */  f32 speed;
        /* 0x3C */  f32 acceleration;
        /* 0x40 */  bool doOverrideSpeedAccel;
        /* 0x41 */  bool lockEndX;
        /* 0x42 */  bool lockEndY;
        /* 0x44 */  Vec2f endPos;
        /* 0x4C */  u8 _4C;
    };

    size_assert(Unk14, 0x50);

    const Vec2f& getUnkPosition();

    /* 0x00 */  u8 pathId;                
    /* 0x01 */  bool isLinearMovement;
    /* 0x02 */  u8 repeatStartNodeID;
    /* 0x03 */  u8 endBehavior;
    /* 0x04 */  u8 startBehavior;
    /* 0x05 */  u8 checkpointEntranceNode;
    /* 0x06 */  u8 startingEntranceID;
    /* 0x07 */  u8 startingEntranceNode;
    /* 0x08 */  u8 triggeringFlagId;
    /* 0x09 */  u8 targetFlagId;
    /* 0x0A */  u8 _A;
    /* 0x0B */  u8 _B;
    /* 0x0C */  bool isActive;
    /* 0x0D */  u8 _D;
    /* 0x0E */  u8 isEnabled;
    /* 0x10 */  Unk10* _10;
    /* 0x14 */  Unk14* _14;
    /* 0x18 */  u8 _18;
};

size_assert(AutoScrollMgr, 0x1C);
