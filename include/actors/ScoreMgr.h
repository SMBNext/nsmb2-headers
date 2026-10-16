#pragma once

#include "math/Vec.h"
#include "sead/heap/seadDisposer.h"
#include "types.h"

class ActorBase;

// Size 0x18
class ScoreMgr
{
    SEAD_SINGLETON_DISPOSER(ScoreMgr);
public:

    enum class CoinType : u8
    {
        cCoins5     = 0,    //
        cCoins10    = 1,    //
        cCoins15    = 2,    //
        cCoins20    = 3,    //
        cCoins30    = 4,    //
        cCoins40    = 5,    //
        cCoins50    = 6,    //
        cCoins100   = 7     //
    };

    enum class RewardType : u8
    {
        cPoints100  = 0,    //
        cPoints200  = 1,    //
        cPoints400  = 2,    //
        cPoints800  = 3,    //
        cPoints1000 = 4,    //
        cPoints2000 = 5,    //
        cPoints4000 = 6,    //
        cPoints8000 = 7,    //

        cLives1UP   = 8,    //
        cLives3UP   = 9     // This is a leftover and does not work correctly.
    };

    enum class RewardTypeBig : u8
    {
        cPoints1000 = 0,    // A value of 1 is also 1000 points.
        cPoints2000 = 2,    //
        cPoints4000 = 3,    //
        cPoints8000 = 4,    //
        cLives1UP   = 5,    // Values above 5 are also a 1-UP.
    };

    enum class TimeType : u8
    {
        cTime10     = 0,    //
        cTime50     = 1,    //
        cTime100    = 2,    //
        cTime150    = 3,    //
        cTime200    = 4,    //
    };

public:
    // Adds lives to the specified player.
    void addLife(s8 playerNum, u8 numLives, bool playSound);

    // Gives Coins. Spawns coin popup at specified position.
    void addCoins(const Vec3f& position, CoinType coinType, s8 playerNum, bool stayOnScreen = false);

    // Gives Coins. Spawns coin popup at actor position with offset.
    void addCoins(const ActorBase& actor, CoinType coinType, s8 playerNum, f32 xOffset, f32 yOffset);

    // Gives Score to one player. Shows a score popup at player position.
    void addScore(RewardType rewardType, s8 playerNum, bool playSound);

    // Gives Score to one player. Shows a score popup at specified position.
    void addScore(const Vec3f& position, RewardType rewardType, s8 playerNum, bool playSound);

    // Gives Score to one player. Shows a score popup at actor position with offset.
    void addScore(const ActorBase& actor, RewardType rewardType, s8 playerNum, f32 xOffset, f32 yOffset);

    // Gives score to all players. Shows a score popup at specified position.
    void addScoreAll(const Vec3f& position, RewardType rewardType);

    // Gives Score to all players. Shows a score popup at actor position with offset.
    void addScoreAll(const ActorBase& actor, RewardType rewardType, f32 xOffset, f32 yOffset);

    // Gives Big Score to one player. Shows a score popup at specified position.
    void addScoreBig(const Vec3f& position, RewardTypeBig rewardType, s8 playerNum);

    // Gives Big Score to one player. Shows a score popup at actor position with offset.
    void addScoreBig(const ActorBase& actor, RewardTypeBig rewardType, s8 playerNum, f32 xOffset, f32 yOffset);

    // Shows a "timer" popup at specified position
    void showTime(const Vec3f& position, TimeType timeType, s8 playerNum);

    // Shows a "X2" popup at specified position.
    void showX2(const Vec3f& position, s8 playerNum, bool stayOnScreen = false);

    // Increments the current POW quake combo.
    inline void incrementPowCombo()
    {
        if (mPowCombo < 8)
        {
            ++mPowCombo;
        }
    }

    // Gets the current POW quake combo.
    inline s32 powCombo()
    {
        return mPowCombo;
    }

    // Increments the number of currently active POW quakes.
    inline void incrementActivePowCount()
    {
        if (mPowActiveCount <= 0)
        {
            mPowCombo = 1;
        }
        ++mPowActiveCount;
    }

    // Decrements the number of currently active POW quakes.
    inline void decrementActivePowCount()
    {
        if (mPowActiveCount > 0)
        {
            --mPowActiveCount;
        }
    }

private:
    /* 0x10 */  s32 mPowCombo;          // The number of enemies killed by POW quake (caps at 8).
    /* 0x14 */  s32 mPowActiveCount;    // The number of currently active POW quakes.
};

size_assert(ScoreMgr, 0x18);
