#pragma once

#include "types.h"
#include "gfx/GL.h"


#ifdef __cplusplus
extern "C" {
#endif

#define GX_DISPLAY_UPPER            0x400
#define GX_DISPLAY_LOWER            0x401
#define GX_DISPLAY_BOTH             0x402
#define GX_DISPLAY_UPPER_3D         0x410

#define NN_GX_STATE_SHADERBINARY                            0x001
#define NN_GX_PROFILING_RESULT_BUFSIZE_VERTEX_CACHE         0x001
#define NN_GX_PROFILING_RESULT_BUFSIZE_FRAGMENT             0x001

#define NN_GX_STATE_SHADERPROGRAM                           0x002
#define NN_GX_PROFILING_RESULT_BUFSIZE_POLYGON              0x003

#define NN_GX_STATE_SHADERMODE                              0x004
#define NN_GX_PROFILING_RESULT_BUFSIZE_BUSY                 0x004

#define NN_GX_PROFILING_RESULT_BUFSIZE_VERTEX_SHADER0       0x005
#define NN_GX_PROFILING_RESULT_BUFSIZE_VERTEX_SHADER1       0x005
#define NN_GX_PROFILING_RESULT_BUFSIZE_VERTEX_SHADER2       0x005
#define NN_GX_PROFILING_RESULT_BUFSIZE_VERTEX_SHADER3       0x005

#define NN_GX_STATE_SHADERFLOAT                             0x008
#define NN_GX_STATE_VSUNIFORM                               0x010
#define NN_GX_PROFILING_RESULT_BUFSIZE_MEMORY_ACCESS        0x012
#define NN_GX_STATE_FSUNIFORM                               0x020
#define NN_GX_PROFILING_RESULT_BUFSIZE_INTERRUPT            0x030

#define NN_GX_STATE_LUT                                     0x040
#define NN_GX_STATE_TEXTURE                                 0x080

#define NN_GX_MEM_SYSTEM                                    0x100
#define NN_GX_STATE_FRAMEBUFFER                             0x100
#define NN_GX_MEM_TEXTURE                                   0x101
#define NN_GX_MEM_VERTEXBUFFER                              0x102
#define NN_GX_MEM_RENDERBUFFER                              0x103
#define NN_GX_MEM_DISPLAYBUFFER                             0x104
#define NN_GX_MEM_COMMANDBUFFER                             0x105

#define NN_GX_CMDLIST_RUN_MODE                              0x200
#define NN_GX_STATE_VERTEX                                  0x200
#define NN_GX_CMDLIST_IS_RUNNING                            0x201
#define NN_GX_CMDLIST_USED_BUFSIZE                          0x202
#define NN_GX_CMDLIST_USED_REQCOUNT                         0x203
#define NN_GX_CMDLIST_MAX_BUFSIZE                           0x204
#define NN_GX_CMDLIST_MAX_REQCOUNT                          0x205
#define NN_GX_CMDLIST_TOP_BUFADDR                           0x206
#define NN_GX_CMDLIST_BINDING                               0x207
#define NN_GX_CMDLIST_CURRENT_BUFADDR                       0x208
#define NN_GX_CMDLIST_RUN_BUFSIZE                           0x209
#define NN_GX_CMDLIST_RUN_REQCOUNT                          0x20A
#define NN_GX_CMDLIST_TOP_REQADDR                           0x20B
#define NN_GX_CMDLIST_NEXT_REQTYPE                          0x20C
#define NN_GX_CMDLIST_NEXT_REQINFO                          0x20D
#define NN_GX_CMDLIST_HW_STATE                              0x20E
#define NN_GX_CMDLIST_GAS_UPDATE                            0x20F

#define NN_GX_CMDLIST_SERIAL_RUN                            0x300
#define NN_GX_CMDLIST_PARALLEL_RUN                          0x301
#define NN_GX_CMDLIST_SYNC_RUN                              0x302
#define NN_GX_CMDLIST_REQTYPE_DMA                           0x310
#define NN_GX_CMDLIST_REQTYPE_RUN3D                         0x311
#define NN_GX_CMDLIST_REQTYPE_FILLMEM                       0x312
#define NN_GX_CMDLIST_REQTYPE_POSTTRANS                     0x313
#define NN_GX_CMDLIST_REQTYPE_COPYTEX                       0x314

#define NN_GX_DISPLAY0                                      0x400
#define NN_GX_DISPLAY0_LEFT                                 0x400
#define NN_GX_STATE_TRIOFFSET                               0x400
#define NN_GX_DISPLAY1                                      0x401
#define NN_GX_DISPLAY_BOTH                                  0x402
#define NN_GX_DISPLAY0_EXT                                  0x410
#define NN_GX_DISPLAY0_RIGHT                                0x410

#define NN_GX_ANTIALIASE_NOT_USED                           0x500
#define NN_GX_ANTIALIASE_2x1                                0x501
#define NN_GX_ANTIALIASE_2x2                                0x502

#define NN_GX_DISPLAYBUFFER_ADDRESS                         0x600
#define NN_GX_DISPLAYBUFFER_FORMAT                          0x601
#define NN_GX_DISPLAYBUFFER_WIDTH                           0x602
#define NN_GX_DISPLAYBUFFER_HEIGHT                          0x603

#define NN_GX_DISPLAYMODE_NORMAL                            0x700
#define NN_GX_DISPLAYMODE_RESERVED                          0x701
#define NN_GX_DISPLAYMODE_STEREO                            0x702

#define NN_GX_STATE_FBACCESS                                0x800
#define NN_GX_CMDGEN_MODE_CONDITIONAL                       0x800
#define NN_GX_CMDGEN_MODE_UNCONDITIONAL                     0x801

#define NN_GX_PROFILING_BUSY                                0x900
#define NN_GX_PROFILING_INTERRUPT                           0x901
#define NN_GX_PROFILING_VERTEX_SHADER0                      0x902
#define NN_GX_PROFILING_VERTEX_SHADER1                      0x903
#define NN_GX_PROFILING_VERTEX_SHADER2                      0x904
#define NN_GX_PROFILING_VERTEX_SHADER3                      0x905
#define NN_GX_PROFILING_VERTEX_CACHE                        0x906
#define NN_GX_PROFILING_POLYGON                             0x907
#define NN_GX_PROFILING_FRAGMENT                            0x908
#define NN_GX_PROFILING_MEMORY_ACCESS                       0x909
#define NN_GX_PROFILING_BUSY_SAMPLING_TIME                  0x910
#define NN_GX_PROFILING_BUSY_SAMPLING_COUNT                 0x911
#define NN_GX_PROFILING_INTERRUPT_ENABLE                    0x912
#define NN_GX_PROFILING_INTERRUPT_TRIGGER                   0x913
#define NN_GX_PROFILING_INTERRUPT_IS_LOGGING                0x914
#define NN_GX_PROFILING_BUSY_SAMPLING_TIME_MICRO_SECOND     0x915
#define NN_GX_PROFILING_BUSY_SAMPLING_TIME_NANO_SECOND      0x916

#define NN_GX_STATE_SCISSOR                                 0x1000
#define NN_GX_STATE_OTHERS                                  0x2000
#define NN_GX_STATE_ALL                                     0x3FFF

#define NN_GX_MEM_FCRAM                                     0x10000
#define NN_GX_MEM_VRAMA                                     0x20000
#define NN_GX_MEM_VRAMB                                     0x30000


void nngxActiveDisplay(u32 display);
void nngxSwapBuffers(u32 display);
void nngxBindDisplaybuffer(GLuint buffer);
void nngxGetDisplaybufferParameteri(u32 param, u32* out);
void nngxAddBlockImageCopyCommand(void* srcaddr, u32 srcunit, u32 srcinterval, void* dstaddr, u32 dstunit, u32 dstinterval, u32 totalsize);
void nngxUpdateState(GLbitfield statemask);
void nngxValidateState(GLbitfield statemask, GLboolean drawelements);
void nngxWaitCmdlistDone();

#define NN_GX_DISPLAY0_WIDTH    240
#define NN_GX_DISPLAY0_HEIGHT   400
#define NN_GX_DISPLAY1_WIDTH    240
#define NN_GX_DISPLAY1_HEIGHT   320


enum PicaDataDepthTest : u8
{
    PICA_DATA_DEPTH_TEST_NEVER    = 0x0,
    PICA_DATA_DEPTH_TEST_ALWAYS   = 0x1,
    PICA_DATA_DEPTH_TEST_EQUAL    = 0x2,
    PICA_DATA_DEPTH_TEST_NOTEQUAL = 0x3,
    PICA_DATA_DEPTH_TEST_LESS     = 0x4,
    PICA_DATA_DEPTH_TEST_LEQUAL   = 0x5,
    PICA_DATA_DEPTH_TEST_GREATER  = 0x6,
    PICA_DATA_DEPTH_TEST_GEQUAL   = 0x7
};

enum PicaDataBlendEquation : u8
{
    PICA_DATA_BLEND_EQUATION_ADD                = 0x0,
    PICA_DATA_BLEND_EQUATION_SUBTRACT           = 0x1,
    PICA_DATA_BLEND_EQUATION_REVERSE_SUBTRACT   = 0x2,
    PICA_DATA_BLEND_EQUATION_MIN                = 0x3,
    PICA_DATA_BLEND_EQUATION_MAX                = 0x4
};

enum PicaDataBlendFunc : u8
{
    PICA_DATA_BLEND_FUNC_ZERO                     = 0x0,
    PICA_DATA_BLEND_FUNC_ONE                      = 0x1,
    PICA_DATA_BLEND_FUNC_SRC_COLOR                = 0x2,
    PICA_DATA_BLEND_FUNC_ONE_MINUS_SRC_COLOR      = 0x3,
    PICA_DATA_BLEND_FUNC_DST_COLOR                = 0x4,
    PICA_DATA_BLEND_FUNC_ONE_MINUS_DST_COLOR      = 0x5,
    PICA_DATA_BLEND_FUNC_SRC_ALPHA                = 0x6,
    PICA_DATA_BLEND_FUNC_ONE_MINUS_SRC_ALPHA      = 0x7,
    PICA_DATA_BLEND_FUNC_DST_ALPHA                = 0x8,
    PICA_DATA_BLEND_FUNC_ONE_MINUS_DST_ALPHA      = 0x9,
    PICA_DATA_BLEND_FUNC_CONSTANT_COLOR           = 0xA,
    PICA_DATA_BLEND_FUNC_ONE_MINUS_CONSTANT_COLOR = 0xB,
    PICA_DATA_BLEND_FUNC_CONSTANT_ALPHA           = 0xC,
    PICA_DATA_BLEND_FUNC_ONE_MINUS_CONSTANT_ALPHA = 0xD,
    PICA_DATA_BLEND_FUNC_SRC_ALPHA_SATURATE       = 0xE
};

enum PicaDataAlphaTest : u8
{
    PICA_DATA_ALPHA_TEST_NEVER    = 0x0,
    PICA_DATA_ALPHA_TEST_ALWAYS   = 0x1,
    PICA_DATA_ALPHA_TEST_EQUAL    = 0x2,
    PICA_DATA_ALPHA_TEST_NOTEQUAL = 0x3,
    PICA_DATA_ALPHA_TEST_LESS     = 0x4,
    PICA_DATA_ALPHA_TEST_LEQUAL   = 0x5,
    PICA_DATA_ALPHA_TEST_GREATER  = 0x6,
    PICA_DATA_ALPHA_TEST_GEQUAL   = 0x7
};

enum PicaDataStencilTest : u8
{
    PICA_DATA_STENCIL_TEST_NEVER    = 0x0,
    PICA_DATA_STENCIL_TEST_ALWAYS   = 0x1,
    PICA_DATA_STENCIL_TEST_EQUAL    = 0x2,
    PICA_DATA_STENCIL_TEST_NOTEQUAL = 0x3,
    PICA_DATA_STENCIL_TEST_LESS     = 0x4,
    PICA_DATA_STENCIL_TEST_LEQUAL   = 0x5,
    PICA_DATA_STENCIL_TEST_GREATER  = 0x6,
    PICA_DATA_STENCIL_TEST_GEQUAL   = 0x7
};

enum PicaDataStencilOp : u8
{
    PICA_DATA_STENCIL_OP_KEEP      = 0x0,
    PICA_DATA_STENCIL_OP_ZERO      = 0x1,
    PICA_DATA_STENCIL_OP_REPLACE   = 0x2,
    PICA_DATA_STENCIL_OP_INCR      = 0x3,
    PICA_DATA_STENCIL_OP_DECR      = 0x4,
    PICA_DATA_STENCIL_OP_INVERT    = 0x5,
    PICA_DATA_STENCIL_OP_INCR_WRAP = 0x6,
    PICA_DATA_STENCIL_OP_DECR_WRAP = 0x7
};

enum PicaDataLogicOp : u8
{
    PICA_DATA_LOGIC_CLEAR                   = 0x0,
    PICA_DATA_LOGIC_AND                     = 0x1,
    PICA_DATA_LOGIC_AND_REVERSE             = 0x2,
    PICA_DATA_LOGIC_COPY                    = 0x3,
    PICA_DATA_LOGIC_SET                     = 0x4,
    PICA_DATA_LOGIC_COPY_INVERTED           = 0x5,
    PICA_DATA_LOGIC_NOOP                    = 0x6,
    PICA_DATA_LOGIC_INVERT                  = 0x7,
    PICA_DATA_LOGIC_NAND                    = 0x8,
    PICA_DATA_LOGIC_OR                      = 0x9,
    PICA_DATA_LOGIC_NOR                     = 0xA,
    PICA_DATA_LOGIC_XOR                     = 0xB,
    PICA_DATA_LOGIC_EQUIV                   = 0xC,
    PICA_DATA_LOGIC_AND_INVERTED            = 0xD,
    PICA_DATA_LOGIC_OR_REVERSE              = 0xE,
    PICA_DATA_LOGIC_OR_INVERTED             = 0xF
};

enum PicaDataVertexAttrType : u8
{
    PICA_DATA_SIZE_1_BYTE           = 0x0,
    PICA_DATA_SIZE_1_UNSIGNED_BYTE  = 0x1,
    PICA_DATA_SIZE_1_SHORT          = 0x2,
    PICA_DATA_SIZE_1_FLOAT          = 0x3,
    PICA_DATA_SIZE_2_BYTE           = 0x4,
    PICA_DATA_SIZE_2_UNSIGNED_BYTE  = 0x5,
    PICA_DATA_SIZE_2_SHORT          = 0x6,
    PICA_DATA_SIZE_2_FLOAT          = 0x7,
    PICA_DATA_SIZE_3_BYTE           = 0x8,
    PICA_DATA_SIZE_3_UNSIGNED_BYTE  = 0x9,
    PICA_DATA_SIZE_3_SHORT          = 0xA,
    PICA_DATA_SIZE_3_FLOAT          = 0xB,
    PICA_DATA_SIZE_4_BYTE           = 0xC,
    PICA_DATA_SIZE_4_UNSIGNED_BYTE  = 0xD,
    PICA_DATA_SIZE_4_SHORT          = 0xE,
    PICA_DATA_SIZE_4_FLOAT          = 0xF
};


#ifdef __cplusplus
}
#endif
