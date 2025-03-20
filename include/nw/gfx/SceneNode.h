#pragma once

#include "nw/gfx/CalculatedTransform.h"
#include "nw/gfx/ISceneVisitor.h"
#include "nw/gfx/res/ResSceneObject.h"
#include "nw/gfx/SceneObject.h"

#include "nw/ut/Children.h"
#include "nw/ut/ResUtil.h"
#include "nw/ut/RuntimeTypeInfo.h"

#include "nw/gfx/AnimBinding.h"

namespace nw {
namespace gfx {

class AnimBinding;
class WorldMatrixUpdater;
class SceneContext;

class SceneNode;
typedef ut::Children<SceneNode, SceneNode, ut::ChildDetacher<SceneNode>> SceneNodeChildren;

class SceneNode : public SceneObject
{

public:
    SceneNode(const SceneNode&);
    void operator=(const SceneNode&);

public:
    // Inlined
    const SceneNode* GetParent() const { return m_Parent; }

    // Inlined
    SceneNode* GetParent() { return m_Parent; }

    // Inlined
    void SetParent(SceneNode* parent) { m_Parent = parent; }

private:
    SceneNode* m_Parent;

public:
    // 0x0048E14C
    virtual const nw::ut::internal::RuntimeTypeInfo* GetRuntimeTypeInfo() const;
    
    // 0x005F3498
    static const nw::ut::internal::RuntimeTypeInfo s_TypeInfo;

    enum TraversalResults
    {
        FLAG_IS_VISIBLE = 1,
        FLAG_IS_DIRTY = 2,
        FLAG_DEFAULT = FLAG_IS_VISIBLE | FLAG_IS_DIRTY
    };

    struct Description
    {
        bool isFixedSizeMemory;
        bool isAnimationEnabled;
        s32 maxCallbacks;
        s32 maxChildren;
        s32 maxAnimObjectsPerGroup;

        Description() :
            isFixedSizeMemory(true),
            isAnimationEnabled(true),
            maxCallbacks(4),
            maxChildren(8),
            maxAnimObjectsPerGroup(1) {}
    };

    //TODO: class DynamicBuilder

    // 0x0018E5C0
    static SceneNode* Create(SceneNode* parent, res::ResSceneObject resource, const SceneNode::Description& description, os::IAllocator* allocator);

    // Inlined
    res::ResSceneNode GetResSceneNode() { return ut::ResStaticCast<res::ResSceneNode>( this->GetResSceneObject() ); }

    // Inlined
    const res::ResSceneNode GetResSceneNode() const { return ut::ResStaticCast<res::ResSceneNode>( this->GetResSceneObject() ); }

    // Deleted
    virtual void UpdateTransform(WorldMatrixUpdater* worldMatrixUpdater, SceneContext* sceneContext);

    // 0x0018DAC0
    bool AttachChild(SceneNode* child);

    // 0x0018E56C
    virtual void Accept(ISceneVisitor* visitor);

    // 0x0048E178
    virtual const math::MTX34& TrackbackWorldMatrix() const;

    // 0x0048E234
    virtual const CalculatedTransform& TrackbackWorldTransform() const;

    // 0x0048E1A4
    virtual const CalculatedTransform& TrackbackLocalTransform() const;

    // Inlined
    void UpdateFrame();

    // Inlined
    bit32 GetTraversalResults() const { return this->m_TraversalResults; }

    // Inlined
    void SetTraversalResults(bit32 results) { this->m_TraversalResults = results; }

    // Inlined
    void EnableTraversalResults(bit32 results) { this->m_TraversalResults |= results; }

    // Inlined
    void ResetTraversalResults() { this->m_TraversalResults = FLAG_DEFAULT; }
    
    // Inlined
    void CopyTraversalResults(const SceneNode* node) { if (node != nullptr) this->m_TraversalResults = node->GetTraversalResults(); }
    
    // Inlined
    inline virtual void InheritTraversalResults();

    // Inlined
    void SetBranchVisible(bool isBranchVisible) { m_BranchVisible = isBranchVisible; }

    // Inlined
    bool IsBranchVisible() const { return m_BranchVisible; }

protected:

    // 0x0018E7E0
    virtual ~SceneNode() noexcept;

    // 0x0048E158
    bool IsCircularReference(const SceneNode* child) const;

    // 0x0018DA68
    virtual Result Initialize(os::IAllocator* allocator);

    SceneNodeChildren m_Children;
    GfxPtr<AnimBinding> m_AnimBinding;
    bool m_BranchVisible;

private:
    // 0x0018DC20
    Result CreateChildren(os::IAllocator* allocator);

    // 0x0018E028
    Result CreateCallbacks(os::IAllocator* allocator);

    // 0x0018E174
    Result CreateAnimBinding(os::IAllocator* allocator);

    void* m_PreUpdateSignal; // UpdateSignal*
    s32 m_TraversalResults;
    Description m_Description;
};

} // namespace gfx
} // namespace nw


