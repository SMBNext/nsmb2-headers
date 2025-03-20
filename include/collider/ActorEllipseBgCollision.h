#pragma once

#include "collider/ActorBgCollisionMgr.h"


class ActorEllipseBgCollision : public BgCollision    // size: 0x170
{
public:
    struct Info     // size: 0x20
    {
        Vec2f positionOffset;    // 0
        u32 _8;                 // 8
        u32 _C;                 // C
        u32 _10;                // 10
        u32 _14;                // 14
        f32 radius;             // 18
        f32 rotation;           // 1C
    };

    ActorEllipseBgCollision();

    void setup(ActorBase* owner, const Info& info);

    void vfC(u32*, u32) override;
    void vf10(u32*, u32) override;
    void vf14() override;
    void execute() override;
    void vf1C(u32*, u32, u32*, Vec2f*, u8) override;
    void vf20(u32, u32*, u32, u32) override;
    u32 vf24(u32, Vec2f*) override;
    Vec2f vf28() override;
    void vf2C() override;           // deleted
    u32* vf30() override;
    void vf34() override;
    void vf38() override;

    Vec2f _138;
    Vec2f _140;
    Vec2f _148;
    Vec2f halfSize;
    u32 _158;
    u32 _15C;
    u32 _160;
    u32 _164;
    u32 _168;
    u32 _16C;
};
