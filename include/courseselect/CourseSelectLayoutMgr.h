#pragma once

#include "sead.h"
#include "state/FStateMgr.h"

namespace course_select {
class CourseSelectLayoutMgr
{
    SEAD_SINGLETON_DISPOSER(CourseSelectLayoutMgr);
public:

    DECLARE_STATE_ID(CourseSelectLayoutMgr, 15A);
    DECLARE_STATE_ID(CourseSelectLayoutMgr, 15B);
    DECLARE_STATE_ID(CourseSelectLayoutMgr, 162);
    DECLARE_STATE_ID(CourseSelectLayoutMgr, 163);
    DECLARE_STATE_ID(CourseSelectLayoutMgr, EnterCourse);
    DECLARE_STATE_ID(CourseSelectLayoutMgr, LoadMapSceneTop);
    DECLARE_STATE_ID(CourseSelectLayoutMgr, ShowCoinMilestoneDialog);
    DECLARE_STATE_ID(CourseSelectLayoutMgr, ShowPauseMenu);
    DECLARE_STATE_ID(CourseSelectLayoutMgr, ShowSaveDialogAfterCourse);
    DECLARE_STATE_ID(CourseSelectLayoutMgr, ShowSaveDialogForSignboard);
    DECLARE_STATE_ID(CourseSelectLayoutMgr, ShowSignBoardDialog);

    FStateMgr<CourseSelectLayoutMgr> stateMgr;
    StateID* someState;
    void* mapSceneTop_00;
    void* courseSelect_00;
    void* pauseTop_00;
    void* mapCursorTop_00;
    sead::ExpHeap* dialogHeap;
    u32 _4C;
    u32 _50;
    u32 _54;
    void* stateLayoutType3;
    u32 _5C;                              // inited to 9
    u8 _60;
    u8 _61;
    u8 _62;
    u8 _63;
    u8 _64;
    u8 _65;
    u8 _66;
    u8 _67; 
};
size_assert(CourseSelectLayoutMgr, 0x68);
}
