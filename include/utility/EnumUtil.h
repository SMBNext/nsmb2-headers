#pragma once

#define ENUM_CLASS_ENABLE_FLAGS(ENUM, BASE_TYPE)                    \
inline constexpr ENUM operator|(ENUM a, ENUM b)                     \
{                                                                   \
    return static_cast<ENUM>(                                       \
        static_cast<BASE_TYPE>(a) | static_cast<BASE_TYPE>(b));     \
}                                                                   \
                                                                    \
inline constexpr ENUM operator&(ENUM a, ENUM b)                     \
{                                                                   \
    return static_cast<ENUM>(                                       \
        static_cast<BASE_TYPE>(a) & static_cast<BASE_TYPE>(b));     \
}                                                                   \
                                                                    \
inline constexpr ENUM operator^(ENUM a, ENUM b)                     \
{                                                                   \
    return static_cast<ENUM>(                                       \
        static_cast<BASE_TYPE>(a) ^ static_cast<BASE_TYPE>(b));     \
}                                                                   \
                                                                    \
inline constexpr ENUM operator~(ENUM a)                             \
{                                                                   \
    return static_cast<ENUM>(~static_cast<BASE_TYPE>(a));           \
}                                                                   \
                                                                    \
inline constexpr ENUM& operator|=(ENUM& a, ENUM b)                  \
{                                                                   \
    return a = a | b;                                               \
}                                                                   \
                                                                    \
inline constexpr ENUM& operator&=(ENUM& a, ENUM b)                  \
{                                                                   \
    return a = a & b;                                               \
}                                                                   \
                                                                    \
inline constexpr ENUM& operator^=(ENUM& a, ENUM b)                  \
{                                                                   \
    return a = a ^ b;                                               \
}

#define ENUM_CLASS_ENABLE_INCREMENT(ENUM, BASE_TYPE)                \
inline constexpr ENUM& operator++(ENUM& a)                          \
{                                                                   \
    return a = static_cast<ENUM>(static_cast<BASE_TYPE>(a) + 1);    \
}

#define ENUM_CLASS_ENABLE_DECREMENT(ENUM, BASE_TYPE)                \
inline constexpr ENUM& operator--(ENUM& a)                          \
{                                                                   \
    return a = static_cast<ENUM>(static_cast<BASE_TYPE>(a) - 1);    \
}

#define ENUM_CLASS_ENABLE_ARITHMETIC(ENUM, BASE_TYPE)               \
inline constexpr ENUM operator+(ENUM e, int v)                      \
{                                                                   \
    return static_cast<ENUM>(static_cast<BASE_TYPE>(e) + v);        \
}                                                                   \
                                                                    \
inline constexpr ENUM operator-(ENUM e, int v)                      \
{                                                                   \
    return static_cast<ENUM>(static_cast<BASE_TYPE>(e) - v);        \
}

#define ENUM_CLASS_ENABLE_ALL(ENUM, BASE_TYPE)                      \
ENUM_CLASS_ENABLE_INCREMENT(ENUM, BASE_TYPE)                        \
ENUM_CLASS_ENABLE_DECREMENT(ENUM, BASE_TYPE)                        \
ENUM_CLASS_ENABLE_ARITHMETIC(ENUM, BASE_TYPE)
