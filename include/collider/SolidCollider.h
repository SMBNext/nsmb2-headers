#pragma once

#include "collider/BasicRideLine.h"
#include "collider/LoopRideLineBgCollision.h"


template<u32 TNumSides>
class SolidCollider : public LoopRideLineBgCollision      // size: 0x150 + 0x48*TNumSides
{
public:
    SolidCollider() : LoopRideLineBgCollision(TNumSides, pointArray, rideLineArray, rideLinePrevArray) {
        for (u32 i = 0; i < TNumSides; ++i) {
            pointArray[i].x = 0.0f;
            pointArray[i].y = 0.0f;
        }

        for (u32 i = 0; i < TNumSides; ++i) {
            rideLineArray[i].bgCheckData = mBgCheckData;
            rideLinePrevArray[i].bgCheckData = mBgCheckData;
        }
    }

    ~SolidCollider() { }

    Vec2f pointArray[TNumSides];
    BasicRideLine rideLineArray[TNumSides];
    BasicRideLine rideLinePrevArray[TNumSides];
};
