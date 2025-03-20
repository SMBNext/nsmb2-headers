#pragma once

#include "collider/FollowArg.h"
#include "collider/UnkCollisionClass.h"
#include "sys/LineNodeMgr.h"

class ActorBase;
class ActorBgCollisionCheck;


class BgCollision
{
public:
    enum Type : u8
    {
        TYPE_NORMAL                 = 0,
        TYPE_COIN                   = 1,
        TYPE_RED_COIN               = 2,
        TYPE_BLUE_COIN              = 3,
        TYPE_COIN_OUTLINE           = 4,
        TYPE_NET                    = 5,
        TYPE_SPIDER_WEB             = 6,
        TYPE_VINE                   = 7,
        TYPE_QUESTION_MARK_BLOCK    = 8,
        TYPE_BRICK_BLOCK            = 9,
        TYPE_USED_BLOCK             = 10,
        TYPE_WOOD_BLOCK             = 11,
        TYPE_STONE_BLOCK            = 12,
        TYPE_RED_BLOCK              = 13,
        TYPE_EXPLODABLE_4           = 14,
        TYPE_SOLID                  = 15,
        TYPE_DONUT                  = 16,
        TYPE_DONUT_ICY              = 17,
        TYPE_LIQUID_0               = 18,
        TYPE_LIQUID_1               = 19,
        TYPE_LIQUID_2               = 20,
        TYPE_POISON                 = 21,
        TYPE_QUICKSAND              = 22,
        TYPE_23,
        TYPE_24,
        TYPE_25,
        TYPE_BOUNCY_MUSHROOM        = 26,
        TYPE_SWINGING_VINE          = 27,
        TYPE_28,
        TYPE_29,
        TYPE_SOLID_ICY              = 30,
        TYPE_31,
        TYPE_SPIKES_TOP             = 32,
        TYPE_SPIKES_BOTTOM          = 33,
        TYPE_SPIKES_LEFT            = 34,
        TYPE_SPIKES_RIGHT           = 35,
        TYPE_36,
        TYPE_TIGHTROPE              = 37,
        TYPE_CONVEYOR_LEFT          = 38,
        TYPE_CONVEYOR_RIGHT         = 39,
    };

    enum SurfaceType : u32
    {
        SURFACE_TYPE_NORMAL         = 0,
        SURFACE_TYPE_ICE            = 1,
        SURFACE_TYPE_SNOW           = 2,
        SURFACE_TYPE_QUICKSAND      = 3,
        SURFACE_TYPE_SAND_DESERT    = 4,
        SURFACE_TYPE_GRASS          = 5,
        SURFACE_TYPE_CLOUD          = 6,
        SURFACE_TYPE_SAND_BEACH     = 7,
        SURFACE_TYPE_CARPET         = 8,
        SURFACE_TYPE_LEAVES         = 9,
        SURFACE_TYPE_WOOD           = 10,
        SURFACE_TYPE_WATER          = 11,
    };

    enum Behavior : u32
    {
        BEHAVIOR_NORMAL                 = 0,
        BEHAVIOR_LINE                   = 1,
        BEHAVIOR_COIN_OUTLINE           = 2,
        BEHAVIOR_COIN                   = 3,
        BEHAVIOR_BLUE_COIN              = 4,
        BEHAVIOR_EXPLODABLE             = 5,
        BEHAVIOR_BRICK_BLOCK            = 6,
        BEHAVIOR_QUESTION_MARK_BLOCK    = 7,
        BEHAVIOR_PARTLY_SOLID           = 8,
        BEHAVIOR_RED_OUTLINE            = 9,
        BEHAVIOR_INVISIBLE_BLOCK        = 10,
        BEHAVIOR_SLOPE                  = 11,
        BEHAVIOR_SLOPE_UPSIDE_DOWN      = 12,
        BEHAVIOR_LIQUID                 = 13,
        BEHAVIOR_CLIMBABLE              = 14,
        BEHAVIOR_DAMAGE                 = 15,
        BEHAVIOR_PIPE                   = 16,
        BEHAVIOR_CONVEYOR               = 17,
        BEHAVIOR_DONUT_PLATFORM         = 18,
        BEHAVIOR_NO_JUMP                = 20,
        BEHAVIOR_HORIZONTAL_ROPE        = 21,
        BEHAVIOR_CLIMB_POLE             = 22,
        BEHAVIOR_FLIPPER_GATE           = 32,
        BEHAVIOR_CLOWN_CAR_FLASH_SAFE   = 33,
        BEHAVIOR_NO_HEADBONK            = 34,
        BEHAVIOR_NOTE_BLOCK             = 35,
        BEHAVIOR_OBAKE_SPRING           = 36,
        BEHAVIOR_POW_BLOCK              = 37,
    };
    
public:

