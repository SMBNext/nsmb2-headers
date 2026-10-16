#pragma once

#include "actors/dBase.h"
#include "collider/ActorCollisionCheck.h"
#include "course/Profiles.h"
#include "event/EventMgr.h"
#include "sead/seadBitFlag.h"
#include "sead/seadBoundBox.h"
#include "types.h"
#include "utility/Direction.h"
#include "utility/EnumUtil.h"

class Model;
class AnimModelBase;
class ActorBgCollisionCheck;

static constexpr f32 cDefaultGravity = -4.0f;
static constexpr f32 cDefaultAccelY = -0.1875f;

// size: 0x1C8
class ActorBase : public dBase
{
    SEAD_RTTI_BASE(ActorBase);
public:
    // Size: 0x3C
    struct CreateInfo
    {
        /* 0x00 */  u16 profileId;              //
        /* 0x02 */
        /* 0x03 */
        /* 0x04 */  u32 spriteData1;            //
        /* 0x08 */  u32 spriteData2;            //
        /* 0x0C */  ActorUniqueID parentId;     //
        /* 0x10 */  fBase* parent;              // Replaced by BsArea::instance* if null
        /* 0x14 */  ActorInfo* actorInfo;       //
        /* 0x18 */  u32 _18;                    //
        /* 0x1C */  Vec3f position;             //
        /* 0x28 */  s32 rotationY;              //
        /* 0x2C */  u8 layer;                   //
        /* 0x2D */  u8 targetFlagId;            //
        /* 0x2E */  u8 triggeringFlagId;        //
        /* 0x2F */  u8 _2F;                     //
        /* 0x30 */  u8 movementId;              //
        /* 0x31 */  u8 spriteData3;             //
        /* 0x32 */
        /* 0x33 */
        /* 0x34 */  u32 _34;                    //
        /* 0x38 */  u8* respawnSettings;        //
    };
    size_assert(CreateInfo, 0x3C);

    enum ActorType : u8
    {
        ActorType_cRegular  = 0,
        ActorType_cPlayer   = 1,
        ActorType_cEnemy    = 2,
        ActorType_cBullet   = 3,
    };

    enum class DeathEffectType : u32
    {
        cExplodeSmall      = 0x0,   //
        cExplodeMedium     = 0x1,   //
        cExplodeLarge      = 0x2,   //
        cExplodeKing       = 0x3,   //
        cUseActorDefault   = 0x5,   // Uses the value of mDeathEffectType
    };

    enum class CarryAction : u8
    {
        cRelease    = 0x1,  // The actor is being released from carry.
        cThrow      = 0x2,  // The actor is being actively thrown by the player.
        cUnk4       = 0x4,  //
    };

public:
    ActorBase();
    virtual ~ActorBase();

    void postCreate(Result createResult) override;
    void postDelete(Result deleteResult) override;
    bool preExecute() override;
    void postExecute(Result execResult) override;
    bool preDraw() override;

    // Returns nullptr
    virtual ActorBgCollisionCheck* getBgCollisionCheck();

    // Returns nullptr
    virtual const ActorBgCollisionCheck* getBgCollisionCheck() const;

    // Sets the player number for this actor, -1 indicates this actor is not a player.
    virtual void setPlayerNum(s8 playerNum);

    // Removes the actor's collision check from the collision manager.
    virtual void removeCollisionCheck();

    // Adds the actor's collision check to the collision manager.
    virtual void addCollisionCheck();

    // Null
    virtual void setCarryFall(ActorBase* actor, s32 a2);

    // Returns true
    virtual bool isSpinLiftUpEnable();

    // Null
    virtual void setSpinLiftUpActor(ActorBase* actor);
    
    // Null
    virtual void vf64();

    // Null
    virtual void vf68();

    // Called when finishing level if `ActorInfo::Flag_LevelClearDeath` is set.
    virtual void levelClearDeath();

    // Spawns a water splash at the given position.
    virtual void waterSplashEffect(const Vec3f& position, f32 scale = 1.0f);

    // Spawns a lava splash at the given position.
    virtual void lavaSplashEffect(const Vec3f& position, f32 scale = 1.0f);

    // Spawns a poison splash at the given position.
    virtual void poisonSplashEffect(const Vec3f& position, f32 scale = 1.0f);

    // Returns 0.
    virtual u32 vf7C();

    // Returns true if the actor is within the given bounds.
    virtual bool inBounds(const sead::BoundBox2f& bounds) const;

    // Null
    virtual void vf84();

    // Called in postCreate, type of created class is determined by ProfileSoundActorKinds.
    virtual void createSoundActor();

    // Deleted
    virtual void vf8C();

    // Starts playback of a sound by id.
    virtual void startSound(u32 soundId);

