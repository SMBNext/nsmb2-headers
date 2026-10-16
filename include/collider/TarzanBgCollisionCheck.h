#pragma once

#include "collider/ActorBgCollisionCheck.h"
#include "utility/Direction.h"

// vtable: 005B4974
class TarzanBgCollisionCheck : public ActorBgCollisionCheck     // size: 0xE58
{
public:
    TarzanBgCollisionCheck();              // 00305A18
    ~TarzanBgCollisionCheck();             // 00305A84
    
    void atFrameStart() override;                     //  003054FC

    ActorBase* getOwnerAtRevCheck(f32 bgCollisionPosY) const override;                 //  004A2A40
    ActorBase* getOwnerAtHit(const BgCollision& collision, Direction direction) const override;   //  004A2A38
    s8* getPlayerNum(f32 collisionYPos) override;                 //  004A2A24

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