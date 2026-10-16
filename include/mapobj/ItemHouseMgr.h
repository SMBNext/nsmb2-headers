#include "actors/ActorMultiState.h"

class ItemHouseMgr : public ActorMultiState
{
public:
    static bool isItemHouseUnk();    // 0x00258448

    u32 itemCount;
    u32 _FF0;
    u8 _FF4[4];
};

size_assert(ItemHouseMgr, 0xFF8);
