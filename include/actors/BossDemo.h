#pragma once

#include "actors/ActorState.h"
#include "state/FStateVirtualID.h"

class BossDemo : public ActorState
{
    SEAD_RTTI_OVERRIDE(BossDemo, ActorState);

public:
    BossDemo();

    int onCreate() override;
    int onDelete() override;
    int onExecute() override;
    int beforeDraw() override;

    DECLARE_STATE_VIRTUAL_ID_BASE(BossDemo, Wait);
    DECLARE_STATE_VIRTUAL_ID_BASE(BossDemo, Intro);
    DECLARE_STATE_VIRTUAL_ID_BASE(BossDemo, Fight);
    DECLARE_STATE_VIRTUAL_ID_BASE(BossDemo, Outro);

    virtual u32 vf13C();
    virtual u32 vf140();
    virtual void killActors();              // Called before intro and outro
    virtual void vf148();
    virtual void vf14C();                   // Called at start of intro and outro
    virtual bool canStartBossDemo();        // Used to walk player into fight area
    virtual void isFightStillGoingMaybe();
    virtual bool canStartIntro();
    virtual ActorBase* searchBossActor();
    virtual ActorBase* searchOutroActor();
    virtual void created();                 // called from onCreate
    virtual bool hasOutroActor();
    virtual void spawnOutroActor();
    virtual bool isOutroActorFinished();
    virtual void vf174();
    virtual bool hasOutroCameraPan();
    virtual void unkShutters1();
    virtual void unkShutters2();
    virtual void openShutters();
    virtual void vf188();
    virtual void vf18C();
    virtual void setAfterFightState();
    virtual void vf194();
    virtual void vf198();

    bool walkInPlayer(f32 distance);

    f32 _FE8;
    f32 _FEC;
    f32 _FF0;
    f32 _FF4;
    u8 _FF8;
    u8 _FF9;
    u8 _FFA;
    u8 canSpawnKeyRelated;      // FFB
    u8 _FFC;
    u8 _FFD;
    u8 outroSubstate;           // FFE      3: celebrate, 4: zero timer
    Vec3f bossShutterPosition;  // 1000
    s32 bossId;                 // 100C
    ActorBase* boss;                // 1010
    u8 _unk1014[4];
    u32 _1018;
    f32 _101C;
    f32 _1020;
    f32 _1024;
    u8 _1028;
    u8 _1029;
    u8 _102A;
    s32 timer;                  // 102C
    u32 _1030;
    u32 _1034;
};

size_assert(BossDemo, 0x1038);
