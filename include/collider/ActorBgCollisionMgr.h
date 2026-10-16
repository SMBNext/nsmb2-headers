#pragma once

#include "collider/ActorBgCollisionCheck.h"
#include "collider/BgCollision.h"
#include "collider/BgUnitCode.h"
#include "collider/TarzanBgCollisionCheck.h"
#include "sys/LineNodeMgr.h"
#include "types.h"

// Size: 0x40
class ActorBgCollisionMgr
{
SEAD_SINGLETON_DISPOSER(ActorBgCollisionMgr);
public:
    using CollisionList = LineNodeMgr<BgCollision>;

public:
    // Updates every active collision.
    // Calls `onFrameStart` on each of the `BgCollision` within `mActiveList`.
    void execute();
    
    // Performs a collision check against `mCandidateList` and returns the collision event that happened earliest.
    // Returns `true` if a collision was found.
    bool findBestCollision(ActorBgCollisionCheckResult& result, Direction direction, BgCollisionCategory collisionCategory, const ActorBgCollisionCheck& check);
    
    // Adds the given `collision` to `mActiveList`, `mSolidList`, `mNonSolidList` or `mCoinList`.
    // Does not add to `mCandidateList` or `mTarzanList`.
    void addToList(BgCollision& collision);

    // Unknown. Related to checking collision in `mTarzanList`.
    bool sub_2E4D60(ActorBgCollisionCheckResult& result, const BgCollision* collision, TarzanBgCollisionCheck* check, int a5);

    // Unknown. Related to checking collision in `mTarzanList`.
    BgCollision* sub_2E4E74(ActorBgCollisionCheckResult& result, const CollisionList& collisionList, const TarzanBgCollisionCheck* check);
    
    // Removes the given `collision` from `mActiveList`, `mSolidList`, `mNonSolidList` or `mCoinList`.
    // Does not remove from `mCandidateList` or `mTarzanList`.
    void removeFromList(BgCollision& collision);

    // Adds the given `collision` to `mTarzanList`.
    void addToListTarzan(BgCollision& collision);
    
    // Re-categorizes `collision` when it's `BgUnitCode` changes from `oldCode` to `newCode`.
    // Returns `true` if the category was changed.
    bool updateCategory(BgCollision& collision, const BgUnitCode& oldCode, const BgUnitCode& newCode);
    
    // Removes the given `collision` from `mCoinList`.
    void removeFromListCoin(BgCollision& collision);
    
    // Removes the given `collision` from `mTarzanList`.
    void removeFromListTarzan(BgCollision& collision);
    
    // Removes the given `collision` from `mSolidList`.
    void removeFromListSolid(BgCollision& collision);
    
    // Removes the given `collision` from `mNonSolidList`.
    void removeFromListNonSolid(BgCollision& collision);
    
    // Removes the given `collision` from `mCandidateList`.
    void removeFromListCandidate(BgCollision& collision);
    
    // Populates `mCandidateList` with potential collision candidates for `check`.
    void buildCandidateList(const ActorBgCollisionCheck& check);

    // Returns `true` if `mActiveList` contains the given `collision`.
    bool activeListContains(const BgCollision& collision) const;
    
    // Returns `true` if `mTarzanList` contains the given `collision`.
    bool tarzanListContains(const BgCollision& collision) const;
    
private:
    /* 0x10 */  CollisionList mActiveList;      // All active BgCollision objects.
    /* 0x18 */  CollisionList mSolidList;       // All solid BgCollision objects.
    /* 0x20 */  CollisionList mNonSolidList;    // All non-solid BgCollision objects.
    /* 0x28 */  CollisionList mCoinList;        // All coin BgCollision objects.
    /* 0x30 */  CollisionList mCandidateList;   // Current collision candidates - populated in `buildCandidateList()`.
    /* 0x38 */  CollisionList mTarzanList;      // All tarzan BgCollision objects - used by TarzanIvy.
};

size_assert(ActorBgCollisionMgr, 0x40);
