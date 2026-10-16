#pragma once

#include "clib/math.h"
#include "math/NumericLimits.h"

#ifndef SEAD_MATHCALCCOMMON_H_
#include "sead/seadMathCalcCommon.h"
#endif

namespace sead {

template <typename T>
inline T
MathCalcCommon<T>::sqrt(T t)
{
    return sqrtf(t);
}

template <typename T>
inline T
MathCalcCommon<T>::rsqrt(T t)
{
    return 1 / sqrtf(t);
}

template <typename T>
inline T
MathCalcCommon<T>::pow(T x, T y)
{
    return powf(x, y);
}

template <typename T>
inline T
MathCalcCommon<T>::sin(T t)
{
    return sinf(t);
}

template <typename T>
inline T
MathCalcCommon<T>::cos(T t)
{
    return cosf(t);
}

template <typename T>
inline T
MathCalcCommon<T>::tan(T t)
{
    return tanf(t);
}

// template <typename T>
// inline T
// MathCalcCommon<T>::asin(T s)
// {
//     return std::asin(s);
// }

template <typename T>
inline T
MathCalcCommon<T>::acos(T c)
{
    return acosf(c);
}

template <typename T>
inline T
MathCalcCommon<T>::atan(T t)
{
    return atanf(t);
}

template <typename T>
inline T
MathCalcCommon<T>::atan2(T y, T x)
{
    return atan2f(y, x);
}

template <>
inline f32
MathCalcCommon<f32>::sinIdx(s32 idx)
{
    u32 index = (idx >> 24) & 0xff;
    u32 rest = idx & 0xffffff;

    return cSinCosTbl[index].sin_val + cSinCosTbl[index].sin_delta * rest / 0x1000000;
}

template <>
inline f32
MathCalcCommon<f32>::cosIdx(s32 idx)
{
    u32 index = (idx >> 24) & 0xff;
    u32 rest = idx & 0xffffff;

    return cSinCosTbl[index].cos_val + cSinCosTbl[index].cos_delta * rest / 0x1000000;
}

template <>
inline f32
MathCalcCommon<f32>::tanIdx(s32 idx)
{
    u32 index = (idx >> 24) & 0xff;
    f32 rest = static_cast<f32>(idx & 0xffffff) / 0x1000000;
    const SinCosSample& sample = cSinCosTbl[index];

    return (sample.sin_val + sample.sin_delta * rest) / (sample.cos_val + sample.cos_delta * rest);
}

template <>
inline s32
MathCalcCommon<f32>::asinIdx(f32 s)
{
    const f32 rsqrt_2 = 0.7071067690849304f; // rsqrt(2)

    if (s >= 0)
    {
        if (s > rsqrt_2)
            return 0x40000000 - atanIdx_(sqrt(1 - s * s) / s);

        else
            return atanIdx_(s / sqrt(1 - s * s));
    }
    else
    {
        if (s < -rsqrt_2)
            return 0xC0000000 + atanIdx_(-sqrt(1 - s * s) / s);

        else
            return -atanIdx_(-s / sqrt(1 - s * s));
    }
}

template <>
inline s32
MathCalcCommon<f32>::acosIdx(f32 c)
{
    const f32 rsqrt_2 = 0.7071067690849304f; // rsqrt(2)

    if (c >= 0)
    {
        if (c > rsqrt_2)
            return atanIdx_(sqrt(1 - c * c) / c);

        else
            return 0x40000000 - atanIdx_(c / sqrt(1 - c * c));
    }
    else
    {
        if (c < -rsqrt_2)
            return 0x80000000 - atanIdx_(-sqrt(1 - c * c) / c);

        else
            return 0x40000000 + atanIdx_(-c / sqrt(1 - c * c));
    }
}

template <>
inline s32
MathCalcCommon<f32>::atanIdx(f32 t)
{
    if (t >= 0)
    {
        if (t > 1)
            return 0x40000000 - atanIdx_(1 / t);

        else
            return atanIdx_(t);
    }
    else
    {
        if (t < -1)
            return 0xC0000000 + atanIdx_(-1 / t);

        else
            return -atanIdx_(-t);
    }
}

template <>
inline s32
MathCalcCommon<f32>::atan2Idx(f32 y, f32 x)
{
    if (x == 0 && y == 0)
        return 0;

    if (x >= 0)
    {
        if (y >= 0)
        {
            if (x >= y)
                return atanIdx_(y / x);

            else
                return 0x40000000 - atanIdx_(x / y);
        }
        else
        {
            if (x >= -y)
                return -atanIdx_(-y / x);

            else
                return 0xC0000000 + atanIdx_(x / -y);
        }
    }
    else
    {
        if (y >= 0)
        {
            if (-x >= y)
                return 0x80000000 - atanIdx_(y / -x);

            else
                return 0x40000000 + atanIdx_(-x / y);
        }
        else
        {
            if (x <= y)
                return 0x80000000 + atanIdx_(y / x);

            else
                return 0xC0000000 - atanIdx_(x / y);
        }
    }
}

template <>
inline void
MathCalcCommon<f32>::sinCosIdx(f32* p_sin, f32* p_cos, s32 idx)
{
    u32 index = (idx >> 24) & 0xff;
    f32 rest = static_cast<f32>(idx & 0xffffff) / 0x1000000;
    const SinCosSample& sample = cSinCosTbl[index];

    *p_sin = sample.sin_val + sample.sin_delta * rest;
    *p_cos = sample.cos_val + sample.cos_delta * rest;
}

// template <typename T>
// inline T
// MathCalcCommon<T>::exp(T t)
// {
//     return std::exp(t);
// }

// template <typename T>
// inline T
// MathCalcCommon<T>::log(T t)
// {
//     return std::log(t);
// }

// template <typename T>
// inline T
// MathCalcCommon<T>::log2(T t)
// {
//     return std::log2(t);
// }

// template <typename T>
// inline T
// MathCalcCommon<T>::log10(T t)
// {
//     return std::log10(t);
// }

template <typename T>
inline T
MathCalcCommon<T>::minNumber()
{
    return NumericLimits<T>::min();
}

template <typename T>
inline T
MathCalcCommon<T>::maxNumber()
{
    return NumericLimits<T>::max();
}

template <>
inline float
MathCalcCommon<float>::minNumber()
{
    return NumericLimits<float>::lowest();
}

template <>
inline float
MathCalcCommon<float>::maxNumber()
{
    return NumericLimits<float>::max();
}

template <>
inline double
MathCalcCommon<double>::minNumber()
{
    return NumericLimits<double>::lowest();
}

template <>
inline double
MathCalcCommon<double>::maxNumber()
{
    return NumericLimits<double>::max();
}

template <>
inline long double
MathCalcCommon<long double>::minNumber()
{
    return NumericLimits<long double>::lowest();
}

template <>
inline long double
MathCalcCommon<long double>::maxNumber()
{
    return NumericLimits<long double>::max();
}

template <typename T>
inline T
MathCalcCommon<T>::infinity()
{
    return NumericLimits<T>::infinity();
}

template <>
inline f32
MathCalcCommon<f32>::nan()
{
    static const u32 float_nan_binary = 0x7FFFFFFF;

    union { const u32* ui; f32* f; } bit_cast = { .ui = &float_nan_binary };
    return *bit_cast.f;
}

template <>
inline f64
MathCalcCommon<f64>::nan()
{
    static const u64 double_nan_binary = 0x7FFFFFFFFFFFFFFF;

    union { const u64* ui; f64* f; } bit_cast = { .ui = &double_nan_binary };
    return *bit_cast.f;
}

template <typename T>
inline T
MathCalcCommon<T>::epsilon()
{
    return NumericLimits<T>::epsilon();
}

template <>
inline constexpr f32
MathCalcCommon<f32>::abs(f32 t)
{
    return __builtin_fabsf(t);
}

template <>
inline constexpr s32
MathCalcCommon<s32>::abs(s32 t)
{
    return (t ^ t >> 31) - (t >> 31);
}

template <>
inline constexpr u32
MathCalcCommon<u32>::abs(u32 t)
{
    return t;
}

template <typename T>
inline s32 MathCalcCommon<T>::round(T val)
{
    return static_cast<s32>(val >= 0 ? val + 0.5f : val - 0.5f);
}

template <typename T>
inline s32 
MathCalcCommon<T>::roundOff(T val)
{
    return floor(val + 0.5f);
}

template <>
inline s32
MathCalcCommon<s32>::roundOff(s32 val)
{
    return val;
}

template <typename T>
inline s32
MathCalcCommon<T>::floor(T val)
{
    int i = static_cast<int>(val);
    return (val < 0 && val != i) ? static_cast<T>(i - 1) : static_cast<T>(i);
}

template <>
inline s32
MathCalcCommon<s32>::floor(s32 val)
{
    return val;
}

template <typename T>
inline s32
MathCalcCommon<T>::ceil(T val)
{
    int i = static_cast<int>(val);
    return (val > 0 && val != i) ? static_cast<T>(i + 1) : static_cast<T>(i);
}

template <>
inline s32
MathCalcCommon<s32>::ceil(s32 val)
{
    return val;
}

template <>
inline s32
MathCalcCommon<s32>::roundUpPow2(s32 val, s32 base)
{
    return (val + (base - 1u)) & ~(base - 1u);
}

template <>
inline s32
MathCalcCommon<u32>::roundUpPow2(u32 val, s32 base)
{
    return (val + (base - 1u)) & ~(base - 1u);
}

template <typename T>
inline T
MathCalcCommon<T>::clampMax(T val, T max_)
{
    if (val > max_) return max_;

    return val;
}

template <typename T>
inline T
MathCalcCommon<T>::clampMin(T val, T min_)
{
    if (val < min_) return min_;

    return val;
}

template <typename T>
inline T
MathCalcCommon<T>::clamp2(T min_, T val, T max_)
{
    if      (val < min_) val = min_;
    else if (val > max_) val = max_;

    return val;
}

template <>
inline s32
MathCalcCommon<s32>::gcd(s32 m, s32 n)
{
    if (m == 0) return n;
    if (n == 0) return m;

    u8 shift = 0;
    while (((m | n) & 1) == 0)
    {
        m >>= 1;
        n >>= 1;
        shift++;
    }

    while ((m & 1) == 0)
        m >>= 1;

    while (n != 0)
    {
        while ((n & 1) == 0)
            n >>= 1;

        if (m > n)
        {
            s32 temp = m;
            m = n;
            n = temp;
        }

        n = n - m;
    }

    return m << shift;
}

template <typename T>
inline T
MathCalcCommon<T>::gcd(T m, T n)
{
    return T(MathCalcCommon<s32>::gcd(s32(m), s32(n)));
}

template <>
inline s32
MathCalcCommon<s32>::lcm(s32 m, s32 n)
{
    if (m == 0 || n == 0)
        return 0;

    s32 gcd = MathCalcCommon<s32>::gcd(m > 0 ? m : -m, n > 0 ? n : -n);

    s32 div = m;
    s32 quotient = 0;

    while (div >= gcd)
    {
        div -= gcd;
        quotient++;
    }

    s32 result = 0;
    for (s32 i = 0; i < quotient; i++)
        result += n;

    return result > 0 ? result : -result;
}

template <typename T>
inline T
MathCalcCommon<T>::lcm(T m, T n)
{
    return T(MathCalcCommon<s32>::lcm(s32(m), s32(n)));
}

} // namespace sead