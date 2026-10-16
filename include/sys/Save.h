#pragma once

#include "player/PlayerStateData.h"
#include "sead.h"
#include "types.h"

// Size: 0x4
class CollectionCoinStatusBase
{
public:
    virtual ~CollectionCoinStatusBase();
    virtual bool isWorldIdValid(u32 worldId);
    virtual u32 getCourseStatus(u32 worldId, u32 courseId);
    virtual void setCourseStatus(u32 worldId, u32 levelId, bool isCollected);
};

size_assert(CollectionCoinStatusBase, 0x4);


// Size: 0x88
class CollectionCoinStatus : public CollectionCoinStatusBase
{
public:
    /* 0x4 */  u32 _4;                  //
    /* 0x8 */  u32 count;               //
    /* 0xC */  u8 statusFlags[124];     //
};

size_assert(CollectionCoinStatus, 0x88);


// Size: 0x18
class MoonCoinStatus : public CollectionCoinStatusBase
{
private:
    /* 0x4 */  u32 _4;                  //
    /* 0x8 */  u8 statusFlags[16];      //
};

size_assert(MoonCoinStatus, 0x18);


// Size: 0x134
struct CollectionCoinSaveData
{
public:
    u32 getForLevel(u32 worldId, u32 levelId);
    bool getForLevel(u32 worldId, u32 levelId, u32 collectionCoinId);
    u32 setForLevel(u32 worldId, u32 levelId, u8 id);

public:
    /* 0x000 */  u8 _0[148];                        //
    /* 0x094 */  CollectionCoinStatus starCoins;    //
    /* 0x11C */  MoonCoinStatus moonCoins;          //
};

size_assert(CollectionCoinSaveData, 0x134);


// Size: 0x1058
class GameState
{
    SEAD_SINGLETON_DISPOSER(GameState);
public:
    enum class CourseExitState : u32
    {
        cReload         = 0,
        cExit           = 1,
        cClear          = 2,
        cFail           = 3,
        cInCourse       = 4,
    };

    // Size: 0x1
    struct Flag
    {
        Flag();

        /* 0x0 */  u8 value;    //
    };
    size_assert(Flag, 0x1);

    // Size: 0x1F
    class CourseFlags
    {
    public:
        CourseFlags();

    public:
        /* 0x00 */  Flag flags[31];     //
    };
    size_assert(CourseFlags, 0x1F);

    // Size: 0x80
    struct StreetPassChallenger
    {
        StreetPassChallenger();

