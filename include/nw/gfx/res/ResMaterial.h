#pragma once

#include "nw/gfx/res/ResSceneObject.h"
#include "nw/ut/BinaryFileFormat.h"
#include "nw/ut/ResArray.h"
#include "nw/ut/ResArrayTypes.h"
#include "nw/ut/ResDictionary.h"
#include "nw/ut/ResMetaData.h"
#include "nw/ut/ResTypes.h"
#include "nw/ut/ResUtil.h"
#include "nw/ut/Color.h"

#include "sead.h"

namespace nw {
namespace gfx {
namespace res {

struct ResMaterialColorData
{
    nw::ut::FloatColor m_Emission;
    nw::ut::FloatColor m_AmbientAndVertexColorScale;
    nw::ut::FloatColor m_Diffuse;
    nw::ut::FloatColor m_Specular0;
    nw::ut::FloatColor m_Specular1;
    nw::ut::FloatColor m_Constant0;
    nw::ut::FloatColor m_Constant1;
    nw::ut::FloatColor m_Constant2;
    nw::ut::FloatColor m_Constant3;
    nw::ut::FloatColor m_Constant4;
    nw::ut::FloatColor m_Constant5;
    u32 m_EmissionU32;
    u32 m_AmbientU32;
    u32 m_DiffuseU32;
    u32 m_Specular0U32;
    u32 m_Specular1U32;
    u32 m_Constant0U32;
    u32 m_Constant1U32;
    u32 m_Constant2U32;
    u32 m_Constant3U32;
    u32 m_Constant4U32;
    u32 m_Constant5U32;
    void* m_CommandCache;
};

struct ResRasterizationData
{
    enum Flag
    {
        FLAG_POLYGON_OFFSET_ENABLED = 0x1 << 0
    };
    
    u32 m_Flags;
    u32 m_CullingMode;
    f32 m_PolygonOffsetUnit;
    u32 m_CommandBuffer[2];
};

struct ResBlendOperationData
{
    s32 m_Mode;
    nw::ut::FloatColor m_BlendColor;
    u32 m_CommandBuffer[6];
};


struct ResDepthOperationData
{
    enum Flag
    {
        FLAG_TEST_ENABLED = 0x1 << 0,
        FLAG_MASK_ENABLED = 0x1 << 1
    };

    u32 m_Flags;
    u32 m_CommandBuffer[4];
};

struct ResStencilOperationData
{
    u32 m_CommandBuffer[4];
};

struct ResFragmentOperationData
{
    ResDepthOperationData m_DepthOperation;
    ResBlendOperationData m_BlendOperation;
    ResStencilOperationData m_StencilOperation;
};

struct ResTextureCoordinatorData
{
    s32 m_SourceCoordinate;
    s32 m_MappingMethod;
    s32 m_ReferenceCamera;
    s32 m_MatrixMode;
    nw::math::VEC2 m_Scale;
    f32 m_Rotate;
    nw::math::VEC2 m_Translate;
    bool m_IsDirty;
    bool m_IsEnabled;
    nw::math::MTX34 m_TextureMatrix;
};

struct ResMaterialData : public ResSceneObjectData
{
    enum Flag
    {
        FLAG_FRAGMENTLIGHT_ENABLED = 0x1 << 0,
        FLAG_VERTEXLIGHT_ENABLED   = 0x1 << 1,
        FLAG_HEMISPHERELIGHT_ENABLED   = 0x1 << 2,
        FLAG_HEMISPHERE_OCCLUSION_ENABLED = 0x1 << 3,
        FLAG_FOG_ENABLED = 0x1 << 4,
        FLAG_PARTICLE_MATERIAL_ENABLED = 0x1 << 5,
        FLAG_HAS_BEEN_SETUP = 0x1 << 6,
        FLAG_HAS_BEEN_SETUP_SHADER = 0x1 << 7,
        FLAG_HAS_BEEN_SETUP_TEXTURE = 0x1 << 8,
        FLAG_HAS_BEEN_SETUP_FRAGMENTSHADER = 0x1 << 9
    };
    
