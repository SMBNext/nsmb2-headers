#pragma once

#include "nw/snd/StreamSound.h"
#include "types.h"

namespace nw {
namespace snd {

class SoundHandle;

// Size: 0x4
class StreamSoundHandle
{
public:
    StreamSoundHandle(SoundHandle* handle);
    void DetachSound();

public:
    /* 0x0 */  internal::StreamSound* pSound;   //
};

size_assert(StreamSoundHandle, 0x4);

} // namespace snd
} // namespace nw
