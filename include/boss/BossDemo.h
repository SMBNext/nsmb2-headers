#pragma once

#include "actors/ActorState.h"
#include "state/FStateVirtualID.h"

// Size: 0x1038
class BossDemo : public ActorState
{
    SEAD_RTTI_OVERRIDE(BossDemo, ActorState);
public:
    enum class KokoopaType : s32
    {
        cNone       = -1,
        cRoy        = 0,    // World 1
        cIggy       = 1,    // World 2
        cWendy      = 2,    // World 3
        cMorton     = 3,    // World 4
        cLemmy      = 4,    // World 8
        cLarry      = 5,    // World 7
        cLudwig     = 6     // World 5
    };

private:
    enum class BattleEdState : u8
    {
        cWaitPlayers    = 0,    // Waits for players to be grounded after grabbing the key.
        cWaitKey        = 1,    // Waits for the key to be created for the victory animation.
        cVictory        = 2,    // Plays the victory animation & music.
        cZeroTimer      = 3,    // Zeroes the timer.
        cRemoveUI       = 4,    // Hides UI & removes gold flower. Changes to `cOpenExit` if `this->hasExitSequence() == true` otherwise `cCreateEdActor`.
        cCoinRushBonus  = 5,    // Handles showing the 2x bonus for coin rush completion.
        cCoinRushTimer  = 6,    // Calculates CoinRush time bonus. Changes to `cRemoveUI`.
        cOpenExit       = 7,    // Opens the exit shutter.
        cInitCamera     = 8,    // Initializes the camera before a movement sequence.
        cPanCamera      = 9,    // Does a camera pan.
        cZoomCamera     = 10,   // Zooms the camera in.
        cCreateEdActor  = 11,   // Creates the ending actor.
        cWaitEdActor    = 12,   // Waits for the ending actor to complete. Changes to `cExitLevel` if `this->hasExitSequence() == true` otherwise `cMoveToExit`.
        cMoveToExit     = 13,   // Moves player to the exit. Skipped when `this->kokoopaType() == KokoopaType::cLudwig`.
        cExitLevel      = 14,   // Handles level exit transition.
    };

    enum class PlayerEnterState : u8
    {
        cWaitPlayers    = 0,    // Waits for a player to walk into the trigger zone.
        cWalkPlayers    = 1,    // Walks players to the target position.
        cWalkEnd        = 2,    // Clears flags for each player & adjusts volume for the sound player `PLAYER_SE_SYSTEM_EX`.
    };
    
    enum class PlayerExitState : u8
    {
        cPositionPlayers    = 0,    // Re-Positions players to be slightly out of frame to the left.
        cWalkPlayers        = 1,    // Walks players into frame.
        cWalkEnd            = 2,    // Plays an animation once the players are in position.
    };
    
public:
    BossDemo();

    Result onCreate() override;
    Result onDelete() override;
    Result onExecute() override;
    bool preDraw() override;

    DECLARE_STATE_VIRTUAL_ID_BASE(BossDemo, Ready);
    DECLARE_STATE_VIRTUAL_ID_BASE(BossDemo, BattleStDemo);
    DECLARE_STATE_VIRTUAL_ID_BASE(BossDemo, BattleIn);
    DECLARE_STATE_VIRTUAL_ID_BASE(BossDemo, BattleEdDemo);

    // Unknown.
    virtual bool vf13C() const;

    // Unknown.
    virtual bool vf140() const;

    // Kills actors based on their `ActorInfo` flags.
    // Called before the demo starts.
    virtual void killActors();

    // Unknown.
    virtual void vf148();

    // Called in `initializeState_Ready` and in `executeState_BattleIn` after `this->battleIn()` completes.
    virtual void vf14C();

    // Does the arena entrance demo sequence for the player.
    // Returns true when complete.
    virtual bool entranceDemo();

    // Called in `executeState_BattleIn` while the battle is still going.
    // Returns true once the battle is over.
    virtual bool doBattleIn();

    // Called before switching to `StateID_BattleStDemo` from `executeState_Ready`.
    // Returns true when complete.
    virtual bool preBattleStDemo();

    // Returns a pointer to the boss actor.
    virtual ActorBase* getBoss();

