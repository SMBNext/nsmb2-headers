#pragma once

#include "collider/ActorBgCollisionCheck.h"

// vtable: 005B4974
class PlayerKoopalingBgCollisionCheck : public ActorBgCollisionCheck     // size: 0xE58
{
public:
    PlayerKoopalingBgCollisionCheck();              // 00305A18
    ~PlayerKoopalingBgCollisionCheck();             // 00305A84
    
    void update() override;                     //  003054FC

    ActorBase* getOwner() override;                 //  004A2A40
    ActorBase* vf1C(BgCollision*, u32) override;   //  004A2A38
    s8* getPlayerId() override;                 //  004A2A24

    f32 _DBC;           // Inited to 0.0f
    f32 _DC0;           // Inited to 0.0f
    f32 _DC4;           // Inited to 0.0f
    f32 _DC8;           // Inited to 0.0f
    f32 _DCC;           // Inited to 0.0f
    f32 _DD0;           // Inited to 0.0f
    f32 _DD4;           // Inited to 0.0f
    f32 _DD8;           // Inited to 0.0f
    u8 _DDC[4];
    UnkCollisionClass _DE0;
    UnkCollisionClass _E18;
    u8 _E50[4];
    s32 ownerId;        // E54  Inited to -1
};