#pragma once

#include "types.h"
#include "nw/ut/Color.h"
#include "math/Mtx34.h"
#include "math/Vec.h"
#include "sead/seadSafeString.h"
#include "sead/heap/seadHeap.h"

namespace sead {
namespace ptcl {

class PtclSystem;
class EmitterSet;

class ResourceEmitterSet
{
public:
    void* setData; // sead::ptcl::EmitterSetData
    void* tblData; // sead::ptcl::EmitterTblData
    s32 numEmitter;
    u32 userData;
    void* setDataROM; // sead::ptcl::EmitterSetData
    void* tblDataROM; // sead::ptcl::EmitterTblData
    s32 numEmitterROM;
    u32 userDataROM;
    const char* setName;
    bool isShowDetail;
};


class PtclResource
{
public:
    void* vtable;  // TODO
    PtclSystem* mSystem;
    s32 mResourceID;
    void* mHeader; // sead::ptcl::HeaderData
    char* mNameTbl;
    const void* mTextureTbl;
    ResourceEmitterSet* mResEmitterSetTbl;
    FixedSafeString<128> _1C;        ///< "Icon = LAYOUT , Order = %d"
};


class PtclSystem
{
public:
    Heap* mHeap;
    PtclResource** mResource; ///< indexed by buffer location
    u8 _8[4];
    void* mPtclEditor; // sead::ptcl::PtclEditor
    EmitterSet* mEmitterSet;
    u32 mNumEmitterSet;
    u8 _18[4];
    u8 _1C[1024];
    void* mEmitters;  // sead::ptcl::EmitterInstance 
    void* mPtcls;     // sead::ptcl::PtclInstance 
    void* mStripes;   // sead::ptcl::PtclStripe
    u8 _428[1024];
    u8 _828;
    u8 _829[3];                           /// probably padding
    s32 mCurEmitterIx;
    s32 mCurPtclIx;
    u32 _834;
    s32 mCurStripeIx;
    s32 mNumEmitterData;
    s32 mNumPtclData;
    s32 mNumStripe;
    s32 mNumEmitterDataMask;
    s32 mNumPtclDataMask;
    s32 mNumStripeMask;
    u32 _854;
    u32 _858;
    u32 _85C;
    u32 _860;
    s32 mNumEmitterSetCalc;
    s32 mNumFreeEmitter;
    s32 mNumEmittedPtcl;
    u32 _870;
    u32 _874;
    void* mPtclRenderer; // sead::ptcl::PtclRenderer
    Mtx34 _87C; // sead::Matrix34f
    u32 _8AC;
    u32 _8B0;
    u8 _8B4[4];
    s64 mLastTick;
    f32 _8C0;
    void* _8C4;                           /// function ptr?
    void* _8C8;                           /// function ptr?
    void* _8CC;                           /// function ptr?
};


class EmitterSet
{
public:
    PtclSystem *mSystem;            // 0 - sead::ptcl::PtclSystem*
    s32 mNumEmitter;                // 4
    s32 mNumEmitterFirst;           // 8
    u32 mEmitterCreateID;           // C
    void *mInstance[16];            // 10 - sead::ptcl::EmitterInstance*
    u8 _10[160];                    // 50
    u32 mResourceID;                // F0 
    u32 mEmitterSetID;              // F4
    u32 mRuntimeUserData;           // F8
    s32 mGroupID;                   // FC
    Mtx34 mSRT;                     // 100
    Mtx34 mRT;                      // 130
    Vec3f mAutoScalcScale;           // 160
    Vec2f mParticleScale;            // 16C
    Vec2f mEmissionParticleScale;    // 174
    Vec2f mParticleScaleForCalc;     // 17C
    Vec3f mEmitterScale;             // 184
    nw::ut::FloatColor mColor;      // 190
    u8 _1A0[4];                     // 1A0
    f32 mRandomVel;                 // 1A4
    u8 _1A8[16];                    // 1A8
    Vec3f mDirectional;              // 1B8
    u32 _1C4;                       // 1C4 some kind of flag/mask
    u8 _1C8[9];                     // 1C8
    bool mIsSetDirectional;         // 1D1
};

class Handle
{
public:
    EmitterSet *mEmitterSet;
    u32 mCreateID;
};

}
}