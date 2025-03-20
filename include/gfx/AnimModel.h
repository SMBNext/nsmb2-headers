#pragma once

#include "gfx/AnimModelBase.h"

template <s32 skeletalCount, s32 materialCount, s32 visibilityCount>
class AnimModel : public AnimModelBase
{
public:

    AnimModel() :
        AnimModelBase(
            skeletalCount,   &animBuf[skeletalOffset],
            materialCount,   &animBuf[materialOffset],
            visibilityCount, &animBuf[visibilityOffset]
        ) {}

private:
    static constexpr s32 totalCount = skeletalCount + materialCount + visibilityCount;

    static constexpr s32 skeletalOffset = 0;
    static constexpr s32 skeletalEnd = skeletalOffset + skeletalCount;

    static constexpr s32 materialOffset = skeletalEnd;
    static constexpr s32 materialEnd = materialOffset + materialCount;

    static constexpr s32 visibilityOffset = materialEnd;

    AnimBase* animBuf[totalCount > 0 ? totalCount : 1];
};

// Specialization for all counts being `0`
template <>
class AnimModel<0, 0, 0> : public AnimModelBase
{
public:
    AnimModel() :
        AnimModelBase(0, nullptr, 0, nullptr, 0, nullptr) {}
};

static_assert(sizeof(AnimModel<0,0,0>) == 0x38);
static_assert(sizeof(AnimModel<0,0,1>) == 0x3C);
static_assert(sizeof(AnimModel<1,1,1>) == 0x44);
static_assert(sizeof(AnimModel<1,2,1>) == 0x48);
static_assert(sizeof(AnimModel<2,2,1>) == 0x4C);