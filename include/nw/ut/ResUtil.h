#pragma once

#include "clib/string.h"

#include "nw/ut/ResTypes.h"
#include "nw/gfx/GfxObject.h"

namespace nw { namespace ut {

template<class TDown, class TBase>
inline TDown ResDynamicCast( TBase res )
{
    if (!res.IsValid()) return TDown(nullptr);

    if ((res.GetTypeInfo() & TDown::TYPE_INFO) == TDown::TYPE_INFO)
        return TDown(res.ptr());

    return TDown(nullptr);
}

template<class TDest, class TSrc>
inline TDest ResStaticCast( TSrc res )
{
    // TODO: assert dynamic cast is valid
    return TDest(res.ptr());
}

struct DataBlockHeader
{
    u32 signature;
    u32 length;
};

class ResCommonBase
{

public:
    explicit ResCommonBase(void* p) :
        mpData(p) {};

    explicit ResCommonBase(const void* p) :
        mpData(const_cast<void*>(p)) {};

    inline bool IsValid() const { return (mpData != nullptr); }

protected:
    inline void* void_ptr() { return mpData; }
    inline const void* void_ptr() const { return mpData; }

    template<class T>
    inline const T* ofs_to_ptr(Offset ofs) const
    {
        const u8* p = reinterpret_cast<const u8*>(mpData);
        if (ofs != 0)
            return reinterpret_cast<const T*>(p + ofs);
        else
            return nullptr;
    }

    template<class T>
    inline const T ofs_to_obj(Offset ofs) const
    {
        const u8* p = reinterpret_cast<const u8*>(mpData);
        if (ofs != 0)
            return T(const_cast<u8*>(p + ofs));
        else
            return T(nullptr);
    }

    template<class T>
    T* ofs_to_ptr_raw(Offset ofs) { return reinterpret_cast<T*>(reinterpret_cast<u8*>(mpData) + ofs); }

    template<class T>
    const T* ofs_to_ptr_raw(Offset ofs) const { return reinterpret_cast<const T*>(reinterpret_cast<const u8*>(mpData) + ofs); }

    inline void invalidate() { mpData = nullptr; }

private:
    void* mpData;
};

template<class T>
class ResCommon : public ResCommonBase
{

public:
    explicit ResCommon(void* p) : ResCommonBase(p) {};
    explicit ResCommon(const void* p) : ResCommonBase(p) {};

    inline T* ptr() { return reinterpret_cast<T*>(void_ptr()); }
    inline const T* ptr() const { return reinterpret_cast<const T*>(void_ptr()); }

    inline T& ref() { return *reinterpret_cast<T*>(void_ptr()); }
    inline const T& ref() const { return *reinterpret_cast<const T*>(void_ptr()); }

};

struct ResNameData
{
    s32 len;
    char str[4];
};

class ResName : public ResCommon<ResNameData>
{
public:
    explicit ResName(const void* p = 0) :
        nw::ut::ResCommon<ResNameData>(p) {}

    ResNameData& ref() { return *ptr(); }
    const ResNameData& ref() const { return *ptr(); }

    bool operator==(const ResName& rhs) const { return ptr() == rhs.ptr(); }
    bool operator!=(const ResName& rhs) const { return ptr() != rhs.ptr(); }

    inline s32 GetLength() const { return ref().len; }

    inline const char* GetName() const { return &ref().str[0]; }

    inline bool Equals(const char* str, s32 len) const { return (GetLength() == len) && (strcmp(GetName(), str) == 0); }

};

} // namespace ut
} // namespace nw


