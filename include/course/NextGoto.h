#pragma once

#include "course/Course.h"
#include "scene/FaderMgr.h"
#include "sead.h"

class PlayerBound;

class NextGoto
{
    SEAD_SINGLETON_DISPOSER(NextGoto);
public:

    enum class DestinationType : u8
    {
        DIFFERENT_AREA,
        SAME_AREA,
        SAME_ZONE,
    };

    Course::Entrance destination;
    s32 warpDelayTimer;
    u16 _2C;
    DestinationType destinationType;
    bool hasDestination;                 // hasDestination?
    bool doWarp;
    bool _31;
    u8 _32;
    u8 _33;

    bool isDestinationMismatch(u8 area, u8 entrance);
    bool setDestination(u8 area, u8 entrance);

    void setupWarp();
    void reset();

    inline void startWarp()
    {
        doWarp = true;
    }

};

// size_assert(NextGoto, 0x34);
