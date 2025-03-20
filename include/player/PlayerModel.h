#pragma once

#include "gfx/Renderer.h"
#include "math/Mtx34.h"
#include "player/PlayerModelBase.h"


struct PlayerResources
{
    sead::SafeString resName;
    sead::SafeString resNameBig;
    sead::SafeString resNameAnim;
    sead::SafeString modelNameNormal;
    sead::SafeString modelNameSmall;
    sead::SafeString modelNameTailBody;
    sead::SafeString modelNameGold;
    sead::SafeString modelNameBig;
    sead::SafeString modelNameTail;
    f32 _48;
    f32 _4C;
    f32 _50;
    f32 _54;
    f32 _58;
};


class MarioModel_24C
{
public:
    void *vtable;
    Vec3f *_4;                   // array of vec3 with length of mCount
    u32 *_8;                    // array of unk type (size = 0x10) of mCount
    Vec3f *_C;                   // array of vec3 with length of mCount
    u32 count;
    f32 _14;
    f32 _18;
    f32 _1C;
    f32 _20;
    f32 _24;
    u8 _28;
    u8 _29;
};


class PlayerModel : public PlayerModelBase
{
public:
    struct PlayerTxAnimationEntry
    {
        sead::SafeString animationName;
        PlayPolicy playPolicy;     // this gets treated like it's 4 bytes not 1....
        f32 frameStep;
    };

    struct PlayerTailAnimationEntry
    {
        sead::SafeString mAnimationName;
        PlayPolicy mPlayPolicy;
        u8 _9;
        u8 _A;
        u8 _B;
    };

    virtual void vf9C();
    virtual void setRenderMode(RenderMode renderMode);

    PlayerResources* resources;
    u32 _B4;
    AnimModelBase* models[5];               // AnimModel<0,4,1> [0: Normal, 1: Small, 2: Tanooki, 3: Gold, 4: modelMega] (these are always loaded and this->mBodyModel is swapped out for one of these pointers)
    void* unkSkeletalAnimHolders[5];        // probably aligns with above
    s32 boneIdxs[22];                       // same order as 0x0061ACF0
    u8 _138[48];                            // unk
    sead::FixedSafeString<32> _168[5];
    AnimModelBase* tailModel;                   // AnimModel<0,1,0>
    RenderMode prevRenderMode;              // these are used when determining which model to use etc
    RenderMode curRenderMode;
    MarioModel_24C _24C;                    // inited with count of 0x16
    MarioModel_24C _278;                    // inited with count of 0x5
    u8 _2A4;
    u32 _2A8;
    u32 _2AC;
    u32 _2B0;
    Vec3i _2B4;
    f32 _2C0;
    u8 _2C4;
    u32 _2C8;
    u32 _2CC;
    u32 _2D0;
    f32 _2D4;
    f32 _2D8;
    f32 _2DC;
    f32 _2E0;
    u8 _2E4;
    u8 _2E5;
    u8 _2E6;
    u8 _2E7;
    u8 _2E8;
    u8 _2F9[3];
    Resource* resAnimLuigi;
};

class PlayerModelMgr
{
public:
    PlayerModelMgr(bool isLuigi);
    virtual ~PlayerModelMgr();

    void setAnimation(u32 id, f32 unk);
    void setAnimation(u32 id, f32 unk1, f32 unk2);

    PlayerModel* model;
};


class MarioModel : public PlayerModel
{
};

size_assert(MarioModel, 0x2F0);
size_assert(PlayerModelMgr, 0x8);
