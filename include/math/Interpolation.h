#pragma once

#include "math/Vec.h"

f32 smoothStepTowards(f32& value, f32 target, f32 scaleFactor, f32 maxStep, f32 minStep);

// Convenience methods

bool directedSmoothRotation(s32& rotation, const s32& destination, const s32& amount);
bool directedSmoothRotation(Vec2i& rotation, const Vec2i& destination, const Vec2i& amount);
bool directedSmoothRotation(Vec3i& rotation, const Vec3i& destination, const Vec3i& amount);

bool moveValueTowardsTarget(s32& value, const s32& target, s32 speed);
bool moveValueTowardsTarget(f32& value, const f32& target, f32 speed);
bool moveValueTowardsTarget(Vec2f& value, const Vec2f& target, const Vec2f& speed);
bool moveValueTowardsTarget(Vec3f& value, const Vec3f& target, const Vec3f& speed);
