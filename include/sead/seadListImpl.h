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
};

}
