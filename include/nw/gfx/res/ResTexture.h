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

struct ResTextureData : public ResSceneObjectData
{
};

class ResTexture : public ResSceneObject
{
public:
    typedef ResTexture SelfType;
    typedef ResTextureData ResDataType;

    explicit ResTexture(const void* p = 0) : ResSceneObject(p) {}

    ResDataType* ptr() { return reinterpret_cast<ResDataType*>(void_ptr()); }
    const ResDataType* ptr() const { return reinterpret_cast<const ResDataType*>(void_ptr()); }

    ResDataType& ref() { return *reinterpret_cast<ResDataType*>(void_ptr()); }
    const ResDataType& ref() const { return *reinterpret_cast<const ResDataType*>(void_ptr()); }

    bool operator==(const ResTexture& rhs) const { return ptr() == rhs.ptr(); }
    bool operator!=(const ResTexture& rhs) const { return ptr() != rhs.ptr(); }
};

} // namespace res
} // namespace gfx
} // namespace nw


