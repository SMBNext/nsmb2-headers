#pragma once

#include "sead.h"


class SarcMgr : public sead::IDisposer
{
    SEAD_SINGLETON_DISPOSER(SarcMgr);
public:
    void* getFile(const sead::SafeString& sarcPath, const sead::SafeString& path, u32* sizeOut = nullptr);
    bool close1814();
};
