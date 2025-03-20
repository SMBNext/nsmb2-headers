#pragma once

#include "types.h"

class StateID;

class StateIDHolder
{
public:
    StateIDHolder()
    {
        reset();
    }

    void set(const StateID* stateID)
    {
        mStateID = stateID;
    }

    void reset()
    {
        mStateID = nullptr;
    }

    bool isSet() const
    {
        return mStateID != nullptr;
    }

    const StateID* get() const
    {
        return mStateID;
    }

protected:
    const StateID* mStateID;
};

size_assert(StateIDHolder, 4);