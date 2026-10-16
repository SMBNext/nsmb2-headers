#pragma once

#include "gfx/Model.h"
#include "gfx/GfxWrapper.h"

// Size: 0x2C
// Vtable: 0x005A8644
class SharedModel : public Model
{
public:
    virtual ~SharedModel();
    virtual SkeletalModelWrapper* getGfxWrapper() override; 

protected:
    SharedModelWrapper mSharedWrapper;
};

size_assert(SharedModel, 0x2C);