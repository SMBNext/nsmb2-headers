#include "sead.h"

namespace sead { namespace system {

static bool sIsWarningEnable = false;

void Warning(const char* pos, s32 line, const char* format, ...)
{
    va_list varg;
    va_start(varg, format);

    if (sIsWarningEnable)
    {
        Print("%s(%d) Warning: ", pos, line);
        PrintV(format, varg);
    }

    va_end(varg);
}

void SetWarningEnable(bool enable)
{
    sIsWarningEnable = enable;
}

} }