        /* 0x00 */  u8 _0[96];          //
        /* 0x60 */  u32 _60;            // Zeroed with _64 by one STRD in the constructor
        /* 0x64 */  u32 _64;            //
        /* 0x68 */  u32 _68;            //
        /* 0x6C */  s16 _6C;            //
        /* 0x6E */  s16 coinCount;      //
        /* 0x70 */  u16 _70[3];         //
        /* 0x76 */  s8 _76;             //
        /* 0x77 */  s8 _77;             //
        /* 0x78 */  s8 _78;             //
        /* 0x79 */  s8 _79;             //
        /* 0x7A */  u8 _7A[6];          //
    };
    size_assert(StreetPassChallenger, 0x80);

public:
    bool isRainbowUnlocked(u32 levelId);
    void loadControlScheme();
    bool starCoinGateIsClosed(u16 gateFlags, u8 gateIdx);
    void setMissCount(u32 count, u32 worldId, u32 levelId);
    void incrementMissCount();
    void resetMissCount();

public:
    /* 0x0010 */  CourseExitState courseExitState;                      //
    /* 0x0014 */  u32 _14;                                              //
    /* 0x0018 */  u8 _18;                                               //
    /* 0x0019 */  u8 _19[3];                                            // padding
    /* 0x001C */  sead::FixedSafeString<260> replayPath;                //
    /* 0x012C */  u8 _12C;                                              //
    /* 0x012D */  u8 _12D;                                              //
    /* 0x012E */  u8 _12E[2];                                           // padding
    /* 0x0130 */  u32 curMode;                                          // 0: Course, 1: Debug, 2: Debug/dlc
    /* 0x0134 */  u32 curWorldID;                                       //
    /* 0x0138 */  u32 curCourseSelectNodeID;                            //
    /* 0x013C */  CollectionCoinSaveData collectionCoins;               //
    /* 0x0270 */  CourseFlags courseFlags[9];                           //
    /* 0x0387 */  Flag _387[31];                                        //
    /* 0x03A6 */  CourseFlags globalLevelFlags[9];                      //
    /* 0x04BD */  u8 _4BD[3];                                           // padding
    /* 0x04C0 */  u32 _4C0;                                             //
    /* 0x04C4 */  u16 starCoinGateFlags[9];                             // One flag per world, several gates per flag
    /* 0x04D6 */  u8 rainbowFlags[9];                                   //
    /* 0x04DF */  u8 _4DF;                                              //
    /* 0x04E0 */  u8 _4E0;                                              //
    /* 0x04E1 */  u8 _4E1[3];                                           // padding
    /* 0x04E4 */  u32 globalCoinCount;                                  //
    /* 0x04E8 */  u8 hasntSeenCredits;                                  // Credits play after the final castle when set
    /* 0x04E9 */  u8 _4E9;                                              //
    /* 0x04EA */  u8 _4EA;                                              //
    /* 0x04EB */  u8 missCounts[9][31];                                 // Capped at 5
    /* 0x0602 */  u8 _602;                                              //
    /* 0x0603 */  u8 _603;                                              //
    /* 0x0604 */  u8 _604;                                              //
    /* 0x0605 */  u8 _605;                                              //
    /* 0x0606 */  u8 _606;                                              //
    /* 0x0607 */  u8 _607;                                              //
    /* 0x0608 */  u16 levelCoinCounts[9][31];                           //
    /* 0x0836 */  u8 _836[98];                                          //
    /* 0x0898 */  u32 _898;                                             //
    /* 0x089C */  u8 _89C[11];                                          //
    /* 0x08A7 */  u8 _8A7;                                              // padding
    /* 0x08A8 */  StreetPassChallenger streetPassChallengers[15];       //
    /* 0x1028 */  u8 _1028;                                             //
    /* 0x1029 */  u8 _1029[15];                                         //
    /* 0x1038 */  u8 _1038;                                             //
    /* 0x1039 */  u8 _1039[2];                                          //
    /* 0x103B */  u8 worldCompletionFlags[9];                           //
    /* 0x1044 */  s8 _1044[3];                                          //
    /* 0x1047 */  s8 _1047[9];                                          //
    /* 0x1050 */  u8 controlScheme;                                     //
    /* 0x1051 */  u8 _1051;                                             //
    /* 0x1052 */  u8 saveFileIdx;                                       //
    /* 0x1053 */  u8 _1053;                                             //
    /* 0x1054 */  bool isCoopGuest;                                     // True for the guest player (Luigi)
    /* 0x1055 */  u8 _1055[3];                                          // padding
};

size_assert(GameState, 0x1058);


// Size: 0xA0
class LevelPlayerStateData
{
    SEAD_SINGLETON_DISPOSER(LevelPlayerStateData);
public:
    /* 0x10 */  PlayerStateData data;       //
};

size_assert(LevelPlayerStateData, 0xA0);


// Size: 0x2838
struct SaveData
{
    // Size: 0xA54
    struct File
    {
        // Size: 0x528
        struct Data
        {
            /* 0x000 */  u32 score;                 //
            /* 0x004 */  u16 lifeCount;             //
            /* 0x006 */  u8 powerup;                //
            /* 0x007 */  u8 stockPowerup;           //
            /* 0x008 */  u8 coinCount;              //
            /* 0x009 */  u8 world;                  //
            /* 0x00A */  u8 mapPos;                 //
            /* 0x00B */  u8 goldBlockFlag;          //
            /* 0x00C */  u32 starCoinCount;         //
            /* 0x010 */  u8 starCoinFlags[140];     //
            /* 0x09C */  u8 _9C[4];                 //
            /* 0x0A0 */  u8 levelFlags[9][31];      //
            /* 0x1B7 */  u8 _1B7[9];                //
            /* 0x1C0 */  u16 coinScores[9][31];     //
            /* 0x3EE */  u16 starCoinGates[9];      //
            /* 0x400 */  u8 rainbowFlags[9];        //
            /* 0x409 */  u8 openingCutsceneFlag;    //
            /* 0x40A */  u8 deathCounts[9][31];     //
            /* 0x521 */  u8 _521[7];                //
        };
        size_assert(Data, 0x528);

