#pragma once

#include "state/FStateMgr.h"

class LineFollower  // size: 0x90
{
public:
    enum LineType : u8
    {
        LINE_UP_45 = 0x0,
        LINE_DOWN_45 = 0x1,
        LINE_CORNER_TL = 0x2,
        LINE_CORNER_BR = 0x3,
        LINE_STRAIGHT_H = 0x4,
        LINE_STRAIGHT_V = 0x5,
        LINE_UNKNOWN_6 = 0x6,
        LINE_UP_26_R = 0x7,
        LINE_UP_26_L = 0x8,
        LINE_DOWN_26_R = 0x9,
        LINE_DOWN_26_L = 0xA,
        LINE_UP_63_B = 0xB,
        LINE_UP_63_T = 0xC,
        LINE_DOWN_63_B = 0xD,
        LINE_DOWN_63_T = 0xE,
        LINE_CIRCLE_1 = 0xF,
        LINE_CIRCLE_2_TR = 0x10,
        LINE_CIRCLE_2_TL = 0x11,
        LINE_CIRCLE_2_BR = 0x12,
        LINE_CIRCLE_2_BL = 0x13,
        LINE_CIRCLE_4_TL = 0x14,
        LINE_CIRCLE_4_TML = 0x15,
        LINE_CIRCLE_4_TMR = 0x16,
        LINE_CIRCLE_4_TR = 0x17,
        LINE_CIRCLE_4_LMT = 0x18,
        LINE_CIRCLE_4_RMT = 0x19,
        LINE_CIRCLE_4_LMB = 0x1A,
        LINE_CIRCLE_4_RMB = 0x1B,
        LINE_CIRCLE_4_BL = 0x1C,
        LINE_CIRCLE_4_BML = 0x1D,
        LINE_CIRCLE_4_BMR = 0x1E,
        LINE_CIRCLE_4_BR = 0x1F,
        LINE_END = 0x20,
        LINE_UNKNOWN_21 = 0x21,
    };

    LineFollower();

    void init(const Vec2f& initialPosition, f32 lineSpeed, u8 layer, u8 unk2, bool reverseDirecton=false);
    void initState(bool unk=false);
    static u8 getLineType(f32 tileX, f32 tileY);

    inline void execute()
    {
        stateMgr.executeState();
    }

    inline bool isOnLine()
    {
        return (stateMgr.getStateID()->number() != 2);
    }

    FStateMgr<LineFollower> stateMgr;  // 0
    sead::Vector2f _24;
    sead::Vector2f _2C;
    sead::Vector2f _30;
    sead::Vector2f _34;
    sead::Vector2f _38;
    sead::Vector2f _3C;
    sead::Vector2f _40;
    Vec2f speed;                         // 5C
    Vec2f position;                      // 64
    Vec2f position2;                     // initial pos maybe?
    Vec2f tilePosition;
    f32 _7C;
    f32 _80;
    u32 _84;
    f32 lineSpeed;                       // 88
    u8 _8C;
    u8 layer;                             // 8D
    u8 reversedDirection;               // 8E
    u8 _8F;
};

size_assert(LineFollower, 0x90);