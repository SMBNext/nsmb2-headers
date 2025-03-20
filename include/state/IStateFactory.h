#pragma once

#include "types.h"

class IState;
class StateID;

class IStateFactory
{
public:
    IStateFactory() {}

    virtual ~IStateFactory() {}

    virtual IState* buildWithInitialize(const StateID& stateId) = 0;
    virtual void disposeWithFinalize(IState*& state) = 0;
    virtual IState* build(const StateID& stateId) = 0;
    virtual void dispose(IState*& state) = 0;
    virtual void initializeState(IState* state) = 0;
};

size_assert(IStateFactory, 4);