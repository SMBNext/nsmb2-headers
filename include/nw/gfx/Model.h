#pragma once

#include "nw/gfx/AnimBinding.h"
#include "nw/gfx/Material.h"
#include "nw/gfx/res/ResMesh.h"
#include "nw/gfx/res/ResModel.h"
#include "nw/gfx/TransformNode.h"

#include "nw/ut/Children.h"

namespace nw { namespace gfx {

class SceneNode;
typedef ut::Children<SceneNode, SceneNode, ut::ChildDetacher<SceneNode> > SceneNodeChildren;

class Model : public TransformNode
{
public:

    enum BufferOption
    {
        FLAG_BUFFER_SHADER_PARAMETER_SHIFT,
        FLAG_BUFFER_SHADING_PARAMETER_SHIFT,
        FLAG_BUFFER_MATERIAL_COLOR_SHIFT,
        FLAG_BUFFER_RASTERIZATION_SHIFT,
        FLAG_BUFFER_TEXTURE_COORDINATOR_SHIFT,
        FLAG_BUFFER_TEXTURE_MAPPER_SHIFT,
        FLAG_BUFFER_PROCEDURAL_TEXTURE_MAPPER_SHIFT,
        FLAG_BUFFER_FRAGMENT_LIGHTING_SHIFT,
        FLAG_BUFFER_FRAGMENT_LIGHTING_TABLE_SHIFT,
        FLAG_BUFFER_TEXTURE_COMBINER_SHIFT,
        FLAG_BUFFER_ALPHA_TEST_SHIFT,
        FLAG_BUFFER_FRAGMENT_OPERATION_SHIFT,
        FLAG_BUFFER_SCENE_ENVIRONMENT_SHIFT,

        FLAG_BUFFER_SHADER_PARAMETER          = 0x1 << FLAG_BUFFER_SHADER_PARAMETER_SHIFT,
        FLAG_BUFFER_SHADING_PARAMETER         = 0x1 << FLAG_BUFFER_SHADING_PARAMETER_SHIFT,
        FLAG_BUFFER_MATERIAL_COLOR            = 0x1 << FLAG_BUFFER_MATERIAL_COLOR_SHIFT,
        FLAG_BUFFER_RASTERIZATION             = 0x1 << FLAG_BUFFER_RASTERIZATION_SHIFT,
        FLAG_BUFFER_TEXTURE_COORDINATOR       = 0x1 << FLAG_BUFFER_TEXTURE_COORDINATOR_SHIFT,
        FLAG_BUFFER_TEXTURE_MAPPER            = 0x1 << FLAG_BUFFER_TEXTURE_MAPPER_SHIFT,
        FLAG_BUFFER_PROCEDURAL_TEXTURE_MAPPER = 0x1 << FLAG_BUFFER_PROCEDURAL_TEXTURE_MAPPER_SHIFT,
        FLAG_BUFFER_FRAGMENT_LIGHTING         = 0x1 << FLAG_BUFFER_FRAGMENT_LIGHTING_SHIFT,
        FLAG_BUFFER_FRAGMENT_LIGHTING_TABLE   = 0x1 << FLAG_BUFFER_FRAGMENT_LIGHTING_TABLE_SHIFT,
        FLAG_BUFFER_TEXTURE_COMBINER          = 0x1 << FLAG_BUFFER_TEXTURE_COMBINER_SHIFT,
        FLAG_BUFFER_ALPHA_TEST                = 0x1 << FLAG_BUFFER_ALPHA_TEST_SHIFT,
        FLAG_BUFFER_FRAGMENT_OPERATION        = 0x1 << FLAG_BUFFER_FRAGMENT_OPERATION_SHIFT,
        FLAG_BUFFER_SCENE_ENVIRONMENT         = 0x1 << FLAG_BUFFER_SCENE_ENVIRONMENT_SHIFT,

        FLAG_BUFFER_NOT_USE = 0,