    u32 m_Flags;
    s32 m_TextureCoordinateConfig;
    s32 m_TranslucencyKind;
    ResMaterialColorData m_MaterialColor;
    ResRasterizationData m_Rasterization;
    ResFragmentOperationData m_FragmentOperation;
    s32 m_ActiveTextureCoordinatorsCount;
    ResTextureCoordinatorData m_TextureCoordinators[3];
    nw::ut::Offset toTextureMappers[3];
    nw::ut::Offset toProceduralTextureMapper;
    nw::ut::Offset toShader;
    nw::ut::Offset toFragmentShader;
    s32 m_ShaderProgramDescriptionIndex;
    s32 m_ShaderParametersTableCount;
    nw::ut::Offset toShaderParametersTable;
    s32 m_LightSetIndex;
    s32 m_FogIndex;
    u32 m_ShadingParameterHash;
    u32 m_ShaderParametersHash;
    u32 m_TextureCoordinatorsHash;
    u32 m_TextureSamplersHash;
    u32 m_TextureMappersHash;
    u32 m_MaterialColorHash;
    u32 m_RasterizationHash;
    u32 m_FragmentLightingHash;
    u32 m_FragmentLightingTableHash;
    u32 m_FragmentLightingTableParametersHash;
    u32 m_TextureCombinersHash;
    u32 m_AlphaTestHash;
    u32 m_FragmentOperationHash;
    u32 m_MaterialId;
};

class ResMaterialColor : public nw::ut::ResCommon<ResMaterialColorData>
{
public:
    typedef ResMaterialColor SelfType;
    typedef ResMaterialColorData ResDataType;

    explicit ResMaterialColor(const void* p = 0) :
        nw::ut::ResCommon<ResMaterialColorData>(p) {}

    ResMaterialColorData& ref() { return *ptr(); }
    const ResMaterialColorData& ref() const { return *ptr(); }

    bool operator==(const ResMaterialColor& rhs) const { return ptr() == rhs.ptr(); }
    bool operator!=(const ResMaterialColor& rhs) const { return ptr() != rhs.ptr(); }

    f32 GetVertexColorScale() const { return ref().m_AmbientAndVertexColorScale.a; }
    void SetVertexColorScale(f32 scale) { ref().m_AmbientAndVertexColorScale.a = scale; }

    u32 GetAmbientU32() const { return ref().m_AmbientU32; }

    void SetAmbient(f32 r, f32 g, f32 b)
    {
        ref().m_AmbientAndVertexColorScale.SetColor(r, g, b);
        ref().m_AmbientU32 = ref().m_AmbientAndVertexColorScale.ToPicaU32();
    }

    void SetAmbient(const nw::ut::FloatColor& value) { this->SetAmbient(value.r, value.g, value.b); }

    const nw::ut::FloatColor& GetAmbient() const { return ref().m_AmbientAndVertexColorScale; }

    u32 GetEmissionU32() const { return ref().m_EmissionU32; }

    void SetEmission(f32 r, f32 g, f32 b) {
        ref().m_Emission.Set(r, g, b);
        ref().m_EmissionU32 = ref().m_Emission.ToPicaU32();
    }

    void SetEmission(f32 r, f32 g, f32 b, f32 a) {
        ref().m_Emission.Set(r, g, b, a);
        ref().m_EmissionU32 = ref().m_Emission.ToPicaU32();
    }

    const nw::ut::FloatColor& GetEmission() const { return ref().m_Emission; }

    void SetEmission(const nw::ut::FloatColor& value) {
        ref().m_Emission = value;
        ref().m_EmissionU32 = ref().m_Emission.ToPicaU32();
    }

    u32 GetDiffuseU32() const { return ref().m_DiffuseU32; }

    void SetDiffuse(f32 r, f32 g, f32 b)
    {
        ref().m_Diffuse.Set(r, g, b);
        ref().m_DiffuseU32 = ref().m_Diffuse.ToPicaU32();
    }

