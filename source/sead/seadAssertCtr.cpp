#include "sead.h"
#include "sys/Svc.h"
#include <stdio.h>


namespace sead { namespace system { 

void Halt()
{
    svcBreak(USERBREAK_PANIC);
    while(true);
}

void HaltWithDetail(const char* pos, s32 line, const char* format, ...)
{
    va_list list;
    va_start(list, format);

    sead::system::Print("\n//================= PROGRAM HALT ==================//\nSource File: %s\nLine Number: %d\nDescription: ", pos, line);
    sead::system::PrintV(format, list);
    sead::system::Print("\n//=================================================//\n");

    va_end(list);

    svcBreak(USERBREAK_PANIC);
    while(true);
}

void HaltWithDetailNoFormat(const char* pos, s32 line, const char* str)
{
    HaltWithDetail(pos, line, "%s", str);
}

} }
