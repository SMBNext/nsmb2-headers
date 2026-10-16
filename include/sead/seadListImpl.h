#pragma once

#include "types.h"

namespace sead {

class ListNode         // size: 0x8
{
public:
    ListNode* mPrev;    // 0
    ListNode* mNext;    // 4
};

class ListImpl          // size: 0xC
{
public:
    ListNode mStartEnd; // 0
    s32 mCount;         // 8

    // Address: 0x0047AB24
    void pushFrontImpl(ListNode* node);     // Doesn't increment the count for some reason, maybe inlined

    inline void pushFront(ListNode* node)
    {
        pushFrontImpl(node);
        mCount++;
    }
};

}
