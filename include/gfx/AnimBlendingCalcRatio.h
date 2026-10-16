#pragma once

#include "types.h"
#include "sead/seadVector.h"

#include "gfx/Model.h"

// Size: 0x2C
// Vtable: 0x005BCC14
class AnimBlendingCalcRatio
{
public:
    // Address C1: 0x00345454
    AnimBlendingCalcRatio(s32 boneNumMax);

    // Address D0: 0x00345538
    // Address D2: 0x0034557C
    virtual ~AnimBlendingCalcRatio();

    // Address: 0x003453C8
    void calc();

    // Address: 0x00345374
    void set(f32 blendDuration);

    // Address: 0x0034508C
    void applyTo(sead::Matrix34<f32>* outBoneRT, const sead::Matrix34<f32>* boneRT, sead::Vector3f* outBoneScale, const sead::Vector3f boneScale, s32 boneIdx);

    // Address: 0x00344FB0
    void applyTo(SkeletalModelWrapper* model);

private:
    sead::Vector3f* mBoneTrans;     // 0x04 - sead::Buffer<Vector3f> of mCount
    void* mBoneRot;                 // 0x08 - sead::Buffer<Quatf> of mCount
    sead::Vector3f* mBoneScale;     // 0x0C - sead::Buffer<Vector3f> of mCount
    s32 mBoneNumMax;                // 0x10 - 
    f32 mEasingState;               // 0x14 - Recursive state used to generate blend ratios
    f32 mCounter;                   // 0x18 - 
    f32 mInvDuration;               // 0x1C - 
    f32 mRatioA;                    // 0x20 - 
    f32 mRatioB;                    // 0x24 - 
    bool mIsFramesPrepared;         // 0x28 - 
    bool mIsActive;                 // 0x29 - 
};

size_assert(AnimBlendingCalcRatio, 0x2C);
