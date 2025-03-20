#pragma once

#include "types.h"

// vtable: 0059ABE4
class StateID
{
public:
    // Address: 0x005ED2A8
    static const StateID cNull;
    static const s32 cNullNumber = -1;

public:
    StateID()
    {
        mNumber = ++sNumberMemo;
    }

    explicit StateID(s32 number) :
        mNumber(number) {}

    virtual ~StateID() {}

    // Address: 0x004B3514
    virtual s32 number() const
    {
        return mNumber;
    }

    bool isNull() const
    {
        return mNumber == cNullNumber;
    }

    bool isEqual(const StateID& rhs) const
    {
        return number() == rhs.number();
    }

    bool operator==(const StateID& rhs) const
    {
        return isEqual(rhs);
    }

    bool operator!=(const StateID& rhs) const
    {
        return !isEqual(rhs);
    }

protected:
    s32 mNumber;

private:
    // Address: 0x00603360
    static s32 sNumberMemo;
};

static_assert(sizeof(StateID) == 8);