        /* 0x000 */  Data fileNormal;           //
        /* 0x528 */  Data fileQuickSave;        //
        /* 0xA50 */  u8 hadAllCrownLives;       //
        /* 0xA51 */  u8 _A51[3];                // padding
    };
    size_assert(File, 0xA54);

    /* 0x0000 */  u32 magic;                                //
    /* 0x0004 */  u32 _4;                                   //
    /* 0x0008 */  u32 _8;                                   //
    /* 0x000C */  u32 _C;                                   //
    /* 0x0010 */  u32 _10;                                  //
    /* 0x0014 */  u32 _14;                                  //
    /* 0x0018 */  File files[3];                            //
    /* 0x1F14 */  u32 _1F14;                                //
    /* 0x1F18 */  u32 globalCoinCount;                      //
    /* 0x1F1C */  u8 mii[0x5C];                             //
    /* 0x1F78 */  u8 _1F78[4];                              //
    /* 0x1F7C */  u8 coinRushHighScorePackFlag;             //
    /* 0x1F7D */  u8 _1F7D[3];                              //
    /* 0x1F80 */  u16 coinRushHighScore;                    //
    /* 0x1F82 */  u8 coinRushHighScoreStage[3][2];          //
    /* 0x1F88 */  u8 coinRushHighScoreTanukiFlag;           //
    /* 0x1F89 */  u8 _1F89[7];                              //
    /* 0x1F90 */  u8 streetPassChallengers[15][0x80];       //
    /* 0x2710 */  u8 controlScheme;                         //
    /* 0x2711 */  u8 _2711;                                 //
    /* 0x2712 */  u8 spotPassSetting;                       //
    /* 0x2713 */  u8 _2713;                                 //
    /* 0x2714 */  u16 streetPassCount;                      //
    /* 0x2716 */  u16 coinRushVictories;                    //
    /* 0x2718 */  u8 globalLevelFlags[9][31];               //
    /* 0x282F */  u8 coinDialogFlag;                        //
    /* 0x2830 */  u8 firstBootFlag;                         //
    /* 0x2831 */  u8 _2831;                                 //
    /* 0x2832 */  u8 _2832;                                 //
    /* 0x2833 */  u8 eShopButtonFlag;                       //
    /* 0x2834 */  u8 coinRushFirstLoadFlag;                 //
    /* 0x2835 */  u8 newStreetPassFlag;                     //
    /* 0x2836 */  u8 _2836;                                 //
    /* 0x2837 */  u8 lastFileSaved;                         //
    /* 0x2838 */  u8 _2838[0x2848-0x2838];                 // Undocumented
};

size_assert(SaveData, 0x2848);


// Size: 0x164
class SaveMgr : public sead::IDisposer
{
public:
    static SaveMgr* sInstance;

    void loadFile(u8 fileId, bool isQuickSave);
    void clearFile(u8 fileId);
    void copyFile(u8 srcFileId, u8 dstFileId);
    void saveFile(u8 fileId, bool isQuickSave);
    void setLastFileId(u8 fileId);
    void write();

    SaveData* getSaveData();

public:
    /* 0x010 */  u32 _10;                               //
    /* 0x014 */  u32 _14;                               //
    /* 0x018 */  u8 loadSaveThreadDelegate[0x10];       //
    /* 0x028 */  u8 loadSaveThread[0x8C];               //
    /* 0x0B4 */  u8 extSaveThreadDelegate[0x10];        //
    /* 0x0C4 */  u8 extSaveThread[0x8C];                //
    /* 0x150 */  u8 currentFileId;                      //
    /* 0x151 */  bool currentSaveIsQuick;               //
    /* 0x152 */  u8 _152[18];                           //
};

size_assert(SaveMgr, 0x164);
