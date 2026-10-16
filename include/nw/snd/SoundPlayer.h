#pragma once

#include "types.h"

namespace nw {
namespace snd {

// Size: 0x48
class SoundPlayer
{
public:
    void StopAllSound(s32 fadeFrames);
    void PauseAllSound(bool pause, s32 fadeFrames);
    void SetVolume(f32 volume);

public:
    /* 0x00 */  u8 soundList[0xC];       // SoundPlayer::SoundList
    /* 0x0C */  u8 priorityList[0xC];    // SoundPlayer::PriorityList
    /* 0x18 */  u8 playerHeapList[0xC];  // SoundPlayer::PlayerHeapList
    /* 0x24 */  s32 playableCount;       //
    /* 0x28 */  s32 playableLimit;       //
    /* 0x2C */  f32 volume;              //
    /* 0x30 */  f32 lpfFreq;             //
    /* 0x34 */  s32 biquadType;          //
    /* 0x38 */  f32 biquadValue;         //
    /* 0x3C */  f32 mainSend;            //
    /* 0x40 */  f32 fxSend[2];           //
};

size_assert(SoundPlayer, 0x48);

} // namespace snd
} // namespace nw
