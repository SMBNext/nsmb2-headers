#pragma once

#include "actors/ActorMultiState.h"
#include "collider/RectCollider.h"
#include "gfx/AnimModel.h"  
#include "gfx/Renderer.h"

class GoalPole : public ActorMultiState
{
public:
    void createModels();

public:
    /* 0x0FEC */  u32 _FEC;
    /* 0x0FF0 */  RectCollider rectColider;
    /* 0x1260 */  HeapAllocator allocator;
    /* 0x1268 */  Resource* resource;
    /* 0x126C */  AnimModelBase* modelGolePole;
    /* 0x1270 */  AnimModelBase* modelBaseA;
    /* 0x1274 */  AnimModelBase* modelBaseABreak;
    /* 0x1278 */  AnimModelBase* modelTorideStd;
    /* 0x127C */  AnimModelBase* modelFlags[2];         // Koopa, Player
    /* 0x1284 */  AnimBase* matAnimGoalPole;
    /* 0x1288 */  AnimBase* matAnimBaseA;
    /* 0x128C */  AnimBase* matAnimTorideStd;
    /* 0x1290 */  AnimBase* matAnimFlagKoopa;
    /* 0x1294 */  AnimBase* matAnimFlagPlayer;
    /* 0x1298 */  ActorCollisionCheck aCollisionCheck;
    /* 0x1350 */  u32 _1350[20];
    /* 0x13A0 */  u32 _13A0;
    /* 0x13A4 */  u32 _13A4;
    /* 0x13A8 */  u32 _13A8;
    /* 0x13AC */  u32 _13AC;
    /* 0x13B0 */  bool isSecretExit;
    /* 0x13B4 */  u32 _13B4;
    /* 0x13B8 */  u32 _13B8;
    /* 0x13BC */  f32 _13BC;
    /* 0x13C0 */  u32 _13C0;
    /* 0x13C4 */  f32 _13C4;
    /* 0x13C8 */  u32 _13C8;
    /* 0x13CC */  u8 _13CC;
    /* 0x13D0 */  u32 _13D0;
    /* 0x13D4 */  u32 _13D4;
    /* 0x13D8 */  u32 _13D8;
    /* 0x13DC */  u32 _13DC;
    /* 0x13E0 */  u32 _13E0;
    /* 0x13E4 */  u32 _13E4;
    /* 0x13E8 */  u8 _13E8;
    /* 0x13E9 */  u8 _13E9;
    /* 0x13EA */  u8 _13EA;
    /* 0x13EB */  u8 _13EB;
    /* 0x13EC */  u8 _13EC;
    /* 0x13ED */  u8 _13ED;
    /* 0x13EE */  u8 _13EE;
    /* 0x13EF */  u8 _13EF;
    /* 0x13F0 */  u8 _13F0;
    /* 0x13F1 */  u8 _13F1;
    /* 0x13F4 */  u32 _13F4;
    /* 0x13F8 */  u32 _13F8;
    /* 0x13FC */  u32 _13FC;
    /* 0x1400 */  u32 _1400;
    /* 0x1404 */  u32 _1404;
    /* 0x1408 */  u8 _1408;
    /* 0x140C */  u32 _140C;
    /* 0x1410 */  u32 _1410;
    /* 0x1414 */  s32 _1414;
    /* 0x1418 */  u8 _1418;
    /* 0x1419 */  u8 _1419;
    /* 0x141A */  u8 _141A;
    /* 0x141C */  u32 _141C;
};
size_assert(GoalPole, 0x1420)
