#pragma once

#include "types.h"
#include "nw/ut/Inline.h"

namespace nw { namespace ut {

typedef u32 Size;
typedef u32 Length;
typedef u32 ResTypeInfo;

struct BinString
{
    s32 offset;

    inline const char* to_ptr() const
    {
        const u8* p = reinterpret_cast<const u8*>(this);
        if ( offset != 0 )
            return reinterpret_cast<const char*>(p + offset); 
        else 
            return nullptr;
    }

    inline void set_ptr(const char* ptr)
    {
        if (ptr == nullptr)
            offset = 0;
        else
            offset = GetOffsetFromPtr(this, ptr);
    }

    operator const char*() const { return to_ptr(); }
};

typedef struct Offset
{
    s32 offset;

    static Offset s32_to_ofs(s32 ofs) { return *reinterpret_cast<Offset*>(&ofs); }

    Offset operator=(s32 ofs) { offset = ofs; return *this; }
    operator s32() const { return offset; }
    Offset operator+(s32 ofs) const { return s32_to_ofs(this->offset + ofs); }
    Offset operator-(s32 ofs) const { return s32_to_ofs(this->offset - ofs); }
    Offset operator+=(s32 ofs) { this->offset += ofs; return *this; }
    Offset operator-=(s32 ofs) { this->offset -= ofs; return *this; }

    void set_ptr(const void* ptr)
    {
        ptr == nullptr ? offset = 0 : offset = GetOffsetFromPtr(this, ptr);
    }

    void* to_ptr()
    {
        u8* p = reinterpret_cast<u8*>(this);
        if ( offset != 0 )
            return p + offset;
        else
            return nullptr;
    }

    const void* to_ptr() const
    {
        const u8* p = reinterpret_cast<const u8*>(this);
        if ( offset != 0 )
            return p + offset;
        else
            return nullptr;
    }

    template<typename T>
    inline const T* to_ptr() const { return static_cast<const T*>(to_ptr()); }

    template<typename T>
    inline T* to_ptr() { return static_cast<T*>(to_ptr()); }

    inline void* to_table_ptr() { return to_ptr(); }
    inline const void* to_table_ptr() const { return to_ptr(); }
} Offset;

} // namespace ut    
} // namespace nw
