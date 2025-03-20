#pragma once

#include "math/Rect.h"
#include "math/Vec.h"
#include "sead.h"


struct ProfileInfo
{
    s32 id;
    const char* name;
    u16 executePriority;
    u16 drawPriority;
};


class fBase;
typedef fBase* (*ProcCreateFunction)();
typedef void (*ProcDestroyFunction)(fBase*);

struct Profile
{
    ProcCreateFunction createFunc;
    ProcDestroyFunction destroyFunc;
};


enum ResLoadMode : s8
{
    RES_LOAD_MODE_NONE = 0,
    RES_LOAD_MODE_ALWAYS = 1,
    RES_LOAD_MODE_COURSE = 2,
};

struct ResTableEntry
{
    sead::SafeString* files;
    s8 loadMode;
};


enum SoundActorType
{
    SOUND_ACTOR_TYPE_NONE = 0,
    SOUND_ACTOR_TYPE_NORMAL = 1,
    SOUND_ACTOR_TYPE_KOOPA = 5,
    SOUND_ACTOR_TYPE_PLAYER = 6,
};


struct ActorInfo
{
    Vec2i spriteOffset;
    Vec2i visibleAreaOffset;
    Vec2i visibleDistance;      // converted to f32, multiplied by 2.0 then stored in existDistance and visibleDistance, a minimum is added
    RectU16 _18;
    u16 spawnFlags;             // stored in _194
    u16 flags;

    enum SpawnFlags : u16
    {
        SPAWNFLAG_NORMAL         = 0x00,    // Actor spawns when near the exist distance
        SPAWNFLAG_ON_ZONE_ENTER  = 0x02,    // Actor spawns on zone enter
        SPAWNFLAG_MAP_OBJ        = 0x08,    // Used by map object actors (blocks, coins, platforms, etc.)
        SPAWNFLAG_GROUP_ID       = 0x10,    // Used by actors used with the Group Controller
    };

    enum Flags : u16
    {
        FLAG_NORMAL                     = 0x00,
        FLAG_CULL                       = 0x02,     // Actor is destroyed when outside exist distance
        FLAG_UNK2                       = 0x04,
        FLAG_LEVELCLEAR_DEATH           = 0x10,     // Actor is destroyed with a puff of smoke, player recieves points, Actor::levelClearDeath is called
        FLAG_LEVELCLEAR_DEATH_NO_POINTS = 0x20,     // Actor is destroyed with a puff of smoke, Actor::levelClearDeath is called
        FLAG_PROJECTILE                 = 0x80,     // Used by projectiles like fireballs, boomerangs, and hammers
        FLAG_UNK7                       = 0x200,    // Used by Chain Chomp and Spiny
        FLAG_UNK8                       = 0x400,    // Used by Lava and Cloud BG Effect
        FLAG_UNK9                       = 0x800,    // Only used by Springboard
        FLAG_UNK10                      = 0x1000,   // Used by blocks and switches
    };
};


extern ProfileInfo ProfileInfos[];
extern Profile Profiles[];
extern ResTableEntry ResTable[];
extern u8 ProfileSoundActorKinds[];
extern ActorInfo* ActorInfos[];


// Helper types so that profiles can be set without manually editing the arrays

template<class P>
struct RegisterProfile
{
    RegisterProfile(s32 id, const char* name, u16 executePriority, u16 drawPriority)
    {
        Profiles[id] = { P::build, P::destroy };
        ProfileInfos[id] = { id, name, executePriority, drawPriority };
    }
};

template<class P>
struct RegisterStageProfile : public RegisterProfile<P>
{
    RegisterStageProfile(s32 id, const char* name, u16 executePriority, u16 drawPriority,
                         ActorInfo* actorInfo, sead::SafeString* resources = nullptr, s8 resourceMode = 0, u8 soundActorType = 0)
        : RegisterProfile<P>(id, name, executePriority, drawPriority)
    {
        ActorInfos[id] = actorInfo;
        ResTable[id] = { resources, resourceMode };
        ProfileSoundActorKinds[id] = soundActorType;
    }
};

