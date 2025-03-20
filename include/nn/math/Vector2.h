#pragma once

#include "types.h"

namespace nn {
namespace math {

struct VEC2_
{
    f32 x;
    f32 y;
};

struct VEC2 : public VEC2_
{

};

typedef VEC2 Vector2;


} // namespace math
} // namespace nn
