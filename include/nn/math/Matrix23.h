#pragma once

#include "nn/math/Vector3.h"

namespace nn {
namespace math {

struct MTX23_
{
    struct BaseData
    {
        f32 _00, _01, _02;
        f32 _10, _11, _12;
    };

    union
    {
        BaseData f;
        f32 m[2][3];
        f32 a[6];
        VEC3_ v[2];
    };
};

struct MTX23 : public MTX23_
{

};

typedef MTX23 Matrix23;

} // namespace math
} // namespace nn
