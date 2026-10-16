#pragma once

#include "types.h"

// Size: 0x4
class ActorUniqueID
{
private:
    static const s32 cInvalidID = -1;

public:
    ActorUniqueID();

    ActorUniqueID(s32 id)
    {
        setValue(id);
    }

    inline void setValue(s32 id)
    {
        mValue = id;
    }

    inline s32 getValue() const
    {
        return mValue;
    }

    inline bool isValid() const
    {
        return mValue != cInvalidID;
    }

    inline void invalidate()
    {
        mValue = cInvalidID;
    }

    friend bool operator==(const ActorUniqueID& lhs, const ActorUniqueID& rhs)
    {
        return lhs.mValue == rhs.mValue;
    }

    friend bool operator!=(const ActorUniqueID& lhs, const ActorUniqueID& rhs)
    {
        return lhs.mValue != rhs.mValue;
    }

private:
    /* 0x0 */  s32 mValue;
};

size_assert(ActorUniqueID, 0x4);
