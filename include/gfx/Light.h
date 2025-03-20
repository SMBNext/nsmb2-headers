#pragma once

#include "sead.h"


class Light
{
public:
    Light();
    ~Light();

    void load(const sead::SafeString& identifier, u32 idx);
    void unload();
    void execute();

    u8 _0[0x2C];
};
