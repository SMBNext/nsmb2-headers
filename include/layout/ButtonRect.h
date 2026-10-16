#pragma once

#include "gfx/M2d.h"
#include "layout/Layout.h"
#include "state/FStateStateMgr.h"
#include "state/FStateVirtualID.h"
#include "types.h"

#include "sys/LinkedList.h"

// Unsure if named correctly - maybe ButtonPane would be better?

namespace Lyt {
    
// Size: 0x1CC
// Vtable: 0x005C159C
class ButtonRect : public ListNode {

public:
    struct LayoutContext
    {
        nw::lyt::Bounding *mBounding;   // 0x0 - 
        nw::lyt::Group *mGroup;         // 0x4 - 
        u32 mButtonIdx;                 // 0x8 - 

        LayoutContext();
    };

    size_assert(LayoutContext, 0xC);

    static constexpr u32 SOUND_ID_NONE = 0xEEEEEEEE;

public:
    enum Flags
    {
        Flag_Enabled        = 1 << 0, // Button is enabled
        Flag_DecideDone     = 1 << 1, // Set when the Decide animation ends
        Flag_InputEnabled   = 1 << 2, // Button can receive input
    };

    enum AnimId
    {
        Anim_On                 = 0, // Pressed Anim
        Anim_Idle               = 1, // Held Anim
        Anim_Off                = 2, // Released Anim
        Anim_Decide             = 3, // Idle Anim

        Anim_Selected_On        = 4, // Pressed Anim with cursor
        Anim_Selected_Idle      = 5, // Held Anim with cursor
        Anim_Selected_Off       = 6, // Released Anim with cursor
        Anim_Selected_Decide    = 7, // Idle Anim with cursor
        
        Anim_Disabled           = 8, // Disabled Anim

        Anim_Count
    };

    enum CursorState : u8
    {
        CursorState_Hidden  = 0,
        CursorState_Visible = 1,
    };

    enum NeighborDirection
    {
        Neighbor_Left   = 0,
        Neighbor_Right  = 1,
        
        Neighbor_Top    = 2,
        Neighbor_Bottom = 3,

        Neighbor_Count
    };
    
public:
    // Address C1: 0x0038BE74
    ButtonRect();

    // Address D1: 0x0038BF70
    virtual ~ButtonRect();

    // Deleted
    virtual void vf8();

    DECLARE_STATE_VIRTUAL_ID_BASE(ButtonRect, On);          //
    DECLARE_STATE_VIRTUAL_ID_BASE(ButtonRect, Idle);        //
    DECLARE_STATE_VIRTUAL_ID_BASE(ButtonRect, Off);         //
    DECLARE_STATE_VIRTUAL_ID_BASE(ButtonRect, Normal);      //
    DECLARE_STATE_VIRTUAL_ID_BASE(ButtonRect, Decide);      //
    DECLARE_STATE_VIRTUAL_ID_BASE(ButtonRect, Disabled);    // - Makes the button grayed out and not pressable

    // Address: 0x0038B750
    // Sets the visual state of the button and unbinds the animation
    void setVisual(u32 animIdx, bool isReversed);

    // Address: 0x0038B804
    void setup(m2d::EmbedLayout_c* layout,
        nw::lyt::AnimTransform* on, nw::lyt::AnimTransform* idle, nw::lyt::AnimTransform* off,
        nw::lyt::AnimTransform* decide, nw::lyt::AnimTransform* selectedOn, nw::lyt::AnimTransform* selectedIdle,
        nw::lyt::AnimTransform* selectedOff, nw::lyt::AnimTransform* selectedDecide, nw::lyt::AnimTransform* disabled
    );

    // Address: 0x0038BA50
    void setNeighbor(NeighborDirection neighborDir, ButtonRect* button);
    
    // Address: 0x0038BC04
    // Sets the button to state "On"
    void setButtonOn(CursorState cursorState);

    // Address: 0x0038BC2C
    // Sets the button to state "Off"
    void setButtonOff(CursorState cursorState);
    
    // Address: 0x0038BC94
    // Sets the button to state either "Disabled" or "Normal"
    void setDisabled(bool isDisabled, bool isForced);
    
    // Address: 0x0038BCE4
    // Sets the button to state "Normal"
    void setButtonNormal(CursorState cursorState);
    
    // Address: 0x0038BD18
    void setLayoutContext(const LayoutContext& context);
    
    // Address: 0x0038BD50
    bool isTouched();
    
    // Address: 0x0038BDA8
    // Sets the button to state "Decide"
    void setButtonDecide(CursorState cursorState);

    // Address: 0x0038BDD0
    void update();

    // Address: 0x0038BDD8
    // Sets the anim to use for playback
    void setAnim(u32 animIdx, bool isReversed);

    inline void setPadFlags(sead::Controller::PadFlag padFlags) { mPadFlags = padFlags; }
    inline void setSoundID(u32 soundID) { mSoundID = soundID; }

private:
    FStateStateMgr<ButtonRect> mStateMgr;                       // 0x00C
    LayoutContext mLayoutContext;                               // 0x034
    ButtonRect* mNeighbors[NeighborDirection::Neighbor_Count];  // 0x040
    sead::Controller::PadFlag mPadFlags;                        // 0x050
    m2d::EmbedLayout_c* mEmbedLayout;                           // 0x054
    m2d::Anm_c mAnims[AnimId::Anim_Count];                      // 0x058
    u32 mSoundID;                                               // 0x1C0 - Init to 0xEEEEEEEE (no sound)
    CursorState mCurrCursorState;                               // 0x1C4 - The current cursor state
    CursorState mNextCursorState;                               // 0x1C5 - The cursor state to transition to
    u32 mFlags;                                                 // 0x1C8
};

size_assert(ButtonRect, 0x1CC);

} // namespace Lyt