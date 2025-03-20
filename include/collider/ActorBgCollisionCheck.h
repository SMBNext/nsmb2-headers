#pragma once

#include "collider/BasicBgCollisionCheck.h"
#include "collider/BgCollision.h"
#include "collider/UnkCollisionClass.h"
#include "sys/Common.h"

class ActorBase;

class ActorBgHitCheckCallback : public BgHitCheckCallback
{
public:
    virtual bool hit(const BgCollisionCheckResultArea& hitRes) override;
    virtual bool hit(const BgCollisionCheckResultPoint& hitRes) override;

    ActorBgCollisionCheck* mBgCollisionCheck;
};

class ActorBgCollisionCheck       // vtable: 005A44A8
{
public:
    struct Sensor
    {
        f32 pos1;
        f32 pos2;
        f32 centerOffset;
    };

    class Output
    {
    public:
        enum Flag : u32
        {
            FLAG_ON_GROUND           = 1u << 0,
            FLAG_ON_SLOPE            = 1u << 1,
            FLAG_ON_LIFT             = 1u << 2,
            FLAG_UNK_8               = 1u << 3,
            FLAG_ON_SEMISOLID        = 1u << 4,
            FLAG_UNK_20              = 1u << 5,
            FLAG_UNK_40              = 1u << 6,
            FLAG_UNK_80              = 1u << 7,
            FLAG_UNK_100             = 1u << 8,
            FLAG_UNK_200             = 1u << 9,
            FLAG_COLLISION_BOTTOM    = 1u << 10,
            FLAG_UNK_800             = 1u << 11,
            FLAG_UNK_1000            = 1u << 12,
            FLAG_UNK_2000            = 1u << 13,
            FLAG_UNK_4000            = 1u << 14,
            FLAG_UNK_8000            = 1u << 15,
            FLAG_UNK_10000           = 1u << 16,
            FLAG_UNK_20000           = 1u << 17,
            FLAG_COLLISION_RIGHT     = 1u << 18,
            FLAG_COLLISION_LEFT      = 1u << 19,
            FLAG_UNK_100000          = 1u << 20,
            FLAG_UNK_200000          = 1u << 21,
            FLAG_BLOCK_BROKEN        = 1u << 22,
            FLAG_UNK_800000          = 1u << 23,
            FLAG_UNK_1000000         = 1u << 24,
            FLAG_UNK_2000000         = 1u << 25,
            FLAG_UNK_4000000         = 1u << 26,
            FLAG_UNK_8000000         = 1u << 27,
            FLAG_UNK_10000000        = 1u << 28,
            FLAG_UNK_20000000        = 1u << 29,
            FLAG_UNK_40000000        = 1u << 30,
            FLAG_UNK_80000000        = 1u << 31,
        };

    public:
        u32 flag;
    };


    class CollisionMgr_9A8
    {
    public:
        CollisionMgr_9A8();

        UnkCollisionClass _0[2];
    };

public:
    ActorBgCollisionCheck();                             // 0021D0C4
    virtual ~ActorBgCollisionCheck();                    // 0021D394
    
    virtual void vf08();                        // deleted
    virtual void process();                     // 0021C9E0     processCollisions?
    virtual void dispose();                     // 0021CEE4     called in onDelete
    virtual void update();                      // 002190EC     called in beforeExecute
    virtual ActorBase* getOwner() = 0;
    virtual ActorBase* vf1C(BgCollision*, u32 direction) = 0;
    virtual s8* getPlayerId() = 0;
    virtual void vf24();                        // 0021C6E8
    
    
    void init(ActorBase* owner, const Sensor* belowSensor, const Sensor* aboveSensor, const Sensor* adjacentSensor);
    void initSensor(const Sensor* sensor, u32 slot);

    bool checkForSuitableGround(const Vec3f& position, f32 xOffset, f32 unk1, f32 yOffset);
    s32 getSlopeAngle(u8 direction);

