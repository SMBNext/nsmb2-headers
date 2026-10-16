#pragma once

#include "types.h"
#include "utility/BitFlag.h"
#include "utility/Direction.h"


class PlayerKeyStatus : public BitFlag<32>
{
public:
    enum Bit
    {
        cNoInput                = 0x0,
        cDisableLR              = 0x1,
        cDisableUD              = 0x2,
        cForceJump              = 0x3,
        cForceNoJump            = 0x4,
        cDemo                   = 0x5,
    };
};

size_assert(PlayerKeyStatus, 0x4);

class PlayerKey   // size: 0x98
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
    PlayerKey();              // 0044DA40

    void execute();             // 0044D840
    void setDemoButton(char button);    // 0044D75C
    void onStatus(int status);          // 0044D970
    void offStatus(char status);        // 0044DA2C

    bool isHeldJump();
    bool isPressedJump();
    bool isHeldRun();
    bool isPressedRun();
    bool isPressedShoot();

    bool isHeldDown();
    bool isHeldLeft();
    bool isHeldRight();
    bool isHeldUp();
    bool isHeldUpExclusive();

    bool isPressedDown();
    bool isPressedLeft();
    bool isPressedRight();
    bool isPressedUp();
    bool isPressedBalloon();            // 0x004AFAB4
    bool isPressedStockItem();          // 0x004AFBC0
    bool isStatus(char flag);           // 0x004AFBE0

    bool getDirectionHeld(Direction* directionOut);    // Returns whether any direction is held

    bool buttonJump();          // 0x004AF948

    void sub_44D820();          // 0x0044D820
    bool sub_4AFAC4(int frames);        // 0x004AFAC4  Run was pressed within the last frames
    bool sub_4AFB44(int frames);        // 0x004AFB44  Jump was pressed within the last frames

    /* 0x00 */  u32 _0;
    /* 0x04 */  PlayerKeyStatus status;
    /* 0x08 */  u32 buttonsHeld;
    /* 0x0C */  u32 buttonsPressed;
    /* 0x10 */  u32 buttonsHeldLast;
    /* 0x14 */  u32 buttonsPressedLast;
    /* 0x18 */  u32 _18;
    /* 0x1C */  u32 _1C;
    /* 0x20 */  u32 _20;
    /* 0x24 */  u32 _24;
    /* 0x28 */  u32 _28[10];
    /* 0x50 */  u32 _50;
    /* 0x54 */  u32 _54;
    /* 0x58 */  u32 _58;
    /* 0x5C */  u32 _5C;
    /* 0x60 */  u32 _60[10];
    /* 0x88 */  u32 demoButtonsPressed;
    /* 0x8C */  u32 demoButtonsHeld;
    /* 0x90 */  u8 hipAttackRead;
    /* 0x91 */  u8 _91;
    /* 0x92 */  u8 hipAttackHoldStart;
    /* 0x94 */  u32 hipAttackHoldCount;
};

size_assert(PlayerKey, 0x98);
