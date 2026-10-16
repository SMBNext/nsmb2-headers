#pragma once

#include "actors/BlockBase.h"
#include "course/PairChild.h"
#include "mapobj/ObjBgCollisionCullCheck.h"

// Size 0x1430
class ChangeBlockBase : public BlockBase
{
    SEAD_RTTI_OVERRIDE(ChangeBlockBase, BlockBase);
public:
    ChangeBlockBase();

    void spawnItemUp() override;
    void spawnItemDown() override;
    void changeToCoin() override;

    // Null. Called in `executeState_Coin` and `executeState_Block`.
    virtual void vf198();

    // Spawns a tile at the block position?
    virtual void vf19C();

    // Called when the block is destroyed.
    // Calls `fBase::requestDelete()`,
    virtual void onDestroyed();

    // Returns true if the `BlockState` at `this->mBlockStatePos` is `BlockState::cChanged`.
    virtual bool isChanged();

    DECLARE_STATE_ID(ChangeBlockBase, Coin);
    DECLARE_STATE_ID(ChangeBlockBase, Block);
    DECLARE_STATE_ID(ChangeBlockBase, Hit);

    // Unknown. Returns `false` if some collision-related check fails, otherwise calls `this->onDestroyed()` and returns `true`.
    bool sub_305DBC();

    // Called in `executeState_Block`.
    // Handles checking if the block was hit and updating the block state.
    void handleBlockHit();

    // Unknown. Checks something using `this->mBlockStatePos`.
    bool sub_3061A8();

    // Calls `this->mColliderActiveInfo->initialize()` and sets `this->mCullCheckEnabled` to `true`.
    void initCullCheck();

    // Called in `executeState_Block` and `executeState_Coin`.
    // Handles checking if a P-Switch was activated and updating the block state.
    void handlePSwitchToggle();

    // Performs a cull check if `this->mCullCheckEnabled` is true.
    void cullCheck();

    // Changes mUnitID and collision type to Coin.
    void setTileCoin();

    // Changes mUnitID and collision type to Brick Block.
    void setTileBrick();

    // Sets up collision check and sensors for a coin.
    void initCollisionCoin();

    // Sets up collision check and sensors for a block.
    void initCollisionBlock();

protected:
    /* 0x12E4 */  ActorBgCollisionCheck::Sensor mFootSensor;    // 
    /* 0x12F0 */  Vec3f mBlockStatePos;                         //
    /* 0x12FC */  PairChild pairChild;                          //
    /* 0x13CC */  ObjBgCollisionCullCheck mCullCheck;           //
    /* 0x13F4 */  Vec2f mColliderActiveAreaSize;                //
    /* 0x13FC */  u32 _13FC;                                    // If this is == 1, doesn't get changed by P-Switch.
    /* 0x1400 */  bool mIsChanged;                              // Is set to true when block is changed to coin by P-Switch.
    /* 0x1404 */  u32 mUnitID;                                  //
    /* 0x1408 */  PairChild::MovementType mPairMovementType;    // 
    /* 0x140C */  u32 mMovementID;                              // MovementID used for PairChild movement.
    /* 0x1410 */  u32 rotationID;                               // Maybe also other id types?
    /* 0x1414 */  bool mCullCheckEnabled;                       // Is set to true in initCullCheck
    /* 0x1415 */  u8 _1415[3];                                  // Probably padding?
    /* 0x1418 */  u32 _1418;                                    //
    /* 0x141C */  u8 _141C;                                     //
    /* 0x141D */  u8 _141D[3];                                  // Probably padding?
    /* 0x1420 */  u32 _1420;                                    //
    /* 0x1424 */  u16 _1424;                                    //
    /* 0x1426 */  u16 mUnkTimer;                                //
    /* 0x1428 */  u16 mCoinSpawnTimer;                          // Used in `executeState_Hit` to time the coin spawn.
    /* 0x142A */  u16 _142A;                                    //
    /* 0x142C */  u16 _142C;                                    //
    /* 0x142E */  u8 _142E[2];                                  // Probably padding?
};

size_assert(ChangeBlockBase, 0x1430);