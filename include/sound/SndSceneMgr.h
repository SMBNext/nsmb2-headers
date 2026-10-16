#pragma once

#include "sead.h"
#include "sound/SoundId.h"

// Size: 0x50
class SndSceneMgr
{
    SEAD_SINGLETON_DISPOSER(SndSceneMgr);
public:
    virtual ~SndSceneMgr();

    enum class MusicState : u8
    {
        cNone                   = 0x00,
        cStopAll                = 0x02,
        cTitle                  = 0x03,
        cCoinRushWin            = 0x05,
        cCoinRushLose           = 0x06,
        cCourseSelect           = 0x07,

        cInCourse               = 0x64,
        cBossOrCannon           = 0x65,
        cMegaChange             = 0x66,
        cMusicChangePending     = 0x67,
        cAreaChange             = 0x68,
        cBossPending            = 0x69,
        cBossPendingCoop        = 0x6A,
        cStopMusic              = 0x6B,
        cCannonEnter            = 0x6C,
        cCannonLaunch           = 0x6D,
        cPausingInCourse        = 0x6E,
        cPausingBossOrCannon    = 0x6F,
        cPausedInCourse         = 0x70,
        cPausedBossOrCannon     = 0x71,

        cBossDemo               = 0xC8,
        cWorldSelected          = 0xC9,
        cCourseIntro            = 0xCA,
        cLevelEnd               = 0xCB,
        cCourseOut              = 0xCC,
        cLastBossHarp           = 0xCD,
        cOpeningDemo            = 0xCE,
        cStaffCredits           = 0xCF,
    };

    void stopAll();
    void stopAllActorPlayers();
    void stopAudio(bool longFade);
    void fadeOutAudio();
    void stopMusic();

    void pauseAudio(s32 fadeFrames);
    void resumeAudio(s32 fadeFrames);
    void muteAllSfxPlayers();
    void muteForCourseClear();
    void setSystemExVolume(f32 volume);

    void playDialogueIn();
    void restoreMusicVolume();

    void playCourseMusic();
    void playBossMusic();
    void playBossBeatenFanfare();
    void playHurryUp();
    void playCourseClearMusic(bool isZoro, bool isBig); // original - 0028B21C
    void playWorldSelected();
    void playCourseIntro();
    void playGameOver();
    void playCoinFanfare(u32 coinCount);

    void startBossDemo(s32 fadeTimer);
    void updateBossDemo();
    void startAllBubbleOut();
    void updateAllBubbleOut();

    void musicStopRelated(bool dontStopMusic);
    void enableCourseMusic();

    u32 getCurrentZoneMusicId();
    u32 getPlayingMusicId();

    /* 0x14 */  MusicState musicState;     //
    /* 0x15 */  u8 _15[3];                 // padding
    /* 0x18 */  f32 fxSendLevel;           //
    /* 0x1C */  f32 panWidth;              //
    /* 0x20 */  u32 goldRingIsActive;      //
    /* 0x24 */  u32 goldRingWasActive;     //
    /* 0x28 */  u8 isBowserPhaseActive;    //
    /* 0x29 */  u8 _29;                    //
    /* 0x2A */  u16 playerSoundVariant;    // Random between 1-2, used for player sounds as variable 0
    /* 0x2C */  u8 isAudioPaused;          //
    /* 0x2D */  u8 _2D[3];                 // padding
    /* 0x30 */  s32 pauseTransitionTimer;  //
    /* 0x34 */  s32 musicDelayTimer;       //
    /* 0x38 */  void* fxMgr;               // AudioFxMgr*
    /* 0x3C */  bool hurryUpPlayed;        //
    /* 0x3D */  u8 _3D[3];                 // padding
    /* 0x40 */  u32 prevTimeLeft;          //
    /* 0x44 */  s32 allBubbleOutTimer;     //
    /* 0x48 */  s32 bossDemoFadeTimer;     //
    /* 0x4C */  s32 musicChangeFadeTimer;  //
};

size_assert(SndSceneMgr, 0x50);
