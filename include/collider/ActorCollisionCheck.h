#pragma once

#include "sead.h"
#include "sead/seadBitFlag.h"
#include "sys/Common.h"
#include "sys/LineNodeMgr.h"

class ActorBase;

class ActorCollisionCheck     // size: 0xB8
{
public:
    typedef void (*HitCallback)(ActorCollisionCheck* self, ActorCollisionCheck* other);

    enum ShapeType : u8
    {
        SHAPE_TYPE_BOX               = 0,
        SHAPE_TYPE_CIRCLE            = 1,
        SHAPE_TYPE_TRAPEZOID_UD      = 2,
        SHAPE_TYPE_TRAPEZOID_LR      = 3,
    };

    // The kind of actor this is
    enum Kind : u8
    {
        KIND_PLAYER                    = 0x0,
        KIND_PLAYER_ATTACK             = 0x1,
        KIND_UNK_2                     = 0x2,      // this is Yoshi in NSMBU
        KIND_ENEMY                     = 0x3,
        KIND_BALLOON                   = 0x4,      // used for bubbles
        KIND_COLLECTIBLE               = 0x5,      // items, star coins, etc.
        KIND_PROJECTILE                = 0x6,      // fireballs, hammers, etc.
        KIND_BULLET                    = 0x7,      // used for bullet bills (and cannonballs in NSMBU)
        KIND_GOAL_POLE                 = 0x8,
        KIND_UNK_9                     = 0x9,      // this is Baby Yoshi in NSMBU
    };

    // The kinds of actors that this actor is allowed to interact with
    enum TargetKind : u32
    {
        TARGET_KIND_NONE                 = 0,
        TARGET_KIND_PLAYER               = 1u << KIND_PLAYER,
        TARGET_KIND_PLAYER_ATTACK        = 1u << KIND_PLAYER_ATTACK,
        TARGET_KIND_UNK_2                = 1u << KIND_UNK_2,         // this is Yoshi in NSMBU
        TARGET_KIND_ENEMY                = 1u << KIND_ENEMY,
        TARGET_KIND_BALLOON              = 1u << KIND_BALLOON,       // used for bubbles
        TARGET_KIND_COLLECTIBLE          = 1u << KIND_COLLECTIBLE,
        TARGET_KIND_PROJECTILE           = 1u << KIND_PROJECTILE,    // fireballs, hammers, etc.
        TARGET_KIND_BULLET               = 1u << KIND_BULLET,        // used for bullet bills (and cannonballs in NSMBU)
        TARGET_KIND_GOAL_POLE            = 1u << KIND_GOAL_POLE,
        TARGET_KIND_UNK_9                = 1u << KIND_UNK_9,         // this is Baby Yoshi in NSMBU


        // A preset suitable for most enemies (Goombas, Koopas, etc.)
        TARGET_KIND_PRESET_ENEMY      = TARGET_KIND_PLAYER         | TARGET_KIND_PLAYER_ATTACK | TARGET_KIND_UNK_2      |
                                        TARGET_KIND_ENEMY          | TARGET_KIND_COLLECTIBLE   | TARGET_KIND_PROJECTILE |
                                        TARGET_KIND_UNK_9,

        // A preset suitable for bullet-like actors (Cannonballs, Bullet Bills, etc.)
        TARGET_KIND_PRESET_BULLET     = TARGET_KIND_PLAYER         | TARGET_KIND_PLAYER_ATTACK | TARGET_KIND_UNK_2  |
                                        TARGET_KIND_ENEMY          | TARGET_KIND_PROJECTILE    | TARGET_KIND_BULLET,

        // A preset suitable for most map_obj actors
        TARGET_KIND_PRESET_MAP_OBJ    = TARGET_KIND_PLAYER | TARGET_KIND_PLAYER_ATTACK | TARGET_KIND_PROJECTILE,

        // A preset suitable for player-related checking only
        TARGET_KIND_PRESET_PLAYER     = TARGET_KIND_PLAYER | TARGET_KIND_PLAYER_ATTACK,
    };

    // The type of attack that the actor will perform
    enum Attack : u8
    {
        ATTACK_NONE             = 0x0,
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

    // The types of attacks that the actor will take damage from
    enum DamageFrom : u32
    {
        DAMAGE_FROM_NONE              = 0,
        DAMAGE_FROM_FIRE              = 1u << ATTACK_FIRE,
        DAMAGE_FROM_STAR_MEGA         = 1u << ATTACK_STAR_MEGA,
        DAMAGE_FROM_SIDE              = 1u << ATTACK_SIDE,
        DAMAGE_FROM_SLIDE             = 1u << ATTACK_SLIDE,
        DAMAGE_FROM_KOOPA_FIRE        = 1u << ATTACK_KOOPA_FIRE,
        DAMAGE_FROM_GROUND_POUND      = 1u << ATTACK_GROUND_POUND,
        DAMAGE_FROM_FENCE_PUNCH       = 1u << ATTACK_FENCE_PUNCH,
        DAMAGE_FROM_SHELL             = 1u << ATTACK_SHELL,
        DAMAGE_FROM_TAIL              = 1u << ATTACK_TAIL,
        DAMAGE_FROM_UNK_10            = 1u << ATTACK_UNK_10,
        DAMAGE_FROM_UNK_11            = 1u << ATTACK_UNK_11,
        DAMAGE_FROM_UNK_12            = 1u << ATTACK_UNK_12,
        DAMAGE_FROM_UNK_13            = 1u << ATTACK_UNK_13,
        DAMAGE_FROM_EXPLOSION         = 1u << ATTACK_EXPLOSION,
        DAMAGE_FROM_CANNON            = 1u << ATTACK_CANNON,

