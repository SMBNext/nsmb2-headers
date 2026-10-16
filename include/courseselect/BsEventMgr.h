#pragma once

#include "actors/fBase.h"
#include "sead.h"

namespace course_select {
class BsEventMgr : public fBase
{
public:
    enum ScriptId : u32
    {
        SCRIPT_ID_COURSE_ENTER,
        SCRIPT_ID_COURSE_FAILED,
        SCRIPT_ID_COURSE_CLEAR,
        SCRIPT_ID_GHOST_ENTER,
        SCRIPT_ID_GHOST_FAILED,
        SCRIPT_ID_GHOST_CLEAR,
        SCRIPT_ID_TOWER_ENTER,
        SCRIPT_ID_TOWER_FAILED,
        SCRIPT_ID_TOWER_CLEAR,
        SCRIPT_ID_CASTLE_ENTER,
        SCRIPT_ID_CASTLE_FAILED,
        SCRIPT_ID_CASTLE_CLEAR,
        SCRIPT_ID_KOOPA_CASTLE_ENTER,
        SCRIPT_ID_KOOPA_CASTLE_FAILED,
        SCRIPT_ID_KOOPA_CASTLE_CLEAR,
        SCRIPT_ID_BOSS_DEMO_TO_TOWER,
        SCRIPT_ID_BOSS_DEMO_TO_CASTLE,
        SCRIPT_ID_BOSS_DEMO_TO_NEXT_WORLD,
        SCRIPT_ID_WALK_ENTER_WORLD,
        SCRIPT_ID_WORLD_CHANGE_FADE_OUT,
        SCRIPT_ID_UNK_20,
        SCRIPT_ID_KINOPIO_HOUSE_DISAPPEAR,
        SCRIPT_ID_UNK_22,
        SCRIPT_ID_RAINBOW_UNLOCK,
        SCRIPT_ID_GOLD_BLOCK_APPEAR,
        SCRIPT_ID_UNLOCK_MULTI_CAMERA_PAN,
        SCRIPT_ID_UNK_26,
        SCRIPT_ID_KANBAN_DIALOG,
        SCRIPT_ID_KANBAN_UNLOCK,
        SCRIPT_ID_NODE_UNLOCK,
        SCRIPT_ID_COIN_RUSH_UNLOCK_DIALOG,
        SCRIPT_ID_VICTORY,
        SCRIPT_ID_MOVE,
        SCRIPT_ID_SAVE_DIALOG,
        SCRIPT_ID_COIN_DIALOG,
        SCRIPT_ID_PAUSE_DIALOG,
        SCRIPT_ID_FADE_IN,
        SCRIPT_ID_TITLESCREEN_FADE_OUT,
        SCRIPT_ID_UNK_38,
        SCRIPT_ID_NONE,
    };

    enum EventId : u32
    {
        EVENT_ID_COURSE_ENTER,
        EVENT_ID_COURSE_FADE_OUT,
        EVENT_ID_COURSE_FAILED,
        EVENT_ID_COURSE_CLEAR,
        EVENT_ID_UNK_4,
        EVENT_ID_TOWER_CLEAR,
        EVENT_ID_CASTLE_CLEAR,
        EVENT_ID_BOSS_TO_TOWER,
        EVENT_ID_BOSS_TO_CASTLE,
        EVENT_ID_BOSS_NEXT_WORLD,
        EVENT_ID_BOSS_CAMERA_BACK_PAN,
        EVENT_ID_STRUCTURE_ENTER,
        EVENT_ID_STRUCTURE_EXIT,
        EVENT_ID_KOOPA_CASTLE_CLOSE_GATE,
        EVENT_ID_KOOPA_CASTLE_OPEN_GATE,
        EVENT_ID_WALK_ENTER_WORLD,
        EVENT_ID_WORLD_CHANGE_FADE_OUT,
        EVENT_ID_KOOPA_CASTLE_WALK,
        EVENT_ID_KINOPIO_HOUSE_DISAPPEAR,
        EVENT_ID_UNK_19,
        EVENT_ID_RAINBOW_UNLOCK_CAMERA_PAN,
        EVENT_ID_RAINBOW_UNLOCK,
        EVENT_ID_RAINBOW_UNLOCK_CAMERA_BACK_PAN,
        EVENT_ID_GOLD_BLOCK_APPEAR,
        EVENT_ID_UNLOCK_MULTI_CAMERA_PAN,
        EVENT_ID_UNK_25,
        EVENT_ID_KANBAN_GROW,
        EVENT_ID_KANBAN_DIALOG,
        EVENT_ID_KANBAN_SHRINK,
        EVENT_ID_KANBAN_UNLOCK,
        EVENT_ID_UNLOCK_NODE_CAMERA_PAN,
        EVENT_ID_UNLOCK_NODE_PATH_FADE_IN,
        EVENT_ID_UNLOCK_NODE_CAMERA_BACK_PAN,
        EVENT_ID_UNLOCK_NODE,
        EVENT_ID_UNLOCK_NODE_EXTRA,
        EVENT_ID_COIN_RUSH_UNLOCK_DIALOG,
        EVENT_ID_VICTORY_SPIN,
        EVENT_ID_VICTORY_DIALOG,
        EVENT_ID_MOVE,
        EVENT_ID_SAVE_DIALOG,
        EVENT_ID_COIN_DIALOG,
        EVENT_ID_PAUSE_DIALOG,
        EVENT_ID_FADE_IN,
        EVENT_ID_TITLESCREEN_FADE_OUT,
        EVENT_ID_UNK_44,
        EVENT_ID_UNK_45,
        EVENT_ID_SCRIPT_END,
    };

    struct Script
    {
        struct Event
        {
            EventId id;
            u32 arg;   // Unused
        };

        Event* events;
        u8 priority;        // If setNextScript is called multiple times, the one with the lowesr value will be executed
    };

public:
    virtual ~BsEventMgr();

    static BsEventMgr* instance;

    bool preCreate() override;
    Result onCreate() override;
    void postCreate(Result createResult) override;
    bool preDelete() override;
    Result onDelete() override;
    void postDelete(Result deleteResult) override;
    bool preExecute() override;
    Result onExecute() override;
    void postExecute(Result execResult) override;
    bool preDraw() override;
    void postDraw(Result drawResult) override;

    bool hasScript();
    ScriptId* getCurrentScriptId();
    Script::Event* getCurrentEvent();
    void setNextScriptId(const ScriptId& scriptId);

    static Script scripts[SCRIPT_ID_NONE];

    ScriptId nextScriptId;                              // 14
    ScriptId nextScriptIdSpecial;                       // 18
    ScriptId currentScriptId;                           // 1C
    u32 currentEventIdx;                                // 20
    u32 currentScriptExecuteTick;                       // 24
    u32 currentScriptEntryStartTick;                    // 28
    sead::FixedPtrArray<void, 64> actorEventAdapters;   // 2C
    bool scriptStarted;                                 // 138
    bool eventStarted;                                  // 139
};
}
