#pragma once

#include "event/EventBase.h"

class PlayerDeathEvent : public EventBase
{
public:
    u32 _C;                               // set to player->spriteData1 & 0xF
    u8 _10;
    u8 _11;
    u8 _12;
    u8 _13;                               // padding?
};
