#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned int    size_t;

void* memcpy(void* dest, const void* src, size_t num);
void* memclr(void* ptr, size_t num);
void* memset(void* ptr, int c, size_t n);

int strcmp(const char* str1, const char* str2);
int strncmp(const char* str1, const char* str2, size_t n);
char* strcpy(char* dst, const char* src);
char* strncpy(char* dst, const char* src, size_t n);
int strlen(const char* str);

#ifdef __cplusplus
}
#endif
