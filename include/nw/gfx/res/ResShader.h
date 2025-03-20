#pragma once

#include "nw/gfx/GfxObject.h"
#include "nw/ut/ResUtil.h"
#include "nw/ut/BinaryFileFormat.h"
#include "nw/ut/ResTypes.h"
#include "nw/ut/ResMetaData.h"
#include "nw/ut/ResDictionary.h"
#include "nw/ut/ResArray.h"
#include "nw/ut/ResArrayTypes.h"


namespace nw {
namespace gfx {
namespace res {


struct ResShaderProgramDescriptionData
{
    u32 m_Flags;
    u32 m_VertexShaderObject;
    u32 m_GeometryShaderObject;
    s32 m_VertexShaderIndex;
    s32 m_GeometryShaderIndex;
    s32 m_SymbolsTableCount;
    nw::ut::Offset toSymbolsTable;
    nw::ut::BinString toAttributeSymbols[12];
    s8 m_AttributeIndices[22];
    s32 m_MaxBoneCount;
    s32 m_MaxVertexLightCount;
    s32 m_VertexLightEndUniform;
    s32 m_GeometryShaderMode;
    u32 m_ProgramObject;
    void* m_UniformLocation;
    void* m_CommandCache;
    u32   m_CommandCacheSize;
    nw::ut::Offset toOwnerShader;
};

class ResShaderProgramDescription : public nw::ut::ResCommon< ResShaderProgramDescriptionData >
{
public:
    explicit ResShaderProgramDescription(const void* p = 0) : nw::ut::ResCommon<ResShaderProgramDescriptionData>(p) {}
    ResShaderProgramDescriptionData& ref() { return *ptr();}
    const ResShaderProgramDescriptionData& ref() const { return *ptr(); }

    bool operator==(const ResShaderProgramDescription& rhs) const { return ptr() == rhs.ptr(); }
    bool operator!=(const ResShaderProgramDescription& rhs) const { return ptr() != rhs.ptr(); }
};

} // namespace res
} // namespace gfx
} // namespace nw


