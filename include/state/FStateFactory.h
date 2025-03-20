#pragma once

#include "state/FState.h"
#include "state/IStateFactory.h"

template <typename T>
class FStateFactory : public IStateFactory
{
public:
    FStateFactory(T& obj) :
        mState(obj) {}

    virtual ~FStateFactory() {}

    IState* buildWithInitialize(const StateID& stateId) override
    {
        mState.setStateID(static_cast<const FStateID<T>*>(&stateId));
        mState.initialize();
        return &mState;
    }

    void disposeWithFinalize(IState*& state) override
    {
        mState.finalize();
        mState.setStateID(nullptr);
        state = nullptr;
    }

    IState* build(const StateID& stateId) override
    {
        mState.setStateID(static_cast<const FStateID<T>*>(&stateId));
        return &mState;
    }

    void dispose(IState*& state) override
    {
        mState.setStateID(nullptr);
        state = nullptr;
    }

    void initializeState(IState* state) override
    {
        static_cast<FState<T>*>(state)->initialize();
    }

protected:
    FState<T> mState;
};