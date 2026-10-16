#pragma once

#include "actors/Shell.h"
#include "effect/Effect.h"

// Size: 0x1210
class Nokonoko : public Shell
{
    SEAD_RTTI_OVERRIDE(Nokonoko, Shell);
public:
    enum class NokoType : u32
    {
        cGreen,     // A green Nokonoko.
        cRed,       // A red Nokonoko.
    };

    enum class DanceMove : u32
    {
        cDance1,    //
        cDance2,    //
        cDance3,    //
    };
    
public:
    Nokonoko();
    virtual ~Nokonoko();

    Result onCreate() override;
    Result onDelete() override;
    bool preExecute() override;
    Result onExecute() override;
    Result onDraw() override;

    bool damagePlayer(PlayerBase* player) override;
    void collisionEnemy(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionTanookiTail(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;

    void initializeState_Sleep() override;
    void executeState_Sleep() override;
    void finalizeState_Sleep() override;

    SkeletalModelWrapper* createShell() override;
    void setEnemyTurn() override;
    void setAfterSleepState() override;
    bool isDieShell() override;
    bool turnProc() override;
    void slideEffect() override;

    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(Nokonoko, Wakeup);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(Nokonoko, WakeupTurn);

    // Deleted.
    virtual void vf278();
    
    // Sets up the initial state of the Nokonoko after creation.
    virtual void setInitialState();

    // Performs a dance with the specified move.
    virtual void danceWithMove(DanceMove move);

    // Calculates and updates `this->mModelNoko` and `this->mModelNokoGold`.
    virtual void calcModel();

    // Handles turning away from the `player` after collision.
    virtual void playerDamageTurn(ActorBase* player);

    DECLARE_STATE_ID(Nokonoko, Walk);
    DECLARE_STATE_ID(Nokonoko, Turn);
    DECLARE_STATE_ID(Nokonoko, 2E5);
    DECLARE_STATE_ID(Nokonoko, BgmDance);
    DECLARE_STATE_ID(Nokonoko, BgmDanceEd);

    // Returns true if there is a ledge in front of the Nokonoko.
    bool checkLedge();

    // Creates the model for the Nokonoko.
    void createModel();

    // Sets the animation for the shell model.
    void setAnimShell(const sead::SafeString& animName, PlayPolicy policy, f32 speed);

    // Calculates the draw matrix for `this->mModelNoko`.
    // Does not update the model.
    void calcModelNoko();

    // Syncs the animation state between normal and gold models.
    // Syncs `this->mModelNoko` with `this->mModelNokoGold` and `this->mModelShell` with `this->mModelShellGold`.
    void syncModelGold();

    // Sets the animation for the body model.
    void setAnimBody(const sead::SafeString& animName, PlayPolicy policy, f32 speed);

    // Processes Bg collision for the Nokonoko.
    void processBgCollision();

    // Returns true if the Nokonoko is in a state where it can dance.
    bool canDance() const;

private:
    /* 0x114C */  Resource* mResNoko;                       // Resource for the Nokonoko model.
    /* 0x1150 */  Resource* mResShell;                      // Resource for the shell model.
    /* 0x1154 */  u8 _unk1154[4];                           //
    /* 0x1158 */  HeapAllocator mAllocator;                 //
    /* 0x1160 */  AnimModelBase* mModelNoko;                // The model for the Nokonoko.
    /* 0x1164 */  AnimModelBase* mModelNokoGold;            // The model for the Nokonoko while gold.
    /* 0x1168 */  AnimModelBase* mModelShell;               // The model for the shell.
    /* 0x116C */  AnimModelBase* mModelShellGold;           // The model for the shell while gold.
    /* 0x1170 */  Vec3f mOriginPos;                         // The position the Nokonoko is spawned at.
    /* 0x117C */  f32 mPositionOffsetZ;                     // 
    /* 0x1180 */  NokoType mNokoType;                       // The type of Nokonoko this is.
    /* 0x1184 */  DanceMove mDanceMove;                     // The current dance move.
    /* 0x1188 */  u32 mDanceTimer;                          // Timer used for dance moves.
    /* 0x118C */  u8 _118C[4];                              // Unknown
    /* 0x1190 */  s32 _1190;                                // Unknown timer.
    /* 0x1194 */  Angle mBgmDanceRotSpeed;                  // The rotation speed for the BGM dance.
    /* 0x1198 */  u8 _1198;                                 //
    /* 0x1199 */  u8 mColliderType;                         //
    /* 0x119A */  u8 _119A;                                 //
    /* 0x119B */ 
    /* 0x119C */  u32 _119C;                                //
    /* 0x11A0 */  s32 mGoldChangeTimer;                     // Timer used when transitioning between normal and gold.
    /* 0x11A4 */  s32 mModelIdx;                            // The index of the model in the model manager.
    /* 0x11A8 */  Angle mGoldChangeRotSpeed;                // Rotation speed used when transitioning between normal and gold.
    /* 0x11AC */  u32 _11AC;                                //
    /* 0x11B0 */  LevelEffect mEffect;                      //
    /* 0x120C */  Resource* mResPata;                       // Resource for the Patapata model.
};

size_assert(Nokonoko, 0x1210);
