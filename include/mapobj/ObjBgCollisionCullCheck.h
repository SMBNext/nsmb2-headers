#pragma once

#include "math/Vec.h"

class BgCollision;

// Size: 0x28
class ObjBgCollisionCullCheck
{
public:
    ObjBgCollisionCullCheck();

    // Initializes the cull check.
    void initialize(const Vec3f& position, const Vec2f& centerOffset, const Vec2f& size, const BgCollision& bgCollision);

    // Performs a cull check at the given `position`.
    void cullCheck(const Vec3f& position);

protected:
    /* 0x0 */  const BgCollision* mBgCollisionPtr;  // This points to ChangeBlockBase's collider
    /* 0x4 */  sead::Vector2f mCenterOffset;        //
    /* 0xC */  sead::Vector2f mSize;                // Init to ChangeBlockBase->visibleAreaOffset

    /* 0x14 */  struct {
        /* 0x0 */  f32 up;                          // Init to 128.0f
        /* 0x4 */  f32 down;                        // Init to 128.0f
        /* 0x8 */  f32 left;                        // Init to 80.0f
        /* 0xC */  f32 right;                       // Init to 80.0f
    } mCameraBoxPadding;

    /* 0x24 */  u8 mIsEntry;                        //
};

size_assert(ObjBgCollisionCullCheck, 0x28);
