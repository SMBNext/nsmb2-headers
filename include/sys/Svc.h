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

enum PageFlags : u32
{
    PAGE_FLAGS_LOCKED       = 0,
    PAGE_FLAGS_CHANGED      = 1
};

enum MemoryState
{
    MEM_STATE_FREE          = 0,
    MEM_STATE_RESERVED      = 1,
    MEM_STATE_IO            = 2,
    MEM_STATE_STATIC        = 3,
    MEM_STATE_CODE          = 4,
    MEM_STATE_PRIVATE       = 5,
    MEM_STATE_SHARED        = 6,
    MEM_STATE_CONTINUOUS    = 7,
    MEM_STATE_ALIASED       = 8,
    MEM_STATE_ALIAS         = 9,
    MEM_STATE_ALIAS_CODE    = 10,
    MEM_STATE_LOCKED        = 11
};

enum MemoryOperation : u32 {
    MEM_OP_FREE           = 1,
    MEM_OP_RESERVE        = 2,
    MEM_OP_COMMIT         = 3,
    MEM_OP_MAP            = 4,
    MEM_OP_UNMAP          = 5,
    MEM_OP_PROTECT        = 6,
};

enum MemoryPermission : u32
{
    MEM_PERM_NONE         = 0,
    MEM_PERM_R            = 1,
    MEM_PERM_W            = 2,         // Invalid
    MEM_PERM_RW           = 3,
    MEM_PERM_X            = 4,
    MEM_PERM_RX           = 5,
    MEM_PERM_WX           = 6,
    MEM_PERM_RWX          = 7,
    MEM_PERM_DONTCARE     = 0x10000000
};

struct MemoryInfo
{
    u32 baseAddr;   // Base process virtual address
    u32 size;
    u32 permission;
    MemoryState state;
};

struct PageInfo
{
    PageFlags flags;
};

extern "C"
{
    nn::Result svcQueryMemory(MemoryInfo* info, PageInfo* out, void* addr);       // 02
    void svcExitProcess() __attribute__((noreturn));                              // 03
    nn::Result svcClearEvent(nn::Handle handle);                                                                                        // 19
    nn::Result svcCreateMemoryBlock(nn::Handle handle, void* addr, u32 size, MemoryPermission myPerms, MemoryPermission otherPerms);    // 1E
    nn::Result svcMapMemoryBlock(nn::Handle handle, void* addr, MemoryPermission myPerms, MemoryPermission otherPerms);                 // 1F
    nn::Result svcUnmapMemoryBlock(nn::Handle handle, void* addr);                // 20
    nn::Result svcCloseHandle(nn::Handle handle);                                 // 23
    nn::Result svcWaitSynchronization(nn::Handle handle, s64 timeout);            // 24  Timeout in nanoseconds
    nn::Result svcWaitSynchronizationN(s32* out, nn::Handle* handles, s32 handleCount, bool waitAll, s64 timeout);   // 25  Timeout in nanoseconds
    u64 svcGetSystemTick();                                                       // 28
    nn::Result svcSendSyncRequest(nn::Handle handle);                             // 32
    nn::Result svcOpenProcess(nn::Handle* process, u32 processId);                // 33
    nn::Result svcGetProcessId(u32* out, nn::Handle handle);                      // 35
    void svcBreak(UserBreakType breakReason);                                     // 3C
    nn::Result svcOutputDebugString(const char* str, s32 length);                 // 3D
    nn::Result svcControlProcessMemory(nn::Handle process, u32 addr0, u32 addr1, u32 size, u32 type, u32 perm);     // 70
}
