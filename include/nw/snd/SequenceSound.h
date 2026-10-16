#pragma once

#include "nw/snd/BasicSound.h"
#include "types.h"

namespace nw {
namespace snd {

class SequenceSoundHandle;

namespace internal {

// Size: 0x558
class SequenceSound : public BasicSound
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

    // Size: 0xC
    struct StartInfo
    {
        /* 0x0 */  s32 seqOffset;       //
        /* 0x4 */  u8 startOffsetType;  // driver::SequenceSoundPlayer::OffsetType
        /* 0x5 */  u8 _5[3];            // padding
        /* 0x8 */  s32 startOffset;     //
    };
    size_assert(StartInfo, 0xC);

    // Size: 0x28
    struct Resource
    {
        /* 0x00 */  const void* seq;            //
        /* 0x04 */  const void* banks[4];       //
        /* 0x14 */  const void* warcs[4];       //
        /* 0x24 */  bool warcIsIndividuals[4];  //
    };
    size_assert(Resource, 0x28);

    // Size: 0x5C
    struct DataLoadTask
    {
        /* 0x00 */  u8 task[0x1C];           // Task
        /* 0x1C */  void* dataManager;       // PlayerHeapDataManager*
        /* 0x20 */  void* allocator;         // PlayerHeap*
        /* 0x24 */  void* callback;          // SequenceSound::NotifyAsyncLoadFinished
        /* 0x28 */  void* callbackData;      //
        /* 0x2C */  void* soundDataManager;  // const SoundDataManager*
        /* 0x30 */  void* soundArchive;      // const SoundArchive*
        /* 0x34 */  u8 loadInfoSeq[0x8];     // SoundArchiveLoader::LoadItemInfo
        /* 0x3C */  u8 loadInfoBanks[0x20];  // SoundArchiveLoader::LoadItemInfo[4]
    };
    size_assert(DataLoadTask, 0x5C);

public:
    void WriteVariable(s32 varNo, s16 var);
    void SetChannelPriority(s32 priority);
    void SetReleasePriorityFix(bool fix);

    u32 GetTick() const;

public:
    /* 0x0F4 */  u8 sequenceSoundPlayerInstance[0x160];   // driver::SequenceSoundPlayer
    /* 0x254 */  SequenceSoundHandle* tempSpecialHandle;  //
    /* 0x258 */  void* manager;                           // SequenceSoundInstanceManager*
    /* 0x25C */  StartInfo startInfo;                     //
    /* 0x268 */  DataLoadTask dataLoadTask;               //
    /* 0x2C4 */  u8 dataManager[0x264];                   // PlayerHeapDataManager
    /* 0x528 */  u32 loadRequestCount;                    //
    /* 0x52C */  Resource resource;                       //
    /* 0x554 */  LoadState loadingFlag;                   //
    /* 0x555 */  bool initializeFlag;                     //
    /* 0x556 */  bool preparedFlag;                       //
    /* 0x557 */  u8 _557;                                 // padding
};

size_assert(SequenceSound, 0x558);

} // namespace internal
} // namespace snd
} // namespace nw
