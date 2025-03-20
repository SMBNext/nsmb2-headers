#pragma once

#include "types.h"

class RNG
{
public:
    static RNG* instance;

    f32 randF32();
    f32 randF32(f32 max);
    f32 randF32(f32 min, f32 max);
    u32 randU32();
    u32 randU32(u32 max);
    u32 randS32(s32 min, s32 max);
    bool randBool();
};

// Convenience
inline f32 randF32() { return RNG::instance->randF32(); }
inline f32 randF32(f32 max) { return RNG::instance->randF32(max); }
inline f32 randF32(f32 min, f32 max) { return RNG::instance->randF32(min, max); }
inline u32 randU32() { return RNG::instance->randU32(); }
inline u32 randU32(u32 max) { return RNG::instance->randU32(max); }
inline s32 randS32(s32 min, s32 max) { return RNG::instance->randS32(min, max); }
inline bool randBool() { return RNG::instance->randBool(); }
