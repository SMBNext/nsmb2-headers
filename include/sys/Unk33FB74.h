#pragma once

#include "types.h"

// Size: 0x14
class Unk33FB74
{
public:
    Unk33FB74();
    ~Unk33FB74();

public:
    /* 0x00 */  void* random;   // sead::Random*
    /* 0x04 */  u32 x;          //
    /* 0x08 */  u32 y;          //
    /* 0x0C */  u32 z;          //
    /* 0x10 */  u32 w;          //
};

size_assert(Unk33FB74, 0x14);
