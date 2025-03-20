#pragma once

#include "sys/Allocator.h"
#include "math/Mtx34.h"

#include "nw/gfx/Model.h"
#include "nw/gfx/CalculatedTransform.h"

#include "sys/ResourceMgr.h"

#include "gfx/GfxWrapper.h"

// Size: 0x1C
// Vtable: 0x005A8698
class Model
{
public:

    // Address: 0x0024B5FC
    Model();

    // Address: 0x0024B640 (free: 0024B620)
    virtual ~Model();

    // Address: 0x0024B5D4
    virtual SkeletalModelWrapper* getGfxWrapper();
    
    // Address: 0x0024B5B4
    virtual void cleanup();
    
    // Address: 0x0024B5DC
    virtual void update();

    // Address: 0x0024B46C
    void create(
        nw::gfx::res::ResSceneObject* resource, nw::os::IAllocator* allocator,
        nw::gfx::Model::BufferOption bufferOption
    );
    
    // Address: 0x0024B4B4
    static Model* create(
        Resource* container, const sead::SafeString& key, Allocator* allocator,
        nw::gfx::Model::BufferOption bufferOption = nw::gfx::Model::FLAG_BUFFER_NOT_USE
    );

    inline void setScale(const Vec3f& scale)
    {
        getGfxWrapper()->getModel()->Transform().SetScale(scale);
    }

    inline void setDrawMatrix(Mtx34* mtx)
    {
        getGfxWrapper()->setDrawMatrix(mtx);
    }

    inline s32 getBoneIdx(const char* boneName)
    {
        return getGfxWrapper()->getBoneIdx(boneName);
    }

    inline bool getBoneWorldMatrix(Mtx34& out, s32 boneIdx)
    {
        return getGfxWrapper()->getBoneWorldTransformMatrix(out, boneIdx);
    }

    inline bool getBonePosition(Vec3f& out, s32 boneIdx)
    {
        return getGfxWrapper()->getBonePosition(out, boneIdx);
    }

    inline bool getBoneLocalMatrix(Mtx34& out, s32 boneIdx)
    {
        return getGfxWrapper()->getBoneLocalTransformMatrix(out, boneIdx);
    }

    inline bool getBoneLocalScale(Vec3f& out, s32 boneIdx)
    {
        return getGfxWrapper()->getBoneLocalTransformScale(out, boneIdx);
    }

    inline void setBoneLocalMatrix(s32 boneIdx, const Mtx34& mtx)
    {
        return getGfxWrapper()->setBoneLocalTransformMatrix(boneIdx, mtx);
    }

    inline void setBoneLocalScale(s32 boneIdx, const Vec3f& vec)
    {
        return getGfxWrapper()->setBoneLocalTransformScale(boneIdx, vec);
    }

    inline nw::gfx::CalculatedTransform* getBoneWorldTransform(s32 boneIdx)
    {
        return getGfxWrapper()->getBoneWorldTransform(boneIdx);
    }

    inline nw::gfx::CalculatedTransform* getBoneLocalTransform(s32 boneIdx)
    {
        return getGfxWrapper()->getBoneLocalTransform(boneIdx);
    }

private:
    SkeletalModelWrapper mModelWrapper;
};

size_assert(Model, 0x1C);