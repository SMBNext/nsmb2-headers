#pragma once

#include "collider/TarzanBgCollisionCheck.h"
#include "collider/UnkCollisionClass.h"
#include "utility/Direction.h"

class ActorBase;

// vtable: 005B8B10
class PlayerBgCollisionCheck : public TarzanBgCollisionCheck
{
public:
    PlayerBgCollisionCheck();                   // 0032E698
    ~PlayerBgCollisionCheck();                  // 0032E730

    void checkBg() override;                    // 0032DEBC
    void clearBg() override;                      // 0021CEE0
    void atFrameStart() override;                     // 003054F8
    ActorBase* getOwnerAtRevCheck(f32 bgCollisionPosY) const override;   
    ActorBase* getOwnerAtHit(const BgCollision& collision, Direction direction) const override; 
    s8* getPlayerNum(f32 collisionYPos) override;                 // 004A43A4

    bool checkCeiling(const Vec3f& position, f32* out, f32 yOffset);   // 0032DE1C
    bool checkWall(Vec3f* position, Vec3f* normalOut, f32 xOffset);    // 0032DCA0
    u32 checkVineCollision(ActorBgCollisionCheck::Sensor* vineSensor);   // 0032E210

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
