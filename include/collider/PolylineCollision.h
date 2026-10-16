#pragma once

#include "collider/LineCollision.h"
#include "types.h"

// Size: 0x154 + (0x40 * TNumSides) + (0x8 * (TNumSides + 1))
template<u32 TNumSides>
class PolylineCollision : public LineCollision
{
public:
    PolylineCollision() : 
        LineCollision(TNumSides, pointArray, rideLineArray, rideLinePrevArray) { }
    
protected:
    /* 0x154                      */  Vec2f pointArray[TNumSides + 1];
    /* 0x15C + (0x8 * TNumSides)  */  u32 _15C;
    /* 0x160 + (0x20 * TNumSides) */  BasicRideLine rideLineArray[TNumSides];
    /* 0x180 + (0x20 * TNumSides) */  BasicRideLine rideLinePrevArray[TNumSides];
};

size_assert(PolylineCollision<1>, 0x1A8);
size_assert(PolylineCollision<4>, 0x280);
