#pragma once

#include "sead/heap/seadHeap.h"
#include "sead/gfx/seadColor.h"
#include "math/Vec.h"
#include "gfx/GL.h"


namespace sead {

class Framework                 // size: 0x28
{
public:
    virtual ~Framework();

    bool mReserveReset;         // 4
    void* mResetParameter;      // 8
    char mResetEvent[0x10];     // C    DelegateEvent
    void* mTaskMgr;             // 1C   TaskMgr
    void* mMethodTreeMgr;       // 20   MethodTreeMgr
    Heap* mMethodTreeMgrHeap;   // 24
};


class GameFramework : public Framework  // size: 0x48
{
public:
    enum DisplayState : u8
    {
        cDisplayState_Hide  = 0,
        cDisplayState_Ready = 1,
        cDisplayState_Show  = 2,
    };

    DisplayState mDisplayState; // 28
    u8 mCalcMeter[8];           // 2C   sead::MultiProcessMeterBar
    u8 mDrawMeter[8];           // 34   sead::MultiProcessMeterBar
    u8 mGPUMeter[8];            // 3C   sead::MultiProcessMeterBar
    void* mCheckerThread;       // 44   sead::Thread* typefed as sead::InfLoopCheckerThread*
};


class GameFrameworkCtrNw4c : public GameFramework   // size: 0x120
{
public:
    struct CreateArg
    {
        Vec2i top_fb_size;              // 0
        Vec2i btm_fb_size;              // 8
        Vec2i top_fb_offset;            // 10
        Vec2i btm_fb_offset;            // 18
        u32 wait_vblank;                // 20
        Color4f clear_color;            // 24
        u32 cmd_buf_size;               // 34
        u32 cmd_req_num;                // 38
        void* gfx_memory_mgr;           // 3C   sead::GfxMemoryMgrCtr
        u32 gfx_heap_size;              // 40
        GLenum display_format;          // 44
        void* exception;                // 48   sead::ExceptionScreenCtr
        u32 screen_shot_buffer_size;    // 4C
    };

    // TODO
    typedef u64 TickSpan;
    typedef u64 TickTime;

    inline void setClearColor(const sead::Color4f& color)
    {
        mArg.clear_color = color;
    }

    CreateArg mArg;                     // 48
    s32 mLastVSyncCount;                // 98
    TickSpan mFrameSpan;                // A0
    TickTime mLastFrameBegin;           // A8
    TickTime mLastVBlankBegin;          // B0
    GLuint mCmdlist;                    // B8
    GLuint mTopDispbuffers[2];          // C0
    GLuint mBtmDispbuffers[2];          // C8
    u8 mFrameBuffer[0x48];              // CC   nn::gr::CTR::FrameBuffer
    void* mTopFrameBuffer;              // 114  sead::FrameBufferCtr
    void* mBtmFrameBuffer;              // 118  sead::FrameBufferCtr
    s32 mCurrentDisplaybuffer;          // 11C
};


class DoubleCmdGameFrameworkCtrNw4c : public GameFrameworkCtrNw4c   // size: 0x154
{
public:
    GLuint mDoubleCmdlist[2];           // 120
    GLuint mTopTripleDispbuffers[3];    // 128
    GLuint mBtmTripleDispbuffers[3];    // 134
    s32 mCurrentCmdlist;                // 140
    s32 mInitialDrawCounter;            // 144
    TickTime mLastGPUEnd;               // 148
    bool mGPUMeterBegin;                // 150
};


class UlcdDoubleCmdGameFrameworkCtrNw4c : public DoubleCmdGameFrameworkCtrNw4c  // size: 0x160
{
public:
    GLuint mRightDispbuffers[3];        // 154
};

}
