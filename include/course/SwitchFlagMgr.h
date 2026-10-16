#pragma once

#include "sead/heap/seadDisposer.h"
#include "types.h"

// size: 0x930
class SwitchFlagMgr
{
    SEAD_SINGLETON_DISPOSER(SwitchFlagMgr);
public:
    static const u32 sFlagNum = 64;
    static const u32 sSwitchNum = 3;

public:
    enum class SwitchType
    {
        SwitchP         = 0,    // P Switch
        SwitchBikkuri   = 1,    // Exclamation Switch
        SwitchHatena    = 2     // Question Switch
    };

    enum class TimerStatusFlags : u8
    {
        Expired     = 1 << 0,   // Plays expiration sound while set
        TimeLow     = 1 << 1,   // Plays low time sound while set
        Running     = 1 << 2,   // Plays ticking sound while set
    };

    struct FlagTimerInfo
    {
        u32 duration;   // 0
        u32 musicFlag;  // 4 - &1 = no music
        u32 flags;      // 8 - &1 = enabled after timer, else disable, &2 = timer sound enabled
    };

    size_assert(FlagTimerInfo, 0xC);

    struct LiquidMoveInfo
    {
        u64 _0;             // 0  - Set to/from BgActorBase->_8480
        f32 yPosition;      // 8  - Set to/from BgActorBase->position.y
        f32 distToTop;      // C  - Set to/from BgActorBase->distToTop
        u8 _10;             // 10 - Set to/from BgActorBase->_84A3
        bool hasLiquidInfo; // 11
    };

    size_assert(LiquidMoveInfo, 0x18);

public:

    // Address: 0x0011F160
    static s64 makeMask(s64 value, u32 bitIndex);       // This might not actually be part of SwitchFlagMgr...

    // Address: 0x002A7EFC
    void initForArea(bool atStartOfLevel, u8 areaId);   // Resets timer flags and loads inital area flags if atStartOfLevel is true

    // Address: 0x002A8080
    void set(u8 id, u32 duration, bool active, bool reversed, bool enableTimerSound, u32 musicFlag);    // Duration = 0 Permanent. Duration is units of 1=1/6 second. Reversed disables event while active.

    // Address: 0x002A82C8
    void updateFlags();                             // Called in SwitchFlagMgr::execute()

    // Address: 0x002A84EC
    void reset();                                   // Resets everything, called in ScCourse::onCreate()

    // Address: 0x002A8564
    u64 getFlagMask(u32 targetID, u32 triggerID);   // Returns a mask for triggerID if it is set, otherwise returns a mask for targetID

    // Address: 0x002A8648
    void updateSwitches();                          // Called in SwitchFlagMgr::execute()

    // Address: 0x002A8850
    u8 getIndexOfMask(u64 mask);                    // Returns the flag index a mask is for. Returns 255 if no index is found

    // Address: 0x002A88D0
    void setLiquidMoveInfo(u8 id, const LiquidMoveInfo& info);

    // Address: 0x002A8934
    void execute();

    // Address: 0x002A89D4
    void resetFlagTimerInfo();  // Resets all FlagTimerInfo to 0, and disables any switch music that was playing

    inline bool isActive(u8 id)
    {
        return (makeMask(1, id) & mSwitchFlag) != 0;
    }

    inline bool isInactive(u8 id)
    {
        return (makeMask(1, id) & mSwitchFlag) == 0;
    }

    inline void set(u8 id, bool active)
    {
        mSwitchFlag &= ~makeMask(1, id);
        if (active)
            mSwitchFlag |= makeMask(1, id);
    }

    // Inlined
    FlagTimerInfo* timerInfo(u8 id)
    {
        if (id < 64)
            return &mTimerInfo[id];
        return nullptr;
    }

    // Inlined
    LiquidMoveInfo* liquidInfo(u8 id)
    {
        if (id < 64)
            return &mLiquidMoveInfo[id];
        return nullptr;
    }

    // Inlined
    TimerStatusFlags getTimerStatus() const
    {
        return mTimerStatus;
    }

    // Inlined
    s8 getPlayerIndex() const
    {
        return mPlayerIndex;
    }

    // Inlined
    void setSwitchEnabled(SwitchType switchType, u32 duration)
    {
        mSwitchTimers[static_cast<u32>(switchType)] = duration * 10;
        mSwitchButtonFlag |= (1 << static_cast<u32>(switchType));
    }

    bool isSwitchEnabled(SwitchType switchType) const
    {
        return mSwitchButtonFlag & (1 << static_cast<u32>(switchType));
    }

private:
    u64 mSwitchFlag;                            // 10  - Event flags 
    FlagTimerInfo mTimerInfo[sFlagNum];         // 18  - Contains timer metadata associated with each flag
    LiquidMoveInfo mLiquidMoveInfo[sFlagNum];   // 318 - Contains liquid movement metadata associated with each flag 
    s8 mPlayerIndex;                            // 918 - Player who activated the last event? Checked in KoopaFloor::State_A1
    u32 mSwitchButtonFlag;                      // 91C - Flags for activation state of P, ? and ! switches
    s32 mSwitchTimers[sSwitchNum];              // 920 - Timers for P, ? and ! switches
    TimerStatusFlags mTimerStatus;              // 92C - Used to determine when to play sfx (e.g. Tick, Expired) while a timer is active. Reset to 0 at the start of every frame in execute
    bool mTimerPaused;                          // 92D - Is true when players are inactive e.g. in pipe etc - unsure if correct
};

size_assert(SwitchFlagMgr, 0x930);