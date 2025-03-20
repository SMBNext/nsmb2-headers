#pragma once

#include "sead.h"


class PersistentDataMgr : public sead::IDisposer
{
public:
    static PersistentDataMgr* instance;

    u16 get(f32 x, f32 y);
    void set(f32 x, f32 y, u16 data);
};
