#pragma once

#include "sead.h"
#include "nw/gfx/res/ResGraphicsFile.h"

class Resource
{
public:
    u32 vtable;
    void* data;                         // points to the raw bcres data
    nw::gfx::res::ResGraphicsFile bcres;
    // more
};

class ResourceMgr
{
public:
    static ResourceMgr* instance;

    Resource* getResource(const sead::SafeString& key);

    bool loadFile(const sead::SafeString& file, u32 unk1, u32 unk2, u32 unk3, bool unk4);
    bool loadFile2(const sead::SafeString& file, u32 unk1, u32 unk2, u32 unk3, bool unk4, const sead::SafeString& unk = "");
    bool unloadFile(const sead::SafeString& file);
};

class WorldmapResourceMgr
{
public:
    static WorldmapResourceMgr* instance;

    Resource* getResource(const sead::SafeString& key);
    bool load(const sead::SafeString& name, u32 unk1 = 0x20000, u32 unk2 = 0x30000);

    static const sead::SafeString commonResources[];
    static const u32 commonResourceCount;

    static const sead::SafeString worldSpecificResources[9][0x10];
    static const u32 worldSpecificResourceCounts[9];
};
