#pragma once

#include "types.h"

namespace nw { namespace os {

class IAllocator
{

public:
    virtual ~IAllocator();
    virtual void* Alloc(size_t size, u8 alignment) = 0;
    virtual void  Free(void* memory) = 0;

    void* Alloc(size_t size) { return this->Alloc( size, 4 ); }

};

} // namespace os
} // namespace nw


