#pragma once

#include "sead/seadRuntimeTypeInfo.h"
#include "sead/seadNamable.h"
#include "sead/seadOffsetList.h"
#include "sead/seadCriticalSection.h"
#include "sead/seadBitFlag.h"

namespace sead {

namespace hostio {
class Context;
} // namespace hostio

class Thread;

// Size: 0x70
// Vtable: 0x005D2DE8
class Heap : public IDisposer, public INamable
{
public:
    enum HeapDirection : s8
    {
        HeapDirection_Forward =  1,
        HeapDirection_Reverse = -1,
    };

private:
    typedef OffsetList<Heap> HeapList;
    typedef OffsetList<IDisposer> DisposerList;

    class Flag
    {
    public:
        enum ValueType : u32
        {
            EnableLock,
        };
    };

public:

    // C2 Address: 0x00116E44
    Heap(const SafeString& name, Heap* parent, void* start, size_t size, HeapDirection direction, bool enableLock);

    // D2 Address: 0x004698D8
    virtual ~Heap();

    // GetRuntimeTypeInfo 0x004B2428
    SEAD_RTTI_BASE(Heap);

    virtual void destroy() = 0;
    virtual u32 adjust() = 0;

    void* alloc(size_t size, s32 alignment)
    {
        return tryAlloc(size, alignment);
    }

    virtual void* tryAlloc(size_t size, s32 alignment) = 0;
    virtual void free(void* ptr) = 0;
    virtual void* resizeFront(void* p_void, size_t size) = 0;
    virtual void* resizeBack(void* p_void, size_t size) = 0;
    virtual void freeAll() = 0;
    virtual void* getStartAddress() const = 0;
    virtual void* getEndAddress() const = 0;
    virtual u32 getSize() const = 0;
    virtual u32 getFreeSize() const = 0;
    virtual u32 getMaxAllocatableSize(s32 alignment) const = 0;

    Heap* getParent() const { return mParent; }

    virtual bool isInclude(const void*) const = 0;

    HeapDirection getDirection() const { return mDirection; }

    virtual bool isFreeable() const = 0;
    virtual bool isResizable() const = 0;
    virtual bool isAdjustable() const = 0;

    void setEnableLock(bool enableLock)
    {
        mFlag.changeBit(Flag::EnableLock, enableLock);
    }

    bool isEnableLock() const
    {
        return mFlag.isOnBit(Flag::EnableLock);
    }

    // void setEnableWarning(bool);
    // bool isEnableWarning() const;
    // void setAccessThread(Thread*);
    // Thread* getAccessThread() const;

    CriticalSection& getCriticalSection() { return mCS; }

    // Deleted
    virtual void dump() const = 0;

protected:
    // Deleted
    virtual void genInformation_(hostio::Context* context);

    // Address: 0x00469828
    void destruct_();

    // Address: 0x00469788
    void dispose_(const void*, const void*);

    // Address: 0x0011AE3C
    void appendDisposer_(IDisposer* d);

    // Address: 0x0010DEF8
    void removeDisposer_(IDisposer* d);

    // Address: 0x0011C4E4
    Heap* findContainHeap_(const void* ptr);

    // void pushBackChild_(Heap*);
    // void eraseChild_(Heap*);
    // bool hasNoChild_() const;


public:
    // temp workaround due to getSize being optimzied out 
    u32 size() const
    {
        return mSize;
    }

protected:
    void* mStart;                   // 18
    u32 mSize;                      // 1C
    Heap* mParent;                  // 20
    HeapList mChildren;             // 24
    ListNode mListNode;             // 34
    DisposerList mDisposerList;     // 3C
    HeapDirection mDirection;       // 4C
    CriticalSection mCS;            // 50
    BitFlag32 mFlag;                // 6C

    friend IDisposer::IDisposer();
    friend IDisposer::~IDisposer();
    friend class HeapMgr;
};

size_assert(Heap, 0x70);

} // namespace sead