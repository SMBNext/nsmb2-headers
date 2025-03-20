#pragma once

#include "collider/BgCollision.h"
#include "sead/seadLine.h"

class Ride2Point
{
    sead::Segment2f mSegment;
};


class BasicRideLine          // size: 0x20
{
public:
    BasicRideLine();         // 0x421394

    u8 _0;
    u8 _1;
    Ride2Point ride2Point;
    u32 _14;
    BgCheckUnitInfo bgCheckData;
};
