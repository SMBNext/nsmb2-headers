#pragma once

#include "gfx/Renderer.h"
#include "math/Mtx34.h"
#include "player/PlayerEnum.h"
#include "player/PlayerModelBase.h"
#include "gfx/AnimBlendingCalcRatio.h"
#include "nw/gfx/res/ResTexture.h"

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
    f32 offsetNormal;
    f32 offsetSmall;
    f32 offsetTailBody;
    f32 offsetGold;
    f32 offsetBig;
};

class PlayerModel : public PlayerModelBase      // Size: 0x2F0
{
public:
    struct PlayerAnimationEntry
    {
        /* 0x00 */  sead::SafeString animationName;
        /* 0x08 */  PlayPolicy playPolicy;
        /* 0x0C */  f32 frameStep;
        /* 0x10 */  f32 blendDuration;
        /* 0x14 */  u8 textureAnimIdx;
        /* 0x15 */  u8 tailAnimIdx;
        /* 0x16 */  u8 _16;
        /* 0x17 */  u8 _17;
        /* 0x18 */  f32 startFrame;
        /* 0x1C */  u32 flags;
    };

    struct PlayerTxAnimationEntry
    {
        sead::SafeString animationName;
        PlayPolicy playPolicy;
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

    enum RenderMode : u8
    {
        RENDER_MODE_NORMAL      = 0x0,
        RENDER_MODE_SMALL       = 0x1,
        RENDER_MODE_TANOOKI     = 0x2,
        RENDER_MODE_GOLD        = 0x3,
        RENDER_MODE_MEGA        = 0x4,

        NUM_RENDER_MODES
    };

    virtual f32 getHitboxScaleMaybe() override;
    virtual void setTextureAnim(s32 animIdx) override;
    virtual bool setPersonalAnim(Resource *&resourceOut, sead::SafeString* animNameOut, AnimId animIdx, s32 unkFlag) override;
    virtual bool getTailAnimName(sead::SafeString* out, AnimId animIdx) override;
    virtual bool getGoldBlockAnimName(sead::SafeString* out, AnimId animIdx) override; 
    virtual bool getEndingAnimName(sead::SafeString* out, AnimId animIdx) override;
    virtual void playBodyAnimPrimary(Resource *animRes, const sead::SafeString* animName, PlayPolicy playPolicy, f32 frameStep, f32 startFrame, f32 blendDuration) override;
    virtual void playBodyAnimSecondary(Resource *animRes, const sead::SafeString* animName, PlayPolicy playPolicy, f32 frameStep, f32 startFrame, f32 blendDuration) override;
    virtual void mapMismatchBodyBone() override;
    virtual void update() override;
    virtual ~PlayerModel() override;
    virtual s32 getBoneIdx(s32 boneId) override;
    virtual void setColorType(u8 colorType) override;
    virtual void setTanooki(int colorTextureIdx) override;
    virtual void setDepthValue(f32 depthValue) override;
    virtual void setSpecularColorScalar(f32 specularColorScalar) override;
    virtual void saveMaterialColors() override;
    virtual void setTargetLookRotation(Vec3i* targetRotation, f32 chaseSpeed) override;
    virtual void setLookRotation(Vec3i* lookRotation) override;
    virtual u32 getLookRotation() override;
    virtual void setLookMode(u8 lookMode) override;
    virtual void setTailTargetRotation(Vec3i* rotation) override;
    virtual void setPowerup(Powerup powerup) override;
    virtual void setAnimation(AnimId animIdx, f32 frameStep, f32 blendDuration, f32 startFrame) override;
    virtual void updateAnimations() override;
    virtual void draw() override;
    virtual void playBigEndColorAnim() override;
    virtual void stopBigColorAnim() override;
    virtual void setStarActive() override;
    virtual void setStarDisabled() override;
    virtual void setStoneActive() override;
    virtual void setStoneDisabled() override;
    virtual f32 getHitboxScaleByPowerup() override;
    virtual void setSoftLight() override;

    virtual void vf9C();    // Deleted
    virtual void setRenderMode(RenderMode renderMode);

    void initBoneIndicies();
    void setTransformFrame(f32 frame);      // 0x002438A8
    void updateRenderMode();
    void stopLookLR();
    bool animIsDone();

    // Plays the look-left/right material anims on a model at the given frame.
    void setLookLRFrame(AnimModelBase* model, f32 frame);

    // Plays the looping star color material anim at a start frame.
    void playStarColorAnim(AnimModelBase* model, f32 startFrame);

    // Sets the tail model's skeletal anim from the TailAnims table.
    void setTailAnim(s32 tailAnimIdx, f32 frameStep, f32 frame, f32 blendDuration);

    // Uninitializes the model's anim allocator.
    void cleanupSomething();

    // Plays the one-shot star color reset material anim.
    void stopStarColorAnim(AnimModelBase* model);

    // Chases the look rotation toward its target and applies it to the head bone; handles the look-LR face override.
    void updateLookRotation();

    // Toggles visibility of a mesh (selected by bone idx) on a model.
    void toggleMeshVisibility(AnimModelBase* model, u32 meshIdx);

    // Swaps the body/tail textures for the tanooki skins.
    void setTanookiTextures(int textureIdx);

