#pragma once

#include "sead.h"

class CourseTimer
{
    SEAD_SINGLETON_DISPOSER(CourseTimer);
public:
    enum TimerState : u32
    {
        TIMER_STATE_FREEZE          = (1 << 0),
        TIMER_STATE_DEATH_MAYBE     = (1 << 1),
        TIMER_STATE_GOAL_MAYBE      = (1 << 2),
    };

    u32 getTimeLeft();
    void addTime(u32 timeToAdd);
    void setTime(u32 time);
    void setTimeLimit(u32 timeLimit);


    u32 state;                           // set to either (mState | 1) or (mState & 0xFFFFFFFE) in bsArea::onCreate() (mState | 4) in goalPole::apCallback
    bool isActive;
    u32 time;
    bool is100SecRemain;

};

size_assert(CourseTimer, 0x20);
