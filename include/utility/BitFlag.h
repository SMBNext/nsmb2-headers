#pragma once

#include "types.h"

template <u32 BitCount>
class BitFlag
{
private:
    static constexpr u32 WordCount = (BitCount + 31) / 32;

public:
    BitFlag()
    {
        reset();
    }

    BitFlag(u32 flag)
    {
        reset();
        enable(flag);
    }
    void enable(u32 flag)
    {
        mBitArray[flag / 32] |= (u32{1} << (flag % 32));
    }

    void clear(u32 flag)
    {
        mBitArray[flag / 32] &= ~(u32{1} << (flag % 32));
    }

    void set(u32 flag, bool enabled)
    {
        enabled ? enable(flag) : clear(flag);
    }

    void reset()
    {
        for (auto& w : mBitArray)
        {
            w = 0;
        }
    }

    bool isSet(u32 flag) const
    {
        return (mBitArray[flag / 32] & (u32{1} << (flag % 32))) != 0;
    }

    bool any() const
    {
        for (const auto& w : mBitArray)
        {
            if (w != 0) return true;
        }
        return false;
    }

    bool any(BitFlag other) const
    {
        for (u32 i = 0; i < WordCount; ++i)
        {
            if ((mBitArray[i] & other.mBitArray[i]) != 0)
            {
                return true;
            }
        }
        return false;
    }

    BitFlag& operator|=(BitFlag rhs)
    {
        for (u32 i = 0; i < WordCount; ++i)
        {
            mBitArray[i] |= rhs.mBitArray[i];
        }
        return *this;
    }

    BitFlag& operator&=(BitFlag rhs)
    {
        for (u32 i = 0; i < WordCount; ++i)
        {
            mBitArray[i] &= rhs.mBitArray[i];
        }
        return *this;
    }

    friend BitFlag operator|(BitFlag lhs, BitFlag rhs)
    {
        lhs |= rhs;
        return lhs;
    }

    friend BitFlag operator&(BitFlag lhs, BitFlag rhs)
    {
        lhs &= rhs;
        return lhs;
    }

    friend bool operator==(BitFlag lhs, BitFlag rhs)
    {
        for (u32 i = 0; i < WordCount; ++i)
        {
            if (lhs.mBitArray[i] != rhs.mBitArray[i])
            {
                return false;
            }
        }
        return true;
    }

    friend bool operator!=(BitFlag lhs, BitFlag rhs)
    {
        return !(lhs == rhs);
    }

    explicit operator bool() const
    {
        return any();
    }

    const u32* data() const
    {
        return mBitArray;
    }

    u32* data()
    {
        return mBitArray;
    }

    static constexpr u32 bitCount()
    {
        return BitCount;
    }

    static constexpr u32 wordCount()
    {
        return WordCount;
    }

private:
    u32 mBitArray[WordCount]{};
};