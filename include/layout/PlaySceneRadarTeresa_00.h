#pragma once

#include "gfx/M2d.h"
#include "layout/StateLayoutType1.h"
#include "sead/heap/seadDisposer.h"

namespace Lyt {

// Size: 0x1A0
class PlaySceneRadarTeresa_00 : public StateLayoutType1
{
    SEAD_SINGLETON_DISPOSER(PlaySceneRadarTeresa_00);
public:
    enum class PaneId : u32
    {
        N_Meter_00 = 0,
    };

    enum class PictureId : u32
    {
        P_ObakeMeter_00 = 0,
        P_Teresa_00     = 1,
        P_ObakeMeter_03 = 2,
        P_Teresa_01     = 3,
        P_Teresa_02     = 4,
    };

    enum class GroupId : u32
    {
        G_Loop_00 = 0,
    };

    enum class AnimId : u32
    {
        Loop = 0,
    };

public:
    void create();
    void execute();
    void draw();
    void delete_();

    void copyPositionFromPane(const nw::lyt::Pane* pane);

    void sub_380230();

public:
    /* 0x03C */  m2d::EmbedLayout_c embedLayout;    //
    /* 0x158 */  nw::lyt::Pane* panes[1];           //
    /* 0x15C */  nw::lyt::Picture* pictures[5];     //
    /* 0x170 */  nw::lyt::Group* groups[1];         //
    /* 0x174 */  m2d::Anm_c anims[1];               //
    /* 0x19C */  u8 _19C[4];                        //
};

size_assert(PlaySceneRadarTeresa_00, 0x1A0);

} // namespace Lyt
