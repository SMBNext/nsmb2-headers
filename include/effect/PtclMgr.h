#pragma once

#include "types.h"
#include "sys/Allocator.h"
#include "sead/heap/seadDisposer.h"
#include "sead/seadCamera.h"
#include "sead/ptcl/seadptcl.h"
#include "sead/gfx/seadColor.h"

#include "PtclParamMgr.h"

struct EffectRelated_SomeStruct
{
    void* _0; // 0x0
    void* _4; // 0x4
    void* _8; // 0x8
    void* _C; // 0xC
};

class PtclMgr
{
    // createInstance()                             Address: 0x003F4688
    // deleteInstance()                             Address: 
    // sInstance                                    Address: 0x005E6190
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x003F4810
    // SingletonDisposer_::sStaticDisposer          Address: 0x005E6194
    // SingletonDisposer_::vtbl                     Address: 0x005C949C
    SEAD_SINGLETON_DISPOSER(PtclMgr);

public:
    // Address: 0x003F526C
    virtual ~PtclMgr();

    // Address: 0x003F4110
    void init();

    // Address: 0x003F437C
    void unk_3F437C(s32 unkA, void* unkB, void* unkC);

    // Address: 0x003F4430
    void draw(s32 unkA, sead::Camera* camera);
    
    // Address: 0x003F4788
    void unload();

    // Address: 0x003F4860
    bool createEmitterSet(sead::ptcl::Handle* pHandle, const Mtx34& matrixRT, u32 paramId);

    // Address: 0x003F4908
    void unk_3F4908();

    // Address: 0x003F4AC8
    void execute();

    // Address: 0x003F4B60
    void setupForArea(sead::Heap* heap);

    // Address: 0x003F51A0
    void reset();

    // Address: 0x004ABA24
    PtclParam* getParam(u32 id) const;

    static constexpr u32 cNumEffectBuckets = 16;

private:
    sead::ptcl::PtclSystem* mPtclSystem;    // 0x14
    PtclParamMgr* mPtclParamMgr;            // 0x18
    sead::ListImpl mEffectsList;            // 0x1C
    void* mCommonEffectMgr;                 // 0x28
    s32 mPlayerId;                          // 0x2C
    sead::Color4f mTintColor;                // 0x30
    u8 _40;                                 // 0x40
    bool mShouldDoUpdate;                   // 0x41
    u8 _42;                                 // 0x42
    u32 _44;                                // 0x44
    u32 _48;                                // 0x48
    void* _4C;                              // 0x4C
    void* _50;                              // 0x50
    void* _mIBO;                            // 0x54
    u32 _58;                                // 0x58
    u32* mCalcData[cNumEffectBuckets];      // 0x5C
    u32 mCalcSize[cNumEffectBuckets];       // 0x9C
    u32* mStripeData[cNumEffectBuckets];    // 0xDC
    u32 mStripeSize[cNumEffectBuckets];     // 0x11C
};

size_assert(PtclMgr, 0x15C);