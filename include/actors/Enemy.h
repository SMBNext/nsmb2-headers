#pragma once

#include "actors/ActorMultiState.h"
#include "player/PlayerLookTarget.h"
#include "enemy/EnemyDeathInfo.h"
#include "actors/ScoreMgr.h"

class PlayerBase;

class Enemy : public ActorMultiState    // size: 0x1060
{
    SEAD_RTTI_OVERRIDE(Enemy, ActorMultiState);

public:

    enum class ScoreType : u32
    {
        None   = 0, // Gives no points
        Normal = 1, // Gives points starting from 100
        Big    = 2  // Gives points starting from 1000
    };

public:
    Enemy();

    int beforeExecute() override;

    void powActivated() override;
    void onCollisionLava(ActorBase* other) override;
    void changeState(const StateID& stateID) override;

    virtual void vf110();                               // Called on nearby Gold Fireball hit
    virtual void vf114();                               // Called when POW block is triggered
    virtual void vf118();                               // Called when POW block is triggered
    virtual u32 vf11C();                                // Returns 0. Maybe a bool
    virtual void vf120();                               // Called on nearby Gold Fireball hit. Probably this is something else...
    virtual bool damagePlayer(PlayerBase* player);
    virtual bool vf128(u32 playerCombo);

    virtual bool collisionHandlerEnemies(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);    // 12C  Handles collisions with other enemies
    virtual bool collisionHandlerPlayers(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);    // 130  Handles collisions with players
    virtual bool collisionHandlerActors(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);     // 134  Handles collisions with all other actor types
    virtual void collisionEnemy(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);             // 138
    virtual void collisionPlayer(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);            // 13C

                                                                                            //      categories
    virtual bool collisionStarMega(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);          // 140  2
    virtual bool collisionSlide(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);             // 144  4
    virtual bool collisionFencePunch(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);        // 148  7
    virtual bool collisionGroundPound(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);       // 14C  6           Mini Ground Pounds do not call this
    virtual bool collisionPipeCannon(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);        // 150  15
    virtual bool collisionTanookiTail(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);       // 154  9
    virtual bool collisionShell(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);             // 158  8
    virtual bool collisionFireball(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);          // 15C  1, 14

    virtual void vf160();                                                                   // Called on Mega Ground Pound. Probably returns a PTR or is void
    virtual void vf164();
    virtual void vf168();                                       // Plays SE_E_DEAD_COMMON
    virtual void vf16C();                                       // Plays SE_EMY_DOWN_HPDP_S/H based on _1038 & 2
    virtual void onDefeat();                                    // Removes collision check and awards points to player
    virtual void vf174();
    virtual void giveScore(PlayerBase* player);
    virtual void vf17C();
    virtual void playStompSoundEffect(PlayerBase* player);      // Plays relevant stomp sound for current player combo
    virtual void vf184();
    virtual void vf188();                                       // Plays SE_EMY_MAME_STEP
    virtual void vf18C();
    virtual void spawnHitEffectCommon(const Vec2f& pos);        // Spawns generic hit effect
    virtual void spawnHitEffectHipDrop(const Vec2f& pos);       // Spawns hit effect used when enemy is ground-pounded
    virtual void vf198(Vec3f* pos);                             // Calls vf190
    virtual void vf19C();                                       // Increases speed.y by 2.0
    virtual bool vf1A0();


    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, DieFall);              // Fall off the stage with x rotation
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, DieBigFall);           // Fall off the stage with x and y rotation
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, DieSmoke);             // Immediate erase with spawned death effect
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, DieOther);             // Immediate erase

    u32 processPlayerCollision(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck, bool noDefaultEffects = false);
    void killWithState(ActorBase* source, Vec2f* speed, const StateID& stateID);

    // Address: 0x0x003ACC90
    void setDeathInfo_Fall(u8 direction, s8 playerId, ScoreMgr::RewardType rewardType);

    // Address: 0x004A6A98
    void giveScore(const Vec3f& position, ScoreMgr::RewardType rewardType, s8 playerId);

    u8 getDirectionToActor(ActorBase* actor);

    // Address: 0x003ACFF4
    static bool collisionCallback(ActorCollisionCheck* self, ActorCollisionCheck* other);

    PlayerLookTarget playerLookTarget;  // FEC

    EnemyDeathInfo deathInfo;   // 1018

    u32* _1034;                 // 1034 inited to 0
    u32 _1038;                  // 1038 inited to 0
    u32* _103C;                 // 103C inited to &this
    u32* _1040;                 // 1040 inited to 5E6518
    u8 _1044;                   // 1044 inited to 0
    u32 _1048;                  // 1048 inited to 0
    u16 _104C;                  // 104C inited to 0
    u16 _104E;                  // 104E inited to 0

    u32 _1050;                  // 1050

    u8 _1054;                   // 1054 inited to 0
    ScoreType scoreType;        // 1058 0: None, 1: 200 Points, 2: 1000 Points, default: 1
    u8 _105C;                   // 105C inited to 0

    u8 _105D;                   // 105D inited to 0
    u8 _105E;                   // 105E inited to 0
    u8 _105F;                   // 105F inited to 0

    static const u32 commonRotations[];
};

size_assert(Enemy, 0x1060);