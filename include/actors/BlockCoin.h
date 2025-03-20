#pragma once

#include "actors/ActorMultiState.h"
#include "collider/RectCollider.h"
#include "course/PairChild.h"


class BlockCoinBase : public ActorMultiState
{
    SEAD_RTTI_OVERRIDE(BlockCoinBase, ActorMultiState);

public:
    BlockCoinBase();

    virtual void vf110();               // nullsub
    virtual void vf114();               // nullsub
    virtual void vf118();               // nullsub
    virtual void vf11C();               // nullsub
    virtual void spawnItemUp();         // nullsub
    virtual void vf124();               // nullsub
    virtual void vf128();               // nullsub
    virtual void spawnItemDown();       // nullsub
    virtual void vf130();               // nullsub
    virtual void vf134(bool);           // sets x and y scale based on _1284 and _1288
    virtual ActorBase* spawnSpringboard();  // also plays sfx
    virtual void spawnGoldBlock();      // nullsub
    virtual void vf140();               // nullsub

    // State: 0x6150F0
    virtual void vf144();               // adds 2.0f to position.z, sets _1290, calls vf110 and plays SE_O_Block_BOUND
    virtual void vf148();               // sets speed.y, calls vf134(), adds speed to position, updates collionMgr and calls vf11C()
    virtual void vf14C();               // nullsub

    // State: 0x615114
    virtual void vf150();               // sets _12CC to 0
    virtual void vf154();               // calls doStateChange(0x615138)
    virtual void vf158();               // nullsub

    // State: 0x615138
    virtual void vf15C();               // adds 2.0f to position.z, sets speed.y to -2.0f, _1290 to 0.281f and calls vf114()
    virtual void vf160();               // adds speed to position, updates colliosionMgr, calls vf114()
    virtual void vf164();               // nullsub

    // State: 0x61515C
    virtual void vf168();               // sets _12A4 to 6
    virtual void vf16C();               // _12A4--, calls vf128() if == 0
    virtual void vf170();               // nullsub

    // State: 0x615180
    virtual void vf174();               // position.z += 2.0f, _1280 = 0.0f, calls vf110(), inits collison sensor, plays SE_O_Block_BOUND
    virtual void vf178();               // speed.y -= 0.281f, calls vf134(), updates _1280, updates collisionCheck, eventually calls vf120()
    virtual void vf17C();               // nullsub

    // State: 0x6151A4
    virtual void vf180();               // position.z += 2.0f, _1280 = 0.0f, speed.y = -2.0f, calls vf118()
    virtual void vf184();               // speed.y += 0.281f, calls vf134(), updates _1280, updates collisionCheck, eventually calls vf12C()
    virtual void vf188();               // nullsub

    // State: 0x6151C8
    virtual void vf18C();               // sets _12A4 to 6
    virtual void vf190();               // _12A4--, calls vf130() if == 0
    virtual void vf194();               // nullsub

    
    u8 _unkFEC[0xFF8-0xFEC];            // FEC

    RectCollider solidCollider;         // FF8

    u8 _unk1268[0x1280-0x1268];         // 1268

    f32 bumpYPositionOffset;            // 1280 Inited to 0.0
    f32 _1284;                          // 1284 Inited to 1.0
    f32 _1288;                          // 1288    
    u32 _128C;                          // 128C Inited to f32 at 0x579CA4 = 0.054688
    f32 _1290;                          // 1290 yAcceleration?
    u32 _1294;                          // 1294 Inited to 0

    u8 _unk1298[0x12A0-0x1298];         // 1298

    u32 activateDirection;              // 12A0
    u32 _12A4;                          // 12A4

    u8 _unk12A8[0x12AC-0x12A8];         // 12A8

    u32 _12AC;                          // 12AC

    u8 _unk12B0[0x12B4-0x12B0];         // 12B0

    u32 _12B4;                          // 12B4 Inited to 0

    u8 _unk12B8[0x12C1-0x12B8];         // 12B8

    u8 _12C1;                           // 12C1
    u8 _12C2;                           // 12C2
    u8 _12C3;                           // 12C3
    u8 _12C4;                           // 12C4
    u8 _12C5;                           // 12C5 Inited to 0

    u8 _unk12C6[0x12CA-0x12C6];         // 12C6

