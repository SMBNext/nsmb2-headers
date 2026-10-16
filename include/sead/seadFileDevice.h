#pragma once

#include "sead/heap/seadDisposer.h"
#include "sead/seadSafeString.h"

namespace sead {

class HandleBase;
class FileHandle;
class DirectoryHandle;

struct DirectoryEntry
{
    FixedSafeString<256> name;
    bool is_directory;
};


class FileDevice : public IDisposer /* TListNode */     // size: 0x50
{
public:
    enum FileOpenFlag : u8
    {
        cFileOpenFlag_ReadOnly  = 0,
        cFileOpenFlag_WriteOnly = 1,
        cFileOpenFlag_ReadWrite = 2,
        cFileOpenFlag_Create    = 3,
    };

    enum SeekOrigin : u8
    {
        cSeekOrigin_Begin   = 0,
        cSeekOrigin_Current = 1,
        cSeekOrigin_End     = 2,
    };

    struct LoadArg
    {
        SafeString path;                // 0
        u8* buffer = nullptr;           // 8
        u32 buffer_size = 0;            // C
        Heap* heap = nullptr;           // 10
        s32 alignment = 0;              // 14
        u32 div_size = 0;               // 18
        u32 read_size = 0;              // 1C
        u32 roundup_size = 0;           // 20
        bool need_unload = false;       // 24
    };
    size_assert(LoadArg, 0x28);

    ~FileDevice();

    virtual void* getRTTI();                                                                                            // nulled
    virtual bool isMatchDevice_(const HandleBase* handle) const;
    virtual bool doIsAvailable_() const;                                                                                // nulled
    virtual u8* doLoad_(LoadArg& arg);
    virtual FileDevice* doOpen_(sead::FileHandle* handle, const SafeString& filename, sead::FileDevice::FileOpenFlag flag);
    virtual bool doClose_(sead::FileHandle* handle);
    virtual bool doRead_(u32* read_size, FileHandle* handle, u8* buf, u32 size);
    virtual bool doWrite_(u32* write_size, FileHandle* handle, const u8* buf, u32 size);
    virtual bool doSeek_(FileHandle* handle, s32 offset, SeekOrigin origin);
    virtual bool doGetCurrentSeekPos_(u32* pos, FileHandle* handle);
    virtual bool doGetFileSize_(u32* size, const SafeString& filename);                                                 // nulled
    virtual bool doGetFileSize_(u32* size, FileHandle* handle);
    virtual bool doIsExistFile_(bool* is_exist, const SafeString& filename);
    virtual bool doIsExistDirectory_(bool* is_exist, const SafeString& filename);
    virtual FileDevice* doOpenDirectory_(DirectoryHandle* handle, const SafeString& dirname);
    virtual bool doCloseDirectory_(DirectoryHandle* handle);
    virtual bool doReadDirectory_(u32* read_num, DirectoryHandle* handle, DirectoryEntry* entry, u32 num);
    virtual bool doMakeDirectory_(const SafeString& path, u32);                                                         // nulled
    virtual u32 doGetLastRawError_() const;
    virtual const char* getArchiveName_() const;

    bool getPermission() const { return mPermission; }

    bool tryIsExistFile(bool* is_exist, const SafeString& path);
    bool tryGetFileSize(u32* size, FileHandle* handle);

    bool tryCloseDirectory(DirectoryHandle* handle);
    bool tryReadDirectory(u32* read_num, sead::DirectoryHandle* handle, DirectoryEntry* entry, u32 num);
    bool tryIsExistDirectory(bool* is_exist, const SafeString& path);

private:
    u8 listNode[0x10];                  // 10
    FixedSafeString<32> mDriveName;     // 20
    bool mPermission;                   // 4C
};


class HandleBase : public IDisposer     // size: 0x38
{
public:
    HandleBase() : mDevice(nullptr), mOriginalDevice(nullptr) {}

    bool isOpened() const { return mOriginalDevice != nullptr; }

    FileDevice* mDevice;                // 10
    FileDevice* mOriginalDevice;        // 14
    u8 mHandleBuffer[0x20];             // 18  sead::HandleBuffer, typedef of sead::SafeArray<0x20>
};


class FileHandle : public HandleBase    // size: 0x3C
{
public:
    FileHandle() : mDivSize(0) {}

    ~FileHandle();

    bool close();

    u32 read(u8* buf, u32 size);
    bool tryRead(u32* read_size, u8* buf, u32 size);

    u32 write(const u8* buf, u32 size);
    bool tryWrite(u32* write_size, const u8* buf, u32 size);

    u32 getFileSize();

    bool seek(s32 offset, FileDevice::SeekOrigin origin = FileDevice::cSeekOrigin_Begin);
    u32 getCurrentSeekPos();

private:
    u32 mDivSize;                       // 38
};

class DirectoryHandle : public HandleBase   // size: 0x38
{
public:
    ~DirectoryHandle();

    bool close();
    u32 read(sead::DirectoryEntry* entry, u32 num);
};

}
