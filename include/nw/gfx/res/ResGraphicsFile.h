#pragma once

#include "nw/anim/res/ResAnim.h"

#include "nw/gfx/res/ResModel.h"
#include "nw/gfx/res/ResTexture.h"

#include "nw/ut/BinaryFileFormat.h"
#include "nw/ut/ResTypes.h"
#include "nw/ut/ResUtil.h"
#include "nw/ut/ResDictionary.h"

namespace nw {
namespace gfx {
namespace res {

struct ResFileHeaderData
{
    u32 m_Signature;
    u16 m_ByteOrder;
    u16 m_HeaderSize;
    u32 m_Revision;
    u32 m_FileSize;
    u16 m_NumBlocks;
    u8 padding_[2];
    nw::ut::BinaryBlockHeader m_BlockHeader;
};

struct ResGraphicsFileData : public ResFileHeaderData
{
    s32 m_ModelsDicCount;
    nw::ut::Offset toModelsDic;
    s32 m_TexturesDicCount;
    nw::ut::Offset toTexturesDic;
    s32 m_LutSetsDicCount;
    nw::ut::Offset toLutSetsDic;
    s32 m_MaterialsDicCount;
    nw::ut::Offset toMaterialsDic;
    s32 m_ShadersDicCount;
    nw::ut::Offset toShadersDic;
    s32 m_CamerasDicCount;
    nw::ut::Offset toCamerasDic;
    s32 m_LightsDicCount;
    nw::ut::Offset toLightsDic;
    s32 m_FogsDicCount;
    nw::ut::Offset toFogsDic;
    s32 m_SceneEnvironmentSettingsDicCount;
    nw::ut::Offset toSceneEnvironmentSettingsDic;
    s32 m_SkeletalAnimsDicCount;
    nw::ut::Offset toSkeletalAnimsDic;
    s32 m_MaterialAnimsDicCount;
    nw::ut::Offset toMaterialAnimsDic;
    s32 m_VisibilityAnimsDicCount;
    nw::ut::Offset toVisibilityAnimsDic;
    s32 m_CameraAnimsDicCount;
    nw::ut::Offset toCameraAnimsDic;
    s32 m_LightAnimsDicCount;
    nw::ut::Offset toLightAnimsDic;
    s32 m_FogAnimsDicCount;
    nw::ut::Offset toFogAnimsDic;
    s32 m_EmittersDicCount;
    nw::ut::Offset toEmittersDic;
};

class ResFileHeader : public nw::ut::ResCommon< ResFileHeaderData >
{
public:
    typedef ResFileHeader SelfType;
    typedef ResFileHeaderData ResDataType;
    
    explicit ResFileHeader(const void *p = 0) : 
        nw::ut::ResCommon<ResFileHeaderData>(p) {}

    ResFileHeaderData& ref() { return *ptr(); }
    const ResFileHeaderData& ref() const { return *ptr(); }

    u32 GetSignature() const { return static_cast<u32>(ref().m_Signature); }
    u16 GetByteOrder() const { return static_cast<u16>(ref().m_ByteOrder); }
    u16 GetHeaderSize() const { return static_cast<u16>(ref().m_HeaderSize); }
    u32 GetRevision() const { return static_cast<u32>(ref().m_Revision); }
    u32 GetFileSize() const { return static_cast<u32>(ref().m_FileSize); }
    u16 GetNumBlocks() const { return static_cast<u16>(ref().m_NumBlocks); } 

    const nw::ut::BinaryFileHeader& GetFileHeader() const { return *reinterpret_cast<const nw::ut::BinaryFileHeader*>(this->ptr()); }
    const nw::ut::BinaryBlockHeader& GetFirstBlockHeader() const { return ref().m_BlockHeader; }
};

class ResGraphicsFile : public ResFileHeader
{
public:
    explicit ResGraphicsFile(const void* p = 0) :
        ResFileHeader(p) {}

