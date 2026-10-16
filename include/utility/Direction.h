#pragma once

#include "math/RNG.h"
#include "sead/container/seadSafeArray.h"
#include "sead/seadSystem.h"
#include "types.h"
#include "utility/EnumUtil.h"

enum class Direction : u8
{
    cRight      = 0,    // Right direction.
    cLeft       = 1,    // Left direction.    
    cUp         = 2,    // Up direction.
    cDown       = 3,    // Down direction.

    cDirNumX    = 2,    // Number of directions in the X axis.
    cDirNumY    = 2,    // Number of directions in the Y axis.
    cDirNum     = 4,    // Number of directions in total.
};

static constexpr u8 cDirectionCountX = static_cast<u8>(Direction::cDirNumX);
static constexpr u8 cDirectionCountY = static_cast<u8>(Direction::cDirNumY);
static constexpr u8 cDirectionCount = static_cast<u8>(Direction::cDirNum);

inline Direction& operator++(Direction& dir)
{
    SEAD_ASSERT(static_cast<u8>(dir) < static_cast<u8>(Direction::cDirNum));
    return dir = static_cast<Direction>(static_cast<u8>(dir) + 1);
}

inline Direction& operator--(Direction& dir)
{
    SEAD_ASSERT(static_cast<u8>(dir) > 0);
    return dir = static_cast<Direction>(static_cast<u8>(dir) - 1);
}

// Returns the inverse direction of `dir`.
inline constexpr Direction inverseDirection(Direction dir)
{
    return
        dir == Direction::cRight ? Direction::cLeft  :
        dir == Direction::cLeft  ? Direction::cRight :
        dir == Direction::cUp    ? Direction::cDown  :
        dir == Direction::cDown  ? Direction::cUp    :
        dir;
}

// Inverts the direction `dir`.
inline void invertDirection(Direction& dir)
{
    dir = inverseDirection(dir);
}

// Returns `true` if a `dir` is horizontal.
inline constexpr bool isDirectionHorizontal(Direction dir)
{
    return dir == Direction::cLeft || dir == Direction::cRight;
}

// Returns `true` if a `dir` is vertical.
inline constexpr bool isDirectionVertical(Direction dir)
{
    return dir == Direction::cUp || dir == Direction::cDown;
}

// Returns the horizontal direction from `from` to `to`.
inline Direction directionToPointH(f32 from, f32 to)
{
    return (to > from) ? Direction::cLeft : Direction::cRight;
}

// Returns the vertical direction from `from` to `to`.
inline Direction directionToPointV(f32 from, f32 to)
{
    return (to > from) ? Direction::cDown : Direction::cUp;
}

// Returns the scalar value of the direction `dir`.
inline constexpr f32 directionScalar(Direction dir)
{
    return 
        dir == Direction::cLeft  ? -1.0f :
        dir == Direction::cRight ? 1.0f  :
        dir == Direction::cUp    ? -1.0f :
        dir == Direction::cDown  ? 1.0f  :
        0.0f;
}

// Returns the scalar value of the x-axis direction `dir`.
inline constexpr f32 directionScalarX(Direction dir)
{
    return
        dir == Direction::cLeft  ? -1.0f :
        dir == Direction::cRight ?  1.0f :
        0.0f; 
}

// Returns the scalar value of the y-axis direction `dir`.
inline constexpr f32 directionScalarY(Direction dir)
{
    return
        dir == Direction::cUp   ? -1.0f :
        dir == Direction::cDown ?  1.0f :
        0.0f;
}

// Returns a random direction.
inline Direction randomDirection()
{
    return static_cast<Direction>(randU32(cDirectionCount));
}

// Returns a random x-axis direction.
inline Direction randDirectionX()
{
    return randBool() ? Direction::cLeft : Direction::cRight;
}

// Returns a random y-axis direction.
inline Direction randDirectionY()
{
    return randBool() ? Direction::cUp : Direction::cDown;
}

template <typename T>
class DirectionArray : public sead::UnsafeArray<T, cDirectionCount>
{
public:
    template <typename... Args>
    DirectionArray(const Args&... args) : sead::UnsafeArray<T, cDirectionCount>(args...) {}
    
    T& operator[](Direction dir)
    {
        return sead::UnsafeArray<T, cDirectionCount>::operator[](static_cast<s32>(dir));
    }

    const T& operator[](Direction dir) const
    {
        return sead::UnsafeArray<T, cDirectionCount>::operator[](static_cast<s32>(dir));
    }
};

template <typename T>
class DirectionArrayX : public sead::UnsafeArray<T, cDirectionCountX>
{
public:
    template <typename... Args>
    DirectionArrayX(const Args&... args) : sead::UnsafeArray<T, cDirectionCountX>(args...) {}
    
    T& operator[](Direction dir)
    {
        SEAD_ASSERT(dir < Direction::cDirNumX);
        return sead::UnsafeArray<T, cDirectionCountX>::operator[](static_cast<s32>(dir));
    }

    const T& operator[](Direction dir) const
    {
        SEAD_ASSERT(dir < Direction::cDirNumX);
        return sead::UnsafeArray<T, cDirectionCountX>::operator[](static_cast<s32>(dir));
    }
};

template <typename T>
class DirectionArrayY : public sead::UnsafeArray<T, cDirectionCountY>
{
public:
    template <typename... Args>
    DirectionArrayY(const Args&... args) : sead::UnsafeArray<T, cDirectionCountY>(args...) {}
    
    T& operator[](Direction dir)
    {
        SEAD_ASSERT(dir >= Direction::cDirNumX && dir < Direction::cDirNum);
        return sead::UnsafeArray<T, cDirectionCountY>::operator[](static_cast<s32>(dir) - 2);
    }

    const T& operator[](Direction dir) const
    {
        SEAD_ASSERT(dir >= Direction::cDirNumX && dir < Direction::cDirNum);
        return sead::UnsafeArray<T, cDirectionCountY>::operator[](static_cast<s32>(dir) - 2);
    }
};

enum class DirectionMask : u8
{
    cNone   = 0,                                        // No direction mask.
    cRight  = 1 << static_cast<u8>(Direction::cRight),  // Right direction mask.
    cLeft   = 1 << static_cast<u8>(Direction::cLeft),   // Left direction mask.
    cUp     = 1 << static_cast<u8>(Direction::cUp),     // Up direction mask.
    cDown   = 1 << static_cast<u8>(Direction::cDown),   // Down direction mask.

    cHorizontal = cRight | cLeft,                       // Horizontal direction mask.
    cVertical   = cUp | cDown,                          // Vertical direction mask.
    cAll        = cHorizontal | cVertical,              // All direction mask.
};

ENUM_CLASS_ENABLE_FLAGS(DirectionMask, u8);
