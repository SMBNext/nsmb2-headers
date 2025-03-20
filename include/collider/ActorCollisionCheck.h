#pragma once

#include "sead.h"
#include "sead/seadBitFlag.h"
#include "sys/Common.h"
#include "sys/LineNodeMgr.h"

class ActorBase;

class ActorCollisionCheck     // size: 0xB8
{
public:
    typedef bool (*HitCallback)(ActorCollisionCheck* self, ActorCollisionCheck* other);

    enum Shape : u8
    {
        SHAPE_BOX               = 0,
        SHAPE_CIRCLE            = 1,
        SHAPE_TRAPEZOID_UD      = 2,
        SHAPE_TRAPEZOID_LR      = 3,
    };

    enum Type : u8
    {
        TYPE_GENERIC            = 0x0,
        TYPE_PLAYER             = 0x1,
        TYPE_UNK_2              = 0x2,      // this is Yoshi in NSMBU
        TYPE_ENEMY              = 0x3,
        TYPE_BALLOON            = 0x4,      // used for bubbles
        TYPE_COLLECTIBLE        = 0x5,
        TYPE_PROJECTILE         = 0x6,      // fireballs, hammers, etc.
        TYPE_BULLET             = 0x7,      // used for bullet bills (and cannonballs in NSMBU)
        TYPE_GOAL_POLE          = 0x8,
        TYPE_UNK_9              = 0x9,      // this is Baby Yoshi in NSMBU
    };

    enum TypeMask : u32
    {
        TYPE_MASK_GENERIC       = 1u << TYPE_GENERIC,
        TYPE_MASK_PLAYER        = 1u << TYPE_PLAYER,
        TYPE_MASK_UNK_2         = 1u << TYPE_UNK_2,         // this is Yoshi in NSMBU
        TYPE_MASK_ENEMY         = 1u << TYPE_ENEMY,
        TYPE_MASK_BALLOON       = 1u << TYPE_BALLOON,       // used for bubbles
        TYPE_MASK_COLLECTIBLE   = 1u << TYPE_COLLECTIBLE,
        TYPE_MASK_PROJECTILE    = 1u << TYPE_PROJECTILE,    // fireballs, hammers, etc.
        TYPE_MASK_BULLET        = 1u << TYPE_BULLET,        // used for bullet bills (and cannonballs in NSMBU)
        TYPE_MASK_GOAL_POLE     = 1u << TYPE_GOAL_POLE,
        TYPE_MASK_UNK_9         = 1u << TYPE_UNK_9,         // this is Baby Yoshi in NSMBU


        // A preset suitable for most enemies (Goombas, Koopas, etc.)
        TYPE_MASK_PRESET_ENEMY      = TYPE_MASK_GENERIC | TYPE_MASK_PLAYER      | TYPE_MASK_UNK_2      |
                                      TYPE_MASK_ENEMY   | TYPE_MASK_COLLECTIBLE | TYPE_MASK_PROJECTILE |
                                      TYPE_MASK_UNK_9,

        // A preset suitable for bullet-like actors (Cannonballs, Bullet Bills, etc.)
        TYPE_MASK_PRESET_BULLET     = TYPE_MASK_GENERIC | TYPE_MASK_PLAYER     | TYPE_MASK_UNK_2  |
                                      TYPE_MASK_ENEMY   | TYPE_MASK_PROJECTILE | TYPE_MASK_BULLET,

        // A preset suitable for most map_obj actors
        TYPE_MASK_PRESET_MAP_OBJ    = TYPE_MASK_GENERIC | TYPE_MASK_PLAYER | TYPE_MASK_ENEMY |
                                      TYPE_MASK_PROJECTILE,

        // A preset suitable for player-related checking only
        TYPE_MASK_PRESET_PLAYER     = TYPE_MASK_GENERIC | TYPE_MASK_PLAYER,
    };


    enum Attack : u8
    {
        ATTACK_GENERIC          = 0x0,
        ATTACK_FIRE             = 0x1,
        ATTACK_STAR_MEGA        = 0x2,
        ATTACK_SIDE             = 0x3,
        ATTACK_SLIDE            = 0x4,
        ATTACK_KOOPA_FIRE       = 0x5,
        ATTACK_GROUND_POUND     = 0x6,
        ATTACK_FENCE_PUNCH      = 0x7,
        ATTACK_SHELL            = 0x8,
        ATTACK_TAIL             = 0x9,
        ATTACK_UNK_10           = 0xA,
        ATTACK_UNK_11           = 0xB,
        ATTACK_UNK_12           = 0xC,
        ATTACK_UNK_13           = 0xD,
        ATTACK_EXPLOSION        = 0xE,
        ATTACK_CANNON           = 0xF,
    };

