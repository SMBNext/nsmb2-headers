#pragma once

#include "collider/BasicRideLine.h"
#include "collider/LoopRideLineBgCollision.h"


template<u32 TNumSides>
class SolidCollider : public LoopRideLineBgCollision      // size: 0x150 + 0x48*TNumSides
{
public:
    SolidCollider() : LoopRideLineBgCollision(TNumSides, pointArray, rideLineArray, rideLinePrevArray) { }
    ~SolidCollider() { }

    Vec2f pointArray[TNumSides];
    BasicRideLine rideLineArray[TNumSides];
    BasicRideLine rideLinePrevArray[TNumSides];
};
