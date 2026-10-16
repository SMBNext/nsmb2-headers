#pragma once

#include "sead/seadFileDevice.h"


namespace sead {

class FileDeviceMgr
{
public:
    static FileDeviceMgr* sInstance;

    FileDevice* tryOpen(FileHandle* handle, const SafeString& filename, FileDevice::FileOpenFlag flag, u32 div_num = 0);
    FileDevice* tryOpenDirectory(sead::DirectoryHandle* handle, const SafeString& dirname);
    u8* tryLoad(FileDevice::LoadArg& arg);

    FileDevice* findDevice(const SafeString& path) const;
    FileDevice* findDeviceFromPath(const SafeString& path, BufferedSafeString* no_drive_path = nullptr) const;
};

}
