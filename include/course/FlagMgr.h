#pragma once

#include "sead.h"

class FlagMgr : public sead::IDisposer  // size: 0x930
{
public:
    struct Entry
    {
        u32 timer;
        u32 _4;
        u32 _8;
    };

    u64 flags;          // 10
    Entry entries[64];  // 18
    // More member vars

    // Delay is in 10x frames, 1=1/6 second
    void set(u8 id, u32 delay, bool active, bool unk1, bool unk2, u32 unk3);

    inline u64 mask(u8 id)
    {
        return (u64)1 << id;
    }

    inline bool isActive(u8 id)
    {
        return (flags & mask(id)) != 0;
    }

    inline bool isInactive(u8 id)
    {
        return (flags & mask(id)) == 0;
    }

    inline void set(u8 id, bool active)
    {
        flags &= ~mask(id);
        if (active)
            flags |= mask(id);
    }


    static FlagMgr* instance;
};
