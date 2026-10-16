#pragma once

#include "sys/Common.h"
#include "sead/gfx/seadColor.h"

struct PtclParam      // size: 0x28
{
    u32 emitterSetID;           // 0
    f32 scale;                  // 4
    Vec3f positionOffset;       // 8
    sead::Color4f tintColor;    // 14
    u32 flags;                  // 24
};