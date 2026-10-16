#pragma once

#include "sead.h"

// Size: 0x58
// Vtable: 0x005CD240
class QuakeMgr
{
    SEAD_SINGLETON_DISPOSER(QuakeMgr);
public:
    enum QuakeFlag : u32
    {
        QuakeFlag_None           = 0,

        // Impact Flags
        QuakeFlag_ImpactSmall    = 1 << 0,  // Will bounce enemies
        QuakeFlag_ImpactMedium   = 1 << 1,  // Will kill enemies
        QuakeFlag_ImpactLarge    = 1 << 2,  // Will kill enemies with high speed & make coins fall

        // Player Flags
        QuakeFlag_Unk8           = 1 << 3,   // Checked in playerMgr::execute
        QuakeFlag_BouncePlayer   = 1 << 4,
        QuakeFlag_StunPlayer     = 1 << 5,
        QuakeFlag_Unk40          = 1 << 6,   // This gets used in playerMgr::doCoopShake
    };

    enum ContinuousShockType : u32
    {
        ContinuousShockType_Unk0    = 0,
        ContinuousShockType_Unk1    = 1,
        ContinuousShockType_Unk2    = 2,
        ContinuousShockType_Unk3    = 3,
        ContinuousShockType_Unk4    = 4,
        ContinuousShockType_Unk5    = 5,
        ContinuousShockType_Unk6    = 6,    // Used by KoopaLast::State_AC & KoopaLast::State_AA
        ContinuousShockType_Unk7    = 7,    // Used by Koopa::State_96
    };

    enum ShockType : u32
    {                                       //              Target, Intensity, Damping, MaxStep, MinStep
        ShockType_Common            = 0,    // QuakeConfig { 0.0,   4.0,       0.0625,  1.0,     0.0625 } - Used by PowBlock, Skewer, Whomp & others
        ShockType_PlayerMegaStep    = 1,    // QuakeConfig { 0.0,   1.5,       0.3,     1.0,     0.0625 } - Used by PlayerObject::Update if player is Mega + Walking
        ShockType_PlayerMegaLand    = 2,    // QuakeConfig { 0.0,   1.625,     0.1,     1.0,     0.0625 } - Used by PlayerObject::UpdateJumpFall if player is Mega && lands
        ShockType_SyncGroundPound   = 3,    // QuakeConfig { 0.0,   4.0,       0.0625,  1.0,     0.0625 } - Used by PlayerMgr::doQuake && PlayerMgr::doCoopQuake
        ShockType_Unk4              = 4,    // QuakeConfig { 0.0,   2.5,       0.0625,  1.0,     0.0625 } - Used by EndingBoss::State_3E & Roy::State_11A & Rock::vf1E4/vf1E8 & Koopa::State_8D & Roy Crash
        ShockType_Unk5              = 5,    // QuakeConfig { 0.0,   1.0,       0.3,     1.0,     0.0625 } - Used by KoopaLastDemo::State_B3 && FireBallPlayer::State_14D
        ShockType_Unk6              = 6,    // QuakeConfig { 0.0,   4.0,       0.0625,  1.0,     0.0625 } -
        ShockType_Unk7              = 7,    // QuakeConfig { 0.0,   7.25,      0.0625,  1.0,     0.0312 } -
        ShockType_Unk8              = 8,    // QuakeConfig { 0.0,   15.0,      0.0625,  1.5,     0.0625 } -
        ShockType_Unk9              = 9,    // QuakeConfig { 0.0,   4.0,       0.0625,  1.0,     0.0625 } -
        ShockType_Unk10             = 10,   // QuakeConfig { 0.0,   3.0,       0.0625,  1.0,     0.0625 } -
        ShockType_Unk11             = 11,   // QuakeConfig { 0.0,   5.0,       0.0625,  1.0,     0.0625 } -
        ShockType_Unk12             = 12,   // QuakeConfig { 0.0,   4.0,       0.0625,  1.0,     0.0625 } - Used by Koopa::State_DieFumi && KoopaLast::State_AB
        ShockType_Unk13             = 13,   // QuakeConfig { 0.0,   10.0,      0.0625,  0.5,     0.0625 } - Used by KoopaLast::State_AC
        ShockType_BossShutter       = 14,   // QuakeConfig { 0.0,   2.5,       0.0625,  1.0,     0.0625 } -

