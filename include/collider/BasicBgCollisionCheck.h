#pragma once

#include "sead/seadBitFlag.h"


class ActorBase;

class BasicBgCollisionCheck     // size: 0x4C
{
public:
    BasicBgCollisionCheck();    // 0044A37C
    
    u8 _0;                                  // inited to 0
    bool ignoreQuicksand;
    sead::BitFlag8 collisionMask;
    u32 _4;
    u32 _8;
    ActorBase *actor;
    void *_10;                              // points to this+0x50?
    void *_14;                              // points to this+0x24?
    u32 _18;
    u32 _1C;
    u32 _20;
    u32 *_unk24[10];                        // first element is pointer to owner?
};