    // Starts playback of a sound by id & sets a sequence arg.
    virtual void startSound(u32 soundId, u32 arg);

    // Starts playback of a sound by name.
    virtual void startSound(const char* soundName);

    // Starts playback of a sound by name & sets a sequence arg.
    virtual void startSound(const char* soundName, u32 arg);

    // Starts/continues a sound by id - must be called every frame.
    virtual void holdSound(u32 soundId);

    // Starts/continues a sound by id & sets a sequence arg - must be called every frame.
    virtual void holdSound(u32 soundId, u32 arg);

    // Starts/continues a sound by name - must be called every frame.
    virtual void holdSound(const char* soundName);

    // Starts player voice sound playback by id & changes depending on player character and powerup.
    virtual void playVoice(u32 soundId, u8 isLuigi, u8 powerup);

    // Like `playVoice`, but sends random 0-1 as sequence variable 0.
    virtual void playVoiceVariant(u32 soundId, u32 isLuigi, u32 powerup, f32 unk);

    // Starts footstep sound playback with volume and pitch set from `speed`.
    virtual void playFootSound(u32 soundId, u32 powerup, f32 speed);

    // Like `playVoice` but always at full volume.
    virtual void playVoiceFullVolume(u32 soundId, u32 isLuigi, u32 powerup);

    // starts/stops playback of a sound at position, does not use Sound Actor.
    virtual void playSound(u32 soundId, const Vec2f& position, bool stopSound = true);

    // Returns true while the player bound sound cooldown is active.
    virtual bool isBoundSoundCooldown();

    // Sets the player bound sound cooldown.
    virtual void setBoundSoundCooldown(u32 frames);

    // Initializes the actor from the given `CreateInfo`.
    virtual void setupFromCreateInfo(CreateInfo* info);

    // Null (used by player)
    virtual void executeLastAll();

    // Returns true if the actor is out of view.
    virtual bool isOutOfView();

    // Called in `ActorBase::BeforeExecute` if `this->powTimer` is equal to 8.
    virtual void powActivated();

    // Assigns `this->zone` from `StageInfo::instance()->zone`.
    void updateZone();

    // Sets `this->existLcation` to the location associated with the given id.
    // On success, updates `this->existLcation` and marks `this->hasExistLocation` as `true` and returns `true`.
    bool assignExistLocation(u8 id);

    // Returns true if the actor is out of view or should be culled based on the given checks bitfield.
    bool cullCheck(u32 checksBitfield = 0);

    // Returns horizontal direction relative to player
    Direction directionToPlayerH(const Vec3f& checkPosition);

    // Returns vertical direction relative to player
    Direction directionToPlayerV(const Vec3f& checkPosition);

    // Spawns a death effect at the given position with the specified type and rotation.
    void spawnDeathEffect(const Vec3f& position, DeathEffectType type, const Vec3i& rotation);

    // Smoothly moves `this->speed.y` toward `target` by `increment` per call (clamped, no overshoot).
    void moveToTargetSpeedY(f32 increment, f32 target);

    // Increases `this->speed.y` by `increment`, clamped to a minimum of `minSpeed`.
    void incrementSpeedY(f32 increment, f32 minSpeed);

    // Applies horizontal acceleration toward `this->targetSpeedX` using `this->accelerationX`,
    // A positive acceleration moves towards the target, while a negative acceleration moves away.
    void applyAccelerationX();

    // De-spawns the actor, optionally marking it as respawnable.
    void despawn(bool isRespawnable);

    // Plays the combo sound for `streakIndex` with the clap for a long streak.
    void playStreakSfx(s32 streakIndex, bool isBigReward);

    // Creates a new actor using the given `CreateInfo`.
    static ActorBase* create(CreateInfo* info);

    // Convenience helpers (not part of the original game) for building a model's draw
    // matrix from the actor's position/rotation/scale.
    void updateModelMatrixWithOffset(Model* model);
    void updateModelMatrixWithOffset(AnimModelBase* model, bool dontUpdateAnimation = false);

