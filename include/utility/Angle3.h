#pragma once

#include "types.h"
#include "math/Vec.h"
#include "utility/Angle.h"

class Angle3
{
public:
    Angle3() {}

    Angle3(const Angle& x, const Angle& y, const Angle& z)
        : x(x)
        , y(y)
        , z(z) { }

    explicit Angle3(const Angle* p)
        : x(p[0])
        , y(p[1])
        , z(p[2]) { }

    explicit Angle3(const sead::Vector3i& v)
        : x(v.x)
        , y(v.y)
        , z(v.z) { }

    explicit Angle3(const sead::Vector3u& v)
        : x(v.x)
        , y(v.y)
        , z(v.z) { }

    operator Angle*()
    {
        return &x;
    }

    operator const Angle*() const
    {
        return &x;
    }

    operator sead::Vector3i() const
    {
        return sead::Vector3i(s32(x), s32(y), s32(z));
    }

    operator sead::Vector3u() const
    {
        return sead::Vector3u(s32(x), s32(y), s32(z));
    }

    Angle3& operator=(const Angle3& rhs)
    {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
        return *this;
    }

    Angle3& operator+=(const Angle3& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }

    Angle3& operator-=(const Angle3& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }

    Angle3 operator+() const
    {
        return *this;
    }

    Angle3 operator-() const
    {
        return Angle3(-x, -y, -z);
    }

    Angle3 operator+(const Angle3& rhs)
    {
        return Angle3(x + rhs.x, y + rhs.y, z + rhs.z);
    }

    Angle3 operator-(const Angle3& rhs)
    {
        return Angle3(x - rhs.x, y - rhs.y, z - rhs.z);
    }

    bool operator==(const Angle3& rhs) const
    {
        return x == rhs.x && y == rhs.y && z == rhs.z;
    }

    bool operator!=(const Angle3& rhs) const
    {
        return x != rhs.x || y != rhs.y || z != rhs.z;
    }

public:
    Angle x;
    Angle y;
    Angle z;
};

size_assert(Angle3, 0xC);
