#pragma once

namespace nw {
namespace snd {
namespace internal {

template<typename TValue, typename TCount>
class MoveValue
{
public:
    void SetTarget(TValue target, TCount frames);

public:
    /* 0x00 */  TValue origin;   //
    /* 0x04 */  TValue target;   //
    /* 0x08 */  TCount frame;    //
    /* 0x0C */  TCount counter;  //
};

} // namespace internal
} // namespace snd
} // namespace nw
