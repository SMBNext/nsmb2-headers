#pragma once

#include "courseselect/ActorState.h"

#include "gfx/AnimModel.h"
#include "sys/Allocator.h"

namespace course_select {
class MapObjDokan : public ActorState
{
public:
    Result onCreate() override;
    Result onExecute() override;
    Result onDelete() override;
    Result onDraw() override;

    DECLARE_STATE_ID(MapObjDokan, Hidden);
    DECLARE_STATE_ID(MapObjDokan, Wait);
    DECLARE_STATE_ID(MapObjDokan, Appear);
    DECLARE_STATE_ID(MapObjDokan, In);
    DECLARE_STATE_ID(MapObjDokan, Out);

    void createModel();

    HeapAllocator allocator;
    Resource* resource;
    AnimModelBase* model;
    Model* modelStatic;
    sead::BoundBox3f boundBox;
    u32 _E4;
    bool _E8;

};
size_assert(MapObjDokan, 0xEC);
}
