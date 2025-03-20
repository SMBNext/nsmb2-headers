#pragma once

#include "nw/types.h"

namespace nw { namespace ut {

inline IntPtr GetIntPtr(const void* ptr)
{
    return reinterpret_cast<IntPtr>(ptr);
}

inline PtrDiff GetOffsetFromPtr(const void* start, const void* end)
{
    return static_cast<PtrDiff>(GetIntPtr(end) - GetIntPtr(start));
}

} // namespace ut    
} // namespace nw
