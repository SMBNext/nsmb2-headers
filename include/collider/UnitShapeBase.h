#pragma once

#include "collider/BasicRideLine.h"
#include "collider/BgCollision.h"
#include "math/Vec.h"
#include "sead/seadBuffer.h"

class UnitShapeBase : public BgCollision
{
public:
    // Size: 0x10
    struct Vertex
    {
        /* 0x0 */  Vec2f position;  // Position of the vertex.
        /* 0x8 */  u32 _8;          //
        /* 0xC */  u8 _C;           //
        /* 0xD */
        /* 0xE */
        /* 0xF */
    };
    size_assert(Vertex, 0x10);
    
    // Size: 0x4
    struct Info
    {
        /* 0x00 */  Vertex* vertexData;     // Pointer to the vertex data.
    };
    size_assert(Info, 0x4);

public:

    UnitShapeBase(u32 numSides, Vec2f* pointBuffer, BasicRideLine* rideLineBuffer, BasicRideLine* rideLinePrevBuffer);
    ~UnitShapeBase();
    
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
    /* 0x138 */  sead::Buffer<Vec2f> mPoint;            // Buffer of points that make up the shape. Capacity: `numSides`.
    /* 0x140 */  sead::Buffer<BasicRideLine> mRideLine;  // Buffer of line segments. Capacity: `numSides`.
};