#pragma once

#include "sead.h"
#include "gfx/Renderer.h"

class KillerModelMgr
{
    SEAD_SINGLETON_DISPOSER(KillerModelMgr);
public:
    bool createModels();        // 0x002EA748
    void destroyModels();       // 0x002EAB68
    void applyEnvLight();

    HeapAllocator allocator;
    void* heapForModels[32];
    AnimModelBase* modelsKiller[32];
    AnimModelBase* modelsKillerG[32];
    bool usedIndices[32];
    u32 numModelsAllocated;
};

size_assert(KillerModelMgr, 0x1BC);
