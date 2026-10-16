#pragma once

#include "seadCalendarTime.h"


namespace sead {

class DateTime
{
public:
    DateTime()
        : mRealTimeClock(0) { }

    u64 setNow();
    void getCalendarTime(CalendarTime* calendar) const;

private:
    u64 mRealTimeClock;
};

}