        // Allows all used attacks; useful for "simple" enemies (Goombas, Koopas, etc.)
        DAMAGE_FROM_PRESET_ALL      = DAMAGE_FROM_FIRE   | DAMAGE_FROM_STAR_MEGA    |
                                      DAMAGE_FROM_SIDE   | DAMAGE_FROM_SLIDE       |
                                      DAMAGE_FROM_GROUND_POUND | DAMAGE_FROM_FENCE_PUNCH |
                                      DAMAGE_FROM_SHELL  | DAMAGE_FROM_TAIL        |
                                      DAMAGE_FROM_EXPLOSION | DAMAGE_FROM_CANNON,

        // For "bullet-like" actors (Cannonball, Bullet Bill, etc.)
        DAMAGE_FROM_PRESET_BULLET   = DAMAGE_FROM_STAR_MEGA | DAMAGE_FROM_SIDE      |
                                      DAMAGE_FROM_GROUND_POUND | DAMAGE_FROM_SHELL |
                                      DAMAGE_FROM_TAIL      | DAMAGE_FROM_EXPLOSION |
                                      DAMAGE_FROM_CANNON    | DAMAGE_FROM_FIRE     |
                                      DAMAGE_FROM_SLIDE,

        // For "big" actors (Big Boo, Giant Urchin, etc.)
        DAMAGE_FROM_PRESET_BIG      = DAMAGE_FROM_NONE | DAMAGE_FROM_STAR_MEGA | DAMAGE_FROM_EXPLOSION,
    };

    enum Status : u32
    {
        STATUS_NONE                     = 0,
        STATUS_NO_REVISION              = 1 << 0,
        STATUS_NO_SAME_ACTOR            = 1 << 1,
        STATUS_NO_PASS_INFO             = 1 << 2,   // If set, this instance will not interact with other instances
        STATUS_NO_SAME_ACTOR_GROUP      = 1 << 3,
        STATUS_NO_CHECK_LIMIT           = 1 << 4,

        STATUS_FIRE_KILL                = 1 << 7,   // If set, this actor will kill
        STATUS_SLIDE_KILL               = 1 << 8,   // If set, this actor will kill objects such as shells

        STATUS_FORCE_GET_REVISION       = 1 << 10,
        STATUS_NO_REVISION_ENEMY        = 1 << 11,
    };


    struct CollisionData            // size: 0x24
    {
        Vec2f centerOffset;         // 0
        Vec2f halfSize;             // 8
        ShapeType shapeType;        // 10
        u8 kind;                    // 11   the kind of actor this is
        u8 attack;                  // 12   type of the attack this instance performs
        u32 vsKind;                 // 14   kinds of actors to interact with
        u32 vsDamage;               // 18   attack types to receive
        u32 status;                 // 1C   sets special flags
        HitCallback callback;       // 20
    };


    ActorCollisionCheck();
    ~ActorCollisionCheck();

    void set(ActorBase* owner, const CollisionData& collisionData);
    void set(ActorBase* owner, const CollisionData& collisionData, const sead::BitFlag8& collisionMask);
    void set(ActorBase* owner, const CollisionData& collisionData, const sead::BitFlag8& collisionMask, u8 layer);

    f32 getTop();
    f32 getBottom();
    f32 getCenterY();
    f32 getRight();
    f32 getLeft();
    f32 getCenterX();

    LineNodeMgr<ActorCollisionCheck>::Node listNode;   // 0

    ActorBase* owner;                                  // C
    ActorBase* ignored;                                // 10   inited to 0
    u8 _14[4];                                         // 14
    u8 id;                                             // 18   used by things with multiple collisionCheck e.g. KuriboTower
    u8 _19[3];                                         // 19
    CollisionData info;                                         // 1C
    f32 trapezoidOffsetTL;                             // 40
    f32 trapezoidOffsetTR;                             // 44
    f32 trapezoidOffsetBL;                             // 48
    f32 trapezoidOffsetBR;                             // 4C
    f32 collisionOffsetsX[10];                         // 50
    f32 collisionOffsetsY[10];                         // 78
    Vec2f lastCollisionPos;                            // A0
    TargetKind hitType;                                // A8   Owner types of others collided with
    DamageFrom attacksPerformed;                       // AC   Attacks performed on others
    DamageFrom attacksRecieved;                        // B0   Attacks recieved from others
    sead::BitFlag8 collisionMask;                      // B4   
    u8 layer;                                          // B5   
    u8 flag;                                           // B6   if == 2 is inactive, is set to 253 before checking collision
    u8 _B7;                                            // B7   pad?
};



class ActorCollisionCheckMgr
{
    SEAD_SINGLETON_DISPOSER(ActorCollisionCheckMgr);
public:
    void addToList(ActorCollisionCheck* aCollisionCheck);
    void removeFromList(ActorCollisionCheck* aCollisionCheck);

    LineNodeMgr<ActorCollisionCheck> activeList;
};
