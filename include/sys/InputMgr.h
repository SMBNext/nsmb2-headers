#include "sead.h"

class InputMgr
{
    SEAD_SINGLETON_DISPOSER(InputMgr);

    struct Class270
    {
        f32 _0;
        f32 _4;
        f32 _8;
        f32 _C;
        f32 _10;
        f32 _14;
        f32 _18;
        f32 _1C;
        f32 _20;
        u8 _24[20];
    };

public:
    sead::ControllerBase controllers[2];
    Class270 _270[2];
    u32 _2E0;
    u32 _2E4;
    u32 _2E8;
    u32 _2EC;
    u32 replayMode;
    u8 _2F4;
    u32 rngSeeds[4];
    u32 _308;
    u32 _30C;
    u32 _310;
    u32 _314;
    u8 _318;
    bool isStockItemPressed;
    bool isBalloonPressed;
    s16 _31C;
    u8 _31E;
    u8 _31F;
    u32 _320;
    u8 _324;
    u32 _328;

    bool saveReplay(const sead::SafeString& path);
};

size_assert(InputMgr, 0x32C);
