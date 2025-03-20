#pragma once

#include "types.h"

namespace sead {


template<typename T>
class SafeStringBase
{
public:
    SafeStringBase(const T* cstr = &cNullChar) : mStringTop(cstr) { }
    virtual ~SafeStringBase() { }
    virtual void assureTerminationImpl_() const { }

    inline const T* cstr() const
    {
        assureTerminationImpl_();
        return mStringTop;
    }

    s32 findIndex(const SafeStringBase<T>& token) const;
    s32 rfindIndex(const SafeStringBase<T>& token) const;
    bool isEqual(const SafeStringBase<T>& rhs) const;
    s32 comparen(const SafeStringBase<T>& rhs, s32 n) const;
    const T& at(s32 idx) const;

    static const T cNullChar;

protected:
    const T* mStringTop;
};


template<typename T>
class BufferedSafeStringBase : public SafeStringBase<T>
{
public:
    BufferedSafeStringBase(T* buffer, s32 size)
        : SafeStringBase<T>(buffer)
    {
        this->mBufferSize = size;
        assureTerminationImpl_();
    }

    ~BufferedSafeStringBase() { }

    void assureTerminationImpl_() const override
    {
        const_cast<T*>(this->mStringTop)[mBufferSize-1] = 0;
    }

    s32 format(const T* fmt, ...);
    void copy(const T* str, s32 maxLen = -1);

    s32 mBufferSize;
};


template<typename T, s32 L>
class FixedSafeStringBase : public BufferedSafeStringBase<T>
{
public:
    FixedSafeStringBase()
        : BufferedSafeStringBase<T>(mBuffer, L)
    {
        const_cast<T*>(this->mStringTop)[0] = 0;
    }

    FixedSafeStringBase(const T* str)
        : BufferedSafeStringBase<T>(mBuffer, L)
    {
        this->copy(str);
    }

    ~FixedSafeStringBase() { }

    T mBuffer[L];
};


using SafeString = SafeStringBase<char>;
using WSafeString = SafeStringBase<wchar_t>;

using BufferedSafeString = BufferedSafeStringBase<char>;
using WBufferedSafeString = BufferedSafeStringBase<wchar_t>;

template<s32 L>
using FixedSafeString = FixedSafeStringBase<char, L>;
template<s32 L>
using WFixedSafeString = FixedSafeStringBase<wchar_t, L>;

}
