#pragma once

#include "nw/snd/BasicSound.h"
#include "nw/snd/MoveValue.h"
#include "types.h"

namespace nw {
namespace snd {

class StreamSoundHandle;

namespace internal {

// Size: 0x2BCC
class StreamSound : public BasicSound
{
public:
    s32 GetPlaySamplePosition() const;

public:
    /* 0x00F4 */  u8 streamSoundPlayerInstance[0x1C5C];  // driver::StreamSoundPlayer
    /* 0x1D50 */  u8 streamSoundLoader[0xC2C];           // driver::StreamSoundLoader
    /* 0x297C */  StreamSoundHandle* tempSpecialHandle;  //
    /* 0x2980 */  void* manager;                         // SoundInstanceManager<StreamSound>*
    /* 0x2984 */  MoveValue<f32, s32> trackVolume[4];    //
    /* 0x29C4 */  void* fileStream;                      // io::FileStream*, unused
    /* 0x29C8 */  u32 fileStreamBuffer[0x80];            //
    /* 0x2BC8 */  u16 allocTrackFlag;                    //
    /* 0x2BCA */  bool initializeFlag;                   //
    /* 0x2BCB */  u8 _2BCB;                              // padding
};

size_assert(StreamSound, 0x2BCC);

} // namespace internal
} // namespace snd
} // namespace nw
