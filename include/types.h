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

typedef unsigned char           bit8;
typedef unsigned short          bit16;
typedef unsigned int            bit32;
typedef unsigned long long int  bit64;

typedef int                sptr;
typedef unsigned int       uptr;

typedef struct Offset
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

template<typename T, size_t N>
constexpr u32 countof(const T (&)[N])
{
    return static_cast<u32>(N);
}

#define array_length_assert(arr, size) \
    static_assert(countof(arr) == size, "countof(" #arr ") must be " #size);

#define size_assert(type, size) \
    static_assert(sizeof(type) == size, "sizeof(" #type ") must be " #size);

#define offset_assert(type, member, offset) \
    static_assert(offsetof(type, member) == offset, "offsetof(" #type ", " #member ") must be " #offset);

#define align_assert(type, alignment) \
    static_assert(alignof(type) == alignment, "alignof(" #type ") must be " #alignment)
