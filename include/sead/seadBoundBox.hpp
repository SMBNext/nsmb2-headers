#pragma once

#ifndef SEAD_MATH_BOUND_BOX_H_
#include "sead/seadBoundBox.h"
#endif

namespace sead
{
template <typename T>
inline Vector2<T> BoundBox2<T>::getCenter() const
{
    return Vector2<T>((min.x + max.x) / 2.0f, (min.y + max.y) / 2.0f);
}

template <typename T>
inline void BoundBox2<T>::getCenter(Vec2* center) const
{
    center->set((min.x + max.x) / 2.0f, (min.y + max.y) / 2.0f);
}

template <typename T>
inline bool BoundBox2<T>::isUndef() const
{
    return min.x > max.x || min.y > max.y;
}

template <typename T>
inline bool BoundBox2<T>::isInside(const Vec2& p) const
{
    return min.x <= p.x && p.x <= max.x && min.y <= p.y && p.y <= max.y;
}

template <typename T>
inline void BoundBox2<T>::setUndef()
{
    min.set(__FLT_MAX__);
    max.set(-__FLT_MAX__);
}

template <typename T>
inline void BoundBox2<T>::set(T x0, T y0, T x1, T y1)
{
    if (x0 < x1)
    {
        min.x = x0;
        max.x = x1;
    }
    else
    {
        min.x = x1;
        max.x = x0;
    }

    if (y0 < y1)
    {
        min.y = y0;
        max.y = y1;
    }
    else
    {
        min.y = y1;
        max.y = y0;
    }
}

template <typename T>
inline void BoundBox2<T>::set(const Vec2& min, const Vec2& max)
{
    this->min = min;
    this->max = max;
}

template <typename T>
inline void BoundBox2<T>::setMin(const Vec2& min)
{
    this->min = min;
}

template <typename T>
inline void BoundBox2<T>::setMax(const Vec2& max)
{
    this->max = max;
}

template <typename T>
inline void BoundBox2<T>::setFromCenterAndXY(T centerX, T centerY, T sizeX, T sizeY)
{
    min.set(centerX - sizeX / 2.0f, centerY - sizeY / 2.0f);
    max.set(centerX + sizeX / 2.0f, centerY + sizeY / 2.0f);
}

template <typename T>
inline void BoundBox2<T>::setFromCornerAndXY(T cornerX, T cornerY, T sizeX, T sizeY)
{
    min.set(cornerX, cornerY);
    max.set(cornerX + sizeX, cornerY + sizeY);
}

template <typename T>
inline void BoundBox2<T>::setFromCornerAndXY(const Vec2& corner, T sizeX, T sizeY)
{
    min.set(corner.x, corner.y);
    max.set(corner.x + sizeX, corner.y + sizeY);
}

template <typename T>
inline void BoundBox2<T>::offset(T dx, T dy)
{
    min.x += dx;
    min.y += dy;
    max.x += dx;
    max.y += dy;
}

template <typename T>
inline void BoundBox2<T>::offset(const Vec2& dv)
{
    offset(dv.x, dv.y);
}

template <typename T>
inline void BoundBox2<T>::scaleX(T sx)
{
    T sizeX = (max.x - min.x) * (sx / 2.0f);
    T centerX = (min.x + max.x) / 2.0f;

    min.x = centerX - sizeX;
    max.x = centerX + sizeX;
}

template <typename T>
inline void BoundBox2<T>::scaleY(T sy)
{
    T sizeY = (max.y - min.y) * (sy / 2.0f);
    T centerY = (min.y + max.y) / 2.0f;

    min.y = centerY - sizeY;
    max.y = centerY + sizeY;
}

template <typename T>
inline Vector3<T> BoundBox3<T>::getCenter() const
{
    return Vector3<T>((min.x + max.x) / 2.0f, (min.y + max.y) / 2.0f, (min.z + max.z) / 2.0f);
}

template <typename T>
inline void BoundBox3<T>::getCenter(Vec3* center) const
{
    center->set((min.x + max.x) / 2.0f, (min.y + max.y) / 2.0f, (min.z + max.z) / 2.0f);
}

template <typename T>
inline bool BoundBox3<T>::isUndef() const
{
    return min.x > max.x || min.y > max.y || min.z > max.z;
}

template <typename T>
inline bool BoundBox3<T>::isInside(const Vec3& p) const
{
    return min.x <= p.x && p.x <= max.x && min.y <= p.y && p.y <= max.y && min.z <= p.z &&
           p.z <= max.z;
}

template <typename T>
inline void BoundBox3<T>::setUndef()
{
    min.set(__FLT_MAX__);
    max.set(-__FLT_MAX__);
}

template <typename T>
inline void BoundBox3<T>::set(T x0, T y0, T z0, T x1, T y1, T z1)
{
    if (x0 < x1)
    {
        min.x = x0;
        max.x = x1;
    }
    else
    {
        min.x = x1;
        max.x = x0;
    }

    if (y0 < y1)
    {
        min.y = y0;
        max.y = y1;
    }
    else
    {
        min.y = y1;
        max.y = y0;
    }

    if (z0 < z1)
    {
        min.z = z0;
        max.z = z1;
    }
    else
    {
        min.z = z1;
        max.z = z0;
    }
}

template <typename T>
inline void BoundBox3<T>::set(const Vec3& min, const Vec3& max)
{
    this->min = min;
    this->max = max;
}

template <typename T>
inline void BoundBox3<T>::setMin(const Vec3& min)
{
    this->min = min;
}

template <typename T>
inline void BoundBox3<T>::setMax(const Vec3& max)
{
    this->max = max;
}

template <typename T>
inline void BoundBox3<T>::offset(T dx, T dy, T dz)
{
    min.x += dx;
    min.y += dy;
    min.z += dz;
    max.x += dx;
    max.y += dy;
    max.z += dz;
}

template <typename T>
inline void BoundBox3<T>::offset(const Vec3& dv)
{
    offset(dv.x, dv.y, dv.z);
}

template <typename T>
inline void BoundBox3<T>::scaleX(T sx)
{
    T sizeX = (max.x - min.x) * (sx / 2.0f);
    T centerX = (min.x + max.x) / 2.0f;

    min.x = centerX - sizeX;
    max.x = centerX + sizeX;
}

template <typename T>
inline void BoundBox3<T>::scaleY(T sy)
{
    T sizeY = (max.y - min.y) * (sy / 2.0f);
    T centerY = (min.y + max.y) / 2.0f;

    min.y = centerY - sizeY;
    max.y = centerY + sizeY;
}

template <typename T>
inline void BoundBox3<T>::scaleZ(T sz)
{
    T sizeZ = (max.z - min.z) * (sz / 2.0f);
    T centerZ = (min.z + max.z) / 2.0f;

    min.z = centerZ - sizeZ;
    max.z = centerZ + sizeZ;
}

template <typename T>
inline bool BoundBox2<T>::intersects(const BoundBox2<T>& box)
{
    return (min.x < box.max.x && max.x > box.min.x && min.y < box.max.y && max.y > box.min.y);
}

template <typename T>
inline bool BoundBox3<T>::intersects(const BoundBox3<T>& box)
{
    return (min.x < box.max.x && max.x > box.min.x &&
            min.y < box.max.y && max.y > box.min.y &&
            min.z < box.max.z && max.z > box.min.z);
}

}
