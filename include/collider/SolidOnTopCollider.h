#pragma once

#include "collider/ActorBgCollisionMgr.h"
#include "collider/BasicRideLine.h"


class SolidOnTopColliderBase : public BgCollision  // size: 0x154
{
public:
    struct Info
    {
        Vec2f positionOffset;
        Vec2f distToCenter;
        Vec2f* points;
        s32 rotation;
    };

    SolidOnTopColliderBase(u32 numSides, Vec2f* pointBuffer, BasicRideLine* rideLineBuffer, BasicRideLine* rideLinePrevBuffer);
    ~SolidOnTopColliderBase();

    void setup(ActorBase* owner, const Info& info);

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

    sead::Buffer<Vec2f> points;             // 138  size: numSides + 1
    sead::Buffer<BasicRideLine> sides1;     // 140  size: numSides
    sead::Buffer<BasicRideLine> sides2;     // 148  size: numSides
    f32 thickness;                          // 150  inited to 4.0
};


template<u32 TNumSides>
class SolidOnTopCollider : public SolidOnTopColliderBase    // size: 0x154 + 0x40*TNumSides + 0x8*(TNumSides+1)
{
public:
    SolidOnTopCollider() : SolidOnTopColliderBase(TNumSides, pointArray, rideLineArray, rideLinePrevArray) { }

    Vec2f pointArray[TNumSides + 1];
    u32 _164;
    BasicRideLine rideLineArray[TNumSides];
    BasicRideLine rideLinePrevArray[TNumSides];
};
