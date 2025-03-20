#pragma once

#include "state/IState.h"
#include "state/IStateFactory.h"
#include "state/StateID.h"

class StateMethod
{
public:
    // Address: 0x00138800
    StateMethod(IStateFactory& factory, const StateID& stateID);

    void executeStateMethod() { executeStateLocalMethod_(); }

    // Address: 0x00138720
    void changeStateMethod(const StateID& stateID);

    IState* getState() const { return mState; }

    const StateID* getNewStateID() const { return mNewStateID; }
    
    // Address: 0x004855D0
    const StateID* getStateID() const;

    const StateID* getOldStateID() const { return mOldStateID; }

protected:
    void initializeStateLocalMethod_();
    // Address: 0x001387B0
    void executeStateLocalMethod_();
    void finalizeStateLocalMethod_();
    void changeStateLocalMethod_();

protected:
    IStateFactory& mFactory;
    const StateID* mNewStateID;
    IState* mState;
    const StateID* mOldStateID;
};

size_assert(StateMethod, 0x10);

inline void StateMethod::initializeStateLocalMethod_()
{
    if (mNewStateID != nullptr)
    {
        mState = mFactory.buildWithInitialize(*mNewStateID);
        mNewStateID = nullptr;
    }
}

inline void StateMethod::finalizeStateLocalMethod_()
{
    if (mState != nullptr && mNewStateID != nullptr)
    {
        mOldStateID = mState->getStateID();
        mFactory.disposeWithFinalize(mState);
    }
}

inline void StateMethod::changeStateLocalMethod_()
{
    finalizeStateLocalMethod_();
    initializeStateLocalMethod_();
}