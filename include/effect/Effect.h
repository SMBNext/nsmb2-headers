#pragma once

#include "math/Mtx34.h"

#include "sys/Common.h"

#include "sead/ptcl/seadptcl.h"
#include "sead/seadRuntimeTypeInfo.h"

#include "effect/PtclParam.h"

#include "effect/EffectId.h"

// size: 0x40
class Effect
{
public:
    // Address: 0x001D0A24
    Effect();

    // Address: 0x001D07D4
    Effect(u32 effectId);

    // Address: 0x001D04C4
    void setEffectId(u32 effectId);

    // Address: 0x001D062C
    void setScale(const Vec2f& scale);

    // Address: 0x001D0694
    void setLoopInterval(f32 interval);

    // Address: 0x001D070C
    sead::ptcl::EmitterSet* getEmitterSet();

    // Address: 0x001D0740
    void remove();

    // Address: 0x001D0788
    void kill();

    // Address: 0x001D0838
    bool update(const Vec3f* position = nullptr, const Vec3i* rotation = nullptr, const Vec3f* scale = nullptr);

    // Address: 0x001D0970
    bool update(const Mtx34& matrix, bool matrixHasScale);

    // Address: 0x0029FB2C
    bool createEffect(u32 effectId, const Vec3f* position = nullptr, const Vec3i* rotation = nullptr, const Vec3f* scale = nullptr);

    // Address: 0x004974E4
    s32 getRuntimeUserData();

    // Address: 0x00497510
    bool isAlive();

    inline sead::ptcl::Handle& getHandle() { return mHandle; }
    inline PtclParam* getParam() { return mParamEntry; }

private:
    // Address: 0x001D0A44
    void _update();

    Mtx34 mMatrix;              // 0
    bool mMtxHasScale;          // 30
    sead::ptcl::Handle mHandle; // 34
    PtclParam* mParamEntry;     // 3C
};

// size: 0x5C
class LevelEffect : public Effect
{
public:
    // C1 Address: 0x003125A0
    LevelEffect();

    // D1 Address: 0x00312544
    ~LevelEffect();

    // Deleted
    virtual void vf0();

    // Deleted
    virtual void vf4();

    // GetRuntimeTypeInfo:                  0x004A31DC
    // GetRuntimeTypeInfoStatic::typeInfo:  0x00603984
    SEAD_RTTI_BASE(LevelEffect);

    inline void setActive(bool active) { mIsActive = active; }
    inline bool isActive() { return mIsActive; }

private:
    u32 _44;                    // 44
    sead::ListNode* mListNode;  // 48 - idk what list type this is
    u32 _4C;                    // 4C
    u32 _50;                    // 50
    sead::ListImpl* mEffects;   // 54
    s16 mEffectID;              // 58
    bool mIsActive;             // 5A
};

// size: 0x5C
class UnkEffectType : public LevelEffect
{
public:
    // C1 Address: 0x00237100
    UnkEffectType();

    // D1 Address: 0x00237118
    ~UnkEffectType();

    // Address: 0x00236E84
    void createEffect(u32 effectId, const Vec3f* position = nullptr, const Vec3i* rotation = nullptr, const Vec3f* scale = nullptr);

    // Address: 0x00236F10
    void createEffect(u32 effectId, const Mtx34& matrix, bool matrixHasScale);

    // Address: 0x00236FC0
    void update(const Vec3f* position = nullptr, const Vec3i* rotation = nullptr, const Vec3f* scale = nullptr);

    // Address: 0x00237060
    void update(const Mtx34& matrix, bool matrixHasScale);

    // GetRuntimeTypeInfo:                  0x0049C628
    // GetRuntimeTypeInfoStatic::typeInfo:  0x006035A4
    SEAD_RTTI_OVERRIDE(UnkEffectType, LevelEffect);
};