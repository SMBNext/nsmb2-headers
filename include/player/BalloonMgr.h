#pragma once

#include "actors/ActorBase.h"
#include "sead.h"

class BalloonMgr
{
    SEAD_SINGLETON_DISPOSER(BalloonMgr);
public:
    s32 _10;                              // probably another actor id
    ActorUniqueID actorIds[5];
    u32 _28;
    u8 _2C;
    u8 _2D[3];                            // unk (probably padding)
    u32 _30;
    u8 state;                            // unsure maybe flags?, 1 = disable player Bubble? 3 = unk, used in CannonWarp::State_407
    u8 _35[3];                            // unk (probably padding)
    u32 _38;                              // counter, max value 3 (see: 003E7DF0)
};
