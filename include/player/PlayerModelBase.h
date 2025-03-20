#pragma once

#include "gfx/AnimModel.h"
#include "player/PlayerEnum.h"
#include "sys/ResourceMgr.h"

class PlayerModelBase
{
public:
    virtual f32* vf0();
    virtual void setTextureAnim(s32 animIdx);
    virtual bool vf8(Resource *resourceOut, sead::SafeString* animNameOut, s32 animIdx, int a4);
    virtual bool getTailAnimName(sead::SafeString* out, AnimId animIdx);            // returns matching Tail anim name for a given anim idx
    virtual bool getGoldBlockAnimName(sead::SafeString* out, AnimId animIdx);       // returns matching goldBlock stoop anim name for a given anim idx (has gold block hat)
    virtual bool getEndingAnimName(sead::SafeString* out, AnimId animIdx);          // returns matching ending anim name for a given anim idx (carrying peach)
    virtual void vf18(Resource *animRes, const sead::SafeString* animName, PlayPolicy playPolicy, f32 frameStep, f32 frame, f32 a7);
    virtual void vf1C(Resource *animRes, const sead::SafeString* animName, PlayPolicy playPolicy, f32 frameStep, f32 frame, f32 a7);
    virtual void vf20();
    virtual void update();
    virtual ~PlayerModelBase();
    virtual s32 getBoneIdx(s32 boneId);
    virtual void vf34(int a2);                             // related to setting powerup id
    virtual void vf38(int a2);
    virtual void vf3C(f32 a2);
    virtual void vf40(f32 a2);
    virtual void vf44();
    virtual void vf48(Vec2f* a2, f32 a3);
    virtual void vf4C(int* a2);
    virtual u32 vf50();
    virtual void vf54(u8 a2);
    virtual void vf58(int* a2);
    virtual void setPowerup(Powerup powerupId);
    virtual void setAnimation(s32 animIdx, f32 frameStep, f32 startFrame, f32 a3);
    virtual void vf64();
    virtual void vf68(f32 a2);
    virtual bool vf6C(sead::SafeString* out, int a2, int a3);
    virtual void getBoneWorldTransformMatrix(Mtx34* out, s32 boneIdx);
    virtual void vf74();
    virtual void draw();
    virtual void playBigEndColorAnim();
    virtual void vf80();
    virtual void setStarActive();
    virtual void setStarDisabled();
    virtual void setStoneActive();
    virtual void setStoneDisabled();
    virtual f32 vf94();
    virtual void applyEnvLight();

    Resource* modelResource;
    Resource* animResource;
    AnimModelBase* bodyModel;
    void* _10;                           // this is something related to animations
    HeapAllocator allocator;
    Powerup currentPowerupId;
    AnimId animId;
    AnimId animId2;                      // idk what this is for
    void* _24;
    Mtx34 _28;
    Mtx34 _58;
    Vec3f _88;
    bool isLuigi;                        // alternatively playerId?
    u8 _95;
    u8 _96;
    u8 _97;
    u32 _98;
    f32 _9C;
    u32 _A0;                              // bitflag
    u32 _A4;
    u32 flags;                           // seems to control visibility of stuff, may control other stuff too, see [PlayerRendererBaseBase::FlagMask] enum
    u32 jumpAnimIdx;                     // maybe also other stuff... subAnimIdx?
};

size_assert(PlayerModelBase, 0x00B0);

