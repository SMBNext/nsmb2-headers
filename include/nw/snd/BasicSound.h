#pragma once

#include "nw/snd/MoveValue.h"
#include "types.h"

namespace nw {
namespace snd {

class SoundHandle;

enum PanMode
{
    PAN_MODE_DUAL    = 0x0,
    PAN_MODE_BALANCE = 0x1,
    PAN_MODE_INVALID = 0x2
};

// Size: 0x28
struct SoundParam
{
    /* 0x00 */  f32 volume;             //
    /* 0x04 */  f32 pitch;              //
    /* 0x08 */  f32 pan;                //
    /* 0x0C */  f32 span;               //
    /* 0x10 */  f32 fxSend;             //
    /* 0x14 */  f32 lpf;                //
    /* 0x18 */  f32 biquadFilterValue;  //
    /* 0x1C */  s32 biquadFilterType;   //
    /* 0x20 */  s32 priority;           //
    /* 0x24 */  u32 userData;           //
};

size_assert(SoundParam, 0x28);

namespace internal {

// Size: 0xC
struct SoundActorParam
{
    /* 0x0 */  f32 volume;  //
    /* 0x4 */  f32 pitch;   //
    /* 0x8 */  f32 pan;     //
};

size_assert(SoundActorParam, 0xC);

// Size: 0xF4
class BasicSound
{
public:
    enum PlayerState : u8
    {
        PLAYER_STATE_INIT     = 0x0,
        PLAYER_STATE_PREPARED = 0x1,
        PLAYER_STATE_PLAY     = 0x2,
        PLAYER_STATE_STOP     = 0x3
    };

    enum PauseState : u8
    {
        PAUSE_STATE_NORMAL    = 0x0,
        PAUSE_STATE_PAUSING   = 0x1,
        PAUSE_STATE_PAUSED    = 0x2,
        PAUSE_STATE_UNPAUSING = 0x3
    };

    // Size: 0x14
    struct AmbientInfo
    {
        /* 0x00 */  void* paramUpdateCallback;   // BasicSound::AmbientParamUpdateCallback
        /* 0x04 */  void* argUpdateCallback;     // BasicSound::AmbientArgUpdateCallback
        /* 0x08 */  void* argAllocatorCallback;  // BasicSound::AmbientArgAllocatorCallback
        /* 0x0C */  void* arg;                   //
        /* 0x10 */  u32 argSize;                 //
    };
    size_assert(AmbientInfo, 0x14);

public:
    void FadeIn(s32 frames);
    void Stop(s32 fadeFrames);
    void Pause(bool flag, s32 fadeFrames);

    void SetVolume(f32 volume, s32 frames);
    void SetPitch(f32 pitch);
    void SetPan(f32 pan);
    void SetPanMode(PanMode panMode);
    void SetBiquadFilter(s32 type, f32 value);

public:
    /* 0x00 */  void* vtable;                         // BasicSound_vtbl*
    /* 0x04 */  void* playerHeap;                     // PlayerHeap*
    /* 0x08 */  SoundHandle* generalHandle;           //
    /* 0x0C */  SoundHandle* tempGeneralHandle;       //
    /* 0x10 */  void* soundPlayer;                    // SoundPlayer*
    /* 0x14 */  void* soundActor;                     // SoundActor*
    /* 0x18 */  void* extSoundPlayer;                 // ExternalSoundPlayer*
    /* 0x1C */  AmbientInfo ambientInfo;              //
    /* 0x30 */  SoundParam ambientParam;              //
    /* 0x58 */  SoundActorParam actorParam;           //
    /* 0x64 */  MoveValue<f32, s32> fadeVolume;       //
    /* 0x74 */  MoveValue<f32, s32> pauseFadeVolume;  //
    /* 0x84 */  bool initializeFlag;                  //
    /* 0x85 */  bool startFlag;                       //
    /* 0x86 */  bool startedFlag;                     //
    /* 0x87 */  bool autoStopFlag;                    //
    /* 0x88 */  bool fadeOutFlag;                     //
    /* 0x89 */  bool playerAvailableFlag;             //
    /* 0x8A */  PlayerState playerState;              //
    /* 0x8B */  PauseState pauseState;                //
    /* 0x8C */  bool unPauseFlag;                     //
    /* 0x8D */  u8 _8D[3];                            // padding
    /* 0x90 */  s32 autoStopCounter;                  //
    /* 0x94 */  u32 updateCounter;                    //
    /* 0x98 */  u8 priority;                          //
    /* 0x99 */  s8 biquadFilterType;                  //
    /* 0x9A */  u8 _9A[2];                            // padding
    /* 0x9C */  u32 id;                               //
    /* 0xA0 */  MoveValue<f32, s32> extMoveVolume;    //
    /* 0xB0 */  f32 initVolume;                       //
    /* 0xB4 */  f32 extPan;                           //
    /* 0xB8 */  f32 extPitch;                         //
    /* 0xBC */  f32 lpfFreq;                          //
    /* 0xC0 */  f32 biquadFilterValue;                //
    /* 0xC4 */  f32 mainSend;                         //
    /* 0xC8 */  f32 fxSend[2];                        //
    /* 0xD0 */  f32 extSurroundPan;                   //
    /* 0xD4 */  u8 priorityLink[0x8];                 // ut::LinkListNode
    /* 0xDC */  u8 soundPlayerPlayLink[0x8];          // ut::LinkListNode
    /* 0xE4 */  u8 soundPlayerPriorityLink[0x8];      // ut::LinkListNode
    /* 0xEC */  u8 extSoundPlayerPlayLink[0x8];       // ut::LinkListNode
};

size_assert(BasicSound, 0xF4);

} // namespace internal
} // namespace snd
} // namespace nw
