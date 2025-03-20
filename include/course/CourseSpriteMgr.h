#pragma once

#include "sead.h"


class CourseSpriteMgr : public sead::IDisposer
{
public:
    static CourseSpriteMgr* instance;

    static const u16 spriteToProfileIds[];
    static const u32 spriteCount;
};
