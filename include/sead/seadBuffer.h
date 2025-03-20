#pragma once

#include "types.h"


namespace sead {

template <typename T>
class Buffer
{
public:
    Buffer() : mSize(0), mBuffer(nullptr) { }

    T* get(s32 i)
    {
        if (i < mSize && i >= 0)
            return &mBuffer[i];
        return nullptr;
    }

    const T* get(s32 i) const
    {
        if (i < mSize && i >= 0)
            return &mBuffer[i];
        return nullptr;
    }

    T& operator[](s32 i)
    {
        return *get(i);
    }

    const T& operator[](s32 i) const
    {
        return *get(i);
    }

    s32 size() const
    {
        return mSize;
    }

private:
    s32 mSize;
    T* mBuffer;
};

}
