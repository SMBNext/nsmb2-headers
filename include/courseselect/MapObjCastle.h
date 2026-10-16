#pragma once

#include "courseselect/ActorState.h"

#include "gfx/AnimModel.h"

namespace course_select {
class MapObjCastle : public ActorState
{
public:
    Result onCreate() override;
    Result onDelete() override;
    Result onExecute() override;
    Result onDraw() override;

    DECLARE_STATE_ID(MapObjCastle, 17D);
    DECLARE_STATE_ID(MapObjCastle, 17E);
    DECLARE_STATE_ID(MapObjCastle, 17F);
    DECLARE_STATE_ID(MapObjCastle, 180);
    DECLARE_STATE_ID(MapObjCastle, 181);
    DECLARE_STATE_ID(MapObjCastle, 182);

    HeapAllocator allocator;
    Resource* resource;
    AnimModelBase* model1;
    Model* model2;
    u32 _CC;
    s32 _D0;
    sead::BoundBox3f boundBox;
    
    void updateModelMatrix1();
    void updateModelMatrix2();
};
}
