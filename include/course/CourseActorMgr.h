#include "sead.h"
#include "math/Vec.h"
#include "actors/ActorBase.h"


class CourseActorMgr
{

    // createInstance()                             Address: 0x003FD554
    // deleteInstance()                             Address: 0x003FD5E4
    // sInstance                                    Address: 0x005E2D18
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x003FD6B0
    // SingletonDisposer_::sStaticDisposer          Address: 0x005E2D1C
    // SingletonDisposer_::vtbl                     Address: 0x005C9CA8
    SEAD_SINGLETON_DISPOSER(CourseActorMgr);

    struct ActorList
    {
        u32 maxCapacity;
        ActorBase** actorList;
        u32 currentCapacity;
        ActorBase** actorListEnd;
    };
    size_assert(ActorList, 0x10);

public:
    ActorBase* create(ActorBase::CreateInfo* info);
    ActorBase* searchById(s32 id);
    ActorBase* searchByProfileId(u32 id);
    ActorBase* searchByProfileId(u32 id, ActorBase* prev);
    ActorBase* countByProfileId(u32 id);

    sead::FixedPtrArray<ActorBase, 512> mActors;
    ActorList mActorList;
};

size_assert(CourseActorMgr, 0x82C);