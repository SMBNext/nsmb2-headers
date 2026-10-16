#pragma once

#include "actors/ActorMultiState.h"
#include "actors/AttentionLook.h"
#include "course/PairChild.h"
#include "gfx/AnimModel.h"

// Size: 0x1138
class CollectionCoinBase : public ActorMultiState
{
public:
    bool setup();                               // 0x003356C0

public:
    /* 0x0FEC */  AnimModelBase* model;             //
    /* 0x0FF0 */  HeapAllocator allocator;          //
    /* 0x0FF8 */  Vec3f _FF8;                       // Inited to position
    /* 0x1004 */  PairChild pairChild;              //
    /* 0x10D4 */  u8 _10D4[12];                     //
    /* 0x10E0 */  u32 _10E0;                        //
    /* 0x10E4 */  u32 movementType;                 //
    /* 0x10E8 */  u32 _10E8;                        //
    /* 0x10EC */  u32 coinId;                       // Nybble 8
    /* 0x10F0 */  u32 zDepth;                       // Nybble 9
    /* 0x10F4 */  u32 _10F4;                        // Nybble 6 bit 1
    /* 0x10F8 */  u8 _10F8[12];                     //
    /* 0x1104 */  u16 _1104;                        //
    /* 0x1106 */  s8 _1106;                         // Inited to -1
    /* 0x1107 */  u8 _1107;                         // Inited to 0 or 54
    /* 0x1108 */  AttentionLook attentionLook;      //
    /* 0x1134 */  u8 _1134[4];                      //
};

size_assert(CollectionCoinBase, 0x1138);
