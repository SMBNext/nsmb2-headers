#pragma once

#include "collider/BgHitCheckCallback.h"

class ActorBgCollisionCheck;

class ActorBgHitCheckCallback : public BgHitCheckCallback
{
public:
    virtual bool hit(const BgCollisionCheckResultPoint& hitRes) override;
    virtual bool hit(const BgCollisionCheckResultArea& hitRes) override;

    ActorBgCollisionCheck* mBgCollisionCheck;
};
