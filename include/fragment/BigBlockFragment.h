#pragma once

#include "fragment/Fragment.h"
#include "sead/heap/seadHeap.h"
#include "math/Vec.h"
#include "gfx/AnimModel.h"

// Size: 0x5C
// Vtable: 0x005CB510
class BigBlockFragment : Fragment
{
    // Unknown class with nullsub constructor at 0x0031A7F4
    struct PartInfo
    {
        Vec3f mPosition;
        Vec3f mSpeed;
    };
    size_assert(PartInfo, 0x18);

public:
    enum class Type : u8
    {
        // Retail
        Big_Renga_Block     = 0x0,   // NSMBU Leftover
        Box_Wood_A          = 0x1,   // NSMBU Leftover
        Box_Wood_B          = 0x2,   // NSMBU Leftover
        Obj_Turaka_Rakka    = 0x3,   // NSMBU Leftover
        Kazan_Rock_A        = 0x4,   // 
        Kazan_Rock_B        = 0x5,   //
        Poltergeist         = 0x6,   // NSMBU Leftover
        Boss_Kameck_Block_A = 0x7,   // NSMBU Leftover
        Boss_Kameck_Block_B = 0x8,   // NSMBU Leftover
        Boss_Kameck_Block_C = 0x9,   // NSMBU Leftover
        Rock_A              = 0xA,   //
        Rock_B              = 0xB,   //
        Block_Hunka         = 0xC,   //
        Boss_Koopa_Lift     = 0xD,   //
        Battan_A            = 0xE,   //
        Battan_B            = 0xF,   //

        Count
    };

    static constexpr u8 TypeCount = static_cast<u8>(BigBlockFragment::Type::Count); 

public:
    // Original Address: 0x006123BC
    static sead::SafeString sResourceNames[];

    // Original Address: 0x0061243C
    static sead::SafeString sModelNames[][4];

    // Address: 0x005E6F10
    static s32 sRotationIncrement; // ((11.25 * 2147500000.0) / 180.0)

public:
    // Address: 0x0031AE04
    BigBlockFragment(sead::Heap* heap, const Vec3f& position, u32 flags);

    // Address: 0x0031A848
    void onCreate() override;

    // Address: 0x0031AC88
    void onExecute() override;

    // Address: 0x0031A7F8
    void onDraw() override;

    // Address: 0x0031AC38
    void onDelete() override;

    // Address: 0x0031A728
    void updateModelMatrix();

    AnimModelBase* mModels[4];
    HeapAllocator mAllocator;
    PartInfo mPartInfo[4];
    Type mType;
    u8 _D5[7];
};

size_assert(BigBlockFragment, 0xDC);
