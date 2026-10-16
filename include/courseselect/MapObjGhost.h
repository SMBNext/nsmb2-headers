#pragma once

#include "courseselect/ActorState.h"

#include "gfx/AnimModel.h"

namespace course_select {
class MapObjGhost : public ActorState
{
public:
    Result onCreate() override;
    Result onDelete() override;
    Result onExecute() override;
    Result onDraw() override;

    DECLARE_STATE_ID(MapObjGhost, 18F);
    DECLARE_STATE_ID(MapObjGhost, 190);
    DECLARE_STATE_ID(MapObjGhost, 191);
    DECLARE_STATE_ID(MapObjGhost, 192);

    HeapAllocator allocator;
    Resource* resource;
    AnimModelBase* model1;
    Model* model2;
    sead::BoundBox3f boundBox;
    
};
}
