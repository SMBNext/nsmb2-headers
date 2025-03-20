#pragma once

#include "Enemy.h"


class CarryableEnemy : public Enemy
{
    SEAD_RTTI_OVERRIDE(CarryableEnemy, Enemy);

public:
    CarryableEnemy();

    void collisionPlayer(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;

    virtual void vf1D4();
    virtual void jumpedOn(ActorBase* other);                                                    // Only called when not carryable
    virtual void jumpedOnMini(ActorBase* other);                                                // ^
    virtual void collisionPlayerNormal(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);      // Called when colliding with player without pickup
    virtual void collisionPlayerLiftable(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);    // Called when player pickup fails

    DECLARE_STATE_VIRTUAL_ID_BASE(CarryableEnemy, Carry);
    DECLARE_STATE_VIRTUAL_ID_BASE(CarryableEnemy, Liftable);
    DECLARE_STATE_VIRTUAL_ID_BASE(CarryableEnemy, Throw);

    void getCarryPosition(Vec3f& outPos);


    f32 _1060;
    f32 _1064;
    f32 _1068;

    u8 _unk106C[0x107C-0x106C];     // unknown size, max 0x107C
};
