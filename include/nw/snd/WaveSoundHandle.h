#pragma once

#include "nw/snd/WaveSound.h"
#include "types.h"

namespace nw {
namespace snd {

class SoundHandle;

// Size: 0x4
class WaveSoundHandle
{
public:
    WaveSoundHandle(SoundHandle* handle);
    void DetachSound();

public:
    /* 0x0 */  internal::WaveSound* pSound;     //
};

size_assert(WaveSoundHandle, 0x4);

} // namespace snd
} // namespace nw
