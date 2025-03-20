#pragma once

#include "sead/heap/seadHeap.h"
#include "math/Vec.h"

// This class is entirely inlined
class UnkFragmentBase
{
public:
    UnkFragmentBase(sead::Heap* heap) :
        mHeap(heap) {}

    u32 _4;
    u32 _8;
    sead::Heap* mHeap;
    bool mIsFinished;
};

size_assert(UnkFragmentBase, 0x10);

// Size: 0x5C
// Vtable: 0x005CB510
class Fragment : UnkFragmentBase
{
public:
    Fragment(sead::Heap* heap) :
        UnkFragmentBase(heap) {}

    virtual void onCreate() = 0;

    // Address: 0x002568AC
    virtual void onExecute();

    // Address: 0x002568A4
    virtual void onDraw();

    // Address: 0x002568A8
    virtual void onDelete();

    Vec3f mPosition;
    Vec3f mSpeed;
    Vec3f mMaxSpeed;
    Vec3f mScale;
    Vec3i mRotation;
    f32 mAcceleration;
    u32 mFlags;
    u16 mTimer;
    s8 mPlayerId;
};

size_assert(Fragment, 0x5C);