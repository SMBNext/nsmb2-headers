#pragma once

#include "actors/ActorMultiState.h"
#include "sys/Allocator.h"
#include "gfx/Model.h"
#include "effect/Effect.h"
#include "player/PlayerEnum.h"



class ItemBase : public ActorMultiState
{
    SEAD_RTTI_OVERRIDE(ItemBase, ActorMultiState);

public:
    ItemBase();

    int onDelete() override;
    int onDraw() override;

    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11C();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12C();
    virtual void vf130();
    virtual void createModel() = 0;
    virtual void vf138();
    virtual void decideFirstState();
    virtual void decideIdleState();
    virtual void vf144();
    virtual void setAnimationOutUp();
    virtual void setAnimationOutDown();
    virtual void setAnimationWait();
    virtual void setAnimationWait2();
    virtual void setAnimationOutJump();
    virtual void vf15C();   // deleted
    virtual void vf160();   // deleted
    virtual void vf164();
    virtual void collectionCheck();
    virtual void vf16C();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void updateModel();
    virtual void vf180();

    void init();
    bool tryGivePlayerPowerup(u32& collectState, Powerup powerup, bool unk2);     // collectState: 0=Not collected, 1=Used, 2=To storage
    void collected(u32 collectState, u32 unk2);

    Vec3f _FEC;                  // FEC      inited to position in ctor
    u8 _unkFF8[0x1010-0xFF8];   // FF8
    AnimModelBase* model;       // 1010
    HeapAllocator allocator;    // 1014
    ScopedEffect _101C;         // 101C     Actually uses a derived class
    ScopedEffect _1078;         // 1078     ^
    u32 stockItemId;            // 10D4
    u8 _unk10D8[0x10DC-0x10D8]; // 10D8
    u32 _10DC;                  // 10DC
    u8 _unk10E0[0x10F4-0x10E0]; // 10E0
    u32 _10F4;                  // 10F4
    u8 _unk10F8[0x111C-0x10F8]; // 10F8
    u8 isInRouletteBlock;       // 111C
    u8 _unk111D[0x11D4-0x111D]; // 111D
    Powerup powerup;          // 11D4

    static u16 glowEffectIds[];
    static u16 collectEffectIds[];
};


class Item : public ItemBase
{
    SEAD_RTTI_OVERRIDE(Item, ItemBase);

public:
    Item();

    virtual void vf184();
    virtual void vf188();
    virtual void vf18C();

    DECLARE_STATE_ID(Item, Moving);
    DECLARE_STATE_ID(Item, Stationary);
    DECLARE_STATE_ID(Item, Jumping);
};


class ItemMgr
{
public:

    struct SpawnInfo
    {
        Vec3f* position;
        u8 itemType;
        u32 itemCount;                        // may be wrong
        u8 layer;
        u8 _D;
        u8 _E[2];                             // probably just padding
        u32 spawnDirection;                   // e.g. up/down from block
        u32 _14;                              // playerId-related
        u32 _18;                              // playerId-related
        u32 playerId;
        u32 _20;
        u32 _24;
        u32 _28;
        u32 behavior;
        u32 _30;
        u32 direction;
        u32 _38;
        u32 isInRouletteBlock;
    };

    enum ItemType : u8
    {
        ITEM_TYPE_KINOKO                = 0x0,
        ITEM_TYPE_FLOWER                = 0x1,
        ITEM_TYPE_STAR                  = 0x2,
        ITEM_TYPE_1UP_KINOKO            = 0x3,
        ITEM_TYPE_MAME_KINOKO           = 0x4,
        ITEM_TYPE_BIG_KINOKO            = 0x5,
        ITEM_TYPE_LEAF                  = 0x6,
        ITEM_TYPE_GOLD_FLOWER           = 0x7,
        ITEM_TYPE_LEAF_WHITE            = 0x8,
        ITEM_TYPE_PANEL_STAR            = 0x9,
        ITEM_TYPE_PANEL_GOLD_FLOWER     = 0xA,
    };

    enum Behavior : u32
    {
        BEHAVIOR_PIPE                       = 0x0,
        BEHAVIOR_NORMAL                     = 0x1,
        BEHAVIOR_UNCOLLECTABLE              = 0x2,   // Also 0x11 onwards
        BEHAVIOR_JUMP                       = 0x3,   
        BEHAVIOR_JUMP_2                     = 0x4,   // Same as 0x3,
        BEHAVIOR_JUMP_3                     = 0x5,   // Same as 0x3,
        BEHAVIOR_HIGH_GRAVITY               = 0x6,   
        BEHAVIOR_GIVE_ITEM                  = 0x7,   // Used for inventory and Red Coin Ring
        BEHAVIOR_GIVE_ITEM_INVENTORY        = 0x8,   // Gives an item, but then places in inventory
        BEHAVIOR_IN_PLACE                   = 0x9,   
        BEHAVIOR_JUMP_UP                    = 0xA,   
        BEHAVIOR_UNCOLLECTABLE_2            = 0xB,   
        BEHAVIOR_JUMP_4                     = 0xC,   // Same as 0x3,
        BEHAVIOR_JUMP_UP_OPPOSITE_DIR       = 0xD,   
        BEHAVIOR_SHOOT_OUT                  = 0xE,   // Shoots diagonally at a rapid speed
        BEHAVIOR_CHEST                      = 0xF,   
        BEHAVIOR_DOWNWARD_IGNORE_COLLISION  = 0x10,  // Unknown purpose
    };

public:
    static ItemMgr* instance;

    static u16 itemProfileIds[];
    static ActorInfo* itemActorInfos[];

    static inline s64 spawnInfoToSpriteData(const SpawnInfo& info)
    {
        s64 spritedata = ((info._38 << 8) & 0x7FF) 
            | ((info.spawnDirection & 3)    << 12)
            | ((info._14 & 1)               << 14)
            | ((info._18 & 1)               << 15)
            | ((info.playerId & 3)          << 16)
            | ((info._20 & 3)               << 18)
            | ((info._24 & 3)               << 20)
            | ((0 & 3)                      << 22)       
            | ((info.behavior & 0x1F)       << 24)
            | ((info.isInRouletteBlock & 1) << 29)
            | ((info._30 & 1)               << 30)
            | (info.direction               << 31);

        return spritedata;
    }

    void spawnItem(const Vec3f& position, s64 spriteData, u8 itemType);
};
