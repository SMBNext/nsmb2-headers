#pragma once

#include "actors/ActorState.h"
#include "effect/Effect.h"

class FunsuiCoin : public ActorState
{
public:
    LevelEffect effect;
    u8 direction;
    u8 _1045[3];                          // unk (padding?)
    u32 timer;
    u32 numSpawned;
    u32 _1050;
    u8 _1054;
    u8 _1055;
    u8 _1056;                             // set from spritedata
    u8 _1057;                             // padding?

    void spawnCoin();   // 0x001D46BC

    DECLARE_STATE_ID(FunsuiCoin, Wait);
    DECLARE_STATE_ID(FunsuiCoin, Activate);
};

size_assert(FunsuiCoin, 0x1058);
