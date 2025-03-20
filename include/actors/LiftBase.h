#pragma once

#include "actors/ActorState.h"

class LiftBase : public ActorState
{
public:
    LiftBase();

    bool isOn(BgCollision* collider, u32 unk);

    u8 _FE8;
};
