#pragma once

#include "types.h"


namespace nn {

struct Result
{
    Result(u32 code = 0) : code(code) {}

    u32 code;

    bool isFailure() { return (code & 0x80000000) != 0; }
    bool isSuccess() { return !isFailure(); }
};

}
