#pragma once

#include "courseselect/ActorState.h"

#include "gfx/AnimModel.h"

namespace course_select {
class MapObjTower : public ActorState
{
public:
    Result onCreate() override;
    Result onDelete() override;
    Result onExecute() override;
    Result onDraw() override;

    DECLARE_STATE_ID(MapObjTower, 1A6);
    DECLARE_STATE_ID(MapObjTower, 1A7);
    DECLARE_STATE_ID(MapObjTower, 1A8);
    DECLARE_STATE_ID(MapObjTower, 1A9);
    DECLARE_STATE_ID(MapObjTower, 1AA);
    DECLARE_STATE_ID(MapObjTower, 1AB);

    HeapAllocator allocator;
    Resource* resource;
    AnimModelBase* model1;
    Model* model2;
    u8 _1D[8];
    sead::BoundBox3f boundBox;
    
    void updateModelMatrix1();
    void updateModelMatrix2();
};
}
