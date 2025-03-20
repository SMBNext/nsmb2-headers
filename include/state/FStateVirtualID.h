#pragma once

#include "state/FStateID.h"

template <typename T>
class FStateVirtualID : public FStateID<T>
{
public:
    using FuncPtr = typename FStateID<T>::FuncPtr;

public:
    FStateVirtualID(FuncPtr initialize, FuncPtr execute, FuncPtr finalize, const StateID& baseID) :
        FStateID<T>(initialize, execute, finalize), mBaseID(&baseID) {}

    virtual ~FStateVirtualID() {}

    s32 number() const override
    {
        if (!mBaseID->isNull())
            return mBaseID->number();

        return StateID::mNumber;
    }

    const StateID* superID() const
    {
        return mBaseID;
    }

protected:
    const StateID* mBaseID;
};

#define DECLARE_STATE_VIRTUAL_ID_BASE(CLASS, NAME)          \
    static FStateVirtualID<CLASS> StateID_##NAME;           \
    virtual void initializeState_##NAME();                  \
    virtual void executeState_##NAME();                     \
    virtual void finalizeState_##NAME();

#define DECLARE_STATE_VIRTUAL_ID_OVERRIDE(CLASS, NAME)      \
    static FStateVirtualID<CLASS> StateID_##NAME;           \
    void initializeState_##NAME() override;                 \
    void executeState_##NAME() override;                    \
    void finalizeState_##NAME() override;                   \

#define CREATE_STATE_VIRTUAL_ID_BASE(CLASS, NAME)           \
    FStateVirtualID<CLASS> CLASS::StateID_##NAME            \
        (&CLASS::initializeState_##NAME,                    \
         &CLASS::executeState_##NAME,                       \
         &CLASS::finalizeState_##NAME,                      \
         StateID::cNull);

#define CREATE_STATE_VIRTUAL_ID_OVERRIDE(CLASS, BASE, NAME) \
    FStateVirtualID<CLASS> CLASS::StateID_##NAME            \
        (&CLASS::initializeState_##NAME,                    \
         &CLASS::executeState_##NAME,                       \
         &CLASS::finalizeState_##NAME,                      \
         BASE::StateID_##NAME);
