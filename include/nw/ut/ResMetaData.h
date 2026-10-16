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

struct ResIntArrayMetaDataData : public ResMetaDataData
{
    s32 m_ValuesCount;
    s32 m_Values[1];
};

struct ResFloatArrayMetaDataData : public ResMetaDataData
{
    s32 m_ValuesCount;
    f32 m_Values[1];
};

struct ResStringArrayMetaDataData : public ResMetaDataData
{
    u32 m_Encoding;
    s32 m_ValuesCount;
    nw::ut::BinString  m_Values[1];
};

class ResMetaData : public nw::ut::ResCommon<ResMetaDataData>
{
public:
    enum DataType : s32
    {
        DATATYPE_FLOAT_ARRAY    = 0,
        DATATYPE_INT_ARRAY      = 1,
        DATATYPE_STRING_ARRAY   = 2,
        DATATYPE_UNKNOWN        = -1
    };

    explicit ResMetaData(const void* p = 0) :
        nw::ut::ResCommon<ResMetaDataData>(p) {}

    ResMetaDataData& ref() { return *ptr(); }
    const ResMetaDataData& ref() const { return *ptr(); }

    bool operator==(const ResMetaData& rhs) const { return ptr() == rhs.ptr(); }
    bool operator!=(const ResMetaData& rhs) const { return ptr() != rhs.ptr(); }

    inline const char* GetKey() const { return ref().toKey.to_ptr(); }

    inline DataType GetDataType() const { return static_cast<DataType>(ref().m_DataType); }
    inline void SetDataType(DataType value) { ref().m_DataType = value; }

    nw::ut::ResTypeInfo GetTypeInfo() const { return ref().typeInfo; }
};


class ResIntArrayMetaData : public ResMetaData
{
public:
    typedef ResIntArrayMetaData SelfType;
    typedef ResIntArrayMetaDataData ResDataType;

    explicit ResIntArrayMetaData(const void* p = nullptr) : ResMetaData(p) {}

    ResDataType* ptr() { return reinterpret_cast<ResDataType*>(void_ptr()); }
    const ResDataType* ptr() const { return reinterpret_cast<const ResDataType*>(void_ptr()); }

    ResDataType& ref() { return *reinterpret_cast<ResDataType*>(void_ptr()); }
    const ResDataType& ref() const { return *reinterpret_cast<const ResDataType*>(void_ptr()); }

    bool operator==(const ResIntArrayMetaData& rhs) const { return ptr() == rhs.ptr(); }
    bool operator!=(const ResIntArrayMetaData& rhs) const { return ptr() != rhs.ptr(); }

    nw::ut::ResTypeInfo GetTypeInfo() const { return ref().typeInfo; }

    s32 GetValuesCount() const { return ref().m_ValuesCount; }

    const s32* GetValues() const { return &(ref().m_Values[0]); }
    s32* GetValues() { return &(ref().m_Values[0]); }
    s32 GetValues(int idx) const { return ref().m_Values[idx]; }

    void SetValues(int idx, s32 value) { ref().m_Values[idx] = value; }
};


class ResFloatArrayMetaData : public ResMetaData
{
public:
    typedef ResFloatArrayMetaData SelfType;
    typedef ResFloatArrayMetaDataData ResDataType;

    explicit ResFloatArrayMetaData(const void* p = nullptr) : ResMetaData(p) {}

    ResDataType* ptr() { return reinterpret_cast<ResDataType*>(void_ptr()); }
    const ResDataType* ptr() const { return reinterpret_cast<const ResDataType*>(void_ptr()); }

    ResDataType& ref() { return *reinterpret_cast<ResDataType*>(void_ptr()); }
    const ResDataType& ref() const { return *reinterpret_cast<const ResDataType*>(void_ptr()); }

    bool operator==(const ResFloatArrayMetaData& rhs) const { return ptr() == rhs.ptr(); }
    bool operator!=(const ResFloatArrayMetaData& rhs) const { return ptr() != rhs.ptr(); }

    nw::ut::ResTypeInfo GetTypeInfo() const { return ref().typeInfo; }

    s32 GetValuesCount() const { return ref().m_ValuesCount; }

    const f32* GetValues() const { return &(ref().m_Values[0]); }
    f32* GetValues() { return &(ref().m_Values[0]); }
    f32 GetValues(int idx) const { return ref().m_Values[idx]; }

    void SetValues(int idx, f32 value) { ref().m_Values[idx] = value; }
};


class ResStringArrayMetaData : public ResMetaData
{
public:
    enum Encoding
    {
        ENCODING_ASCII   = 0,
        ENCODING_UTF8    = 1,
        ENCODING_UTF16LE = 2,
        ENCODING_UTF16BE = 3
    };

    typedef ResStringArrayMetaData SelfType;
    typedef ResStringArrayMetaDataData ResDataType;

    explicit ResStringArrayMetaData(const void* p = nullptr) : ResMetaData(p) {}

    ResDataType* ptr() { return reinterpret_cast<ResDataType*>(void_ptr()); }
    const ResDataType* ptr() const { return reinterpret_cast<const ResDataType*>(void_ptr()); }

    ResDataType& ref() { return *reinterpret_cast<ResDataType*>(void_ptr()); }
    const ResDataType& ref() const { return *reinterpret_cast<const ResDataType*>(void_ptr()); }

    bool operator==(const ResStringArrayMetaData& rhs) const { return ptr() == rhs.ptr(); }
    bool operator!=(const ResStringArrayMetaData& rhs) const { return ptr() != rhs.ptr(); }

    nw::ut::ResTypeInfo GetTypeInfo() const { return ref().typeInfo; }

    Encoding GetEncoding() const { return static_cast<Encoding>(ref().m_Encoding); }
    void SetBillboardMode(Encoding value) { ref().m_Encoding = value; }

    s32 GetValuesCount() const { return ref().m_ValuesCount; }

    const char* GetValues(int idx) const { return ref().m_Values[idx].to_ptr(); }
    const wchar_t* GetWValues(int idx) const { return reinterpret_cast<const wchar_t*>(ref().m_Values[idx].to_ptr()); }
};

} // namespace ut
} // namespace nw


