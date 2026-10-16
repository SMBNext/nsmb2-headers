#pragma once

#include "sead.h"

class ScrollEffect
{
public:
    ScrollEffect();       // 0x0028367C
    bool execute(Vec2f* screenSizeOut, Vec2f* topLeft, f32 screenLeft, f32 screenTop, f32 zoom);    // 0x00283560

    f32 screenLeft;       // 0        init to 0.0
    f32 screenTop;        // 4        init to 0.0
    f32 zoom;             // 8        init to 1.0
    f32 zoomOverride;     // C        init to 0.0
    Vec2f maxTopLeft;     // 10
    Vec2f viewOffset;     // 18
    bool enabled;         // 20
    s32 angle;            // 24
    f32 yOffset;          // 28       init to 0.0
};

size_assert(ScrollEffect, 0x2C);
