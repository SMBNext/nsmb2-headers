#pragma once

#include "collider/BgCollision.h"

class RopeCollision : public BgCollision
{
public:
    class RopeCollision_140
    {
    public:
        RopeCollision_140();

        u32 _0;
    };

    RopeCollision();
    virtual ~RopeCollision();

    virtual void vfC(u32*, u32) override;
    virtual void vf10(u32*, u32) override;           // null
    virtual void vf14() override;
    virtual void execute() override;
    virtual void vf1C(u32*, u32, u32*, Vec2f*, u8) override;
    virtual void vf20(u32, u32*, u32, u32) override;
    virtual u32 vf24(u32, Vec2f*) override;
    virtual Vec2f vf28() override;
    virtual void vf2C() override;       // null
    virtual u32* vf30() override;
    virtual void vf34() override;
    virtual void vf38() override;

    u32 _138;
    u32 _13C;
    RopeCollision_140 _140[2];
    u32 _148;
    u32 _14C;
    u32 _150;
    u32 _154;
    u32 _158;
    u32 _15C;
    f32 _160;
    f32 _164;
    f32 _168;
    f32 _16C;
    f32 _170;
    f32 _174;
};

size_assert(RopeCollision, 0x178);
