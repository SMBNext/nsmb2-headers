#pragma once

#include "nw/types.h"

#include "nw/gfx/CalculatedTransform.h"
#include "nw/gfx/SceneNode.h"

#include "nw/gfx/res/ResSceneObject.h"

#include "nw/ut/Children.h"

namespace nw {
namespace gfx {

class TransformNode : public SceneNode
{

public:

    // 0x0048B668
    virtual const nw::ut::internal::RuntimeTypeInfo* GetRuntimeTypeInfo();

    struct Description : public SceneNode::Description
    {
        Description() {}
    };

    // 0x00173AEC
    static TransformNode* Create(SceneNode* parent, res::ResSceneObject resource, const TransformNode::Description& description, os::IAllocator* allocator);

    CalculatedTransform& Transform() { return m_Transform; }
    const CalculatedTransform& Transform() const { return m_Transform; }

    math::MTX34& WorldMatrix() { return m_WorldMatrix; }
    const math::MTX34& WorldMatrix() const { return m_WorldMatrix; }

    CalculatedTransform& WorldTransform() { return m_CalculatedTransform; }
    const CalculatedTransform& WorldTransform() const { return m_CalculatedTransform; }

    // 0x0048B674
    const math::MTX34& InverseWorldMatrix();

    // 0x00173A8C
    void InvalidateInverseWorldMatrix();
    
    virtual void UpdateDirection() {}

    // 0x001B37AC
    virtual void UpdateTransform(WorldMatrixUpdater* worldMatrixUpdater, SceneContext* sceneContext);

    // 0x00173A98
    virtual void Accept(ISceneVisitor* visitor);

    // 0x0048B6D4
    virtual const math::MTX34& TrackbackWorldMatrix();

    // 0x0048B6E4
    virtual const CalculatedTransform& TrackbackWorldTransform() const { return this->WorldTransform(); }

    // 0x0048B6DC
    virtual const CalculatedTransform& TrackbackLocalTransform();

    inline virtual void InheritTraversalResults();

protected:

    // 0x00173CB0
    TransformNode(os::IAllocator* allocator, res::ResTransformNode resObj, const TransformNode::Description& description);

    // 0x00174038
    virtual ~TransformNode() noexcept;

    // 0x00173764
    virtual Result Initialize(os::IAllocator* allocator);

    // 0x001738E8
    static void GetMemorySizeForInitialize(os::MemorySizeCalculator* pSize, res::ResTransformNode resTransformNode, Description description);

private:
    // 0x0017379C
    Result CreateCallbacks(os::IAllocator* allocator);
    
    CalculatedTransform m_Transform;
    math::MTX34 m_WorldMatrix;
    CalculatedTransform m_CalculatedTransform;

    mutable math::MTX34 m_InverseWorldMatrix;
    mutable bool m_IsInverseWorldMatrixValid;

    void* m_PostCalculateWorldMatrixSignal; // CalculateMatrixSignal
    bool m_IsBranchWorldMatrixCalculationEnabled;
    Description m_Description;
};

} // namespace gfx
} // namespace nw


