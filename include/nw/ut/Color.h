#pragma once

#include "nw/ut/ResTypes.h"

namespace nw {
namespace ut {

template <typename T>
inline T Clamp(T x, T min, T max) { return (x > max) ? max : ((x < min) ? min : x); }

struct Color8
{
public:
    Color8() { this->SetU32(0xFFFFFFFF); }
    Color8(u32 color) { this->SetU32(color); }
    Color8(s32 red, s32 green, s32 blue, s32 alpha) :
        r(static_cast<u8>(red)),
        g(static_cast<u8>(green)),
        b(static_cast<u8>(blue)),
        a(static_cast<u8>(alpha)) {}

    ~Color8() {}
    
    operator u32() const { return ToU32(); }

    void Set(s32 red, s32 green, s32 blue, s32 alpha = 255)
    {
        r = static_cast<u8>(red);
        g = static_cast<u8>(green);
        b = static_cast<u8>(blue);
        a = static_cast<u8>(alpha);
    }

    u32 ToU32() const { return this->ToU32RawRef(); }
    void SetU32(u32 value) { this->ToU32RawRef() = value; }

protected:
    u32& ToU32RawRef() { return *reinterpret_cast<u32*>(this); }
    const u32& ToU32RawRef() const { return *reinterpret_cast<const u32*>(this); }
    u32 ToU32Raw() const { return *reinterpret_cast<const u32*>(this); }

public:
    u8 r;
    u8 g;
    u8 b;
    u8 a;
};

struct FloatColor
{
public:
    FloatColor() : r(0.0f), g(0.0f), b(0.0f), a(1.0f) {}

    FloatColor(f32 red, f32 green, f32 blue, f32 alpha) : r(red), g(green), b(blue), a(alpha) {}

    ~FloatColor() {}

    operator Color8() const
    {
        return Color8(static_cast<u8>( 0.5f + Clamp(r, 0.0f, 1.0f) * 255.f ),
                      static_cast<u8>( 0.5f + Clamp(g, 0.0f, 1.0f) * 255.f ),
                      static_cast<u8>( 0.5f + Clamp(b, 0.0f, 1.0f) * 255.f ),
                      static_cast<u8>( 0.5f + Clamp(a, 0.0f, 1.0f) * 255.f ));
    }

    void Set(f32 red, f32 green, f32 blue, f32 alpha = 1 )
    {
        r = red;
        g = green;
        b = blue;
        a = alpha;
    }

    void SetColor(f32 red, f32 green, f32 blue)
    {
        this->Set(red, green, blue, a);
    }

    void SetAlpha(f32 alpha)
    {
        this->Set(r, g, b, alpha);
    }

    void Set(s32 red, s32 green, s32 blue, s32 alpha = 255 )
    {
        r = static_cast<f32>( red ) / 255.f;
        g = static_cast<f32>( green ) / 255.f;
        b = static_cast<f32>( blue ) / 255.f;
        a = static_cast<f32>( alpha ) / 255.f;
    }

    void SetColor(s32 red, s32 green, s32 blue)
    {
        f32 fr = static_cast<f32>( red ) / 255.f;
        f32 fg = static_cast<f32>( green ) / 255.f;
        f32 fb = static_cast<f32>( blue ) / 255.f;

        this->Set(fr, fg, fb, a);
    }

    void SetAlpha(s32 alpha)
    {
        f32 fa = static_cast<f32>(alpha) / 255.f;
        this->Set(r, g, b, fa);
    }

    void Set(const FloatColor& color) { operator=(color); }

    // 0048A308
    u32 ToPicaU32() const;

public:
    f32 r;
    f32 g;
    f32 b;
    f32 a;
};

} // namespace ut
} // namespace nw
