#pragma once

#include <stddef.h>
#include <stdarg.h>

typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;
typedef unsigned long long  u64;

typedef signed char         s8;
typedef signed short        s16;
typedef signed int          s32;
typedef signed long long    s64;

typedef char                char8;
typedef wchar_t             char16;

typedef float               f32;
typedef double              f64;


enum Direction : u8
{
    RIGHT = 0,
    LEFT  = 1,
    UP    = 2,
    DOWN  = 3,
};


typedef struct
{
    s32 offset;

    void* ptr()
    {
        if (offset == 0) return nullptr;
        u8* ret = reinterpret_cast<u8*>(this);
        return (ret + offset);
    }

} Offset;

template<typename T>
struct TOffset : public Offset
{
    T* ptr()
    {
        return reinterpret_cast<T*>(Offset::ptr());
    }

    T& operator*()
    {
        return *ptr();
    }

    T* operator->()
    {
        return ptr();
    }
};

#define array_length(arr) \
    (sizeof(arr) / sizeof((arr)[0]))

#define array_length_assert(arr, size) \
    static_assert(array_length(arr) == size, "array_length(" #arr ") must be " #size);

#define size_assert(type, size) \
    static_assert(sizeof(type) == size, "sizeof(" #type ") must be " #size);

#define offset_assert(type, member, offset) \
    static_assert(offsetof(type, member) == offset, "offsetof(" #type ", " #member ") must be " #offset);
