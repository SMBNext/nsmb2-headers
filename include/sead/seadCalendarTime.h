#pragma once

#include "types.h"


namespace sead {

class CalendarTime
{
public:

    class Year
    {
    public:
        u32 getValue() const { return mValue; }

    private:
        u32 mValue;
    };

    class Month
    {
    public:
        u32 getValue() const { return mValue; }

    private:
        u32 mValue;
    };

    class Day
    {
    public:
        u32 getValue() const { return mValue; }

    private:
        u32 mValue;
    };

    enum Week : u8
    {
        cWeek_Sunday    = 0,
        cWeek_Monday    = 1,
        cWeek_Tuesday   = 2,
        cWeek_Wednesday = 3,
        cWeek_Thursday  = 4,
        cWeek_Friday    = 5,
        cWeek_Saturday  = 6,
        cWeek_Max       = 7,
    };

    class Hour
    {
    public:
        u32 getValue() const { return mValue; }

    private:
        u32 mValue;
    };

    class Minute
    {
    public:
        u32 getValue() const { return mValue; }

    private:
        u32 mValue;
    };

    class Second
    {
    public:
        u32 getValue() const { return mValue; }

    private:
        u32 mValue;
    };

    static const Year cDefaultYear;
    static const Month cDefaultMonth;
    static const Day cDefaultDay;
    static const Hour cDefaultHour;
    static const Minute cDefaultMinute;
    static const Second cDefaultSecond;

    class Date
    {
    public:
        const Year& getYear() const { return mYear; }
        const Month& getMonth() const { return mMonth; }
        const Day& getDay() const { return mDay; }
        const Week& getWeek() const { return mWeek; }

    private:
        Year mYear;
        Month mMonth;
        Day mDay;
        Week mWeek;
    };

    class Time
    {
    public:
        const Hour& getHour() const { return mHour; }
        const Minute& getMinute() const { return mMinute; }
        const Second& getSecond() const { return mSecond; }

    private:
        Hour mHour;
        Minute mMinute;
        Second mSecond;
    };


    CalendarTime(const Year& year = cDefaultYear, const Month& mon = cDefaultMonth,   const Day& day = cDefaultDay,
                 const Hour& hour = cDefaultHour, const Minute& min = cDefaultMinute, const Second& sec = cDefaultSecond);

    const Date& getDate() const { return mDate; }
    const Time& getTime() const { return mTime; }

private:
    Date mDate;
    Time mTime;
};

}
