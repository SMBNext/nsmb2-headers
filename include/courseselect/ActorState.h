#pragma once

#include "courseselect/Actor.h"
#include "state/FStateStateMgr.h"

namespace course_select {
class ActorState : public Actor   // Size: 0xB8
{
public:
    ActorState();
    virtual ~ActorState();

    void changeState(const StateID& stateID);

    FStateStateMgr<ActorState> stateMgr;
};
}
