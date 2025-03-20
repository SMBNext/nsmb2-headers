#pragma once

#include "math/Vec.h"
#include "math/Mtx33.h"
#include "math/Mtx34.h"
#include "math/Mtx44.h"

namespace nw {
    
typedef unsigned long IntPtr;
typedef signed long PtrDiff;

typedef unsigned int bit32;

namespace math
{
    using VEC2 = Vec2f;
    using VEC3 = Vec3f;
    using MTX33 = Mtx33;
    using MTX34 = Mtx34;
    using MTX44 = Mtx44;

struct Transform3
{
    VEC3 scale;
    VEC3 rotate;
    VEC3 translate;
};

} // namespace Math

} // namespace nw