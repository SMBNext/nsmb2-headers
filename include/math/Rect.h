// TODO: Remove this entirely

#pragma once

#include "Vec.h"

struct RectU16
{
    u16 x1;
    u16 y1;
    u16 x2;
    u16 y2;

    Vec2u& v(int idx) { return *reinterpret_cast<Vec2u*>(&x1 + 2*idx); }
    Vec2u& v1() { return v(0); }
    Vec2u& v2() { return v(1); }
};
