#pragma once

#include "sead.h"

#include "courseselect/BsEventMgr.h"
#include "state/FStateMgr.h"

namespace course_select {
class SequenceMgr
{
    SEAD_SINGLETON_DISPOSER(SequenceMgr);
public:
    enum class SequenceType : u8
    {
        CourseClear         = 1,
        CourseFailed        = 2,
        Unk3                = 3,
        KinopioExit         = 4,
        Unk5                = 5,
    };

    DECLARE_STATE_ID(SequenceMgr, 1C0);
    DECLARE_STATE_ID(SequenceMgr, 1C3);
    DECLARE_STATE_ID(SequenceMgr, CastleClear);
    DECLARE_STATE_ID(SequenceMgr, CastleEnter);
    DECLARE_STATE_ID(SequenceMgr, CastleFail);
    DECLARE_STATE_ID(SequenceMgr, CourseClear);
    DECLARE_STATE_ID(SequenceMgr, CourseEnter);
    DECLARE_STATE_ID(SequenceMgr, CourseFail);
    DECLARE_STATE_ID(SequenceMgr, ExitToTitle);
    DECLARE_STATE_ID(SequenceMgr, Idle);
    DECLARE_STATE_ID(SequenceMgr, KanbanInteract);
    DECLARE_STATE_ID(SequenceMgr, KinopioHouseExit);
    DECLARE_STATE_ID(SequenceMgr, ObakeClear);
    DECLARE_STATE_ID(SequenceMgr, ObakeEnter);
    DECLARE_STATE_ID(SequenceMgr, ObakeFail);
    DECLARE_STATE_ID(SequenceMgr, TowerClear);
    DECLARE_STATE_ID(SequenceMgr, TowerEnter);
    DECLARE_STATE_ID(SequenceMgr, TowerFail);
    DECLARE_STATE_ID(SequenceMgr, WorldBegin);
    DECLARE_STATE_ID(SequenceMgr, WorldChange);

    bool isIdle();
    void clearQueue();

    void goToCourseSelect();
    void goToTitlescreen();
    void doPointUnlock();
    void updateMusicForState(const StateID& state);

    void handleScript();
    void setCourseClearScript();
    void setCourseEnterScript();
    void setCourseFailScript();
    void setNextScript(const BsEventMgr::ScriptId& scriptId);
    void setStateByScript(const BsEventMgr::ScriptId& scriptId);

    FStateMgr<SequenceMgr> stateMgr;            // 10
    u32 _34;                                    // 34   Inited to GameState::instance->_10
    SequenceType sequenceType;                  // 38
    u8 _39;                                     // 39 
    u32 currentScriptIdx;                       // 3C
    u32 scriptCount;                            // 40
    BsEventMgr::ScriptId scriptQueue[8];        // 44   All init to SCRIPT_ID_NONE
};
size_assert(SequenceMgr, 0x64);
}
