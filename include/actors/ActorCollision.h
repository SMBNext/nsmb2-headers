#pragma once

#include "actors/ActorBase.h"
#include "collider/ActorBgCollisionCheck.h"


class ActorCollision : public ActorBase     // size: 0xFC4
{
    SEAD_RTTI_OVERRIDE(ActorCollision, ActorBase);

public:
    ActorCollision();
    
    void afterCreate(int) override;
    int onDelete() override;
    int beforeExecute() override;
    void afterExecute(int) override;

    ActorBgCollisionCheck* getBgCollisionCheck() override;   // returns collisionCheck
    ActorBgCollisionCheck* getBgCollisionCheck2() override;  // returns collisionCheck
    
    virtual void vfD8();    // deleted
    virtual void vfDC();    // deleted
    virtual void vfE0();    // deleted
    virtual void vfE4();    // deleted
    virtual void vfE8();    // deleted
    virtual void vfEC();    // deleted
    virtual void vfF0();    // deleted
    virtual void vfF4();    // deleted
    virtual bool vfF8();    // returns false
    virtual void vfFC(u32); // called from beforeExecute if vfF8 returns true and _190 is 0
    virtual void onCollisionLava(ActorBase* other);   // null, called when in lava, depending on flags
    virtual f32 vf104();    // returns 0.25
    virtual f32 vf108();

    void applyYAcceleration();      // calls Actor::incrementYSpeed with verticalAccel + speedMax.y
    void applyFallAcceleration();   // calls Actor::moveToTargetYSpeed with verticalAccel + maxFallSpeed

    void processMovement();

    ActorBgCollisionObjCheck collisionCheck;     // 1C8
    
    f32 _F88;                           // F88  inited to 0.0
    f32 _F8C;                           // F8C  inited to 0.0
    Vec3f* liquidCheckPosition;          // F90  inited to &position
    f32 liquidSplashScale;              // F94  inited to 1.0
    f32 _F98;                           // F98  inited to 0.0
    f32 _F9C;                           // F9C  inited to 0.0
    f32 _FA0;                           // FA0  inited to 0.0
    f32 _FA4;                           // FA4  inited to 0.0
    f32 yMaxSpeedLiquid;                // FA8  inited to 1.5
    f32 yMinSpeedLiquid;                // FAC  inited to -1.5
    f32 ySpeedIncrementLiquid;          // FBO  inited to -0.0625
    u8 inLiquidType;                    // FB4  inited to 0
    u8 _FB5;                            // FB5  ^
    u8 _FB6;                            // FB6  ^
    u8 isInLiquid;                      // FB7  ^
    u8 _FB8;                            // FB8  ^
    u8 _FB9;                            // FB9  ^
    u8 _FBA;                            // FBA  ^
    u8 _FBB;                            // FBB  ^
    u8 _FBC;                            // FBC  ^
    u32 _FC0;                           // FC0  ^
};
