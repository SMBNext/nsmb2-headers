#pragma once

#include "sead/heap/seadDisposer.h"

namespace sead {

class CriticalSection : public IDisposer
{
public:
    CriticalSection();
    virtual ~CriticalSection();

    void lock();
    void unlock();
    bool tryLock();

private:
    u32 nnOsCriticalSection[3];
};

}