        MULTI_FLAG_BUFFER_FRAGMENT_SHADER = 
            FLAG_BUFFER_FRAGMENT_LIGHTING         |
            FLAG_BUFFER_FRAGMENT_LIGHTING_TABLE   |
            FLAG_BUFFER_TEXTURE_COMBINER          |
            FLAG_BUFFER_ALPHA_TEST,

        MULTI_FLAG_BUFFER_MATERIAL = 
            FLAG_BUFFER_SHADER_PARAMETER          |
            FLAG_BUFFER_SHADING_PARAMETER         |
            FLAG_BUFFER_MATERIAL_COLOR            |
            FLAG_BUFFER_RASTERIZATION             |
            FLAG_BUFFER_TEXTURE_COORDINATOR       |
            FLAG_BUFFER_TEXTURE_MAPPER            |
            FLAG_BUFFER_PROCEDURAL_TEXTURE_MAPPER |
            FLAG_BUFFER_FRAGMENT_LIGHTING         |
            FLAG_BUFFER_FRAGMENT_LIGHTING_TABLE   |
            FLAG_BUFFER_TEXTURE_COMBINER          |
            FLAG_BUFFER_ALPHA_TEST                |
            FLAG_BUFFER_FRAGMENT_OPERATION        |
            FLAG_BUFFER_SCENE_ENVIRONMENT,

        MULTI_FLAG_ANIMATABLE_MATERIAL = 
            FLAG_BUFFER_MATERIAL_COLOR      |
            FLAG_BUFFER_TEXTURE_COORDINATOR |
            FLAG_BUFFER_TEXTURE_MAPPER      |
            FLAG_BUFFER_FRAGMENT_OPERATION,

        MULTI_FLAG_LIGHTING_MATERIAL = 
            FLAG_BUFFER_SHADING_PARAMETER       |
            FLAG_BUFFER_MATERIAL_COLOR          |
            FLAG_BUFFER_FRAGMENT_LIGHTING       |
            FLAG_BUFFER_FRAGMENT_LIGHTING_TABLE |
            FLAG_BUFFER_SCENE_ENVIRONMENT
    };


public:
    // 0x0048E054
    virtual const nw::ut::internal::RuntimeTypeInfo* GetRuntimeTypeInfo();

    struct Description : public TransformNode::Description
    {
        u32 bufferOption;
        Model* sharedMaterialModel;

        Description() :
            bufferOption(0), sharedMaterialModel(nullptr) {}
    };

    // 0x001868F4
    static Model* Create(SceneNode* parent, res::ResSceneObject resource, const Model::Description& description, os::IAllocator* allocator);

    static size_t GetMemorySize(res::ResModel resModel, Description description, size_t alignment = 4);

    static void GetMemorySizeInternal(os::MemorySizeCalculator* pSize, res::ResModel resModel, Description description);

    // 0x001868A0
    virtual void Accept(ISceneVisitor* visitor);

    res::ResModel GetResModel() { return res::ResModel(this->GetResSceneObject().ptr()); }

    const res::ResModel GetResModel() const { return res::ResModel(this->GetResSceneObject().ptr()); }

    AnimGroup* GetMaterialAnimGroup() { return m_MaterialAnimGroup; }
    const AnimGroup* GetMaterialAnimGroup() const { return m_MaterialAnimGroup; }

    int GetMaterialAnimBindingIndex() const { return m_MaterialAnimBindingIndex; }

    AnimGroup* GetVisibilityAnimGroup() { return m_VisibilityAnimGroup; }
    const AnimGroup* GetVisibilityAnimGroup() const { return m_VisibilityAnimGroup; }

    int GetVisibilityAnimBindingIndex() const { return m_VisibilityAnimBindingIndex; }

    typedef gfx::MaterialArray MaterialArray;

    int GetMaterialCount() const { return m_Materials.size(); }

    Material* GetMaterial(int index) { return m_Materials[index]; }
    const Material* GetMaterial(int index) const { return m_Materials[index]; }

    const void* GetMaterialActivator() const { return this->m_MaterialActivator.Get(); }
    void* GetMaterialActivator() { return this->m_MaterialActivator.Get(); }

    bit32 GetBufferOption() const { return this->m_BufferOption; }

