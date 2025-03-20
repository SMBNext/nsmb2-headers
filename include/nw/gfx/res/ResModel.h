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

namespace nw {
namespace gfx {
namespace res {

struct ResModelData : public ResTransformNodeData
{
    s32 m_MeshesTableCount;
    nw::ut::Offset toMeshesTable;
    s32 m_MaterialsDicCount;
    nw::ut::Offset toMaterialsDic;
    s32 m_ShapesTableCount;
    nw::ut::Offset toShapesTable;
    s32 m_MeshNodeVisibilitiesDicCount;
    nw::ut::Offset toMeshNodeVisibilitiesDic;
    bool m_IsVisible;
    bool m_IsNonuniformScalable;
    u8 _padding_0[6];
    u32 m_LayerId;
};


class ResModel : public ResTransformNode
{
public:
    typedef ResModel SelfType;
    typedef ResModelData ResDataType;

    explicit ResModel(const void* p = 0) : ResTransformNode(p) {}

    ResDataType* ptr() { return reinterpret_cast<ResDataType*>(void_ptr()); }
    const ResDataType* ptr() const { return reinterpret_cast<const ResDataType*>(void_ptr()); }

    ResDataType& ref() { return *reinterpret_cast<ResDataType*>(void_ptr()); }
    const ResDataType& ref() const { return *reinterpret_cast<const ResDataType*>(void_ptr()); }

    bool operator==(const ResModel& rhs) const { return ptr() == rhs.ptr(); }
    bool operator!=(const ResModel& rhs) const { return ptr() != rhs.ptr(); }

    s32 GetMaterialsCount() const { return ref().m_MaterialsDicCount; }
    ResMaterial GetMaterials(int idx)
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toMaterialsDic.to_ptr());
        return ResMaterial(dic[idx]);
    }

    ResMaterial GetMaterials(const char* key)
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toMaterialsDic.to_ptr());
        return ResMaterial(dic[key]);
    }

    const ResMaterial GetMaterials(int idx) const {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toMaterialsDic.to_ptr());
        return ResMaterial(dic[idx]);
    }

    const ResMaterial GetMaterials(const char* key) const {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toMaterialsDic.to_ptr());
        return ResMaterial(dic[key]);
    }

    s32 GetMaterialsIndex(const char* key) const {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toMaterialsDic.to_ptr());
        return dic.GetIndex(key);
    }

    nw::ut::internal::ResArray<ResMaterial, nw::ut::internal::ResArrayDicTraits<nw::ut::ResDicPatriciaData>::Traits> GetMaterials()
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toMaterialsDic.to_ptr());
        return nw::ut::internal::ResArray<ResMaterial, nw::ut::internal::ResArrayDicTraits<nw::ut::ResDicPatriciaData>::Traits>((dic.IsValid()) ? dic.ref().GetBeginNode() : 0, GetMaterialsCount());
    }

    const nw::ut::internal::ResArray<const ResMaterial, nw::ut::internal::ResArrayDicTraits<nw::ut::ResDicPatriciaData>::Traits> GetMaterials() const
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toMaterialsDic.to_ptr());
        return nw::ut::internal::ResArray<const ResMaterial, nw::ut::internal::ResArrayDicTraits<nw::ut::ResDicPatriciaData>::Traits>((dic.IsValid()) ? dic.ref().GetBeginNode() : 0, GetMaterialsCount());
    }
};

} // namespace res
} // namespace gfx
} // namespace nw


