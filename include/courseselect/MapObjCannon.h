#pragma once

#include "courseselect/ActorState.h"

#include "gfx/Model.h"

namespace course_select {
class MapObjCannon : public ActorState
{
public:
    Result onCreate() override;
    Result onDelete() override;
    Result onExecute() override;
    Result onDraw() override;

    HeapAllocator allocator;
    Resource* resource;
    Model* model;
    sead::BoundBox3f boundBox;
    
    void updateModelMatrix();
};
}
