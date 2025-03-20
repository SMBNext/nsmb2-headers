#pragma once

#include "nn/math/Vector4.h"

namespace nn {
namespace math {

enum PivotDirection
{
    PIVOT_NONE,
    PIVOT_UPSIDE_TO_TOP,
    PIVOT_UPSIDE_TO_RIGHT,
    PIVOT_UPSIDE_TO_BOTTOM,
    PIVOT_UPSIDE_TO_LEFT,
    PIVOT_NUM
};

struct MTX44_
{
    struct BaseData
    {
        f32 _00, _01, _02, _03;
        f32 _10, _11, _12, _13;
        f32 _20, _21, _22, _23;
        f32 _30, _31, _32, _33;
    };

    union
    {
        BaseData f;
        f32 m[4][4];
        f32 a[16];
        VEC4_ v[4];
    };
};

struct MTX44 : public MTX44_
{

};

typedef MTX44 Matrix44;

} // namespace math
} // namespace nn
