#pragma once

#include "state/StateIDHolder.h"
#include "state/StateMethod.h"

class StateStateMethod : public StateMethod
{
public:
    StateStateMethod(IStateFactory& factory, const StateID& stateID) :
        StateMethod(factory, stateID) {}

    void changeToSubStateMethod(const StateID& stateID)
    {
        mMain.set(getStateID());
        mOldStateID = mState->getStateID();
        mFactory.dispose(mState);
        mState = mFactory.buildWithInitialize(stateID);
    }

    bool isSubStateMethod() const
    {
        return mMain.isSet();
    }

    void returnStateMethod()
    {
        mOldStateID = mState->getStateID();
        mFactory.disposeWithFinalize(mState);
        const StateID& mainStateID = *(mMain.get());
        mMain.reset();
        mState = mFactory.build(mainStateID);
    }

    void replaceStateMethod(const StateID& stateID)
    {
        mFactory.disposeWithFinalize(mState);
        mState = mFactory.buildWithInitialize(stateID);
    }

    const StateID* getMainStateID() const
    {
        const StateID* stateID = mMain.get();
        if (stateID == nullptr)
            stateID = getStateID();
        return stateID;
    }

protected:
    StateIDHolder mMain;
};

size_assert(StateStateMethod, 0x14);