#pragma once

#include "ActorCollision.h"
#include "state/FStateStateMgr.h"
#include "state/FStateVirtualID.h"

class ActorMultiState : public ActorCollision
{
    SEAD_RTTI_OVERRIDE(ActorMultiState, ActorCollision);

public:
    ActorMultiState();

    virtual void changeState(const StateID& stateID);

    FStateStateMgr<ActorMultiState> stateMgr;     // FC4
};

size_assert(ActorMultiState, 0xFEC);
