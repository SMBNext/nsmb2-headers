#pragma once

#include "collider/ActorBgCollisionMgr.h"
#include "collider/BasicRideLine.h"
#include "types.h"
#include "utility/Angle.h"

// Size: 0x154
class LineCollision : public BgCollision
{
public:
    // Size: 0x18
    struct Info
    {
        /* 0x00 */  Vec2f position;
        /* 0x08 */  Vec2f centerOffset;
        /* 0x10 */  Vec2f* points;
        /* 0x04 */  Angle rotation;
    };
    size_assert(Info, 0x18);

    LineCollision(u32 numSides, Vec2f* pointBuffer, BasicRideLine* rideLineBuffer, BasicRideLine* rideLinePrevBuffer);
    ~LineCollision();

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

protected:
    /* 0x138 */  sead::Buffer<Vec2f> mPoint;                    // Buffer of points that make up the line. Capacity: `numSides + 1`.
    /* 0x140 */  sead::Buffer<BasicRideLine> mRideLine;         // Buffer of line segments. Capacity: `numSides`.
    /* 0x148 */  sead::Buffer<BasicRideLine> mRideLinePrev;     // Buffer of line segments from the previous frame. Capacity: `numSides`.
    /* 0x150 */  f32 mThickness;                                // The thickness of the line. Initialized to `4.0f`.
};



