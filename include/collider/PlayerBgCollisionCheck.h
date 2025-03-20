#pragma once

#include "collider/PlayerKoopalingBgCollisionCheck.h"
#include "collider/UnkCollisionClass.h"

class ActorBase;

// vtable: 005B8B10
class PlayerBgCollisionCheck : public PlayerKoopalingBgCollisionCheck
{
public:
    PlayerBgCollisionCheck();                       // 0032E698
    ~PlayerBgCollisionCheck();                      // 0032E730

    void process() override;                    // 0032DEBC
    void dispose() override;                    // 0021CEE0
    void update() override;                     // 003054F8
    ActorBase* getOwner() override;                 // 004A4470
    ActorBase* vf1C(BgCollision*, u32) override;   // 004A43F4
    s8* getPlayerId() override;

    s8 playerId;    // Inited to -1
    u16 _E5A;       // Inited to 0
    u8 _E5C;        // Inited to 0
    u8 _E5D;        // Inited to 0
    u8 _E5E;        // Inited to 0
    u8 _E5F;        // Inited to 0
    u8 _E60;        // Inited to 0
    u8 _E61;        // Inited to 1
    u32 _E64;       // Inited to 0
    f32 _E68;       // Inited to 0.0f
    f32 _E6C;       // Inited to 0.0f
    f32 _E70;       // Inited to 0.0f
    f32 _E74;       // Inited to 0.0f
    f32 _E78;       // Inited to 0.0f
    f32 _E7C;       // Inited to 0.0f
    f32 _E80;       // Inited to 0.0f
    f32 _E84;       // Inited to 0.0f
    UnkCollisionClass _E88;
    UnkCollisionClass _EC0;
    u8 _EF8[4];                           ///< unk
    s32 _EFC;
    u8 _400[8];
};

size_assert(PlayerBgCollisionCheck, 0xF08);
