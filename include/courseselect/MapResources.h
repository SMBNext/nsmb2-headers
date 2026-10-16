#pragma once

#include "sead.h"
#include "sys/ResourceMgr.h"

namespace course_select {
class MapResources
{
    SEAD_SINGLETON_DISPOSER(MapResources);
public:
    struct List
    {
        u32 elementSize;
        u32 elementCount;
        Resource resources[32];
    };
    size_assert(List, 0x3688);

    virtual ~MapResources();

    void init();

    Resource* getResource(const sead::SafeString& key);
    bool loadResource(const sead::SafeString& name, u32 textureLocation = NN_GX_MEM_VRAMA, u32 vertexStreamLocation = NN_GX_MEM_VRAMB, u32 indexStreamLocation = NN_GX_MEM_VRAMA);

    static const sead::SafeString commonResources[];
    static const u32 commonResourceCount;

    sead::FixedSafeString<32> resourceNames[32];
    List* resourceList;
    HeapAllocator* allocator;
    u32 resourceCount;

private:
    Resource* insertResource(const sead::SafeString& name);
};
size_assert(MapResources, 0x5A0);

}
