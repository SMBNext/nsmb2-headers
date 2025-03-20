#pragma once

#include "Scene.h"
#include "state/FStateStateMgr.h"

class StateScene : public Scene     // size: 0x3C
{
public:
    StateScene();
    virtual ~StateScene();

    s32 vf40(u32) override;         // returns -1

    virtual void vf44();            // deleted
    virtual void changeState(const StateID& stateID);

    FStateStateMgr<StateScene> stateMgr;
};
