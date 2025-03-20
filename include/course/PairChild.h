#pragma once

#include "state/FStateMgr.h"

class PairChild   // size: 0xD0 or larger
{
public:

    enum MovementType
    {
        MOVEMENT_NONE       = 0,
        MOVEMENT_ROTATION   = 1,
        MOVEMENT_UNK2       = 2,
        MOVEMENT_PATH       = 3,
        MOVEMENT_BACKFORTH  = 4,
        MOVEMENT_UNK5       = 5,
        MOVEMENT_UNK6       = 6,
        MOVEMENT_UNK7       = 7,
        MOVEMENT_UNK8       = 8,
        MOVEMENT_UNK9       = 9,
        MOVEMENT_UNKA       = 10,
        MOVEMENT_UNKB       = 11
    };


    PairChild();

    void link(const Vec3f& initialPosition, u32 movementMask, u8 movementId);
    void execute();
    u32 getMaskForMovementType(u32 movementType);


    Vec3f position;                  // 0
    Vec3f position2;                 // C
    Vec3f _18;                       // 18
    Vec3f _24;                       // 24
    bool isMoving;                  // 30   Inited to 0
    u8 _31;                         // 31
                                    // pad?
    s32 parentId;                   // 34
    f32 _38;                        // 38   Inited to 0.0
    u32 _3C;                        // 3C
    u32 _40;                        // 40   Inited to 0
    u32 movementMask;               // 44
    u8 movementId;                  // 48
    s32 rotation;                   // 4C   Inited to 0
    u32 _50;                        // 50
    f32 _54;                        // 54   Inited to 1.0
    u32 _58;                        // 58   Set by function at 0x2A7410
    f32 _5C;                        // 5C
    f32 _60;                        // 60
    u32 _64;                        // 64
    u32 _68;                        // 68
    f32 _6C;                        // 6C
    f32 _70;                        // 70
    u32 _74;                        // 74   Inited to 0
    u32 _78;                        // 78   Inited to 0
    u32 _7C;                        // 7C   Inited to 0
    u8 _80;                         // 80
    u8 _81;                         // 81
    u8 _82;                         // 82
    u8 _83;                         // 83
    u32 _84;                        // 84
    f32 _88;                        // 88
    u32 _8C;                        // 8C   Inited to 0
    u32 _90;                        // 90   Inited to 0
    u32 _94;                        // 94   Inited to 0

    u8 _unk98[0xAC-0x98];           // 98

    FStateMgr<PairChild> stateMgr;   // AC   up to D0, Used with two different states
};
