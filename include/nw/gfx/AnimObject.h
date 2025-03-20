#pragma once

#include "nw/anim/AnimResult.h"

#include "nw/gfx/AnimGroup.h"
#include "nw/gfx/Common.h"
#include "nw/gfx/GfxObject.h"

#include "nw/ut/MoveArray.h"
#include "nw/ut/RuntimeTypeInfo.h"

namespace nw { namespace gfx {

class AnimObject : public GfxObject
{
public:
    // Deleted
    virtual const nw::ut::internal::RuntimeTypeInfo* GetRuntimeTypeInfo();

    // 0x005F32C0
    static const nw::ut::internal::RuntimeTypeInfo s_TypeInfo;

    // Inlined
    AnimObject(os::IAllocator* allocator, u32 animType) :
        GfxObject(allocator), m_AnimGroup(nullptr), m_AnimType(animType) {}

    // Deleted
    virtual ~AnimObject() noexcept;

    // Deleted
    virtual Result TryBind(AnimGroup* animGroup) = 0;

    // Deleted
    virtual void Release() = 0;

    // Deleted
    virtual void UpdateFrame() = 0;

    // Deleted
    virtual const nw::anim::AnimResult* GetResult(void* target, int memberIdx) const = 0;

    // Deleted
    virtual bool HasMemberAnim(int memberIdx) const = 0;

    // Deleted
    virtual void UpdateCache() = 0;

    bool Bind(AnimGroup* animGroup) { return TryBind(animGroup).IsSuccess(); }

    const AnimGroup* GetAnimGroup() const { return m_AnimGroup; }
    AnimGroup* GetAnimGroup() { return m_AnimGroup; }
    void SetAnimGroup(AnimGroup* group) { m_AnimGroup = group; }

    enum 
    {
        ANIMTYPE_SIMPLE,
        ANIMTYPE_TRANSFORM_SIMPLE,
        ANIMTYPE_BLENDER
    };

    u32 GetAnimType() const { return m_AnimType; }

protected:
    AnimGroup* m_AnimGroup;
    u32 m_AnimType;
};

} // namespace gfx
} // namespace nw