#pragma once

#include "course/PointGetTop.h"
#include "math/Vec.h"
#include "sead.h"
#include "types.h"


// Size: 0x4B8C
class SmallScoreMgr
{
    SEAD_SINGLETON_DISPOSER(SmallScoreMgr);
public:
    void create();
    void update();
    void draw();
    void reset();
    void show(const Vec3f& position, u32 type, s8 playerNum, bool stayOnScreen);
    void hide(const s32& playerNum);
    void disappear(const s32& playerNum);
    void setPosition(const Vec3f& position, const s32& playerNum);
    bool isIdle(const s32& playerNum);

public:
    /* 0x0010 */  PointGetTop layouts[30];  //
    /* 0x4B88 */  u32 nextLayoutIdx;        //
};

size_assert(SmallScoreMgr, 0x4B8C);
