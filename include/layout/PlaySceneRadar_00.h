#pragma once

#include "gfx/M2d.h"
#include "layout/StateLayoutType1.h"
#include "sead/heap/seadDisposer.h"

namespace Lyt {

// Size: 0x230
class PlaySceneRadar_00 : public StateLayoutType1
{
    SEAD_SINGLETON_DISPOSER(PlaySceneRadar_00);
public:
    enum class PaneId : u32
    {
        N_Mario_00     = 0,
        N_Flag_00      = 1,
        N_Meter_00     = 2,
        N_MaterLine_00 = 3,
    };

    enum class PictureId : u32
    {
        P_Kuppa_00  = 0,
        P_Memori_00 = 1,
    };

public:
    void create();
    void execute();
    void draw();
    void delete_();

    void copyPositionFromPane(const nw::lyt::Pane* pane);

    void sub_36C954();
    void sub_36CE14();

public:
    /* 0x03C */  m2d::EmbedLayout_c embedLayout;    //
    /* 0x158 */  nw::lyt::Pane* panes[4];           //
    /* 0x168 */  nw::lyt::Picture* pictures[2];     //
    /* 0x170 */  u8 _170[192];                      //
};

size_assert(PlaySceneRadar_00, 0x230);

} // namespace Lyt
