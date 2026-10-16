#pragma once

#include "sead.h"
#include "gfx/Renderer.h"

class NokonokoModelMgr
{
    SEAD_SINGLETON_DISPOSER(NokonokoModelMgr);
public:
    bool createModels();        // 0x00320EA0
    void destroyModels();       // 0x00321478
    void applyEnvLight();

    HeapAllocator allocator;                            // 10
    void* heapForModels[32];                            // 18
    AnimModelBase* modelsNokonokoA[32];                // 98
    AnimModelBase* modelsNokonokoA_G[32];              // 118
    AnimModelBase* modelsNokonoko_shell[32];           // 198
    AnimModelBase* modelsNokonokoA_G_shell[32];        // 218
    AnimModelBase* modelsPatapata[32];                 // 298
    AnimModelBase* modelsPatapata_G[32];               // 318
    bool usedIndices[32];                               // 398
    u32 numModelsAllocated;                             // 3B8
};

size_assert(NokonokoModelMgr, 0x3BC);
