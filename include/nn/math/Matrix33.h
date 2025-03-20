#pragma once

#include "nn/math/Vector3.h"

namespace nn {
namespace math {

struct MTX33_
{
    struct BaseData
    {
        f32 _00, _01, _02;
        f32 _10, _11, _12;
        f32 _20, _21, _22;
    };

    union
    {
        BaseData f;
        f32 m[3][3];
        f32 a[9];
        VEC3_ v[3];
    };
};

struct MTX33 : public MTX33_
{

};

typedef MTX33 Matrix33;

} // namespace math
} // namespace nn