        // Continuous Types                                         //              Target, Intensity, Damping, MaxStep, MinStep
        ShockType_ContinuousUnk0 = 15 + ContinuousShockType_Unk0,   // QuakeConfig { 2.0,   2.0,       0.0625,  1.0,     0.0625 } -
        ShockType_ContinuousUnk1 = 15 + ContinuousShockType_Unk1,   // QuakeConfig { 4.0,   5.0,       0.0625,  1.0,     0.0625 } -
        ShockType_ContinuousUnk2 = 15 + ContinuousShockType_Unk2,   // QuakeConfig { 1.75,  1.75,      0.0625,  1.0,     0.0625 } -
        ShockType_ContinuousUnk3 = 15 + ContinuousShockType_Unk3,   // QuakeConfig { 1.25,  1.25,      0.0625,  1.0,     0.0625 } -
        ShockType_ContinuousUnk4 = 15 + ContinuousShockType_Unk4,   // QuakeConfig { 1.25,  1.25,      0.0625,  1.0,     0.0625 } -
        ShockType_ContinuousUnk5 = 15 + ContinuousShockType_Unk5,   // QuakeConfig { 1.25,  1.25,      0.0625,  1.0,     0.0625 } -
        ShockType_ContinuousUnk6 = 15 + ContinuousShockType_Unk6,   // QuakeConfig { 2.0,   2.0,       0.0625,  1.0,     0.0625 } -
        ShockType_ContinuousUnk7 = 15 + ContinuousShockType_Unk7,   // QuakeConfig { 1.0,   1.0,       0.0625,  1.0,     0.0625 } -
    };

    enum ShockFlag : u32
    {
        Shock_Camera    = 1 << 0,
        Shock_Motor     = 1 << 1    // Exists in Wii/U but unused here 
    };


    enum CamFlag : u8
    {
        CamFlag_None = 0,
        CamFlag_ReduceXMovement = 2,
    };

private:
    struct QuakeConfig
    {
        f32 mTargetIntensity;   // 0
        f32 mIntensity;         // 4
        f32 mDampingFactor;     // 8
        f32 mMaxStep;           // C
        f32 mMinStep;           // 10
    };
    size_assert(QuakeConfig, 0x14);

public:
    // Address D1: 0x00428F74
    // Address D2: 0x00428F70
    virtual ~QuakeMgr();

    // Address: 0x00428A60
    void doQuake(s8 playerIdx, ShockType shockType, ShockFlag shockFlag, u32 quakeFlags);   // Used by player e.g. when doing coop-groundPound etc

    // Address: 0x00428AE0
    void doQuake(s8 playerIdx, ShockType shockType, u32 quakeFlags);                        // Used by OpeningDemoMgr - does not enable impact timer

    // Address: 0x00428B78
    void doQuake(ShockType shockType, ShockFlag shockFlag, u32 quakeFlags);                 // Used by several things

    // Address: 0x00428B34
    void doContinuousQuake(ContinuousShockType shockType, ShockFlag shockFlag);             // Does not enable impact timers

    // Address: 0x00428D7C
    void execute();

    // Address: 0x00428F60
    void stopQuake();

    // Inlined
    const Vec2f& getCamOffset() const { return mCamOffset; }

    // Inlined
    const u32 getQuakeFlags() const { return mQuakeFlags; }

    // Inlined
    const u8 getPlayerIdx() const { return mPlayerIdx; }

    // Inlined
    void setCamFlags(CamFlag camFlags) { mCamFlags = camFlags; }

private:
    QuakeConfig mConfig[2];             // 14
    u32 mQuakeFlags;                    // 3C
    u8 mCamFlags;                       // 40 - This is never set to anything, and only ever checked as & 2
    bool mActive;                       // 41
    u8 mPlayerIdx;                      // 42
    u32 mMediumImpactTimer;             // 44
    u32 mLargeImpactTimer;              // 48
    Vec2f mCamOffset;                   // 4C
    u32 mQuakeTimer;                    // 54 
};

size_assert(QuakeMgr, 0x58);