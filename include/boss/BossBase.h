#pragma once

#include "actors/ActorBase.h"
#include "enemy/Enemy.h"
#include "state/FStateVirtualID.h"

// Size: 0x1070
class BossBase : public Enemy
{
    SEAD_RTTI_OVERRIDE(BossBase, Enemy);
public:
    BossBase();

    Result onCreate() override;
    bool preExecute() override;
    void postExecute(Result execResult) override;

    void collisionPlayer(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionStarMega(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionSlide(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionFencePunch(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionGroundPound(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionTanookiTail(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionShell(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionFireball(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    void onDefeatQuake(QuakeCollisionType quakeType, s8 playerId) override;
    bool isQuakeable() override;
    void giveScore(PlayerBase* player) override;

    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(BossBase, DieFumi);

    DECLARE_STATE_VIRTUAL_ID_BASE(BossBase, DieFire);
    DECLARE_STATE_VIRTUAL_ID_BASE(BossBase, DieSlide);
    DECLARE_STATE_VIRTUAL_ID_BASE(BossBase, DieShell);
    DECLARE_STATE_VIRTUAL_ID_BASE(BossBase, DieStar);
    DECLARE_STATE_VIRTUAL_ID_BASE(BossBase, DieQuake);

    // Sets `this->mIsDemoRunning` to true.
    virtual void demoStart();

    // Sets `this->mIsDemoRunning` to false.
    virtual void demoEnd();

    // Null
    virtual void vf218();

    // Deleted
    virtual void vf21C();

    // Deleted
    virtual void vf220();

    // Deleted
    virtual void vf224();

    // Returns true if the last hit dealt damage.
    virtual bool hitWasDamage();

    // Uses `damage` to recalculate `this->mHitPoints`.
    virtual void damageRev(s32 damage);

    // The amount of damage to deal when hit by a fireball.
    virtual s32 getDamageFire() = 0;

    // The amount of damage to deal when hit by a gold fireball.
    virtual s32 getDamageGoldFire() = 0;

    // The amount of damage to deal when stomped.
    virtual s32 getDamageFumi() = 0;

    // The amount of damage to deal when hit by a ground pound.
    virtual s32 getDamageHipAtk() = 0;

    // The amount of damage to deal when hit by an invincible player (star/mega/white tanooki).
    virtual s32 getDamageStar() = 0;

    // Unknown. Returns a damage value.
    virtual s32 vf244() = 0;

    // Unknown. Returns a damage value.
    virtual s32 vf248() = 0;

    // Unknown. Returns a damage value.
    virtual s32 vf24C() = 0;

    // Unknown. Returns a damage value.
    virtual s32 vf250();

    // Called when tenmetsu (invulnerability) starts.
    virtual void tenmetsuReady();

    // Called during tenmetsu (invulnerability).
    virtual void tenmetsuProc();

    // Called when tenmetsu (invulnerability) ends.
    virtual void tenmetsuFin();

    // Returns the duration of tenmetsu (invulnerability) when damaged by FireBall.
    virtual s32 tenmetsuTimeFire();

    // Deleted. Returns the duration of tenmetsu (invulnerability) when damaged by Shell.
    virtual s32 tenmetsuTimeShell();

    // Returns the duration of tenmetsu (invulnerability) when damaged by jump.
    virtual s32 tenmetsuTimePress();

    // Called when boss is defeated. Kills other actors spawned during the fight.
    virtual void deadKillAll();

    // Handles fumi collision.
    virtual void fumiProc(ActorBase* actor);

    // Sets the boss to a damage state for fumi attacks.
    virtual void setFumiDamage(ActorBase* actor);

    // Sets the boss to a death state for fumi attacks.
    virtual void setFumiDead(ActorBase* actor);

    // Sets the boss to a damage state for fire attacks.
    virtual void setFireDamage(ActorBase* actor);

    // Sets the boss to a death state for fire attacks.
    virtual void setFireDead(ActorBase* actor);

    // Sets the boss to a damage state for ground pound attacks.
    virtual void setHipAtkDamage(ActorBase* actor);

    // Sets the boss to a death state for ground pound attacks.
    virtual void setHipAtkDead(ActorBase* actor);

    // Deleted. Sets the boss to a damage state for slide attacks.
    virtual void setSlideDamage(ActorBase* actor);

    // Deleted. Sets the boss to a death state for slide attacks.
    virtual void setSlideDead(ActorBase* actor);

    // Sets the boss to a damage state for star/mega/white tanooki attacks.
    virtual void setStarDamage(ActorBase* actor);
    
    // Sets the boss to a death state for star/mega/white tanooki attacks.
    virtual void setStarDead(ActorBase* actor);

    // Sets the boss to a damage state for quake attacks
    virtual void setQuakeDamage(ActorBase* actor);

    // Sets the boss to a death state for quake attacks.
    virtual void setQuakeDead(ActorBase* actor);

    // Deleted. Sets the boss to a damage state.
    virtual void vf2A4(ActorBase* actor);

    // Deleted. Sets the boss to a death state.
    virtual void vf2A8(ActorBase* actor);

    // Called from `fumiProc` when damaged.
    virtual void damageProc();

    // Called from `fumiProc` when defeated.
    virtual void deadProc();

    // Returns true if fumi attacks cannot hurt the boss.
    virtual bool isFumiInvalid();

    // Returns true if fumi attacks cannot hurt the boss.
    virtual bool isFumiDamageInvalid();

    // Unknown. Returns true if the boss cannot be hurt by some attack. 
    virtual bool vf2DC();

    // Returns true if the boss cannot be hurt by fire attacks.
    virtual bool isFireInvalid();

    // Deleted. Returns true if the boss cannot be hurt by some attack. 
    virtual bool vf2C4();

    // Deleted. Returns true if the boss cannot be hurt by some attack.
    virtual bool vf2C8();

    // Returns true if the boss cannot be hurt by star/mega/white tanooki attacks.
    virtual bool isStarInvalid();

    // Spawns death effect for fumi attacks.
    virtual void fumiDeadEffect();

    // Spawns damage effect for fumi attacks.
    virtual void fumiDamageEffect();

    // Spawns hit effect for fireball attacks.
    virtual void hitFireEffect();

    // Deleted. Spawns hit effect for shell attacks.
    virtual void hitShellEffect();

    // Plays the damage sound effect for fumi attacks.
    virtual void fumiDamageSE();

    // Plays the death sound effect for fumi attacks.
    virtual void fumiDeadSE();

    // Plays the damage sound effect for star/mega/white tanooki attacks.
    virtual void starDamageSE();

    // Plays the death sound effect for star/mega/white tanooki attacks.
    virtual void starDeadSE();

    // Deleted.
    virtual void vf2F0();

    // Deleted.
    virtual void vf2F4();

    // Plays the damage sound effect for fire attacks.
    virtual void fireDamageSE();

    // Plays the death sound effect for fire attacks.
    virtual void fireDeadSE();

    // Plays the damage sound effect for quake attacks.
    virtual void quakeDamageSE();

    // Plays the death sound effect for quake attacks.
    virtual void quakeDeadSE();

    // Plays voice line for fumi death.
    virtual void fumiDeadVo();

    // Deleted. Plays voice line for small damage.
    virtual void damageSVo();

    // Deleted. Plays voice line for large damage.
    virtual void damageLVo();

    // Creates and sets up the boss model.
    virtual void createModel();

    // Calculates and updates the boss model.
    virtual void calcModel();

    // Sets the value of `this->mHitPoints`.
    virtual void setHitPoints();

    // Sets the value of `this->mHitsToDamage`.
    virtual void setHitToDamage();

    // Initializes the boss.
    virtual bool setup();

    // Enables the attentionLook target.
    virtual void enableLookAt();

    // Disables the attentionLook target.
    virtual void disableLookAt();

protected:
    /* 0x1060 */  s32 mHitPoints;       // The maximum health for this Boss
    /* 0x1064 */  s32 mHitsToDamage;    // The number of hits required to be damaged via projectiles
    /* 0x1068 */  s32 mTenmetsuTimer;   //
    /* 0x106C */  bool mIsShock;        // Is currently shocked from a quake
    /* 0x106D */  bool mIsDemoRunning;  //
    /* 0x106E */  u16 mAudioObjSeqVar;  // Sequence arg passed when playing sound effects
};

size_assert(BossBase, 0x1070);
