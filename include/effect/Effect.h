#pragma once

#include "math/Mtx34.h"

#include "sys/Common.h"

#include "sead/seadRuntimeTypeInfo.h"

struct EffectParam      // size: 0x28
{
    u32 emitterSetId;       // 0
    f32 scale;              // 4
    Vec3f positionOffset;    // 8
    ColorF32 tintColor;     // 14
    u32 flags;              // 24
};


class Effect     // size: 0x40
{
public:
    Effect();
    Effect(u32 id);

    void setEffectId(u32 id);
    void update(const Vec3f* position = nullptr, const Vec3i* rotation = nullptr, const Vec3f* scale = nullptr);
    void remove();

    bool isAlive();

    Mtx34 mtx;                  // 0
    bool mMtxHasScale;          // 30
    void* mHandleEmitterSet;    // 34
    u32 mHandleCreateID;        // 38
    EffectParam* paramEntry;    // 3C
};


class ScopedEffect : public Effect          // size: 0x5C
{
public:
    ScopedEffect();
    ~ScopedEffect();                // Calls remove()

    virtual void vf0();                     // deleted
    virtual void vf4();                     // deleted
    
    SEAD_RTTI_BASE(ScopedEffect);

    void createEffect(u32 id, const Vec3f* position = nullptr, const Vec3i* rotation = nullptr, const Vec3f* scale = nullptr);


    u32 _44;
    u32 _48;
    u32 _4C;
    u32 _50;        // Vec2 probably
    u32 _54;        // ^
    s16 effectID;
    bool mIsActive;
};

class UnkEffectType : public ScopedEffect          // size: 0x5C
{
public:
    UnkEffectType();

    SEAD_RTTI_OVERRIDE(UnkEffectType, ScopedEffect);

};