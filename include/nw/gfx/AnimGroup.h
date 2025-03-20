#pragma once

#include "nw/anim/res/ResAnimGroup.h"

#include "nw/gfx/Common.h"
#include "nw/gfx/SceneNode.h"

#include "nw/ut/MoveArray.h"

namespace nw { 

namespace os { class MemorySizeCalculator; }

namespace gfx {

namespace anim { class AnimBlendOp; }
class SceneNode;

class AnimGroup : public GfxObject
{
public:
    typedef bool (*PreEvaluateCallback)(AnimGroup* animGroup, int targetObjIdx);

    nw::anim::res::ResAnimGroup GetResAnimGroup() const { return m_ResAnimGroup; }

    const char* GetName() const { return m_ResAnimGroup.GetName(); }
    s32 GetMemberCount() const { return m_ResAnimGroup.GetMemberInfoSetCount(); }

    const anim::AnimBlendOp* GetBlendOperationInGroup(int blendOpIdx) const { return m_BlendOperations[blendOpIdx]; }
    void SetBlendOperationInGroup(int blendOpIdx, anim::AnimBlendOp* blendOp) { m_BlendOperations[blendOpIdx] = blendOp; }

    SceneNode* GetSceneNode() const { return m_SceneNode; }

    int GetTargetObjectIndex(int memberIdx) const { return m_TargetObjectIndicies[memberIdx]; }
    void SetTargetObjectIndex(int memberIdx, const int targetObjIdx) { m_TargetObjectIndicies[memberIdx] = targetObjIdx; }

    void* GetTargetObject(int memberIdx) const { return m_TargetObjects[memberIdx]; }
    void SetTargetObject(int memberIdx, void* object) { m_TargetObjects[memberIdx] = object; }

    void* GetTargetPtr(int memberIdx) const { return m_TargetPtrs[memberIdx]; }
    void SetTargetPtr(int memberIdx, void* target) { m_TargetPtrs[memberIdx] = target; }

    bool HasOriginalValue() const { return m_OriginalValues.size() != 0; }
    const void* GetOriginalValue(int memberIdx) const { return m_OriginalValues[memberIdx]; }
    void SetOriginalValue(int memberIdx, const void* value) { m_OriginalValues[memberIdx] = value; }

    PreEvaluateCallback GetPreEvaluateCallback() const { return m_PreEvaluateCallback; }
    void SetPreEvaluateCallback(PreEvaluateCallback function) { m_PreEvaluateCallback = function; }

    bool GetFullBakedAnimEnabled() const { return m_FullBakedAnimEnabled; }
    void SetFullBakedAnimEnabled(bool enable) { m_FullBakedAnimEnabled = enable; }

protected:
    // 0x0018D8D8
    AnimGroup(nw::anim::res::ResAnimGroup resAnimGroup, SceneNode* sceneNode, os::IAllocator* allocator);

    // 0x0018D984
    virtual ~AnimGroup() noexcept;

    // 0x0018D834
    static void GetMemorySizeForInitialize(os::MemorySizeCalculator* pSize, const nw::anim::res::ResAnimGroup resAnimGroup, bool useOriginalValue);

    // 0x0018CA54
    Result Initialize(bool useOriginalValue);

private:
    nw::anim::res::ResAnimGroup m_ResAnimGroup;
    ut::MoveArray<anim::AnimBlendOp*> m_BlendOperations;

    SceneNode* m_SceneNode;
    ut::MoveArray<int> m_TargetObjectIndicies;
    ut::MoveArray<void*> m_TargetObjects;
    ut::MoveArray<void*> m_TargetPtrs;
    ut::MoveArray<const void*> m_OriginalValues;

    PreEvaluateCallback m_PreEvaluateCallback;

    bool m_FullBakedAnimEnabled;
};

} // namespace gfx
} // namespace nw


