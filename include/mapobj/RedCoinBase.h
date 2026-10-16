#pragma once

#include "actors/ActorMultiState.h"

#include "collider/RectCollider.h"
#include "course/PairChild.h"
#include "gfx/Renderer.h"

class RedCoinBase : public ActorMultiState
{
    SEAD_RTTI_OVERRIDE(RedCoinBase, ActorMultiState);

public:
    static u8 RedRingContents[];

    Model* model;
    HeapAllocator allocator;
    PairChild pairChild;
    u32 movementType;
    u32 movementId;
    u32 coinGroupID;
    u32 _10D4;
    u8 playerIdx;                   // used for  giving score etc
    u32 _10DC;
    u32 _10E0;
    u8 _10E4;
    u8 _10E5;
    u16 coinIdx;
    u8 _10E8[4];
    u32 _10EC;
    u8 _10F0;                       // maybe bool
    u8 _10F1;                       // maybe bool
    u8 _10F2[5];
    RectCollider rectCollider;
    u32 itemGetFlag[2];
    u32 contents[2];
    u32 _1378;
    u32 _137C;
    u8 _pad3[12];
    u32 _138C;
    s32 paraCoinStartAngle;         // init to 0xE00000
    bool paraCoinSyncType;
    Vec3i _1398;
    u16 fallSpeedIdx;
    bool isGravityAffected;
    u8 _13A7[9];
    u8 _13B0;
    void* paraParent;               // RedCoinParaParent
    Model* paraModel;
    HeapAllocator paraAllocator;
    u8 _13C4;
    u8 _13C5;

};

size_assert(RedCoinBase, 0x13C8);
