#pragma once

namespace sead {

template <typename T>
class Policies
{
public:
    struct Vec2Base
    {
        T x;
        T y;

        Vec2Base(T x = 0, T y = 0) :
            x(x), y(y) {}
    };

    struct Vec3Base
    {
        T x;
        T y;
        T z;

        Vec3Base(T x = 0, T y = 0, T z = 0) :
            x(x), y(y), z(z) {}
    };

    struct Vec4Base
    {
        T x;
        T y;
        T z;
        T w;

        Vec4Base(T x = 0, T y = 0, T z = 0, T w = 0) :
            x(x), y(y), z(z), w(w) {}
    };

    struct QuatBase
    {
        T x;
        T y;
        T z;
        T w;

        QuatBase(T x = 0, T y = 0, T z = 0, T w = 0) :
            x(x), y(y), z(z), w(w) {}
    };

    struct Mtx22Base
    {
        union
        {
            T m[2][2];
            T a[4];
        };
    };

    struct Mtx33Base
    {
        union
        {
            T m[3][3];
            T a[9];
        };
    };

    struct Mtx34Base
    {
        union
        {
            T m[3][4];
            T a[12];
        };
    };

    struct Mtx44Base
    {
        union
        {
            T m[4][4];
            T a[16];
        };
    };
};

} // namespace sead