#pragma once

#include "sead.h"

#include "gfx/GfxWrapper.h"


class FragmentLight : public TransformNodeWrapper
{
public:
    FragmentLight();
    ~FragmentLight();

    virtual bool setup(HeapAllocator* allocator);
    virtual void vf14();        // Deleted

    bool setAmbient(const sead::Color4f& color);
    bool setDiffuse(const sead::Color4f& color);
    bool setDirection(const Vec3f& direction);
    bool setSpecular0(const sead::Color4f& color);
    bool setSpecular1(const sead::Color4f& color);
    void updateTransform();

private:
    void* mResFragmentLightData;
    void* mFragmentLight;
    s32 mLightSetID;
    HeapAllocator* mHeapAllocator;
    s32 _18;
};

size_assert(FragmentLight, 0x1C);

class EnvironmentalLightSet : public FragmentLight
{
public:
    EnvironmentalLightSet();
    ~EnvironmentalLightSet();

    void load(const sead::SafeString& identifier, u32 idx);
    void unload();
    void execute();

    sead::Color4f environmentColor;
};

size_assert(EnvironmentalLightSet, 0x2C);

class LightMgr
{
    SEAD_SINGLETON_DISPOSER(LightMgr);
public:
    virtual ~LightMgr();

    void insertLight(const EnvironmentalLightSet& light);
    void applyEnvColorToModel(nw::gfx::Model* model);

    HeapAllocator* allocator;
    sead::ExpHeap* lightMgrHeap;
    EnvironmentalLightSet* lights[11];
    void* lightSets[11];
    bool applyEnvColor;
};

size_assert(LightMgr, 0x78);
