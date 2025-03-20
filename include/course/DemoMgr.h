#pragma once

#include "sead.h"

class DemoMgr : public sead::IDisposer
{
public:
    static DemoMgr* instance;

    bool freeze();
    bool freezeIfOnGround();

    void unfreeze();

    bool setDemoState(u32 id);
};
