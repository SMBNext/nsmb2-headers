#pragma once

#include "sead.h"


class PersistentDataMgr
{
    SEAD_SINGLETON_DISPOSER(PersistentDataMgr);
public:
    u16 get(f32 x, f32 y);
    void set(f32 x, f32 y, u16 data);
};
