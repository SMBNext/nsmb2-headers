#include "types.h"
#include "nn/result.h"
#include "nn/handle.h"
#include "nn/fnd.h"

enum OpenMode
{
    OPEN_MODE_READ   = (1 << 0),
    OPEN_MODE_WRITE  = (1 << 1),
    OPEN_MODE_CREATE = (1 << 2),
};

struct DirectoryEntry       // size: 0x228
{
    wchar_t name[0x106];    // 0
    u8 _20C[0x10];          // 20C
    bool isDirectory;       // 21C
    bool isHidden;          // 21D
    bool isArchive;         // 21E
    bool isReadOnly;        // 21F
    s64 entrySize;          // 220
};

nn::Result TryDeleteFile(const wchar_t* path);
nn::Result TryCreateFile(const wchar_t* path, s64 size);
nn::Result GetFileTimeStamp(const wchar_t* path, nn::fnd::DateTime* out);

nn::Result TryOpenFile(void** out, const wchar_t* path, u32 mode);
void CloseFile(void* ptr);

nn::Result TryGetFileSize(s64* out, void* ptr);

nn::Result TryReadFile(s32* out, void* ptr, s64 offset, void* buffer, size_t size);
nn::Result TryWriteFile(s32* out, void* ptr, s64 offset, void* buffer, size_t size, bool flush);

nn::Result TryCreateDirectory(const wchar_t* path);

nn::Result TryOpenDirectory(void** out, const wchar_t* path);
void CloseDirectory(void* ptr);

nn::Result TryReadDirectory(s32* out, void* ptr, DirectoryEntry* entries, s32 numEntries);

nn::Result MountRom(const char* name, size_t maxFiles, size_t maxDirs, void* workMem, size_t workMemSize, bool cache);
nn::Result MountRom(size_t maxFiles, size_t maxDirs, void* workMem, size_t workMemSize, bool cache);
nn::Result MountSdmc(const char* name);
nn::Result Unmount(const char* name);


// Replicates a base class used by more complex file classes of nn::fs
class File
{
public:
    File() :
        data(nullptr) { }

    ~File()
    {
        Close();
    }

    void Close()
    {
        if (ptr())
        {
            CloseFile(ptr());
            data = nullptr;
        }
    }

    nn::Result TryOpen(const wchar_t* path, u32 mode)
    {
        return TryOpenFile(&data, path, mode);
    }

    nn::Result TryGetSize(s64* size)
    {
        return TryGetFileSize(size, ptr());
    }

    nn::Result TryRead(s32* readLen, s64 offset, void* buffer, size_t size)
    {
        return TryReadFile(readLen, ptr(), offset, buffer, size);
    }

    s32 Read(s64 offset, void* buffer, size_t size)
    {
        s32 ret;
        TryRead(&ret, offset, buffer, size);
        return ret;
    }

    nn::Result TryWrite(s32* writtenLen, s64 offset, void* buffer, size_t size, bool flush)
    {
        return TryWriteFile(writtenLen, ptr(), offset, buffer, size, flush);
    }

    s32 Write(s64 offset, void* buffer, size_t size, bool flush)
    {
        s32 ret;
        TryWrite(&ret, offset, buffer, size, flush);
        return ret;
    }

    nn::Result TryFlush();

private:
    // Bit 1 is used as flush flag. Only seems to be used for panic if not flushed on close
    void* data;

    void* ptr() { return (void*)((u32)data & ~1); }
};


class Directory
{
public:
    Directory() :
        data(nullptr) { }

    ~Directory()
    {
        if (data)
        {
            CloseDirectory(data);
            data = nullptr;
        }
    }

    nn::Result TryOpen(const wchar_t* path)
    {
        return TryOpenDirectory(&data, path);
    }

    nn::Result TryRead(s32* out, DirectoryEntry* entries, s32 numEntries)
    {
        return TryReadDirectory(out, data, entries, numEntries);
    }

private:
    void* data;
};
