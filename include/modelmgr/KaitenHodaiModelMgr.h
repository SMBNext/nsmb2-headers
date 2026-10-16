#pragma once

#include "sead.h"
#include "gfx/Renderer.h"

class KaitenHodaiModelMgr
{
    SEAD_SINGLETON_DISPOSER(KaitenHodaiModelMgr);
public:
    bool createModels();        // 0x0033AFFC
    void destroyModels();       // 0x0033B3E8
    void applyEnvLight();
};