    inline bool isOnGround()               { return output.flag & Output::FLAG_ON_GROUND; }
    inline bool isOnSlope()                { return output.flag & Output::FLAG_ON_SLOPE; }
    inline bool isOnLift()                 { return output.flag & Output::FLAG_ON_LIFT; }
    inline bool isOnSemiSolid()            { return output.flag & Output::FLAG_ON_SEMISOLID; }
    inline bool isCollidedBelow()          { return output.flag & Output::FLAG_COLLISION_BOTTOM; }
    inline bool isCollidedRight()          { return output.flag & Output::FLAG_COLLISION_RIGHT; }
    inline bool isCollidedLeft()           { return output.flag & Output::FLAG_COLLISION_LEFT; }
    inline bool isCollided(bool direction) { return output.flag & (Output::FLAG_COLLISION_RIGHT << direction); }
    inline bool isCollided()               { return output.flag & (Output::FLAG_COLLISION_RIGHT | Output::FLAG_COLLISION_LEFT); }

    static u8 getLiquidInfo(f32* levelOut, const Vec3f& position);  // Returns Liquid type, levelOut can be nullptr


    BasicBgCollisionCheck bgCheck;
    ActorBgHitCheckCallback bgHitCheckCallback;
    sead::FixedPtrArray<BgCollision, 512> _58;
    u32* _864;
    u32 _unk868;
    u32 _86C;
    u32* _870;
    u32 _unk874;
    u32 _878;
    u32* _87C;
    u32 _unk880;
    u32 _884;
    u32* _888;
    u32 _unk88C;
    u32 _890;
    ActorBase* owner;
    u32 _898;
    FollowArg followArg;
    Vec3f _8AC;                            // may be part of followArg
    u8 _8B8;
    u8 _8B9;
    u8 _8BA;
    u8 _8BB;                              ///< set to 1 when sensor init
    u8 _8BC;                              ///< set to 1 when sensor init
    bool sensorsInited[4];
    bool sensorsInactive[4];
    bool _8C5[4];
    ActorBgCollisionCheck::Sensor sensors[4];
    u32 _8FC;
    u32 _900;
    u32 _904;
    u32 _908;
    u32 _90C;
    u32 _910;
    u32 _914;
    u32 _918;
    u32 _91C;
    u32 _920;
    u32 _924;
    u32 _928;
    u32 _92C;
    u32 _930;
    u32 _934;
    u32 _938;
    u32 _93C;
    u32 _940;
    u32 _944;
    u32 _948;
    u32 _94C;
    u32 _950;
    u32 _954;
    u32 _958;
    u32 _95C;
    u32 _960;
    u32 _964;
    u32 _968;
    u32 _96C;
    u32 _970;
    u16 _974;
    u16 _976;                             ///< copy of _974 (prev _974 ?)
    u32 sensorFlags[4][2];
    u8 _998;                              ///< Holds result after init
    u8 _999;
    u8 _99A[4];                           ///< init to 2020202
    u8 _99E[4];                           ///< struct? size 0x4 | init to 2020202 | copy of _99A (prev _99A ?)
    u8 _unk9A2[6];
    CollisionMgr_9A8 _9A8[4];
    CollisionMgr_9A8 _B68[4];             ///< copy of _9A8 (prev _9A8 ?)
    u32 _D28;
    u32 _D2C;
    u32 _D30;
    u32 _D34;
    u32 _D38;
    u32 _D3C;
    u32 _D40;
    u32 _D44;
    u32 _D48;
    u32 _D4C;
    u32 _D50;
    u32 _D54;
    u32 _D58;
    u32 _D5C;
    u32 _D60;
    u32 _D64;
    ActorBgCollisionCheck::Output output;
    u32 _D6C;
    u32 _D70;                             ///< struct? size 0x8 | copy of output (prev output ?)
    u32 _D74;
    sead::BoundBox2f _D78;
    sead::BoundBox2f _D88;
    sead::BoundBox2f _D98;
    sead::BoundBox2f _DA8;                ///< copy of _D98 (prev _D98 ?)
    u8 _unkDB8;
};


// vtable: 005B8AE0
class ActorBgCollisionObjCheck : public ActorBgCollisionCheck
{
public:
    ActorBgCollisionObjCheck();                        // 0032D600
    // doesn't have a dtor.
    
    ActorBase* getOwner() override;                 // 004A439C     returns owner
    ActorBase* vf1C(BgCollision*, u32) override;   // 004A4394     returns owner
    s8* getPlayerId() override;

    f32 _unkDBC;                                // unkDBC  might be part of base. probably not tho
};
