#pragma once

#include "sead.h"
#include "event/EventBase.h"
#include "player/PlayerObject.h"

class PlayerDemoMgr
{
    SEAD_SINGLETON_DISPOSER(PlayerDemoMgr);
public:
    enum class State : u32
    {
        cNone           = 0,
        cWait           = 1,
        cFireworks      = 2,
        cBossBattle     = 4,
        cGoalDemo       = 5,
    };

    class EntranceEvent : public EventBase
    {
    public:
        bool isDone;
    };

    class UnkEventTypeB : public EventBase
    {
    public:
        u8 _C;
    };

    class UnkEventTypeC : public EventBase { };

    class CourseClearEvent : public EventBase
    {
        u8 _C;
        u8 _D[3];   // probably padding
    };

    void execute();
    void handleGoalDemoState();

    bool freeze();
    bool freezeIfOnGround();
    void unfreeze();
    bool setBossDemoState(u32 id);

    void pushPowerupEvent(PlayerObject* player);
    void startPlayerDeathEvent(PlayerObject* player, u8 unkArg);
    void startEntranceEvent();
    void startUnkEventB();
    void startUnkEventC();

    bool isReadyCourseRelated();
    void getEnterPosition(Vec3f* posOut);
    u32 getPlayerCount();

    State state;
    u32 subState;
    u32 timer;
    u32 unkFlag;                         // goal pole sets this
    sead::ListImpl _20;
    u32 _2C;
    u32 _30[8];
    sead::ListImpl _50;
    u32 _5C[9];
    u32 _80;
    u8 _84;
    u8 rainbowExit;
    u8 _86[2];
    u32 elapsed;
    u32 _8C;
    Vec3f cameraPosition;
    u8 unkRainbowFlag;
    u8 _9D;
    u32 fireworksCount;
    u32 fireworksLeft;
    Vec3f effectPosition;
    u32 lastFireworkIdx;
    u32 _B8[6];
    u32 _D0;
    u32 _D4;
    u32 _D8;
    u32 _DC;
    u32 _E0;
    u32 _E4;
    u32 _E8;
    u32 _EC;
    u32 _F0;
    u32 _F4;
    u32 _F8[2];
    s32 playerId;
    u32 _104;
    u32 _108;
    u32 _10C;
    u32 _110;
    EntranceEvent* entranceEvent;
    UnkEventTypeB* unkEventB;
    CourseClearEvent* courseClearEvent;
    UnkEventTypeC* unkEventC;
};

size_assert(PlayerDemoMgr, 0x124);
