#pragma once

#include "sead.h"
#include "actors/ActorBase.h"

class BeansKuriboMgr
{
    SEAD_SINGLETON_DISPOSER(BeansKuriboMgr);
public:
  ActorUniqueID actorIDs[100];      // 10
  u8 playerIDs[100];                // 1A0
  u8 _204[2];                       // 204
  u16 _206[2];                      // 206
};

size_assert(BeansKuriboMgr, 0x20C);
