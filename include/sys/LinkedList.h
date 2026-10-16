#pragma once

#include "types.h"

// This is likely part of some unknown library due to it's ordering

// Size: 0xC
// Vtable: 0x005D35FC
class ListNode
{
public:
    // Address C1: 0x0010E8E4
    ListNode();

    // Deleted
    virtual ~ListNode();

    inline ListNode* prev() const { return mPrev; }
    inline ListNode* next() const { return mNext; }

private:
    ListNode* mPrev;    // 0x0
    ListNode* mNext;    // 0x4
};

size_assert(ListNode, 0xC);

// Size: 0xC
// Vtable: 0x005D35EC
class IntrusiveList
{
public:
    // Address C1: 0x0010E8C8
    IntrusiveList();

    // Address D1: 0x0047EF70
    virtual ~IntrusiveList();

    // Address: 0x0010E85C
    void clear();
    
    // Address: 0x0010E88C
    void remove(ListNode* node);

    // Address: 0x0047EEDC
    bool contains(ListNode* node);

    // Address: 0x0047EF2C
    void append(ListNode* node);

    inline ListNode* head() const { return mHead; }
    inline ListNode* tail() const { return mTail; }
    
private:
    ListNode* mHead;
    ListNode* mTail;
};

size_assert(IntrusiveList, 0xC);
