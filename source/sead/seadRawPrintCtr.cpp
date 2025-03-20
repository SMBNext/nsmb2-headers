#include "sead.h"

#include "types.h"
#include "sys/Svc.h"

#include <stdio.h>


namespace sead { namespace system {

void PrintString(const char* str, s32 len)
{
    if (str != nullptr)
        svcOutputDebugString(str, len);
}

void Print(const char* format, ...)
{
    va_list list;
    va_start(list, format);

    char buffer[256];

    s32 fmt_len = vsnprintf(buffer, 256, format, list);
    s32 print_len;

    if (fmt_len <= 256)
    {
        print_len = fmt_len;
        if (print_len <= 0)
            return;
    }
    else
        print_len = 256;

    svcOutputDebugString(buffer, print_len);

    va_end(list);
}

void PrintV(const char* format, va_list list)
{
    char buffer[256];

    s32 fmt_len = vsnprintf(buffer, 256, format, list);
    s32 print_len;

    if (fmt_len <= 256)
    {
        print_len = fmt_len;
        if (print_len <= 0)
            return;
    }
    else
        print_len = 256;

    svcOutputDebugString(buffer, print_len);
}

} }
