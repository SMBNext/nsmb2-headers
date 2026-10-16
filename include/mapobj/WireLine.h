#pragma once

#include "collider/RectCollider.h"
#include "course/LineFollower.h"
#include "gfx/Model.h"
#include "mapobj/LiftBase.h"

class WireLine : public LiftBase
{
public:
    WireLine();
    virtual ~WireLine();

    Result onCreate() override;
    Result onDelete() override;
    Result onExecute() override;
    Result onDraw() override;

    void executeState_Idle();

    Model* model;
    HeapAllocator allocator;
    LineFollower lineFollower;
    RectCollider rectCollider;
    f32 _12F8;
    f32 _12FC;
    f32 _1300;
    f32 _1304;
    Vec3f initialPosition;
    f32 width;
    f32 height;
    f32 heightOffset;                     // The height when on the top side, 0 on the bottom
    u8 _1320[4];                          // UNK
    f32 _1324;
    u32 timer;
    u8 _132C[4];                          // UNK
    u32 _1330;
    u8 _1334;
    u8 _1335;
    u8 size;                              // (3x3, 3x6, 6x3, 3x3) or (3x3, 3x3, 3x3, 6x6)
    bool isOnTop;
    bool isWireLineSlide;
    bool isNotSwitching;
    u8 _133A[6];                          // UNK   

    DECLARE_STATE_ID(WireLine, Active);

    static const f32 speeds[];
};

size_assert(WireLine, 0x1340);

