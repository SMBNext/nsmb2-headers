#include "sead.h"

namespace sead {

mw_symptr(0x005D2F98)
u32 ExpHeap::getSize() const
{
    return mSize;
}

mw_symptr(0x005D2F9C)
u32 ExpHeap::getFreeSize() const
{
    u32 freeSize = 0;
    for (MemBlockList::iterator it = mFreeList.begin(); it != mFreeList.end(); ++it)
        freeSize += it->getSize();
    return freeSize;
}

}
