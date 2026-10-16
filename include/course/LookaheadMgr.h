#pragma once

#include "sead.h"

#include "course/BgScrollMgr.h"

class PlayerBoundMgr;

class LookaheadMgr
{
public:
    struct LookaheadOffset
    {
        /* 0x0 */  f32 amount;
        /* 0x4 */  f32 speed;
    };

    void execute(PlayerBoundMgr* playerBoundMgr, bool isScreenWrap, BgScrollMgr::CameraMode cameraMode);

    /* 0x0 */  LookaheadOffset lookaheadOffsetX;
    /* 0x4 */  LookaheadOffset lookaheadOffsetY;
};

size_assert(LookaheadMgr, 0x10);
