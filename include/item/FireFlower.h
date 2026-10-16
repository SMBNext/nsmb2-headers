#pragma once

#include "item/ItemActorBase.h"

class FireFlower : public ItemActorBase
{
public:
    DECLARE_PROC_GLUE_CODE(FireFlower);

    FireFlower();                             // 0x001D2F1C
    ~FireFlower();                            // 0x001D2F34

    Result onCreate() override;                  // 0x001D2E98
    Result onExecute() override;                 // 0x001D2EDC

    void powActivated() override;             // 0x001D2B64

    void createModel() override;              // 0x001D2974
    void decideStateIdle() override;          // 0x001D2E70
    void setAnimOutUp() override;        // 0x001D2CA0
    void setAnimOutDown() override;      // 0x001D2D84
    void setAnimWait() override;         // 0x001D28A0
    void setAnimWaitBubble() override;        // 0x001D2BD0
    void setAnimOutJump() override;      // 0x001D27D0
    bool checkCollection() override;          // 0x001D2B94
    void setLiquidGravity() override;                    // 0x001D2E84
};