    u8 _12CA;                           // 12CA Inited to 0
    u8 _12CB;                           // 12CB Inited to 0
    u8 _12CC;                           // 12CC Inited to 0
    u8 _12CD;                           // 12CD Inited to 0
    u8 _12CE;                           // 12CE Inited to 0

    u8 _unk12CF;                        // 12CF

    u32 _12D0;                          // 12D0 Inited to 0

    u8 _unk12D4[0x12F0-0x12D4];         // 12D4 Might belong (partly) to dereived classes
};


class BlockCoinPairChildBase : public BlockCoinBase
{
    SEAD_RTTI_OVERRIDE(BlockCoinPairChildBase, BlockCoinBase);

public:
    BlockCoinPairChildBase();

    void spawnItemUp() override;        // _1280 = 0.0f, doStateChange(0x615A04)
    void spawnItemDown() override;      // calls spawnItemUp()
    void vf140() override;              

    virtual void vf198();               // nullsub
    virtual void vf19C();               // swawns a tile at the block position?
    virtual void vf1A0();               // erases the actor
    virtual bool vf1A4();               // checks for something at position _12F0


    Vec3f blockStatePos;                 // 12F0
    PairChild pairChild;                // 12FC

    u8 _unk13CC[0x13F4-0x13CC];         // 13CC

    f32 _13F4;                          // 13F4 Inited to 0.0f
    f32 _13F8;                          // 13F8 Inited to 0.0f

    u8 _unk13FC[0x1400-0x13FC];         // 13FC

    u8 _1400;                           // 1400 Inited to 0
    u32 tileId;                         // 1404
    u32 movementType;                   // 1408 Inited to 0
    u32 blockMovementId;                // 140C Inited to 0
    u32 _1410;                          // 1410 Inited to 0

    u8 _unk1414[0x141C-0x1414];         // 1414

    u8 _141C;                           // 141C Inited to 0

    u8 _unk141D[0x1426-0x141D];         // 141D

    u16 _1426;                          // 1426

    u8 _unk1428[0x142A-0x1428];         // 1428

    u16 _142A;                          // 142A
    u16 _142C;                          // 142C

    u8 _unk142E[2];                     // 142E

    // Non-virtual states: 0x6159E4, 0x615A04, 0x0615A24
};


class BlockBase : public BlockCoinPairChildBase     // size: max 0x1450
{
    SEAD_RTTI_OVERRIDE(BlockBase, BlockCoinPairChildBase);

public:
    BlockBase();

    int onExecute() override;
    int onDraw() override;

    void powActivated() override;       // if _1420 == 1: doStateChange(0x615A24)

    void vf118() override;              // inits collision sensor
    void spawnItemUp() override;        // changes tile to used block, more
    void spawnItemDown() override;      // inits collision sensor, changes tile to used block, more
    void vf130() override;              // doStateChange(0x613E00)

    virtual bool fetchInitialState();   // returns true if not destroyed
    virtual void vf1AC();               // nullsub
    virtual u8 getContents();           // returns spriteData2 & 0xF
    virtual void vf1B4();
    virtual void vf1B8();
    virtual void vf1BC();
    virtual void vf1C0();
    virtual bool doCullCheck();         // calls cullCheck(0)
    virtual void vf1C8();
    virtual void vf1CC();
    virtual void vf1D0();

    DECLARE_STATE_VIRTUAL_ID_BASE(BlockBase, Wait);
    DECLARE_STATE_VIRTUAL_ID_BASE(BlockBase, Used);


    bool init(bool addColliderToList);
    
    void linkPairChild();
    void updatePairChild();


    u8 _1430[0x1444-0x1430];            // 1430 Might belong (partly) to base class or overshoot actual size

    u32 colliderCallbackType;           // 1444 0=None? 1=Active, 2,3=Inactive

    u8 _1448[0x1450-0x1448];            // 1448 Might belong (partly) to base class or overshoot actual size
};



class BlockStateMgr
{
public:
    enum State
    {
        STATE_UNUSED = 0,
        STATE_USED = 1,
    };

    static BlockStateMgr* instance;

    u8 getBlockState(const Vec3f& position, u8 areaId);
    void setBlockState(const Vec3f& position, u8 state, u8 areaId);
};
