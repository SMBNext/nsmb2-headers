#pragma once

#include "actors/Shell.h"

// Size: 0x11B8
class TogezoBase : public Shell
{
    SEAD_RTTI_OVERRIDE(TogezoBase, Shell);
public:
    TogezoBase();

    Result onCreate() override;
    Result onDelete() override;
    Result onExecute() override;
    Result onDraw() override;

    void powActivated() override;
    void vf114() override;
    bool damagePlayer(PlayerBase* player) override;
    bool collisionSlide(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionTanookiTail(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;

    SkeletalModelWrapper* createShell() override;
    void setEnemyTurn() override;
    void setAfterSleepState() override;
    bool isDieShell() override;
    bool turnProc() override;
    bool setPlayerDamage(ActorBase* player) override;
    bool isBlockHitDeath() override;
    bool isFumiInvalid() const override;

    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(TogezoBase, Wakeup);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(TogezoBase, WakeupTurn);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(TogezoBase, WakeupReverse);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(TogezoBase, Bound);

    // Initializes the Togezo. Is called from `onCreate()`.
    virtual void initialize();

    // Returns `true` if cull checks are allowed.
    virtual bool isCullCheckOk() const;

    // 
    virtual void vf280();

    // Deleted.
    virtual void vf284();

    // Deleted.
    virtual void vf288();
    
    // Returns `true` if the Togezo is allowed to react to BGM.
    virtual bool isBGMReactOk();

    DECLARE_STATE_VIRTUAL_ID_BASE(TogezoBase, 340);     // Unused?
    DECLARE_STATE_VIRTUAL_ID_BASE(TogezoBase, 341);     // Unused?

    DECLARE_STATE_ID(TogezoBase, Walk);             //
    DECLARE_STATE_ID(TogezoBase, 337);              //
    DECLARE_STATE_ID(TogezoBase, Change_Paipo);     //
    DECLARE_STATE_ID(TogezoBase, Change_Togezo);    //
    DECLARE_STATE_ID(TogezoBase, Turn);             //
    DECLARE_STATE_ID(TogezoBase, Paipo);            //
    
    // 
    void sub_20D1E0();

    // Creates the various models for the TogezoBase.
    void createModel();

    // Handles rolling movement when in the Paipo state.
    void paipoRolling();

    // Calculates the model matrix for the Paipo model.
    void calcPaipoModel();

    // Calculates the model matrix for the Togezo model.
    void calcTogezoModel();

    // Sets the anim for `mModelTogezo` to the walk anim.
    void setAnimWalk();

    // Sets-up `this->mCollisionCheck` with `this->mCollisionData` and calls `this->addCollisionCheck()`.
    void setupCollisionCheck();

    // Unknown. Is empty.
    // Called from `ReverseTogezo::executeState_ShellSlide()`.
    void sub_20E3B0();

    // Sets the collision sensors for when `this->mShellState` is `ShellState::cPaipo`.
    void setCollisionPaipo();

    // Sets the collision sensors for when `this->mShellState` is `ShellState::cNormal`.
    void setCollisionTogezo();

    // Creates an effect and spawns a coin at the Togezo's position.
    // Used when gold ring is activated to create a death effect.
    void effectDieGold();

    // Returns the step value used to increment rotation when turning.
    void getTurnStep() const;

    // Returns the X movement speed of the Togezo for the given `direction`.
    void getMovementSpeed(u8 direction) const;

public:
    void setScale();

public:
    /* 0x114C */  Resource* resource;                   //
    /* 0x1150 */  HeapAllocator allocator;              //
    /* 0x1158 */  AnimModelBase* modelTogezo;           //
    /* 0x115C */  Model* modelShell;                    //
    /* 0x1160 */  Model* modelPaipo;                    //
    /* 0x1164 */  u32 paipoRollSpeed;                   // 
    /* 0x1168 */  f32 _1168;                            //
    /* 0x116C */  bool disableModelDraw;                // 
    /* 0x116D */  bool paipoTouchedGround;              // True if Paipo form has touched the ground
    /* 0x116E */  u8 paipoDirection;                    // The direction Paipo is moving (0: Left, 1: Right)
    /* 0x116F */  u8 _116F;                             //
    /* 0x1170 */  f32 _1170;                            //
    /* 0x1174 */  f32 _1174;                            //
    /* 0x1178 */  u32 _1178;                            //
    /* 0x117C */  f32 _117C;                            //
    /* 0x1180 */  f32 _1180;                            //
    /* 0x1184 */  u8 _1184;                             //
    /* 0x1185 */  u8 _1185;                             //
    /* 0x1186 */  u8 _1186;                             //
    /* 0x1187 */  u8 _1187;                             //
    /* 0x1188 */  u32 _1188;                            //
    /* 0x118C */  u32 _118C;                            //
    /* 0x1190 */  bool mSmallBottomSensor;              // nybble 8 bit 1
    /* 0x1191 */
    /* 0x1192 */
    /* 0x1193 */
    /* 0x1194 */  f32 _1194;                            //
    /* 0x1198 */  f32 _1198;                            //
    /* 0x119C */  f32 _119C;                            //
    /* 0x11A0 */  f32 _11A0;                            //
    /* 0x11A4 */  u8 _11A4[4];                          // unk
    /* 0x11A8 */  u32 _11A8;                            //
    /* 0x11AC */  ActorBase *_11AC;                     // init to this
    /* 0x11B0 */  s32 _11B0;                            //
    /* 0x11B4 */  u8 _11B4;                             //
    /* 0x11B5 */
    /* 0x11B6 */
    /* 0x11B7 */
};

size_assert(TogezoBase, 0x11B8);
