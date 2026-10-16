#pragma once

#include "gfx/UnkSkeletalAnimHolder.h"
#include "sys/Allocator.h"
#include "math/Mtx34.h"

#include "nw/gfx/Model.h"

#include "sys/ResourceMgr.h"

// These are all wrappers around nw::gfx classes, used to be called UnkA, UnkB etc

// TODO: Give these better names...


class SharedModel;

class TransformNodeWrapper  // Size 0x8
{
    // Vtable: 0059E1EC
public:
    // 001B2248
    TransformNodeWrapper();

    // 001B2260
    virtual ~TransformNodeWrapper();

    // 001B221C
    virtual void updateTransform();

    // 001B21D4
    virtual void cleanup();

    // 001B2224
    void setDrawMatrix(Mtx34* mtx);

    // 001B2194
    void accept(s32 sceneTraverserIdx); // Indexes an array of two nw::gfx::SceneTraverser at 0x005EFB90

    // 00495588
    const nw::gfx::CalculatedTransform& getTransform() const;

    // 0024B01C
    SharedModel* createSharedModel(HeapAllocator* allocator);

protected:
    nw::gfx::TransformNode* obj;  // 4
};

class ModelWrapper : public TransformNodeWrapper    // Size 0x14
{
    // Vtable: 0059E1D0
public:
    // 001B1D6C
    ModelWrapper();

    // 001B1D84
    ~ModelWrapper() override;

    // 001B3718
    void updateTransform() override;

    // 001B21B0
    void cleanup() override;

    // Deleted
    virtual void vf10();

    // 001B4858
    void createObject(nw::gfx::res::ResSceneObjectData* resData, nw::os::IAllocator* allocator, nw::os::IAllocator* deviceAllocator,
                    nw::gfx::Model::BufferOption bufferOption, bool isAnimEnabled, s32 maxAnimObjectsPerGroup);

    // 00317C70
    void createObject(nw::gfx::Model* sharedMaterialModel, nw::os::IAllocator* allocator);

    // 001B49B8
    nw::gfx::Model* getModel();

    u8  maxAnimObjectsPerGroup;  // 8
    u8  _9;                      // 9
    u8  _A;                      // A
    u8  _B;                      // B
    f32 depthValue;              // C - set to -1000000.0 in createObject
    u8  renderOrder;             // 10 - defaulted to 6, max is 10, DistantViewMgr uses 0
};

class SkeletalModelWrapper : public ModelWrapper    // Size 0x18
{
    // Some of the functions here likely belong to ModelWrapper and not SkeletalModelWrapper...

    // Vtable: 005D0048
public:
    // 001B1658
    void setBoneLocalTransformMatrix(s32 boneIdx, const Mtx34& mtx);

    // 001B16E0
    void setBoneLocalTransformScale(s32 boneIdx, const Vec3f& scale);

    // 001B1AD4
    nw::gfx::AnimGroup* getSkeletalAnimGroup();

    // 001B1B20
    nw::gfx::CalculatedTransform* getBoneLocalTransform(s32 boneIdx);

    // 001B4334
    void evaluateAnims();

    // 001B436C
    void updateAnims();

    // 001B4540
    nw::gfx::AnimGroup* getMaterialAnimGroup();

    // 001B4688
    nw::gfx::AnimGroup* getVisibilityAnimGroup();

    // 001B1CD8
    void linkToUnkSkeletalAnimHolder(UnkSkeletalAnimHolder* unkSkeletalAnimHolder);

    // 001B4A04
    void sortMeshDataByUnk();

    // 002D2678 - unk

    // 002D26E4 - unk

    // 00494E90
    bool getBoneWorldTransformMatrix(Mtx34& out, s32 boneIdx);

    // 00495024
    bool getBonePosition(Vec3f& positionOut, s32 boneIdx);

    // 00495190
    const char* getBoneName(s32 boneIdx);

    // 00495248
    s32 getBoneCount();

    // 004952C0
    s32 getBoneIdx(const char* boneName);

    // 0049539C
    bool getBoneLocalTransformMatrix(Mtx34& out, s32 boneIdx);

    // 00495450
    const nw::gfx::SkeletalModel& getSkeletalModel() const; // these may be the other way round, unsure

    // 001B17B4
    nw::gfx::SkeletalModel& getSkeletalModel();

    // 0049549C
    bool getBoneLocalTransformScale(Vec3f& scaleOut, s32 boneIdx);

    // 00495524
    nw::gfx::CalculatedTransform* getBoneWorldTransform(s32 boneIdx);

    f32 _14;                     // 14
};

// Size: 0x14
// Vtable: 0x005B6A98
class SharedModelWrapper : public ModelWrapper
{

};

// Size 0xC
// Vtable: 0x0059E2F4
class FogWrapper : public TransformNodeWrapper
{
public:
    // Address C1: 0x001B4170
    FogWrapper();

    // Address D1: 0x001B4198
    ~FogWrapper() override;

    // Address: 0x001B416C
    void updateTransform() override;

    // Address: 0x001B40B8
    bool create(HeapAllocator* allocator);

private:
    void *mResData; // TODO: nw::gfx::res::ResFogData*
};

size_assert(FogWrapper, 0xC);