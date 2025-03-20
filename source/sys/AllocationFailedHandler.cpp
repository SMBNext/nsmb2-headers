#include "sead.h"
#include "sys/Allocator.h"


class AllocationFailedHandler : sead::HeapMgr::IAllocFailedCallback
{
public:
    static AllocationFailedHandler sAllocationFailedHandler;
    static void registerCallback();

    void invoke(const sead::HeapMgr::AllocFailedCallbackArg* arg) override;
};


AllocationFailedHandler AllocationFailedHandler::sAllocationFailedHandler;

void AllocationFailedHandler::registerCallback()
{
    sead::HeapMgr::instance()->mAllocFailedCallback = &sAllocationFailedHandler;
}

void AllocationFailedHandler::invoke(const sead::HeapMgr::AllocFailedCallbackArg* arg)
{
    SEAD_HALT_WITH_DETAIL
    (
        "sead allocation failed\n"
        "\n"
        "Requested size:      0x%X\n"
        "Requested alignment: 0x%X\n"
        "Alloc size:          0x%X\n"
        "Alloc alignment:     0x%X\n"
        "Heap:                %s",
        arg->request_size,
        arg->request_alignment,
        arg->alloc_size,
        arg->alloc_alignment,
        arg->heap->mINamableName.cstr()
    );
}
