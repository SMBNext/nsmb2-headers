#pragma once

#include "types.h"

#include "sead/heap/seadHeap.h"
#include "sead/basis/seadNew.h"

// TODO: Move these 
extern sead::Heap* SystemHeap;
extern sead::Heap* ActorHeap;
extern sead::Heap* ModelResourceHeap;
extern sead::Heap* ModelSetupHeap;
extern sead::Heap* BgUnitHeap;
extern sead::Heap* CourseHeap;
extern sead::Heap* AreaHeap;
extern sead::Heap* SeadParticleHeap;
extern sead::Heap* FontHeap;
extern sead::Heap* SaveHeap;
extern sead::Heap* UIHeap;
extern sead::Heap* SoundResourceHeap;
extern sead::Heap* SoundHeap;
extern sead::Heap* NetHeap;
extern sead::Heap* WorkHeap;
extern sead::Heap* DebugHeap;


class Allocator
{    
public:
    virtual void unk00();                    // 004B39CC

    virtual void* alloc(size_t size, u8 align) = 0;
    virtual void* free(void* memblock) = 0;
};


/* There is a class between these two. dtor at 0x47EAD8 */

class HeapAllocator : public Allocator      // vtable: 005D35CC
{
public:
    HeapAllocator();                        // 0010A210
    void unk00();                           // 0047EAD8 Not sure if dtor or not. It's NOPed.

    void* alloc(size_t size, u8 align);     // 0047EABC
    void* free(void* memblock);             // 0047EAAC

    bool link(sead::Heap* heap);                  // 0010A204

    sead::Heap* heap;
};
