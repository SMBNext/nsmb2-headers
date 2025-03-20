#pragma once

#include "sead.h"

// Most functionality of this class is removed in NSMB2

class CoinOrigin : public sead::IDisposer   // size 0x130
{
public:
    static CoinOrigin* instance;

    sead::IDisposer unkDisposer;          // 10
    s32 coinAngle;                        // 14 
    void *modelCoin;                      // 18 - Unused NSMBU Leftover
    void *modelBlueCoin;                  // 1C ^
    sead::OrthoProjection projection;     // 20 ^
    sead::OrthoCamera camera;             // CC ^

};
