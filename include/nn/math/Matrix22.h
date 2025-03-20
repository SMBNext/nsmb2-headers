#pragma once

#include "nn/math/Vector2.h"

namespace nn {
namespace math {

struct MTX22_
{
    struct BaseData
    {
        f32 _00, _01;
        f32 _10, _11;
    };

    union
    {
        BaseData f;
        f32 m[2][2];
        f32 a[4];
        VEC2_ v[2];
    };
};

struct MTX22 : public MTX22_
{

};

typedef MTX22 Matrix22;

} // namespace math
} // namespace nn
