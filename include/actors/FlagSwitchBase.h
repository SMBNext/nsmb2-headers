#pragma once

#include "actors/ActorMultiState.h"


class FlagSwitchBase : public ActorMultiState
{
    SEAD_RTTI_OVERRIDE(FlagSwitchBase, ActorMultiState);

public:
    FlagSwitchBase();
    
    int onExecute() override;
    int beforeDraw() override;
};
