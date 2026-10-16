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
    BoundBox2(const Vec2& min, const Vec2& max) : min(min), max(max) {}

    T getSizeX() const { return max.x - min.x; }
    T getSizeY() const { return max.y - min.y; }

    T getHalfSizeX() const { return (max.x - min.x) / 2.0f; }
    T getHalfSizeY() const { return (max.y - min.y) / 2.0f; }

    const Vec2& getMin() const { return min; }
    const Vec2& getMax() const { return max; }

    Vec2 getTL() const { return min; }
    Vec2 getTR() const { return Vec2(max.x, min.y); }
    Vec2 getBL() const { return Vec2(min.x, max.y); }
    Vec2 getBR() const { return max; }

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

    bool intersects(const sead::BoundBox2<T>& box);

    Vec2 min;
    Vec2 max;

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

    T getSizeX() const { return max.x - min.x; }
    T getSizeY() const { return max.y - min.y; }
    T getSizeZ() const { return max.z - min.z; }

    T getHalfSizeX() const { return (max.x - min.x) / 2.0f; }
    T getHalfSizeY() const { return (max.y - min.y) / 2.0f; }
    T getHalfSizeZ() const { return (max.z - min.z) / 2.0f; }

    const Vec3& getMin() const { return min; }
    const Vec3& getMax() const { return max; }

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

    bool intersects(const sead::BoundBox3<T>& box);

    Vec3 min;
    Vec3 max;

    static const BoundBox3<T> cUndefined;
};

typedef BoundBox2<f32> BoundBox2f;
typedef BoundBox3<f32> BoundBox3f;

}


#define SEAD_MATH_BOUND_BOX_H_
#include "sead/seadBoundBox.hpp"
#undef SEAD_MATH_BOUND_BOX_H_