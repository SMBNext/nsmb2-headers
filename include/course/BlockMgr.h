#pragma once

#include "actors/ActorBase.h"
#include "actors/ActorUniqueID.h"
#include "actors/BlockBase.h"
#include "math/Vec.h"
#include "sead/heap/seadDisposer.h"
#include "types.h"

// Size: 0xF0DC
class BlockMgr
{
    SEAD_SINGLETON_DISPOSER(BlockMgr);
public:
    enum class BlockState : u32
    {
        cNormal     = 0x0,  //
        cUsed       = 0x1,  //
        cDestroyed  = 0x2,  //
        cChanged    = 0x3,  // Used when affected by a P-Switch (E.g. coin became a brick)
    };

    // Size: 0x10
    struct HitInfo
    {
        /* 0x0 */  Vec3f position;       // The position of the block that was hit
        /* 0xC */  u16 hitCount;         // The number of times the block has been hit
        /* 0xE */  u16 hitTimer;         // The timer used when allowing consecutive hits

        HitInfo();
    };

    size_assert(HitInfo, 0x10);

    // Size: 0x14
    struct StateInfo
    {
        /* 0x00 */  Vec3f position;          // The position of the block
        /* 0x0C */  BlockState state;        // The state of the block
        /* 0x10 */  u16 areaID;              // The area the block is in
        /* 0x12 */
        /* 0x13 */

        StateInfo();
    };

    size_assert(StateInfo, 0x14);

    // Size: 0x10
    struct BreakBlockInfo
    {
        /* 0x00 */  Vec2f position;      //
        /* 0x08 */  u8 hitDirection;     //
        /* 0x09 */  u8 blockType;        // ActorBlockBase::Type
        /* 0x0A */  u8 _A;               //
        /* 0x0B */  s8 playerNum;        //
        /* 0x0C */  u16 _C;              //
        /* 0x0E */ 
        /* 0x0F */ 
    };

    size_assert(BreakBlockInfo, 0x10);

    // Size: 0xC
    struct FragmentInfo
    {
        /* 0x00 */  Vec2f position;      //
        /* 0x08 */  u8 hitDirection;     //
        /* 0x09 */  s8 playerNum;        //
        /* 0x0A */  u8 _A;               //
        /* 0x0B */  u8 _B;               //
    };

    size_assert(FragmentInfo, 0xC);

    // Size: 0x18
    struct BreakInfo
    {
        /* 0x00 */  Vec2f position;                          // The position of the block
        /* 0x08 */  u32 _8;                                  // Indexes a list at 0x579DC8 [ 4, 1, 2, 5, 5 0 ], 0 = Palm?, 1 = stone, 2 = used, 3 = red block, 4 = red block?, 5 = Brick block 
        /* 0x0C */  u32 _C;                                  // 0 = ? Block, 1 = Brick, 2 = palm block? [Enables indexing _8]
        /* 0x10 */  Direction direction;                     // The direction the block was hit from
        /* 0x11 */  u8 _11;                                  //
        /* 0x12 */  ActorBase::ActorType actorType;          //
        /* 0x13 */  u8 _13;                                  //
        /* 0x14 */  ActorBgCollisionCheck* collisionCheck;   //
    };

    size_assert(BreakInfo, 0x18);

    // Size: 0x14
    struct HitBlockInfo
    {
        /* 0x00 */  Vec2f position;                          // The position of the block
        /* 0x08 */  u32 contents;                            // 0 = spawn coin, 1 = mushroom / fireflower, 2 = star, 3 = coin (chain star?), 4 = vine, 5 = springboard, 6 = mini mush, 7 = mush if small, 8 = mega mush, 9 = mush/leaf, A = gold flower, B = Nothing?, C = Nothing?, D = Nothing?, E = Nothing?, F = Nothing?
        /* 0x0C */  Direction direction;                     // The direction the block was hit from
        /* 0x0D */  bool _D;                                 //
        /* 0x0E */  s8 playerNum;                            //
        /* 0x0F */  ActorBase::ActorType actorType;          //
        /* 0x10 */  ActorBgCollisionCheck* collisionCheck;   //
    };

    size_assert(HitBlockInfo, 0x14);
    
public:
    BlockMgr();

    // Does a block hit using the provided `HitBlockInfo`.
    // Spawns a used block once done.
    void hitBlock(const HitBlockInfo& info);

    // Appends a new `HitInfo` entry to `this->mHitInfoList` if empty.
    // Returns `BlockBase::Contents` based on the `hitCount` and `hitTimer` of the entry.
    BlockBase::Contents sub_4038A8(const Vec3f& position); 
    
    // Creates an `ActorBlockJump` at the given position.
    ActorBase* createActorBlockJump(const Vec2f& position);

    // Processes the timer for each entry in `this-mHitInfoList`.
    void execute();

    // Breaks a block according to the given `BreakInfo`.
    void breakBlock(const BreakInfo& info);

    // Returns the `BlockState` of the entry in `this->mStateInfoList` corresponding to the given `position` and `areaId`.
    BlockState getBlockState(const Vec3f& position, u8 areaId);

    // Sets the `BlockState` of the entry in `this->mStateInfoList` corresponding to the given `position` and `areaId` to `state`.
    void setBlockState(const Vec3f& position, BlockState state, u8 areaId);

    // Creates a `ChikuwaBlock` at the given `position` with the specified `size` and `type`.
    ActorBase* createChikuwaBlock(const Vec2f& position, u32 size, u16 type);

    // Creates an `ActorBlockShock` at the given `position` with the specified `playerId` and `actorId`.
    ActorBase* createActorBlockShock(const Vec2f& position, s8 playerId, ActorUniqueID actorId);

    // Creates a `YukaBaneChild` at the given `position`.
    ActorBase* createYukaBaneChild(const Vec2f& position);

    // Creates a `BreakBlock` using the given `info`.
    ActorBase* createBreakBlock(const BreakBlockInfo& info);

    // Spawns a block fragment using the given `FragmentInfo`.
    void createBlockFragment(const FragmentInfo& info, bool noSound, bool doEffect);
    
private:
    /* 0x0010 */  HitInfo mHitInfoList[101];         // 
    /* 0x0660 */  StateInfo mStateInfoList[3001];    //
    /* 0xF0D4 */  u32 mHitInfoCount;                 // The number of entries used in `mHitInfoList`.
    /* 0xF0D8 */  u32 mStateInfoCount;               // The number of entries used in `mStateInfoList`.
};

size_assert(BlockMgr, 0xF0DC);
