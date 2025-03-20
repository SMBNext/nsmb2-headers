#pragma once

#include "sead/heap/seadDisposer.h"

#include "math/Vec.h"


// Size: 0x4CA0
class ActorCoinMgr
{
    // createInstance()                             Address: 0x00250A3C
    // deleteInstance()                             Address: 0x00250A9C
    // sInstance                                    Address: 0x005E79E0
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x00250C5C
    // SingletonDisposer_::sStaticDisposer          Address: 0x005E79E4
    // SingletonDisposer_::vtbl                     Address: 0x005A8CC0
    SEAD_SINGLETON_DISPOSER(ActorCoinMgr);

public:

    // Size: 0x14
    struct UnkA
    {
        Vec2f mPos;  // 0x0
        u32 _8;     // 0x8
        u32 _C;     // 0xC
        u8 _10;     // 0x10

        // Address: 0x00250ADC
        UnkA();
    };

    // Size: 0x1C
    struct UnkB
    {
        u8 _0[28];  // 0x0

        // Address: 0x00250AD8
        UnkB();
    };

    // Size: 0x18
    struct CoinJumpInfo
    {
        Vec3f position;          // 0x0
        u8 direction;           // 0xC - 0 : right, 1 : left
        u8 numCoins;            // 0xD
        u8 upwardThrust;        // 0xE - is beaten by gravity at values less than 0xC unless coins are going upwards
        u8 _F;                  // 0xF
        u8 spread;              // 0x10 - controls the spread of the coins thrown (loops after a certain amount)
        u8 _11;                 // 0x11
        bool disableCollision;  // 0x12
        u8 _13;                 // 0x13
        u8 _14;                 // 0x14
        u8 _15;                 // 0x15
    };


    enum CoinType : u32
    {
        NORMAL = 0,
        RED    = 1,
        BLUE   = 2
    };

    // Address: 0x00251AF0
    ActorCoinMgr();

    // Address: 0x00250C90
    void execute();

    // Address: 0x00250994
    // Collect coin direct - (increments coin count directly)
    void collectCoins(const Vec2f& position, u32 numCoins, s32 playerID);

    // Address: 0x00250AE0
    // Collect coin from ground - (removes coin tile at pos, spawns pickup effect + increments coin count)
    void collectCoin(const Vec2f& position, CoinType type, s32 playerID);

    // Address: 0x00250D64
    void registerBlueCoinLocation(u32 locationID);

    // Address: 0x00250FB4
    // Returns true if target was reached
    bool incrementBlueCoinCount(u32 locationID);

    // Address: 0x00251028
    void incrementBlueCoinTarget(u32 locationID);

    // Address: 0x00251378
    void decrementBlueCoinTarget(u32 locationID);

    // Address: 0x002514DC
    void resetBlueCoinInfo();

    // Address: 0x0025121C
    void handleBlueCoinCollected(const Vec2f& position);

    // Address: 0x0025199C
    // Increments coin counter, spawns pickup effect + plays sfx
    void handleCoinCollected(const Vec2f& position, s32 playerID, CoinType type);

    // Address: 0x0025105C
    // creates a regular coin
    void createCoinJump(const CoinJumpInfo& spawnInfo, bool isAccending, bool spreadEvenly);

    // Address: 0x00251540
    // creates coins with sparkly trails
    void createCoinJumpFire(const CoinJumpInfo& spawnInfo);

    // Address: 0x002516A4
    // creates a coin erruption
    void createCoinJumpFunka(const CoinJumpInfo& spawnInfo);

    // Address: 0x00251808
    // creates a coin fountain
    void createCoinJumpFunsui(const CoinJumpInfo& spawnInfo);

    // Address: 0x002513D0
    void createCoinShowerJump(const Vec3f& position, s32 unkA, s32 unkB, u8 layer, s32 unkC, s32 unkD, bool unkE);

    // Address: 0x00250B54
    // Spawns a coin at pos...
    void unk1(const Vec2f& position, s32 unkA, s32 unkB);

    // Address: 0x00250F04
    // Collect coin from block - (spawns block hit coin effect + increments coin count)
    void unk2(const Vec2f& position, CoinType type, s32 playerID);

    // Address: 0x00251950
    void unk3();

private:
    UnkA _10[256];                        // 0x10
    UnkB _1410[512];                      // 0x1410
    bool mLocationHasBlueCoins[16];       // 0x4C10 - index of location ids 0 - 16  - used with pswitch
    u32 mBlueCoinCollectedAmount[16];     // 0x4C20 - the number of blue coins within each location the player collected
    u32 mBlueCoinTargets[16];             // 0x4C60 - the total number of blue coins within a location
};

size_assert(ActorCoinMgr, 0x4CA0);