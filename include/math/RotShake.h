#pragma once

#include "types.h"

class RotShake
{
    struct Arg
    {
        s32 mCurrentValue = 0;              // 0x00 — Output shake value (applied each frame)
        s32 mPhase = 0;                     // 0x04 — Phase in waveform
        s32 mFrequency = 32;                // 0x08 — Oscillation period control
        s32 mPhaseVelocity = 0x20000;       // 0x0C — Rate of phase change (speed of shake)
        s32 mClampAmplitude = 0x8000000;    // x010 — Soft clamp to limit shake strength
        s32 mMaxAmplitude = 0x80000;        // 0x14 — Hard clamp for resetting/bouncing
        s32 mBounceThreshold = 0x800000;    // 0x18 — Threshold to trigger bounce reset
        s32 mDefaultValue = 0x400000;       // 0x1C — Base rotation to reset to
    };

public:
    RotShake() {};

    // Address: 0x00429B48
    void init(const Arg& arg);

    // Address: 0x00429B5C
    s32 updateShake();

    inline void resetShake() {
        mArg.mCurrentValue = mArg.mDefaultValue;
    }

private:
    Arg mArg;                           // 0x00
    bool mBounced = false;              // 0x20
};
