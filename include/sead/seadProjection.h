#pragma once

#include "math/Mtx44.h"
#include "math/Vec.h"

#include "sead/seadGraphics.h"
#include "sead/seadRuntimeTypeInfo.h"

namespace sead {

// size: 0x94
class Projection
{
    // Vtable: 005D1234
public:
    enum Type : u32
    {
        Type_Perspective = 0,
        Type_Ortho       = 1,
        Type_Undefined   = 2
    };

    // Inlined
    Projection() : 
        mDirty(true),
        mDeviceDirty(true),
        mDevicePosture(Graphics::sDefaultDevicePosture),
        mDeviceZScale(Graphics::sDefaultDeviceZScale),
        mDeviceZOffset(Graphics::sDefaultDeviceZOffset) {}

    // GetRuntimeTypeInfo: 004B0894
    // GetRuntimeTypeInfoStatic::typeInfo: 00603EC4
    SEAD_RTTI_BASE(Projection);

    // Pure virtual
    virtual Type getProjectionType() const = 0;
    // Pure virtual
    virtual void doUpdateMatrix(Mtx44* mtx) const = 0;
    // 004B0A68
    virtual void doUpdateDeviceMatrix(Mtx44* dst, const Mtx44& src, Graphics::DevicePosture posture) const;
    // Pure virtual
    virtual void doScreenPosToCameraPosTo(Vec3f* vec1, const Vec3f& vec2) const = 0;

    // 004B08E0
    const Mtx44& getProjectionMatrix() const;
    // 004B0C4C
    const Mtx44& getDeviceProjectionMatrix() const;

    void setDirty()
    {
        mDirty = true;
    }

    void setDeviceDirty()
    {
        mDeviceDirty = true;
    }

    void setDevicePosture(Graphics::DevicePosture posture)
    {
        mDevicePosture = posture;
        setDeviceDirty();
    }

private:
    mutable bool mDirty;                    // 4
    mutable bool mDeviceDirty;              // 5
    Mtx44 mMatrix;                          // 8
    Mtx44 mDeviceMatrix;                    // 48
    Graphics::DevicePosture mDevicePosture; // 88
    f32 mDeviceZScale;                      // 8C
    f32 mDeviceZOffset;                     // 90
};


class OrthoProjection : public Projection   // size: 0xAc
{
public:
    OrthoProjection();

    SEAD_RTTI_OVERRIDE(OrthoProjection, Projection);

    Type getProjectionType() const override;
    void doUpdateMatrix(Mtx44* mtx) const override;
    void doScreenPosToCameraPosTo(Vec3f* vec1, const Vec3f& vec2) const override;

    void setTBLR(f32 top, f32 bottom, f32 left, f32 right);

    void setNear(f32 near)
    {
        mNear = near;
        setDirty();
    }

    void setFar(f32 far)
    {
        mFar = far;
        setDirty();
    }

    void setTop(f32 top)
    {
        mTop = top;
        setDirty();
    }

    void setBottom(f32 bottom)
    {
        mBottom = bottom;
        setDirty();
    }

    void setLeft(f32 left)
    {
        mLeft = left;
        setDirty();
    }

    void setRight(f32 right)
    {
        mRight = right;
        setDirty();
    }

private:
    f32 mNear;                  // 94
    f32 mFar;                   // 98
    f32 mTop;                   // 9C
    f32 mBottom;                // A0
    f32 mLeft;                  // A4
    f32 mRight;                 // A8
};


class PerspectiveProjection : public Projection     // size: 0xB4
{
public:
    PerspectiveProjection();

    SEAD_RTTI_OVERRIDE(PerspectiveProjection, Projection);

    Type getProjectionType() const override;
    void doUpdateMatrix(Mtx44* mtx) const override;
    void doScreenPosToCameraPosTo(Vec3f* vec1, const Vec3f& vec2) const override;

    void set(f32 near, f32 far, f32 angle, f32 aspect);
    void setFovy_(f32 fov);

    f32 mNear;                  // 94
    f32 mFar;                   // 98
    f32 mAngle;                 // 9C
    f32 mFovySin;               // A0
    f32 mFovyCos;               // A4
    f32 mFovyTan;               // A8
    f32 mAspect;                // AC
    Vec2f mOffset;               // B0
};


}
