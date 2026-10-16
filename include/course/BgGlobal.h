#pragma once

#include "sead.h"
#include "sead/seadSafeString.h"

struct BgObject
{
    const u8* tileData;    // C00
    u8 _4[8];
    u16 _C;
    u16 _E;
    u16 tileId;           // C10
    u16 _12;
    u16 slotBits;         // C14  bits 12-13 are the tileset slot, 0xFFFF for none
    u16 _16;
    u16 _18;
    u16 _1A;
    u16 _1C;
};
size_assert(BgObject, 0x20);

class BgGlobal
{
    SEAD_SINGLETON_DISPOSER(BgGlobal);
public:
    sead::SafeString* getTilesetName(u8 area, u8 slot);   // Address: 0x004016B8
    void loadTilesetNames();                              // Address: 0x004016F4

    static u16 sStairSourceIds[6];                      // 0x00619B88  3 stair pieces x 2 halves
    static u16 sStairDestIds[24];                       // 0x00619B94  x 4 counter states
    static u16 sBounceTileIds[6];                       // 0x0057EB60
    static u16 sJumpblockTileId[1];                     // 0x0057EA4E
    static u16 sTileIdTable[129];                       // 0x00619ED4  entry 17 is the note block

    u8 _0[0x130];
    sead::FixedSafeString<32> mTilesetNames[4][4];
};
size_assert(BgGlobal, 0x400);
