#pragma once

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef NULL
#define NULL 0
#endif

typedef unsigned int size_t;

int vsnprintf(char* buffer, size_t n, const char* format, va_list arg);
int snprintf(char* buffer, size_t n, const char* format, ...);

#ifdef __cplusplus
}
#endif
