#pragma once

#include "types.h"

class UnkCollisionClass  // size: 0x38
{
public:
    UnkCollisionClass();
    void reset();
    void copy(UnkCollisionClass* other);

    u8 _0;          // Inited to 0
    u8 _1;          // Inited to 0
    u8 _2;          // Inited to 0
    u8 _3;          // Inited to 0
    s32 _4;         // Inited to -1
    u32 _8;         // Inited to 0
    f32 _C;         // Inited to 0.0f
    f32 _10;        // Inited to 0.0f
    f32 _14;        // Inited to 0.0f
    f32 _18;        // Inited to 0.0f
    u32 _1C;        // Inited to 0
    u32 _20;        // Inited to 0
    u32 _24;        // Inited to 0
    f32 _28;        // Inited to 0.0f
    u32 _2C;        // Inited to 0
    u8 _30;         // Inited to 0
    u32 _unk34;     // Most likely part of this class
};
