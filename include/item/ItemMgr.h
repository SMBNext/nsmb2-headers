#pragma once

#include "actors/BlockBase.h"
#include "effect/EffectId.h"
#include "item/ItemBase.h"
#include "item/ItemType.h"
#include "math/Vec.h"
#include "sead/heap/seadDisposer.h"
#include "types.h"
#include "utility/Direction.h"

// Size: 0x14
class ItemMgr
{
    SEAD_SINGLETON_DISPOSER(ItemMgr);
public:
    // Size: 0x40
    struct SpawnInfo
    {
        /* 0x00 */  Vec3f* position;                        // The position at which to spawn the item.
        /* 0x04 */  ItemType itemType;                      // The type of item to spawn.     
        /* 0x08 */  u32 itemCount;                          //
        /* 0x0C */  u8 layer;                               //
        /* 0x0D */  bool forceAdvancedPowerup;              //
        /* 0x0E */  u8 _E[2];                               // Probably padding.
        /* 0x0F */  u32 spawnDirection;                     // e.g. up/down from block
        /* 0x10 */  u32 _14;                                // playerId-related
        /* 0x14 */  u32 _18;                                // playerId-related
        /* 0x1C */  u32 playerId;                           //
        /* 0x20 */  u32 _20;                                //
        /* 0x24 */  u32 _24;                                //
        /* 0x28 */  u32 _28;                                //
        /* 0x2C */  ItemBase::SpawnBehavior spawnBehavior;  //
        /* 0x30 */  u32 _30;                                //
        /* 0x34 */  Direction direction;                    //
        /* 0x35 */
        /* 0x36 */
        /* 0x37 */      
        /* 0x38 */  u32 speed;                              //
        /* 0x3C */  u32 isInRouletteBlock;                  //
    };
    size_assert(SpawnInfo, 0x40);

    static const u16 cItemEffects[];
    static const u16 cItemGetEffects[];
    static const u16 cItemProfileIds[];
    static const ActorInfo* cItemActorInfos[];
    static const ItemType cBlockContentsTable[];

public:
    virtual ~ItemMgr();

    // Used internally by many of the other createItem functions.
    // Creates an item with the given `position`, `spriteData`, and `itemType`.
    ItemBase* createItem(const Vec3f& position, s64 spriteData, ItemType itemType) const;

    // Unknown. Called from `ItemObj::initializeState_442()`.
    // Creates an item with some unknown parameter.
    void createItemUnk1(const Vec3f& position, s64 unk1) const;
    
    // Creates an item spawned from the inventory of the player with the given `playerNum`.
    void createItemStock(const Vec3f& position, ItemType itemType, s8 playerNum) const;
    
    // -- REIMPLEMENTED -- 
    // Creates an item spawned from a block based on the given `spawnInfo` and `blockContents`.
    void createItemBlock(const SpawnInfo& spawnInfo, BlockBase::Contents blockContents) const;

    // Unknown. Called from `BlockBase::sub_43332C()`.
    // Creates an item based on the given `spawnInfo`.
    void createItemUnk2(const SpawnInfo& spawnInfo) const;
    
    // Used by RedRing.
    // Creates an item spawned from a red-coin ring with the given `blockContents` and `playerNum`.
    void createItemRedRing(const Vec3f& position, u32 blockContents, s8 playerNum) const;
    
    // Used by FireCoinJet.
    // Creates an item spawned from a pipe with the given `dokanContents`, `direction`, and `unk1`.
    void createItemDokan(const Vec3f& position, u32 dokanContents, u32 direction, u32 unk1) const;
    
    // Returns the ID of the effect for the specified `itemType` used for item pickup.
    EffectID getPickupEffect(ItemType itemType) const;

    // Unknown. Called from `PlayerObject::vf270()`.
    // Creates an item at the specified `position` with the given `blockContents` and `playerNum`.
    void createItemUnk3(const Vec3f& position, u32 blockContents, s8 playerNum);
    
    // Returns true if the specified player is powered-up and eligible for an advance powerup.
    bool canSpawnAdvancePowerup(s8 playerNum) const;

    // Unknown. Called from `ItemObj::executeState_441()`.
    // Creates an item at the specified `position` with the given `blockContents`.
    void createItemUnk4(const Vec3f& position, const Vec2f& blockPosition, u32 blockContents) const;

    // Returns the number of additional items to spawn for extra players in co-op.
    s32 getNumCoopBonusItem() const;
    
    // Resolves the correct `ItemType` for the given `blockContents`.
    // Returns the resolved `ItemType` in `itemTypeOut`.
    void getItemType(ItemType& itemTypeOut, u32 blockContents, bool isRouletteBlock) const;
    
    // Returns the ID of the effect for the specified `itemType` used for item.
    EffectID getItemEffect(ItemType itemType) const;

    // Creates an item spawned from a treasure chest.
    ItemBase* createItemTreasureBox(const Vec3f& position, u32 blockContents, s8 playerNum) const;
    
    // Creates a Mushroom at the specified `position`.
    ItemBase* createKinoko(const Vec3f& position) const;
    
};

size_assert(ItemMgr, 0x14);
