#pragma once

#include "sead.h"


class BigRedFramework : public sead::UlcdDoubleCmdGameFrameworkCtrNw4c  // 0x168
{
public:
    static BigRedFramework* getInstance();

    bool clearFrameBuffers;     // 160
    u8 _161;                    // 161
    u8 _162;                    // 162
    GLuint _164;                // 164  cmdlist
};
