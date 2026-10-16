#pragma once

#include "types.h"

class Angle
{
public:
    Angle() :
        mValue(0) { }

    Angle(s32 value) :
        mValue(value) { }
        
    operator s32() const
    {
        return mValue;
    }

    Angle& operator=(const Angle& rhs)
    {
        mValue = rhs.mValue;
        return *this;
    }

    Angle& operator+=(const Angle& rhs)
    {
        mValue += rhs.mValue;
        return *this;
    }

    Angle& operator-=(const Angle& rhs)
    {
        mValue -= rhs.mValue;
        return *this;
    }

    Angle operator+() const
    {
        return *this;
    }

    Angle operator-() const
    {
        return Angle(-mValue);
    }

    Angle operator+(const Angle& rhs)
    {
        return mValue + rhs.mValue;
    }

    Angle operator+(s32 rhs)
    {
        return mValue + rhs;
    }

    Angle operator-(const Angle& rhs)
    {
        return mValue - rhs.mValue;
    }

    Angle operator-(s32 rhs)
    {
        return mValue - rhs;
    }

    bool operator==(const Angle& rhs) const
    {
        return mValue == rhs.mValue;
    }

    bool operator==(s32 rhs) const
    {
        return mValue == rhs;
    }

    bool operator!=(const Angle& rhs) const
    {
        return mValue != rhs.mValue;
    }

    bool operator!=(s32 rhs) const
    {
        return mValue != rhs;
    }

    // Returns the tangent of the angle.
    f32 getTangent() const;
    
protected:
    s32 mValue;
};

size_assert(Angle, 0x4);
