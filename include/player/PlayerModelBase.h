#pragma once

#include "gfx/AnimModel.h"
#include "player/PlayerEnum.h"
#include "sys/ResourceMgr.h"

class PlayerModelBase
{
public:
    virtual f32 getHitboxScaleMaybe();
    virtual void setTextureAnim(s32 animIdx) = 0;
    virtual bool setPersonalAnim(Resource *&resourceOut, sead::SafeString* animNameOut, AnimId animIdx, int unkFlag);
    virtual bool getTailAnimName(sead::SafeString* out, AnimId animIdx);            // returns matching Tail anim name for a given anim idx
    virtual bool getGoldBlockAnimName(sead::SafeString* out, AnimId animIdx);       // returns matching goldBlock stoop anim name for a given anim idx (has gold block hat)
    virtual bool getEndingAnimName(sead::SafeString* out, AnimId animIdx);          // returns matching ending anim name for a given anim idx (carrying peach)
    virtual void playBodyAnimPrimary(Resource *animRes, const sead::SafeString* animName, PlayPolicy playPolicy, f32 frameStep, f32 startFrame, f32 blendDuration);
    virtual void playBodyAnimSecondary(Resource *animRes, const sead::SafeString* animName, PlayPolicy playPolicy, f32 frameStep, f32 startFrame, f32 blendDuration);
    virtual void mapMismatchBodyBone();
    virtual void update();
    virtual ~PlayerModelBase();
    virtual s32 getBoneIdx(s32 boneId);
    virtual void setColorType(u8 colorType);
    virtual void setTanooki(int colorTextureIdx);
    virtual void setDepthValue(f32 depthValue);
    virtual void setSpecularColorScalar(f32 specularColorScalar);
    virtual void saveMaterialColors();
    virtual void setTargetLookRotation(Vec3i* targetRotation, f32 chaseSpeed);
    virtual void setLookRotation(Vec3i* lookRotation);
    virtual u32 getLookRotation();
    virtual void setLookMode(u8 lookMode);
    virtual void setTailTargetRotation(Vec3i* rotation);
    virtual void setPowerup(Powerup powerup);
    virtual void setAnimation(AnimId animIdx, f32 frameStep, f32 blendDuration, f32 startFrame);
    virtual void setBodyAnim(AnimId animIdx, f32 frameStep, f32 startFrame, f32 blendDuration);
    virtual void releaseBodyAnim(f32 blendDuration);
    virtual bool getJumpAnimName(sead::SafeString* outStr, int animIdx, int unkResetJumpAnimIdx);
    virtual void getBoneWorldTransformMatrix(Mtx34* out, s32 boneIdx);
    virtual void updateAnimations() = 0;
    virtual void draw();
    virtual void playBigEndColorAnim();
    virtual void stopBigColorAnim();
    virtual void setStarActive();
    virtual void setStarDisabled();
    virtual void setStoneActive();
    virtual void setStoneDisabled();
    virtual f32 getHitboxScaleByPowerup();
    virtual void setSoftLight();

    // Sets the frame of the primary skeletal anim.
    void setFrame(f32 frame);

    // Sets the player's base model matrix (baseMtxSRT).
    void setBaseMtx(const Mtx34* baseMtx);

    // Applies the current anim to the linked (carry / spin-lift parent) model.
    void setLinkAnim(f32 frameStep, f32 blendDuration, f32 footFrame);

    // Sets the frame-step of a skeletal anim slot; snapshots the frame when the direction reverses.
    void setSkeletalAnimStep(s32 skelAnimIdx, f32 step);

    // Picks a jump anim variant (0/1/2) via RNG, optionally weighted.
    void setJumpAnimRand(int weightedRng);

    // True when the current anim is at a footstep frame.
    bool isFootStepTiming();

    // Starts the carry (link) body anim with the given blend duration.
    void setCarryBodyAnim(f32 blendDuration);

    // Sets the frame-step on the primary (and secondary if blending) skeletal anim.
    void setSkelAnimIdxFrameStep(f32 step);

    // Sets the frame on the primary (and secondary if blending) skeletal anim.
    void setAnimFrame(f32 frame);

    inline void getBonePosition(Vec3f& out, s32 boneIdx)
    {
        Mtx34 mtx;
        getBoneWorldTransformMatrix(&mtx, boneIdx);

        mtx.rows[0][3] = ((mtx.rows[0][1] * 4.0) + (mtx.rows[0][2] * 4.0)) + (mtx.rows[0][3] + (mtx.rows[0][0] * -1.0));
        mtx.rows[1][3] = ((mtx.rows[1][1] * 4.0) + (mtx.rows[1][2] * 4.0)) + (mtx.rows[1][3] + (mtx.rows[1][0] * -1.0));
        mtx.rows[2][3] = ((mtx.rows[2][1] * 4.0) + (mtx.rows[2][2] * 4.0)) + (mtx.rows[2][3] + (mtx.rows[2][0] * -1.0));
        out = mtx.getTranslation();
    }

    /* 0x04 */  Resource* modelResource;
    /* 0x08 */  Resource* animResource;
    /* 0x0C */  AnimModelBase* bodyModel;
    /* 0x10 */  UnkSkeletalAnimHolder* unkSkeletalAnimHolder;
    /* 0x14 */  HeapAllocator allocator;
    /* 0x1C */  Powerup curPowerupId;
    /* 0x1E */  AnimId currAnimId;
    /* 0x20 */  AnimId prevAnimId;
    /* 0x24 */  void* linkPlayerModel;
    /* 0x28 */  Mtx34 baseMtxSRT;
    /* 0x58 */  Mtx34 baseMtxSR;
    /* 0x88 */  Vec3f headTopPos;
    /* 0x94 */  bool isLuigi;                        // alternatively playerId?
    /* 0x95 */  u8 colorType;
    /* 0x96 */  u8 colorTextureIdx;
    /* 0x97 */  u8 currTextureAnimIdx;
    /* 0x98 */  u32 stoopTimer;
    /* 0x9C */  f32 offsetY;
    /* 0xA0 */  u32 flags;                              // bitflag
    /* 0xA4 */  u32 currAnimFlags;
    /* 0xA8 */  u32 visibilityFlags;                 // seems to control visibility of stuff, may control other stuff too, see [PlayerRendererBaseBase::FlagMask] enum
    /* 0xAC */  u32 jumpAnimVariant;                     // maybe also other stuff... subAnimIdx?
};

size_assert(PlayerModelBase, 0x00B0);
