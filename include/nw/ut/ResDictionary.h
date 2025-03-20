#pragma once

#include "nw/ut/ResUtil.h"
#include "nw/ut/ResTypes.h"

namespace nw {
namespace ut {

struct ResDicPatriciaData : public DataBlockHeader
{
    u32 numData;
    struct ResDicNodeData
    {
        u32 ref;
        u16 idxLeft;
        u16 idxRight;
        Offset ofsString;
        Offset ofsData;
    }
    data[1];

    inline ResDicNodeData* GetBeginNode() { return &data[1]; }
    inline const ResDicNodeData* GetBeginNode() const { return &data[1]; }

};

class ResDicPatricia : public nw::ut::ResCommon<ResDicPatriciaData>
{
public:
    explicit ResDicPatricia(const void* p = 0) :
        nw::ut::ResCommon<ResDicPatriciaData>(p) {}

    ResDicPatriciaData& ref() { return *ptr(); }
    const ResDicPatriciaData& ref() const { return *ptr(); }

    bool operator==(const ResDicPatricia& rhs) const { return ptr() == rhs.ptr(); }
    bool operator!=(const ResDicPatricia& rhs) const { return ptr() != rhs.ptr(); }

    inline s32 GetCount() const { return ref().numData; }

    void* operator[](int idx) const
    {
        if (!this->IsValid()) { return nullptr; }
        return const_cast<void*>(ref().data[idx + 1].ofsData.to_ptr());
    }

    void* operator[](u32 idx) const { return operator[](int(idx)); }

    void* operator[](const char* str) const
    {
        if (this->IsValid() && str)
        {
            ResDicPatriciaData::ResDicNodeData* nodeData = Get(str, strlen(str));
            if (nodeData) { return const_cast<void*>(nodeData->ofsData.to_ptr()); }
        }
        return nullptr;
    }

    void* operator()(const char* str, size_t len) const
    {
        if (this->IsValid())
        {
            ResDicPatriciaData::ResDicNodeData* nodeData = Get(str, len);
            if (nodeData) { return const_cast<void*>(nodeData->ofsData.to_ptr()); }
        }
        return nullptr;
    }

    s32 GetIndex(const char* str) const
    {
        if (IsValid() && str)
        {
            size_t len = strlen(str);
            ResDicPatriciaData::ResDicNodeData* nodeData = Get(str, len);
            if (nodeData) { return static_cast<s32>(nodeData - &ptr()->data[1]); }
        }
        return -1;
    }

    const ResName GetResName(u32 idx) const
    {
        if (!IsValid()) { return ResName(nullptr); }
        return ofs_to_obj<ResName>(ptr()->data[idx + 1].ofsString - s32(sizeof(u32)));
    }

    const char* GetName(u32 idx) const
    {
        if (!IsValid()) { return nullptr; }
        return GetResName(idx).GetName();
    }

    u32 GetNumData() const
    {
        if ( !IsValid() ) { return 0; }
        return ptr()->numData;
    }

    u32 GetLength() const { return ref().length; }

protected:
    ResDicPatriciaData::ResDicNodeData* Get(const char* s, size_t len) const;

};

} // namespace ut
} // namespace nw


