#pragma once

#include "CarryableEnemy.h"


class ShellEnemy : public CarryableEnemy
{
    SEAD_RTTI_OVERRIDE(ShellEnemy, CarryableEnemy);

public:
    ShellEnemy();

    int onCreate() override;
    int onDelete() override;
    int beforeExecute() override;
    int onExecute() override;
    void afterExecute(int) override;

    void vf58() override;
    u32 vf5C() override;
    void powActivated() override;
    void vf114() override;
    u32 vf11C() override;

    bool collisionHandlerActors(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    void collisionEnemy(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    void collisionPlayer(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionGroundPound(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionTanookiTail(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionShell(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;

    void vf174() override;
    void giveScore(PlayerBase* player) override;

    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(ShellEnemy, DieBigFall);

    void vf1D4() override;
    void jumpedOn(ActorBase* other) override;
    void collisionPlayerNormal(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    void collisionPlayerLiftable(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;

    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(ShellEnemy, Carry);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(ShellEnemy, Liftable);

    virtual void createModel();
    virtual void vf210();
    virtual void vf214();
    virtual void vf218();
    virtual void vf21C();
    virtual void vf220();
    virtual void vf224();
    virtual void vf228();
    virtual void vf230();
    virtual void vf234();
    virtual void vf238();
    virtual void vf23C();
    virtual void vf240();
    virtual void vf244();
    virtual void vf248();
    virtual void vf24C();
    virtual void vf250();
    virtual void vf254();
    virtual void vf258();
    virtual void vf25C();
    virtual void vf260();
    virtual void vf264();
    virtual void vf268();
    virtual void vf26C();
    virtual void vf270();
    virtual void vf274();

    ActorBgCollisionCheck::Sensor sensorAbove;       // 107C
    ActorBgCollisionCheck::Sensor sensorBelow;       // 1088
    ActorBgCollisionCheck::Sensor sensorAdjacent;    // 1094
    u32 _10A0;
    u32 _10A4;
    u32 _10A8;
    ActorCollisionCheck::Info aCollisionCheckInfo;       // 10AC
    u32 model1_UnkC;                        // 10D0
    u32 model2_UnkC;                        // 10D4
    Vec3f initialPosition;                   // 10D8
    u32 _10E4;
    u32 _10E8;
    u32 _10EC;
    u32 _10F0;
    u32 _10F4;
    u32 _10F8;
    u32 _10FC;
    u32 _1100;
    u32 shellState;                         // 1104     0: Liftable, 1: Normal/Not Liftable, 2: Egg
    u32 _1108;
    bool isUpsideDown;                      // 110C
    u8 _110D;
    u8 _110E;
    u8 _110F;
    u8 _1110;
    u8 _1111;
    u8 _1112;
    u8 _1113;
    u8 _1114;
    u8 _1115;
    u8 _1116;
    u8 _1117;
    u8 _1118;
    u8 _1119;
    u8 _111A;
    u8 _111B;
    u32 _111C;
    u16 _1120;
    u32 _1124;
    u8 _unk1128[0x14];
    u8 enabled1upTrick;                     // 113C
    u8 _unk112D;
    bool goldRingActive;                    // 113E
    u8 _unk113F[0xD];
};