    typedef void (*Callback)(BgCollision* collider, ActorBgCollisionCheck* otherMgr);
    typedef void (*CallbackWall)(BgCollision *collider, ActorBgCollisionCheck *otherMgr, Direction direction);
    typedef bool (*CheckRev)(ActorBase *self, ActorBase *other);
    typedef bool (*CheckRevWall)(ActorBase *self, ActorBase *other, u8 direction);



    virtual void vf0();     // deleted. rtti?

    BgCollision();
    virtual ~BgCollision();

    virtual void vfC(u32*, u32);
    virtual void vf10(u32*, u32);           // null
    virtual void vf14() = 0;
    virtual void execute() = 0;
    virtual void vf1C(u32*, u32, u32*, Vec2f*, u8) = 0;
    virtual void vf20(u32, u32*, u32, u32) = 0;
    virtual u32 vf24(u32, Vec2f*) = 0;
    virtual Vec2f vf28() = 0;
    virtual void vf2C() = 0;
    virtual u32* vf30();
    virtual void vf34() = 0;
    virtual void vf38() = 0;


    void setType(u32 type);         // Preset flags for the following and more. Fetched from table at 0x00570378

    void setHitbox(u32 type);
    void setSurfaceType(u32 type);
    void setBehaviour(u32 type);    
    void setSubBehaviour(u32 type);

    Vec2f getPosition();


    LineNodeMgr<BgCollision>::Node listNodesA;
    LineNodeMgr<BgCollision>::Node listNodesB;
    LineNodeMgr<BgCollision>::Node listNodesC;
    LineNodeMgr<BgCollision>::Node listNodesD;
    LineNodeMgr<BgCollision>::Node listNodesE;
    LineNodeMgr<BgCollision>::Node listNodesF;
    LineNodeMgr<BgCollision> _4C;
    LineNodeMgr<BgCollision> _54;
    LineNodeMgr<BgCollision> _5C;
    LineNodeMgr<BgCollision> _64;
    Callback callbackTop;
    Callback callbackBottom;
    CallbackWall callbackSide;
    CheckRev checkRevTop;
    CheckRev checkRevBottom;
    CheckRevWall checkRevSide;
    ActorBase* owner;
    ActorBase* ignoreActor;
    FollowArg followArg;
    Vec2f posOffset;
    Vec2f posOffsetPrev;
    Vec2f rotPivotOffset;       // used to be distToCenter
    Vec2f rotPivotOffsetPrev;
    Vec2f typeOffset;           // assumed
    Vec2f typeOffsetPrev;       // assumed
    sead::BoundBox2f _CC;
    u8 type;
    u8 _DD;
    u8 _DE;
    u8 _DF;
    u64 behaviourData;
    u8 _E8;
    u8 _E9;
    u8 _EA;
    u8 _EB;
    s32 angle;
    s32 anglePrev;
    u32 _F4;
    u32 _F8;
    u8 _FC;
    u8 _FD;
    u8 _FE;
    u8 _FF;
    UnkCollisionClass unkClass;
};

size_assert(BgCollision,0x138);


class BgCheckUnitInfo
{
public:
    u64 data;
};


class BgCollisionCheckResultArea
{
public:
    u8 hitDirectionFlag;
    Vec2f hitPos;
    u32 _C;
    u32 _10;
    u8 _14[4];                            // unk
    BgCheckUnitInfo bgCheckData;
    BgCollision* bgCollision;
};


class BgCollisionCheckResultPoint
{
public:   
    BgCheckUnitInfo bgCheckData;
    BgCollision* bgCollision;
};


class BgHitCheckCallback
{
public:
    virtual bool hit(const BgCollisionCheckResultArea& hitRes) = 0;
    virtual bool hit(const BgCollisionCheckResultPoint& hitRes) = 0;

};
