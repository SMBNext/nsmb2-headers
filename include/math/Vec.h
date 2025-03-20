#pragma once

#include "types.h"

#include "sead/seadVector.h"

using Vec2f = sead::Vector2<f32>;
using Vec2d = sead::Vector2<f64>;
using Vec2u = sead::Vector2<u32>;
using Vec2i = sead::Vector2<s32>;

using Vec3f = sead::Vector3<f32>;
using Vec3d = sead::Vector3<f64>;
using Vec3u = sead::Vector3<u32>;
using Vec3i = sead::Vector3<s32>;

using Vec4f = sead::Vector4<f32>;
using Vec4d = sead::Vector4<f64>;
using Vec4u = sead::Vector4<u32>;
using Vec4i = sead::Vector4<s32>;

inline f32 calcAngleCos(const Vec2f& a, const Vec2f& b)
{
    return a.dot(b) / (a.length() * b.length());
}

inline f32 calcAngle(const Vec2f& a, const Vec2f& b)
{
    return acosf(calcAngleCos(a, b));
}