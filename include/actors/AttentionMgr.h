#pragma once

#include "actors/AttentionLook.h"
#include "sead/seadOffsetList.h"
#include "types.h"
#include "utility/Direction.h"

class ActorBase;

// Size: 0x24
class AttentionMgr
{
    SEAD_SINGLETON_DISPOSER(AttentionMgr);
public:
    virtual ~AttentionMgr();

    // Appends an `AttentionLook` to the list.
    void addToList(AttentionLook* target);

    // Removes an `AttentionLook` to the list.
    void removeFromList(AttentionLook* target);

    // Returns the first `AttentionLook` in range of the provided `position` that is not owned by `excludedActor`.
    AttentionLook* findTargetInRange(ActorBase* excludedActor, const Vec2f& position);

    // Returns the first `AttentionLook` in range of `position` that is not owned by
    // `excludedActor` and is located in the specified horizontal `direction`.
    AttentionLook* findTargetInRange(ActorBase* excludedActor, const Vec2f& position, Direction direction);

private:
    /* 0x10 */  sead::OffsetList<AttentionLook> mList;
};

size_assert(AttentionMgr, 0x24);
