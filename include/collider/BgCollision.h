#pragma once

#include "collider/ActorBgCollisionCheckResult.h"
#include "collider/FollowArg.h"
#include "collider/UnkCollisionClass.h"
#include "math/Vec.h"
#include "sead/seadRuntimeTypeInfo.h"
#include "sys/LineNodeMgr.h"
#include "utility/Direction.h"

#include "collider/BgUnitCode.h"

class ActorBase;
class ActorBgCollisionCheck;

// Size: 0x138
class BgCollision
{
    SEAD_RTTI_BASE(BgCollision);
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

public:
    using Callback = void (*)(BgCollision* collider, ActorBgCollisionCheck* otherMgr);
    using CallbackWall = void (*)(BgCollision *collider, ActorBgCollisionCheck *otherMgr, Direction direction);
    
    using CheckRev = bool (*)(ActorBase *self, ActorBase *other);
    using CheckRevWall = bool (*)(ActorBase *self, ActorBase *other, Direction direction);

public:
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
    
    void reset();

    ActorBase* getOwner() const
    {
        return mOwnerPtr;
    }

    template<typename T>
    T* getOwner() const
    {
        return reinterpret_cast<T*>(mOwnerPtr);
    }

    ActorBase* getIgnoreActor() const
    {
        return mIgnoreActorPtr;
    }

    void setIgnoreActor(ActorBase* ignoreActor)
    {
        mIgnoreActorPtr = ignoreActor;
    }
    
    
    const FollowArg& getFollowArg() const
    {
        return mFollowArg;
    }

    Vec2f& getPosOffset()
    {
        return mPosOffset;
    }

    const Vec2f& getPosOffset() const
    {
        return mPosOffset;
    }

    Vec2f& getTypeOffset()
    {
        return mTypeOffset;
    }

    const Vec2f& getTypeOffset() const
    {
        return mTypeOffset;
    }

    f32 getPosX() const
    {
        return mFollowArg.positionPtr->x + mPosOffset.x;
    }

    f32 getPosY() const
    {
        return mFollowArg.positionPtr->y + mPosOffset.y;
    }

    // Returns the position of the BgCollision. (`this->mFollowArg.positionPtr + mPosOffset`).
    Vec2f getPos() const;

    f32 getPosPrevX() const
    {
        return mFollowArg.prevPositionPtr->x + mPosOffsetPrev.x;
    }

    f32 getPosPrevY() const
    {
        return mFollowArg.prevPositionPtr->y + mPosOffsetPrev.y;
    }

    // Returns the previous frame position of the BgCollision. (`this->mFollowArg.prevPositionPtr + mPosOffset`).
    Vec2f getPosPrev() const;

    f32 getTypePosX() const
    {
        return getPosX() + mTypeOffset.x;
    }

    f32 getTypePosY() const
    {
        return getPosY() + mTypeOffset.y;
    }

    Vec2f getTypePos() const
    {
        return getPos() + mTypeOffset;
    }

    f32 getTypePosPrevX() const
    {
        return getPosPrevX() + mTypeOffsetPrev.x;
    }

    f32 getTypePosPrevY() const
    {
        return getPosPrevY() + mTypeOffsetPrev.y;
    }

    Vec2f getTypePosPrev() const
    {
        return getPosPrev() + mTypeOffsetPrev;
    }

    bool isInactive() const
    {
        return mIsInactive;
    }
    
    Angle getAngle() const
    {
        return mAngle;
    }

    void setAngle(Angle angle)
    {
        mAngle = angle;
    }
        
    // Sets the callbacks used when something collides with this BgCollision.
    // Callback `callbackFoot` is used when a foot sensor collides with this BgCollision.
    // Callback `callbackHead` is used when a head sensor collides with this BgCollision.
    // Callback `callbackWall` is used when a wall sensor collides with this BgCollision.
    void setCallback(Callback callbackFoot, Callback callbackHead, CallbackWall callbackWall)
    {
        mCallbackFoot = callbackFoot;
        mCallbackHead = callbackHead;
        mCallbackWall = callbackWall;
    }

    inline void setCallbackFoot(Callback callbackFoot)
    {
        mCallbackFoot = callbackFoot;
    }

    // Sets the reverse check used when something collides with this BgCollision.
    void setCheckRev(CheckRev checkRevFoot, CheckRev checkRevHead, CheckRevWall checkRevWall)
    {
        mCheckRevFoot = checkRevFoot;
        mCheckRevHead = checkRevHead;
        mCheckRevWall = checkRevWall;
    }

