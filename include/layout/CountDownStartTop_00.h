#pragma once

#include "gfx/M2d.h"
#include "gfx/TagProcessor.h"
#include "layout/StateLayoutType1.h"

namespace Lyt {

// Size: 0x33C
class CountDownStartTop_00 : public StateLayoutType1
{
public:
    enum class PaneId : u32
    {
        N_CountDown1_00 = 0,
        N_CDStart_00    = 1,
        N_CountDown3_00 = 2,
        N_CountDown2_00 = 3,
        N_CDAll_00      = 4,
    };

public:
    CountDownStartTop_00();
    ~CountDownStartTop_00() override;

    DECLARE_STATE_VIRTUAL_ID_BASE(CountDownStartTop_00, countdown);
    DECLARE_STATE_VIRTUAL_ID_BASE(CountDownStartTop_00, go);
    DECLARE_STATE_VIRTUAL_ID_BASE(CountDownStartTop_00, done);

    void create();
    void reset();
    void execute();
    void draw();
    void delete_();

public:
    /* 0x02C */  m2d::EmbedLayout_c embedLayout;    //
    /* 0x148 */  nw::lyt::Pane* panes[5];           //
    /* 0x15C */  m2d::TextBox_c textBoxes[8];       //
    /* 0x27C */  nw::lyt::Group* groups[4];         //
    /* 0x28C */  m2d::Anm_c anims[4];               //
    /* 0x32C */  TagProcessor tagProcessor;         //
    /* 0x338 */  s8 countdownStep;                  //
    /* 0x339 */  bool hasGo;                        //
    /* 0x33A */  u8 _33A[2];                        // padding
};

size_assert(CountDownStartTop_00, 0x33C);

} // namespace Lyt
