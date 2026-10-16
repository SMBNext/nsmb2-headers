#pragma once

#include "player/PlayerObject.h"
#include "sead.h"

class CoursePlayerInfoMgr
{
    SEAD_SINGLETON_DISPOSER(CoursePlayerInfoMgr);
public:
    PlayerObject* players[2];
    sead::Vector3f* positions[2];
    sead::Vector3f* speeds[2];
};

size_assert(CoursePlayerInfoMgr, 0x28);
