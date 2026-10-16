#pragma once

#include "sead.h"
#include "gfx/Renderer.h"

class TeresaModelMgr
{
    SEAD_SINGLETON_DISPOSER(TeresaModelMgr);
public:
    bool createModels();        // 0x002FBA8C
    void destroyModels();       // 0x002FC238
    void applyEnvLight();

    HeapAllocator allocator;                    // 10
    void* modelHeap[16];                        // 18
    AnimModelBase* modelsTeresa[16];           // 58
    AnimModelBase* modelsTeresa_G[16];         // 98
    AnimModelBase* modelsTeresaB[16];          // D8
    AnimModelBase* modelsTeresaB_G[16];        // 118
    AnimModelBase* modelsFog[16];              // 158
    AnimModelBase* modelsFog_G[16];            // 198
    u8 usedIndices[16];                         // 1D8
    s32 numModelsAllocated;                     // 1E8
};

size_assert(TeresaModelMgr, 0x1EC);
