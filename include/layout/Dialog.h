#pragma once

#include "layout/StateLayout.h"
#include "sead/heap/seadExpHeap.h"
#include "sead/seadSafeString.h"
#include "state/FStateVirtualID.h"
#include "types.h"

namespace Lyt {

// Size: 0x3C
// Vtable: 0x005C17A4
class Dialog : private StateLayout {
public:
    // Address: 0x0038F53C
    Dialog();

    // D1: 0x0038F57C
    // D0: 0x0038F568
    ~Dialog() override;

    // Address: 0x0038F358
    void changeState(const StateID& stateID) override;
    
    DECLARE_STATE_VIRTUAL_ID_BASE(Dialog, 674);
    DECLARE_STATE_VIRTUAL_ID_BASE(Dialog, 675);
    DECLARE_STATE_VIRTUAL_ID_BASE(Dialog, 676);
    
    // Pure virtual
    virtual void initialize() = 0;

    // Pure virtual
    virtual u8 execute() = 0;

    // Pure virtual
    virtual bool isVisible() = 0;
    
    // Address: 0x004A5CB8
    virtual s32 vf40();

    // Address: 0x0038F2F4
    sead::ExpHeap* createDialogHeap(const sead::SafeString& name, u32 size = 0x8000);

private:
    u8 mExecResult;         // 0x2C - value is used as return value of execute (dialog State? idk)
    StateID *mUnkStateID;   // 0x30
    u32 mFlags;             // 0x34
    u32 _38;                // 0x38
};

size_assert(Dialog, 0x3C);
    
} // namespace Lyt