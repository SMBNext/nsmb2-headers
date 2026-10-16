#include "math/Interpolation.h"

#include "Common.h"

bool directedSmoothRotation(s32& rotation, const s32& destination, const s32& amount)
{
    if (rotation == destination || amount == 0)
        return true;

    s32 newRotation = rotation + amount;
    s32 difference = destination - rotation;

    // Check if we're moving in the correct direction
    if ((amount > 0 && difference < 0) || (amount < 0 && difference > 0))
    {
        rotation = newRotation;
        return false;
    }

    // Prevent overshoot
    if ((amount > 0 && difference <= amount) || (amount < 0 && difference >= amount))
    {
        rotation = destination;
        return true;
    }

    rotation = newRotation;
    return false;
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
            speed *= -1;
        
        if (speed < 0)
            value = Mathi::max(target, value + speed);
        else
            value = Mathi::min(target, value + speed);
    }

    return (value == target);
}

bool moveValueTowardsTarget(f32& value, const f32& target, f32 speed, f32 epsilon)
{
    if (Mathf::abs(target - value) > epsilon)
    {
        if ((target < value && speed > 0.0f) || (value < target && speed < 0.0f))
            speed *= -1.0f;
        
        if (speed < 0.0f)
            value = Mathf::max(target, value + speed);
        else
            value = Mathf::min(target, value + speed);
    }
    else
        value = target;

    return Mathf::abs(target - value) <= epsilon;
}

bool moveValueTowardsTarget(Vec2f& value, const Vec2f& target, const Vec2f& speed, f32 epsilon)
{
    bool xComplete = moveValueTowardsTarget(value.x, target.x, speed.x, epsilon);
    bool yComplete = moveValueTowardsTarget(value.y, target.y, speed.y, epsilon);
    return xComplete && yComplete;
}

bool moveValueTowardsTarget(Vec3f& value, const Vec3f& target, const Vec3f& speed, f32 epsilon)
{
    bool xComplete = moveValueTowardsTarget(value.x, target.x, speed.x, epsilon);
    bool yComplete = moveValueTowardsTarget(value.y, target.y, speed.y, epsilon);
    bool zComplete = moveValueTowardsTarget(value.z, target.z, speed.z, epsilon);

    return xComplete && yComplete && zComplete;
}
