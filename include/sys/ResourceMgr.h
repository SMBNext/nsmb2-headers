#pragma once

#include "sead.h"
#include "course/Profiles.h"
#include "nw/gfx/res/ResGraphicsFile.h"
#include "sys/Allocator.h"

class Resource
{
public:
    void* vtable;
    u8* binaryData;
    nw::gfx::res::ResGraphicsFile resGraphicsFile;
    u32 setupResult;
    void* vramBlockA;
    void* vramBlockB;
    sead::Heap* heap;
    void* _1C;
    u32 _20;
    u8 archiveHandle[0x190]; // TODO

    bool loadArchive(const sead::SafeString& path, sead::Heap* heap, s32 alignment);
    void setVramLocations(u32 textureLocation, u32 vertexStreamLocation, u32 indexStreamLocation);
    void setupResGraphicsFile(Allocator* allocator, Resource* sharedResource, bool setupShader);
};

size_assert(Resource, 0x1B4);

class ResourceMgr   // Size: 0x31A8
{
public:
    static ResourceMgr* instance;

    Resource* getResource(const sead::SafeString& key);

    bool loadFile(const sead::SafeString& file, u32 textureLocation, u32 vertexStreamLocation, u32 indexStreamLocation, bool isMergedModel);
    bool loadFile2(const sead::SafeString& file, u32 textureLocation, u32 vertexStreamLocation, u32 indexStreamLocation, bool isMergedModel, const sead::SafeString& prefix = "");
    bool unloadFile(const sead::SafeString& file);

    static void unload(ResLoadMode loadMode);           // 0x002E4478
    static void loadCourseResources(ResLoadMode loadMode);   // 0x002E3F24
    static void loadCourseMergedModelResources();       // 0x002E3D84
    bool unloadCourseMergedModelResources();            // 0x0023D8EC

    void* vtable;
    sead::ExpHeap* heap;
    void* _8;                                       // a list node maybe?
    void* _C;                                       // list node maybe?
    sead::FixedSafeString<32> resourceNames[256];   // fixed size list of resources that are always loaded?
    Resource* resourceList;                         // list of resources, max count 256
    HeapAllocator* modelSetupHeapAllocator;         // might actually be pointer to bigger struct, unsure
    u32 resourceCount;
    sead::FixedSafeString<32> resModelNames[32];    // dynamically loaded resources?
    nw::gfx::res::ResModel* resModels;              // max count 32
    void* mergedModelHeapAllocator;                 // some class inheriting m3d_allocator?
    void* _31A4;
};

size_assert(ResourceMgr, 0x31A8);
