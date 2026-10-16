#pragma once

#include "sead.h"

class PlayerBound
{
public:
    class Info
    {
    public:
        Info();                     // 0x0033FCB8
        Info(const Info& info);     // 0x0033FC84

        u16 playerWarpFlags;        // 0   Two bits are set while warping, one for each player
        u32 numWarping;             // 4
        f32 leftPlayerBound;        // 8   These form a boundary box between the two players in multiplayer
        f32 rightPlayerBound;       // C
        f32 bottomPlayerBound;      // 10
        f32 topPlayerBound;         // 14
    };

    size_assert(Info, 0x18);

    PlayerBound();              // 0x00346078

    PlayerBound* init();        // 0x0033FCB8
    void sortPlayerBounds();        // 0x0033FC50
    void updatePlayerBounds();      // 0x00345E80
    bool playersAreWarping();       // 0x004A53D4

    Info info;                      // 0
    u8 warpTimers[2];               // 18
};

size_assert(PlayerBound, 0x1C);


class PlayerBoundMgr
{
public:
    class Interpolator
    {
    public:
        // 0x00348564
        Interpolator(u8 boundDirection);

        // 0x003482B4
        void interpolate(f32* out, bool reset, f32 target, f32 prevCenterDelta, f32 accel, f32 scale, f32 maxStep);

        u8 boundDirection;      // 0
        bool isCubicMode;       // 1
        u32 _4;                 // 4
        u32 delayTimer;         // 8
        f32 curveTime;          // C

    private:
        f32 cubicCurve(f32 t);      // 0x0040A364
    };

    size_assert(Interpolator, 0x10);

    // 0x00337FCC
    PlayerBoundMgr(const PlayerBound& playerWarpBound);

    // 0x00337AC0
    void execute(const PlayerBound& playerWarpBound, const sead::BoundBox2f& viewBound);

    PlayerBound::Info info;                 // 0
    Interpolator interpLeft;                    // 18
    Interpolator interpRight;                   // 28
    Interpolator interpDown;                    // 38
    Interpolator interpUp;                      // 48
    bool warpStateChanged;                      // 58 
    Vec2f boundCenterDelta;                     // 5C
    Vec2f boundCenterDeltaPrev;                 // 64
    f32 leftPlayerBoundDelta;                   // 6C
    f32 rightPlayerBoundDelta;                  // 70
    f32 bottomPlayerBoundDelta;                 // 74
    f32 topPlayerBoundDelta;                    // 78
    Vec2f boundCenter;                          // 7C
    f32 leftPlayerBoundPrev;                    // 84
    f32 rightPlayerBoundPrev;                   // 88
    f32 bottomPlayerBoundPrev;                  // 8C
    f32 topPlayerBoundPrev;                     // 90
};

size_assert(PlayerBoundMgr, 0x94);
