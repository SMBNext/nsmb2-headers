#pragma once

#include "actors/ActorUniqueID.h"
#include "nw/snd/BasicSound.h"
#include "nw/snd/SoundHandle.h"
#include "sead/heap/seadDisposer.h"
#include "types.h"


class SoundRelated_28;

// Unknown; likely related to one of several bcsar players
// Size: 0x68
class SoundRelated
{
    SEAD_SINGLETON_DISPOSER(SoundRelated);
public:
    virtual ~SoundRelated();

    void playGlobalSfx(u32 id);
    bool holdGlobalSfx(u32 id);

    bool holdSound(nw::snd::SoundHandle* handle, s32 soundId);
    s32 prepareSound(nw::snd::SoundHandle* handle, s32 soundId, s32 startOffset);
    bool fadeIn(const char* streamName, s32 fadeFrames);

    const char* getSfxNameById(u32 id);
    s32 getSfxIdByName(const char* name);
    u32 getMusicStreamSoundId();

    void setPlayerVolume(u32 playerId, f32 volume);
    f32 getPlayerVolume(u32 playerId);
    void pauseAllSfxPlayers(s32 fadeFrames);
    void unpauseAllSfxPlayers(s32 fadeFrames);
    static void unmuteAllSfxPlayers();

    void setPitchOfAllHandles(f32 pitch);
    void setVolumeOfAllHandles(f32 volume, s32 frames);
    void pauseHandle(nw::snd::SoundHandle* handle, s32 fadeFrames);
    void unpauseHandle(nw::snd::SoundHandle* handle, s32 fadeFrames);

    void pausePlayerSounds(u32 playerId, s32 fadeFrames);
    void stopPlayerSounds(u32 playerId, s32 fadeFrames);
    void stopSoundById(s32 soundId, s32 fadeFrames);
    void stopAllHandles(s32 fadeFrames);
    void stopAndFreeHandleList(s32 fadeFrames);
    void stopMusicStreams(s32 fadeFrames);

    /* 0x14 */  u32 _14;                                  //
    /* 0x18 */  void* audioMgr;                           // sead::AudioMgr*
    /* 0x1C */  u32 soundHeapState;                       //
    /* 0x20 */  bool headphoneStatus;                     //
    /* 0x21 */  bool prevHeadphoneStatus;                 //
    /* 0x22 */  u8 _22[2];                                // padding
    /* 0x24 */  void* audioPlayer;                        // sead::AudioPlayerCtr*
    /* 0x28 */  SoundRelated_28* _28;                     //
    /* 0x2C */  nw::snd::SoundHandle musicStreamHandle;   // primary BGM stream
    /* 0x30 */  nw::snd::SoundHandle musicStreamHandle2;  // secondary BGM stream
    /* 0x34 */  sead::ListImpl handleList;                //
    /* 0x40 */  u8 _40[32];                               //
    /* 0x60 */  nw::snd::SoundHandle musicTrackHandle;    // MusicTrackMgr::playTrackById
    /* 0x64 */  bool hurryUpPlayed;                       //
    /* 0x65 */  u8 _65[3];                                // padding
};

size_assert(SoundRelated, 0x68);

// Unknown; Between SafeStringBase (14 length) and CriticalSection (15 length)
// Size: 0x38
// Vtable: 0x005D19B4
class SoundRelated_28 : public sead::IDisposer
{
public:
    nw::snd::SoundHandle* getFreeHandle();
    nw::snd::SoundHandle* allocHandleForActor(ActorUniqueID actorId);
    nw::snd::SoundHandle* findOrAllocHandle(s32 soundId, bool stopSound);
    nw::snd::SoundHandle* getHandleById(s32 soundId, bool stopSound);
    nw::snd::SoundHandle* findSoundHandle(ActorUniqueID actorId, u32 soundId, bool stopSound);
    void stopSoundById(s32 soundId, s32 fadeFrames);

    /* 0x10 */  nw::snd::SoundHandle* soundHandles;  //
    /* 0x14 */  u32 handleCount;                     //
    /* 0x18 */  u8 _18;                              // set to 1 at init
    /* 0x19 */  u8 _19[3];                           // padding
    /* 0x1C */  void* _1C;                           // mStartEnd.mNext, user-param bit 0x100
    /* 0x20 */  void* _20;                           // mStartEnd.mPrev
    /* 0x24 */  u32 _24;                             // mCount
    /* 0x28 */  void* _28;                           // mStartEnd.mNext, user-param bit 0x400
    /* 0x2C */  void* _2C;                           // mStartEnd.mPrev
    /* 0x30 */  u32 _30;                             // mCount
    /* 0x34 */  u32* handleActorIds;                 // per handle, parallel to soundHandles[]
};

size_assert(SoundRelated_28, 0x38);
