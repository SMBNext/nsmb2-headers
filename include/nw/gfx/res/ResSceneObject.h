#pragma once

#include "nw/gfx/GfxObject.h"
#include "nw/ut/ResUtil.h"
#include "nw/ut/BinaryFileFormat.h"
#include "nw/ut/ResTypes.h"
#include "nw/ut/ResMetaData.h"
#include "nw/ut/ResDictionary.h"
#include "nw/ut/ResArray.h"
#include "nw/ut/ResArrayTypes.h"
#include "nw/anim/res/ResAnimGroup.h"


namespace nw {
namespace gfx {
namespace res {

struct ResSceneObjectData
{
    nw::ut::ResTypeInfo typeInfo;
    nw::ut::BinaryRevisionHeader m_Header;
    nw::ut::BinString toName;
    s32 m_UserDataDicCount;
    nw::ut::Offset toUserDataDic;
};

struct ResSceneNodeData : public ResSceneObjectData
{
    enum Flag 
    {
        FLAG_IS_BRANCH_VISIBLE_SHIFT = 0,
        FLAG_SHIFT_MAX,
        
        FLAG_IS_BRANCH_VISIBLE = 0x1 << FLAG_IS_BRANCH_VISIBLE_SHIFT
    };
    
    u32 m_Flags;
    bool m_IsBranchVisible;
    u8 padding_0[3];
    s32 m_ChildrenTableCount;
    nw::ut::Offset toChildrenTable;
    s32 m_AnimGroupsDicCount;
    nw::ut::Offset toAnimGroupsDic;
};

struct ResTransformNodeData : public ResSceneNodeData
{
    nw::math::Transform3 m_Transform;
    nw::math::MTX34 m_LocalMatrix;
    nw::math::MTX34 m_WorldMatrix;
};

class ResSceneObject : public nw::ut::ResCommon<ResSceneObjectData>
{

public:
    explicit ResSceneObject(const void* p = 0) : nw::ut::ResCommon<ResSceneObjectData>(p) {}

    ResSceneObjectData& ref() { return *ptr(); }
    const ResSceneObjectData& ref() const { return *ptr(); }

    bool operator==(const ResSceneObject& rhs) const { return ptr() == rhs.ptr(); }
    bool operator!=(const ResSceneObject& rhs) const { return ptr() != rhs.ptr(); }

    inline nw::ut::BinaryRevisionHeader& GetHeader() { return ref().m_Header; }
    inline const nw::ut::BinaryRevisionHeader& GetHeader() const { return ref().m_Header; }
    inline void SetHeader(const nw::ut::BinaryRevisionHeader& value) { ref().m_Header = value; }

    inline const char* GetName() const { return ref().toName.to_ptr(); }

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

    nw::ut::ResTypeInfo GetTypeInfo() const { return ref().typeInfo; }
};

class ResSceneNode : public ResSceneObject
{
public:
    typedef ResSceneNode SelfType;
    typedef ResSceneNodeData ResDataType;

    explicit ResSceneNode(const void* p = 0) : ResSceneObject(p) {}

    ResDataType* ptr() { return reinterpret_cast<ResDataType*>(void_ptr()); }
    const ResDataType* ptr() const { return reinterpret_cast<const ResDataType*>(void_ptr()); }

    ResDataType& ref() { return *reinterpret_cast<ResDataType*>(void_ptr()); }
    const ResDataType& ref() const { return *reinterpret_cast<const ResDataType*>(void_ptr()); }
    
    bool operator==(const ResSceneNode& rhs) const { return ptr() == rhs.ptr(); }
    bool operator!=(const ResSceneNode& rhs) const { return ptr() != rhs.ptr(); }

    u32 GetFlags() const { return static_cast<u32>(ref().m_Flags); }
    void SetFlags(u32 value) { ref().m_Flags = value; }

    s32 GetChildrenCount() const { return ref().m_ChildrenTableCount; }
    ResSceneObject GetChildren(int idx)
    {
        nw::ut::Offset* tbl_ptr = static_cast<nw::ut::Offset*>(ref().toChildrenTable.to_table_ptr());
        return ResSceneObject(tbl_ptr[idx].to_ptr());
    }

    const ResSceneObject GetChildren(int idx) const
    {
        const nw::ut::Offset* tbl_ptr = static_cast<const nw::ut::Offset*>(ref().toChildrenTable.to_table_ptr());
        return ResSceneObject(tbl_ptr[idx].to_ptr());
    }

