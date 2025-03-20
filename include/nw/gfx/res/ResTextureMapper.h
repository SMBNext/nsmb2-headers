#pragma once

#include "nw/gfx/res/ResSceneObject.h"
#include "nw/ut/ResUtil.h"
#include "nw/ut/BinaryFileFormat.h"
#include "nw/ut/ResTypes.h"
#include "nw/ut/ResMetaData.h"
#include "nw/ut/ResDictionary.h"
#include "nw/ut/ResArray.h"
#include "nw/ut/ResArrayTypes.h"
#include "nw/anim/res/ResAnimGroup.h"
#include "nw/gfx/res/ResMaterial.h"
#include "nw/gfx/res/ResTexture.h"

namespace nw {
namespace gfx {
namespace res {

struct ResTextureMapperData
{
    nw::ut::ResTypeInfo typeInfo;
    nw::os::IAllocator* m_DynamicAllocator;
    nw::ut::Offset toTexture;
};

struct ResPixelBasedTextureMapperData : public ResTextureMapperData
{
    nw::ut::Offset toSampler;
    u32 m_CommandCache[14];
    u32 m_CommandSizeToSend;
};

class ResTextureMapper : public nw::ut::ResCommon< ResTextureMapperData >
{
public:
    typedef ResTextureMapper SelfType;
    typedef ResTextureMapperData ResDataType;

    explicit ResTextureMapper(const void* p = 0) : nw::ut::ResCommon<ResTextureMapperData>(p) {}

    void SetTexture(ResTexture resTexture);

    ResTextureMapperData& ref() { return *ptr();}
    const ResTextureMapperData& ref() const { return *ptr(); }

    bool operator==(const ResTextureMapper& rhs) const { return ptr() == rhs.ptr(); }
    bool operator!=(const ResTextureMapper& rhs) const { return ptr() != rhs.ptr(); }
};

class ResPixelBasedTextureMapper : public ResTextureMapper
{
public:
    typedef ResPixelBasedTextureMapper SelfType;
    typedef ResPixelBasedTextureMapperData ResDataType;

    explicit ResPixelBasedTextureMapper(const void* p = 0) : ResTextureMapper(p) {}

    ResDataType* ptr() { return reinterpret_cast<ResDataType*>(void_ptr()); }
    const ResDataType* ptr() const { return reinterpret_cast<const ResDataType*>(void_ptr()); }

    ResDataType& ref() { return *reinterpret_cast<ResDataType*>(void_ptr()); }
    const ResDataType& ref() const { return *reinterpret_cast<const ResDataType*>(void_ptr()); }

    bool operator==(const ResPixelBasedTextureMapper& rhs) const { return ptr() == rhs.ptr(); }
    bool operator!=(const ResPixelBasedTextureMapper& rhs) const { return ptr() != rhs.ptr(); }
};

} // namespace res
} // namespace gfx
} // namespace nw


