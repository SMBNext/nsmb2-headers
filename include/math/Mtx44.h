#pragma once

#include "math/Mtx34.h"
#include "types.h"

#include "nn/math/Matrix44.h"

class Mtx44
{
public:
    union
    {
        f32 rows[4][4];
        f32 cells[4*4];
    };

    inline void ortho(f32 left, f32 right, f32 bottom, f32 top, f32 near, f32 far, bool isLeftHanded)
    {
        rows[0][0] = 2.0f / (right - left);
        rows[0][3] = (left + right) / (left - right);
        rows[1][1] = 2.0f / (top - bottom);
        rows[1][3] = (bottom + top) / (bottom - top);
        if (isLeftHanded)
            rows[2][2] = 1.0f / (far - near);
        else
            rows[2][2] = 1.0f / (near - far);
        rows[2][3] = 0.5f*(near + far) / (near - far) - 0.5f;
        rows[3][3] = 1.0f;
    }

    void swapXY();
    static void multiply(Mtx44& dst, const Mtx34& a, const Mtx44& b);

    // Rotates the matrix as the 3ds physical screens actually are rotated 90°
    inline void device()
    {
        rows[0][0] = -rows[0][0];
        rows[0][1] = -rows[0][1];
        rows[0][2] = -rows[0][2];
        rows[0][3] = -rows[0][3];
        swapXY();
    }

    inline operator nn::math::MTX44() const
    {
        nn::math::MTX44 result;
        
        result.f._00 = this->rows[0][0];
        result.f._01 = this->rows[0][1];
        result.f._02 = this->rows[0][2];
        result.f._03 = this->rows[0][3];

        result.f._10 = this->rows[1][0];
        result.f._11 = this->rows[1][1];
        result.f._12 = this->rows[1][2];
        result.f._13 = this->rows[1][3];

        result.f._20 = this->rows[2][0];
        result.f._21 = this->rows[2][1];
        result.f._22 = this->rows[2][2];
        result.f._23 = this->rows[2][3];

        result.f._30 = this->rows[3][0];
        result.f._31 = this->rows[3][1];
        result.f._32 = this->rows[3][2];
        result.f._33 = this->rows[3][3];

        return result;
    }

    inline operator const nn::math::MTX44*() const
    {
        return reinterpret_cast<const nn::math::MTX44*>(this);
    }

};
