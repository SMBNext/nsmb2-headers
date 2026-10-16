#pragma once

#include "sead/heap/seadDisposer.h"
#include "sead/seadPtrArray.h"
#include "env/EnvEffectBase.h"

// Size: 0x9C
class EnvEffectMgr
{
    // createInstance()                             Address: 0x0030C254
    // deleteInstance()                             Address: 0x0030C2CC
    // sInstance                                    Address: 0x005E73A0
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x0030C308
    // SingletonDisposer_::sStaticDisposer          Address: 0x005E73A4
    // SingletonDisposer_::vtbl                     Address: 0x005B5884
    SEAD_SINGLETON_DISPOSER(EnvEffectMgr);

public:
    // Address: 0x0030C33C
    void execute();

    // Address: 0x0030C3A4
    void insertEffect(EnvEffectBase* effect);

    // Address: 0x0030C3C8
    void unkA();

    // Address: 0x0030C448
    void unkB();

private:
    sead::FixedPtrArray<EnvEffectBase, 32> mEffects;
};

size_assert(EnvEffectMgr, 0x9C);