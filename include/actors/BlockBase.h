#pragma once

#include "actors/ActorMultiState.h"
#include "collider/RectCollider.h"
#include "course/PairChild.h"
#include "types.h"
#include "utility/Direction.h"

class PlayerObject;
class Shell;

// Size: 0x12E4
class BlockBase : public ActorMultiState
{
    SEAD_RTTI_OVERRIDE(BlockBase, ActorMultiState);
public:
    enum Contents : u32
    {
        Contents_cKinoko            = 0x0,   // Mushroom/Fire Flower
        Contents_cMameKinoko        = 0x1,   // Mini-Mushroom
        Contents_c1UpKinoko         = 0x2,   // 1UP-Mushroom
        Contents_cKinokoForced      = 0x3,   // Mushroom (Always)
        Contents_cFlower            = 0x4,   // Fire Flower
        Contents_cLeaf              = 0x5,   // Raccoon Leaf
        Contents_cPanelStar         = 0x6,   // Star Item Panel
        Contents_cPanelGoldFlower   = 0x7,   // Gold Flower Item Panel
        Contents_cStar              = 0x8,   // Star
        Contents_cStarChain         = 0x9,   // Star or Coin
        Contents_cGoldFlower        = 0xA,   // Gold Flower
        Contents_cBigKinoko         = 0xB,   // Mega Mushroom
        Contents_cCoin              = 0xC,   // Coin
        Contents_cUnkD              = 0xD,   //
        Contents_cHatenaCap         = 0xE,   // Gold Block Hat
        Contents_cUnkF              = 0xF,   //
        Contents_cUnk10             = 0x10,  //
        Contents_cJumpdai           = 0x11,  // Springboard
        Contents_cLeafWhite         = 0x12,  // Assist Leaf
        Contents_cUnk13             = 0x13,  //
        Contents_cUnk14             = 0x14,  //
        Contents_cUnk15             = 0x15,  //
        Contents_cUnk16             = 0x16,  //
 
        Contents_cContentsCount
    };

    static constexpr u32 cNumContentsType = static_cast<u32>(Contents_cContentsCount);
    
public:
    BlockBase();

    // Null. Called from `initializeState_UpMove` and `initializeState_UpMoveSpawn`.
    virtual void onUpMoveStart();

    // Null. Called from `initializeState_DownMove`.
    virtual void onDownMoveStart();

    // Null. Called from `initializeState_DownMoveSpawn`.
    virtual void onDownMoveSpawnStart();

    // Null. Called from `executeState_UpMove`.
    virtual void onUpMove();

    // Null. Called from `executeState_UpMoveSpawn`.
    virtual void spawnItemUp();

    // Null. Called from `executeState_DownMove`.
    virtual void onDownMove();

    // Null. Called from `executeState_DownMoveEnd`.
    virtual void onDownMoveEnd();

    // Null. Called from `executeState_DownMoveSpawn`.
    virtual void spawnItemDown();

    // Null. Called from `executeState_DownMoveSpawnEnd`.
    virtual void onDownMoveSpawnEnd();

    // Sets x and y scale based on _1284 and _1288
    virtual void doScaleEffect(u8 arg);

    // Spawns a `Jumpdai` (Springboard) from the block.
    virtual ActorBase* spawnJumpdai();

    // Spawns an `ActorBlockHatenaCap` (Gold brick hat) from the block.
    virtual void spawnHatenaCap();

    // Null. Used to change the block into a coin while a P-Switch is active.
    virtual void changeToCoin();

    // States used when a block is hit.
    DECLARE_STATE_VIRTUAL_ID_BASE(BlockBase, UpMove);
    DECLARE_STATE_VIRTUAL_ID_BASE(BlockBase, UpMoveEnd);
    DECLARE_STATE_VIRTUAL_ID_BASE(BlockBase, DownMove);
    DECLARE_STATE_VIRTUAL_ID_BASE(BlockBase, DownMoveEnd);

    // States used when a block is hit and spawns something.
    DECLARE_STATE_VIRTUAL_ID_BASE(BlockBase, UpMoveSpawn);
    DECLARE_STATE_VIRTUAL_ID_BASE(BlockBase, DownMoveSpawn);
    DECLARE_STATE_VIRTUAL_ID_BASE(BlockBase, DownMoveSpawnEnd);

    // Returns true if the block is to the right of `player`.
    // Handles special case for screen wrap.
    bool isRightOfPlayer(PlayerObject* player);

    // Hit direction related.
    s32 sub_432BC0();

    // Sets `this->contents` to either `Contents_cCoin` or `Contents_cStar` depending on the player's star status.
    void resolveStarChainContents(Contents* contents, u8 playerId);

    // Initializes `this->headSensor` and `this->bgCollision`.
    void initalizeCollision();

    // Collision related
    void sub_43326C(PlayerObject* player);

    // Item Spawning related.
    void sub_43332C(const Vec3f& position, u32 unk1, u32 unk2, u32 unk3, u32 unk4);

    // Item Spawning related.
    void spawnItem(const Vec3f& position, u32 unk1, u32 unk2, u32 unk3, bool isRouletteBlock);

    // Creates a an instance of FunkaCoin with some preset settings (used by gold block when spewing coins)
    void spawnGoldBlockEruption();

    // Sets sensor `this->headSensor` in slot 2 on `this->collisionCheck`.
    void sub_433754();

