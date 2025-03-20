#pragma once

#include "types.h"


class PlayerInput   // size: 0x98
{
public:
    enum Button
    {
        BUTTON_JUMP     = 0x1,      // A/B or A/X
        BUTTON_RUN      = 0x2,      // X/Y or B/Y
        BUTTON_ACTION   = 0x4,      // L/R
        BUTTON_UP       = 0x8,      // Up
        BUTTON_DOWN     = 0x10,     // Down
        BUTTON_LEFT     = 0x20,     // Left
        BUTTON_RIGHT    = 0x40      // Right
    };

public:
    PlayerInput();              // 0044DA40

    void execute();             // 0044D840

    bool isJumpHeld();
    bool isJumpPressed();
    bool isRunHeld();
    bool isRunPressed();
    bool getDirectionHeld(u8* directionOut);    // Returns whether any direction is held

    u32 _0;                     // 0    Inited to 0    
    u32 _4;                     // 4    Inited to 0
    u32 buttonsHeld;            // 8    Inited to 0
    u32 buttonsPressed;         // C    Inited to 0
    u32 buttonsHeldLast;        // 10   Inited to 0
    u32 buttonsPressedLast;     // 14   Inited to 0
    u32 _18;                    // 18   Inited to 0
    u32 _1C;                    // 1C   Inited to 0
    u32 _20;                    // 20   Inited to 0
    u32 _24;                    // 24   Inited to 0
    u32 _28[10];                // 28   Inited to 0
    u32 _50;                    // 50   Inited to 0
    u32 _54;                    // 54   Inited to 0
    u32 _58;                    // 58   Inited to 0
    u32 _5C;                    // 5C   Inited to 0
    u32 _60[10];                // 60   Inited to 0
    u32 _88;                    // 88   Inited to 0
    u32 _8C;                    // 8C   Inited to 0
    u8 _90;                     // 90   Inited to 0
    u8 _91;                     // 91   Inited to 0
    u8 _92;                     // 92   Inited to 0
    u32 _94;                    // 94   Inited to 0
};
