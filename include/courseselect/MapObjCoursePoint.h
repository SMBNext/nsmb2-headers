#pragma once

#include "courseselect/ActorState.h"
#include "gfx/AnimModel.h"
#include "effect/Effect.h"
#include "sys/Allocator.h"

namespace course_select {
class MapObjCoursePoint : public ActorState
{
public:
    enum class CourseStatus : u8
    {
        CLEAR    = 0,
        HELP     = 1,
        OPEN     = 2,
        CLOSED   = 3,
    };


    Result onCreate() override;
    Result onExecute() override;
    // Result onDelete() override;
    // Result onDraw() override;

    void handleUnlock();

    HeapAllocator allocator;
    Resource* resource;
    AnimModelBase* model;
    u8 _C8;
    CourseStatus courseStatus;
    u8 _CA;
    u8 _CB;
    sead::BoundBox3f boundBox;
    u32 unlockTimer;
    u8 _E8;
    u32 _EC;
    u8 eventComplete;
    u8 _F1;
    u8 _F2;
    u8 _F3;
    LevelEffect effect;

    DECLARE_STATE_ID(MapObjCoursePoint, Clear);
    DECLARE_STATE_ID(MapObjCoursePoint, Help);
    DECLARE_STATE_ID(MapObjCoursePoint, Unlock);
    DECLARE_STATE_ID(MapObjCoursePoint, Open);
    DECLARE_STATE_ID(MapObjCoursePoint, Closed);

};
}