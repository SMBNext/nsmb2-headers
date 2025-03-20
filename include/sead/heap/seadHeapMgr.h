#pragma once

#include "sead/heap/seadHeap.h"
#include "sead/heap/seadArena.h"
#include "sead/seadDelegate.h"
#include "sead/seadPtrArray.h"

namespace sead {

// Size: 0x8
// Vtable: 0x005D2FCC
class HeapMgr
{
public:

    struct AllocFailedCallbackArg   // size: 0x14
    {
        sead::Heap* heap;           // 0
        u32 request_size;           // 4
        s32 request_alignment;      // 8
        u32 alloc_size;             // C
        s32 alloc_alignment;        // 10
    };

    typedef IDelegate1<const AllocFailedCallbackArg*> IAllocFailedCallback;

private:
    typedef FixedPtrArray<Heap, 4> RootHeaps;

public:
    // D2 Address: 0x00478A64
    virtual ~HeapMgr();

    // Address: 0x0011732C
    static void initialize(u32 size);

    // TODO
    // static void initialize(Arena* arena);

    // TODO
    // static void destroy();

    static bool isInitialized() { return sInstancePtr != nullptr; }
    static HeapMgr* instance() { return sInstancePtr; }

    // Address: 0x001197C8
    Heap* findContainHeap(const void* memBlock) const;

    // Address: 0x0011340C
    Heap* getCurrentHeap() const;
    
    // TODO
    // static Heap* getRootHeap(s32 n) { return sRootHeaps.at(n); }
    // static s32 getRootHeapNum() { return sRootHeaps.size(); }
    // static void addRootHeap(Heap* heap);
    // static const Arena* getArena();
    // static IndependentHeaps* getIndependentHeaps() { return &sIndependentHeaps; }
    // static bool isContainedInAnyHeap(const void* ptr) { return sInstancePtr->findContainHeap(ptr) != nullptr; }

    // TODO
    // IAllocFailedCallback* setAllocFailedCallback(IAllocFailedCallback* callback);
    // IAllocFailedCallback* getAllocFailedCallback();


    IAllocFailedCallback* mAllocFailedCallback;     // 4
protected:

    // Address: 0x00109E10
    Heap* setCurrentHeap_(Heap* heap);


    // Address: 0x005F3E50
    static HeapMgr sInstance;

    // Address: 0x005F3E48
    static HeapMgr* sInstancePtr;

    // Address: 0x005F3E4C
    static Arena* sArena;

    // Address: 0x006B6624
    static Arena sDefaultArena;

    // Address: 0x006B6630
    static RootHeaps sRootHeaps;

    // Address: 0x006B664C
    static CriticalSection sHeapTreeLockCS;

    // TODO
    // static IndependentHeaps sIndependentHeaps;

    friend class AllocationFailedHandler;
};

}
