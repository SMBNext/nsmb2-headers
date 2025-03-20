#pragma once

#include "seadListImpl.h"

namespace sead {

template <typename T>
class OffsetList : public ListImpl  // size: 0x10
{
public:
    class iterator
    {
    public:
        iterator(T* ptr, s32 offset)
            : mPtr(ptr), mOffset(offset) { }

        bool operator==(const iterator& other) const
        {
            return mPtr == other.mPtr;
        }

        bool operator!=(const iterator& other) const
        {
            return !(*this == other);
        }

        iterator& operator++()
        {
            ListNode* node = reinterpret_cast<ListNode*>(reinterpret_cast<u8*>(mPtr) + mOffset)->mNext;
            mPtr = reinterpret_cast<T*>(reinterpret_cast<u8*>(node) - mOffset);
            return *this;
        }

        T& operator*() const
        {
            return *mPtr;
        }

        T* operator->() const
        {
            return mPtr;
        }

        T* mPtr;
        s32 mOffset;
    };

    iterator begin() const
    {
        return iterator(reinterpret_cast<T*>(reinterpret_cast<u8*>(mStartEnd.mNext) - mOffset), mOffset);
    }

    iterator end() const
    {
        return iterator(reinterpret_cast<T*>(reinterpret_cast<u8*>(const_cast<ListNode*>(&mStartEnd)) - mOffset), mOffset);
    }

    s32 mOffset;    // 0xC
};

}
