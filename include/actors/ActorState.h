#pragma once

#include "ActorCollision.h"
#include "state/FStateMgr.h"
#include "state/FStateID.h"

class ActorState : public ActorCollision
{
    SEAD_RTTI_OVERRIDE(ActorState, ActorCollision);

public:
    ActorState();

    void changeState(const StateID& stateID);

    FStateMgr<ActorState> stateMgr;     // FC4
};

size_assert(ActorState, 0xFE8);

inline void ActorState::changeState(const StateID& stateID)
{
    stateMgr.changeState(stateID);
}
