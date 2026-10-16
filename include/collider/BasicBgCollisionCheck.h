#pragma once

#include "sead/container/seadRingBuffer.h"
#include "math/Vec.h"
#include "types.h"
#include "utility/Direction.h"

class ActorBase;
class ActorBgHitCheckCallback;
class BgCollision;
class BgCollisionCheckResultArea;
class BgUnitCode;

// size: 0x4C
class BasicBgCollisionCheck
{
public:
    using IgnoreList = sead::FixedRingBuffer<ActorBase*, 10>;

    enum class HitCheckType : u8
    {
        cCheckSolid     = 0,    // Perform collision checks against BgCollision with `BgUnitCode::HitType_cFull`, `BgUnitCode::HitType_cHalf` or `BgUnitCode::HitType_cHalfCeiling`.
        cCheckNonSolid  = 1,    // Perform collision checks against BgCollision with `BgUnitCode::HitType_cNone`.
    };

public:
    // Size: 0xC
    struct InitArg
    {
        /* 0x00 */  bool forceEdgeCheck;                        // If enabled, forces full edge-by-edge collision checking, even when the ray starts inside the shape.
        /* 0x01 */  bool isIgnoreQuicksand;                     // If the CollisionCheck should ignore quicksand collision.
        /* 0x02 */  u8 _2;                                      // Unused?
        /* 0x03 */  u8 layer;                                   // Determines the tile layer to check against.
        /* 0x04 */  HitCheckType hitCheckType;                  // Determines the type of BgCollision that should be checked against (Solid/NonSolid).
        /* 0x05 */
        /* 0x06 */
        /* 0x07 */
        /* 0x08 */  ActorBgHitCheckCallback* hitCheckCallback;  // The callback that should be used during hit checking.
    };
    size_assert(InitArg, 0xC);
    
public:
    BasicBgCollisionCheck();

    BasicBgCollisionCheck(const InitArg& initArg);

    // Initializes the collision check with the provided `initArg`.
    void initialize(const InitArg& initArg);

    // Performs a hit check with the ray `rayStart` to `rayEnd` against all `BgCollision` with the given directions `hitDirMask`.
    // Returns `true` if a hit occurs.
    // Optionally returns a `BgCollisionCheckResultArea` via `resultOut`.
    bool hitCheck(BgCollisionCheckResultArea* resultOut, const Vec2f& rayStart, const Vec2f& rayEnd, DirectionMask hitDirMask) const;

    // Performs a hit check with the ray `rayStart` to `rayEnd` against actor `BgCollision` with the given directions `hitDirMask`.
    // Returns `true` if a hit occurs.
    // Optionally returns a `BgCollisionCheckResultArea` via `resultOut`.
    bool hitCheckActor(BgCollisionCheckResultArea* resultOut, const Vec2f& rayStart, const Vec2f& rayEnd, DirectionMask hitDirMask) const;

    // Performs a hit check with the ray `rayStart` to `rayEnd` against tile `BgCollision` with the given directions `hitDirMask`.
    // Returns `true` if a hit occurs.
    // Optionally returns a `BgCollisionCheckResultArea` via `resultOut`.
    bool hitCheckUnit(BgCollisionCheckResultArea* resultOut, const Vec2f& rayStart, const Vec2f& rayEnd, DirectionMask hitDirMask) const;

    // Performs a hit check at the position `checkPos` against all `BgCollision`.
    // Returns `true` if a hit occurs.
    // Optionally returns a `BgUnitCode` via `unitCodeOut`.
    bool hitCheck(BgUnitCode* unitCodeOut, const Vec2f& checkPos) const;

    // Performs a hit check at the position `checkPos` against actor `BgCollision`.
    // Returns `true` if a hit occurs.
    // Optionally returns a `BgUnitCode` via `unitCodeOut`.
    bool hitCheckActor(BgUnitCode* unitCodeOut, const Vec2f& checkPos) const;

    // Performs a hit check at the position `checkPos` against tile `BgCollision`.
    // Returns `true` if a hit occurs.
    // Optionally returns a `BgUnitCode` via `unitCodeOut`.
    bool hitCheckUnit(BgUnitCode* unitCodeOut, const Vec2f& checkPos) const;

    // Returns access to `this->mIgnoreList`.
    IgnoreList& getIgnoreList()
    {
        return  mIgnoreList;
    }

    // Returns const access to `this->mIgnoreList`.
    const IgnoreList& getIgnoreList() const
    {
        return  mIgnoreList;
    }

    // Sets the owner of this CollisionCheck.
    void setOwner(ActorBase* owner)
    {
        mOwnerPtr = owner;
    }

    // Sets whether this CollisionCheck should force full edge-by-edge collision checking.
    void forceEdgeCheck(bool enabled)
    {
        mForceEdgeCheck = enabled;
    }

    // Sets whether this CollisionCheck should ignore quicksand collision.
    void IgnoreQuicksand(bool enabled)
    {
        mIsIgnoreQuicksand = enabled;
    }
    
private:
    // Returns `true` if collision with `bgCol` is possible for this check.
    bool canCollide(const BgCollision& bgCol) const;    

private:
    /* 0x00 */  bool mForceEdgeCheck;                           // If enabled, forces full edge-by-edge collision checking, even when the ray starts inside the shape.
    /* 0x01 */  bool mIsIgnoreQuicksand;                        // True if this CollisionCheck should ignore quicksand collision.
    /* 0x02 */  u8 _2;                                          // Unused?
    /* 0x03 */  u8 mLayer;                                      // The tile layer used when checking collision.
    /* 0x04 */  HitCheckType mHitCheckType;                     // The type of BgCollision to check against (Solid/NonSolid).
    /* 0x05 */
    /* 0x06 */
    /* 0x07 */
    /* 0x08 */  ActorBase* mOwnerPtr;                           // The actor that owns the check.
    /* 0x0C */  ActorBgHitCheckCallback* mHitCheckCallback;     // Callback used during hit checking.
    /* 0x10 */  IgnoreList mIgnoreList;                         // A ring buffer containing up to 10 `ActorBase` pointers to ignore when performing a hit check.
    /* 0x48 */  u32 _48;                                        // Unused?
};

size_assert(BasicBgCollisionCheck, 0x4C);
