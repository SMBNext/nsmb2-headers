#pragma once

#ifdef __cplusplus
extern "C" {
#endif

int atoi(const char* str);
long strtol(const char* str, char** strEnd, int base);

#ifdef __cplusplus
}
#endif
