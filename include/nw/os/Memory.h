#pragma once

#include "types.h"

namespace nw {
namespace os {

// Size: 0x4
class IAllocator
{
public:
    virtual ~IAllocator();

    virtual void* Alloc(size_t size, u8 alignment) = 0;
    virtual void Free(void* memory) = 0;

    void* Alloc(size_t size) { return this->Alloc(size, 4); }
};

size_assert(IAllocator, 0x4);


// Size: 0xC
class MemorySizeCalculator
{
public:
    /* 0x0 */  size_t size;             //
    /* 0x4 */  size_t alignment;        //
    /* 0x8 */  size_t maxAlignment;     //
};

size_assert(MemorySizeCalculator, 0xC);

} // namespace os
} // namespace nw
