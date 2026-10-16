#pragma once

#include "actors/fBase.h"
#include "course/Course.h"

#include "sead.h"

class BsArea : public fBase
{
public:
    enum class PauseType : u8
    {
        NONE                = 0x0,
        IN_PAUSE_MENU       = 0x1,
        COURSE_FAILED       = 0x2,
        IN_SCENE_TRANSITION = 0x3,
    };

    static BsArea* instance;

    void startMidCourseWarp();
    void exitLevel();
    void exitLevel2();      // Used for some item house related thing
    void exitLevelFailed();

    sead::BoundBox2f zone;
    sead::BoundBox2f zonePadded;
    u8 screenWrap;                       // broken, can be multiple values 0, 1, 2
    PauseType pauseState;
    sead::ExpHeap* dialogHeap;
    u32 _3C;
    u32 pauseTopLyt;
    u8 _44;
    u8 _45;
    u8 _46;
    u8 _47;
    u8 _48;
    u8 _49;
    u8 _4A;
    u8 _4B;
    Course::CourseType courseType;
    bool isToadHouse1;
    bool isRainbowCourse;
    bool isCreditsStage;
    bool isCannonStage;
    bool doGhostHouseStairOverrides;
    bool isToadHouse2;
    u8 _53;
    u8 _54;
    u8 specialLevelFlag2bit0;
    u8 _56;
    u8 _57;
};

size_assert(BsArea, 0x58);
