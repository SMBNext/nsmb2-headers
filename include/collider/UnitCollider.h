#pragma once

#include "collider/BgCollision.h"
#include "collider/PolylineCollision.h"
#include "collider/UnitShape.h"
#include "collider/UnitShapeBase.h"
#include "sead/heap/seadDisposer.h"
#include "sead/seadVector.h"
#include "types.h"

// Size: 0x0x598
class UnitCollider
{
    SEAD_SINGLETON_DISPOSER(UnitCollider);
public:
    UnitCollider();

    // Sets up the collider to match the solid tile at the provided position (`posX`, `posY`) on the given `layer`.
    void setSolidTile(u32 posX, u32 posY, u8 layer);

    // Sets up the collider to match the tile at the provided position (`posX`, `posY`) on the given `layer`.
    void setTile(u32 posX, u32 posY, u8 layer);
    
    // Sets up the collider to match the bottom-half of the slope tile at the provided position (`posX`, `posY`) on the given `layer`.
    void setSlopeBottomTile(u32 posX, u32 posY, u8 layer);

    // Sets up the collider to match the top-half of the upside-down slope tile at the provided position (`posX`, `posY`) on the given `layer`.
    void setReverseSlopeBottomTile(u32 posX, u32 posY, u8 layer);

    // Returns a pointer to the `BgCollision` instance used by the collider.
    BgCollision* getBgCollision() const { return mCollisionPtr; }
    
private:
    /* 0x010 */  u8 _10;                                    //
    /* 0x011 */  u8 mLayer;                                 // The layer of the tile. Passed to FollowArg when constructing collision.
    /* 0x012 */  s8 mPlayerNum;                             // The playerNum associated with the tile (Always -1). Passed to FollowArg when constructing collision.
    /* 0x014 */  Vec3f mPosition;                           // The position of the tile. Passed to FollowArg when constructing collision.
    /* 0x020 */  LineCollision::Info mTwoPointInfo;         // Stores the info used when constructing a two-point collision.
    /* 0x038 */  UnitShapeBase::Info* mThreePointInfoPtr;   // Stores the info used when constructing a three-point collision.
    /* 0x03C */  UnitShapeBase::Info* mFourPointInfoPtr;    // Stores the info used when constructing a four-point collision.
    /* 0x040 */  PolylineCollision<1> mTwoPointCollision;   // The two-point collision.
    /* 0x1E8 */  UnitShape<3> mThreePointCollision;         // The three-point collision.
    /* 0x3A8 */  UnitShape<4> mFourPointCollision;          // The four-point collision.
    /* 0x590 */  BgCollision* mCollisionPtr;                // Pointer to the currently in-use collision.
    /* 0x594 */  u8 _594[4];                                //
};

size_assert(UnitCollider, 0x598);
