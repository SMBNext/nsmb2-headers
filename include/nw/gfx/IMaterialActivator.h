#pragma once

#include "nw/gfx/GfxObject.h"

namespace nw { namespace gfx {

class RenderContext;
class Material;

class IMaterialActivator : public GfxObject
{
public:
    virtual void Activate(RenderContext* renderContext, const Material* material) = 0;

protected:
    IMaterialActivator(os::IAllocator* allocator) : GfxObject(allocator) {}
    virtual ~IMaterialActivator() = 0;
};

} // namespace gfx
} // namespace nw


