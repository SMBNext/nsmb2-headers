#pragma once

#include "scene/FaderMgr.h"
#include "scene/StateScene.h"
#include "state/FStateVirtualID.h"
#include "types.h"

// Size: 0xDC
class ScCourseIn : public StateScene
{
public:
    DECLARE_STATE_VIRTUAL_ID_BASE(ScCourseIn, CreateSingletons1);
    DECLARE_STATE_VIRTUAL_ID_BASE(ScCourseIn, CreateSingletons2);
    DECLARE_STATE_VIRTUAL_ID_BASE(ScCourseIn, LoadCourse);
    DECLARE_STATE_VIRTUAL_ID_BASE(ScCourseIn, LoadGoldKinoko);
    DECLARE_STATE_VIRTUAL_ID_BASE(ScCourseIn, LoadResources);
    DECLARE_STATE_VIRTUAL_ID_BASE(ScCourseIn, LoadModelMgrs);
    DECLARE_STATE_VIRTUAL_ID_BASE(ScCourseIn, WaitExitReady);
    DECLARE_STATE_VIRTUAL_ID_BASE(ScCourseIn, WaitExitReadyCoinRush);
    DECLARE_STATE_VIRTUAL_ID_BASE(ScCourseIn, StartCourse);

    void createLayout();
    static void destroySingletons();

private:
    /* 0x3C */  void* mCourseInTop;                // Lyt::CourseInTop_00*
    /* 0x40 */  void* mCoinRushCourseInTop;        // Lyt::CoinRushCourseInTop_00*
    /* 0x44 */  void* mCoinRushCourseIn;           // Lyt::CoinRushCourseIn_00*
    /* 0x48 */  u32 mLoadTimer;                    //
    /* 0x4C */  u32 mCoinRushWaitTimer;            //
    /* 0x50 */  u8 mLoadThread[0x88];              // sead::Thread
    /* 0xD8 */  bool mIsCreditsLevel;              //
    /* 0xD9 */  s8 mModelMgrStep;                  //
    /* 0xDA */  u8 _DA[2];                         // padding
};