    math::MTX34& ModelViewMatrix() { return this->m_ModelViewMatrix; }
    const math::MTX34& ModelViewMatrix() const { return this->m_ModelViewMatrix; }

    math::MTX34& NormalMatrix() { return this->m_NormalMatrix; }
    const math::MTX34& NormalMatrix() const { return this->m_NormalMatrix; }

    inline void UpdateModelViewMatrixAndNormalMatrix(const math::MTX34& viewMatrix, bool isModelCoordinate);

    u8 GetLayerId() const { return m_LayerId; }
    void SetLayerId(u8 layerId) { m_LayerId = layerId; }

    bool IsVisible() const { return m_Visible; }
    void SetVisible(bool visible) { m_Visible = visible; }

    template<typename Type>
    Type GetUserParameter() const
    { return *reinterpret_cast<const Type*>(&m_UserParameter); }

    template<typename Type>
    void SetUserParameter(Type parameter)
    { m_UserParameter = *reinterpret_cast<u32*>(&parameter); }

protected:

    // 0x00185098
    virtual Result Initialize(os::IAllocator* allocator);

    Model(os::IAllocator* allocator, res::ResTransformNode resource, const Model::Description& description) :
        TransformNode(allocator, resource, description), 
        m_MaterialAnimGroup(nullptr),
        m_MaterialAnimBindingIndex(0),
        m_VisibilityAnimGroup(nullptr),
        m_VisibilityAnimBindingIndex(0),
        m_PreRenderSignal(nullptr),
        m_PostRenderSignal(nullptr),
        m_MeshBuffers(nullptr, nullptr),
        m_BufferOption(description.bufferOption),
        m_ModelViewMatrix(math::MTX34::ident),
        m_NormalMatrix(math::MTX34::ident),
        m_LayerId(0),
        m_OriginalVisibility(true),
        m_Visible(true),
        m_SharingMaterial(description.sharedMaterialModel != nullptr),
        m_Description(description),
        m_UserParameter(0)
    {
        // SetVisible(ResStaticCast<res::ResModel>(resource).IsVisible());
    }

    // 0x00186CD4
    virtual ~Model() noexcept;

private:

    // 0x00185A44
    void BindMaterialAnim(AnimGroup* animGroup);

    // 0x00185EB0
    void BindVisibilityAnim(AnimGroup* animGroup);

    // 0x00185740
    Result CreateResMeshes(os::IAllocator* allocator);

    // void DestroyResMeshes(os::IAllocator* allocator, ResMeshArray resMeshes);

    // 0x0018653C
    Result CreateResMeshNodeVisibilities(os::IAllocator* allocator);

    // 0x00185530
    Result CreateMaterials(os::IAllocator* allocator);

    // 0x00185CC8
    Result CreateAnimGroups(os::IAllocator* allocator);

    // 0x001852A4
    Result CreateCallbacks(os::IAllocator* allocator);

    AnimGroup* m_MaterialAnimGroup;
    s32 m_MaterialAnimBindingIndex;

    AnimGroup* m_VisibilityAnimGroup;
    s32 m_VisibilityAnimBindingIndex;

    void* m_PreRenderSignal; // RenderSignal
    void* m_PostRenderSignal; // RenderSignal

    nw::gfx::MaterialArray m_Materials;
    res::ResMeshArray m_MeshBuffers;
    ut::MoveArray<res::ResMeshNodeVisibilityData> m_MeshNodeVisibilityBuffers;
    u32 m_BufferOption;
    math::MTX34 m_ModelViewMatrix;
    math::MTX34 m_NormalMatrix;
    GfxPtr<int> m_MaterialActivator;

    u8 m_LayerId;
    bool m_OriginalVisibility;
    bool m_Visible;
    bool m_SharingMaterial;

    ut::MoveArray<bool> m_MeshOriginalVisibilities;
    ut::MoveArray<bool> m_MeshNodeOriginalVisibilities;
    
    const Model::Description& m_Description;

    u32 m_UserParameter;
};


} // namespace gfx
} // namespace nw