    void SetDiffuse(f32 r, f32 g, f32 b, f32 a)
    {
        ref().m_Diffuse.Set(r, g, b, a);
        ref().m_DiffuseU32 = ref().m_Diffuse.ToPicaU32();
    }
    const nw::ut::FloatColor& GetDiffuse() const { return ref().m_Diffuse; }

    void SetDiffuse(const nw::ut::FloatColor& value)
    {
        ref().m_Diffuse = value;
        ref().m_DiffuseU32 = ref().m_Diffuse.ToPicaU32();
    }

    u32 GetSpecular0U32() const { return ref().m_Specular0U32; }
    void SetSpecular0(f32 r, f32 g, f32 b)
    {
        ref().m_Specular0.Set(r, g, b);
        ref().m_Specular0U32 = ref().m_Specular0.ToPicaU32();
    }

    void SetSpecular0(f32 r, f32 g, f32 b, f32 a)
    {
        ref().m_Specular0.Set(r, g, b, a);
        ref().m_Specular0U32 = ref().m_Specular0.ToPicaU32();
    }

    const nw::ut::FloatColor& GetSpecular0() const { return ref().m_Specular0; }

    void SetSpecular0(const nw::ut::FloatColor& value)
    {
        ref().m_Specular0 = value;
        ref().m_Specular0U32 = ref().m_Specular0.ToPicaU32();
    }

    u32 GetSpecular1U32() const { return ref().m_Specular1U32; }

    void SetSpecular1(f32 r, f32 g, f32 b)
    {
        ref().m_Specular1.Set(r, g, b);
        ref().m_Specular1U32 = ref().m_Specular1.ToPicaU32();
    }

    void SetSpecular1(f32 r, f32 g, f32 b, f32 a)
    {
        ref().m_Specular1.Set(r, g, b, a);
        ref().m_Specular1U32 = ref().m_Specular1.ToPicaU32();
    }

    const nw::ut::FloatColor& GetSpecular1() const { return ref().m_Specular1; }

    void SetSpecular1(const nw::ut::FloatColor& value)
    {
        ref().m_Specular1 = value;
        ref().m_Specular1U32 = ref().m_Specular1.ToPicaU32();
    }

    u32 GetConstant0U32() const { return ref().m_Constant0U32; }

    void SetConstant0(f32 r, f32 g, f32 b)
    {
        ref().m_Constant0.Set(r, g, b);
        ref().m_Constant0U32 = ref().m_Constant0.ToPicaU32();
    }

    void SetConstant0(f32 r, f32 g, f32 b, f32 a)
    {
        ref().m_Constant0.Set(r, g, b, a);
        ref().m_Constant0U32 = ref().m_Constant0.ToPicaU32();
    }

    const nw::ut::FloatColor& GetConstant0() const { return ref().m_Constant0; }

    void SetConstant0(const nw::ut::FloatColor& value)
    {
        ref().m_Constant0 = value;
        ref().m_Constant0U32 = ref().m_Constant0.ToPicaU32();
    }

    u32 GetConstant1U32() const { return ref().m_Constant1U32; }
    void SetConstant1(f32 r, f32 g, f32 b) {
        ref().m_Constant1.Set(r, g, b);
        ref().m_Constant1U32 = ref().m_Constant1.ToPicaU32();
    }

    void SetConstant1(f32 r, f32 g, f32 b, f32 a)
    {
        ref().m_Constant1.Set(r, g, b, a);
        ref().m_Constant1U32 = ref().m_Constant1.ToPicaU32();
    }

    const nw::ut::FloatColor& GetConstant1() const { return ref().m_Constant1; }

    void SetConstant1(const nw::ut::FloatColor& value)
    {
        ref().m_Constant1 = value;
        ref().m_Constant1U32 = ref().m_Constant1.ToPicaU32();
    }

