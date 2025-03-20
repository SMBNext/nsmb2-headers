#pragma once

#include "StateScene.h"

class ScCourse : public StateScene  // size: 0x18C
{
public:
    void zeroTimer();               // 0x0042B304
    void showCourseCompleteMsg();   // 0x00429DD8

    u8 getStockItemId(u8 playerId);
    void setStockItemId(u8 playerId, u8 stockItemId);

    void setCollectionCoinStatus(u8 collectionCoinId, bool status);


    static ScCourse* instance;      // 0x005E7210

    fBase* bsArea;                  // 3C   created and set in onCreate
    u8 _unk40[0xEC-0X40];           // 40
    u32 ticks;                      // EC   counts the ticks in which actors are executed
    u8 _unkF0[0x174-0xF0];          // F0
    u8 stockItemIds[2];             // 174
    u8 _unk176[0x18C-0x176];        // 176
};
