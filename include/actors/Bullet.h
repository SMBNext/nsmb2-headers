#pragma once

#include "actors/ActorState.h"
#include "state/FStateVirtualID.h"

// Size 0x1000
class Bullet : public ActorState
{
public:
    enum class CollisionType : u8
    {
        cCollisionNone          = 0,    // No collision occurred.
        cCollisionReflect       = 1,    // Collided with a reflective surface.
        cCollisionStar          = 2,    // Collided with a player using a star/mega mushroom/white tanooki.
        cCollisionShell         = 3,    // Collided with a shell or a tail swipe.
        cCollisionYoshiBullet   = 4,    // Collided with a bullet spat out by a yoshi. [NSMBW/U Leftover].
    };

public:
    Bullet()
        : ActorState { }
    {
        this->actorType = ActorType_cBullet;
    };

    virtual ~Bullet() = default;

    Result onCreate() override;
    bool preExecute() override;
    Result onExecute() override;
    void deleteReady() override;

    void waterSplashEffect(const Vec3f& position, f32 scale = 1.0f) override;
    void powActivated() override;

    // Returns true if `this->mCollisionStatus` is not `cCollisionNone`.
    virtual bool isCollided() const;

    // Used to update model matrices for the Bullet's model.
    virtual void calcModel() = 0;

    DECLARE_STATE_VIRTUAL_ID_BASE(Bullet, EatIn);
    DECLARE_STATE_VIRTUAL_ID_BASE(Bullet, EatNow);
    DECLARE_STATE_VIRTUAL_ID_BASE(Bullet, SpitMove);
    DECLARE_STATE_VIRTUAL_ID_BASE(Bullet, Reflect);
    DECLARE_STATE_VIRTUAL_ID_BASE(Bullet, HitReflect);
    DECLARE_STATE_VIRTUAL_ID_BASE(Bullet, HitStar);
    DECLARE_STATE_VIRTUAL_ID_BASE(Bullet, HitShell);
    DECLARE_STATE_VIRTUAL_ID_BASE(Bullet, HitYoshiBullet);

    // Allocates the model for the Bullet.
    virtual void createModel() = 0;

    // Deleted. Leftover from NSMBW/NSMBU.
    // De-allocates the model for the Bullet.
    virtual void deleteModel() {}

    // Initializes the position/rotation/collision etc for the Bullet.
    virtual void initialize() = 0;

    //
    virtual void setDeathSpeed(const Vec3f& speed, s32 rotationSpeed);

    // Processes culling for the bullet.
    virtual void cullingProc();

    // Hit processing for star/mega mushroom/white tanooki collision.
    virtual bool hitProc_Star(ActorCollisionCheck* check);

    // Hit processing for shell collision.
    virtual bool hitProc_Shell(ActorCollisionCheck* check);

    // Hit processing for tail collision.
    virtual bool hitProc_Tail(ActorCollisionCheck* check);
    
    // Null. Leftover from NSMBW/NSMBU.
    // Roll effect used when bullet is spit out by a Yoshi.
    virtual void spitRoll();

    // Null. 
    virtual void moveSE() = 0;

    // Roll effect used when bullet is killed.
    virtual void deadRoll();

    // Callback for colliding with another actor.
    static void collisionCallback(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);

protected:
    /* 0xFE8 */  u8 _FE8;                                   //
    /* 0xFEC */  u32 deathDirection;                        // 
    /* 0xFF0 */  Bullet::CollisionType collisionStatus;     // The current collision status of the Bullet.
    /* 0xFF4 */  Vec3i rotationSpeed;                       //
};

size_assert(Bullet, 0x1000);
