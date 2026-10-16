#pragma once

#include "effect/PtclParam.h"
#include "sead/heap/seadHeap.h"
#include "sys/Common.h"

class PtclParamMgr
{
public:
    // C1 Address: 0x0027CDDC
    PtclParamMgr();

    // Address: 0x0027CD40
    void loadParam(sead::Heap* heap);

    // Address: 0x0049E550
    PtclParam* getParam(u32 index);

    inline u32 getParamCount() { return mParamCount; }

private:
    PtclParam* mParams;
    u32 mParamCount;
};
