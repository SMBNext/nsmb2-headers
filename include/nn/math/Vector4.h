#pragma once

#include "types.h"

namespace nn {
namespace math {

struct VEC4_
{
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

struct VEC4 : public VEC4_
{

};

typedef VEC4 Vector4;


} // namespace math
} // namespace nn
