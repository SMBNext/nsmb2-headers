#pragma once

#include "types.h"
#include "math/Vec.h"

#include "actors/ScoreMgr.h"
#include "state/StateID.h"

// Size: 0x1C
class EnemyDeathInfo
{
    struct KillArg
    {
        KillArg(u32 arg = 0) :
            arg(arg) {}

        KillArg(ScoreMgr::RewardType rewardType, u8 killDirection, s8 playerId) :
            rewardType(rewardType), killDirection(killDirection), playerId(playerId) {}

            union 
            {
                struct
                {
                    ScoreMgr::RewardType rewardType;
                    u8 killDirection;
                    s8 playerId;
                };
                u32 arg;
            };
    };

public:

    // Address: 0x005733F4
    static f32 sDefaultFallSpeedMax; // -4.0

    // Address: 0x005E64E8
    static f32 sDefaultFallAcceleration; // -0.24375

public:
    EnemyDeathInfo() :
        mSpeed({ 1.5f, 3.9f }),
        mFallSpeedMax(sDefaultFallSpeedMax),
        mFallAcceleration(sDefaultFallAcceleration),
        mStateID(nullptr),
        mKillArg({ ScoreMgr::RewardType::Points_100, 0, -1 }),
        mNoRespawn(false) {}

    EnemyDeathInfo(const Vec2f& speed, f32 fallSpeedMax, f32 fallAcceleration, const StateID* stateID) :
        mSpeed(speed),
        mFallSpeedMax(fallSpeedMax),
        mFallAcceleration(fallAcceleration),
        mStateID(stateID) {}

    void setKillArg(ScoreMgr::RewardType rewardType, u8 killDirection, s8 playerId)
    {
        mKillArg.rewardType = rewardType;
        mKillArg.killDirection = killDirection;
        mKillArg.playerId = playerId;
    }

    // Address: 0x002E84B0
    void setNoRespawn(const EnemyDeathInfo& info);

private:
    Vec2f mSpeed;
    f32 mFallSpeedMax;
    f32 mFallAcceleration;
    const StateID* mStateID;
    KillArg mKillArg;
    bool mNoRespawn;
};

size_assert(EnemyDeathInfo, 0x1C);