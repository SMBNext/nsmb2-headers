#pragma once

#include "gfx/M2d.h"
#include "sead/heap/seadDisposer.h"
#include "sead/seadSafeString.h"
#include "types.h"

namespace Lyt {

// Size: 0x2F4
class LayoutResource : public m2d::ResAcc_c
{
public:
    LayoutResource();
    virtual ~LayoutResource();
};

size_assert(LayoutResource, 0x2F4);


// Size: 0x1C
class LayoutResMgr
{
    SEAD_SINGLETON_DISPOSER(LayoutResMgr);
public:
    // Size: 0x58
    struct Entry
    {
        Entry();

        /* 0x00 */  LayoutResource* resource;           //
        /* 0x04 */  sead::FixedSafeString<64> name;     //
        /* 0x50 */  u32 fontCount;                      // Set to 5
        /* 0x54 */  nw::lyt::FontKey* fontList;         //
    };
    size_assert(Entry, 0x58);

public:
    // Deleted
    virtual void vf0();

    virtual ~LayoutResMgr();

    void initialize(u32 resourceCount);
    LayoutResource* getResource(const sead::SafeString& resourceName);
    bool loadResource(const sead::SafeString& resourceName);
    bool unloadResource(const sead::SafeString& resourceName);

private:
    Entry* getEntry(const sead::SafeString& resourceName);
    Entry* insert(const sead::SafeString& resourceName);

private:
    /* 0x14 */  s32 mResourceCount;         //
    /* 0x18 */  Entry* mResourceList;       // mResourceCount + 8 entries
};

size_assert(LayoutResMgr, 0x1C);

} // namespace Lyt
