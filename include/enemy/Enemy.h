#pragma once

#include "actors/ActorMultiState.h"
#include "actors/AttentionLook.h"
#include "enemy/EnemyDeathInfo.h"
#include "actors/ScoreMgr.h"
#include "enemy/Combo.h"
#include "utility/Direction.h"

class PlayerBase;
class PlayerObject;

// Size: 0x4
struct PlayerDownTimer
{
    u16 mTimer[2];

    // Address: 0x002E8478
    void updateTimers();
};

class Enemy : public ActorMultiState    // size: 0x1060
{
    SEAD_RTTI_OVERRIDE(Enemy, ActorMultiState);

public:
    enum class FumiType : u32
    {
        Hit         = 0,    // Player was hit
        Fumi        = 1,    // Normal stomp
        MameFumi    = 2,    // Mini stomp
    };

    enum class FumiEffectType : u32
    {
        Normal  = 0,    // 
        Unk1    = 1,    // 
        Unk2    = 2,    //
    };

    // Related to _103C; not part of this class
    struct PlayerCollisionEvent
    {
        ActorCollisionCheck* actorCheck;
        ActorCollisionCheck* playerCheck;
    };

public:
    Enemy();

    // Address: 0x003AB858
    bool preExecute() override;

    void powActivated() override;
    void onCollisionLava(ActorBase* other) override;
    void changeState(const StateID& stateID) override;

    virtual void vf110();                               // Called on nearby Gold Fireball hit
    virtual void vf114();                               // Called when POW block is triggered
    virtual void vf118();                               // Called when POW block is triggered
    virtual u32 vf11C();                                // Returns 0. Maybe a bool
    virtual void vf120();                               // Called on nearby Gold Fireball hit. Probably this is something else...
    virtual bool damagePlayer(PlayerBase* player);
    virtual bool checkComboClap(u32 playerCombo);       // Returns true if the player's combo count is high enough to trigger clap sfx upon death

    virtual bool collisionHandlerEnemies(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);  // 12C  Handles collisions with other enemies
    virtual bool collisionHandlerPlayers(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);  // 130  Handles collisions with players
    virtual bool collisionHandlerActors(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);   // 134  Handles collisions with all other actor types
    virtual void collisionEnemy(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);           // 138
    virtual void collisionPlayer(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);          // 13C

                                                                                                            //      categories
    virtual bool collisionStarMega(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);        // 140  2
    virtual bool collisionSlide(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);           // 144  4
    virtual bool collisionFencePunch(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);      // 148  7
    virtual bool collisionGroundPound(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);     // 14C  6           Mini Ground Pounds do not call this
    virtual bool collisionPipeCannon(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);      // 150  15
    virtual bool collisionTanookiTail(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);     // 154  9
    virtual bool collisionShell(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);           // 158  8
    virtual bool collisionFireball(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);        // 15C  1, 14

    virtual void onDefeatQuake(QuakeCollisionType quakeType, s8 playerId);
    virtual bool isQuakeable();

    virtual void deathSoundFire();                              // Plays sound for when dying to fire
    virtual void deathSoundHipDrop();                           // Plays sound for when dying to ground-pound
    virtual void onDefeat();                                    // Removes collision check and awards points to player

    virtual void fumiJumpSet(PlayerBase* player);               // Set the player's jump for FumiType Fumo (Stomp)
    virtual void giveScore(PlayerBase* player);
    virtual void mameFumiJumpSet(PlayerBase* player);           // Set the player's jump for FumiType Mame (Stomp while mini)

    virtual void fumiSE(PlayerBase* player);                    // Plays Fumi sound effect (Stomp) 
    virtual void fumiEffect(PlayerBase* player);                // Spawns Fumi effect (Stomp)
    virtual void mameFumiSE();                                  // Plays MameFumi sound effect (Stomp while mini) 
    virtual void mameFumiEffect(PlayerBase* player);            // Spawns MameFumi effect (Stomp while mini)

    virtual void hitEffectCommon(const Vec2f& pos);             // Spawns generic hit effect
    virtual void hitEffectHipDrop(const Vec2f& pos);            // Spawns hit effect used when enemy is ground-pounded
    virtual void hitEffectQuake(const Vec2f& pos);              // Spawns the hit effect to use for quake attacks

    virtual void doQuakeBounce();                               // Increases speed.y by 2.0
    virtual bool isInRangeOfQuake();

    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, DieFumi);              // Used when stomped - Fall off the stage with x rotation
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, DieFall);              // Used when killed with shell etc - Fall off the stage with x and y rotation
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, DieSmoke);             // Immediate erase with spawned death effect
    DECLARE_STATE_VIRTUAL_ID_BASE(Enemy, DieOther);             // Immediate erase

    // Address: 0x004A68B8
    FumiType fumiCheck(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck, FumiEffectType effectType = FumiEffectType::Normal);    // Only spawns effect if FumiEffectType == Normal, BossBase uses FumiEffectType::Unk2

    void killWithState(ActorBase* source, const Vec2f& speed, const StateID& stateID);

    // Address: 0x003ACC90
    void setDeathInfo_Fall(u8 direction, s8 playerId, ScoreMgr::RewardType rewardType);

    // Address: 0x004A6A98
    void giveScore(const Vec3f& position, ScoreMgr::RewardType rewardType, s8 playerId);

    // Address: 0x00432080
    Direction getDirectionToActor(ActorBase* actor);

    // Address: 0x003ACFF4
    static void collisionCallback(ActorCollisionCheck* self, ActorCollisionCheck* other);

public:
    AttentionLook attentionLook;    // FEC
    EnemyDeathInfo deathInfo;       // 1018

    PlayerDownTimer noHitPlayer;    // 1034 inited to { 0, 0 } - Player hit-role timers, updated in preExecute
    u32* _1038;                     // 1038 inited to 0
    u32* _103C;                     // 103C inited to &this
    u32* fumiCheckPtr;              // 1040 inited to 0x5E6518 (NonUniqueFumiCheck::sInstance)
    u8 _1044;                       // 1044 inited to 0
    u32 _1048;                      // 1048 inited to 0
    u16 timerA;                     // 104C inited to 0 - General purpose timer? Is decremented every frame in BeforeExecute
    u16 timerB;                     // 104E inited to 0 - General purpose timer? Is decremented every frame in BeforeExecute

    u32 _1050;                      // 1050

    Direction dieFallDirection;     // 1054 inited to 0
    u8 _1055[3];                    // 1055 padding
    Combo combo;                    // 1058
    u8 _105C;                       // 105C inited to 0

    u8 _105D;                       // 105D inited to 0
    u8 _105E;                       // 105E inited to 0
    u8 _105F;                       // 105F inited to 0

    static const DirectionArrayX<s32> commonRotations;
};

size_assert(Enemy, 0x1060);