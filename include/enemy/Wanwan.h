#pragma once

#include "enemy/Enemy.h"
#include "gfx/AnimModel.h"

// size: 0x1270
class Wanwan : public Enemy
{
public:

public:
    /* 0x1060 */  AnimModel<1,1,0>* model;
    /* 0x1064 */  Resource* resource;
    /* 0x1068 */  HeapAllocator allocator;
    /* 0x1070 */  Model* chainModels[5];
    /* 0x1084 */  Vec3f _1084;                 // init to this->position (chain related)
    /* 0x1090 */  Vec3f _1090;                 // init to this->position (chain related)
    /* 0x109C */  Vec3f _109C;                 // init to this->position + some offsets (chain related)
    /* 0x10A8 */  Vec3f _10A8;
    /* 0x10B4 */  Vec3f _10B4;
    /* 0x10C0 */  Vec3f _10C0;
    /* 0x10CC */  Vec3f _10CC;
    /* 0x10D8 */  Vec3f _10D8;
    /* 0x10E4 */  u8 _10E4;
    /* 0x10E5 */  u8 _10E5;
    /* 0x10E6 */  u8 _10E6[2];                  // Probably padding
    /* 0x10E8 */  f32 _10E8;
    /* 0x10EC */  f32 _10EC;
    /* 0x10F0 */  u32 _10F0;
    /* 0x10F4 */  u32 _10F4;
    /* 0x10F8 */  u32 _10F8;
    /* 0x10FC */  u32 _10FC;                    // stores result of indexing table with random number (0 - 5)
    /* 0x1100 */  u32 randValue;                // random value between 0 - 7
    /* 0x1104 */  u32 _1104;
    /* 0x1108 */  u32 _1108;
    /* 0x110C */  u32 _110C;
    /* 0x1110 */  u8 _[352];                    // Unk
};

size_assert(Wanwan, 0x1270);
