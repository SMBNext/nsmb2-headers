#pragma once

#include "sead.h"
#include "types.h"

// Size: 0x1AC
class MessageMgr
{
    SEAD_SINGLETON_DISPOSER(MessageMgr);
public:
    // Size: 0x10
    class Handle
    {
    public:
        Handle();
        virtual ~Handle();

        bool loadData(const void* message, const void* project);
        void unloadData();
        const wchar_t* get(const char* label);
        s32 getTextSize(const char* label);

    public:
        /* 0x4 */  void* message;       // LMS_MessageBinary*
        /* 0x8 */  void* project;       // LMS_ProjectBinary*
        /* 0xC */  void* _C;            //
    };
    size_assert(Handle, 0x10);

    // Size: 0x3B0
    struct Entry
    {
        /* 0x000 */  Handle* handle;                        //
        /* 0x004 */  u8 messageFile[0x190];                 // RomFile
        /* 0x194 */  u8 _194[0x190];                        // RomFile
        /* 0x324 */  sead::FixedSafeString<128> path;       //
    };
    size_assert(Entry, 0x3B0);

    // Size: 0x10
    struct FileInfo
    {
        /* 0x0 */  sead::SafeString directory;      //
        /* 0x8 */  sead::SafeString file;           //
    };
    size_assert(FileInfo, 0x10);

    // Size: 0x10
    struct DirectoryInfo
    {
        /* 0x0 */  sead::SafeString name;           //
        /* 0x8 */  const FileInfo* files;           //
        /* 0xC */  u32 fileCount;                   //
    };
    size_assert(DirectoryInfo, 0x10);

public:
    // Deleted
    virtual void vf0();

    virtual ~MessageMgr();

    void initialize(const sead::SafeString& projectName, u32 capacity);
    bool load(const sead::SafeString& path);
    bool unload(const sead::SafeString& path);
    Handle* getHandle(const sead::SafeString& path);

    static u32 getLanguageIdx();
    static const char* getLanguageByIdx(u32 idx);
    static const DirectoryInfo* getDirectoryInfo(const sead::SafeString& name);
    static const FileInfo* getFiles(const sead::SafeString& name);
    static u32 getFileCount(const sead::SafeString& name);
    static void formatLifeCount(sead::WBufferedSafeString* out, s32 lifeCount);

private:
    Entry* findEntry(const sead::SafeString& path);
    Entry* insertEntry(const sead::SafeString& path);

public:
    /* 0x014 */  u32 capacity;              //
    /* 0x018 */  Entry* entries;            //
    /* 0x01C */  u8 projectFile[0x190];     // RomFile
};

size_assert(MessageMgr, 0x1AC);
