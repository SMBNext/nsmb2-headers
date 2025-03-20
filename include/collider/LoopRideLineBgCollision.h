#pragma once

#include "collider/ActorBgCollisionMgr.h"
#include "collider/BasicRideLine.h"


class LoopRideLineBgCollision : public BgCollision
{
public:
    struct Info
    {
        Vec2f positionOffset;
        Vec2f distToCenter;
        Vec2f* points;
        s32 rotation;
    };

    LoopRideLineBgCollision(u32 numSides, Vec2f* pointBuffer, BasicRideLine* rideLineBuffer, BasicRideLine* rideLinePrevBuffer);
    ~LoopRideLineBgCollision();

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

    sead::Buffer<Vec2f> point;                  // 138  size: numSides + 1   
    sead::Buffer<BasicRideLine> rideLine;       // 140  size: numSides
    sead::Buffer<BasicRideLine> rideLinePrev;   // 148  size: numSides
};
