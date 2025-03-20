#pragma once

#include "sys/Common.h"
#include "math/Vec.h"

#include "nn/math/Matrix34.h"

class Mtx34
{
public:
    union
    {
        f32 rows[3][4];
        f32 cells[12];
    };

    void setRotationAndTranslation(const Vec3i& rotation, const Vec3f& translate);    // 004620D8

    inline void setTranslation(f32 x, f32 y, f32 z)
    {
        cells[3] = x;
        cells[7] = y;
        cells[11] = z;
    }

    inline void translateX(f32 x) { cells[3] += x; }
    inline void translateY(f32 y) { cells[7] += y; }
    inline void translateZ(f32 z) { cells[11] += z; }

    inline void translate(f32 x, f32 y, f32 z)
    {
        translateX(x);
        translateY(y);
        translateZ(z);
    }

    inline void identity()
    {
        cells[0] = 1.0f;
        cells[1] = 0.0f;
        cells[2] = 0.0f;
        cells[3] = 0.0f;

        cells[4] = 0.0f;
        cells[5] = 1.0f;
        cells[6] = 0.0f;
        cells[7] = 0.0f;

        cells[8] = 0.0f;
        cells[9] = 0.0f;
        cells[10] = 1.0f;
        cells[11] = 0.0f;
    }

    void rotateX(const u32& rot);       // 0040A610
    void rotateY(const u32& rot);       // 0040A6A0
    void rotateZ(const u32& rot);       // 0040A730

    inline void rotate(u32 x, u32 y, u32 z)
    {
        rotateX(x);
        rotateY(y);
        rotateZ(z);
    }

    inline void rotate(f32 x, f32 y, f32 z)
    {
        rotateX(Mathf::rad2idx(x));
        rotateY(Mathf::rad2idx(y));
        rotateZ(Mathf::rad2idx(z));
    }

    static Mtx34* copy(Mtx34* out, const Mtx34* in);                            // 0011D3B8
    static void multiply(Mtx34* out, const Mtx34& a, const Mtx34& b);           // 0011E4F0

    static const Mtx34 ident;

    inline operator nn::math::MTX34() const
    {
        nn::math::MTX34 result;
        
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

        return result;
    }
};
