#pragma once

#include "types.h"

namespace nn {
namespace math {

struct VEC3_
{
    f32 x;
    f32 y;
    f32 z;
};

struct VEC3 : public VEC3_
{

};

typedef VEC3 Vector3;

} // namespace math
} // namespace nn
