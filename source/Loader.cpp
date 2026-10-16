#include "sys/Svc.h"

mw_loader_code
void loaderPanic()
{
    svcBreak(USERBREAK_PANIC);
    while (true);
}

mw_loader_code
mw_pre(0x100000)
void loaderMain()
{
    nn::Result r;
    u32 currentPid;
    nn::Handle processHandle;

    r = svcGetProcessId(&currentPid, nn::Handle::CURRENT_PROCESS);
    if (r.isFailure())
        loaderPanic();

    r = svcOpenProcess(&processHandle, currentPid);
    if (r.isFailure())
        loaderPanic();

    u32 addr = (u32)&__mw_text_start & ~0xFFF;
    u32 size = (((u32)&__mw_text_end + 0xFFF) & ~0xFFF) - addr;

    // Reprotect custom code as RWX
    r = svcControlProcessMemory(
        processHandle,
        addr,
        addr,
        size,
        MEM_OP_PROTECT,
        MEM_PERM_RWX
    );
    if (r.isFailure())
        loaderPanic();

    // Reprotect rodata as RW
    r = svcControlProcessMemory(
        processHandle,
        0x0056B000,
        0x0056B000,
        0x70000,
        MEM_OP_PROTECT,
        MEM_PERM_RW
    );
    if (r.isFailure())
        loaderPanic();
}