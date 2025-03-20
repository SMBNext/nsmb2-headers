#include "sead.h"

namespace sead {

u32 ExpHeap::getSize() const
{
    return mSize;
}

u32 ExpHeap::getFreeSize() const
{
    u32 freeSize = 0;
    for (MemBlockList::iterator it = mFreeList.begin(); it != mFreeList.end(); ++it)
        freeSize += it->getSize();
    return freeSize;
}

}
