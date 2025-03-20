#pragma once

#include "sead.h"


class QuakeMgr : public sead::IDisposer
{
public:
    enum Flags : u32
    {
        FLAG_HOP_ENEMIES    = 0x1,
        FLAG_STUN_ENEMIES   = 0x2,
        FLAG_HOP_PLAYER     = 0x10,
        FLAG_STUN_PLAYER    = 0x20,
    };

    void quake(u32 patternIdx, bool doShake = true, u32 flags = 0);

    void UnkQuake(char a2, u32 patternIdx, bool doShake = true, u32 flags = 0);
    void UnkQuake2(char a2, u32 patternIdx, u32 flags = 0);
    void UnkQuake3(u32 patternIdx, bool doShake = true);

    void stopQuake();

    u32 _10;                            // 10
    f32 currentPatternConstants[2][5];  // 14
    u32 _3C;                            // 3C
    u8 _40;                             // 40
    u8 _41;                             // 41
    u8 _42;                             // 42
    u32 _44;                            // 44
    u32 _48;                            // 48
    Vec2f cameraShift;                   // 4C
    u32 _54;                            // 54 

    static QuakeMgr* instance;
};