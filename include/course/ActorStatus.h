#pragma once

#include "boss/BossDemo.h"
#include "sead.h"

class ActorStatus
{
    SEAD_SINGLETON_DISPOSER(ActorStatus);
public:
    struct FireBallPlayerInfo
    {
        s32 _0;     // 0
        s32 _4;     // 4
    };

    f32 _10;                                    // 10   init to -8000.0, assigned in GoalPole onCreate, used in JugemCloud state 297
    bool _14;                                   // 14   set to true in GoalPole sub_4145B4, is checked in SwitchFlagMgr::updateSwitches
    BossDemo* bossDemo;                         // 18   assigned in BossDemo onCreate
    bool bossDemoIsActive;                      // 1C   set to true in BossDemo vf118
    void* _20;                                  // 20   this is a KoopaLastLiftMgr ptr
    s32 _24;                                    // 24   used in various BgActorBase states
    u32 _28;                                    // 28   incremented in BgActorLava/Water/Poison onCreate
    u32 redCoinGroupACount[8];                  // 2C   used in RedCoinBase execute State Idle/handleCoinCollected/Deactivate
    u32 redCoinGroupBCount[8];                  // 4C   used in RedCoinBase execute State Idle/handleCoinCollected/Deactivate
    FireBallPlayerInfo fireBallPlayerInfo[2];   // 6C   used in FireBallPlayer 0x144, FireBallPlayer onDelete/vf138
    s32 fireBallPakkunCount;                    // 7C   dec in FireBallPakkun onDelete, inc in FireBallPakkun vf138
    s32 fireBallBrosCount;                      // 80   decremented in FireBallBros/Keronpa onDelete, incremented in FireBallBros vf138
    s32 kuriboCount;                            // 84   used in EnemyGenerator spawnGoomba
    s32 killerCount;                            // 88   inc in Killer onCreate, dec in KillerBase onDelete, used in KillerBase spawnKiller
    u32 _8C[32];                                // 8C
    u32 _10C[32];                               // 10C
    u32 _18C;                                   // 18C
    u32 _190[2];                                // 190
    s32 bomheiCount;                            // 198  incremented in Bomhei onCreate, decremented in Bomhei onDelete, used in EnemyGenerator spawnBobOmb
    u16 _19C;                                   // 19C  increment in Teresa onCreate (wrap 0 - 7)
    u32 _1A0;                                   // 1A0
    u32 _1A4;                                   // 1A4  incremented in BuiBui setup, decremented in BuiBui damagedLast
    u32 _1A8;                                   // 1A8  incremented in BuiBui setup
    u8 _1AC;                                    // 1AC  set to true in BuiBui sub_3D1358
    u8 _1AD;                                    // 1AD  checked in BuiBui sub_3D1294
    s32 goldRingActiveCount;                    // 1B0  this is a counter, each ring is +1, active while non 0
    u32 quakeKillCount;                         // 1B4  used in DokanPakkunBase, Enemy, set to 0 in QuakeMgr UnkQuake
    u8 _1B8;                                    // 1B8  checked in NetEnemy onExecute/vf1E0/vf1EC
};

size_assert(ActorStatus, 0x1BC);
