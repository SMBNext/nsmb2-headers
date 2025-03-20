#pragma once

#include "actors/dBase.h"
#include "collider/ActorCollisionCheck.h"
#include "sead/seadBoundBox.h"

#include "course/Profiles.h"

class Model;
class AnimModelBase;
class ActorBgCollisionCheck;

class ActorBase : public dBase  // size: 0x1C8
{
    SEAD_RTTI_BASE(ActorBase);

public:
    struct CreateInfo           // size: 0x3C
    {
        u16 profileId;          // 0
        u32 spriteData1;        // 4
        u32 spriteData2;        // 8
        u32 parentId;           // C
        fBase* parent;          // 10   Replaced by BsArea::instance if = 0
        ActorInfo* actorInfo;   // 14
        u32 _18;                // 18
        Vec3f position;          // 1C
        u32 _28;                // 28   Y Rotation Related?
        u8 layer;               // 2C   Stored in _15
        u8 targetFlagId;        // 2D
        u8 triggeringFlagId;    // 2E
        u8 _2F;                 // 2F
        u8 movementId;          // 30
        u8 spriteData3;         // 31
        u32 _34;                // 34
        u8* respawnSettings;    // 38
    };

    enum ActorType : u8
    {
        ACTOR_TYPE_REGULAR  = 0,
        ACTOR_TYPE_PLAYER   = 1,
        ACTOR_TYPE_ENEMY    = 2
    };

    enum class SpawnDeathEffectType : u32
    {
        BR_Cm_ExplodeSmall      = 0x0,
        BR_Cm_ExplodeMedium     = 0x1,
        BR_Cm_ExplodeLarge      = 0x2,
        BR_Cm_ExplodeKing       = 0x3,
        USE_DEATH_EFFECT_TYPE   = 0x5,
    };

public:
    ActorBase();
    virtual ~ActorBase();

    void afterCreate(int) override;
    void afterDelete(int) override;
    int beforeExecute() override;
    void afterExecute(int) override;
    int beforeDraw() override;

    virtual ActorBgCollisionCheck* getBgCollisionCheck();
    virtual ActorBgCollisionCheck* getBgCollisionCheck2();
    virtual void setPlayerId(s8 playerId);
    virtual void removeCollisionCheck();
    virtual void addCollisionCheck();
    virtual void vf58();                        // null
    virtual u32 vf5C();                         // returns 1
    virtual void vf60();                        // null
    virtual void vf64();                        // null
    virtual void vf68();                        // null    
    virtual void levelClearDeath();                                     // Called when finishing level if FLAG_LEVELCLEAR_DEATH is set
    virtual void waterSplash(const Vec3f& position, f32 scale=1.0f);
    virtual void lavaSplash(const Vec3f& position, f32 scale=1.0f);
    virtual void poisonSplash(const Vec3f& position, f32 scale=1.0f);
    virtual u32 vf7C();                                                 // returns 0. probably a ptr?
    virtual bool inBounds(const sead::BoundBox2f& bounds) const;
    virtual void vf84();                                                // null

    // Sound Actor
    virtual void createSoundActor();                                             // Called in afterCreate, type of created class is determined by ProfileSoundActorKinds
    virtual void vf8C();                                                         // deleted    
    virtual void startSound(u32 soundId);                                        // starts playback of a sound by id
    virtual void startSound(u32 soundId, u32 arg);                               // starts playback of a sound by id & sets a sequence arg
    virtual void startSound(const char* soundName);                              // starts playback of a sound by name
    virtual void startSound(const char* soundName, u32 arg);                     // starts playback of a sound by name & sets a sequence arg
    virtual void holdSound(u32 soundId);                                         // starts/continues a sound by id - must be called every frame
    virtual void holdSound(u32 soundId, u32 arg);                                // starts/continues a sound by id & sets a sequence arg - must be called every frame
    virtual void holdSound(const char* soundName);                               // starts/continues a sound by name - must be called every frame
    virtual void vfAC(u32, u8, u8);                                              // 
    virtual void vfB0(u32, u32, u32);                                            // 
    virtual void vfB4(u32, u32);                                                 // 
    virtual void vfB8(u32, u32, u32);                                            // 
    virtual void playSound(u32 soundId, const Vec2f& position, bool stopSound=true);  // starts/stops playback of a sound at position, does not use Sound Actor
    virtual void vfC0(u32);                                                      // 
    virtual void vfC4(u32);                                                      // 

    virtual void setupFromCreateInfo(CreateInfo* info);
    virtual void vfCC();                                                // null
    virtual bool isOutOfView();
    virtual void powActivated();

