#pragma once

#include "enemy/Enemy.h"

#include "gfx/Renderer.h"
#include "gfx/SimpleRenderer.h"

class Gasagoso : public Enemy
{
public:
    Resource* resouce;
    AnimModelBase* model;                 // AnimModel<1,1,0>
    HeapAllocator allocator;
    void* matAnimPtr;                     // should be MaterialAnim
    u8 _1074[8];                          // unk
    Vec3f startPos;                       // init to this->position in onCreate
    Vec3f lineTop;
    Vec3f lineBottom;
    u32 _10A0;
    u8 _10A4[4];                          // unk
    u32 _10A8;
    u32 _10AC;
    u32 _10B0;
    f32 _10B4;
    f32 _10B8;
    u32 _10BC;
    u16 _10C0;
    u8 _10C2;
    u8 _10C3;
    u8 _10C4;
    u8 _10C5[3];                          // unk
    sead::ExpHeap* gasagosoHeap;
    SimpleRenderer simpleRenderer;
    u8 _2344[4];                          // unk
};

size_assert(Gasagoso, 0x2348);