    void setCheckRevFoot(CheckRev checkRevFoot)
    {
        mCheckRevFoot = checkRevFoot;
    }

    void setCheckRevHead(CheckRev checkRevHead)
    {
        mCheckRevHead = checkRevHead;
    }

    void setCheckRevWall(CheckRevWall checkRevWall)
    {
        mCheckRevWall = checkRevWall;
    }

    void removeFromListFoot(ActorBgCollisionCheck* check);

    // Clears the four ActorBgCollisionCheck lists.                    0x0044C1C0
    void clearBcList();

    // Resets the per-frame collision state.                           0x0044C780
    void sub_44C780();

protected:
    using List = LineNodeMgr<BgCollision>;
    using BcList = LineNodeMgr<ActorBgCollisionCheck>;
    
    /* 0x004 */  List::Node mActiveListNode;        // A list node used when inserting this BgCollision into `ActorBgCollisionMgr->mActiveList`.
    /* 0x010 */  List::Node mSolidListNode;         // A list node used when inserting this BgCollision into `ActorBgCollisionMgr->mSolidList`.
    /* 0x01C */  List::Node mNonSolidListNode;      // A list node used when inserting this BgCollision into `ActorBgCollisionMgr->mNonSolidList`.
    /* 0x028 */  List::Node mCandidateNode;         // A list node used when inserting this BgCollision into `ActorBgCollisionMgr->mCandidateList`.
    /* 0x034 */  List::Node mCoinListNode;          // A list node used when inserting this BgCollision into `ActorBgCollisionMgr->mCoinList`.
    /* 0x040 */  List::Node mTarzanListNode;        // A list node used when inserting this BgCollision into `ActorBgCollisionMgr->mTarzanList`.
    /* 0x04C */  BcList mBcListFoot;                // A list of ActorBgCollisionCheck with foot sensor hitting this BgCollision.
    /* 0x054 */  BcList mBcListHead;                // A list of ActorBgCollisionCheck with head sensor hitting this BgCollision.
    /* 0x05C */  BcList mBcListRight;               // A list of ActorBgCollisionCheck with right wall sensor hitting this BgCollision.
    /* 0x064 */  BcList mBcListLeft;                // A list of ActorBgCollisionCheck with left wall sensor hitting this BgCollision.
    /* 0x06C */  Callback mCallbackFoot;            // Callback used when a foot sensor hits this BgCollision.
    /* 0x070 */  Callback mCallbackHead;            // Callback used when a head sensor hits this BgCollision.
    /* 0x074 */  CallbackWall mCallbackWall;        // Callback used when a wall sensor hits this BgCollision.
    /* 0x078 */  CheckRev mCheckRevFoot;
    /* 0x07C */  CheckRev mCheckRevHead;
    /* 0x080 */  CheckRevWall mCheckRevWall;
    /* 0x084 */  ActorBase* mOwnerPtr;
    /* 0x088 */  ActorBase* mIgnoreActorPtr;
    /* 0x08C */  FollowArg mFollowArg;
    /* 0x09C */  Vec2f mPosOffset;
    /* 0x0A4 */  Vec2f mPosOffsetPrev;
    /* 0x0AC */  Vec2f mRotPivotOffset;
    /* 0x0B4 */  Vec2f mRotPivotOffsetPrev;
    /* 0x0BC */  Vec2f mTypeOffset;           // assumed
    /* 0x0C4 */  Vec2f mTypeOffsetPrev;       // assumed
    /* 0x0CC */  sead::BoundBox2f mBounds;
    /* 0x0DC */  u8 mType;
    /* 0x0DD */  u8 _DD;
    /* 0x0DE */  u8 _DE;
    /* 0x0DF */  u8 _DF;
    /* 0x0E0 */  BgUnitCode mBgCheckData;
    /* 0x0E8 */  u8 mCategory;
    /* 0x0E9 */  u8 _E9;
    /* 0x0EA */  u8 _EA;
    /* 0x0EB */  u8 _EB;
    /* 0x0EC */  Angle mAngle;
    /* 0x0F0 */  Angle mAnglePrev;
    /* 0x0F4 */  u32 _F4;
    /* 0x0F8 */  u32 _F8;
    /* 0x0FC */  u8 mIsInactive;
    /* 0x0FD */  u8 _FD;
    /* 0x0FE */  u8 _FE;
    /* 0x0FF */  u8 _FF;
    /* 0x100 */  ActorBgCollisionCheckResult mCollisionResult;
};

size_assert(BgCollision, 0x138);
