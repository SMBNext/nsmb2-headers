#pragma once

#include "gfx/M2d.h"
#include "nw/font/ResFont.h"
#include "sead/heap/seadDisposer.h"
#include "types.h"

// Size: 0x18
class FontMgr
{
    SEAD_SINGLETON_DISPOSER(FontMgr);
public:
    /* 0x10 */  void* fontHandles;              // FontHandle*
    /* 0x14 */  nw::font::ResFont* systemFont;  //

};

size_assert(FontMgr, 0x18);
