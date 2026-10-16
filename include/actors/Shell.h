#pragma once

#include "actors/ActorBase.h"
#include "actors/ActorUniqueID.h"
#include "actors/Carry.h"
#include "collider/ActorBgCollisionCheck.h"
#include "enemy/Enemy.h"
#include "gfx/GfxWrapper.h"
#include "state/FStateVirtualID.h"
#include "types.h"
#include "utility/Angle3.h"

// Size: 0x114C
class Shell : public Carry
{
    SEAD_RTTI_OVERRIDE(Shell, Carry);
public:

    enum class ShellState : u32
    {
        cShell          = 0x0,  // The Shell is a shell.
        cNormal         = 0x1,  // The Shell is out of the shell state (E.g. Koopa walking).

        cTogezoPaipo    = 0x2,  // The Shell is a "Paipo" (A spiny egg thrown by Lakitu).
        cPataJump       = 0x2,  // Jumping as a Patapata.
        
    };
    
public:
    Shell();

    Result onCreate() override;
    Result onDelete() override;
    bool preExecute() override;
    Result onExecute() override;
    void postExecute(Result execResult) override;

    void setCarryFall(ActorBase* actor, s32 a2) override;
    bool isSpinLiftUpEnable() override;
    void powActivated() override;
    void vf114() override;
    u32 vf11C() override;

