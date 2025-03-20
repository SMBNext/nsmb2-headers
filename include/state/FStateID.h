#pragma once

#include "state/StateID.h"

template <typename T>
class FStateID : public StateID
{
public:
    using FuncPtr = void (T::*)();

public:
    FStateID(FuncPtr initialize, FuncPtr execute, FuncPtr finalize) :
        mInitialize(initialize), mExecute(execute), mFinalize(finalize) {}

    virtual ~FStateID() {}

    void initializeState(T& obj) const
    {
        (obj.*mInitialize)();
    }

    void executeState(T& obj) const
    {
        (obj.*mExecute)();
    }

    void finalizeState(T& obj) const
    {
        (obj.*mFinalize)();
    }

protected:
    FuncPtr mInitialize;
    FuncPtr mExecute;
    FuncPtr mFinalize;
};

#define DECLARE_STATE_ID(CLASS, NAME)       \
    static FStateID<CLASS> StateID_##NAME;  \
    void initializeState_##NAME();          \
    void executeState_##NAME();             \
    void finalizeState_##NAME();

#define CREATE_STATE_ID(CLASS, NAME)        \
    FStateID<CLASS> CLASS::StateID_##NAME   \
        (&CLASS::initializeState_##NAME,    \
         &CLASS::executeState_##NAME,       \
         &CLASS::finalizeState_##NAME);
