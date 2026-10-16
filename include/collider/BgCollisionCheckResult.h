#pragma once

#include "collider/BgUnitCode.h"
#include "math/Vec.h"

class BgCollision;

struct BgCollisionCheckResultPoint
{   
    BgUnitCode bgCheckData;
    BgCollision* bgCollision;
};


struct BgCollisionCheckResultArea
{
    u8 hitDirectionFlag;
    Vec2f hitPos;
    u32 _C;
    u32 _10;
    u8 _14[4];                            // unk
    BgUnitCode bgCheckData;
    BgCollision* bgCollision;
};

