#pragma once

#include "sead/heap/seadHeap.h"
#include "sead/heap/seadMemBlock.h"

namespace sead {

typedef OffsetList<MemBlock> MemBlockList;

class ExpHeap : public Heap     // size: 0x94
{
public:
    enum AllocMode : u8
    {
        cAllocMode_FirstFit = 0,
        cAllocMode_BestFit  = 1,
    };

    void destroy() override;
    u32 adjust() override;
    void* tryAlloc(size_t size, s32 alignment) override;
    void free(void* ptr) override;
    void* resizeFront(void* p_void, size_t size) override;
    void* resizeBack(void* p_void, size_t size) override;
    void freeAll() override;
    void* getStartAddress() const override;
    void* getEndAddress() const override;
    u32 getSize() const override;
    u32 getFreeSize() const override;
    u32 getMaxAllocatableSize(s32 alignment) const override;
    bool isInclude(const void* p_void) const override;
    bool isFreeable() const override;
    bool isResizable() const override;
    bool isAdjustable() const override;
    void dump() const override;
    void genInformation_(hostio::Context* context) override;

    virtual void setAllocMode(AllocMode mode);
    virtual AllocMode getAllocMode() const;

    AllocMode mAllocMode;           // 70
    MemBlockList mFreeList;         // 74
    MemBlockList mUseList;          // 84
};

}
