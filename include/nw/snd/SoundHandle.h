#pragma once

#include "nw/snd/BasicSound.h"
#include "types.h"

namespace nw {
namespace snd {

// Size: 0x4
class SoundHandle
{
public:
    bool IsAttachedSound() const;
    u32 GetId() const;

    void Stop(s32 fadeFrames);
    void Pause(s32 fadeFrames);
    void UnPause(s32 fadeFrames);

    void SetVolume(f32 volume, s32 frames = 0);
    void SetPitch(f32 pitch);
    void SetPan(f32 pan);

    void detail_AttachSound(internal::BasicSound* sound);
    void DetachSound();

public:
    /* 0x0 */  internal::BasicSound* pSound;    //
};

size_assert(SoundHandle, 0x4);

} // namespace snd
} // namespace nw
