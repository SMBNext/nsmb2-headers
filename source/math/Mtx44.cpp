#include "math/Mtx44.h"
#include "math/Mtx34.h"

void Mtx44::multiply(Mtx44& dst, const Mtx34& a, const Mtx44& b)
{
    const f32 a11 = a.rows[0][0];
    const f32 a12 = a.rows[0][1];
    const f32 a13 = a.rows[0][2];
    const f32 a14 = a.rows[0][3];

    const f32 a21 = a.rows[1][0];
    const f32 a22 = a.rows[1][1];
    const f32 a23 = a.rows[1][2];
    const f32 a24 = a.rows[1][3];

    const f32 a31 = a.rows[2][0];
    const f32 a32 = a.rows[2][1];
    const f32 a33 = a.rows[2][2];
    const f32 a34 = a.rows[2][3];

    const f32 b11 = b.rows[0][0];
    const f32 b12 = b.rows[0][1];
    const f32 b13 = b.rows[0][2];
    const f32 b14 = b.rows[0][3];

    const f32 b21 = b.rows[1][0];
    const f32 b22 = b.rows[1][1];
    const f32 b23 = b.rows[1][2];
    const f32 b24 = b.rows[1][3];

    const f32 b31 = b.rows[2][0];
    const f32 b32 = b.rows[2][1];
    const f32 b33 = b.rows[2][2];
    const f32 b34 = b.rows[2][3];

    const f32 b41 = b.rows[3][0];
    const f32 b42 = b.rows[3][1];
    const f32 b43 = b.rows[3][2];
    const f32 b44 = b.rows[3][3];

    dst.rows[0][0] = a11 * b11 + a12 * b21 + a13 * b31 + a14 * b41;
    dst.rows[0][1] = a11 * b12 + a12 * b22 + a13 * b32 + a14 * b42;
    dst.rows[0][2] = a11 * b13 + a12 * b23 + a13 * b33 + a14 * b43;
    dst.rows[0][3] = a11 * b14 + a12 * b24 + a13 * b34 + a14 * b44;

    dst.rows[1][0] = a21 * b11 + a22 * b21 + a23 * b31 + a24 * b41;
    dst.rows[1][1] = a21 * b12 + a22 * b22 + a23 * b32 + a24 * b42;
    dst.rows[1][2] = a21 * b13 + a22 * b23 + a23 * b33 + a24 * b43;
    dst.rows[1][3] = a21 * b14 + a22 * b24 + a23 * b34 + a24 * b44;

    dst.rows[2][0] = a31 * b11 + a32 * b21 + a33 * b31 + a34 * b41;
    dst.rows[2][1] = a31 * b12 + a32 * b22 + a33 * b32 + a34 * b42;
    dst.rows[2][2] = a31 * b13 + a32 * b23 + a33 * b33 + a34 * b43;
    dst.rows[2][3] = a31 * b14 + a32 * b24 + a33 * b34 + a34 * b44;

    dst.rows[3][0] = b41;
    dst.rows[3][1] = b42;
    dst.rows[3][2] = b43;
    dst.rows[3][3] = b44;
}
