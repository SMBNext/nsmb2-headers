#pragma once

#include "actors/fBase.h"
#include "gfx/GfxWrapper.h"
#include "types.h"


// Size: 0x3C
class BsFogMgr : public fBase
{
public:
    enum class FogLayer
    {
        cLayer0 = 0,    // used by KoopaLast
        cLayer1 = 1,    // Used by KoopaClown
        cLayerCount     //
    };

    enum class DepthType
    {
        cMin = 0,       // 
        cMax = 1,       // 
        cDepthCount     //
    };

    static constexpr u32 cFogLayerNum = static_cast<u32>(FogLayer::cLayerCount);
    static constexpr u32 cDepthTypeNum = static_cast<u32>(DepthType::cDepthCount);

    // Size: 0x14
    struct FogConfig
    {
        /* 0x00 */  u32 fogUpdaterType;     // TODO: this is a nw::gfx::res::ResFogUpdater::FogUpdaterType
        /* 0x04 */  f32 minFogDepth;        //
        /* 0x08 */  f32 maxFogDepth;        //
        /* 0x0C */  f32 fogDensity;         //
        /* 0x10 */  f32 _10;                //
    };
    size_assert(FogConfig, 0x14);

private:
    static BsFogMgr* sInstance;

    static FogConfig sFogWork[BsFogMgr::cFogLayerNum];
    static FogConfig sFogActive[BsFogMgr::cFogLayerNum];
    static nw::ut::FloatColor sFogColor[BsFogMgr::cFogLayerNum];

public:
    BsFogMgr();
    ~BsFogMgr() override;

    Result onCreate() override;
    Result onDelete() override;
    Result onExecute() override;
    Result onDraw() override;

    // Sets the minimum depth offset value for the given `layer` to `depth`.
    void setMinDepthOffset(FogLayer layer, s32 depth);

    // Returns a pointer to the singleton instance of `BsFogMgr`.
    static BsFogMgr* instance();

private:
    // Updates all fog layers with the matching `FogConfig` contained in `sFogWork` and `sFogActive`.
    void updateFog();
    
    /* 0x18 */  FogWrapper mFogs[BsFogMgr::cFogLayerNum];   // The fog associated with each fog layer.
    /* 0x2C */  struct {
        /* 0x0 */  s32 depth[BsFogMgr::cFogLayerNum];       // Depth offset for each fog layer.
    } mDepthOffsets[BsFogMgr::cDepthTypeNum];               // Depth offsets for minimum & maximum depth.
};

size_assert(BsFogMgr, 0x3C);
