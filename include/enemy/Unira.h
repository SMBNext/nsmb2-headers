#pragma once

#include "enemy/Enemy.h"

#include "gfx/AnimModel.h"

class Unira : public Enemy
{
public:
    Result onDelete() override;

    AnimModelBase* model;
    Resource* resource;
    HeapAllocator* allocator;
    u32 _106C;
    u32 _1070;
    u32 _1074;
    u32 _1078;
    u32 _107C;
    u32 _1080;
    u32 _1084;
    u32 _1088;
    u32 _108C;
    u32 _1090;
    u32 _1094;
    u32 _1098;
    u32 targetFlagIdNormalized;
    u32 _10A0;
    u32 _10A4;
    u32 _10A8;
    u32 _10AC;
    u8 isEventTriggered;
    u8 unkDrawFlag;
    u8 _10B2;
    u8 _10B3;
    u32 _10B4;
    u32 _10B8;
    u32 _10BC;

};
size_assert(Unira, 0x10C0);
