#pragma once

#include "state/FStateID.h"
#include "state/IState.h"

template <typename T>
class FState : public IState
{
public:
    FState(T& obj) :
        mObject(obj), mStateID(nullptr) {}

    T& getObject() const
    {
        return mObject;
    }

    const StateID* getStateID() const override
    {
        return mStateID;
    }

    void setStateID(const FStateID<T>* stateID)
    {
        mStateID = stateID;
    }

    void initialize()
    {
        mStateID->initializeState(mObject);
    }

    void execute() override
    {
        mStateID->executeState(mObject);
    }

    void finalize()
    {
        mStateID->finalizeState(mObject);
    }

protected:
    T& mObject;
    const FStateID<T>* mStateID;
};