#pragma once

#include "sead/seadVector.h"

namespace sead {

template <typename T>
class BoundBox2
{
public:
    using Vec2 = Vector2<T>;

public:
    BoundBox2() { setUndef(); }
    BoundBox2(T x0, T y0, T x1, T y1) { set(x0, y0, x1, y1); }
    BoundBox2(const Vec2& min, const Vec2& max) : mMin(min), mMax(max) {}

    T getSizeX() const { return mMax.x - mMin.x; }
    T getSizeY() const { return mMax.y - mMin.y; }

    T getHalfSizeX() const { return (mMax.x - mMin.x) / 2.0f; }
    T getHalfSizeY() const { return (mMax.y - mMin.y) / 2.0f; }

    const Vec2& getMin() const { return mMin; }
    const Vec2& getMax() const { return mMax; }

    Vec2 getTL() const { return mMin; }
    Vec2 getTR() const { return Vec2(mMax.x, mMin.y); }
    Vec2 getBL() const { return Vec2(mMin.x, mMax.y); }
    Vec2 getBR() const { return mMax; }

    Vec2 getCenter() const;
    void getCenter(Vec2* p) const;
    bool isUndef() const;
    bool isInside(const Vec2& p) const;

    void setUndef();
    void set(T x0, T y0, T x1, T y1);
    void set(const Vec2& min, const Vec2& max);
    void setMin(const Vec2& min);
    void setMax(const Vec2& max);
    void setFromCenterAndXY(T centerX, T centerY, T sizeX, T sizeY);
    void setFromCornerAndXY(T cornerX, T cornerY, T sizeX, T sizeY);
    void setFromCenterAndXY(const Vec2& center, T sizeX, T sizeY)
    {
        setFromCenterAndXY(center.x, center.y, sizeX, sizeY);
    }
    void setFromCornerAndXY(const Vec2& corner, T sizeX, T sizeY);
    void offset(T dx, T dy);
    void offset(const Vec2& dv);
    void scaleX(T sx);
    void scaleY(T sy);

    // Custom - for convenience
    BoundBox2(T x) { set(x, x, x, x); }

    void scale(T s) { scaleX(s); scaleY(s); };
    void padX(T s) { mMin.x -= s; mMax.x += s; }
    void padY(T s) { mMin.y -= s; mMax.y += s; }
    void pad(T s) { padX(s); padY(s); };
    bool intersects(const sead::BoundBox2<T>& box);

private:
    Vec2 mMin;
    Vec2 mMax;

    static const BoundBox2<T> cUndefined;
};


template <typename T>
class BoundBox3
{
public:
    using Vec3 = Vector3<T>;

public:
    BoundBox3() { setUndef(); }
    BoundBox3(T x0, T y0, T z0, T x1, T y1, T z1) { set(x0, y0, z0, x1, y1, z1); }
    BoundBox3(const Vec3& min, const Vec3& max) { set(min, max); }

    T getSizeX() const { return mMax.x - mMin.x; }
    T getSizeY() const { return mMax.y - mMin.y; }
    T getSizeZ() const { return mMax.z - mMin.z; }

    T getHalfSizeX() const { return (mMax.x - mMin.x) / 2.0f; }
    T getHalfSizeY() const { return (mMax.y - mMin.y) / 2.0f; }
    T getHalfSizeZ() const { return (mMax.z - mMin.z) / 2.0f; }

    const Vec3& getMin() const { return mMin; }
    const Vec3& getMax() const { return mMax; }

    Vec3 getCenter() const;
    void getCenter(Vec3* p) const;
    bool isUndef() const;
    bool isInside(const Vec3& p) const;

    void setUndef();
    void set(T x0, T y0, T z0, T x1, T y1, T z1);
    void set(const Vec3& min, const Vec3& max);
    void setMin(const Vec3& min);
    void setMax(const Vec3& max);
    void offset(T dx, T dy, T dz);
    void offset(const Vec3& dv);
    void scaleX(T sx);
    void scaleY(T sy);
    void scaleZ(T sz);

    // Custom - for convenience
    BoundBox3(T x) { set(x, x, x, x, x, x); }

    void scale(T s) { scaleX(s); scaleY(s); scaleZ(s); }
    void padX(T s) { mMin.x -= s; mMax.x += s; }
    void padY(T s) { mMin.y -= s; mMax.y += s; }
    void padZ(T s) { mMin.z -= s; mMax.z += s; }
    void pad(T s) { padX(s); padY(s); padZ(s); };
    bool intersects(const sead::BoundBox3<T>& box);

private:
    Vec3 mMin;
    Vec3 mMax;

    static const BoundBox3<T> cUndefined;
};

typedef BoundBox2<f32> BoundBox2f;
typedef BoundBox3<f32> BoundBox3f;

}


#define SEAD_MATH_BOUND_BOX_H_
#include "sead/seadBoundBox.hpp"
#undef SEAD_MATH_BOUND_BOX_H_