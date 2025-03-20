#pragma once


// Clean this mess up eventually...

#include "math/Calc.h"
#include "math/Mtx34.h"
#include "math/Vec.h"

struct Color8
{
    Color8(u8 r = 0, u8 g = 0, u8 b = 0, u8 a = 0xFF) :
        r(r), g(g), b(b), a(a) { }

    u8 r;
    u8 g;
    u8 b;
    u8 a;

    u16 rgb565()
    {
        return ((r & 0b11111000) << 8) | ((g & 0b11111100) << 3) | (b >> 3);
    }
};

struct ColorF32
{
    f32 r;
    f32 g;
    f32 b;
    f32 a;
};

// Misc

void playSfx(u32 id, const Vec3f& pos, u32 unk = 1);
void playSfx(const char* name, const Vec3f& pos, u32 unk = 1);
void playSfxWhileCalled(u32 id, u32 unk, const Vec3f& pos);   // unk always set to actor id

void spawnEffect(u32 id, const Vec3f& pos, Vec3i* rotation = nullptr, Vec3f* scale = nullptr);

bool smoothRotation(s32& rotation, const s32& destination, const s32& amount);
bool moveTowards(Vec3f& position, const Vec3f& destination, f32 speed);
