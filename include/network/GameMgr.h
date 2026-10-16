#pragma once

#include "types.h"

namespace net {
namespace game {

class Mgr
{
public:
    static bool isCoopSession();    // 0x001BF430
    static bool playerIsGuest();    // 0x001C5248

};

} // namespace game
} // namespace net
