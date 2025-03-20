#pragma once

#include "nw/types.h"

namespace nw {
namespace anim {


class AnimResult
{
public:
    AnimResult() :
        m_Flags(0) {}

    virtual ~AnimResult() {}

private:
    bit32 m_Flags;
    f32 m_ValueBuf[16];
};

} // namespace anim
} // namespace nw