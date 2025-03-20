#pragma once

#include "sead.h"

class PlayerLookTarget : public sead::IDisposer     // size: 0x2C
{
public:
    PlayerLookTarget(s32 id);   // 0028A940
    ~PlayerLookTarget();        // 0028A988     Removes from list

    s32 id;
    Vec2f position;
    u8 _1C;
    u8 radius;
    u32 _20;
    u32 _24;
    u32 _28;
};


class PlayerLookTargetMgr : public sead::IDisposer
{
public:
    static PlayerLookTargetMgr* instance;

    void addToList(PlayerLookTarget* target);
    void removeFromList(PlayerLookTarget* target);

};