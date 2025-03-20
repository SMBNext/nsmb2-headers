#pragma once

#include "types.h"

namespace nn { namespace hid {

enum Button
{
    BUTTON_A                    = 0x00000001,
    BUTTON_B                    = 0x00000002,
    PSEUDO_BUTTON_SELECT        = 0x00000004,
    BUTTON_SELECT_FOR_DEBUGGING = 0x00000004,
    BUTTON_START                = 0x00000008,
    BUTTON_RIGHT                = 0x00000010,
    BUTTON_LEFT                 = 0x00000020,
    BUTTON_UP                   = 0x00000040,
    BUTTON_DOWN                 = 0x00000080,
    BUTTON_R                    = 0x00000100,
    BUTTON_L                    = 0x00000200,
    BUTTON_X                    = 0x00000400,
    BUTTON_Y                    = 0x00000800,
    BUTTON_DEBUG                = 0x00001000,
    BUTTON_RESERVED             = 0x00002000,
    BUTTON_EMULATION_RIGHT      = 0x10000000,
    BUTTON_EMULATION_LEFT       = 0x20000000,
    BUTTON_EMULATION_UP         = 0x40000000,
    BUTTON_EMULATION_DOWN       = 0x80000000,

    BUTTON_MASK                = BUTTON_A | BUTTON_B | BUTTON_START | BUTTON_R | BUTTON_L | BUTTON_X | BUTTON_Y | BUTTON_DEBUG,
    PLUS_BUTTON_MASK           = BUTTON_RIGHT | BUTTON_LEFT | BUTTON_UP | BUTTON_DOWN,
    PLUS_BUTTON_EMULATION_MASK = BUTTON_EMULATION_RIGHT | BUTTON_EMULATION_LEFT | BUTTON_EMULATION_UP | BUTTON_EMULATION_DOWN,
    ALL_MASK                   = BUTTON_MASK | PLUS_BUTTON_MASK | PLUS_BUTTON_EMULATION_MASK,

    BUTTON_ZL = 0x00004000,
    BUTTON_ZR = 0x00008000,

    BUTTON_EMULATION_R_RIGHT = 0x01000000,
    BUTTON_EMULATION_R_LEFT  = 0x02000000,
    BUTTON_EMULATION_R_UP    = 0x04000000,
    BUTTON_EMULATION_R_DOWN  = 0x08000000,

    PLUS_BUTTON_EMULATION_R_MASK = BUTTON_EMULATION_R_RIGHT | BUTTON_EMULATION_R_LEFT | BUTTON_EMULATION_R_UP | BUTTON_EMULATION_R_DOWN,
};

struct StickStatus
{
    s16 x;
    s16 y;
};

struct PadStatus
{
    u32 pressed;
    u32 down;
    u32 up;
    StickStatus stick;
};

struct Pad;
Pad& getPad();

class PadReader     // Size: 0x40
{
public:
    PadReader(Pad& pad = getPad());

    void Read(PadStatus* statusBuffer, s32* readLen, s32 bufferLen);
    bool ReadLatest(PadStatus* status);

private:
    u8 _unk[0x40];
};

} }