    // Replaces a model's textures and colors with stone.
    void setTextureToStone(AnimModelBase* model);

    // Restores saved material colors/textures and stops the look-LR anim.
    void restoreMaterialColors(AnimModelBase* model);

    // Re-applies material anim resets to all models.
    void syncMaterialAnims();

    inline void setAnimation(AnimId animId)
    {
        const PlayerAnimationEntry& animEntry = animationEntries[u32(animId)];
        setAnimation(animId, animEntry.frameStep, animEntry.blendDuration, animEntry.startFrame);
    }

    inline static const PlayerAnimationEntry& getAnimEntry(AnimId animId)
    {
        return animationEntries[u32(animId)];
    }

    inline Resource* getAnimResource(AnimId animId)
    {
        return animResource;
    }

    /* 0xB0 */  PlayerResources* resources;                         //
    /* 0xB4 */  Resource* bigModelResource;                         //
    /* 0xB8 */  AnimModel<0, 4, 1>* models[5];                      // AnimModel<0,4,1> [0: Normal, 1: Small, 2: Tanooki, 3: Gold, 4: modelMega] (these are always loaded and this->mBodyModel is swapped out for one of these pointers)
    /* 0xCC */  UnkSkeletalAnimHolder* unkSkeletalAnimHolders[5];   //
    /* 0xE0 */  s32 boneIdxs[22];                                   // same order as 0x0061ACF0
    /* 0x138 */ f32 savedMatColor0[6];                              //
    /* 0x150 */ f32 savedMatColor1[6];                              //
    /* 0x168 */ sead::FixedSafeString<32> matTextureNames[5];       //
    /* 0x244 */ AnimModel<0, 1, 0>* tailModel;                      // AnimModel<0,1,0>
    /* 0x248 */ RenderMode prevRenderMode;                          // used when determining which model to use
    /* 0x249 */ RenderMode curRenderMode;                           //
    /* 0x24C */ AnimBlendingCalcRatio blendCalc;                    // max bone count of 22
    /* 0x278 */ AnimBlendingCalcRatio tailBlendCalc;                // max bone count of 5
    /* 0x2A4 */ u8 curTailAnimIdx;                                  //
    /* 0x2A8 */ Vec3i lookRotation;                                 //
    /* 0x2B4 */ Vec3i lookRotationTarget;                           //
    /* 0x2C0 */ f32 lookRotationSpeed;                              //
    /* 0x2C4 */ u8 lookMode;                                        //
    /* 0x2C8 */ u32 tailRotationX;                                  //
    /* 0x2CC */ u32 tailRotationXTarget;                            //
    /* 0x2D0 */ u32 unused;                                         //
    /* 0x2D4 */ Vec3f hitBoxScaleMaybe;                             //
    /* 0x2E0 */ f32 specularColorScalar;                            //
    /* 0x2E4 */ u8 txTransformResetDone;                            //
    /* 0x2E5 */ u8 megaStarAnimActive;                              //
    /* 0x2E6 */ u8 extraMatAnimResetDone;                           //
    /* 0x2E7 */ u8 lookLRFaceOverride;                              //
    /* 0x2E8 */ u8 stopTailRotation;                                //
    /* 0x2F9 */ u8 _2F9[3];                                         //
    /* 0x2EC */ Resource* resAnimLuigi;                             //

    static const RenderMode powerupToRenderMode[];
    static const PlayerAnimationEntry animationEntries[];
};


class MarioModel : public PlayerModel
{
public:
    enum ColorType : u8
    {
        COLOR_TYPE_INVALID = 0x0,
        COLOR_TYPE_NORMAL = 0x1,
        COLOR_TYPE_FIRE_FLOWER = 0x2,
    };

    virtual f32 getHitboxScaleMaybe() override;
    virtual void setTextureAnim(s32 animIdx) override;
    virtual bool setPersonalAnim(Resource *&resourceOut, sead::SafeString* animNameOut, AnimId animIdx, s32 unkFlag) override;
    virtual void update() override;
    virtual ~MarioModel() override;
    virtual void setColorType(u8 colorType) override;
    virtual void setTanooki(int colorTextureIdx) override;
    virtual void updateAnimations() override;
    virtual void draw() override;
    virtual void setRenderMode(RenderMode renderMode) override;

    static const u32 size;

    // Writes a bone's world translation to `translationOut`.
    void getBoneTranslation(Vec3f* translationOut, s32 boneIdx);

    // True if the primary skeletal anim is at the given frame.
    bool modelIsAtFrame(f32 frame);

    // Returns the current frame of the primary skeletal anim.
    f32 getCurrentUnkFrame();

    // Returns the end frame of the primary skeletal anim.
    f32 getEndFrame();
};

size_assert(PlayerModel::PlayerAnimationEntry, 0x20);


class PlayerModelMgr
{
public:
    PlayerModelMgr(bool isLuigi);
    virtual ~PlayerModelMgr();

    void setAnimation(AnimId animIdx, f32 startFrame);
    void setAnimation(AnimId animIdx, f32 blendDuration, f32 startFrame);
    inline void setAnimation(AnimId animId) { model->setAnimation(animId); }

    MarioModel* model;
};

size_assert(PlayerModelMgr, 0x8);
