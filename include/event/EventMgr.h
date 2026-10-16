#pragma once

#include "sead.h"

class ActorBase;
class EventBase;

class EventMgr // Size 0x24
{
SEAD_SINGLETON_DISPOSER(EventMgr);
public:
    enum ExecuteFlags : u32
    {
        EXECUTE_FLAG_NORMAL                 = 1 << 0,
        EXECUTE_FLAG_WARP                   = 1 << 1,
        EXECUTE_FLAG_FLAGPOLE_GRAB          = 1 << 2,
        EXECUTE_FLAG_ZONE_LOAD              = 1 << 3,
        EXECUTE_FLAG_PLAYER_STATE_CHANGE    = 1 << 4,
        EXECUTE_FLAG_PLAYER_DEATH           = 1 << 5,

        EXECUTE_FLAG_ALL                    = 0xFFFFFFFF
    };

    bool isJoin(const ActorBase& actor) const;
    bool pushEvent(EventBase* entry);

    sead::OffsetList<EventBase> eventList; 
    EventBase* currentEvent;
};

size_assert(EventMgr, 0x24);
