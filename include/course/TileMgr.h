#pragma once

#include "sead.h"
#include "mapobj/BgActorLiquid.h"

class TileMgr : public sead::IDisposer
{
public:
    static TileMgr* instance;

    u8 _unk10[0x18-0x10];       // 10
    f32 liquidLevel;            // 18
    u8 _unk1C[0x160-0x1C];      // 1C
    u8 liquidType;              // 160
    u8 _unk161[0x10B4-0x161];   // 161

    LiquidTop* waveLiquidTop;   // 10B4 Custom

    void setTileType(u16 x, u16 y, u32 tileIdx);

    void initWaveLiquidTop();
    f32 getWaveLiquidLevel(f32 x) const;
};
