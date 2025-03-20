#pragma once

#include "actors/Enemy.h"

class Boss : public Enemy
{
    SEAD_RTTI_OVERRIDE(Boss, Enemy);

public:
    Boss();

    int onCreate() override;
    int beforeExecute() override;
    void afterExecute(int) override;

    void collisionPlayer(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionStarMega(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionSlide(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionFencePunch(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionGroundPound(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionTanookiTail(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionShell(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionFireball(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    void vf160() override;
    void vf164() override;
    void giveScore() override;

    DECLARE_STATE_VIRTUAL_ID_BASE(Boss, DieFall);

    DECLARE_STATE_VIRTUAL_ID_BASE(Boss, DieFireball);
    DECLARE_STATE_VIRTUAL_ID_BASE(Boss, DieUnk1);
    DECLARE_STATE_VIRTUAL_ID_BASE(Boss, DieUnk2);
    DECLARE_STATE_VIRTUAL_ID_BASE(Boss, DieStarMega);
    DECLARE_STATE_VIRTUAL_ID_BASE(Boss, DieUnk3);

    virtual void demoStart();
    virtual void demoEnd();
    virtual void vf218();
    virtual void vf21C();       // deleted
    virtual void vf220();       // deleted
    virtual void vf224();       // deleted
    virtual void lastDamageWasHit();
    virtual void processDamage(s32 damage);
    virtual s32 damageAmountFireball() = 0;
    virtual s32 damageAmountGoldFireball() = 0;
    virtual s32 damageAmountStomped() = 0;
    virtual s32 damageAmountGroundPound() = 0;
    virtual s32 damageAmountStarMega() = 0;
    virtual void vf244();       // deleted
    virtual void vf248();       // deleted
    virtual s32 damageAmountUnk() = 0;
    virtual void vf250();
    virtual void hitTimerStarted();
    virtual void hitTimerRunning();
    virtual void hitTimerEnded();
    virtual s32 hitTimeFireball();
    virtual void vf264();       // deleted
    virtual s32 hitTimeStomped();
    virtual void killActors();
    virtual void playerCollision();
    virtual void stompCollision();
    virtual void stompCollisionLast();
    virtual void fireballCollision();
    virtual void fireballCollisionLast();
    virtual void groundPoundCollision();
    virtual void groundPoundCollisionLast();
    virtual void vf28C();       // deleted
    virtual void vf290();       // deleted
    virtual void starMegaCollision();
    virtual void starMegaCollisionLast();
    virtual void unkCollision();
    virtual void unkCollisionLast();
    virtual void vf2A4();       // deleted
    virtual void vf2A8();       // deleted
    virtual void damaged();
    virtual void damagedLast();
    virtual bool canCollidePlayerPreMaybe();
    virtual bool canCollidePlayerTopMaybe();
    virtual bool canCollidePlayerSideMaybe();
    virtual bool canCollideFireball();
    virtual void vf2C4();       // deleted
    virtual void vf2C8();       // deleted
    virtual bool invincibleToStarMega();
    virtual void onDamageAlive();
    virtual void onDamageDead();
    virtual void onDamageFireballMaybe();
    virtual void vf2DC();       // deleted
    virtual void playSoundStomped();
    virtual void playSoundStompedLast();
    virtual void playSoundStarDefeat();
    virtual void playSoundStarLast();
    virtual void vf2F0();       // deleted
    virtual void vf2F4();       // deleted
    virtual void playSoundFireDamage();
    virtual void playSoundFireDamageLast();
    virtual void playSoundStarDefeat2();
    virtual void playSoundStarLast2();
    virtual void vf308_onDead2();
    virtual void vf30C();       // deleted
    virtual void vf310();       // deleted
    virtual void setupModel();
    virtual void updateModel();
    virtual void setupDamageToDeath();
    virtual void setupDamageToHit();
    virtual bool setup();
    virtual void addPlayerLookTarget();
    virtual void removePlayerLookTarget();

    s32 damageToDeath;      // 1060
    s32 damageToHit;        // 1064
    s32 hitTimer;           // 1068
    u8 _106C;               // 106C
    bool demoRunning;       // 106D
    u16 _106E;              // 106E Sound related
};

size_assert(Boss, 0x1070);
