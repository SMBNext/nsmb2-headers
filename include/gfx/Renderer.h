#pragma once

#include "gfx/AnimModel.h"
#include "sead.h"
#include "nn/ulcd/StereoCamera.h"

// Size 0x3A0
class Renderer
{
    // createInstance()                             Address: 0x00429264
    // deleteInstance()                             Address: deleted
    // sInstance                                    Address: 0x005E74F0
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x00429314
    // SingletonDisposer_::sStaticDisposer          Address: 0x005E74F4
    // SingletonDisposer_::vtbl                     Address: 0x005CD250
    SEAD_SINGLETON_DISPOSER(Renderer);

    typedef u8 OrthoCamWrapper[0x10C];

public:

    // Address: 0x00429A90
    Renderer();

    // Address: 0x00428F78
    void initialize();

    // Address: 0x004290B4
    void setViewRect(const sead::BoundBox2f& viewRect);

    // Address: 0x004290D8
    void updateCamera();
    
    // Address: 0x00429A1C
    void drawModel(SkeletalModelWrapper* model);

    // Address: 0x00429370
    void drawTile(u16 tileId, const Vec3f& position);

    // Address: 0x004293D8
    void drawTile(u16 tileId, const Vec3f& position, const s32& rotationZ, const Vec3f& scale);

    // Address: 0x00429474
    void drawTile(u16 tileId, const Vec3f& position, const Vec3i& rotation, const Vec3f& scale);

    // Address: 0x004292C0
    // Draws tile with Layer ID 3 (foreground layer)
    void drawTileForeground(u16 tileId, const Vec3f& position, const s32& rotationZ, const Vec3f& scale);

    // Address: 0x004294F8
    void drawTile(u16 tileId, const Vec3f& position, const Vec3f& position2, Vec3f** position3, Vec3f** position4);

    inline u32 zPosToLayerId(f32 zPos)
    {
        if (zPos < 0.0) return 1;
        if (zPos >= 2500.0) return 3;
        if (zPos >= 500.0) return 2;
        return 0;
    }

    inline void drawModel(Model* model)
    {
        drawModel(model->getGfxWrapper());
    }

    inline const sead::BoundBox2f& viewRect() const
    {
        return mViewRect;
    }

    inline const sead::OrthoProjection& projection() const
    {
        return mProjection;
    }

    inline const sead::OrthoCamera& camera() const
    {
        return mCamera;
    }

private:
    sead::BoundBox2f mViewRect;             // 0x10
    sead::OrthoProjection mProjection;      // 0x20
    sead::OrthoCamera mCamera;              // 0xCC
    OrthoCamWrapper _124;                   // 0x124
    OrthoCamWrapper _320;                   // 0x320
    nn::ulcd::CTR::StereoCamera mStereoCam; // 0x33C
    f32 mParallax;                          // 0x39C
};

size_assert(Renderer, 0x3A0);