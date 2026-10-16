#pragma once

#include "sead.h"
#include "sead/gfx/seadTexture.h"

#include "sys/ResourceMgr.h"
#include "gfx/AnimModel.h"
#include "gfx/VertexBuffer.h"
#include "utility/EnumUtil.h"

// Size: 0x18D4
class DistantViewMgr
{
public:
    static constexpr u32 MAX_MATERIALS = 30;
    static constexpr u32 MAX_LAYERS = 12;

public:
    SEAD_SINGLETON_DISPOSER(DistantViewMgr);

public:
    class Material
    {
    public:
        // Address: 0x002E7A5C
        Material();

        nw::gfx::res::ResMaterialData *mMaterialData;
        bool mOverrideAlpha;
        f32 m3DBlendFactor;
    };

    size_assert(Material, 0xC);

    enum class ParallaxType : u32
    {
        cAllParallax_NoYOffset   = 0,
        cAllParallax_YOffset     = 1,
        cNoParallax_YOffset      = 2,
        cParallaxX_YOffset       = 3,
        cParallaxY_YOffset       = 4,
    };

    enum class LayerSettings : s32
    {
        cNone = 0,
        cParallaxOffX = 1 << 0,
        cParallaxOffY = 1 << 1,
    };

public:
    // Address: 0x002E80D4
    DistantViewMgr();

    // Address D0: 0x002E82F4
    // Address D1: 0x002E83B8
    virtual ~DistantViewMgr();

    // Address: 0x002E6A74
    void execute();
    
    // Address: 0x002E6A78
    void updateModel();

    // Address: 0x002E6CB4
    void load(u8 areaId, u8 zoneId, const sead::BoundBox2f& zoneRect);

    // Address: 0x002E7B6C
    void setMaterialAlpha(u32 materialIdx, f32 alpha);

    // Address: 0x002E7BB0
    void draw();

    // Address: 0x002E80A0
    void unkCallback();

private:
    Resource resource;                              // 14
    HeapAllocator allocator;                        // 1C8  
    AnimModel<1,1,0>* model;                        // 1D0  
    sead::FixedSafeString<32> dvName;               // 1D4
    f32 xPosOffset;                                 // 200
    f32 _204;                                       // 204 
    f32 _208;                                       // 208
    f32 yPosOffset;                                 // 20C  
    u32 layerCount;                                 // 210
    s32 layerBoneIdx[MAX_LAYERS];                   // 214
    sead::Vector3f layerPositions[MAX_LAYERS];      // 244
    sead::Vector2f layerOffsets[MAX_LAYERS];        // 2D4 - maybe speeds?
    Material materials[MAX_MATERIALS];              // 334
    u32 materialCount;                              // 49C
    u32 _4A0[MAX_MATERIALS];                        // 4A0 - material related
    f32 _518;                                       // 518
    f32 _51C;                                       // 51C
    sead::Vector2f currentScrollOffset;             // 520
    ParallaxType parallaxType;                      // 528
    sead::Delegate<DistantViewMgr> renderDelegate;  // 52C
    sead::GraphicsContext graphicsContext;          // 53C
    VertexBuffer vertexBuffer;                      // 624
    sead::Color4f vertexColor[4];                   // 1878
    sead::TextureCtrGR noiseTexture;                // 18B8
    u8 _18CC[6];                                    // 18CC

};

ENUM_CLASS_ENABLE_FLAGS(DistantViewMgr::LayerSettings, s32);

size_assert(DistantViewMgr, 0x18D4);
