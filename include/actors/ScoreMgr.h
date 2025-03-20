#pragma once

#include "sead.h"

class ActorBase;

// Size 0x18
class ScoreMgr
{
    // createInstance()                             Address: 0x0042C5B0
    // deleteInstance()                             Address: 0x0042C614
    // sInstance                                    Address: 0x005E7268
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x0042C7E8
    // SingletonDisposer_::sStaticDisposer          Address: 0x005E726C
    // SingletonDisposer_::vtbl                     Address: 0x005CD328
    SEAD_SINGLETON_DISPOSER(ScoreMgr);

public:

    enum class CoinType : u8
    {
        Coins_5   = 0,
        Coins_10  = 1,
        Coins_15  = 2,
        Coins_20  = 3,
        Coins_30  = 4,
        Coins_40  = 5,
        Coins_50  = 6,
        Coins_100 = 7
    };

    enum class RewardType : u8
    {
        Points_100  = 0,
        Points_200  = 1,
        Points_400  = 2,
        Points_800  = 3,
        Points_1000 = 4,
        Points_2000 = 5,
        Points_4000 = 6,
        Points_8000 = 7,

        Lives_1UP = 8,
        Lives_3UP = 9 // This is a leftover and does not work correctly
    };

    enum class RewardTypeBig : u8
    {
        Reward_1000 = 0, // is also 1
        Reward_2000 = 2,
        Reward_4000 = 3,
        Reward_1UP  = 4, // >= 4 is 1UP
    };

    enum class TimeType : u8
    {
        Time_10  = 0,
        Time_50  = 1,
        Time_100 = 2,
        Time_150 = 3,
        Time_200 = 4,
    };

public:

    // Address: 0x0042C4C4
    // PlayerId and numLives are both unused args
    void addLife(s8 playerId, u8 numLives, bool playSound);

    // Address: 0x0042C43C
    // Gives Coins. Spawns coin popup at specified position
    void addCoins(const Vec3f& position, CoinType coinType, s8 playerId, bool stayOnScreen = false);

    // Address: 0x0042C81C
    // Gives Coins. Spawns coin popup at actor position with offset
    void addCoins(const ActorBase& actor, CoinType coinType, s8 playerId, f32 xOffset, f32 yOffset);

    // Address: 0x0042C650
    // Gives Score to one player. Spawns score popup at player position
    void addScore(RewardType rewardType, s8 playerId, bool playSound);

    // Address: 0x0042CA70
    // Gives Score to one player. Spawns score popup at specified position
    void addScore(const Vec3f& position, RewardType rewardType, s8 playerId, bool playSound);

    // Address: 0x0042C7A4
    // Gives Score to one player. Spawns score popup at actor position with offset
    void addScore(const ActorBase& actor, RewardType rewardType, s8 playerId, f32 xOffset, f32 yOffset);

    // Address: 0x0042C714
    // Gives score to all players. Spawns score popup at specified position
    void addScoreAll(const Vec3f& position, RewardType rewardType);

    // Address: 0x0042C97C
    // Gives Score to all players. Spawns score popup at actor position with offset
    void addScoreAll(const ActorBase& actor, RewardType rewardType, f32 xOffset, f32 yOffset);

    // Address: 0x0042C52C
    // Gives Big Score to one player. Spawns score popup at specified position
    void addScoreBig(const Vec3f& position, RewardTypeBig rewardType, s8 playerId);

    // address: 0x0042C8C8
    // Gives Big Score to one player. Spawns score popup at actor position with offset
    void addScoreBig(const ActorBase& actor, RewardTypeBig rewardType, s8 playerId, f32 xOffset, f32 yOffset);

    // Address: 0x0042CA3C
    // Spawns timer popup at specified position
    void showTime(const Vec3f& position, TimeType timeType, s8 playerId);

    // Address: 0x0042C6E4
    // Spawns X2 popup at specified position
    void showX2(const Vec3f& position, s8 playerId, bool stayOnScreen = false);

    // Increments the current POW quake combo
    inline void incrementPowCombo()
    {
        if (mPowCombo < 8)
        {
            ++mPowCombo;
        }
    }

    // Gets the current POW quake combo
    inline s32 powCombo()
    {
        return mPowCombo;
    }

    // Increments the number of currently active POW quakes
    inline void incrementActivePowCount()
    {
        if (mPowActiveCount <= 0)
        {
            mPowCombo = 1;
        }
        ++mPowActiveCount;
    }

    // Decrements the number of currently active POW quakes
    inline void decrementActivePowCount()
    {
        if (mPowActiveCount > 0)
        {
            --mPowActiveCount;
        }
    }

private:
    s32 mPowCombo;          // number of enemies killed by POW quake (caps at 8)
    s32 mPowActiveCount;    // number of currently active POW quakes
};

size_assert(ScoreMgr, 0x18);