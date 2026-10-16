#pragma once

#include "sead.h"
#include "actors/fBase.h"
#include "effect/Effect.h"

namespace course_select {
class BsSequenceMgr : public fBase {
public:
    Result onCreate();
    Result onDelete();
    Result onDraw();
    Result onExecute();

    void updateEffectPosition();    // 0x002BD24C

    bool isEffectActive;
    Vec3f effectPosition;
    LevelEffect effect;
};
size_assert(BsSequenceMgr, 0x80);
}
