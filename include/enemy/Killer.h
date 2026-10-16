#pragma once

#include "KillerBase.h"


class Killer : public KillerBase
{
    SEAD_RTTI_OVERRIDE(Killer, KillerBase);

public:
    Killer();

    Result onCreate() override;
    Result onExecute() override;
    Result onDraw() override;

    u8 _unk1FD4[0x1FE0-0x1FD4];     // 1FD4
    bool isDummy;                   // 1FE0     Facing left, left of the zone. Reduces the spawnable amount.
    u8 _unk1FE1[0x1FE8-0x1FE1];     // 1FE1
};