    enum AttackMask : u32
    {
        ATTACK_MASK_GENERIC           = 1u << ATTACK_GENERIC,
        ATTACK_MASK_FIRE              = 1u << ATTACK_FIRE,
        ATTACK_MASK_STAR_MEGA         = 1u << ATTACK_STAR_MEGA,
        ATTACK_MASK_SIDE              = 1u << ATTACK_SIDE,
        ATTACK_MASK_SLIDE             = 1u << ATTACK_SLIDE,
        ATTACK_MASK_KOOPA_FIRE        = 1u << ATTACK_KOOPA_FIRE,
        ATTACK_MASK_GROUND_POUND      = 1u << ATTACK_GROUND_POUND,
        ATTACK_MASK_FENCE_PUNCH       = 1u << ATTACK_FENCE_PUNCH,
        ATTACK_MASK_SHELL             = 1u << ATTACK_SHELL,
        ATTACK_MASK_TAIL              = 1u << ATTACK_TAIL,
        ATTACK_MASK_UNK_10            = 1u << ATTACK_UNK_10,
        ATTACK_MASK_UNK_11            = 1u << ATTACK_UNK_11,
        ATTACK_MASK_UNK_12            = 1u << ATTACK_UNK_12,
        ATTACK_MASK_UNK_13            = 1u << ATTACK_UNK_13,
        ATTACK_MASK_EXPLOSION         = 1u << ATTACK_EXPLOSION,
        ATTACK_MASK_CANNON            = 1u << ATTACK_CANNON,

        // Convenience presets
        // Allows all used attacks; useful for "simple" enemies (Goombas, Koopas, etc.)
        ATTACK_MASK_PRESET_ALL      = ATTACK_MASK_GENERIC     | ATTACK_MASK_FIRE   | ATTACK_MASK_STAR_MEGA    |
                                      ATTACK_MASK_SIDE        | ATTACK_MASK_SLIDE  | ATTACK_MASK_GROUND_POUND |
                                      ATTACK_MASK_FENCE_PUNCH | ATTACK_MASK_SHELL  | ATTACK_MASK_TAIL         | 
                                      ATTACK_MASK_EXPLOSION   | ATTACK_MASK_CANNON,

        // For "bullet-like" actors (Cannonball, Bullet Bill, etc.)
        ATTACK_MASK_PRESET_BULLET   = ATTACK_MASK_GENERIC      | ATTACK_MASK_STAR_MEGA | ATTACK_MASK_SIDE      |
                                      ATTACK_MASK_GROUND_POUND | ATTACK_MASK_SHELL     | ATTACK_MASK_TAIL      |
                                      ATTACK_MASK_EXPLOSION    | ATTACK_MASK_CANNON    | ATTACK_MASK_FIRE      |
                                      ATTACK_MASK_SLIDE,

        // For "big" actors (Big Boo, Giant Urchin, etc.)
        ATTACK_MASK_PRESET_BIG      = ATTACK_MASK_GENERIC | ATTACK_MASK_STAR_MEGA | ATTACK_MASK_EXPLOSION,
    };

    enum Flag : u32
    {
        FLAG_UNK_0      = 0x1,
        FLAG_PASSIVE    = 0x4,
    };


    struct Info                     // size: 0x24
    {
        Vec2f centerOffset;          // 0
        Vec2f halfSize;              // 8
        Shape shape;                // 10
        u8 type;                    // 11   type of the owner of this instance
        u8 attack;                  // 12   type of the attack this instance performs
        u32 typeMask;               // 14   mask of owner types to interact with
        u32 attackMask;             // 18   mask for attack types to receive
        Flag flag;                  // 1C   sets allowed interactions
        HitCallback callback;       // 20
    };


    ActorCollisionCheck();
    ~ActorCollisionCheck();

    void set(ActorBase* owner, const Info& info);
    void set(ActorBase* owner, const Info& info, const sead::BitFlag8& collisionMask);
    void set(ActorBase* owner, const Info& info, const sead::BitFlag8& collisionMask, u8 layer);


    LineNodeMgr<ActorCollisionCheck>::Node listNode;   // 0

    ActorBase* owner;                                      // C
    ActorBase* ignored;                                    // 10   inited to 0
    u8 _14[4];                                         // 14
    u8 id;                                             // 18   used by things with multiple collisionCheck e.g. KuriboTower
    u8 _19[3];                                         // 19
    Info info;                                         // 1C
    f32 trapezoidOffsetTL;                             // 40
    f32 trapezoidOffsetTR;                             // 44
    f32 trapezoidOffsetBL;                             // 48
    f32 trapezoidOffsetBR;                             // 4C
    f32 collisionOffsetsX[10];                         // 50
    f32 collisionOffsetsY[10];                         // 78
    Vec2f lastCollisionPos;                             // A0
    TypeMask hitType;                                  // A8   Owner types of others collided with
    AttackMask attacksPerformed;                       // AC   Attacks performed on others
    AttackMask attacksRecieved;                        // B0   Attacks recieved from others
    sead::BitFlag8 collisionMask;                      // B4   
    u8 layer;                                          // B5   
    u8 flag;                                           // B6   if == 2 is inactive, is set to 253 before checking collision
    u8 _B7;                                            // B7   pad?
};



class ActorCollisionCheckMgr : public sead::IDisposer     // size: 0x18
{
public:
    static ActorCollisionCheckMgr* instance;

    void addToList(ActorCollisionCheck* aCollisionCheck);
    void removeFromList(ActorCollisionCheck* aCollisionCheck);

    LineNodeMgr<ActorCollisionCheck> activeList;
};
