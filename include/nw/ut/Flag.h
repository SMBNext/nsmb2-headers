#pragma once

#include "nw/types.h"

namespace nw { namespace ut {


template<typename Flags, typename Mask>
inline bool CheckFlag(const Flags& flags, const Mask& mask)
{
    return (flags & static_cast<Flags>(mask)) == static_cast<Flags>(mask);
}

template<typename Flags, typename Value>
inline Flags EnableFlag(const Flags& flags, const Value& value)
{
    return flags | static_cast<Flags>(value);
}

template<typename Flags, typename Value>
inline Flags DisableFlag(const Flags& flags, const Value& value)
{
    return flags & ~(static_cast<Flags>(value));
}

} // namespace ut
} // namespace nw
