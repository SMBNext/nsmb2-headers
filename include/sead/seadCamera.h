#pragma once

#include "seadProjection.h"
#include "math/Mtx34.h"


namespace sead {


class Camera    // size: 0x34
{
public:
    Camera()
        : mMatrix(Mtx34::ident) { }

    virtual void* getRuntimeTypeInfo() const;
    virtual void doUpdateMatrix(Mtx34* dst) const = 0;

    Mtx34 mMatrix;  // 4

    void worldPosToCameraPosByMatrix(Vec3f* dst, const Vec3f& world_pos) const;
};


class LookAtCamera : public Camera          // size: 0x58
{
public:
    LookAtCamera()
        : mPos(0.0f, 0.0f, 1.0f), mAt(0.0f, 0.0f, 0.0f), mUp(0.0f, 1.0f, 0.0f) { }

    virtual void* getRuntimeTypeInfo() const override;
    virtual void doUpdateMatrix(Mtx34* dst) const override;

    Vec3f mPos;  // 34   Inited to (0.0f, 0.0f, 1.0f)
    Vec3f mAt;   // 40   Inited to (0.0f, 0.0f, 0.0f)
    Vec3f mUp;   // 4C   Inited to (0.0f, 1.0f, 0.0f)
};


class OrthoCamera : public LookAtCamera     // size: 0x58
{
public:
    OrthoCamera();
    OrthoCamera(const OrthoProjection& proj);
    OrthoCamera(const Vec2f& center, f32 distance);
};


}
