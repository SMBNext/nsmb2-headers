#pragma once

#include "state/StateStateMethod.h"
#include "state/StateMgr.h"

template <typename T, template <typename FactoryT> class Factory>
class StateStateMgr
{
    STATE_MGR_BASE_BODY(StateStateMgr, StateStateMethod)

public:
    void changeToSubState(const StateID& stateID)
    {
        mMethod.changeToSubStateMethod(stateID);
    }

    bool isSubState() const
    {
        return mMethod.isSubStateMethod();
    }

    void returnState()
    {
        mMethod.returnStateMethod();
    }

    void replaceState(const StateID& stateID)
    {
        mMethod.replaceStateMethod(stateID);
    }

    const StateID* getMainStateID() const
    {
        return mMethod.getMainStateID();
    }
};