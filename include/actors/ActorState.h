#pragma once

#include "ActorCollision.h"
#include "state/FStateMgr.h"
#include "state/FStateID.h"

// Size: 0xFE8
class ActorState : public ActorCollision
{
    SEAD_RTTI_OVERRIDE(ActorState, ActorCollision);
public:
    ActorState();

    inline void changeState(const StateID& stateID)
    {
        mStateMgr.changeState(stateID);
    }

    inline void executeState()
    {
        mStateMgr.executeState(); 
    }

    // Returns true if the current state matches the specified state ID.
    inline bool isState(const StateID& stateID) const
    {
        return *mStateMgr.getStateID() == stateID;
    }

    // Returns true if the previous state matches the specified state ID.
    inline bool isLastState(const StateID& stateID) const
    {
        return *mStateMgr.getOldStateID() == stateID;
    }
    
private:
    /* 0xFC4 */  FStateMgr<ActorState> mStateMgr;
};

size_assert(ActorState, 0xFE8);
