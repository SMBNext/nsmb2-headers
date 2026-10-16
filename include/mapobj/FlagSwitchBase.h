#pragma once

#include "actors/ActorMultiState.h"
#include "types.h"

class PlayerBase;

// Size: 0x1008
class FlagSwitchBase : public ActorMultiState
{
    SEAD_RTTI_OVERRIDE(FlagSwitchBase, ActorMultiState);
public:
    FlagSwitchBase();
    
    Result onExecute() override;
    bool preDraw() override;

    // Checks if there are any players alive in the current zone, de-spawning if none are.
    void cullCheck();
    
    // Returns the first available player.
    PlayerBase* getPlayer();
    
protected:
    /* 0x0FEC */
    /* 0x0FED */
    /* 0x0FEE */
    /* 0x0FEF */
    /* 0x0FF0 */  s64 mFlagMask;          //
    /* 0x0FF8 */  s64 mLastFlag;          // Stores the state of `mFlagMask & mSwitchFlag` from the previous frame.
    /* 0x1000 */  s16 mDuration;          // The duration of the switch's effect.
    /* 0x1002 */  u8 mTargetFlag;         // 
    /* 0x1003 */  u8 mTriggeringFlag;     //
    /* 0x1004 */  u8 _1004[3];            //
    /* 0x1007 */  s8 mPlayerNo;           // The player that activated the switch.
};

size_assert(FlagSwitchBase, 0x1008);
