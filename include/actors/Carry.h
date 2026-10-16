#pragma once

#include "enemy/Enemy.h"
#include "math/Vec.h"

// Size: 0x107C
class Carry : public Enemy
{
    SEAD_RTTI_OVERRIDE(Carry, Enemy);
public:
    Carry();

    void collisionPlayer(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;

    // Unknown.
    virtual void vf1D4();

    // Handles the reaction to being stomped by a player.
    virtual void reactFumiProc(ActorBase* other);

    // Handles the reaction to being stomped by a player using the Mini Mushroom.
    virtual void reactMameFumiProc(ActorBase* other);

    // Handles collision with players when the Carry actor is not liftable ("awake").
    virtual void collisionPlayer_Awake(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);

    // Handles collision with players when the Carry actor is liftable ("asleep").
    virtual void collisionPlayer_Sleep(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);

    DECLARE_STATE_VIRTUAL_ID_BASE(Carry, Carry);
    DECLARE_STATE_VIRTUAL_ID_BASE(Carry, Sleep);
    DECLARE_STATE_VIRTUAL_ID_BASE(Carry, Slide);

    // Sets `this->collisionCheck` for when the Carry is sliding.
    void setSlideCollisionCheck();

    // Resets `this->collisionCheck` to the default state.
    void resetSlideCollisionCheck();
    
    // Unknown. Handles fumi collision when the Carry is in `StateID_Carry`.
    bool sub_3AAB38(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);
    
    // Sets `this->mBgCollisionCheck` for when the Carry is sliding.
    void setSlideBgCollisionCheck();

    // Unknown. 
    bool sub_3AAD50(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);

    // Resets `this->mBgCollisionCheck` to the default state.
    void resetSlideBgCollisionCheck();

    // Unknown. 
    // Sets `this->mDirection = getDirectionToActor(actor)`.
    // Sets `this->mPlayerId = actor->mPlayerId`.
    void sub_3AB09C(ActorBase* actor);

    // Unknown. Related to being thrown/kicked?
    bool sub_3AB110(ActorBase* actor);

    // Unknown. Returns true if `this->collisionCheck->collisionOffsets[3] < 0.0f`.
    bool sub_3AB424(ActorCollisionCheck* check);

    // Unknown. Sets death info for dying while carried?
    // Spawns a kick effect and plays a sound if `doEffect` is true.
    bool setDeathInfoUnk(ActorBase* actor, bool doEffect);

    // Returns the position of the Carry relative to the player carrying it.
    void getCarryPosition(Vec3f& outPos);

protected:
    /* 1060 */  Vec3f mCarryBaseOffset;     // The base offset used for positioning when being carried.
    /* 106C */  Vec2f mCollisionCenter;     // Stores a copy of `collisionCheck.collisionData.centerOffset` so it can be restored when thrown.
    /* 1074 */  Vec2f mCollisionHalfSize;   // Stores a copy of `collisionCheck.collisionData.halfSize` so it can be restored when thrown.

};

size_assert(Carry, 0x107C);
