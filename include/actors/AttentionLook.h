#pragma once

#include "actors/ActorUniqueID.h"
#include "math/Vec.h"
#include "sead/heap/seadDisposer.h"
#include "sead/seadListImpl.h"

// Size: 0x2C
class AttentionLook
{
    SEAD_SINGLETON_DISPOSER(AttentionLook);
public:
    enum class RangeType : u8
    {
        cTiles5     = 0,    // 80.0f
        cTiles15    = 1,    // 240.0f
        cTiles32    = 2,    // 512.0f
        cTiles5_2   = 3,    // 80.0f  - Unsure why there's two at 80.0f
    };

public:
    AttentionLook(ActorUniqueID id);
    ~AttentionLook();

    const ActorUniqueID& getOwnerID() const
    {
        return mOwnerID;
    }

    void setPosition(const Vec2f& position)
    {
        mPosition = position;
    }

    Vec2f& getPosition()
    {
        return mPosition;
    }

    const Vec2f& getPosition() const
    {
        return mPosition;
    }

    void setMaxRange(RangeType range)
    {
        mMaxRange = range;
    }

    RangeType getMaxRange() const
    {
        return mMaxRange;
    }

private:
    /* 0x10 */  ActorUniqueID mOwnerID;     //
    /* 0x14 */  Vec2f mPosition;            //
    /* 0x1C */  u8 _1C;                     //
    /* 0x1D */  RangeType mMaxRange;        //
    /* 0x1E */ 
    /* 0x1F */
    /* 0x20 */  u32 _20;                    //
    /* 0x14 */  sead::ListNode mListNode;   //
};

size_assert(AttentionLook, 0x2C);
