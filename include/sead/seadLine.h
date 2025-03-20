#pragma once

#include "sead/seadVector.h"

namespace sead {

template <typename VectorType>
class Segment
{
public:
    using T = typename VectorType::ValueType;

public:
    Segment() :
        mP0(VectorType::zero), mP1(VectorType::ex) {}

    Segment(const VectorType& p0, const VectorType& p1) :
        mP0(p0), mP1(p1) {}

    const VectorType& getPos0() const
    {
        return mP0;
    }

    void setPos0(const VectorType& p0)
    {
        mP0 = p0;
    }

    const VectorType& getPos1() const
    {
        return mP1;
    }

    void setPos1(const VectorType& p1)
    {
        mP1 = p1;
    }

private:
    VectorType mP0;
    VectorType mP1;
};

typedef Segment<Vector2f> Segment2f;
typedef Segment<Vector3f> Segment3f;

}
