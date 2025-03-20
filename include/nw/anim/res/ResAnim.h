#pragma once

#include "nw/gfx/res/ResSceneObject.h"

#include "nw/ut/BinaryFileFormat.h"
#include "nw/ut/ResDictionary.h"
#include "nw/ut/ResMetaData.h"
#include "nw/ut/ResTypes.h"
#include "nw/ut/ResUtil.h"

namespace nw {
namespace anim {
namespace res {

struct ResAnimData
{
    enum LoopMode
    {
        LOOP_MODE_ONETIME,
        LOOP_MODE_LOOP
    };

    ut::BinaryRevisionHeader m_Header;
    ut::BinString toName;
    ut::BinString toTargetAnimGroupName;
    u8 m_LoopMode;
    u8 padding_[3];
    f32 m_FrameSize;
    s32 m_MemberAnimSetDicCount;
    ut::Offset toMemberAnimSetDic;
    s32 m_UserDataDicCount;
    ut::Offset toUserDataDic;
};

class ResAnim : public ut::ResCommon<ResAnimData>
{
public:
    explicit ResAnim(const void* p = nullptr) : 
        nw::ut::ResCommon<ResAnimData>(p) {}

    ResAnimData& ref() { return *ptr(); }
    const ResAnimData& ref() const { return *ptr(); }

    nw::ut::BinaryRevisionHeader& GetHeader() { return ref().m_Header; }
    const nw::ut::BinaryRevisionHeader& GetHeader() const { return ref().m_Header; }

    u32 GetRevision() const { return this->GetHeader().revision; }

    const char* GetName() const { return ref().toName.to_ptr(); }

    const char* GetTargetAnimGroupName() const { return ref().toTargetAnimGroupName.to_ptr(); }

    u8 GetLoopMode() const { return static_cast<u8>(ref().m_LoopMode); }
    void SetLoopMode(u8 value) { ref().m_LoopMode = value; }

    f32 GetFrameSize() const { return static_cast<f32>(ref().m_FrameSize); }
    void SetFrameSize(f32 value) { ref().m_FrameSize = value; }

    s32 GetMemberAnimSetCount() const { return ref().m_MemberAnimSetDicCount; }
    // TODO: GetMemberAnimSet()

    s32 GetUserDataCount() const { return ref().m_UserDataDicCount; }

    nw::ut::ResMetaData GetUserData(int idx)
    {
        ut::ResDicPatricia dic = ut::ResDicPatricia(ref().toUserDataDic.to_ptr());
        return nw::ut::ResMetaData(dic[idx]);
    }

    nw::ut::ResMetaData GetUserData(const char* key)
    {
        ut::ResDicPatricia dic = ut::ResDicPatricia(ref().toUserDataDic.to_ptr());
        return nw::ut::ResMetaData(dic[key]);
    }

    s32 GetUserDataIndex(const char* key) const
    {
        ut::ResDicPatricia dic = ut::ResDicPatricia(ref().toUserDataDic.to_ptr());
        return dic.GetIndex(key);
    }

};

} // namespace res
} // namespace anim
} // namespace nw
