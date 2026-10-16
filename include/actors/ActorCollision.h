#pragma once

#include "actors/ActorBase.h"
#include "collider/ActorBgCollisionObjCheck.h"
#include "types.h"

// size: 0xFC4
class ActorCollision : public ActorBase
{
    SEAD_RTTI_OVERRIDE(ActorCollision, ActorBase);
public:
    enum class QuakeCollisionType : u32
    {
        cMediumQuake = 0,
        cLargeQuake  = 1,
        cSmallQuake  = 2,
    };

    enum class LiquidProcessCmd : u8
    {
        cNoCommand      = 0,
        cEnableProcess  = 1,
        cDisableProcess = 2,
    };

public:
    ActorCollision();
    
    void postCreate(Result createResult) override;
    Result onDelete() override;
    bool preExecute() override;
    void postExecute(Result execResult) override;

    // Returns `this->collisionCheck`.
    ActorBgCollisionCheck* getBgCollisionCheck() override;

    // Returns `this->collisionCheck`.
    const ActorBgCollisionCheck* getBgCollisionCheck() const override;

    // Deleted
    virtual void vfD8();

    // Deleted
    virtual void vfDC();

    // Deleted
    virtual void vfE0();

    // Deleted
    virtual void vfE4();

    // Deleted
    virtual void vfE8();

    // Deleted
    virtual void vfEC();

    // Deleted
    virtual void vfF0();

    // Deleted
    virtual void vfF4();

    // Returns false
    virtual bool quakeCollisionEnabled();

    // Called in `preExecute` when a quake occurs if quake collision is enabled.
    virtual void onCollisionQuake(QuakeCollisionType quakeType);

    // Null. Called while in lava, depending on flags.
    virtual void onCollisionLava(ActorBase* other);

    // Returns 0.25.
    virtual f32 getLiquidSpeedScalarX();

    // Returns 0.0 if `this->_FB6` is true, otherwise returns `a1`.
    virtual f32 getUnkSpeedY(f32 a1);

    // Applies `this->accelerationY`, only enforcing the minimum speed / downward terminal velocity in `this->minSpeedY`.
    void applyFallAcceleration();

    // Accelerates towards `this->targetSpeedY`, where a negative `this->accelerationY` moves towards the target, and a positive moves away.
    void applyAccelerationY();

    // Processes movement, applying gravity, acceleration, and liquid forces.
    void processMovement();

    // Returns true if the actor is in touching two parallel walls or floors.
    bool isSquished();

public:
    /* 0x1C8 */  ActorBgCollisionObjCheck collisionCheck;   // 
    /* 0xF88 */  f32 unkXSpeedRelated;                      // Inited to 0.0, added to X speed in ActorBase::processMovement()
    /* 0xF8C */  f32 _F8C;                                  // Inited to 0.0
    /* 0xF90 */  Vec3f* liquidCheckPosition;                // Inited to &position
    /* 0xF94 */  f32 liquidSplashScale;                     // Inited to 1.0
    /* 0xF98 */  Vec2f unkSpeedAdditional;                  // Inited to (0.0, 0.0), added to speed in ActorBase::processMovement()
    /* 0xFA0 */  f32 _FA0;                                  // Inited to 0.0
    /* 0xFA4 */  f32 _FA4;                                  // Inited to 0.0
    /* 0xFA8 */  f32 maxSpeedYLiquid;                       // Inited to 1.5
    /* 0xFAC */  f32 minSpeedYLiquid;                       // Inited to -1.5
    /* 0xFB0 */  f32 accelerationYLiquid;                   // Inited to -0.0625
    /* 0xFB4 */  u8 inLiquidType;                           // Inited to 0
    /* 0xFB5 */  bool doLiquidProcess;                      // If set, the actor will process checks for liquids every frame. Should be set via liquidProcessCommand.
    /* 0xFB6 */  bool _FB6;                                 // 
    /* 0xF87 */  bool isInLiquid;                           // Whether the actor is in liquid. Only works if liquid processing is enabled.
    /* 0xFB8 */  u8 _FB8;                                   // 
    /* 0xFB9 */  bool disableLavaCallback;                  // If set, the onCollisionLava() callback will be disabled and actor will behave same as with poison or water.
    /* 0xFBA */  LiquidProcessCmd liquidProcessCmd;         // The command to give regarding liquid processing. Gets reset to 0 every frame (one-shot).
    /* 0xFBB */  bool forceXLiquidSpeedOnly;                // If set, the liquid scalar for X speed will be used, and Y speed will be set to a value defined in getUnkYSpeed()
    /* 0xFBC */  u8 _FBC;                                   // 
    /* 0xFBD */
    /* 0xFBE */
    /* 0xFBF */
    /* 0xFC0 */  u32 _FC0;                                  //
};

size_assert(ActorCollision, 0xFC4);