    nw::ut::internal::ResArray<ResSceneObject, nw::ut::internal::ResArrayClassTraits> GetChildren()
    {
        return nw::ut::internal::ResArray<ResSceneObject, nw::ut::internal::ResArrayClassTraits>(ref().toChildrenTable.to_table_ptr(), GetChildrenCount());
    }
    const nw::ut::internal::ResArray<const ResSceneObject, nw::ut::internal::ResArrayClassTraits> GetChildren() const
    {
        return nw::ut::internal::ResArray<const ResSceneObject, nw::ut::internal::ResArrayClassTraits>(ref().toChildrenTable.to_table_ptr(), GetChildrenCount());
    }

    s32 GetAnimGroupsCount() const { return ref().m_AnimGroupsDicCount; }
    nw::anim::res::ResAnimGroup GetAnimGroups(int idx)
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toAnimGroupsDic.to_ptr());
        return nw::anim::res::ResAnimGroup(dic[idx]);
    }
    nw::anim::res::ResAnimGroup GetAnimGroups(const char* key)
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toAnimGroupsDic.to_ptr());
        return nw::anim::res::ResAnimGroup(dic[key]);
    }
    const nw::anim::res::ResAnimGroup GetAnimGroups(int idx) const
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toAnimGroupsDic.to_ptr());
        return nw::anim::res::ResAnimGroup(dic[idx]);
    }
    const nw::anim::res::ResAnimGroup GetAnimGroups(const char* key) const
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toAnimGroupsDic.to_ptr());
        return nw::anim::res::ResAnimGroup(dic[key]);
    }
    s32 GetAnimGroupsIndex(const char* key) const {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toAnimGroupsDic.to_ptr());
        return dic.GetIndex(key);
    }
    nw::ut::internal::ResArray<nw::anim::res::ResAnimGroup, nw::ut::internal::ResArrayDicTraits<nw::ut::ResDicPatriciaData>::Traits> GetAnimGroups()
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toAnimGroupsDic.to_ptr());
        return nw::ut::internal::ResArray<nw::anim::res::ResAnimGroup, nw::ut::internal::ResArrayDicTraits<nw::ut::ResDicPatriciaData>::Traits>((dic.IsValid()) ? dic.ref().GetBeginNode() : 0, GetAnimGroupsCount());
    }
    const nw::ut::internal::ResArray<const nw::anim::res::ResAnimGroup, nw::ut::internal::ResArrayDicTraits<nw::ut::ResDicPatriciaData>::Traits> GetAnimGroups() const
    {
        nw::ut::ResDicPatricia dic = nw::ut::ResDicPatricia(ref().toAnimGroupsDic.to_ptr());
        return nw::ut::internal::ResArray<const nw::anim::res::ResAnimGroup, nw::ut::internal::ResArrayDicTraits<nw::ut::ResDicPatriciaData>::Traits>((dic.IsValid()) ? dic.ref().GetBeginNode() : 0, GetAnimGroupsCount());
    }

    bool IsBranchVisible() const { return ref().m_Flags & 0x1; }
    
    void SetBranchVisible(bool flag) 
    {
        if (flag)
        {
            ref().m_Flags |= 0x1;
        }
        else
        {
            ref().m_Flags &= ~0x1;
        }
    }
};

class ResTransformNode : public ResSceneNode
{

public:
    typedef ResTransformNode SelfType;
    typedef ResTransformNodeData ResDataType;

    explicit ResTransformNode(const void* p = 0) : ResSceneNode(p) {}

    ResDataType* ptr() { return reinterpret_cast<ResDataType*>(void_ptr()); }
    const ResDataType* ptr() const { return reinterpret_cast<const ResDataType*>(void_ptr()); }

    ResDataType& ref() { return *reinterpret_cast<ResDataType*>(void_ptr()); }
    const ResDataType& ref() const { return *reinterpret_cast<const ResDataType*>(void_ptr()); }

    bool operator==(const ResTransformNode& rhs) const { return ptr() == rhs.ptr(); }
    bool operator!=(const ResTransformNode& rhs) const { return ptr() != rhs.ptr(); }

    nw::math::Transform3& GetTransform() { return ref().m_Transform; }
    const nw::math::Transform3& GetTransform() const { return ref().m_Transform; }

    void SetTransform(const nw::math::Transform3& value) { ref().m_Transform = value; }

    nw::math::MTX34& GetWorldMatrix() { return ref().m_WorldMatrix; }
    const nw::math::MTX34& GetWorldMatrix() const { return ref().m_WorldMatrix; }

    void SetWorldMatrix(const nw::math::MTX34& value) { ref().m_WorldMatrix = value; }
};

} // namespace res
} // namespace gfx
} // namespace nw


