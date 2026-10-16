#pragma once

#include "collider/ActorBgCollisionCheck.h"
#include "math/Vec.h"
#include "types.h"
#include "utility/Direction.h"

// Size: 0xDC0
class ActorBgCollisionObjCheck : public ActorBgCollisionCheck
{
public:
    ActorBgCollisionObjCheck();

    ActorBase* getOwnerAtHit(const BgCollision& collision, Direction direction) const override;
    ActorBase* getOwnerAtRevCheck(f32 bgCollisionPosY) const override;
    s8* getPlayerNum(f32 collisionYPos) override;
    
    // Casts a ray from `rayStart` to `rayEnd` against `BgCollision` in the given directions `dirMask`.
    // Optionally returns the hit point in `hitPosOut` if one occurred.
    bool hitCheck(Vec2f* hitPosOut, const Vec2f& rayStart, const Vec2f& rayEnd, DirectionMask dirMask);
};

size_assert(ActorBgCollisionObjCheck, 0xDC0);
