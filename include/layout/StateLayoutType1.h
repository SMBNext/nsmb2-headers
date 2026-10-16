#pragma once

#include "layout/StateLayout.h"

namespace Lyt {

// TODO: Rename this...
// Size: 0x2C
class StateLayoutType1 : public StateLayout
{
public:
    StateLayoutType1();
    ~StateLayoutType1() override;

    DECLARE_STATE_VIRTUAL_ID_BASE(StateLayoutType1, hidden);
    DECLARE_STATE_VIRTUAL_ID_BASE(StateLayoutType1, appear);
    DECLARE_STATE_VIRTUAL_ID_BASE(StateLayoutType1, visible);
    DECLARE_STATE_VIRTUAL_ID_BASE(StateLayoutType1, disappear);
    DECLARE_STATE_VIRTUAL_ID_BASE(StateLayoutType1, paused);
    DECLARE_STATE_VIRTUAL_ID_BASE(StateLayoutType1, Unk6);

    // Changes to "appear" state if state is "hidden"
    virtual void appear();

    // Changes to "disappear" state if state is "visible"
    virtual void disappear();

    // Deleted
    virtual void showLayout();

    // Deleted
    virtual void hideLayout();

    // Changes to "paused" state if bool is true, otherwise changes back to main state
    virtual void setPaused(bool paused);

    // Deleted
    virtual void vf6C();

};

size_assert(StateLayoutType1, 0x2C);

} // namespace Lyt
