#pragma once

#include "gfx/M2d.h"
#include "layout/StateLayoutType1.h"
#include "sead/heap/seadDisposer.h"

namespace Lyt {

// TODO: improve this header
// Size: 0x254
class WaitParts_00 : public StateLayoutType1
{
    SEAD_SINGLETON_DISPOSER(WaitParts_00);
private:
    /* 0x03C */  m2d::EmbedLayout_c mEmbedLayout;       //
    /* 0x158 */  nw::lyt::Pane* mPanes[1];              //
    /* 0x15C */  nw::lyt::Picture* mPictures[10];       //
    /* 0x184 */  nw::lyt::Group* mGroups[2];            //
    /* 0x18C */  m2d::Anm_c mAnims[5];                  //
};

size_assert(WaitParts_00, 0x254);

} // namespace Lyt
