#pragma once

#include "types.h"
#include "nn/gx.h"
#include "nn/gr/gr_BindSymbol.h"

namespace nn {
namespace gr {
namespace CTR {

class Vertex
{
public:
    static const u32 VERTEX_ATTRIBUTE_MAX = 12;
    static const u32 VERTEX_ATTRIBUTE_DIMENSION_MAX = 4;
    static const u32 VERTEX_ENABLE_COMMAND_MAX = 12 + VERTEX_ATTRIBUTE_MAX * 6;

    class InterleaveInfo
    {
    public:
        // Inlined @ 0x001CA9D0
        InterleaveInfo()
        { 
            dataNum = 0;
            for ( u32 index = 0; index < VERTEX_ATTRIBUTE_MAX; index++ )
            {
                dataType[index] = PICA_DATA_SIZE_1_BYTE;
                symbol[index] = NULL;
            }
        }

    public:
        u8 dataNum;
        PicaDataVertexAttrType dataType[VERTEX_ATTRIBUTE_MAX];
        const nn::gr::CTR::BindSymbolVSInput* symbol[VERTEX_ATTRIBUTE_MAX];                  
    };

    size_assert(InterleaveInfo, 0x40);

    class IndexStream
    {
    public:
        IndexStream() :
            physicalAddr(0),
            drawVtxNum(0),
            isUnsignedByte(false) {}

    public:
        uptr physicalAddr;
        u32 drawVtxNum;
        bool isUnsignedByte;
    };

    size_assert(IndexStream, 0xC);

protected:
    class LoadArray
    {
    public:
        // Address: 0x001443D0
        LoadArray();

        bool IsEnable() const { return physicalAddr != 0; }
        void CheckDisable();

        // Address: 0x00144390
        void DisableAll();

        public:
            uptr physicalAddr;
            PicaDataVertexAttrType type[VERTEX_ATTRIBUTE_MAX];
            u32 byte[VERTEX_ATTRIBUTE_MAX];
            s32 bind[VERTEX_ATTRIBUTE_MAX];
    };

    size_assert(LoadArray, 0x70);

    class AttrConst
    {
    public:
        // Address: 0x00144384
        AttrConst();

        bool IsEnable() const { return dimension != 0; }
        void Disable() { dimension = 0; }

        // Inlined @ 0x0014445C
        void DisableAll()
        {
            dimension = 0;
            for ( u32 index = 0; index < VERTEX_ATTRIBUTE_DIMENSION_MAX; index++ )
            {
                param[index] = 0;
            }
        }

    public:
        u8 dimension;
        f32 param[VERTEX_ATTRIBUTE_DIMENSION_MAX];
    };

    size_assert(AttrConst, 0x14);

public:
    // Address: 0x001443DC
    explicit Vertex();

    // Address: 0x00144118
    void EnableAttrAsArray(const nn::gr::CTR::BindSymbolVSInput& symbol, const uptr physical_addr, const PicaDataVertexAttrType type);
    
    // This is probably inlined
    //void EnableAttrAsConst(const nn::gr::CTR::BindSymbolVSInput& symbol, const u8 dimension, const f32 param[]);
    
    // Address: 0x00144248
    void EnableInterleavedArray(const nn::gr::CTR::Vertex::InterleaveInfo& interleave_info, const uptr physical_addr);
    
    // Address: 0x00488358
    bit32* MakeEnableAttrCommand(bit32* command) const;

    // Address: 0x004882B8
    bit32* MakeDrawCommand(bit32* command, const IndexStream& index_stream) const;

    // This is probably inlined
    // bit32* MakeDisableAttrCommand(bit32* command) const;
    // static bit32* MakeDisableCommand(bit32* command);

    void DisableAttr(const nn::gr::CTR::BindSymbolVSInput& symbol)
    {
        DisableAttr_(symbol.start);
    }

    void DisableAll()
    {
        mCmdCacheVertexNum = 0;

        for (u32 index = 0; index < VERTEX_ENABLE_COMMAND_MAX; index++)
        {
            mCmdCacheVertex[index] = 0;
        }

        for (u32 index = 0; index < VERTEX_ATTRIBUTE_MAX; index++)
        {
            mIsEnableReg[index] = false;
            mLoadArray[index].DisableAll();
            mAttrConst[index].DisableAll();
        }
    }
    
protected:
    // Address: 0x0014400C
    void DisableAttr_(const bit32 bind_reg);

    // Address: 0x00488358
    bit32* MakeEnableAttrCommand_(bit32* command) const;

protected:
    mutable u32 mCmdCacheVertexNum;
    mutable bit32 mCmdCacheVertex[VERTEX_ENABLE_COMMAND_MAX];

    bool mIsEnableReg[VERTEX_ATTRIBUTE_MAX];
    LoadArray mLoadArray[VERTEX_ATTRIBUTE_MAX];
    AttrConst mAttrConst[VERTEX_ATTRIBUTE_MAX];
};

size_assert(Vertex, 0x790);

}  // namespace CTR
}  // namespace gr
} // namespace nn
