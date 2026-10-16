#pragma once

#include "ActorCollision.h"
#include "state/FStateStateMgr.h"
#include "state/FStateVirtualID.h"
#include "state/StateID.h"

// Size: 0xFEC
class ActorMultiState : public ActorCollision
{
    SEAD_RTTI_OVERRIDE(ActorMultiState, ActorCollision);
public:
    ActorMultiState();

    // Changes the current state to the specified state.
    virtual void changeState(const StateID& stateID);

    // Changes the current state to the specified sub-state.
    inline void changeToSubState(const StateID& stateID)
    {
        mStateMgr.changeToSubState(stateID);
    }

    // Returns to the main state from a sub-state.
    inline void returnToMainState()
    {
        mStateMgr.returnState();
    }

    // Executes the current state.
    inline void executeState()
    {
        mStateMgr.executeState(); 
    }

    // Returns the current state ID.
    inline const StateID* getCurrentStateID() const
    {
        return mStateMgr.getStateID();
    }
    
    // Returns true if the current state matches the specified state ID.
    inline bool isState(const StateID& stateID) const
    {
        return *mStateMgr.getStateID() == stateID;
    }

    // Returns true if the current state matches the specified state number.
    inline bool isStateNumber(s32 number) const
    {
        return mStateMgr.getStateID()->number() == number;
    }
    
    // Returns true if the previous state matches the specified state ID.
    inline bool isLastState(const StateID& stateID) const
    {
        return *mStateMgr.getOldStateID() == stateID;
    }

    // Returns true if the new state matches the specified state ID.
    inline bool isNextState(const StateID& stateID) const
    {
        return *mStateMgr.getNewStateID() == stateID;
    }
    
    // Returns true if the main state matches the specified state ID.
    inline bool isMainState(const StateID& stateID) const
    {
        return *mStateMgr.getMainStateID() == stateID;
    }

private:
    /* 0xFC4 */  FStateStateMgr<ActorMultiState> mStateMgr;
};

size_assert(ActorMultiState, 0xFEC);
