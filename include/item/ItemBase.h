#pragma once

#include "actors/ActorMultiState.h"
#include "effect/Effect.h"
#include "gfx/Model.h"
#include "item/ItemType.h"
#include "player/PlayerEnum.h"
#include "state/FStateID.h"
#include "sys/Allocator.h"
#include "state/FStateVirtualID.h"

// Size: 0x11D8
class ItemBase : public ActorMultiState
{
    SEAD_RTTI_OVERRIDE(ItemBase, ActorMultiState);

public:
    enum class Animation : u32
    {
        cNone       = 0,    //
        cOutUp      = 1,    //
        cOutJump    = 2,    //
        cOutDown    = 3,    //
        cWait       = 4,    //
        cWait2      = 5,    //
    };

    enum class SpawnBehavior : u32
    {
        cFromPipe                   = 0x00,     // ItemOut (Block/Pipe).
        cNormal                     = 0x01,     // Drop down with trail. (Stock Item?).
        cNotCollectable             = 0x02,     // Floating in place, using bubble anim?
        cJump                       = 0x03,     // Throws item to the right?
        cJump2                      = 0x04,     // Throws item to the right?
        cJump3                      = 0x05,     // Throws item to the right?
        cHighGravity                = 0x06,     // Falls down fast.
        cGiveItem                   = 0x07,     // Spawns with delay before falling. Used for Stock items and Rewards (red ring).
        cGiveItemStock              = 0x08,     // Spawns with delay before going into the Player's item stock.
        cInPlace                    = 0x09,     // Spawns in place and patrols, ignoring gravity.
        cJumpUp                     = 0x0A,     // Thrown up colliding with anything in the way.
        cNonCollectable2            = 0x0B,     // Floating in place, using bubble anim?
        cJump4                      = 0x0C,     // Throws item to the right?
        cJumpUpOppositeDir          = 0x0D,     // Thrown straight up, not colliding with anything until falling.
        cShootOut                   = 0x0E,     // Shoots diagonally at a rapid speed
        cTreasureChest              = 0x0F,     // Item is the contents of a treasure chest.
        cKinopioThrow               = 0x10,     // Item is thrown off screen and deleted. Used at the beginning of a 1-Up House.
    };

    enum class CollectionStatus : u32
    {
        cNone   = 0,    // The Item has cannot be/has not been collected.
        cApply  = 1,    // The effect of the Item can be applied to the player.
        cStore  = 2,    // The Item should be stored in the player's inventory.
    };
    
public:
    ItemBase();

    Result onDelete() override;
    Result onDraw() override;

    DECLARE_STATE_VIRTUAL_ID_BASE(ItemBase, 382);
    DECLARE_STATE_VIRTUAL_ID_BASE(ItemBase, 383);
    DECLARE_STATE_VIRTUAL_ID_BASE(ItemBase, 384);

    // Creates the model for the item.
    virtual void createModel() = 0;

    // Cleans up the model.
    virtual void removeModel();

    // Determines the state to use when spawned.
    virtual void decideStateSpawn();

    // Determines the state to use while idle.
    virtual void decideStateIdle();

    // Changes the state to 382.
    virtual void changeState_382();

    // Sets the animation to the out up animation.
    virtual void setAnimOutUp();

    // Sets the animation to the out down animation.
    virtual void setAnimOutDown();

    // Sets the animation to the wait animation.
    virtual void setAnimWait();

    // Sets the animation to the wait animation used while in a bubble.
    virtual void setAnimWaitBubble();

    // Sets the animation to the out jump animation.
    virtual void setAnimOutJump();

    // Deleted.
    virtual void vf15C();

    // Deleted.
    virtual void vf160();

    // Called from `ItemBase::initialize()`.
    // Sets up the actor collision check for the Item.
    virtual void setActorCollisionCheck();

    // Handles checking if the Item has been collected by the player.
    // Returns `true` if the item has been collected.
    virtual bool checkCollection();

    // Called from `ItemBase::initialize()`.
    // Sets up the BgCollision sensor above the Item.
    virtual void setSensorAbove();

    // Called from `ItemBase::initialize()`.
    // Sets up the BgCollision sensor below the Item.
    virtual void setSensorBelow();

