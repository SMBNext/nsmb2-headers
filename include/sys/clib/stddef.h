#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#ifndef NULL
#define NULL 0
#endif

#ifndef offsetof
#define offsetof(t, d) __builtin_offsetof(t, d)
#endif

typedef unsigned int    size_t;
typedef int             ptrdiff_t;

#ifdef __cplusplus
}
#endif