    u32 GetConstant2U32() const { return ref().m_Constant2U32; }
    void SetConstant2(f32 r, f32 g, f32 b)
    {
        ref().m_Constant2.Set(r, g, b);
        ref().m_Constant2U32 = ref().m_Constant2.ToPicaU32();
    }

    void SetConstant2(f32 r, f32 g, f32 b, f32 a)
    {
        ref().m_Constant2.Set(r, g, b, a);
        ref().m_Constant2U32 = ref().m_Constant2.ToPicaU32();
    }

    const nw::ut::FloatColor& GetConstant2() const { return ref().m_Constant2; }
    void SetConstant2(const nw::ut::FloatColor& value)
    {
        ref().m_Constant2 = value;
        ref().m_Constant2U32 = ref().m_Constant2.ToPicaU32();
    }

    u32 GetConstant3U32() const { return ref().m_Constant3U32; }
    void SetConstant3(f32 r, f32 g, f32 b)
    {
        ref().m_Constant3.Set(r, g, b);
        ref().m_Constant3U32 = ref().m_Constant3.ToPicaU32();
    }
    void SetConstant3(f32 r, f32 g, f32 b, f32 a)
    {
        ref().m_Constant3.Set(r, g, b, a);
        ref().m_Constant3U32 = ref().m_Constant3.ToPicaU32();
    }

    const nw::ut::FloatColor& GetConstant3() const { return ref().m_Constant3; }
    void SetConstant3(const nw::ut::FloatColor& value)
    {
        ref().m_Constant3 = value;
        ref().m_Constant3U32 = ref().m_Constant3.ToPicaU32();
    }

    u32 GetConstant4U32() const { return ref().m_Constant4U32; }
    void SetConstant4(f32 r, f32 g, f32 b)
    {
        ref().m_Constant4.Set(r, g, b);
        ref().m_Constant4U32 = ref().m_Constant4.ToPicaU32();
    }

    void SetConstant4(f32 r, f32 g, f32 b, f32 a)
    {
        ref().m_Constant4.Set(r, g, b, a);
        ref().m_Constant4U32 = ref().m_Constant4.ToPicaU32();
    }

    const nw::ut::FloatColor& GetConstant4() const { return ref().m_Constant4; }
    void SetConstant4(const nw::ut::FloatColor& value)
    {
        ref().m_Constant4 = value;
        ref().m_Constant4U32 = ref().m_Constant4.ToPicaU32();
    }

    u32 GetConstant5U32() const { return ref().m_Constant5U32; }
    void SetConstant5(f32 r, f32 g, f32 b)
    {
        ref().m_Constant5.Set(r, g, b);
        ref().m_Constant5U32 = ref().m_Constant5.ToPicaU32();
    }

    void SetConstant5(f32 r, f32 g, f32 b, f32 a)
    {
        ref().m_Constant5.Set(r, g, b, a);
        ref().m_Constant5U32 = ref().m_Constant5.ToPicaU32();
    }

    const nw::ut::FloatColor& GetConstant5() const { return ref().m_Constant5; }
    void SetConstant5(const nw::ut::FloatColor& value)
    {
        ref().m_Constant5 = value;
        ref().m_Constant5U32 = ref().m_Constant5.ToPicaU32();
    }
};

class ResMaterial : public ResSceneObject
{
public:
    typedef ResMaterial SelfType;
    typedef ResMaterialData ResDataType;
    explicit ResMaterial(const void* p = 0) : ResSceneObject(p) {}
    
    ResDataType* ptr() { return reinterpret_cast<ResDataType*>(void_ptr()); }
    const ResDataType* ptr() const { return reinterpret_cast<const ResDataType*>(void_ptr()); }

    ResDataType& ref() { return *reinterpret_cast<ResDataType*>(void_ptr()); }
    const ResDataType& ref() const { return *reinterpret_cast<const ResDataType*>(void_ptr()); }

    bool operator==(const ResMaterial& rhs) const { return ptr() == rhs.ptr(); }
    bool operator!=(const ResMaterial& rhs) const { return ptr() != rhs.ptr(); }

