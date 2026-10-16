#pragma once

#include "courseselect/ActorState.h"

#include "gfx/AnimModel.h"

namespace course_select {
class MapObjKinokoHouse : public ActorState
{
public:
    Result onCreate() override;
    Result onDelete() override;
    Result onExecute() override;
    Result onDraw() override;

    HeapAllocator allocator;
    Resource* resource;
    AnimModelBase* model;
    u32 _C8;
    sead::BoundBox3f boundBox;
    u8 pad[8];
    
};
}
