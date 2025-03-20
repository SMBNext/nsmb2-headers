#pragma once

#include "nw/gfx/res/ResSceneObject.h"
#include "nw/ut/ResArrayTypes.h"

namespace nw {
namespace gfx {
namespace res {

struct ResMeshNodeVisibilityData
{
    nw::ut::BinString toName;
    bool m_IsVisible;
};

struct ResMeshData : public ResSceneObjectData
{
    s32 m_ShapeIndex;
    s32 m_MaterialIndex;
    nw::ut::Offset toOwnerModel;
    bool m_IsVisible;
    u8 m_RenderPriority;
    s16 m_MeshNodeVisibilityIndex;
    s32 m_CurrentPrimitiveIndex;
    u32 m_Flags;
    u32 m_IrScaleCommand[12];
    void* m_ActivateCommandCache;
    s32 m_ActivateCommandCacheSize;
    void* m_DeactivateCommandCache;
    s32 m_DeactivateCommandCacheSize;
    nw::ut::BinString toMeshNodeName;
    u64 m_RenderKeyCache;
    nw::os::IAllocator* m_CommandAllocator;
};

class ResMesh : public ResSceneObject
{
public:
    enum Flag
    {
        FLAG_HAS_VERTEX_ALPHA  = 0x1,
        FLAG_HAS_BONE_WEIGHT_W = 0x1 << 1,
        FLAG_VALID_RENDER_KEY_CACHE = 0x1 << 2,
        FLAG_HAS_BEEN_SETUP = 0x1 << 3
    };

    typedef ResMesh SelfType;
    typedef ResMeshData ResDataType;
    explicit ResMesh(const void* p = 0) : ResSceneObject(p) {}

    ResDataType* ptr() { return reinterpret_cast<ResDataType*>(void_ptr()); }
    const ResDataType* ptr() const { return reinterpret_cast<const ResDataType*>(void_ptr()); }

    ResDataType& ref() { return *reinterpret_cast<ResDataType*>(void_ptr()); }
    const ResDataType& ref() const { return *reinterpret_cast<const ResDataType*>(void_ptr()); }

    bool operator==(const ResMesh& rhs) const { return ptr() == rhs.ptr(); }
    bool operator!=(const ResMesh& rhs) const { return ptr() != rhs.ptr(); }
};

typedef nw::ut::ResArrayClass<ResMesh>::type  ResMeshArray;

} // namespace res
} // namespace gfx
} // namespace nw


