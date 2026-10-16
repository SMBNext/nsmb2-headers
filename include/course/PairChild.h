#pragma once

#include "actors/ActorBase.h"
#include "state/FStateMgr.h"

class PairChild   // size: 0xD0 or larger
{
public:

    enum MovementType : u32
    {
        MOVEMENT_NONE       = 0,
        MOVEMENT_ROTATION   = 1,
        MOVEMENT_UNK2       = 2,    // Unused, used to skip checks for path & back and forth when mask is set
        MOVEMENT_PATH       = 3,
        MOVEMENT_BACKFORTH  = 4,
        MOVEMENT_UNK5       = 5,    // Unused, only some checks remain
        MOVEMENT_UNK6       = 6,    // Unused, only some checks remain
        MOVEMENT_UNK7       = 7,    // Unused, only some checks remain
        MOVEMENT_UNK8       = 8,
        MOVEMENT_UNK9       = 9,
        MOVEMENT_UNKA       = 10,

        NUM_MOVEMENT_TYPES,
    };

    enum MovementMask : u32
    {
        MOVEMENT_MASK_NONE         = MOVEMENT_NONE,
        MOVEMENT_MASK_ROTATION     = 1 << (-1 + MOVEMENT_ROTATION),
        MOVEMENT_MASK_UNK2         = 1 << (-1 + MOVEMENT_UNK2),
        MOVEMENT_MASK_PATH         = 1 << (-1 + MOVEMENT_PATH),
        MOVEMENT_MASK_BACKFORTH    = 1 << (-1 + MOVEMENT_BACKFORTH),
        MOVEMENT_MASK_UNK5         = 1 << (-1 + MOVEMENT_UNK5),
        MOVEMENT_MASK_UNK6         = 1 << (-1 + MOVEMENT_UNK6),
        MOVEMENT_MASK_UNK7         = 1 << (-1 + MOVEMENT_UNK7),
        MOVEMENT_MASK_UNK8         = 1 << (-1 + MOVEMENT_UNK8),
        MOVEMENT_MASK_UNK9         = 1 << (-1 + MOVEMENT_UNK9),
        MOVEMENT_MASK_UNKA         = 1 << (-1 + MOVEMENT_UNKA),
    };

    enum class RotationType : u32
    {
        SWINGING = 0,
        SPINNING = 1,
        SWINGING_PATH = 2,
        SPINNING_PATH = 3
    };


    PairChild();

    void link(const Vec3f& initialPosition, u32 movementMask, u8 movementId);
    void execute();


    Vec3f position;                 // 0
    Vec3f initialPosition;          // C
    Vec3f positionOffset;           // 18   Used with the path movement type; the offset from the controller to the path start node.
    Vec3f _24;                      // 24
    u8 _30;                         // 30   Inited to 0
    u8 _31;                         // 31
                                    // pad?
    ActorUniqueID parentId;         // 34
    f32 _38;                        // 38   Inited to 0.0
    bool isVertical;                // 3C   Only used with the back and forth movement type
    u32 _40;                        // 40   Inited to 0. Set to 1 if the controller somehow cannot be found and the parentId is not -1
    u32 movementMask;               // 44
    u8 movementId;                  // 48
    s32 rotation;                   // 4C   Inited to 0
    ActorBase* parent;              // 50
    f32 _54;                        // 54   Inited to 1.0
    RotationType rotationType;      // 58   0 if controller actor not found, or if non-rotation type
    f32 _5C;                        // 5C
    f32 _60;                        // 60
    u32 _64;                        // 64
    u32 _68;                        // 68
    f32 _6C;                        // 6C
    f32 moveDistance;               // 70   Only used with the back and forth movement type
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
