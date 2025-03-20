#pragma once

#include "sead.h"

class FollowArg
{
public:
    Vec3f* position;
    Vec3f* prevPosition;
    u8* layer;
    s8* playerIdx;
};
