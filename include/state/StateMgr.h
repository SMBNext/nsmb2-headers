#pragma once

#include "state/StateMethod.h"

#define STATE_MGR_BASE_BODY(CLASS, METHOD)                  \
    public:                                                 \
        CLASS(T& obj, const StateID& stateID) :             \
            mFactory(obj), mMethod(mFactory, stateID) {}    \
                                                            \
        virtual ~CLASS() {}                                 \
                                                            \
        void executeState()                                 \
        {                                                   \
            mMethod.executeStateMethod();                   \
        }                                                   \
                                                            \
        void changeState(const StateID& stateID)            \
        {                                                   \
            mMethod.changeStateMethod(stateID);             \
        }                                                   \
                                                            \
        IState* getState() const                            \
        {                                                   \
            return mMethod.getState();                      \
        }                                                   \
                                                            \
        const StateID* getNewStateID() const                \
        {                                                   \
            return mMethod.getNewStateID();                 \
        }                                                   \
                                                            \
        const StateID* getStateID() const                   \
        {                                                   \
            return mMethod.getStateID();                    \
        }                                                   \
                                                            \
        const StateID* getOldStateID() const                \
        {                                                   \
            return mMethod.getOldStateID();                 \
        }                                                   \
                                                            \
    protected:                                              \
        Factory<T> mFactory;                                \
        METHOD mMethod;

template <typename T, template <typename FactoryT> class Factory>
class StateMgr
{
    STATE_MGR_BASE_BODY(StateMgr, StateMethod)
};