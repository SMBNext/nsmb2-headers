#pragma once

#include "sead/heap/seadDisposer.h"
#include "sead/seadSafeString.h"
#include "types.h"

namespace Lyt {

// Size: 0x14
// Vtable: 0x005C163C
class LayoutResLoader
{
    SEAD_SINGLETON_DISPOSER(LayoutResLoader);

public:    
    enum ResourceSet
    {
        ResourceSet_Global                      = 0x0, // Used by ScBoot
        ResourceSet_ScCourseIn                  = 0x1,
        ResourceSet_ScCourse1P                  = 0x2, // Used when playing single player
        ResourceSet_ScCourse2P                  = 0x3, // Used when playing Co-op
        ResourceSet_ScCourseCoinRush            = 0x4, // Used when playing CoinRush normally
        ResourceSet_ScCourseCoinRushChallenge   = 0x5, // Used when challenging a CoinRush record
        ResourceSet_ScGameOver                  = 0x6,
        ResourceSet_ScCourseSelect              = 0x7,
        ResourceSet_ScTitleMenu                 = 0x8,
        ResourceSet_ScMatching                  = 0x9,
        ResourceSet_ScCoinRushMenu              = 0xA,
        ResourceSet_ScShop                      = 0xB,
        ResourceSet_ScPackSelect                = 0xC,
        ResourceSet_CoinRush                    = 0xD, // Used by ScCoinRushMiiSelect  & ScCoinRushResult
        ResourceSet_Countdown                   = 0xE, // Used by CannonWarp & Kinopio
        ResourceSet_EventWindow                 = 0xF, // Used by ScExceedCoinNum & ScCongratulation
        
        ResourceSet_Count,
    };
    
    static constexpr u32 sResourceSetCount = ResourceSet_Count;

public:
    // Deleted
    virtual void vf0();

    // Address D1: 0x0038CB44
    virtual ~LayoutResLoader();


    // 0x005EF788
    static const sead::SafeString* sResourceSets[sResourceSetCount];

    // 0x005869D8
    static u32 sResourceCounts[sResourceSetCount];

    array_length_assert(sResourceCounts, sResourceSetCount);
    array_length_assert(sResourceSets, sResourceSetCount);

    void load(u32 resourceSetID);
    void unload(u32 resourceSetID);
    u32 getTotalResourceCount();
};

size_assert(LayoutResLoader, 0x14);

} // namespace Lyt
