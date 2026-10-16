#pragma once


// Clean this mess up eventually...

#include "stdlib.h"
#include "string.h"
#include "actors/ActorUniqueID.h"
#include "math/Calc.h"
#include "math/Mtx34.h"
#include "math/RNG.h"
#include "math/Vec.h"
#include "nw/snd/SoundHandle.h"
#include "sead/seadSafeString.h"

static constexpr f32 _3DL_MODEL_SCALE = 0.15808211f;

struct Color8
{
    Color8(u8 r = 0, u8 g = 0, u8 b = 0, u8 a = 0xFF) :
        r(r), g(g), b(b), a(a) { }

    u8 r;
    u8 g;
    u8 b;
    u8 a;

    Color8 operator+(const Color8& rhs) const
    {
        return Color8(
            Mathu::clamp2(0, this->r + rhs.r, 255),
            Mathu::clamp2(0, this->g + rhs.g, 255),
            Mathu::clamp2(0, this->b + rhs.b, 255),
            Mathu::clamp2(0, this->a + rhs.a, 255)
        );
    }

    Color8 operator-(const Color8& rhs) const
    {
        return Color8(
            Mathu::clamp2(0, this->r - rhs.r, 255),
            Mathu::clamp2(0, this->g - rhs.g, 255),
            Mathu::clamp2(0, this->b - rhs.b, 255),
            Mathu::clamp2(0, this->a - rhs.a, 255)
        );
    }

    Color8& operator+=(const Color8& rhs)
    {
        return *this = *this + rhs;
    }

    Color8& operator-=(const Color8& rhs)
    {
        return *this = *this - rhs;
    }

    u16 rgb565()
    {
        return ((r & 0b11111000) << 8) | ((g & 0b11111100) << 3) | (b >> 3);
    }
};

// Misc

void playSfx(u32 id, const Vec3f& pos, bool stopSound = true);
void playSfx(u32 id, const Vec2f& pos, bool stopSound = true);
void playSfx(const char* name, const Vec3f& pos, bool stopSound = true);
void playSfxWhileCalled(u32 id, ActorUniqueID actorId, const Vec3f& pos);
void playSfxWhileCalled(u32 id, ActorUniqueID actorId, const Vec2f& pos);
void playSfxWhileCalled(u32 id, ActorUniqueID actorId, const Vec2f& pos, s16 arg);
void playSfxWhileCalled(const char* name, ActorUniqueID actorId, const Vec3f& pos, s16 arg);
void playSfxPositional(u32 id, const Vec2f& pos, bool stopSound = true);
void playSfxPositionalWhileCalled(u32 id, ActorUniqueID actorId, const Vec2f& pos);
void stopSfx(u32 id, s32 fadeFrames);
void setSfxArg(nw::snd::SoundHandle* handle, u32 id, s32 varNo, s16 arg);

void spawnEffect(u32 id, const Vec3f& pos, Vec3i* rotation = nullptr, Vec3f* scale = nullptr);

bool smoothRotation(s32& rotation, const s32& destination, const s32& amount);
bool moveTowards(Vec3f& position, const Vec3f& destination, f32 speed);

bool sdmcFileInc();
void sdmcFileDec();
bool fileExists(const char* path);

enum class Screen : u32
{
    cTop    = 0,
    cBottom = 1,
};

