#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned int size_t;

int atoi(const char* str);
long strtol(const char* str, char** strEnd, int base);
long long strtoll(const char* str, char** strEnd, int base);

size_t mbstowcs(wchar_t* dst, const char* src, size_t len);

#ifdef __cplusplus
}
#endif
