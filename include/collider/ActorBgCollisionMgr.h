#pragma once

#include "collider/BgCollision.h"
#include "sys/LineNodeMgr.h"

class ActorBgCollisionMgr : public sead::IDisposer
{
public:
    static ActorBgCollisionMgr* instance;                   // 0x005E3CE0

    void addToList(BgCollision* collider);         // 0x002E4C94
    void removeFromList(BgCollision* collider);    // 0x002E519C

    LineNodeMgr<BgCollision> lists[6];
};
