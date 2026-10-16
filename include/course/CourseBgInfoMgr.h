#pragma once

#include "sead.h"

class CourseBgInfoMgr
{
    SEAD_SINGLETON_DISPOSER(CourseBgInfoMgr);
public:
    void loadCourseBg();                               // 0x001C7B88
    const sead::SafeString* getBgName();               // 0x001C7B6C

    const sead::SafeString* getPlayerLightName();      // 0x001C7B00
    const sead::SafeString* getEnemyLightName();       // 0x001C7A48

    u8 bgIdx;
};

size_assert(CourseBgInfoMgr, 0x14);
