#pragma once

#include "sead.h"
#include "gfx/Renderer.h"

class KuriboModelMgr
{
    SEAD_SINGLETON_DISPOSER(KuriboModelMgr);
public:
    bool createModels();        // 0x002ECE34
    void destroyModels();       // 0x002ED2DC
    void applyEnvLight();

    HeapAllocator allocator;        // 10
    void* heapForModels[32];        // 18
    AnimModelBase* models[32];      // 98
    void* modelsGold[32];           // 118
    bool usedIndices[32];           // 198
    u32 numModelsAllocated;         // 1B8
};

size_assert(KuriboModelMgr, 0x1BC);
