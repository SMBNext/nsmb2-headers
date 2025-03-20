#pragma once

#include "types.h"

namespace nw { namespace ut {

struct BinaryRevisionHeader
{
    s32 signature;
    u32 revision;
};

struct BinaryBlockHeader
{
    u32 kind;
    u32 size;
};

struct BinaryFileHeader
{
    s32 signature;
    u16 byteOrder;
    u16 headerSize;
    u32 version;
    u32 fileSize;
    u16 dataBlocks;
    u16 reserved;
};


} // namespace ut    
} // namespace nw
