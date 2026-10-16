#pragma once

#include "types.h"
#include "actors/ScoreMgr.h"

// Size: 0x4
class Combo
{
public:
    enum class Type : u32
    {
        None    = 0,    // Gives no points
        Normal  = 1,    // Gives points starting from 100
        Big     = 2     // Gives points starting from 1000
    };

public:
    // Address C1: 0x001CEA74
    Combo();

    // Address: 0x00497404
    ScoreMgr::RewardType getComboScore(u32 comboCount);

    // Address: 0x00497448
    ScoreMgr::RewardType getQuakeScore(u32 comboCount);

    // Address: 0x0049746C
    ScoreMgr::RewardType getDamageScore();

    // Address: 0x00497480
    void setScore(ActorBase* actor, ScoreMgr::RewardType rewardType, s8 playerId);

    // Inlined
    Type getType() const
    {
        return mType;
    }

    // Inlined
    bool isBigComboType() const
    {
        return mType == Type::Big;
    }

    // I'm not sure this should exist...
    void setType(Type type)
    {
        mType = type;
    }

private:
    Type mType;
};

size_assert(Combo, 0x4);