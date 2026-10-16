#pragma once

#include "actors/ActorMultiState.h"
#include "gfx/GfxWrapper.h"
#include "gfx/SimpleRenderer.h"

// Size: 0x22C8
class RotParentBase : public ActorMultiState
{
    SEAD_RTTI_OVERRIDE(RotParentBase, ActorMultiState);
public:
    static const u32 cMaxChildren = 16;
    
public:
    RotParentBase();

    virtual Result onCreate() override;
    virtual Result onDelete() override;
    virtual Result onExecute() override;
    virtual Result onDraw() override;
    
    // Returns the model wrapper for the actor.
    virtual SkeletalModelWrapper* getModel() = 0;

    // Creates a child actor at the specified `position` and `childIndex`.
    virtual void createChild(const Vec3f& position, u32 childIndex) = 0;

    // Creates a child coin at the specified `position` and `childIndex`.
    virtual void createChildCoin(const Vec3f& position, u32 childIndex);

    // Creates the model used for for the child actor.
    virtual void createModel() = 0;

    // Updates the animation for the child actor.
    virtual void updateAnimation() = 0;

    // Returns `true` if the RotParent is in view of the camera.
    bool isInViewRange();

    // Returns `true` if the RotParent's activation range is in view of the camera.
    bool isInActiveRange();

    // Sets the active state of the child actors.
    void setChildrenActive(bool active);

    // Calculates the position of the child actor at `childIndex` within the circle.
    // Stores the result in `positionOut`.
    void calcChildAngle(u32 childIndex, Vec2f& positionOut);

    DECLARE_STATE_ID(RotParentBase, Rotate);

    // Sets the child actor at `childIndex` to `actorId`.
    void setChild(u32 childIndex, ActorUniqueID actorId)
    {
        mChildren[childIndex] = actorId;
    }
    
protected:
    /* 0x0FEC */  ActorUniqueID mChildren[cMaxChildren];    //
    /* 0x102C */  sead::ExpHeap* mLineHeap;                 // 
    /* 0x1030 */  SimpleRenderer mLineRenderer;             // 
    /* 0x22A8 */  u32 mRotationDirection;                   // Initialized to nybble 11
    /* 0x22AC */  u32 mRotationSpeed;                       // Initialized to nybble 10
    /* 0x22B0 */  u32 mChildCount;                          // Initialized to nybble 7 (+1)
    /* 0x22B4 */  s32 mAngleStep;                           //
    /* 0x22B8 */  s32 mCurRotation;                         //
    /* 0x22BC */  f32 mCircleRadius;                        // Initialized to nybble 6 (16 * value + 16)
    /* 0x22C0 */  u16 mGapBitfield;                         // Initialized to nybble 16 - 19
    /* 0x22C2 */  bool mIsAllCoin;                          // Initialized to nybble 15 == 2
    /* 0x22C3 */  bool mGapIsCoin;                          // Initialized to nybble 15 == 1
    /* 0x22C4 */  bool mChildrenActive;                     //
    /* 0x22C5 */  bool mVisibleLine;                        // Initialized to nybble 9 bit 1
};

size_assert(RotParentBase, 0x22C8);
