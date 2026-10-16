#pragma once

#include "types.h"
#include "math/Vec.h"
#include "sys/Common.h"
#include "nn/gr/gr_Vertex.h"
#include "sead/gfx/seadColor.h"

// This probably has a different name, but idk what it would be called
class VertexBuffer
{
public:
    struct VertexInfo
    {
        Vec4f position;
        Vec2f uv;
        sead::Color4f color;
    };

    size_assert(VertexInfo, 0x28);

public:
    // Address: 0x0024BF90
    VertexBuffer();

    // Address: 0x0024B970
    void sub_24B970(sead::Heap* heap, u32 vertexCount, const sead::TextureCtrGR& texture);

    // Address: 0x0024BD4C
    void sub_24BD4C();

    // Address: 0x0024BE80
    void sub_24BE80();

protected:
    VertexInfo* mVertexInfo[2];
    u32 mNumIndices;
    u32 mBufferIndex;
    u32 mVertexCount;
    nn::gr::CTR::Vertex mVertexArray[2];
    nn::gr::CTR::Vertex::IndexStream mIndexStream;
    u8 mCmdBuffer[256];
    u32 mCmdBufferSize;
    u8 mAttributeBufferA[2][128];
    u32 mAttributeBufferASize[2];
    u8 mAttributeBufferB[2][128];
    u32 mAttributeBufferBSize[2];
};

size_assert(VertexBuffer, 0x1254);