    // Called from `ItemBase::initialize()`.
    // Sets up the BgCollision collision sensor for the Item.
    virtual void setSensorAdjacent();

    // Sets the value of `this->speed.y` for when the item is in liquid.
    virtual void setLiquidGravity();

    // Calculates and updates the Item's model.
    virtual void calcModel();

    // Called when the Item collides with the ground.
    // Used by `BigKinoko` to play a sound when it lands.
    virtual void onCollisionGround();

    DECLARE_STATE_ID(ItemBase, OutUp);
    DECLARE_STATE_ID(ItemBase, OutDown);
    DECLARE_STATE_ID(ItemBase, 379);
    DECLARE_STATE_ID(ItemBase, 37A);
    DECLARE_STATE_ID(ItemBase, 37B);
    DECLARE_STATE_ID(ItemBase, 37C);
    DECLARE_STATE_ID(ItemBase, 37D);
    DECLARE_STATE_ID(ItemBase, 37E);
    DECLARE_STATE_ID(ItemBase, KinopioThrow);
    DECLARE_STATE_ID(ItemBase, OutChest);
    DECLARE_STATE_ID(ItemBase, 381);

    // Calculates the horizontal speed of the Item using the given `direction`.
    // Uses a lookup table of speeds indexed by `this->speedIndex`.
    f32 horizontalSpeed(u32 direction) const;

    // Calculates the horizontal speed of the Item using `this->direction`.
    // Uses a lookup table of speeds indexed by `this->speedIndex`.
    f32 horizontalSpeed() const;

    // Attempts to give a stock item to the player with the given `playerNum`.
    // Gives either the stock item to the player, or `1000` points if they are not eligible.
    void givePlayerStock(s32 playerNum) const;

    // Creates the trail effect for items falling from stock or moving into the stock item slot.
    void doEffectItemTrail();
    
    // Should be called from `onCreate`.
    // Sets up collision, culling and other properties.
    void initialize();

    // Returns `true` if the Item is in water.
    bool inWater() const;

    // Returns true if there is water at the given `position`.
    bool checkWater(const sead::Vector3f& position) const;

    // Unknown. Handles a state machine sub-state for `StateID_382` and `StateID_37D`.
    void sub_41BA38(bool checkHead);
    
    // Kills the Item, emitting a particle and playing a sound.
    void kill();

    // Handles giving the item to the specified player.
    // Returns `true` if the item was successfully collected.
    bool handleCollection(CollectionStatus status, s8 playerNum);

    // Unknown. Updates effects.
    // Called from `executeState_382`.
    void sub_41BE98();

    // Sets up speed and other properties before changing to the Idle state.
    // Calls `this->decideStateIdle()` to change to the Idle state.
    void changeStateIdle();

    // Checks if the Item has collided with a trampoline.
    // Plays a sound and returns `true` if the item has collided.
    bool checkTrampoline() const;

    // Returns the z-depth value for the Item's layer.
    // Returns `-2600.0f` if the item is on layer 1, else `700.0f`.
    f32 getLayerZDepth() const;

    // Calls `ActorCollisionCheckMgr::instance()->addToList()` with `this->collisionCheck`.
    void enableCollisionCheck();

    // Creates and updates the item's glow effect.
    void updateItemEffect();

    // Unknown. Checks something related to BgCollision.
    // Called from `PanelGoldFlower::calcModel`.
    bool sub_41C2C8();

    // Applies the item as a power-up to the specified player.
    void powerUpPlayer(s8 playerNum) const;

    // Called from `executeState_OutDown` and `executeState_OutUp`.
    // Checks the space in the area the item is moving into while emerging from a block.
    // Returns `true` if a tile is occupying the space the item is trying to move into.
    bool checkAreaOut(bool down) const;

    // Returns the speed value used for falling during a quake.
    static f32 getQuakeSpeedY();

    // Handles reacting to the BGM to have the item dance.
    void handleDance();

    // Tries to have `this->collidedPlayerNum` collect the item.
    // Returns `true` if the powerup was collected, stores the status of collection in `statusOut`.
    bool tryCollect(CollectionStatus& statusOut, Powerup powerup, bool isPowerup);

    // Returns the Y-Position offset used during a quake.
    static f32 getQuakeOffsetY();

