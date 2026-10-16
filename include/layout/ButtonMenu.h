#pragma once

#include "gfx/M2d.h"
#include "layout/Layout.h"
#include "state/FStateStateMgr.h"
#include "types.h"
#include "layout/ButtonRect.h"
#include "sys/LinkedList.h"

#include "sead/seadSafeString.h"


namespace Lyt {

// Size: 0x1E0
// Vtable: 0x005C1570
class ButtonMenu : public IntrusiveList
{
public:
    struct LayoutConfig
    {
        void *mRes;                                                 // 0x00 - LayoutRes pointer
        m2d::EmbedLayout_c *mEmbedLayout;                           // 0x04
        const sead::SafeString* animNames[ButtonRect::Anim_Count];  // 0x08

        LayoutConfig();
    };

    size_assert(LayoutConfig, 0x2C);

    enum Flags
    {
        Flag_Decided            = 1 << 0,   // Set when a button is decided
        Flag_DecideDone         = 1 << 1,   // Set when the decided button's Decide animation ends
        Flag_SelectionDirty     = 1 << 2,   // Set when selection changes
        Flag_ActiveButtonHeld   = 1 << 3,   // Set when active button interacted (Hold A/Touch/Hold Hotkey)
    };
    
public:
    // Address C1: 0x0038B61C
    ButtonMenu();

    // Address D1: 0x0038B6F8
    virtual ~ButtonMenu();

    DECLARE_STATE_VIRTUAL_ID_BASE(ButtonMenu, CheckInput);  //
    DECLARE_STATE_VIRTUAL_ID_BASE(ButtonMenu, Decided);     //

    // Address: 0x0038A7D0
    void highlightSelection();
    
    // Address: 0x0038AA64
    void validateSelection();

    // Address: 0x0038ABB8
    s32 getSelectedButtonIndex();
    
    // Address: 0x0038AE30
    s32 sub_38AE30();
    
    // Address: 0x0038B13C
    void selectDefaultButton();
    
    // Address: 0x0038B1DC
    void clearSelection();
    
    // Address: 0x0038B274
    void initialize(const LayoutConfig& config);
    
    // Address: 0x0038B438
    void update();
    
    // Address: 0x0047EF0C
    void appendButton(ButtonRect* button);

    // Address: 0x0038B34C
    void onButtonPressed(ButtonRect::CursorState cursorState);

private:
    // Address: 0x0038A73C
    bool isPadTrig(sead::Controller::PadFlag padFlag);

    // Address: 0x0038A87C
    bool processTouch();

    // Address: 0x0038AB60
    void setupButton(ButtonRect* button);

    // Address: 0x0038ABCC
    void handleNavigation();

    // Address: 0x0038AEB0
    ButtonRect* getFirstEnabledButton();

    // Address: 0x0038AEF4
    bool processHotkeys();

    // Address: 0x0038B540
    bool isPadHold(sead::Controller::PadFlag padFlag);
    
public:
    FStateStateMgr<ButtonMenu> mStateMgr;                   // 0x00C
    void* mRes;                                             // 0x034 - A LayoutRes pointer
    m2d::EmbedLayout_c* mEmbedLayout;                       // 0x038
    sead::SafeString* mAnimNames[ButtonRect::Anim_Count];   // 0x03C
    m2d::EmbedLayout_c* mEmbedLayout2;                      // 0x060 - Unsure - asigned to the same value as mEmbedLayout
    m2d::Anm_c mAnims[ButtonRect::Anim_Count];              // 0x064
    ButtonRect* mActiveButton;                              // 0x1CC - The button that is visually selected
    ButtonRect* mTouchedButton;                             // 0x1D0 - The button currently being touched
    ButtonRect* mNavButton;                                 // 0x1D4 - The button used as the origin when navigating left/right/up/down
    ButtonRect* mDefaultButton;                             // 0x1D8 - The button that is selected by default when the menu is first shown
    u32 mFlags;                                             // 0x1DC
};

size_assert(ButtonMenu, 0x1E0);
    
} // namespace Lyt
