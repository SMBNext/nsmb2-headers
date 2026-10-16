#pragma once

#include "enemy/Enemy.h"
#include "gfx/AnimModel.h"
#include "math/Mtx34.h"
#include "math/Vec.h"
#include "sead/seadVector.h"
#include "types.h"
#include <Allocator.h>

// size: 0x11D0
class BrosBase : public Enemy
{
public:
    enum class BrosType
    {
        cNone       = -1,   // 
        cHammer     = 0,    // HammerBros
        cFire       = 1,    // FireBros
        cBoomerang  = 2,    // BoomerangBros
    };
    
public:
    BrosBase();

    Result onCreate() override;
    Result onDelete() override;
    Result onExecute() override;
    Result onDraw() override;

    bool damagePlayer(PlayerBase* player) override;
    void collisionPlayer(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionGroundPound(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;

    void doQuakeBounce() override;

    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(BrosBase, DieFumi);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(BrosBase, DieFall);
    
    DECLARE_STATE_VIRTUAL_ID_BASE(BrosBase, Walk);
    DECLARE_STATE_VIRTUAL_ID_BASE(BrosBase, Attack);
    DECLARE_STATE_VIRTUAL_ID_BASE(BrosBase, JumpSt);
    DECLARE_STATE_VIRTUAL_ID_BASE(BrosBase, Jump);
    DECLARE_STATE_VIRTUAL_ID_BASE(BrosBase, JumpEd);
    DECLARE_STATE_VIRTUAL_ID_BASE(BrosBase, JumpAttack);

    // Returns the frame of the throw animation at which the projectile should be spawned.
    virtual f32 throwStartFrame() const;

    // Returns the frame of the throw animation at which the projectile should be released.
    virtual f32 throwReleaseFrame() const;

    // Handles the transition in and out of the gold state.
    virtual void changeGold();

    // Creates an instance of `ActorCoinBros` at `this->mCoinBrosPosition`.
    virtual void createActorCoinBros();

    // Sets the value of `this->mSpeed` for grounded movement.
    virtual void setWalkingSpeed();

    // Deleted.
    virtual void vf230();

    // Returns the `BrosType` for this Bros.
    virtual BrosType getBrosType();

    // Sets the value of `this->mAttackCooldown`.
    // Is called from `initializeState_Walk`.
    virtual void setAttackCooldown();

    // Deleted.
    virtual void vf23C();

    // Updates the Bros' position when patrolling left/right.
    virtual void updatePatrol();

    // Updates the projectile during a throw animation, keeping it attached to the hand.
    virtual void updateThrow();

    // Creates a projectile and parents it to the Bros.
    virtual void createProjectile();

    // Releases the projectile from the Bros hand.
    virtual void releaseProjectile();

    // Sets `this->mJumpCooldown` to random value
    virtual void setJumpCooldown();

    // Sets `this->speed.y` for jumps.
    virtual void setJumpSpeed();

    // Changes the state to `StateID_Attack`.
    // Is called once `this->mJumpCooldown` reaches 1.
    virtual void changeToJumpAttack();

    // Unknown. Returns false.
    // Used to decrement a timer in `HammerBros` that returns false when complete.
    virtual bool vf25C();
    
    // Returns true if the Bros is able to attack while on the ground.
    virtual bool attackWhileGrounded() const;

    // Changes the state to `StateID_Attack`.
    // Is called once `this->mAttackCooldown` reaches 1.
    virtual void changeToAttack();

    // Sets the current animation to "throw".
    virtual void setThrowAnimation();

    // Sets `this->_1194` to 0.
    virtual void vf26C();

    // Unknown. Used by `HammerBros` to check ground position.
    virtual void vf270();

    // Unknown. Used to set the value of `mJumpFrequency` in `HammerBros`.
    virtual void vf274();

    // Returns the position projectiles should be spawned at.
    // Returns a different value depending on the type of projectile.
    Vec3f projectilePosition() const;
    
    // Returns true if the Bros has collided with a wall.
    bool isCollidedWall() const;

    // Sets the animation the model will use.
    void setAnim(const sead::SafeString& animName, PlayPolicy playPolicy, f32 a3);

    // Used to update model matrices for `this->mModelNormal`.
    void calcModel();

    // Calls either `mBgCollisionCheck->process()` or `mBgCollisionCheck->sub_218460()`.
    // The function called is determined by `this->mSpriteData2 & 0x01000000`.
    void processCollision();

protected:
    /* 0x1060 */  AnimModelBase* mModelNormal;               // The regular Bros model.
    /* 0x1064 */  AnimModelBase* mModelGold;                 // The gold Bros model.
    /* 0x1068 */  AnimModelBase* mActiveModelPtr;            // Points to the active model, either `mModelNormal` or `mModelGold`.
    /* 0x106C */  HeapAllocator mAllocator;                  //
    /* 0x1074 */  Mtx34 mBoneMatrices[5];                    // sead::Matrix34f
    /* 0x1164 */  sead::Vector3f mOriginPosition;            // Used to anchor the patrol movement.
    /* 0x1170 */  sead::Vector3f mCoinBrosPosition;          // Used when spawning `ActorCoinBros`.
    /* 0x117C */  u32 _117C;                                 //
    /* 0x1180 */  u32 _1180;                                 //
    /* 0x1184 */  u8 _1184;                                  //
    /* 0x1185 */  u8 _1185[3];                               // probably padding
    /* 0x1188 */  s32 mAttackCooldown;                       // Cooldown between attacks while grounded.
    /* 0x118C */  u32 _118C;                                 //
    /* 0x1190 */  s32 mJumpCooldown;                         // Cooldown between attacks while jumping. Randomly picked from a list with the options [90, 110, 90, 100].
    /* 0x1194 */  u32 _1194;                                 //
    /* 0x1198 */  u32 mNotFacingPatrol;                      // Set to 1 (true?) if `mPatrolDirection` != `mFacingDirection`.
    /* 0x119C */  u32 _119C;                                 //
    /* 0x11A0 */  u32 mNumProjectiles;                       // Set to 3 if gold, else 1 (projectile count maybe?) set in vf264
    /* 0x11A4 */  u32 _11A4;                                 //
    /* 0x11A8 */  u32 _11A8;                                 //
    /* 0x11AC */  u32 _11AC;                                 //
    /* 0x11B0 */  f32 mPatrolDistanceL;                      // The maximum distance the Bro can move to the left of it's origin.
    /* 0x11B4 */  f32 mPatrolDistanceR;                      // The maximum distance the Bro can move to the right of it's origin.
    /* 0x11B8 */  u32 _11B8;                                 //
    /* 0x11BC */  u32 _11BC;                                 //
    /* 0x11C0 */  u32 mHasProjectile;                        // Set to 1 (true?) if the Bros has a projectile in its hand.
    /* 0x11C4 */  Direction mPatrolDirection;                // The direction the Bro is currently walking.
    /* 0x11C5 */  u8 _11C5[3];                               // probably padding
    /* 0x11C8 */  ActorUniqueID mProjectileID;               // ID of the the last projectile thrown.
    /* 0x11CC */  bool mIsGold;                              //
    /* 0x11CD */  u8 _11CD[3];                               // probably padding
};

size_assert(BrosBase, 0x11D0);
