#pragma once

#include "types.h"
#include "sead/seadListImpl.h"

namespace sead
{

// size: 0x18
class MemBlock
{
public:
    // static MemBlock* FindManageArea(void* ptr);

    static u32 getOffset() { return offsetof(MemBlock, mListNode); }

    u32 getSize() const { return mSize; }

protected:
    sead::ListNode mListNode;   // 0
    u32 mSize;                  // 10
    u32 mOffset;                // 14
};

} // namespace sead
