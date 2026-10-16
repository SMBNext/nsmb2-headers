#pragma once

#include "collider/UnitShapeBase.h"

// Size: 0x154 + (0x8 * (TNumSides))
template <u32 TNumSides>
class UnitShape : public UnitShapeBase
{
public:

protected:
    /* 0x154                     */  sead::Vector2f pointsBuffer[TNumSides];
    /* 0x15C + (0x8 * TNumSides) */  BasicRideLine sidesBuffer1[TNumSides];
};

size_assert(UnitShape<3>, 0x1C0);
size_assert(UnitShape<4>, 0x1E8);