    ResGraphicsFileData* ptr() { return reinterpret_cast<ResGraphicsFileData*>(void_ptr()); }
    const ResGraphicsFileData* ptr() const { return reinterpret_cast<const ResGraphicsFileData*>(void_ptr()); }

    ResGraphicsFileData& ref() { return *reinterpret_cast<ResGraphicsFileData*>(void_ptr()); }
    const ResGraphicsFileData& ref() const { return *reinterpret_cast<const ResGraphicsFileData*>(void_ptr()); }

    s32 GetModelsCount() const { return ref().m_ModelsDicCount; }

    ResModel GetModels(int idx)
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toModelsDic.to_ptr());
        return ResModel(dic[idx]);
    }

    ResModel GetModels(const char* key)
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toModelsDic.to_ptr());
        return ResModel(dic[key]);
    }

    s32 GetTexturesCount() const { return ref().m_TexturesDicCount; }

    nw::gfx::res::ResTexture GetTextures(int idx)
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toTexturesDic.to_ptr());
        return nw::gfx::res::ResTexture(dic[idx]);
    }

    nw::gfx::res::ResTexture GetTextures(const char* key)
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toTexturesDic.to_ptr());
        return nw::gfx::res::ResTexture(dic[key]);
    }

    s32 GetLutSetsCount() const { return ref().m_LutSetsDicCount; }
    // TODO: GetLutSets()

    s32 GetShadersCount() const { return ref().m_ShadersDicCount; }
    // TODO: GetShaders()

    s32 GetCamerasCount() const { return ref().m_CamerasDicCount; }
    // TODO: GetCameras()

    s32 GetLightsCount() const { return ref().m_LightsDicCount; }
    // TODO: GetLights()

    s32 GetFogsCount() const { return ref().m_FogsDicCount; }
    // TODO: GetFogs()

    s32 GetSceneEnvironmentSettingsCount() const { return ref().m_SceneEnvironmentSettingsDicCount; }
    // TODO: GetSceneEnvironmentSettings()

    s32 GetSkeletalAnimsCount() const { return ref().m_SkeletalAnimsDicCount; }

    nw::anim::res::ResAnim GetSkeletalAnims(int idx)
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toSkeletalAnimsDic.to_ptr());
        return nw::anim::res::ResAnim(dic[idx]);
    }

    nw::anim::res::ResAnim GetSkeletalAnims(const char* key)
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toSkeletalAnimsDic.to_ptr());
        return nw::anim::res::ResAnim(dic[key]);
    }

    s32 GetMaterialAnimsCount() const { return ref().m_MaterialAnimsDicCount; }

    nw::anim::res::ResAnim GetMaterialAnims(int idx)
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toMaterialAnimsDic.to_ptr());
        return nw::anim::res::ResAnim(dic[idx]);
    }

    nw::anim::res::ResAnim GetMaterialAnims(const char* key)
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toMaterialAnimsDic.to_ptr());
        return nw::anim::res::ResAnim(dic[key]);
    }

    s32 GetVisibilityAnimsCount() const { return ref().m_VisibilityAnimsDicCount; }

    nw::anim::res::ResAnim GetVisibilityAnims(int idx)
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toVisibilityAnimsDic.to_ptr());
        return nw::anim::res::ResAnim(dic[idx]);
    }

    nw::anim::res::ResAnim GetVisibilityAnims(const char* key)
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toVisibilityAnimsDic.to_ptr());
        return nw::anim::res::ResAnim(dic[key]);
    }

    s32 GetCameraAnimsCount() const { return ref().m_CameraAnimsDicCount; }
    // TODO: GetCameraAnims()

    s32 GetLightAnimsCount() const { return ref().m_LightAnimsDicCount; }
    // TODO: GetLightAnims()

    s32 GetFogAnimsCount() const { return ref().m_FogAnimsDicCount; }
    // TODO: GetFogAnims()

    s32 GetEmittersCount() const { return ref().m_EmittersDicCount; }
    // TODO: GetEmitters()

};

} // namespace res
} // namespace gfx
} // namespace nw
