#pragma once

#include "types.h"

#include "nn/math/Matrix33.h"

class Mtx33
{
public:
    union
    {
        f32 rows[3][3];
        f32 cells[3*3];
    };

    static Mtx33* copy(Mtx33& out, const Mtx33& in);
    static void makeRzxyIdx(Mtx33& out, u32 rotationX, u32 rotationY, u32 rotationZ);
    static void makeR(Mtx33& out, Vec3f rotation);

    inline operator nn::math::MTX33() const
    {
        nn::math::MTX33 result;
        
        result.f._00 = this->rows[0][0];
        result.f._01 = this->rows[0][1];
        result.f._02 = this->rows[0][2];

        result.f._10 = this->rows[1][0];
        result.f._11 = this->rows[1][1];
        result.f._12 = this->rows[1][2];

        result.f._20 = this->rows[2][0];
        result.f._21 = this->rows[2][1];
        result.f._22 = this->rows[2][2];

        return result;
    }

    inline operator const nn::math::MTX33*() const
    {
        return reinterpret_cast<const nn::math::MTX33*>(this);
    }
};
