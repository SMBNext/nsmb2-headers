#pragma once

#include "actors/ActorBase.h"

class BeansKuriboMgr    // Size: 0x20C
{
    SEAD_SINGLETON_DISPOSER(BeansKuriboMgr);
public:
    enum class BeanSelectState : u8
    {
        cNone       = 0,
        cSelected   = 1,
        cDetached   = 2,
    };

    void reset();   // 0x002E48C4

    /* 0x010 */  ActorUniqueID actorIDs[100];            //
    /* 0x1A0 */  s8 playerIDs[100];                      //
    /* 0x204 */  BeanSelectState beanSelectState[2];     // not sure where it's reset to 0
    /* 0x206 */  u16 beanSelectIdx[2];                   //

};
size_assert(BeansKuriboMgr, 0x20C);
