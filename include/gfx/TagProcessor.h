#pragma once

#include "sys/Common.h"
#include "types.h"

// Size: 0xC
class TagProcessor
{
public:
    TagProcessor();
    virtual ~TagProcessor();

    virtual s32 Process(u16 code, void* printContext);
    virtual s32 CalcRect(void* rect, u16 code, void* printContext);

    static s32 formatMessage(
        wchar_t* out, u32 outLength, const wchar_t* text, u32 textSize, s32 _10, s32 page, s32* pageCount,
        bool usePlaceholders, s32 argCount, const u32* args
    );

public:
    /* 0x4 */  Color8 savedTextColors[2];  // TextColor
};

size_assert(TagProcessor, 0xC);
