#pragma once

#include "nw/gfx/GfxObject.h"
#include "nw/ut/ResUtil.h"
#include "nw/ut/BinaryFileFormat.h"
#include "nw/ut/ResTypes.h"

namespace nw { namespace ut {

struct ResMetaDataData
{
    nw::ut::ResTypeInfo typeInfo;
    nw::ut::BinString toKey;
    s32 m_DataType;
};

class ResMetaData : public nw::ut::ResCommon<ResMetaDataData>
{

public:
    explicit ResMetaData(const void* p = 0) :
        nw::ut::ResCommon<ResMetaDataData>(p) {}

    ResMetaDataData& ref() { return *ptr(); }
    const ResMetaDataData& ref() const { return *ptr(); }

    bool operator==(const ResMetaData& rhs) const { return ptr() == rhs.ptr(); }
    bool operator!=(const ResMetaData& rhs) const { return ptr() != rhs.ptr(); }

    inline const char* GetKey() const { return ref().toKey.to_ptr(); }

    inline s32 GetDataType() const { return static_cast<s32>(ref().m_DataType); }
    inline void SetDataType(s32 value) { ref().m_DataType = value; }

    nw::ut::ResTypeInfo GetTypeInfo() const { return ref().typeInfo; }
};

} // namespace ut
} // namespace nw


