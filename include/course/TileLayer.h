#pragma once

#include "types.h"

class TileLayer
{
public:
    static TileLayer* Layer1;

    u16* getTilePtr(u32 x, u32 y, u32* unkOut = nullptr);
};
