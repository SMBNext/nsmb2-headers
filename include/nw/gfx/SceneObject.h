#pragma once

#include "nw/gfx/GfxObject.h"
#include "nw/gfx/res/ResSceneObject.h"

namespace nw { namespace gfx {

class SceneObject : public GfxObject
{

public:
    res::ResSceneObject GetResSceneObject() { return m_ResObject; }
    const res::ResSceneObject GetResSceneObject() const { return m_ResObject; }

protected:
    SceneObject(os::IAllocator* allocator, res::ResSceneObject resObj) :
        GfxObject(allocator), m_ResObject(resObj) {}

    virtual ~SceneObject();

private:
    res::ResSceneObject m_ResObject;
};

} // namespace gfx
} // namespace nw