    // Returns a pointer to the ending actor.
    virtual ActorBase* getEndActor();

    // Called in `onCreate` before switching to `StateID_Ready`.
    virtual void initialize();

    // Returns true if the demo has an ending actor.
    virtual bool hasEndActor() const;

    // Creates the actor used for the ending sequence.
    virtual void createEndActor();

    // Returns the completion status of the ending actor.
    // Called from `executeState_BattleEdDemo` when `this->mBattleEdState` is `BattleEdState::cWaitEdActor`.
    virtual bool isEndActorFinished();

    // Related to updating player animations for battle ending sequence.
    // Called from `executeState_BattleEdDemo` when `this->mBattleEdState` is `BattleEdState::cWaitEdActor`.
    virtual void vf174();

    // Returns whether the player should walk to the exit during the ending sequence.
    // Called from `executeState_BattleEdDemo` when `this->mBattleEdState` is `BattleEdState::cWaitEdActor`.
    virtual bool hasExitSequence() const;

    // Closes the entrance shutter for the arena.
    virtual void closeEntranceShutter();

    // Returns true if the entrance shutter has finished closing.
    virtual bool entranceShutterClosed();

    // Opens the exit shutter for the arena.
    virtual void openExitShutter();

    // Unknown. `KokoopaBase` uses this to call `createEdActor()`.
    virtual void vf188();

    // Unknown.
    virtual void vf18C();

    // Changes the state to `StateID_BattleEdDemo`.
    virtual void startBattleEdDemo();

    // Returns the `KokoopaType` this demo is for.
    // Returns `KokoopaType::cNone` if demo is not a `KokoopaDemo`.
    virtual KokoopaType getKokoopaType() const;

    // Unknown. `KokoopaBase` uses this to call `createEdActor()`.
    virtual void vf198();

    // Walks the player into frame for the ending sequence.
    // Returns true when complete.
    bool movePlayerToExit();

    // Handles the player walk in sequence. Uses `this->mPlayerEnterState` as a sub-state.
    // Returns true when complete.
    bool doEntranceWalk(f32 distance);
    
protected:
    /* 0x0FE8 */  f32 _FE8;                             //
    /* 0x0FEC */  f32 _FEC;                             //
    /* 0x0FF0 */  f32 _FF0;                             //
    /* 0x0FF4 */  f32 _FF4;                             //
    /* 0x0FF8 */  u8 _FF8;                              //
    /* 0x0FF9 */  u8 _FF9;                              //
    /* 0x0FFA */  u8 mBattleInState;                    // Set to 0 in `initializeState_BattleIn`. Returned from `this->battleIn()`.
    /* 0x0FFB */  u8 mCanSpawnKeyRelated;               //
    /* 0x0FFC */  PlayerEnterState mPlayerEnterState;   // Sub-state used in `doEntranceWalk()`.
    /* 0x0FFD */  PlayerExitState mPlayerExitState;     // Sub-state used in `movePlayerToExit()`.
    /* 0x0FFE */  BattleEdState mBattleEdState;         // Sub-state used in `executeState_BattleEdDemo`.
    /* 0x0FFF */ 
    /* 0x1000 */  Vec3f exitShutterPosition;            // Used for tracking the position of the exit shutter.
    /* 0x100C */  s32 bossId;                           //
    /* 0x1010 */  ActorBase* mBossPtr;                  //
    /* 0x1014 */  u32 mLeadPlayerId;                    // The ID of the player who activated the trigger zone in `doEntranceWalk()`.
    /* 0x1018 */  u32 _1018;                            //
    /* 0x101C */  f32 _101C;                            //
    /* 0x1020 */  f32 _1020;                            //
    /* 0x1024 */  f32 _1024;                            //
    /* 0x1028 */  u8 _1028;                             //
    /* 0x1029 */  u8 _1029;                             //
    /* 0x102A */  u8 _102A;                             //
    /* 0x102B */ 
    /* 0x102C */  s32 mTimerA;                          // Used to delay sub-state transitions.
    /* 0x1030 */  s32 mTimerB;                          // Camera pan related
    /* 0x1034 */  u32 _1034;                            //
};

size_assert(BossDemo, 0x1038);
