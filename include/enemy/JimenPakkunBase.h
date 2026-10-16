#pragma once

#include "enemy/Enemy.h"
#include "gfx/Renderer.h"

class JimenPakkunBase : public Enemy
{
public:
    AnimModelBase* modelGold;                   // 1060
    AnimModelBase* modelNormal;                 // 1064
    void* model;                                // 1068     (points to some container whose first member is an AnimModelBase*)
    HeapAllocator allocator;                    // 106C
    u32 _1074;                                  // 1074
    void* _1078[5];                             // 1078
    u8 pad0[228];                               // 108C
    ActorCollisionCheck aCollisionCheck2;       // 1170
    ActorCollisionCheck aCollisionCheck3;       // 1228
    Vec3f unkPosition;                          // 12E0
    u8 pad2[38];                                // 12EC
    bool isUpsideDown;                          // 1312
    u8 pad3[53];                                // 1313

};

