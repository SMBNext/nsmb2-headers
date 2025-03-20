#pragma once

#include "player/PlayerObject.h"

class PlayerStateData;

// Size: 0x78
// Vtable: 0x005D0374
class PlayerMgr
{
    // createInstance()                             Address: 0x0044DC84
    // deleteInstance()                             Address: 0x0044DCE8
    // sInstance                                    Address: 0x005EB530
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x0044DE2C
    // SingletonDisposer_::sStaticDisposer          Address: 0x005EB534
    // SingletonDisposer_::vtbl                     Address: 0x005D0364
    SEAD_SINGLETON_DISPOSER(PlayerMgr);

public:

    // Address: 0x0044E58C
    PlayerMgr();

    // D1: 0x0044E640
    // D2: 0x0044E6B0
    virtual ~PlayerMgr();

    // Address: 0x0044E2D0
    void execute();

    // Address: 0x0044E43C
    void reset();

    // Address: 0x0044E47C
    void createPlayers(PlayerStateData* playerState);

    // Address: 0x0044DECC
    void removePlayer(s32 playerId);

    // Address: 0x0044DE90
    void addPlayer(s32 playerId, PlayerBase* player);

    // Address: 0x0044E000
    void gotoEntrance(u8 areaId, u8 entranceId);

    // Address: 0x0044DE7C
    PlayerObject* getPlayer(s32 playerId = 0);

    // Address: 0x0044DE7C
    const PlayerObject* getPlayer(s32 playerId = 0) const;

    // Address: 0x0044DF0C
    void doCoopQuake();

    enum class QuakeType
    {
        Normal = 0, // Used for co-op ground pound
        Mega = 1,   // Used for mega mario ground pound
        Mini = 2    // Used for mini mario (prevents quake)
    };

    // Address: 0x0044DD48
    void doQuake(QuakeType quakeType, s32 playerId);

    // Address: 0x0044DC44
    void enableStarMusic();

    // Address: 0x0044DB7C
    void disableStarMusic();

    // Address: 0x0044DBF4
    void enableMegaMusic();

    // Address: 0x0044DB04
    void disableMegaMusic();

    // Address: 0x0044DC08
    void doPlayerDown(s32 playerId);

    // Address: 0x004AFC04
    s32 numPlayers();

    // Address: 0x004AFC60
    s32 numPlayersAlive();

    // Address: 0x004AFCD8
    sead::BitFlag16* getUnkFlag();

private:
    u32 _14;
    u32 _18;
    u32 _1C;
    u32 _20;
    u32 _24;
    u32 _28;
    u32 _2C;
    u32 _30;
    u32 _34;
    u32 _38;
    u32 _3C;
    PlayerObject *mPlayers[2];
    PlayerObject *mPlayers2[2];     // idk why there's two of these
    sead::BitFlag16 mPlayerFlags;   // 1: Player 1 exists, 2: Player 2 exists
    u32 _54;
    u32 _58;
    u32 _5C;
    u32 _60;
    u8 _64;
    sead::BitFlag16 mMusicFlags;    // 1: Star Active, 2: Mega Active
    u8 _68;
    u8 _69;
    u8 _6A;
    u32 _6C[2];
    u8 _74[2];
    u8 _76;

};

size_assert(PlayerMgr, 0x78);