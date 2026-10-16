#pragma once

#include "nw/gfx/res/ResSceneObject.h"
#include "nw/ut/Flag.h"
#include "nw/ut/ResArrayTypes.h"

namespace nw {
namespace gfx {
namespace res {

class ResBoneData
{
public:
    enum Flag
    {
        FLAG_IS_IDENTITY                    = 0x1 << 0,
        FLAG_IS_TRANSLATE_ZERO              = 0x1 << 1,
        FLAG_IS_ROTATE_ZERO                 = 0x1 << 2,
        FLAG_IS_SCALE_ONE                   = 0x1 << 3,
        FLAG_IS_UNIFORM_SCALE               = 0x1 << 4,
        FLAG_IS_SEGMENTSCALE_COMPENSATE     = 0x1 << 5,
        FLAG_IS_NEED_RENDERING              = 0x1 << 6,
        FLAG_IS_LOCAL_MATRIX_CALCULATE      = 0x1 << 7,
        FLAG_IS_WORLD_MATRIX_CALCULATE      = 0x1 << 8,
        FLAG_HAS_SKINNING_MATRIX            = 0x1 << 9 
    };

    nw::ut::BinString toName;
    u32 m_Flags;
    s32 m_Index;
    s32 m_ParentBoneIndex;
    nw::ut::Offset toParentBone;
    nw::ut::Offset toChildBone;
    nw::ut::Offset toPrevSibling;
    nw::ut::Offset toNextSibling;
    math::Transform3 m_Transform;
    math::MTX34 m_LocalMatrix;
    math::MTX34 m_WorldMatrix;
    math::MTX34 m_InverseBaseMatrix;
    s32 m_BillboardMode;
    s32 m_UserDataDicCount;
    nw::ut::Offset toUserDataDic;
};

class ResSkeletonData : public ResSceneObjectData
{
public:
    enum Flag
    {
        FLAG_MODEL_COORDINATE                       = 0x1 << 0,
        FLAG_TRANSLATE_ANIMATION_ENABLED            = 0x1 << 1
    };

    s32 m_BonesDicCount;
    nw::ut::Offset toBonesDic;
    nw::ut::Offset toRootBone;
    s32 m_ScalingRule;
    u32 m_Flags;
};

class ResBone : public nw::ut::ResCommon<ResBoneData>
{
public:
    enum BillboardMode
    {
        BILLBOARD_MODE_OFF,
        BILLBOARD_MODE_WORLD,
        BILLBOARD_MODE_WORLD_VIEWPOINT,
        BILLBOARD_MODE_SCREEN,
        BILLBOARD_MODE_SCREEN_VIEWPOINT,
        BILLBOARD_MODE_Y_AXIAL,
        BILLBOARD_MODE_Y_AXIAL_VIEWPOINT
    };

    enum Flag
    {
        FLAG_IS_IDENTITY                    = 0x1 << 0,
        FLAG_IS_TRANSLATE_ZERO              = 0x1 << 1,
        FLAG_IS_ROTATE_ZERO                 = 0x1 << 2,
        FLAG_IS_SCALE_ONE                   = 0x1 << 3,
        FLAG_IS_UNIFORM_SCALE               = 0x1 << 4,
        FLAG_IS_SEGMENTSCALE_COMPENSATE     = 0x1 << 5,
        FLAG_IS_NEED_RENDERING              = 0x1 << 6,
        FLAG_IS_LOCAL_MATRIX_CALCULATE      = 0x1 << 7,
        FLAG_IS_WORLD_MATRIX_CALCULATE      = 0x1 << 8,
        FLAG_HAS_SKINNING_MATRIX            = 0x1 << 9 
    };

    typedef ResBone SelfType;
    typedef ResBoneData ResDataType;

    explicit ResBone(const void* p = nullptr) :
        nw::ut::ResCommon<ResBoneData>(p) {}

    ResBoneData& ref() { return *ptr(); }
    const ResBoneData& ref() const { return *ptr(); }

    const char* GetName() const { return ref().toName.to_ptr(); }

