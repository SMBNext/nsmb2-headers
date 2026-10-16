#pragma once

#include "sead.h"
#include "gfx/Renderer.h"

class PukupukuModelMgr
{
    SEAD_SINGLETON_DISPOSER(PukupukuModelMgr);
public:
    bool createModels();        // 0x003258F8
    void destroyModels();       // 0x00325D94
    void applyEnvLight();
};