    ResMaterialColor GetMaterialColor() { return ResMaterialColor(&(ref().m_MaterialColor)); }
    const ResMaterialColor GetMaterialColor() const { return ResMaterialColor(&(ref().m_MaterialColor)); }

    ResMaterialColorData& GetMaterialColorData() { return ref().m_MaterialColor; }
    const ResMaterialColorData& GetMaterialColorData() const { return ref().m_MaterialColor; }

    s32 GetTextureMappersCount() const { return sizeof(ref().toTextureMappers) / sizeof(nw::ut::Offset); }

    s32 GetLightSetIndex() const { return static_cast<s32>(ref().m_LightSetIndex); }
    void SetLightSetIndex(s32 value) { ref().m_LightSetIndex = value; }

    s32 GetFogIndex() const { return static_cast<s32>(ref().m_FogIndex); }
    void SetFogIndex(s32 value) { ref().m_FogIndex = value; }

    u32 GetShadingParameterHash() const { return static_cast<u32>(ref().m_ShadingParameterHash); }
    void SetShadingParameterHash(u32 value) { ref().m_ShadingParameterHash = value; }

    u32 GetShaderParametersHash() const { return static_cast<u32>(ref().m_ShaderParametersHash); }
    void SetShaderParametersHash(u32 value) { ref().m_ShaderParametersHash = value; }

    u32 GetTextureCoordinatorsHash() const { return static_cast<u32>(ref().m_TextureCoordinatorsHash); }
    void SetTextureCoordinatorsHash(u32 value) { ref().m_TextureCoordinatorsHash = value; }

    u32 GetTextureSamplersHash() const { return static_cast<u32>(ref().m_TextureSamplersHash); }
    void SetTextureSamplersHash(u32 value) { ref().m_TextureSamplersHash = value; }

    u32 GetTextureMappersHash() const { return static_cast<u32>(ref().m_TextureMappersHash); }
    void SetTextureMappersHash(u32 value) { ref().m_TextureMappersHash = value; }

    u32 GetMaterialColorHash() const { return static_cast<u32>(ref().m_MaterialColorHash); }
    void SetMaterialColorHash(u32 value) { ref().m_MaterialColorHash = value; }

    u32 GetRasterizationHash() const { return static_cast<u32>(ref().m_RasterizationHash); }
    void SetRasterizationHash(u32 value) { ref().m_RasterizationHash = value; }

    u32 GetFragmentLightingHash() const { return static_cast<u32>(ref().m_FragmentLightingHash); }
    void SetFragmentLightingHash(u32 value) { ref().m_FragmentLightingHash = value; }

    u32 GetFragmentLightingTableHash() const { return static_cast<u32>(ref().m_FragmentLightingTableHash); }
    void SetFragmentLightingTableHash(u32 value) { ref().m_FragmentLightingTableHash = value; }

    u32 GetFragmentLightingTableParametersHash() const { return static_cast<u32>(ref().m_FragmentLightingTableParametersHash); }
    void SetFragmentLightingTableParametersHash(u32 value) { ref().m_FragmentLightingTableParametersHash = value; }

    u32 GetAlphaTestHash() const { return static_cast<u32>(ref().m_AlphaTestHash); }
    void SetAlphaTestHash(u32 value) { ref().m_AlphaTestHash = value; }

    u32 GetTextureCombinersHash() const { return static_cast<u32>(ref().m_TextureCombinersHash); }
    void SetTextureCombinersHash(u32 value) { ref().m_TextureCombinersHash = value; }

    u32 GetFragmentOperationHash() const { return static_cast<u32>(ref().m_FragmentOperationHash); }
    void SetFragmentOperationHash(u32 value) { ref().m_FragmentOperationHash = value; }
};
typedef nw::ut::ResArrayPatricia<ResMaterial>::type ResMaterialArray;
typedef nw::ut::ResArrayPatricia<const ResMaterial>::type ResMaterialArrayConst;

} // namespace res
} // namespace gfx
} // namespace nw
