#pragma once

#include "state/FStateMgr.h"

class LineFollower  // size: 0x90
{
public:
    LineFollower();

    void init(const Vec2f& initialPosition, f32 lineSpeed, u8 layer, u8 unk2, bool reverseDirecton=false);
    void initState(bool unk=false);

    inline void execute()
    {
        stateMgr.executeState();
    }


    FStateMgr<LineFollower> stateMgr;  // 0
    f32 _24;
    f32 _28;
    Vec2f _2C[6];
    Vec2f speed;                         // 5C
    Vec2f position;                      // 64
    Vec2f _6C;
    Vec2f _74;
    f32 _7C;
    f32 _80;
    u32 _84;
    f32 lineSpeed;                      // 88
    u8 _8C;
    u8 layer;                           // 8D
    u8 reversedDirection;               // 8E
    u8 _8F;
};
