#pragma once

#include "nw/ut/ResArray.h"
#include "nw/ut/ResDictionary.h"
#include "nw/ut/ResTypes.h"
#include "nw/ut/ResUtil.h"

namespace nw {

namespace gfx { class SceneNode; }

namespace anim { 

class AnimBlendOp;

namespace res {

struct ResAnimGroupData
{
    nw::ut::ResTypeInfo typeInfo;
    u32 m_Flags;
    ut::BinString toName;
    s32 m_TargetType;
    s32 m_MemberInfoSetDicCount;
    ut::Offset toMemberInfoSetDic;
    s32 m_BlendOperationsTableCount;
    ut::Offset toBlendOperationsTable;
};

class ResAnimGroup : public ut::ResCommon<ResAnimGroupData>
{
public:
    typedef ResAnimGroup SelfType;
    typedef ResAnimGroupData ResDataType;

    explicit ResAnimGroup(const void* p = nullptr) :
        nw::ut::ResCommon<ResAnimGroupData>(p) {}

    ResAnimGroupData& ref() { return *ptr(); }
    const ResAnimGroupData& ref() const { return *ptr(); }

    u32 GetFlags() const { return static_cast<u32>(ref().m_Flags); }
    void SetFlags(u32 value) { ref().m_Flags = value; }

    const char* GetName() const { return ref().toName.to_ptr(); }

    s32 GetTargetType() const { return static_cast<s32>(ref().m_TargetType); }
    void SetTargetType(s32 value) { ref().m_TargetType = value; }

    s32 GetMemberInfoSetCount() const { return ref().m_MemberInfoSetDicCount; }

    s32 GetBlendOperationsCount() const { return ref().m_BlendOperationsTableCount; }
    s32 GetBlendOperations(int idx) const
    {
        const s32* tablePtr = static_cast<const s32*>(ref().toBlendOperationsTable.to_table_ptr());
        return tablePtr[idx];
    }

    void SetBlendOperations(int idx, s32 value)
    {
        s32* tablePtr = GetBlendOperations();
        tablePtr[idx] = value;
    }

    s32* GetBlendOperations() { return static_cast<s32*>(ref().toBlendOperationsTable.to_table_ptr()); }
    const s32* GetBlendOperations() const { return static_cast<const s32*>(ref().toBlendOperationsTable.to_table_ptr()); }
};

} // namespace res
} // namespace anim
} // namespace nw