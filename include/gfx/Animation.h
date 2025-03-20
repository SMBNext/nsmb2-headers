#pragma once

#include "types.h"
#include "sys/Allocator.h"

enum class PlayPolicy : u8
{
    One_Time = 0,
    Loop     = 1,
};

// Size: 0x18
// Vtable: 0x0059E344
class AnimBase
{
public:
    virtual ~AnimBase();

    // Address: 0x001B549C
    virtual void* animEvaluator();                                     // nw::gfx::BaseAnimEvaluator*

    // Address: 0x00495CE4
    virtual const void* animEvaluator() const;                         // const nw::gfx::BaseAnimEvaluator*

    // Address: 0x001B54A4
    virtual void vf10(nw::anim::res::ResAnim resAnim);                 //
    
    virtual void cleanup();                                            // Deleted
    virtual void vf18(nw::anim::res::ResAnim animData, s32 a3) = 0;    //
    virtual bool tryBind() = 0;                                        //

    // Address: 0x001B271C
    void setPlayPolicy(PlayPolicy playPolicy);

    // Address: 0x001B2770
    void unkA(nw::anim::res::ResAnim animData);

    // Address: 0x001B281C
    void setFrameStep(f32 step);

    // Address: 0x001B284C
    void setFrame(f32 frame);

    // Address: 0x001B548C
    void updateFrame();

    // Address: 0x004955AC
    bool isAtFrame(f32 frame);

    // Address: 0x004956EC
    f32 getEndFrame();

    // Address: 0x00495704
    f32 getStartFrame();

    // Address: 0x00495728
    bool isDone();

    // Address: 0x004957E8
    f32 getFrameStep();

    // Address: 0x0049580C
    f32 getCurrentFrame();

private:
    PlayPolicy mPlayPolicy;         //
    void* mAnimEvaluator;           // nw::gfx::BaseAnimEvaluator
    HeapAllocator mAllocator;       //
    SkeletalModelWrapper* mModel;   //
};

size_assert(AnimBase, 0x18);