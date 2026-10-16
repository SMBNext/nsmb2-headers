#pragma once

#include "enemy/Nokonoko.h"
#include "gfx/GfxWrapper.h"
#include "state/FStateID.h"
#include "types.h"

// Size: 0x1240
class Patapata : public Nokonoko
{
    SEAD_RTTI_OVERRIDE(Patapata, Nokonoko);
public:

    enum class FlightPhase : u32
    {
        cFlying,    // The Patapata is flying normally.
        cBreaking,  // The Patapata is breaking to turn.
        cTurning    // The Patapata is turning around.
    };
    
public:
    Patapata();
    virtual ~Patapata();

    Result onDelete() override;
    bool preExecute() override;
    Result onDraw() override;

    void collisionEnemy(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    void doQuakeBounce() override;
    void setEnemyTurn() override;
    bool setPlayerDamage(ActorBase* player) override;
    
    void setInitialState() override;
    void danceWithMove(DanceMove move) override;
    void calcModel() override;
    void playerDamageTurn(ActorBase* player) override;

    // Returns true if the Patapata is currently able to dance.
    virtual bool canDance();

    DECLARE_STATE_ID(Patapata, FlyV);
    DECLARE_STATE_ID(Patapata, FlyH);
    DECLARE_STATE_ID(Patapata, Jump);
    DECLARE_STATE_ID(Patapata, JumpTurn);

    // Waits for the current animation to finish if `this->mIsDancing` is true.
    // Changes animation back to flying animation and clears `this->mIsDancing` when the animation finishes.
    void updateDanceAnim();

    // Sets the current animation for the Patapata.
    void setAnim(const sead::SafeString& animName, PlayPolicy policy, f32 speed);
    
private:
    /* 0x1210 */  AnimModelBase* mModelPata;            // The model for the Patapata.
    /* 0x1214 */  AnimModelBase* mModelPataGold;        // The model for the Patapata while gold.
    /* 0x1218 */  s16 mFlightTimer;                     // The timer used during `FlightPhase::cFlying` before transitioning to `FlightPhase::cBreaking`.
    /* 0x121A */  u16 _121A;                            //
    /* 0x121C */  u16 _121C;                            //
    /* 0x122D */
    /* 0x122E */    
    /* 0x1220 */  u32 _1220;                            //
    /* 0x1224 */  bool _1224;                           // Unknown. Dance related.
    /* 0x1225 */  bool mIsDancing;                      // True if the Patapata is currently dancing.
    /* 0x1226 */  u8 mFlightDirection;                  // The direction the Patapata is flying in (Either [0 = Left, 1 = Right] or [0 = Up, 1 = Down]).
    /* 0x1227 */  
    /* 0x1228 */  FlightPhase mFlightPhase;             // The current flight phase of the Patapata.
    /* 0x122C */  s32 mPhaseAccumulator;                // Accumulator used while flying to create a sine wave bobbing effect. 
    /* 0x1230 */  s32 mGoldChangeTimer;                 // Timer used when transitioning between normal and gold.
    /* 0x1234 */  Angle mGoldChangeRotSpeed;            // Rotation speed used when transitioning between normal and gold.
    /* 0x1238 */  bool mIsLowJump;                      // True if the Patapata has a lower jump height.
    /* 0x1239 */  bool mIsFastJump;                     // True if the Patapata has a faster jump.
    /* 0x123A */
    /* 0x123B */
    /* 0x123C */  SharedModel* mSharedModel;            //
};

size_assert(Patapata, 0x1240);
