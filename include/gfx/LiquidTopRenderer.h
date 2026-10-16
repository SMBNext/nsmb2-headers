#pragma once

#include "sead.h"
#include "gfx/VertexBuffer.h"

class LiquidTopRenderer_UnkBase
{
public:
    u32 arraySize;                  // (count for arrays?)
    Vec3f* unkVec3Array;            // length set in vf0
    Vec2f* unkVec2Array;            // length set in vf0
    void* _10;                      // unk array pointers, element size 4, all have same length
    void* _14;
    void* _18;
    void* _1C;
    void* _20;                      // unk array pointer, element size of 0x10
    Mtx34 matrix;

    virtual void vf0(sead::Heap* heap, u32 count);
};

size_assert(LiquidTopRenderer_UnkBase, 0x54);


class LiquidTopRenderer : public LiquidTopRenderer_UnkBase
{
public:
    void swapBuffers();                                  // 0x002FCF10
    void drawSegment(u32 index);                         // 0x002FCEEC

    Vec2f arr[2][1024];             // holds 1024 points for top/bottom of the liquid top, separated by 8.0 units on X
    sead::Color4f color;
    sead::Color4f color2;
    u32 _4074;
    u32 _4078;
    u32 _407C;
    sead::Delegate<LiquidTopRenderer> renderDelegate;
    VertexBuffer vertexBuffer;
    sead::GraphicsContext graphicsContext;
};

size_assert(LiquidTopRenderer, 0x53CC);
