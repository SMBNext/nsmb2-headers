#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned int    size_t;
typedef signed short    wchar_t;    /* fix this */

wchar_t* wcscpy(wchar_t* dst, const wchar_t* src);
wchar_t* wcsncpy(wchar_t* dst, const wchar_t* src, size_t n);
size_t wcslen(const wchar_t* wcs);
int wcsncmp(const wchar_t *s1, const wchar_t *s2, size_t n);

#ifdef __cplusplus
}
#endif
