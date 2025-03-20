#pragma once

#include "types.h"
#include "nn/result.h"
#include "nn/handle.h"

enum UserBreakType
{
    USERBREAK_PANIC         = 0,
    USERBREAK_ASSERT        = 1,
    USERBREAK_USER          = 2,
    USERBREAK_LOAD_RO       = 3,
    USERBREAK_UNLOAD_RO     = 4
};

extern "C"
{
    nn::Result svcCloseHandle(nn::Handle handle);                   // 23
    u64 svcGetSystemTick();                                         // 28
    nn::Result svcSendSyncRequest(nn::Handle handle);               // 32
    void svcBreak(UserBreakType breakReason);                       // 3C
    nn::Result svcOutputDebugString(const char* str, s32 length);   // 3D
}
