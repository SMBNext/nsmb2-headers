#pragma once

#include "types.h"

#include "sead/seadMathCalcCommon.h"

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

    Color4f operator+(const Color4f& rhs) const {
        return Color4f(
            Mathf::clamp2(0.0f, this->r + rhs.r, 1.0f),
            Mathf::clamp2(0.0f, this->g + rhs.g, 1.0f),
            Mathf::clamp2(0.0f, this->b + rhs.b, 1.0f),
            Mathf::clamp2(0.0f, this->a + rhs.a, 1.0f)
        );
    }

    Color4f operator-(const Color4f& rhs) const {
        return Color4f(
            Mathf::clamp2(0.0f, this->r - rhs.r, 1.0f),
            Mathf::clamp2(0.0f, this->g - rhs.g, 1.0f),
            Mathf::clamp2(0.0f, this->b - rhs.b, 1.0f),
            Mathf::clamp2(0.0f, this->a - rhs.a, 1.0f)
        );
    }

    Color4f& operator+=(const Color4f& rhs) {
        return *this = *this + rhs;
    }

    Color4f& operator-=(const Color4f& rhs) {
        return *this = *this - rhs;
    }
};


}
