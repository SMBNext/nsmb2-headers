#include "types.h"

template <typename T>
struct NumericLimits;

template <>
struct NumericLimits<s8> {
    static constexpr s8 min() { return -__INT8_MAX__ - 1; }
    static constexpr s8 max() { return __INT8_MAX__; }
    static constexpr s8 lowest() { return min(); }
    static constexpr s8 epsilon() { return 1; }
    static constexpr s8 infinity() { return 0; }
    static constexpr int digits() { return 8; }
    static constexpr bool is_signed = true;
    static constexpr bool has_infinity = false;
};

template <>
struct NumericLimits<u8> {
    static constexpr u8 min() { return 0; }
    static constexpr u8 max() { return __UINT8_MAX__; }
    static constexpr u8 lowest() { return min(); }
    static constexpr u8 epsilon() { return 1; }
    static constexpr u8 infinity() { return 0; }
    static constexpr int digits() { return 8; }
    static constexpr bool is_signed = false;
    static constexpr bool has_infinity = false;
};

template <>
struct NumericLimits<s16> {
    static constexpr s16 min() { return -__INT16_MAX__ - 1; }
    static constexpr s16 max() { return __INT16_MAX__; }
    static constexpr s16 lowest() { return min(); }
    static constexpr s16 epsilon() { return 1; }
    static constexpr s16 infinity() { return 0; }
    static constexpr int digits() { return 16; }
    static constexpr bool is_signed = true;
    static constexpr bool has_infinity = false;
};

template <>
struct NumericLimits<u16> {
    static constexpr u16 min() { return 0; }
    static constexpr u16 max() { return __UINT16_MAX__; }
    static constexpr u16 lowest() { return min(); }
    static constexpr u16 epsilon() { return 1; }
    static constexpr u16 infinity() { return 0; }
    static constexpr int digits() { return 16; }
    static constexpr bool is_signed = false;
    static constexpr bool has_infinity = false;
};

template <>
struct NumericLimits<s32> {
    static constexpr s32 min() { return -__INT32_MAX__ - 1; }
    static constexpr s32 max() { return __INT32_MAX__; }
    static constexpr s32 lowest() { return min(); }
    static constexpr s32 epsilon() { return 1; }
    static constexpr s32 infinity() { return 0; }
    static constexpr int digits() { return 32; }
    static constexpr bool is_signed = true;
    static constexpr bool has_infinity = false;
};

template <>
struct NumericLimits<u32> {
    static constexpr u32 min() { return 0; }
    static constexpr u32 max() { return __UINT32_MAX__; }
    static constexpr u32 lowest() { return min(); }
    static constexpr u32 epsilon() { return 1; }
    static constexpr u32 infinity() { return 0; }
    static constexpr int digits() { return 32; }
    static constexpr bool is_signed = false;
    static constexpr bool has_infinity = false;
};

template <>
struct NumericLimits<s64> {
    static constexpr s64 min() { return -__INT64_MAX__ - 1; }
    static constexpr s64 max() { return __INT64_MAX__; }
    static constexpr s64 lowest() { return min(); }
    static constexpr s64 epsilon() { return 1; }
    static constexpr s64 infinity() { return 0; }
    static constexpr int digits() { return 64; }
    static constexpr bool is_signed = true;
    static constexpr bool has_infinity = false;
};

template <>
struct NumericLimits<u64> {
    static constexpr u64 min() { return 0; }
    static constexpr u64 max() { return __UINT64_MAX__; }
    static constexpr u64 lowest() { return min(); }
    static constexpr u64 epsilon() { return 1; }
    static constexpr u64 infinity() { return 0; }
    static constexpr int digits() { return 64; }
    static constexpr bool is_signed = false;
    static constexpr bool has_infinity = false;
};

template <>
struct NumericLimits<float> {
    static constexpr float min() { return __FLT_MIN__; }
    static constexpr float max() { return __FLT_MAX__; }
    static constexpr float lowest() { return -__FLT_MAX__; }
    static constexpr float epsilon() { return __FLT_EPSILON__; }
    static constexpr float infinity() {
        union { u32 i; float f; } u = { 0x7F800000 };
        return u.f;
    }
    static constexpr int digits() { return __FLT_MANT_DIG__; }
    static constexpr bool is_signed = true;
    
};

template <>
struct NumericLimits<double> {
    static constexpr double min() { return __DBL_MIN__; }
    static constexpr double max() { return __DBL_MAX__; }
    static constexpr double lowest() { return -__DBL_MAX__; }
    static constexpr double epsilon() { return __DBL_EPSILON__; }
        static constexpr long double infinity() {
        union { u64 i; double d; } u = { 0x7FF0000000000000 };
        return u.d;
    }
    static constexpr int digits() { return __DBL_MANT_DIG__; }
    static constexpr bool is_signed = true;
    static constexpr bool has_infinity = true;
};

template <>
struct NumericLimits<long double> {
    static constexpr long double min() { return __LDBL_MIN__; }
    static constexpr long double max() { return __LDBL_MAX__; }
    static constexpr long double lowest() { return -__LDBL_MAX__; }
    static constexpr long double epsilon() { return __LDBL_EPSILON__; }
    static constexpr long double infinity() {
        union { u64 i; double d; } u = { 0x7FF0000000000000 };
        return u.d;
    }
    static constexpr int digits() { return __LDBL_MANT_DIG__; }
    static constexpr bool is_signed = true;
    static constexpr bool has_infinity = true;
};