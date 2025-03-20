#pragma once

#include "nw/gfx/AnimGroup.h"
#include "nw/gfx/AnimObject.h"
#include "nw/gfx/GfxObject.h"

#include "nw/ut/MoveArray.h"

namespace nw {
namespace gfx {

class AnimBinding : public GfxObject
{
public:
    typedef ut::MoveArray<AnimGroup*> AnimGroupArray;
    typedef ut::MoveArray<AnimObject*> AnimObjectArray;

    // TODO: functions

protected:
    AnimBinding(os::IAllocator* allocator, int maxAnimObjects) :
        GfxObject(allocator), m_AnimObjectCountPerGroup(maxAnimObjects) {}


    // 0x00167DD8
    virtual ~AnimBinding() noexcept;

private:
    AnimGroupArray m_AnimGroups;
    AnimObjectArray m_AnimObjects;
    const int m_AnimObjectCountPerGroup;
};

} // namespace gfx
} // namespace nw