    // Initializes stuff for onCreate.
    void sub_433768(f32 a1);

    // Unsets sensor in slot 2 on `this->collisionCheck`.
    void sub_43383C();

    // Resets some pre-frame for onExecute.
    void sub_43384C();

    // Item spawning related.
    void sub_433990(const Vec3f& position, u32 unk1, u32 unk2, u32 unk3, u32 unk4);

    // Item spawning related.
    void sub_433A1C(const Vec3f& position, u32 unk1, u32 unk2, u32 unk3);

    // Handles collision with shells. Returns true on hit.
    bool isHitShell(Shell* shell, ActorBgCollisionCheck* collisionCheck, u8 hitDirection);

    // -- REIMPLEMENTED -- 
    void spawnContents(const Vec3f& position, u32 unk1, u32 unk2, u32 unk3, bool isRouletteBlock);

    // Callback for bottom inactive collision.
    static void bottomCallbackInactive(BgCollision* collision, ActorBgCollisionCheck* collisionCheck);

    // Callback for adjacent inactive collision.
    static void adjacentCallbackInactive(BgCollision* collision, ActorBgCollisionCheck* collisionCheck, Direction direction);
    
    // Unknown Callback for top collision.
    static void topCallbackUnk(BgCollision* collision, ActorBgCollisionCheck* collisionCheck);
    
    // Callback for top collision.
    static void collisionCallbackTop(BgCollision* collision, ActorBgCollisionCheck* collisionCheck);

    // Callback for top inactive collision.
    static void topCallbackInactive(BgCollision* collision, ActorBgCollisionCheck* collisionCheck);

    // Called from topCallbackInactive.
    static void sub_433EB0(BgCollision* collision, ActorBgCollisionCheck* collisionCheck);

    // Called from bottomCallbackInactive.
    static void sub_434170(BgCollision* collision, ActorBgCollisionCheck* collisionCheck);

    // Called from sideCallbackInactive.
    static void sub_434170(BgCollision* collision, ActorBgCollisionCheck* collisionCheck, Direction direction);
    
protected:
    /* 0x0FEC */  ActorBgCollisionCheck::Sensor headSensor; // 
    /* 0x0FF8 */  RectCollider bgCollision;                 //
    
    /* 0x1268 */  struct {
        /* 0x0 */  Vec2f p0;                                //
        /* 0x4 */  Vec2f p1;                                //
    } bgCollisionOffsets;                                   //

    /* 0x1278 */  u8 _1278[4];                              //
    /* 0x127C */  f32 _127C;                                //
    /* 0x1280 */  f32 bumpPosOffsetY;                       // Inited to 0.0
    /* 0x1284 */  f32 _1284;                                // Inited to 1.0
    /* 0x1288 */  f32 _1288;                                // Inited to 0.054688
    /* 0x128C */  f32 _128C;                                // Inited to 1.2812
    /* 0x1290 */  f32 _1290;                                //
    /* 0x1294 */  u32 _1294;                                //
    /* 0x1298 */  Contents contents;                        //
    /* 0x129C */  s32 hitPlayerID;                          //
    /* 0x12A0 */  Direction spawnDirection;                 //
    /* 0x12A1 */
    /* 0x12A2 */
    /* 0x12A3 */
    /* 0x12A4 */  u32 downMoveEndTimer;                     // Used in `StateID_DownMoveEnd` and `StateID_DownMoveSpawnEnd` to delay calling `this->onDownMoveEnd()`.
    /* 0x12A8 */  u32 _12A8;                                //
    /* 0x12AC */  u32 _12AC;                                //
    /* 0x12B0 */  u32 _12B0;                                //
    /* 0x12B4 */  u32 _12B4;                                //
    /* 0x12B8 */  u16 _12B8;                                //
    /* 0x12BC */  u8 _12BC[5];                              //
    /* 0x12BF */  u8 _12BF;                                 //
    /* 0x12C0 */  s8 _12C0;                                 //
    /* 0x12C1 */  u8 _12C1;                                 //
    /* 0x12C2 */  u8 _12C2;                                 //
    /* 0x12C3 */  u8 _12C3;                                 //
    /* 0x12C4 */  u8 _12C4;                                 //
    /* 0x12C5 */  u8 _12C5;                                 //
    /* 0x12C6 */  u8 _12C6;                                 //
    /* 0x12C7 */  u8 _12C7;                                 //
    /* 0x12C8 */  u8 hitDirection;                          //
    /* 0x12C9 */  u8 unkPlayerIdx;                          //
    /* 0x12CA */  u8 _12CA;                                 //
    /* 0x12CB */  u8 _12CB;                                 //
    /* 0x12CC */  u8 _12CC;                                 //
    /* 0x12CD */  u8 _12CD;                                 //
    /* 0x12CE */  bool forceSpawnContents;                  //
    /* 0x12CF */  u8 _12CF;                                 //
    /* 0x12D0 */  u32 _12D0;                                //

    /* 0x12D4 */  struct {
        /* 0x0 */  u8 _0[4];                                 // Unknown
        /* 0x4 */  s8 _4;                                    //
        /* 0x5 */  s8 _5;                                    //
        /* 0x6 */  s8 _6;                                    //
        /* 0x7 */  u8 _7;                                    //
    } _12D4[2];                                              //
};

size_assert(BlockBase, 0x12E4);
