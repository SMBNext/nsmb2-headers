#pragma once

#include "sead.h"

#include "PlayerEnum.h"

class PlayerStateData  // Size: 0x90
{
public:
    class Player  // Size: 0x18
    {
    public:
        enum PlayerId : u8
        {
            PLAYER_MARIO = 0x0,
            PLAYER_LUIGI = 0x1,
        };

        Player();                                    // PlayerStateData::Player__ctor

        bool isActive;          // 0
        u32 lifeCount;          // 4
        Powerup powerup;        // 8
        PlayerId playerID;      // 9
        u8 _A;                  // A
        u8 _B;                  // B
        u32 score;              // C
        u32 _10;                // 10
        u32 _14;                // 14
    };

    size_assert(Player, 0x18);

    class CheckPointData  // Size: 0x1C
    {
    public:
        CheckPointData();       // 001085E8
        void clear();           // 002E671C

                                // 002E6760
        void set(s32 checkPointId, s8 playerIdx, u8 unk1, f32 xPosition, f32 yPosition, u8 mode, u8 world,
             u8 level, u8 area, u8 zone, u8 entranceID, u8 unk2, bool assistLeafRelated, s8* collectionCoins);

        s32 GetCheckPointId(u8 mode, u8 world, u8 level);   // 004A193C

        s32 checkPointId;                       // 0
        u8 mode;                                // 4
        u8 worldId;                             // 5
        u8 levelId;                             // 6
        u8 destArea;                            // 7
        u8 zone;                                // 8
        u8 entranceID;                          // 9
        u8 _A;                                   // A
        bool assistLeafRelated;                 // B
        u8 _C;                                   // C
        s8 playerIdxFirst;                      // D
        s8 playerIdxSecond;                     // E
        s8 collectionCoinStatus[3];             // F
        s8 _12;                                  // 12
        s8 _13;                                  // 13
        sead::Vector2f checkPointPos;           // 14
    };

    size_assert(CheckPointData, 0x1C);

    PlayerStateData();                                              // PlayerStateData__ctor

    PlayerStateData* sync(const PlayerStateData& src);               // 004106F8

    void setLifeCount(s32 player, s32 lifeCount);                    // 004106CC
    void setInventoryItem(u8 itemId, s8 playerId);                    // 0041052C
    void enableGoldBlockFlag();
    void disableGoldBlockFlag();
    void setupForCoop();
    void nullPlayers_C();
    s32 getPlayerCount();

    u8 isCoinRush;                       // 0
    CheckPointData checkPointData;       // 4
    Player players[2];                   // 20
    u32 curCoinCount;                    // 50   counts to 99 and loops - gives life at 99
    u32 stageCoinTotal;                  // 54   caps at 9999 - total coins collected for stage
    u32 score;                           // 58
    s8 collectionCoins[3];               // 5C   star coin status (true = obtained)
    u8 _5F[36];                          // 5F
    u8 inventoryItems[2];                // 83
    u8 _85;                              // 85
    u8 _86;                              // 86
    u32 _88;                             // 88
    u8 goldBlockFlag;                    // 8C
};

size_assert(PlayerStateData, 0x90);