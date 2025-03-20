#pragma once

#include "types.h"

namespace sead {


class Color4f
{
public:
    union
    {
        struct
        {
            f32 r;
            f32 g;
            f32 b;
            f32 a;
        };

        f32 c[4];        
    };

    Color4f(f32 r=0.0f, f32 g=0.0f, f32 b=0.0f, f32 a=1.0f)
        : r(r), g(g), b(b), a(a) { }
};


}
