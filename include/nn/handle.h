#pragma once

#include "types.h"


namespace nn {

struct Handle
{
    enum SpecialHandle : u32 {
        CURRENT_THREAD  = 0xFFFF8000,
        CURRENT_PROCESS = 0xFFFF8001,
    };

    Handle() : handle(0) {}
    Handle(SpecialHandle h) : handle(static_cast<u32>(h)) {}

    inline bool IsValid() const { return handle != 0; }

    u32 handle;
};

}
