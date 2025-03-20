#pragma once

#include "sead/heap/seadDisposer.h"

#include "math/Vec.h"

#include "fragment/BigBlockFragment.h"

enum class WaterSplashFlags : u32
{
    FLAGS_NONE = 0x0,

    // Splash types (Mask: 0xF)
    TYPE_WATER_SMALL  = 0x0,   // 0x0
    TYPE_WATER_LARGE  = 0x1,   // 0x1
    TYPE_LAVA_SMALL   = 0x2,   // 0x2
    TYPE_LAVA_LARGE   = 0x3,   // 0x3
    TYPE_POISON_SMALL = 0x4,   // 0x4
    TYPE_POISON_LARGE = 0x5,   // 0x5

    // Layer flag (Mask: 0x10000)
    LAYER_FLAG = 0x10000    // 0x1 << 20
};

inline WaterSplashFlags operator|(WaterSplashFlags lhs, WaterSplashFlags rhs)
{
    return static_cast<WaterSplashFlags>(static_cast<u32>(lhs) | static_cast<u32>(rhs));
};

enum class CoinFragmentHitDirection : u8
{
    HIT_DIR_RIGHT = 0x0,   //
    HIT_DIR_LEFT  = 0x1,   //
    HIT_DIR_BELOW = 0x2,   //
    HIT_DIR_ABOVE = 0x3,   //
};

enum class BlockFragmentFlags : u32
{
    FLAGS_NONE = 0x0,

    // Break directions (Mask: 0x3)
    BREAK_DIR_RIGHT = 0x0,   //
    BREAK_DIR_LEFT  = 0x1,   //
    BREAK_DIR_UP    = 0x2,   //
    BREAK_DIR_DOWN  = 0x3,   //

    // Tile types (Mask: 0xF00)
    TYPE_BRICK    = 0x000,   // 0x0 << 8
    TYPE_STONE    = 0x100,   // 0x1 << 8
    TYPE_WOOD     = 0x200,   // 0x2 << 8
    TYPE_QUESTION = 0x300,   // 0x3 << 8
    TYPE_USED_A   = 0x400,   // 0x4 << 8
    TYPE_RED      = 0x500,   // 0x5 << 8
    TYPE_USED_B   = 0x500,   // 0x5 << 8
    TYPE_UNK      = 0x700,   // 0x7 << 8

    // Velocity flag (Mask: 0x1000)
    VELOCITY_NORMAL = 0x0000,   // 0x0 << 16
    VELOCITY_HIGH   = 0x1000    // 0x1 << 16
};

inline BlockFragmentFlags operator|(BlockFragmentFlags lhs, BlockFragmentFlags rhs)
{
    return static_cast<BlockFragmentFlags>(static_cast<u32>(lhs) | static_cast<u32>(rhs));
};

// TODO: Figure out what these flags do
// TODO: There may be more flags here
enum class PipeFragmentFlags : u32
{
    FLAGS_NONE = 0x0,

    // UnkA (Mask: 0xF0000)
    UnkA_0 = 0x00000,   // 0x0 << 16
    UnkA_1 = 0x10000,   // 0x1 << 16
    UnkA_2 = 0x20000,   // 0x2 << 16
    UnkA_3 = 0x30000,   // 0x3 << 16
    UnkA_4 = 0x40000,   // 0x4 << 16
    UnkA_5 = 0x50000,   // 0x5 << 16
    UnkA_6 = 0x60000,   // 0x6 << 16
    UnkA_7 = 0x70000,   // 0x7 << 16
    UnkA_8 = 0x80000,   // 0x8 << 16
    UnkA_9 = 0x90000,   // 0x9 << 16
    UnkA_A = 0xA0000,   // 0xA << 16
    UnkA_B = 0xB0000,   // 0xB << 16
    UnkA_C = 0xC0000,   // 0xC << 16
    UnkA_D = 0xD0000,   // 0xD << 16
    UnkA_E = 0xE0000,   // 0xE << 16
    UnkA_F = 0xF0000,   // 0xF << 16

    // UnkB (Mask: 0x100000)
    UnkB = 0x100000,   // 0x1 << 20

    // UnkC (Mask: 0x200000)
    UnkC = 0x200000,   // 0x2 << 20

    // UnkD (Mask: 0x3000000)
    UnkD_1 = 0x1000000,   // 0x1 << 24
    UnkD_2 = 0x2000000,   // 0x2 << 24
    UnkD_3 = 0x3000000,   // 0x3 << 24

    // UnkE (Mask: 0x10000000)
    UnkE = 0x10000000,   // 0x1 << 28
};

inline PipeFragmentFlags operator|(PipeFragmentFlags lhs, PipeFragmentFlags rhs)
{
    return static_cast<PipeFragmentFlags>(static_cast<u32>(lhs) | static_cast<u32>(rhs));
};

// Size: 0x38
// Vtable: 0x005A5C44
class FragmentMgr
{
    // createInstance()                             Address: 0x00227108
    // deleteInstance()                             Address: 0x00227198
    // sInstance                                    Address: 0x005E6FA0
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x002272D0
    // SingletonDisposer_::sStaticDisposer          Address: 0x005E6FA4
    // SingletonDisposer_::vtbl                     Address: 0x005A5C34
    SEAD_SINGLETON_DISPOSER(FragmentMgr);

public:

    // Deleted
    FragmentMgr();

    // D1 Address: 0x00227B30
    // D2 Address: 0x00227B2C
    virtual ~FragmentMgr();

    // Address: 0x002271E4
    void createWaterSplash(const Vec3f& position, WaterSplashFlags flags, const Vec3f& scale);

    // Address: 0x00227320
    void createCoinFragment(const Vec3f& position, CoinFragmentHitDirection hitDirection, s32 playerID, bool showScore, bool hasTail, bool isBlueCoin);

    // Address: 0x0022742C 
    void createBlockFragment(const Vec3f& position, BlockFragmentFlags flags, s32 playerID);

    // Address 0x00227534
    void createPipeFragment(const Vec3f& position, PipeFragmentFlags flags, s32 playerID);

    // Address: 0x0022763C
    void createBigBlockFragment(const Vec3f& position, BigBlockFragment::Type type);

    // Address: 0x00227728
    void createCoinTailFragment(const Vec3f& position);

    // Address: 0x0022780C
    void createBigBlockFragmentUnderwater(const Vec3f& position, BigBlockFragment::Type type);

    // Address: 0x002278FC
    void draw();

    // Address: 0x00227954
    void reset();

    // Address: 0x002279C4
    void execute();

    // Address: 0x00227ACC
    void createFragmentUnitHeap(sead::Heap* parentHeap);

private:
    sead::Heap* mFragmentUnitHeap;  // 0x14 - is actually a sead::UnitHeap
    sead::ListImpl mListImpl;       // 0x18
    u32 _24;                        // 0x24
    sead::ListNode mListNode;       // 0x28
    u32 _30;                        // 0x30
    u32 _34;                        // 0x34
};

size_assert(FragmentMgr, 0x38);