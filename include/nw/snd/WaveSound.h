#pragma once

#include "nw/snd/BasicSound.h"
#include "types.h"

namespace nw {
namespace snd {

class WaveSoundHandle;

namespace internal {

// Size: 0x460
class WaveSound : public BasicSound
{
public:
    enum LoadState : u8
    {
        LOAD_STATE_NONE     = 0x0,
        LOAD_STATE_LOADING  = 0x1,
        LOAD_STATE_LOADED   = 0x2,
        LOAD_STATE_PREPARED = 0x3,
        LOAD_STATE_FAILED   = 0x4
    };

    // Size: 0x14
    struct StartInfo
    {
        /* 0x00 */  s32 index;             //
        /* 0x04 */  u8 startOffsetType;    // driver::WaveSoundPlayer::StartOffsetType
        /* 0x05 */  u8 _5[3];              // padding
        /* 0x08 */  s32 startOffset;       //
        /* 0x0C */  const void* callback;  // const driver::WaveSoundPlayer::WaveSoundCallback*
        /* 0x10 */  u32 callbackData;      //
    };
    size_assert(StartInfo, 0x14);

    // Size: 0x40
    struct DataLoadTask
    {
        /* 0x00 */  u8 task[0x1C];           // Task
        /* 0x1C */  void* dataManager;       // PlayerHeapDataManager*
        /* 0x20 */  void* allocator;         // PlayerHeap*
        /* 0x24 */  void* callback;          // WaveSound::NotifyAsyncLoadFinished
        /* 0x28 */  void* callbackData;      //
        /* 0x2C */  void* soundDataManager;  // const SoundDataManager*
        /* 0x30 */  void* soundArchive;      // const SoundArchive*
        /* 0x34 */  u8 loadInfoWsd[0x8];     // SoundArchiveLoader::LoadItemInfo
        /* 0x3C */  s32 index;               //
    };
    size_assert(DataLoadTask, 0x40);

public:
    void SetChannelPriority(s32 priority);
    void SetReleasePriorityFix(bool fix);
    s32 GetPlaySamplePosition() const;

public:
    /* 0x0F4 */  u8 waveSoundPlayerInstance[0x9C];    // driver::WaveSoundPlayer
    /* 0x190 */  WaveSoundHandle* tempSpecialHandle;  //
    /* 0x194 */  void* manager;                       // WaveSoundInstanceManager*
    /* 0x198 */  DataLoadTask dataLoadTask;           //
    /* 0x1D8 */  u8 dataManager[0x264];               // PlayerHeapDataManager
    /* 0x43C */  StartInfo startInfo;                 //
    /* 0x450 */  const void* wsdFile;                 //
    /* 0x454 */  const void* waveFile;                //
    /* 0x458 */  u32 loadRequestCount;                //
    /* 0x45C */  LoadState loadingFlag;               //
    /* 0x45D */  bool initializeFlag;                 //
    /* 0x45E */  bool preparedFlag;                   //
    /* 0x45F */  u8 _45F;                             // padding
};

size_assert(WaveSound, 0x460);

} // namespace internal
} // namespace snd
} // namespace nw
