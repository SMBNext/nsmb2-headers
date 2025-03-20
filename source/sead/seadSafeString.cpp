#include "sead.h"

#include <string.h>
#include <wchar.h>


template<>
void sead::BufferedSafeStringBase<char>::copy(const char* str, s32 maxLen)
{
    if (maxLen < 0 || maxLen > mBufferSize)
        maxLen = mBufferSize;

    strncpy(const_cast<char*>(mStringTop), str, maxLen);
    assureTerminationImpl_();
}

template<>
void sead::BufferedSafeStringBase<wchar_t>::copy(const wchar_t* str, s32 maxLen)
{
    if (maxLen < 0 || maxLen > mBufferSize)
        maxLen = mBufferSize;

    wcsncpy(const_cast<wchar_t*>(mStringTop), str, maxLen);
    assureTerminationImpl_();
}