    void fetchZone();                   // reassigns zone to the current one, only used by player actor
    bool assignLocation(u8 id);
    void cullCheck(u32 checksBitfield = 0);
    u8 directionToPlayerH(const Vec3f& checkPosition);
    u8 directionToPlayerV(const Vec3f& checkPosition);
    s8 closestPlayerOffset(Vec3f& playerOffsetOut);      // Returns the player id
    
    void spawnDeathEffect(const Vec3f& position, SpawnDeathEffectType type, const Vec3f& rotation);

    void moveToTargetYSpeed(f32 increment, f32 target);
    void incrementYSpeed(f32 increment, f32 minSpeed);

    void applyAccelerationH();

    void despawn(bool isRespawnable);

    static ActorBase* create(CreateInfo* info);

    // Custom helper methods
    void updateModelMatrixWithOffset(Model* model);
    void updateModelMatrixWithOffset(AnimModelBase* model);

    void updateModelMatrix(Model* model);
    void updateModelMatrix(AnimModelBase* model);

    s8 playerId;                    // 14   inited to -1
    u8 layer;                       // 15   
    bool isCreated;                 // 16 
                                    // 17   padding
    f32 _18;                        // 18   inited to 0.0
    f32 _1C;                        // 1C   inited to 0.0
    f32 maxFallSpeed;               // 20   inited to 0.0
    f32 verticalAccel;              // 24   inited to 0.0
    f32 horizontalAccel;            // 28   inited to 0.0
    Vec2f aCollisionCheckLastShift; // 2C   set in beforeExecute
    Vec3f position;                  // 34
    Vec3f speed;                     // 40
    Vec3f maxSpeed;                  // 4C
    Vec3f scale;                     // 58   inited to (1.0, 1.0, 1.0)
    Vec3i rotation;                 // 64   inited to (0, 0, 0)
    u32 _70;                        // 70   inited to 0
    u32 _74;                        // 74   inited to 0
    u32 _78;                        // 78   inited to 0
    u8 deathEffectType;             // 7C   0: Smoke puff with sparkles, 1: Small smoke puff, 2: Smoke puff, 4: Big smoke puff
    bool bigLiquidSplash;           // 7D   inited to false, roughly doubles the splash size
                                    // 7E   padding    
    Vec2f aCollisionCheckShift;             // 80   Added to position and zeroed in beforeExecute
    ActorCollisionCheck aCollisionCheck;         // 88
    Vec2f visibleAreaOffset;         // 140
    Vec2f existDistance;             // 148
    Vec2f visibleDistance;           // 150
    sead::BoundBox2f cullRelated;   // 158  Used in cullCheck() to check when to erase actor, possibly zone bounds related
    sead::BoundBox2f location;      // 168  set by assignLocation
    bool hasLocation;               // 178  inited to 0, set by assignLocation
                                    // 179  padding
    u32 spriteData1;                // 17C  nybbles  4-11
    u32 spriteData2;                // 180  nybbles 12-19
    u8 movementId;                  // 184  nybbles 20-21
    u8 spriteData3;                 // 185  nybbles 22-23
                                    // 186  padding    
    u32 eventMgrRelated;            // 188  inited to 0          0x4 - Flagpole grabbed, 0x8 - Zone load
    u8 zone;                        // 18C  inited to current zone
    u8 actorType;                   // 18D  0: Not specified, 1: Player, 2: Enemy
    u8 aCollisionCheckEnabled;      // 18E  ActorCollisionCheck callbacks are disabled if set to zero
    bool visible;                   // 18F  not drawn if set to false, inited to true
    bool disableRespawn;            // 190  inited to 0
    bool eraseLater;                // 191  not drawn and erased in next beforeExecute if set to true
    u8 targetFlagId;                // 192  nybbles 0-1
    u8 triggeringFlagId;            // 193  nybbles 2-3
    u16 _194;                       // 194
                                    // 196  padding    
    u32 powTimer;                   // 198  decremented in beforeExecute, powActivated is called when it reaches 8
    u8 _19C;                        // 19C  inited to 0
    u8 _19D;                        // 19D  inited to 0
    u8 _19E;                        // 19E  inited to 0
                                    // 19F  padding    
    u32 _1A0;                       // 1A0  inited to 0
    u32 flags;                      // 1A4  ActorInfo::Flags
    Vec3f centerOffset;              // 1A8  inited to (0.0, 0.0, 0.0)
    Vec3f lastPosition;              // 1B4  always updated to the same values as position
    u8* respawnSettings;            // 1C0
    void* soundActor;               // 1C4
};
