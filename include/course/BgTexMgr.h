#pragma once

#include "sead.h"

#include "sead/gfx/seadTexture.h"

class BgTexMgr
{
    SEAD_SINGLETON_DISPOSER(BgTexMgr);
public:
    // createInstance()                             Address: 0x00401F90
    // deleteInstance()                             Address: 0x0040205C
    // sInstance                                    Address: 0x005E98B0
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x004022CC
    // SingletonDisposer_::sStaticDisposer          Address: 0x005E98B4
    // SingletonDisposer_::vtbl                     Address: 0x005CA168

    struct AnimEntry
    {
        u8 _0;
        u8 _1;
        u8 _2;
        u8 shouldBeCopied;
        u32 _4;
        u32 *_8;
        u32 _C;
        u32 _10;
        u32 _14;
        u32 frameMaybe;
    };
    size_assert(AnimEntry, 0x1C);

    void loadAnimatedTileById(const sead::SafeString& tilesetName, u32 id);            // 0x004021A0
    void setAnimatedTileData(u32 id, char _1, int _2, int _4, void* _8, int _C);       // 0x00401E98
    static u32 rainbowIndex();                                                         // 0x004ADB68

    BgTexMgr() = delete;    // Inlined
    ~BgTexMgr();            // 0x004032C0

    static u32 CoinRelated;
    static u32 BlueCoinRelated;
    static u32 RedCoinRelated;

    static s8 sAnimArg1[19];                            // 0x0057E5EC
    static u32 sAnimArg2[19];                           // 0x005E9910
    static void* sAnimArg3[19];                         // 0x005E995C
    static u32 sAnimArg4[19];                           // 0x0057E5A0
    static u32 sRainbowPalette[8];                      // 0x005E98F0

    static u16 sConveyorTileIds[120];                   // 0x00619C34  beltconveyor
    static u16 sFlowerTileIds[208];                     // 0x00619D24  FlowerA
    static u16 sSandTileIds[8];                         // 0x005E98E0  Sand
    static u16 sTorchTileIds[8];                        // 0x00619EC4  TorchA

    sead::TextureCtrGL mainTexture;                     // 010
    sead::TextureCtrGL _2C[14];                         // 02C
    AnimEntry animatedTiles[19];                        // 1B4
    u8 isTex8Loaded;                                    // 3C8
    u8 isTex0to7Loaded;                                 // 3C9
    u8 isTex9Loaded;                                    // 3CA
    u8 isTex11Loaded;                                   // 3CB
    sead::TextureCtrGL* tilesetTextures[4];             // 3CC
    void* mainTextureAddr;                              // 3DC
    void* mainTexturePhysicalAddr;                      // 3E0
    u8 _3E4[0x48C - 0x3E4];
    u32 animTileId0;                                    // 48C  From overlay3DId[BLOCK_QUESTION]
    u32 animTileId1;                                    // 490  From overlay3DId[BLOCK_BRICK]
    bool isRainbowCourse;                               // 494

};

// size_assert(BgTexMgr, 0x498);