    bool collisionHandlerActors(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    void collisionEnemy(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    void collisionPlayer(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionGroundPound(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionTanookiTail(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionShell(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;

    void fumiJumpSet(PlayerBase* player) override;
    void giveScore(PlayerBase* player) override;

    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(Shell, DieFall);

    void vf1D4() override;
    void reactFumiProc(ActorBase* other) override;
    void collisionPlayer_Awake(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    void collisionPlayer_Sleep(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;

    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(Shell, Carry);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(Shell, Sleep);

    // Creates the Shell model, returning a pointer to the `SkeletalModelWrapper`.
    virtual SkeletalModelWrapper* createShell();

    // Sets the Enemy to the turn state.
    virtual void setEnemyTurn();

    // Determines what state the Shell should change to after sleep ends.
    virtual void setAfterSleepState();

    // Returns `true` if the Shell should die as a shell.
    // Used to change `this->shellState` to `ShellState::cShell` in `initializeState_DieFall()`.
    virtual bool isDieShell();

    // Handles turning the Shell.
    // Returns `true` if the turn is complete.
    virtual bool turnProc();

    // Checks if the shell is currently sleeping, updating sleep-related timers.
    // Returns `true` if the Shell has woken up.
    virtual bool checkSleep();

    // Unknown. Called in `initializeState_DieFall()`.
    virtual bool vf224();

    // Tries to damage the `player` and returns `true` if the player was damaged.
    virtual bool setPlayerDamage(ActorBase* player);

    // Deleted.
    virtual void vf22C();

    // Returns `true` if a block hit should kill the Shell.
    virtual bool isBlockHitDeath();

    // Returns `true` if fumi attacks should be invalidated.
    virtual bool isFumiInvalid() const;

    // Creates effects used during `StateID_ShellSlide` (E.g. a Shell trail effect).
    virtual void slideEffect();

    DECLARE_STATE_VIRTUAL_ID_BASE(Shell, ShellSlide);       //
    DECLARE_STATE_VIRTUAL_ID_BASE(Shell, Wakeup);           //
    DECLARE_STATE_VIRTUAL_ID_BASE(Shell, WakeupTurn);       //
    DECLARE_STATE_VIRTUAL_ID_BASE(Shell, WakeupReverse);    //
    DECLARE_STATE_VIRTUAL_ID_BASE(Shell, Bound);            // 

    // Handles kick impact effects and handles transition into `StateID_ShellSlide`.
    // Gives the player who kicked the shell 200 points if `giveScore` is `true`.
    void setKickSlide(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck, bool giveScore);

    // Used to update model matrices for the Shell's model.
    void calcShellModel();

    // Smoothly rotates `this->mRotation.y` towards `targetY` by `step`.
    // Returns `true` when the target rotation is reached.
    bool smoothRotateY(s32 targetY, s32 step);

    // Flips the Shell upright if it is upside down.
    // Increments `this->mRotation.x` by `step` to be upright.
    // Returns `true` when the shell is upright and both `inAir` and `isUprightY` are `true`.
    bool flipUpright(s32 step, bool inAir, bool isUprightY);

    // Checks if the `player` is performing an infinite combo with the Shell.
    bool checkMugenCombo(PlayerBase* player);

    // Sets the speed of the Shell when dropped/thrown by `player`.
    void setSlideThrowSpeed(ActorBase* player, bool strongThrow);

    // Stops movement and resolves the position of the Shell to stop sliding.
    // Changes the state to `StateID_Sleep`.
    void stopSlide();

    // Checks if the shell should be culled based on the `cullFlags`.
    bool cullCheck(u32 cullFlags);

    // Draws the model for the Shell.
    void drawShell();

public:
    /* 0x107C */  ActorBgCollisionCheck::Sensor sensorAbove;            //
    /* 0x1088 */  ActorBgCollisionCheck::Sensor sensorBelow;            //
    /* 0x1094 */  ActorBgCollisionCheck::Sensor sensorAdjacent;         //
    /* 0x10A0 */  u32 _10A0;                                            //
    /* 0x10A4 */  u32 _10A4;                                            //
    /* 0x10A8 */  u32 _10A8;                                            //
    /* 0x10AC */  ActorCollisionCheck::CollisionData collisionData;     //
    /* 0x10D0 */  SkeletalModelWrapper* modelNormal;                    // Pointer to regular Shell model.
    /* 0x10D4 */  SkeletalModelWrapper* modelGold;                      // Pointer to the model used when the Shell is gold.
    /* 0x10D8 */  Vec3f spawnPosition;                                  // Position used when reading/writing persistent data.
    /* 0x10E4 */  Vec3f _10E4;                                          // Position used when spawning effects.
    /* 0x10F0 */  Angle3 wakeupShakeAngle3D;                            //
    /* 0x10FC */  Angle wakeupShakeAngle;                               //
    /* 0x1100 */  f32 mugenComboPositionX;                              // Pre-calculated X position used during infinite combo to keep the shell in place.
    /* 0x1104 */  ShellState shellState;                                // 0: Liftable, 1: Normal/Not Liftable, 2: Egg
    /* 0x1108 */  u16 sleepTimer;                                       // Timer used before waking up from sleep.
    /* 0x1108 */  u16 carryTimer;                                       // Timer used before waking up from carry.
    /* 0x110C */  bool isFlipped;                                       // True if the Shell is flipped upside down.
    /* 0x110D */  bool wasCarry;                                        // Set to true if the previous state was `StateID_Carry` when entering `StateID_ShellSlide`.
    /* 0x110E */  bool mugenComboActive;                                // True if the player is performing an infinite combo. Set to the result of `checkMugenCombo()`.
    /* 0x110F */  u8 _110F;                                             //
    /* 0x1110 */  f32 mugenComboSpeed;                                  // Accumulated speed during infinite combo.
    /* 0x1114 */  u8 _1114;                                             //
    /* 0x1115 */  u8 _1115;                                             //
    /* 0x1116 */  u8 _1116;                                             //
    /* 0x1117 */  u8 _1117;                                             //
    /* 0x1118 */  f32 carryZPos;                                        // Stores Z pos when entering carry state.
    /* 0x111C */  ActorUniqueID ignoredActor;                           // Actor that is currently being ignored by the shell's collision checks.
    /* 0x1120 */  u16 ignoreTimer;                                      // Timer used to delay re-enabling collision checks with the ignored actor.
    /* 0x1121 */
    /* 0x1122 */  
    /* 0x1124 */  u32 flipSubState;                                     // Sub-state used in `flipUpright()`. [0: Normal, 1: Flipping, 2: Falling to ground].
    /* 0x1128 */  s32 coinSpawnTimer;                                   // Delay timer used between coin spawns while gold.
    /* 0x112C */  u32 _112C;                                            //
    /* 0x1130 */  u8 _1130[4];                                          //
    /* 0x1130 */  s32 stompCounter;                                     // The number of times the shell has been stomped. Used to make the shell explode after reaching `22` if it or the player is gold.
    /* 0x1138 */  u8 _1138[4];                                          //
    /* 0x113C */  bool mugenComboEnabled;                               // True if an infinite combo is allowed to be performed with the Shell.
    /* 0x113D */  u8 _unk112D;                                          //
    /* 0x113E */  bool isGold;                                          // True if the Shell is currently gold.
    /* 0x113F */  bool isInWater;                                       // True if the Shell is currently in water.
    /* 0x1140 */  u8 _1140[4];                                          //
    /* 0x1144 */  ActorBgCollisionCheck::Sensor* prevSensorAbove;       // Used to save and restore the Shell's above sensor when entering `StateID_ShellSlide`.
    /* 0x1148 */  u8 _1148;                                             //
    /* 0x1149 */
    /* 0x114A */
    /* 0x114B */
};

size_assert(Shell, 0x114C);