    void updateModelMatrix(Model* model);
    void updateModelMatrix(AnimModelBase* model, bool dontUpdateAnimation = false);

public:
    /* 0x013 */  Direction direction;                   // Initialized to 0.
    /* 0x014 */  s8 playerNum;                          // Inited to -1
    /* 0x015 */  u8 layer;                              //
    /* 0x016 */  sead::BitFlag8 collisionMask;          //
    /* 0x017 */
    /* 0x018 */  f32 speedX;                            // Inited to 0.0, used instead of speed.x in PlayerObject
    /* 0x01C */  f32 maxSpeedX;                         // Inited to 0.0
    /* 0x020 */  f32 targetSpeedY;                      // More general purpose than minSpeedY, as `ActorCollision::applyAccelerationY()` always enforces it as a target
    /* 0x024 */  f32 accelerationY;                     // Inited to 0.0
    /* 0x028 */  f32 accelerationX;                     // Inited to 0.0
    /* 0x02C */  Vec2f lastPosDelta;                    // Set in preExecute
    /* 0x034 */  Vec3f position;                        // 
    /* 0x040 */  Vec3f speed;                           // 
    /* 0x04C */  f32 targetSpeedX;                      // 
    /* 0x050 */  f32 minSpeedY;                         // Mostly used as "gravity", in a downward (negative) direction and applied using `ActorCollision::applyFallAcceleration()`
    /* 0x054 */  f32 targetSpeedZ;                      // Unknown use
    /* 0x058 */  Vec3f scale;                           // Inited to { 1.0, 1.0, 1.0 }
    /* 0x064 */  Vec3i rotation;                        // Inited to { 0, 0, 0 }
    /* 0x070 */  u32 _70;                               // Inited to 0
    /* 0x074 */  u32 _74;                               // Inited to 0
    /* 0x078 */  u32 _78;                               // Inited to 0
    /* 0x07C */  u8 deathEffectType;                    // 0: Smoke puff with sparkles, 1: Small smoke puff, 2: Smoke puff, 4: Big smoke puff
    /* 0x07D */  bool bigLiquidSplash;                  // Inited to false, roughly doubles the splash size
    /* 0x07E */
    /* 0x07F */
    /* 0x080 */  Vec2f posDelta;                        // Added to position and zeroed in preExecute
    /* 0x088 */  ActorCollisionCheck aCollisionCheck;   // 
    /* 0x140 */  Vec2f visibleAreaOffset;               // 
    /* 0x148 */  Vec2f existDistance;                   // 
    /* 0x150 */  Vec2f visibleDistance;                 // 
    /* 0x158 */  f32 cullLimitUp;                       // Used in cullCheck() to check when to erase actor, possibly zone bounds related
    /* 0x15C */  f32 cullLimitDown;
    /* 0x160 */  f32 cullLimitLeft;
    /* 0x164 */  f32 cullLimitRight;
    /* 0x168 */  sead::BoundBox2f existLocation;        // Set by assignExistLocation, checked by ActorBase::cullCheck() if set
    /* 0x178 */  bool hasExistLocation;                 // Inited to 0, set by assignExistLocation
    /* 0x179 */
    /* 0x17A */
    /* 0x17B */
    /* 0x17C */  u32 spriteData1;                       // Nybbles  4-11
    /* 0x180 */  u32 spriteData2;                       // Nybbles 12-19
    /* 0x184 */  u8 movementId;                         // Nybbles 20-21
    /* 0x185 */  u8 spriteData3;                        // Nybbles 22-23
    /* 0x186 */
    /* 0x187 */
    /* 0x188 */  u32 executeFlags;                      // 
    /* 0x18C */  u8 zone;                               // Inited to current zone
    /* 0x18D */  ActorType actorType;                   // ActorType
    /* 0x18E */  bool doExecute;                        // Not executed if set to false, inited to true
    /* 0x18F */  bool visible;                          // Not drawn if set to false, inited to true
    /* 0x190 */  bool disableRespawn;                   // Inited to 0
    /* 0x191 */  bool deleteLater;                      // Not drawn and erased in next preExecute if set to true
    /* 0x192 */  u8 targetFlagId;                       // Nybbles 0-1
    /* 0x193 */  u8 triggeringFlagId;                   // Nybbles 2-3
    /* 0x194 */  u16 _194;                              // 
    /* 0x195 */
    /* 0x196 */
    /* 0x198 */  u32 powTimer;                          // Decremented every frame in `ActorBase::PreExecute`
    /* 0x19C */  Direction deathFallDirection;          // The X direction to move towards on death.
    /* 0x19D */  CarryAction carryingFlags;             // The actor's carrying flags.
    /* 0x19E */  Direction throwDirection;              // The actor's direction when thrown or dropped after carrying.
    /* 0x19F */
    /* 0x1A0 */  u32 powCombo;                          // Inited to 0
    /* 0x1A4 */  u32 flags;                             // ActorInfo::Flags
    /* 0x1A8 */  Vec3f centerOffset;                    // Inited to { 0.0, 0.0, 0.0 }
    /* 0x1B4 */  Vec3f lastPosition;                    // Always updated to the same values as position
    /* 0x1C0 */  u8* respawnSettings;                   // 
    /* 0x1C4 */  void* soundActor;                      // 
};

size_assert(ActorBase, 0x1C8);

ENUM_CLASS_ENABLE_FLAGS(ActorBase::CarryAction, u8);
