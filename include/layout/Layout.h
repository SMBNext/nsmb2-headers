#pragma once

#include "types.h"

namespace Lyt {

// Size: 0x4
class LayoutBase
{
public:    
    virtual void vf0();
};

size_assert(LayoutBase, 0x4);

// Size: 0x4
// Vtable: 0x005C17F0
class Layout : LayoutBase
{
public:
    // Address C1: 0x0038F580
    Layout();
    
    // Address D1: 0x0038F590;
    virtual ~Layout();
};

size_assert(Layout, 0x4);

} // namespace Lyt
