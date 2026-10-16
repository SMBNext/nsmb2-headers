#pragma once

#include "actors/ActorBase.h"
#include "actors/BlockBase.h"
#include "actors/ChangeBlockBase.h"
#include "player/PlayerBase.h"
#include "sead/seadVector.h"
#include "types.h"

class PlayerBase;

// size: 0x1450
class ActorBlockBase : public ChangeBlockBase
{
    SEAD_RTTI_OVERRIDE(BlockBase, ChangeBlockBase);
public:

    enum Type : u32
    {
        Type_cHatena        = 0x0,  // Question Block
        Type_cRenga         = 0x1,  // Brick Block
        Type_cHit           = 0x2,  // Used Block
        Type_cClear         = 0x3,  // Invisible Block
        Type_cHatenaCap     = 0x4,  // Gold Hat Block
        Type_Unk5           = 0x5,  //
        Type_Unk6           = 0x6,  //
    };
    
public:
    ActorBlockBase();

    Result onExecute() override;
    Result onDraw() override;

    void powActivated() override;       

    void onDownMoveSpawnStart() override;
    void spawnItemUp() override;
    void spawnItemDown() override;
    void onDownMoveSpawnEnd() override;

    // Returns true if not destroyed.
    virtual bool fetchInitialState();

    // Called when a block is hit.
    virtual void onHit();

    // Returns `this->spriteData2 & 0xF`.
    virtual u8 getContentsIdx();

    virtual void vf1B4();
    virtual void vf1B8();

    // Called when a block is broken (E.g. via SpikeBall).
    virtual void onBreak();

    virtual void vf1C0();

    // Calls `ActorBase::CullCheck(0)`.
    virtual bool doCullCheck();
    
    virtual void vf1C8();
    virtual void vf1CC();
    virtual void vf1D0();

    DECLARE_STATE_VIRTUAL_ID_BASE(BlockBase, Wait);
    DECLARE_STATE_VIRTUAL_ID_BASE(BlockBase, HitWait);

    // Destroys the block with the specified death effect type.
    void destroy(ActorBase::DeathEffectType deathType);

    // 
    void sub_2DD9E4();

    // Calls `BlockBase::resolveStarChainContents` if `this->type` is `Type_cHatena` or `Type_cRenga`.
    void sub_2DDB40();

    // 
    void updatePairChild();

    // Disables the GoldBlock flag in `PlayerStateData` preventing the flying gold block from respawning.
    void disableGoldBlockFlag();

    // Returns the block's `BlockBase::Contents` using the index from `getContentsIndex()`.
    BlockBase::Contents getBlockContents() const;

    // 
    bool sub_2DDCD0(u32 a1);

    // 
    void sub_2DDE90();
    
    // Links `this->pairChild` to a movement controller and updates `this->position`.
    void linkPairChild();

    // 
    void sub_2DE2F0(ActorBase* a1, PlayerBase* player, u32 a3);

    // Related to calculating position for PairChild rotation.
    Vec2f sub_2DE3FC();

    // 
    void sub_2DE5CC();

    // Returns the `BlockBase::Contents` at the given index.
    BlockBase::Contents getBlockContents(u8 index) const;

    // Spawns `ActorBlockHatenaCapPut` at `this->position` and destroys itself.
    void spawnHatenaCapPut(Direction hitDirection);
    
    // Initializes the actor, optionally registering the collider with the collision manager.
    bool init(bool registerCollider);

    // Collision callback for adjacent collisions
    static void collisionCallbackSide(BgCollision* collider, ActorBgCollisionCheck* check, Direction direction);
    
public:
    /* 0x1430 */  f32 itemCreateZPos;       // Set to either 500.0f or -3000.0f in `init`
    /* 0x1434 */  f32 itemCreateYPosUp;     // Inited to 0.0f
    /* 0x1438 */  f32 itemCreateYPosDown;   // Inited to 0.0f
    /* 0x143C */  f32 _143C;                // Inited to 0.0f
    /* 0x1440 */  f32 _1440;                // Inited to 0.0f
    /* 0x1444 */  Type type;                //
    /* 0x1448 */  u32 _1448;                //
    /* 0x144C */  u8 _144C;                 // Inited to 0
    /* 0x144D */  u8 _144D;                 //
    /* 0x144E */  u8 _144E;                 // Inited to 0
    /* 0x144F */  u8 _144F;                 //
};

size_assert(ActorBlockBase, 0x1450);
