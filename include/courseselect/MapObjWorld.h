#pragma once

#include "courseselect/ActorState.h"

#include "courseselect/CourseSelect.h"
#include "effect/Effect.h"
#include "env/EnvEffectBase.h"
#include "gfx/AnimModel.h"
#include "sead/gfx/seadTexture.h"
#include "state/FStateVirtualID.h"


namespace course_select {
class MapObjWorld : public ActorState   // Size: 0x2DC
{
public:
    Result onCreate() override;
    Result onDelete() override;
    Result onExecute() override;
    Result onDraw() override;

    SkeletalModelWrapper* getPathModel();
    void updateModelMtxPaths();

    DECLARE_STATE_ID(MapObjWorld, Unk1);
    DECLARE_STATE_ID(MapObjWorld, Unk2);

    HeapAllocator allocator;
    Resource* resource;
    Model* pathModel;
    Model* baseModel;
    AnimModelBase* animObjModel;
    Model* pathModelMulti;
    AnimModelBase* baseModels[3];
    AnimModelBase* animObjModels[3];
    sead::BoundBox3f boundBoxArray[3];      // Culling rects, probably
    bool baseModelCullStatus[3];            // init to 0x1010101
    bool animObjModelCullStatus[3];
    u8 _139[2];
    AnimModelBase* baseModelW3;
    sead::BoundBox3f baseBoundBoxW3;
    sead::BoundBox3f animObjBoundBoxW3_1;
    sead::BoundBox3f animObjBoundBoxW3_2;
    sead::BoundBox3f animObjBoundBoxW3_3;
    AnimModelBase* baseModelW6_1;
    AnimModelBase* baseModelW6_2;
    sead::BoundBox3f baseBoundBoxW6_1;
    sead::BoundBox3f baseBoundBoxW6_2;
    sead::BoundBox3f animObjBoundBoxW6_1;
    sead::BoundBox3f animObjBoundBoxW6_2;
    sead::BoundBox3f animObjBoundBoxW6_3;
    EnvEffectBase* envEffect;
    LevelEffect effect;
    Vec3f effectPos;
    u8 _unk28C[4];
    bool notFadingInPath;
    u8 _291;
    u8 _292[2];                           // unk
    u8 newlyCompletedCourseId;            // Set to 31 if already completed or non-completable course slot
    ExitType newlyCompletedExitType;      // The exit type of the last newly completed course
    u8 _296[2];                           // unk
    u32 numRoutesUnlocking;
    sead::SafeString* routesUnlocking[16];

};
}
