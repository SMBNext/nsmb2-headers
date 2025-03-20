#pragma once

#include "types.h"

#include "sead/heap/seadDisposer.h"

namespace sead {

class Graphics : public sead::IDisposer 
{
public:
    enum DevicePosture : u8
    {
        DevicePosture_Same = 0x0,
        DevicePosture_RotateRight = 0x1,
        DevicePosture_RotateLeft = 0x2,
        DevicePosture_RotateHalfAround = 0x3,
        DevicePosture_FlipXY = 0x3,
        DevicePosture_FlipX = 0x4,
        DevicePosture_Invalid = 0x4,
        DevicePosture_FlipY = 0x5,
    };

    // 005F3D98
    static Graphics* sInstance;

    // 005F3D9C
    static DevicePosture sDefaultDevicePosture;
    // 005F3DA0
    static f32 sDefaultDeviceZScale;
    // 005F3DA4
    static f32 sDefaultDeviceZOffset;
};


} // namespace sead
