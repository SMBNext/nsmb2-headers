#pragma once

#include "types.h"

namespace sead {

// Size: 0xC
class Arena
{
public:
    // C1 Address: 0x0047788C
    Arena();

    // D1 Address: 0x004778A0
    ~Arena();

    // Address: 0x001193B4
    u8* initialize(size_t size);

    u8* getStartAddr() { return mStart; }
    size_t getSize() const { return mSize; }
    bool isInclude(void* ptr) const { return mStart <= ptr && ptr < mStart + mSize; }

protected:
    u8* mStart;
    size_t mSize;
    bool mInitWithStartAddress;
};

size_assert(Arena, 0xC);

} // namespace sead
