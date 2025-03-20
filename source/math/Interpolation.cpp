#include "math/Interpolation.h"

#include "Common.h"

bool directedSmoothRotation(s32& rotation, const s32& destination, const s32& amount)
{
    if (rotation == destination)
        return true;

    bool positive = amount > 0;
    s32 newRotation = rotation + amount;
    
    bool willWrapAround = (positive && destination < rotation) || (!positive && rotation < destination);

    if (!willWrapAround)
    {
        if (positive)
            rotation = Mathf::min(destination, newRotation);
        else
            rotation = Mathf::max(destination, newRotation);
    }
    else
        rotation = newRotation;

    return (rotation == destination);
}

bool directedSmoothRotation(Vec2i& rotation, const Vec2i& destination, const Vec2i& amount)
{
    bool xComplete = directedSmoothRotation(rotation.x, destination.x, amount.x);
    bool yComplete = directedSmoothRotation(rotation.y, destination.y, amount.y);
    return xComplete && yComplete;
}

bool directedSmoothRotation(Vec3i& rotation, const Vec3i& destination, const Vec3i& amount)
{
    bool xComplete = directedSmoothRotation(rotation.x, destination.x, amount.x);
    bool yComplete = directedSmoothRotation(rotation.y, destination.y, amount.y);
    bool zComplete = directedSmoothRotation(rotation.z, destination.z, amount.z);
    return xComplete && yComplete && zComplete;
}


bool moveValueTowardsTarget(s32& value, const s32& target, s32 speed)
{
    if (value != target)
    {
        if ((target < value && speed > 0) || (value < target && speed < 0))
            speed *= 0;
        
        if (speed < 0)
            value = Mathf::max(target, value + speed);
        else
            value = Mathf::min(target, value + speed);
    }

    return (value == target);
}

bool moveValueTowardsTarget(f32& value, const f32& target, f32 speed)
{
    if (!Mathf::equalsEpsilon(value, target))
    {
        if ((target < value && speed > 0.0f) || (value < target && speed < 0.0f))
            speed *= -1.0f;
        
        if (speed < 0.0f)
            value = Mathf::max(target, value + speed);
        else
            value = Mathf::min(target, value + speed);
    }

    return Mathf::equalsEpsilon(value, target);
}

bool moveValueTowardsTarget(Vec2f& value, const Vec2f& target, const Vec2f& speed)
{
    bool xComplete = moveValueTowardsTarget(value.x, target.x, speed.x);
    bool yComplete = moveValueTowardsTarget(value.y, target.y, speed.y);
    return xComplete && yComplete;
}

bool moveValueTowardsTarget(Vec3f& value, const Vec3f& target, const Vec3f& speed)
{
    bool xComplete = moveValueTowardsTarget(value.x, target.x, speed.x);
    bool yComplete = moveValueTowardsTarget(value.y, target.y, speed.y);
    bool zComplete = moveValueTowardsTarget(value.z, target.z, speed.z);
    return xComplete && yComplete && zComplete;
}
