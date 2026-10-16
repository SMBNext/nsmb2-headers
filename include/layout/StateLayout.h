#pragma once

#include "types.h"
#include "layout/Layout.h"

#include "state/FStateStateMgr.h"
#include "state/FStateVirtualID.h"

namespace Lyt {

// Size: 0x2C
// Vtable: 0x005C187C
class StateLayout : public Layout
{
public:
    // Address C1: 0x0038FB08
    StateLayout();

    // Address D1: 0x0038FB7C
    virtual ~StateLayout() override;

    // Address: 0x0038FA90
    virtual void changeState(const StateID& stateID);

protected:
    FStateStateMgr<StateLayout> stateMgr;   // 4
};

size_assert(StateLayout, 0x2C);

}    // namespace Lyt
