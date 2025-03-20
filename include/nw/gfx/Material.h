#pragma once

#include "nw/gfx/res/ResMaterial.h"
#include "nw/gfx/res/ResShader.h"
#include "nw/gfx/SceneObject.h"

namespace nw { namespace gfx {

class Model;

class Material : public SceneObject
{

public:
    res::ResMaterial& GetShaderParameterResMaterial() { return m_ShaderParameterResMaterial; }
    const res::ResMaterial& GetShaderParameterResMaterial() const { return m_ShaderParameterResMaterial; }

    res::ResMaterial& GetShadingParameterResMaterial() { return m_ShadingParameterResMaterial; }
    const res::ResMaterial& GetShadingParameterResMaterial() const { return m_ShadingParameterResMaterial; }

    res::ResMaterial& GetMaterialColorResMaterial() { return m_MaterialColorResMaterial; }
    const res::ResMaterial& GetMaterialColorResMaterial() const { return m_MaterialColorResMaterial; }

    res::ResMaterial& GetRasterizationResMaterial() { return m_RasterizationResMaterial; }
    const res::ResMaterial& GetRasterizationResMaterial() const { return m_RasterizationResMaterial; }
    
    res::ResMaterial& GetTextureCoordinatorResMaterial() { return m_TextureCoordinatorResMaterial; }
    const res::ResMaterial& GetTextureCoordinatorResMaterial() const { return m_TextureCoordinatorResMaterial; }
    
    res::ResMaterial& GetTextureMapperResMaterial() { return m_TextureMapperResMaterial; }
    const res::ResMaterial& GetTextureMapperResMaterial() const { return m_TextureMapperResMaterial; }

    res::ResMaterial& GetFragmentLightingResMaterial() { return m_FragmentLightingResMaterial; }
    const res::ResMaterial& GetFragmentLightingResMaterial() const { return m_FragmentLightingResMaterial; }

    res::ResMaterial& GetFragmentLightingTableResMaterial() { return m_FragmentLightingTableResMaterial; }
    const res::ResMaterial& GetFragmentLightingTableResMaterial() const { return m_FragmentLightingTableResMaterial; }

    res::ResMaterial& GetTextureCombinerResMaterial() { return m_TextureCombinerResMaterial; }
    const res::ResMaterial& GetTextureCombinerResMaterial() const { return m_TextureCombinerResMaterial; }

    res::ResMaterial& GetAlphaTestResMaterial() { return m_AlphaTestResMaterial; }
    const res::ResMaterial& GetAlphaTestResMaterial() const { return m_AlphaTestResMaterial; }
    
    res::ResMaterial& GetFragmentOperationResMaterial() { return m_FragmentOperationResMaterial; }
    const res::ResMaterial& GetFragmentOperationResMaterial() const { return m_FragmentOperationResMaterial; }

    res::ResMaterial& GetSceneEnvironmentResMaterial() { return m_SceneEnvironmentResMaterial; }
    const res::ResMaterial& GetSceneEnvironmentResMaterial() const { return m_SceneEnvironmentResMaterial; }


protected:
    Material(os::IAllocator* allocator, res::ResMaterial resMaterial, s32 bufferCount, Model* parent);

    virtual ~Material();
private:

    typedef ut::MoveArray<res::ResMaterial> ResMaterialArray;

    ResMaterialArray m_Buffers;
    Model* m_Owner;
    res::ResShaderProgramDescription m_ProgramDescription;
    s32 m_BufferCount;

    res::ResMaterial m_ShaderParameterResMaterial;
    res::ResMaterial m_ShadingParameterResMaterial;
    res::ResMaterial m_MaterialColorResMaterial;
    res::ResMaterial m_RasterizationResMaterial;
    res::ResMaterial m_TextureCoordinatorResMaterial;
    res::ResMaterial m_TextureMapperResMaterial;
    res::ResMaterial m_FragmentLightingResMaterial;
    res::ResMaterial m_FragmentLightingTableResMaterial;
    res::ResMaterial m_TextureCombinerResMaterial;
    res::ResMaterial m_AlphaTestResMaterial;
    res::ResMaterial m_FragmentOperationResMaterial;
    res::ResMaterial m_SceneEnvironmentResMaterial;

    friend class Model;
};

typedef ut::MoveArray<Material*> MaterialArray;

} // namespace gfx
} // namespace nw


