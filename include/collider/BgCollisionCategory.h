#pragma once

#include "types.h"

enum class BgCollisionCategory : u8
{
    cUnknown0   = 0,    //
    cUnknown1   = 1,    //

    cNum
};

static constexpr u32 cBgCollisionCategoryCount = static_cast<u32>(BgCollisionCategory::cNum);
