#pragma once

#include "sead.h"

#include "nn/gr/gr_Vertex.h"
#include "sead/seadVector.h"

// size: 0xCA314
class BgRenderer
{
    /* 0x00 */  void* vtable;
    SEAD_SINGLETON_DISPOSER(BgRenderer);
public:
    struct TileVertex
    {
        /* 0x00 */  f32 x;          // Screen x
        /* 0x04 */  f32 y;          // Screen y
        /* 0x08 */  f32 z;          // Render depth plane (Position.z in shader) - depth test/occlusion; per layer, baked by init
        /* 0x0C */  f32 parallax;   // Stereo parallax factor (Position.w in shader) - per-eye x-offset only; per tile, set by drawTileLayer
        /* 0x10 */  f32 u;          // Texture u
        /* 0x14 */  f32 v;          // Texture v
    };
    size_assert(TileVertex, 0x18);

    static constexpr u32 cMaxTilesPerLayer = 1000;    // Quads per layer before the buffers fill
    static constexpr u32 cNumLayers = 4;              // Background layers (0..3); 3 is the 3D/overlay layer
    static constexpr u32 cNumBufferSlots = 2;         // Tile vertices are double-buffered per layer
    static constexpr u32 cTilesetTileCount = 2048;    // Size of the per-tile lookup arrays

    static u32 paddedTileSize;              // Address: 0x005E9880  Tile size incl. padding, in texture pixels
    static u32 tileSize;                    // Address: 0x005E9884  Tile size, in pixels
    static u32 tilesPerRow;                 // Address: 0x005E9888  Tiles across a texture sheet
    static u32 tilesPerCol;                 // Address: 0x005E988C  Tiles down a texture sheet
    static sead::Vector2f tileSizeUv;       // Address: 0x005E9890  Tile size in UV units
    static f32 xScale;                      // Address: 0x005E9898
    static f32 yScale;                      // Address: 0x005E989C

public:
    void init();                            // Address: 0x001CA86C
    void init3DInfo();                      // Address: 0x001CA738

    void draw();                                                        // Address: 0x001CA6A8
    void drawTileLayer(sead::BoundBox2f* viewRect, int layerId);        // Address: 0x001C9368

    // Records one tile quad (and its 3D overlay quad, if any) into the tile scratch.
    void addTileQuad(u32 layerId, u16 tileId, sead::Vector3f* position, sead::Vector3f* position2, sead::Vector3f* position3, sead::Vector3f* position4);   // Address: 0x001CA30C

    void submitLayer0DrawCmd();             // Address: 0x001C9358
    void submitLayer1DrawCmd();             // Address: 0x001C9360
    void submitLayer2DrawCmd();             // Address: 0x001C9848
    void submitLayer3DrawCmd();             // Address: 0x001CA650

    // Emits one layer's recorded quads into the render command list and consumes its tile count.
    void submitLayerDrawCmd(s32 layerId);   // Address: 0x001C9850

    // Emits the shared bg shader/setup commands (incl. the texture binds).
    void submitBgSetupCommands();           // Address: 0x001CA7EC

    // Clears every layer's tile count & draw flag and toggles the double buffer.
    void resetTexturePtrs();                // Address: 0x001C995C

    /* 0x00014 */ TileVertex tileVertices[cNumBufferSlots][cNumLayers][cMaxTilesPerLayer * 4];  // Tile vertex scratch, double-buffered per layer
    /* 0xBB814 */  u16 quadIndices[cMaxTilesPerLayer * 6];                                      // Shared quad index buffer, referenced by indexStream
    /* 0xBE6F4 */  u32 bufferIdx;                                                               // Active double-buffer slot, toggled by resetTexturePtrs
    /* 0xBE6F8 */  u32 layerTileCounts[cNumLayers];                                             // Quads recorded per layer this frame; reset by resetTexturePtrs
    /* 0xBE708 */  u8 layerHasTiles[cNumLayers];                                                // Per-layer "has tiles to draw" flags, recomputed each frame
    /* 0xBE70C */  nn::gr::CTR::Vertex::IndexStream indexStream;                                // Index buffer pointing at quadIndices
    /* 0xBE718 */  nn::gr::CTR::Vertex vertexArray[cNumBufferSlots * cNumLayers];               // Per-slot vertex states bound to tileVertices
    /* 0xC2398 */  nn::gr::CTR::BindSymbol proj;
    /* 0xC23A0 */  nn::gr::CTR::BindSymbol view;
    /* 0xC23A8 */  nn::gr::CTR::BindSymbol parallax;                                            // Tensor/parallax bind symbols resolved in init
    /* 0xC23B0 */  u32 bgSetupCmds[200];                                                        // Bg shader/setup commands emitted by submitBgSetupCommands
    /* 0xC26D0 */  u32 bgSetupCmdCount;                                                         // Word count of the above
    /* 0xC26D4 */  u8 _C26D4[1024];                                                             // Per-slot commands copied before the draw call (0x80 bytes per slot)
    /* 0xC2AD4 */  u8 _C2AD4[2080];                                                             // Per-slot command word counts & commands copied after the draw
    /* 0xC32F4 */  u8 _C32F4[32];                                                               // Per-slot trailing command word counts
    /* 0xC3314 */  sead::Vector2f tileUVs[cTilesetTileCount];                                   // Per-tile UVs into the tileset texture
    /* 0xC7314 */  f32 tileZDepth[cTilesetTileCount];                                           // Per-tile draw depth
    /* 0xC9314 */  u16 overlay3DId[cTilesetTileCount];                                          // Per-tile 3D overlay tile id (0 = none)

};

// size_assert(BgRenderer, 0xCA314);