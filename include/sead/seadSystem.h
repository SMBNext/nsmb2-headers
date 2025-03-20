#pragma once

#include "types.h"

namespace sead { namespace system { 

void PrintString(const char* str, s32 len);
void Print(const char* format, ...);
void PrintV(const char* format, va_list list);

void Warning(const char* pos, s32 line, const char* format, ...);
void SetWarningEnable(bool enable);

void Halt();
void HaltWithDetail(const char* pos, s32 line, const char* format, ...);
void HaltWithDetailNoFormat(const char* pos, s32 line, const char* str);

} }


#define SEAD_WARNING(...) \
    sead::system::Warning(__FILE__, __LINE__, __VA_ARGS__)

#define SEAD_HALT_WITH_DETAIL(...) \
    sead::system::HaltWithDetail(__FILE__, __LINE__, __VA_ARGS__)

#define SEAD_HALT_WITH_DETAIL_NO_FORMAT(str) \
    sead::system::HaltWithDetailNoFormat(__FILE__, __LINE__, str)

#define SEAD_ASSERT(exp) \
    (void) ((exp) || (SEAD_HALT_WITH_DETAIL_NO_FORMAT(#exp), 0))

#define SEAD_ASSERT_FMT(exp, ...) \
    (void) ((exp) || (SEAD_HALT_WITH_DETAIL(__VA_ARGS__), 0))
