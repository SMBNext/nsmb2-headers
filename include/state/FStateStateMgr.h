#pragma once

#include "state/FStateFactory.h"
#include "state/StateStateMgr.h"

template <typename T>
class FStateStateMgr : public StateStateMgr<T, FStateFactory>
{
public:
    FStateStateMgr(T& obj, const StateID& stateID = StateID::cNull) :
        StateStateMgr<T, FStateFactory>(obj, stateID) {}

    virtual ~FStateStateMgr() {}
};