    u32 GetFlags() const { return static_cast<u32>(ref().m_Flags); }
    void SetFlags(u32 value) { ref().m_Flags = value; }
    void EnableFlags(u32 value) { ref().m_Flags = nw::ut::EnableFlag(ref().m_Flags, value); }
    void DisableFlags(u32 value) { ref().m_Flags = nw::ut::DisableFlag(ref().m_Flags, value); }
    
    s32 GetIndex() const { return static_cast<s32>(ref().m_Index); }
    void SetIndex(s32 value) { ref().m_Index = value; }

    s32 GetParentBoneIndex() const { return static_cast<s32>(ref().m_ParentBoneIndex); }
    void SetParentBoneIndex(s32 value) { ref().m_ParentBoneIndex = value; }

    ResBone GetParentBone() { return ResBone(ref().toParentBone.to_ptr()); }
    const ResBone GetParentBone() const { return ResBone(ref().toParentBone.to_ptr()); }

    ResBone GetChildBone() { return ResBone(ref().toChildBone.to_ptr()); }
    const ResBone GetChildBone() const { return ResBone(ref().toChildBone.to_ptr()); }

    ResBone GetPrevSibling() { return ResBone(ref().toPrevSibling.to_ptr()); }
    const ResBone GetPrevSibling() const { return ResBone(ref().toPrevSibling.to_ptr()); }

    ResBone GetNextSibling() { return ResBone(ref().toNextSibling.to_ptr()); }
    const ResBone GetNextSibling() const { return ResBone(ref().toNextSibling.to_ptr()); }

    math::Transform3 GetTransform() { return ref().m_Transform; }
    const math::Transform3& GetTransform() const { return ref().m_Transform; }
    void SetTransform(const math::Transform3& value) { ref().m_Transform = value; }

    math::MTX34 GetLocalMatrix() { return ref().m_LocalMatrix; }
    const math::MTX34& GetLocalMatrix() const { return ref().m_LocalMatrix; }
    void SetLocalMatrix(const math::MTX34& value) { ref().m_LocalMatrix = value; }

    math::MTX34 GetWorldMatrix() { return ref().m_WorldMatrix; }
    const math::MTX34& GetWorldMatrix() const { return ref().m_WorldMatrix; }
    void SetWorldMatrix(const math::MTX34& value) { ref().m_WorldMatrix = value; }

    math::MTX34 GetInverseBaseMatrix() { return ref().m_InverseBaseMatrix; }
    const math::MTX34& GetInverseBaseMatrix() const { return ref().m_InverseBaseMatrix; }
    void SetInverseBaseMatrix(const math::MTX34& value) { ref().m_InverseBaseMatrix = value; }

    BillboardMode GetBillboardMode() const { return static_cast<BillboardMode>(ref().m_BillboardMode); }
    void SetBillboardMode(BillboardMode value) { ref().m_BillboardMode = value; }

    inline s32 GetUserDataCount() const { return ref().m_UserDataDicCount; }

    inline nw::ut::ResMetaData GetUserData(int idx)
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toUserDataDic.to_ptr());
        return nw::ut::ResMetaData(dic[idx]);
    }

    inline nw::ut::ResMetaData GetUserData(const char* key)
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toUserDataDic.to_ptr());
        return nw::ut::ResMetaData(dic[key]);
    }

    inline const nw::ut::ResMetaData GetUserData(const char* key) const
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toUserDataDic.to_ptr());
        return nw::ut::ResMetaData(dic[key]);
    }

    inline s32 GetUserDataIndex(const char* key) const
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toUserDataDic.to_ptr());
        return dic.GetIndex(key);
    }

    nw::ut::internal::ResArray<nw::ut::ResMetaData, nw::ut::internal::ResArrayDicTraits<nw::ut::ResDicPatriciaData>::Traits> GetUserData()
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toUserDataDic.to_ptr());
        return nw::ut::internal::ResArray<nw::ut::ResMetaData, nw::ut::internal::ResArrayDicTraits<nw::ut::ResDicPatriciaData>::Traits>(
            (dic.IsValid()) ? dic.ref().GetBeginNode() : 0, GetUserDataCount());
    }

    const nw::ut::internal::ResArray<const nw::ut::ResMetaData, nw::ut::internal::ResArrayDicTraits<nw::ut::ResDicPatriciaData>::Traits> GetUserData() const
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toUserDataDic.to_ptr());
        return nw::ut::internal::ResArray<const nw::ut::ResMetaData, nw::ut::internal::ResArrayDicTraits<nw::ut::ResDicPatriciaData>::Traits>(
            (dic.IsValid()) ? dic.ref().GetBeginNode() : 0, GetUserDataCount());
    }
};

