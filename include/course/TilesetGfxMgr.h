#pragma once

#include "gfx/Texture.h"


class TilesetGfxMgr : public sead::IDisposer
{
public:
    static TilesetGfxMgr* instance;

    struct AnimatedTileEntry
    {
        u8 _0;
        u8 _1;
        u8 _2;
        bool shouldBeCopied;
        u32 _4;
        void* _8;
        u32 _C;
        u32 _10;
        u32 _14;
        u32 _18;
    };

    CtpkTexture mainTexture;
    CtpkTexture _2C[14];
    AnimatedTileEntry animatedTiles[19];
    bool isTex8Loaded;
    bool isTex0to7Loaded;
    bool isTex9Loaded;
    bool isTex11Loaded;
    CtpkTexture* tilesetTextures[4];
    void* mainTextureAddr;
    void* mainTexturePhysicalAddr;
    u8 _3E4[0x494-0x3E4];
    bool isRainbowCourse;
};
