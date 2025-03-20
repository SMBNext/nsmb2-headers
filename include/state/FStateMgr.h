#pragma once

#include "state/FStateFactory.h"
#include "state/StateMgr.h"

template <typename T>
class FStateMgr : public StateMgr<T, FStateFactory>
{
public:
    FStateMgr(T& obj, const StateID& stateID = StateID::cNull) :
        StateMgr<T, FStateFactory>(obj, stateID) {}

    virtual ~FStateMgr() {}
};