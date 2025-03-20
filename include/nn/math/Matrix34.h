#pragma once

#include "nn/math/Vector4.h"

namespace nn {
namespace math {

struct MTX34_
{
    struct BaseData
    {
        f32 _00, _01, _02, _03;
        f32 _10, _11, _12, _13;
        f32 _20, _21, _22, _23;
    };

    union
    {
        BaseData f;
        f32 m[3][4];
        f32 a[12];
        VEC4_ v[3];
    };
};

struct MTX34 : public MTX34_
{

};

typedef MTX34 Matrix34;

} // namespace math
} // namespace nn
