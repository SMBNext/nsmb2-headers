#pragma once

#include "types.h"
#include "nn/gx.h"

// TODO: Some stuff is missing from this, either find in nsmb2 or re-implement

namespace nn {
namespace gr {
namespace CTR {

class RenderState
{
public:
    class Blend
    {
    public:
        // Inlined
        explicit Blend(const RenderState& renderState) : 
            isEnable(false),
            eqRgb(PICA_DATA_BLEND_EQUATION_ADD),
            eqAlpha(PICA_DATA_BLEND_EQUATION_ADD),
            srcRgb(PICA_DATA_BLEND_FUNC_SRC_ALPHA),
            srcAlpha(PICA_DATA_BLEND_FUNC_SRC_ALPHA),
            dstRgb(PICA_DATA_BLEND_FUNC_ONE_MINUS_SRC_ALPHA),
            dstAlpha(PICA_DATA_BLEND_FUNC_ONE_MINUS_SRC_ALPHA),
            colorR(0xFF),
            colorG(0xFF),
            colorB(0xFF),
            colorA(0xFF),
            mRenderState(renderState) {}

        // Address: 0x00112F20
        bit32* MakeCommand(bit32* command, bool isUpdateFBAccess = true) const;

    public:
        bool isEnable;
        PicaDataBlendEquation eqRgb;
        PicaDataBlendEquation eqAlpha;
        PicaDataBlendFunc srcRgb;
        PicaDataBlendFunc srcAlpha;
        PicaDataBlendFunc dstRgb;
        PicaDataBlendFunc dstAlpha;
        u8 colorR;
        u8 colorG;
        u8 colorB;
        u8 colorA;

    protected:
        const RenderState& mRenderState;
    };

    size_assert(Blend, 0x10);


    class LogicOp
    {
    public:
        // Inlined
        explicit LogicOp(const RenderState& renderState) :
            isEnable(false),
            opCode(PICA_DATA_LOGIC_NOOP),
            mRenderState(renderState) {}

        // Inlined @ 0x0010E970
        // bit32* MakeCommand(bit32* command, bool isUpdateFBAccess = true) const;

    public:
        bool isEnable;
        PicaDataLogicOp opCode;

    protected:
        const RenderState& mRenderState;
    };

    size_assert(LogicOp, 0x8);


    class ShadowMap
    {
    public:
        // Inlined
        explicit ShadowMap(const RenderState& renderState) : 
            isEnable(false),
            isPerspective(true),
            zBias(0.0f),
            zScale(1.0f),
            penumbraScale(0.0f),
            penumbraBias(1.0f),
            mRenderState(renderState) {}

        // Address: 0x00113204
        bit32* MakeCommand(bit32* command, bool isUpdateFBAccess = true, bool isAddDummyCommand = true) const;

    public:
        bool isEnable;
        bool isPerspective;
        f32 zBias;
        f32 zScale;
        f32 penumbraScale;
        f32 penumbraBias;

    protected:
        const RenderState& mRenderState;
    };

    size_assert(ShadowMap, 0x18);


    class AlphaTest
    {
    public:
        // Inlined
        explicit AlphaTest(const RenderState& renderState) :
            isEnable(false),
            refValue(0),
            func(PICA_DATA_ALPHA_TEST_NEVER),
            mRenderState(renderState) {}

        // Address: 0x0048784C
        bit32* MakeCommand(bit32* command, bool isUpdateFBAccess = true) const;

    public:
        bool isEnable;
        u8 refValue;
        PicaDataAlphaTest func;

    protected:
        const RenderState& mRenderState;
    };

    size_assert(AlphaTest, 0x8);


    class StencilTest
    {
    public:
        // Inlined
        explicit StencilTest(const RenderState& renderState) :
            isEnable(false),
            maskOp(0xFF),
            func(PICA_DATA_STENCIL_TEST_ALWAYS),
            ref(0),
            mask(0xFF),
            opFail(PICA_DATA_STENCIL_OP_KEEP),
            opZFail(PICA_DATA_STENCIL_OP_KEEP),
            opZPass(PICA_DATA_STENCIL_OP_KEEP),
            mRenderState(renderState) {}

