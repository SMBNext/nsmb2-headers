#pragma once

#include "gfx/Model.h"
#include "gfx/Animation.h"

// Size: 0x38
// Vtable: 0x005AC908
class AnimModelBase : public Model
{
public:

    // Address: 0x0028A880
    AnimModelBase(
        u32 numSkeletalAnim,   AnimBase** skeletalAnims,
        u32 numMaterialAnim,   AnimBase** materialAnims,
        u32 numVisibilityAnim, AnimBase** visibilityAnims
    );

    // Address: 0x0028A620
    void cleanup() override;

    // Address: 0x0028A838
    void update() override;

    // Address: 0x0028A814
    void updateAnimation();

    // Address: 0x0028A140
    void setup(
        nw::gfx::res::ResModel* model, nw::anim::res::ResAnim* anim,
        HeapAllocator* allocator, Resource* modeRes, Resource* animRes,
        nw::gfx::Model::BufferOption bufferOption = nw::gfx::Model::MULTI_FLAG_ANIMATABLE_MATERIAL
    );

    // Address: 0x0028A744
    void setSkeletalAnim(Resource* res, const sead::SafeString& key);

    // Address: 0x001B1B60
    void setSkeletalAnim(u32 slot, Resource* res, const sead::SafeString& key);

    // Address: 0x001B454C
    void setMaterialAnim(u32 slot, Resource* res, const sead::SafeString& key);

    // Address: 0x001B4724
    void setVisibilityAnim(u32 slot, Resource* res, const sead::SafeString& key);

    inline AnimBase* skeletalAnim(u32 slot) const
    {
        return mSkeletalAnims[slot];
    }

    inline AnimBase* materialAnim(u32 slot) const
    {
        return mMaterialAnims[slot];
    }

    inline AnimBase* visibilityAnim(u32 slot) const
    {
        return mVisibilityAnims[slot];
    }

private:
    u32 mNumSkeletalAnim;           // 1C
    AnimBase** mSkeletalAnims;      // 20
    
    u32 mNumMaterialAnim;           // 24
    AnimBase** mMaterialAnims;      // 28

    u32 mNumVisibilityAnim;         // 2C
    AnimBase** mVisibilityAnims;    // 30

    bool mHasNoAnimations;          // 34
    u8 _35;                         // 35
};

size_assert(AnimModelBase, 0x38);