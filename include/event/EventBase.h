#pragma once

#include "sead.h"

class ActorBase;

class EventBase     // Size 0x18
{
public:

    enum ExecuteState : u8
    {
        STATE_WAITING        = 0,
        STATE_REQUEST_EXIT   = 1
    };

    SEAD_RTTI_BASE(EventBase)

    EventBase();

    virtual void vf4();                      // deleted
    virtual void vf8();                      // deleted
    virtual void enter();                    // nullsub
    virtual ExecuteState execute();          // returns false
    virtual void exit();                     // nullsub, deleteReady?
    virtual void vf18();                     // deleted
    virtual void vf1C();                     // deleted
    virtual bool isJoin(const ActorBase& actor);       // returns false

    sead::ListNode listNode;
};