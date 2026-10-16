#pragma once

#include "collider/BgUnitCode.h"
#include "math/Vec.h"
#include "types.h"
#include "utility/Angle.h"

class BgCollision;

// Size: 0x38
class ActorBgCollisionCheckResult
{
public:
    /* 0x00 */  u8 _0;                          //
    /* 0x01 */  bool mIsSolidOnTop;             // true if  the tile's HitboxType is solid on top
    /* 0x02 */  u8 _2;                          //
    /* 0x03 */  bool mIsHit;                    // unnsure, but seems correct based on usage? is maybe "has collision"
    /* 0x04 */  u8 mLayer;                      // may just be an s8 + 3 byte padding
    /* 0x05 */  
    /* 0x06 */  
    /* 0x07 */  
    /* 0x08 */  Angle mAngle;                   //
    /* 0x0C */  Vec2f mContactPoint;            // the point where the sensor collided with the BgCollision
    /* 0x14 */  Vec2f _14;                      //
    /* 0x1C */  BgCollision *mpOwner;           //
    /* 0x20 */  BgUnitCode mBgCheckData;        //
    /* 0x28 */  f32 _28;                        // unsure?
    /* 0x2C */  u32 _2C;                        // unsure?
    /* 0x30 */  u8 _30;                         //
    /* 0x31 */  
    /* 0x32 */  
    /* 0x33 */  
    /* 0x34 */  u32 _34;                        //
};

size_assert(ActorBgCollisionCheckResult, 0x38);