    // Callback for collision events.
    static void collisionCallback(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);
    
    // Checks if the Item has been squished by a wall.
    // Kills the Item and returns `true` if the item was squished.
    bool checkSquished();

    // Returns the speed increment when moving left/right.
    static f32 speedIncrementX();

    // Unknown. Related to updating item position.
    void sub_41D87C();

public:

    DECLARE_STATE_ID(ItemBase, Still);
    
public:
    /* 0x0FEC */  Vec3f initialPosition;            // Initialized to `this->position` in constructor.
    /* 0x0FF8 */  u8 _unkFF8[24];                   //
    /* 0x1010 */  AnimModelBase* model;             //
    /* 0x1014 */  HeapAllocator allocator;          //
    /* 0x101C */  UnkEffectType mEffect;            //
    /* 0x1078 */  UnkEffectType mEffect2;           //
    /* 0x10D4 */  ItemType mItemType;               // The type of item this actor is.
    /* 0x10D8 */  u32 _10D8;                        //
    /* 0x10DC */  Animation currentAnim;            //
    /* 0x10E0 */  SpawnBehavior behavior;           //
    /* 0x10E4 */  s32 mAssociatedPlayer;            // The player who spawned the item (E.g. from inventory stock).
    /* 0x10E8 */  u8 _10E8;                         //
    /* 0x10E9 */  u8 _10E9;                         //
    /* 0x10EA */
    /* 0x10EB */
    /* 0x10EC */  u32 _10EC;                        //
    /* 0x10F0 */  u8 _10F0;                         //
    /* 0x10F1 */  u8 _10F1;                         //
    /* 0x10F2 */  u8 _10F2;                         //
    /* 0x10F3 */
    /* 0x10F4 */  s32 collidedPlayerNum;            // The player who collected the item.
    /* 0x10F8 */  u32 _10F8;                        //
    /* 0x10FC */  u32 _10FC;                        // Unknown sub-state.
    /* 0x1100 */  u32 _1100;                        //
    /* 0x1104 */  u32 _1104;                        //
    /* 0x1108 */  u32 _1108;                        //
    /* 0x110C */  u32 effectState;                  // Sub-state used in `updateItemEffect()`. 0=Create, 1=Update, 2=Complete.
    /* 0x1110 */  u32 effectTimer;                  // Timer used in `updateItemEffect()`.
    /* 0x1114 */  u32 speedIndex;                   // Used to index a list of speed values.
    /* 0x1118 */  f32 targetScale;                  // Scale target used for scale animations.
    /* 0x111C */  bool isInRouletteBlock;           // True if the item is contained in a roulette block.
    /* 0x111D */  u8 _111D[3];                      // Unknown. Probably padding.
    /* 0x1120 */  u32 outTimer;                     // Timer used when emerging out of a block etc. Used in `StateID_OutDown` and `StateID_OutUp`.
    /* 0x1124 */  f32 spawnOffsetY;                 // Position offset used when spawning.
    /* 0x1128 */  f32 _1128;                        //
    /* 0x112C */  u32 _112C;                        // Unknown sub-state.
    /* 0x1130 */  bool collisionRegistered;         // True if collision has been registered.
    /* 0x1131 */  
    /* 0x1132 */  
    /* 0x1133 */  
    /* 0x1134 */  u32 blinkTimer;                   // Timer used while the item is blinking. Used in `StateID_37A`.
    /* 0x1138 */  u32 blinkCount;                   // Counts the number of times the item has blinked.
    /* 0x113C */  u32 _113C;                        // Unknown timer.
    /* 0x1140 */  u32 _1140;                        // Unknown timer.
    /* 0x1144 */  Effect effect3;                   //
    /* 0x1184 */  s32 _1084;                        //
    /* 0x1188 */  Effect effect4;                   //
    /* 0x11C8 */  u32 _11C8;                        //
    /* 0x11CC */  s32 _11CC;                        //
    /* 0x11D0 */  u8 _11D0;                         //
    /* 0x11D1 */  u8 _11D1;                         //
    /* 0x11D2 */  u8 isCoinRush;                    //
    /* 0x11D3 */  u8 _11D3;                         //
    /* 0x11D4 */  Powerup powerup;                  //
};

size_assert(ItemBase, 0x11D8);
