#pragma once

#include "nw/snd/SequenceSound.h"
#include "types.h"

namespace nw {
namespace snd {

class SoundHandle;

// Size: 0x4
class SequenceSoundHandle
{
public:
    SequenceSoundHandle(SoundHandle* handle);
    void DetachSound();

public:
    /* 0x0 */  internal::SequenceSound* pSound;     //
};

size_assert(SequenceSoundHandle, 0x4);

} // namespace snd
} // namespace nw