        // Inlined @ 0x0010E9E8
        //bit32* MakeCommand(bit32* command, bool isUpdateFBAccess = true) const;

    public:
        bool isEnable;
        bit8 maskOp;
        u8 _padding[2];
        PicaDataStencilTest func;
        bit32 ref;
        bit32 mask;
        PicaDataStencilOp opFail;
        PicaDataStencilOp opZFail;
        PicaDataStencilOp opZPass;

    protected:
        const RenderState& mRenderState;
    };

    size_assert(StencilTest, 0x18);


    enum ColorMask : u8
    {
        COLOR_MASK_R    = 1 << 0,
        COLOR_MASK_G    = 1 << 1,
        COLOR_MASK_B    = 1 << 2,
        COLOR_MASK_A    = 1 << 3, 
        COLOR_MASK_RGBA = COLOR_MASK_R | COLOR_MASK_G | COLOR_MASK_B | COLOR_MASK_A 
    };


    class DepthTest
    {
    public:
        // Inlined
        explicit DepthTest(const RenderState& renderState) :
            isEnable(true),
            isEnableWrite(true),
            func(PICA_DATA_DEPTH_TEST_LESS),
            mRenderState(renderState) {}

        // Address: 0x004878A4
        bit32* MakeCommand(bit32* command, bool isUpdateFBAccess = true) const;

    public:
        bool isEnable;
        bool isEnableWrite;
        PicaDataDepthTest func;

    protected:
        const RenderState& mRenderState;
    };

    size_assert(DepthTest, 0x8);


    class Culling
    {
    public:
        enum FrontFace : u8
        {
            FRONT_FACE_CW, 
            FRONT_FACE_CCW
        };

        enum CullFace : u8
        {
            CULL_FACE_FRONT,
            CULL_FACE_BACK
        };

    public:
        // Inlined
        explicit Culling(const RenderState& renderState) :
            isEnable(true),
            frontFace(FRONT_FACE_CCW),
            cullFace(CULL_FACE_BACK),
            mRenderState(renderState) {}

        // Address: 0x004877CC
        bit32* MakeCommand(bit32* command, bool isUpdateFBAccess = true) const;

    public:
        bool isEnable;
        FrontFace frontFace;
        CullFace cullFace;

    protected:
        const RenderState& mRenderState;
    };

    size_assert(Culling, 0x8);


    class WBuffer
    {
    public:
        // Inlined
        explicit WBuffer() :
            wScale(0.0f),
            isEnablePolygonOffset(false),
            polygonOffsetUnit(0.0f),
            depthRangeNear(0.0f),
            depthRangeFar(1.0f),
            depthRangeBit(24) {}
    
        // Address: 0x00112FE4
        bit32* MakeCommand(bit32* command) const;
    
    public:
        f32 wScale;
        bool isEnablePolygonOffset;
        f32 polygonOffsetUnit;
        f32 depthRangeNear;
        f32 depthRangeFar;
        u8 depthRangeBit;
    };

    size_assert(WBuffer, 0x18);


    class FBAccess
    {
    public:
        // Inlined
        explicit FBAccess(const RenderState& renderState) :
            mRenderState(renderState) {}
        
        // Address: 0x0011747C
        bit32* MakeCommand(bit32* command, bool isClearFrameBufferCache = true) const;

    protected:
        const RenderState& mRenderState;
    };

    size_assert(FBAccess, 0x4);

public:
    // Address: 0x0010BE20
    explicit RenderState();

    // Address: 0x0010E900
    bit32* MakeCommand(bit32* command, bool isClearFrameBufferCache = true) const;

    // Address: 0x00142DFC
    static bit32* MakeDisableCommand(bit32* command, bool isClearFrameBufferCache = true);

public:
    Blend blend;
    LogicOp logicOp;
    ShadowMap shadowMap;
    AlphaTest alphaTest;
    StencilTest stencilTest;
    ColorMask colorMask;
    DepthTest depthTest;
    Culling cullingTest;
    WBuffer wBuffer;
    FBAccess fbAccess;
};

size_assert(RenderState, 0x80);

} // namespace CTR
} // namespace gr
} // namespace nn

