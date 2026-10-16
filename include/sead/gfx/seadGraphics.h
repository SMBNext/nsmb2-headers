#pragma once

#include "types.h"

#include "sead/heap/seadDisposer.h"

#include "nn/gx.h"

namespace sead {

class Graphics : public sead::IDisposer 
{
public:
    enum DevicePosture : u8
    {
        DevicePosture_Same = 0x0,
        DevicePosture_RotateRight = 0x1,
        DevicePosture_RotateLeft = 0x2,
        DevicePosture_RotateHalfAround = 0x3,
        DevicePosture_FlipXY = 0x3,
        DevicePosture_FlipX = 0x4,
        DevicePosture_Invalid = 0x4,
        DevicePosture_FlipY = 0x5,
    };

    enum DepthFunc : u32
    {
        cDepthFunc_Never        = PICA_DATA_DEPTH_TEST_NEVER,
        cDepthFunc_Less         = PICA_DATA_DEPTH_TEST_LESS,
        cDepthFunc_Equal        = PICA_DATA_DEPTH_TEST_EQUAL,
        cDepthFunc_LessEqual    = PICA_DATA_DEPTH_TEST_LEQUAL,
        cDepthFunc_Greater      = PICA_DATA_DEPTH_TEST_GREATER,
        cDepthFunc_NotEqual     = PICA_DATA_DEPTH_TEST_NOTEQUAL,
        cDepthFunc_GreaterEqual = PICA_DATA_DEPTH_TEST_GEQUAL,
        cDepthFunc_Always       = PICA_DATA_DEPTH_TEST_ALWAYS,
    };

    enum CullingMode : u32
    {
        cCullingMode_Front = 0,
        cCullingMode_Back  = 1,
        cCullingMode_None  = 2,
        cCullingMode_All   = 3
    };

    enum BlendFactor : u32
    {
        cBlendFactor_Zero             = PICA_DATA_BLEND_FUNC_ZERO,
        cBlendFactor_One              = PICA_DATA_BLEND_FUNC_ONE,
        cBlendFactor_SrcColor         = PICA_DATA_BLEND_FUNC_SRC_COLOR,
        cBlendFactor_InvSrcColor      = PICA_DATA_BLEND_FUNC_ONE_MINUS_SRC_COLOR,
        cBlendFactor_SrcAlpha         = PICA_DATA_BLEND_FUNC_SRC_ALPHA,
        cBlendFactor_InvSrcAlpha      = PICA_DATA_BLEND_FUNC_ONE_MINUS_SRC_ALPHA,
        cBlendFactor_DstAlpha         = PICA_DATA_BLEND_FUNC_DST_ALPHA,
        cBlendFactor_InvDstAlpha      = PICA_DATA_BLEND_FUNC_ONE_MINUS_DST_ALPHA,
        cBlendFactor_DstColor         = PICA_DATA_BLEND_FUNC_DST_COLOR,
        cBlendFactor_InvDstColor      = PICA_DATA_BLEND_FUNC_ONE_MINUS_DST_COLOR,
        cBlendFactor_SrcAlphaSaturate = PICA_DATA_BLEND_FUNC_SRC_ALPHA_SATURATE,
        cBlendFactor_ConstantColor    = PICA_DATA_BLEND_FUNC_CONSTANT_COLOR,
        cBlendFactor_InvConstantColor = PICA_DATA_BLEND_FUNC_ONE_MINUS_CONSTANT_COLOR,
        cBlendFactor_ConstantAlpha    = PICA_DATA_BLEND_FUNC_CONSTANT_ALPHA,
        cBlendFactor_InvConstantAlpha = PICA_DATA_BLEND_FUNC_ONE_MINUS_CONSTANT_ALPHA
    };

    enum BlendEquation : u32
    {
        cBlendEquation_Add        = PICA_DATA_BLEND_EQUATION_ADD,
        cBlendEquation_Sub        = PICA_DATA_BLEND_EQUATION_SUBTRACT,
        cBlendEquation_Min        = PICA_DATA_BLEND_EQUATION_MIN,
        cBlendEquation_Max        = PICA_DATA_BLEND_EQUATION_MAX,
        cBlendEquation_ReverseSub = PICA_DATA_BLEND_EQUATION_REVERSE_SUBTRACT
    };

    enum AlphaFunc : u32
    {
        cAlphaFunc_Never        = PICA_DATA_ALPHA_TEST_NEVER,
        cAlphaFunc_Less         = PICA_DATA_ALPHA_TEST_LESS,
        cAlphaFunc_Equal        = PICA_DATA_ALPHA_TEST_EQUAL,
        cAlphaFunc_LessEqual    = PICA_DATA_ALPHA_TEST_LEQUAL,
        cAlphaFunc_Greater      = PICA_DATA_ALPHA_TEST_GREATER,
        cAlphaFunc_NotEqual     = PICA_DATA_ALPHA_TEST_NOTEQUAL,
        cAlphaFunc_GreaterEqual = PICA_DATA_ALPHA_TEST_GEQUAL,
        cAlphaFunc_Always       = PICA_DATA_ALPHA_TEST_ALWAYS
    };

    enum StencilFunc : u32
    {
        cStencilFunc_Never        = PICA_DATA_STENCIL_TEST_NEVER,
        cStencilFunc_Less         = PICA_DATA_STENCIL_TEST_LESS,
        cStencilFunc_Equal        = PICA_DATA_STENCIL_TEST_EQUAL,
        cStencilFunc_LessEqual    = PICA_DATA_STENCIL_TEST_LEQUAL,
        cStencilFunc_Greater      = PICA_DATA_STENCIL_TEST_GREATER,
        cStencilFunc_NotEqual     = PICA_DATA_STENCIL_TEST_NOTEQUAL,
        cStencilFunc_GreaterEqual = PICA_DATA_STENCIL_TEST_GEQUAL,
        cStencilFunc_Always       = PICA_DATA_STENCIL_TEST_ALWAYS
    };

    enum StencilOp : u32
    {
        cStencilOp_Keep          = PICA_DATA_STENCIL_OP_KEEP,
        cStencilOp_Zero          = PICA_DATA_STENCIL_OP_ZERO,
        cStencilOp_Replace       = PICA_DATA_STENCIL_OP_REPLACE,
        cStencilOp_Increment     = PICA_DATA_STENCIL_OP_INCR,
        cStencilOp_Decrement     = PICA_DATA_STENCIL_OP_DECR,
        cStencilOp_Invert        = PICA_DATA_STENCIL_OP_INVERT,
        cStencilOp_IncrementWrap = PICA_DATA_STENCIL_OP_INCR_WRAP,
        cStencilOp_DecrementWrap = PICA_DATA_STENCIL_OP_DECR_WRAP
    };


    // 005F3D98
    static Graphics* sInstance;

    // 005F3D9C
    static DevicePosture sDefaultDevicePosture;
    // 005F3DA0
    static f32 sDefaultDeviceZScale;
    // 005F3DA4
    static f32 sDefaultDeviceZOffset;
};


} // namespace sead
