#pragma once

#include "gfx/Animation.h"
#include "nw/anim/res/ResAnim.h"

class SkeletalModelWrapper;

class UnkSkeletalAnimHolder
{
public:
    UnkSkeletalAnimHolder();                // 0x0059E23C
    virtual ~UnkSkeletalAnimHolder();       // 0x001B32A8

    void* _4;                               // Unk class
    SkeletalModelWrapper* _8;
    HeapAllocator allocator;
    SkeletalAnim skeletalAnims[4];

    bool setup(SkeletalModelWrapper* skeletalModelWrapper, nw::anim::res::ResAnim resAnim, HeapAllocator* allocator, u32 unkFlag);
};

size_assert(UnkSkeletalAnimHolder, 0x74)
