#pragma once

#include "actors/ChangeBlockBase.h"
#include "sys/Allocator.h"

// Size: 0x1488
class ActorCoinBase : public ChangeBlockBase
{
    SEAD_RTTI_OVERRIDE(ActorCoinBase, ChangeBlockBase);
public:
    enum CoinCollisionFlags
    {
        CoinCollision_cNone             = 0,
        CoinCollision_cOnGround         = 1 << 0,
        CoinCollision_cHitCeiling       = 1 << 1,
        CoinCollision_cHitWall          = 1 << 2,
        CoinCollision_cBounceFinished   = 1 << 3,
    };

    enum class SquishEffectType : u32
    {
        cExplodeSmall      = 0x0,   //
        cExplodeMedium     = 0x1,   //
        cExplodeLarge      = 0x2,   //
    };
    
public:
    ActorCoinBase();

    Result onCreate() override;
    Result onDelete() override;
    Result onExecute() override;
    Result onDraw() override;

    void removeCollisionCheck() override;
    void addCollisionCheck() override;    

    // Changes to StateID_419.
    void powActivated() override;
    bool quakeCollisionEnabled() override;

    // Changes to StateID_3B3 if `quakeType` == `QuakeType_cLargeQuake`.
    void onCollisionQuake(QuakeCollisionType quakeType) override;

    DECLARE_STATE_VIRTUAL_ID_BASE(ActorCoinBase, 3B2);
    DECLARE_STATE_VIRTUAL_ID_BASE(ActorCoinBase, 3B3);
    DECLARE_STATE_VIRTUAL_ID_BASE(ActorCoinBase, 3B4);
    DECLARE_STATE_VIRTUAL_ID_BASE(ActorCoinBase, 3B5);

    // Processes physics for the coin.
    // Scales `this->speed.x` by 0.5f if `applyGroundFriction` is true.
    // Sets `this->speed.x` to `finalGroundSpeed` if `this->mBounceCounter` is >= 3.
    CoinCollisionFlags updateCoinPhysics(bool onlyWhileFalling, bool applyGroundFriction, f32 finalGroundSpeed);

    // Sets up a collider for a "Jump" coin (Has an offset collider).
    void setupCollisionJump(bool registerCollider);

    // Does _14B4 ^= if some Z rotation is complete.
    void sub_287890();

    // Sets `this->maxSpeedYLiquid`, `this->minSpeedYLiquid` and `this->accelerationYLiquid`
    void initLiquidPhysics();

    // Sets up a collider for a normal coin.
    void setupCollisionNormal(bool registerCollider);

    // Sets `this->maxSpeed` and `this->accelerationY`.
    void initPhysics();

    // Sets up collision sensors based on the value of `this->_1468`.
    void setupCollisionSensors();

    // Sets `this->visibleAreaOffset`, `this->existDistance` and `this->visibleDistance`.
    void initCulling();

    // Enables collision if the coin is falling or bouncing.
    // Returns `true` if collision is enabled and the coin has been destroyed.
    bool enableCollision();

    // Address: 0x00287C0C
    bool sub_287C0C(bool unk1);
    
    // Links `this->pairChild` to a movement controller and updates `this->position`.
    void linkPairChild();

    // Checks if the coin has been squished and destroys it with the chosen effect. 
    void checkSquished(SquishEffectType effectType);

    // Initializes various tile-related properties.
    void initializeTile(bool isBlueCoin);

    // Increments `this->rotation.y` by `0x4000000`/
    void updateRotationY();

protected:
    /* 0x1430 */  u8 _1430[4];                                  // Unknown
    /* 0x1434 */  HeapAllocator mAllocator;                     // 
    /* 0x143C */  f32 _143C;                                    // Added to X position in draw
    /* 0x1440 */  f32 _1440;                                    // Added to Y position in draw
    /* 0x1444 */  f32 _1444;                                    // 
    /* 0x1448 */  f32 _1448;                                    // 
    /* 0x144C */  ActorBgCollisionCheck::Sensor mHeadSensor;    // 
    /* 0x1458 */  f32 _1458;                                    // 
    /* 0x145C */  u32 _145C;                                    // 
    /* 0x1460 */  u32 mBounceCounter;                           // 
    /* 0x1464 */  u32 _1464;                                    // 
    /* 0x1468 */  u32 _1468;                                    // 
    /* 0x146C */  u32 mLayering;                                // 0: Above Layer 1, 1: Below Layer 1 (un-collectable 1), 2: Below Layer 1
    /* 0x1470 */  u32 _1470;                                    // 
    /* 0x1474 */  u8 _1474;                                     // 
    /* 0x1475 */  bool mCollisionActive;                        // 
    /* 0x1476 */  u8 _1476;                                     // 
    /* 0x1477 */  u8 _1477;                                     // 
    /* 0x1478 */  u8 _1478;                                     // 
    /* 0x1479 */  u8 _1479;                                     // 
    /* 0x147A */  u8 _147A;                                     // 
    /* 0x147B */  u8 _147B;                                     // 
    /* 0x147C */  f32 _147C;                                    // 
    /* 0x1480 */  u32 _1480;                                    // 
    /* 0x1484 */  u8 _1484;                                     // 
    /* 0x1485 */  u8 _1485;                                     // 
    /* 0x1486 */
    /* 0x1487 */
};

size_assert(ActorCoinBase, 0x1488);