typedef nw::ut::ResArrayPatricia<ResBone>::type  ResBoneArray;

class ResSkeleton : public ResSceneObject
{
public:
    enum Flag
    {
        FLAG_MODEL_COORDINATE                       = 0x1 << 0,
        FLAG_TRANSLATE_ANIMATION_ENABLED            = 0x1 << 1
    };

    typedef ResSkeleton SelfType;
    typedef ResSkeletonData ResDataType;
    explicit ResSkeleton(const void* p = 0) : ResSceneObject(p) {}
    
    ResDataType* ptr() { return reinterpret_cast<ResDataType*>(void_ptr()); }
    const ResDataType* ptr() const { return reinterpret_cast<const ResDataType*>(void_ptr()); }

    ResDataType& ref() { return *reinterpret_cast<ResDataType*>(void_ptr()); }
    const ResDataType& ref() const { return *reinterpret_cast<const ResDataType*>(void_ptr()); }

    bool operator==(const ResSkeleton& rhs) const { return ptr() == rhs.ptr(); }
    bool operator!=(const ResSkeleton& rhs) const { return ptr() != rhs.ptr(); }

    const char* GetName() const { return ref().toName.to_ptr(); }

    u32 GetFlags() const { return static_cast<u32>(ref().m_Flags); }
    void SetFlags(u32 value) { ref().m_Flags = value; }
    void EnableFlags(u32 value) { ref().m_Flags = nw::ut::EnableFlag(ref().m_Flags, value); }
    void DisableFlags(u32 value) { ref().m_Flags = nw::ut::DisableFlag(ref().m_Flags, value); }

    inline s32 GetBonesCount() const { return ref().m_BonesDicCount; }

    inline ResBone GetBones(int idx)
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toBonesDic.to_ptr());
        return ResBone(dic[idx]);
    }

    inline ResBone GetBones(const char* key)
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toBonesDic.to_ptr());
        return ResBone(dic[key]);
    }

    inline const ResBone GetBones(const char* key) const
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toBonesDic.to_ptr());
        return ResBone(dic[key]);
    }

    inline s32 GetBonesIndex(const char* key) const
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toBonesDic.to_ptr());
        return dic.GetIndex(key);
    }

    nw::ut::internal::ResArray<ResBone, nw::ut::internal::ResArrayDicTraits<nw::ut::ResDicPatriciaData>::Traits> GetBones()
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toBonesDic.to_ptr());
        return nw::ut::internal::ResArray<ResBone, nw::ut::internal::ResArrayDicTraits<nw::ut::ResDicPatriciaData>::Traits>(
            (dic.IsValid()) ? dic.ref().GetBeginNode() : 0, GetBonesCount());
    }

    const nw::ut::internal::ResArray<const ResBone, nw::ut::internal::ResArrayDicTraits<nw::ut::ResDicPatriciaData>::Traits> GetBones() const
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toBonesDic.to_ptr());
        return nw::ut::internal::ResArray<const ResBone, nw::ut::internal::ResArrayDicTraits<nw::ut::ResDicPatriciaData>::Traits>(
            (dic.IsValid()) ? dic.ref().GetBeginNode() : 0, GetBonesCount());
    }

    ResBone GetRootBone() { return ResBone(ref().toRootBone.to_ptr()); }
    const ResBone GetRootBone() const { return ResBone(ref().toRootBone.to_ptr()); }

    s32 GetScalingRule() const { return static_cast<s32>(ref().m_ScalingRule); }
    void SetScalingRule(s32 value) { ref().m_ScalingRule = value; }
};


} // namespace res
} // namespace gfx
} // namespace nw