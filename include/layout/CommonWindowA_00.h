#pragma once

#include "gfx/TagProcessor.h"
#include "layout/ButtonMenu.h"
#include "layout/ButtonRect.h"
#include "layout/Layout.h"
#include "layout/WaitParts_00.h"
#include "state/FStateMgr.h"

namespace Lyt {

// Size: 0x1864
class CommonWindowA_00 : public StateLayoutType1
{
    SEAD_SINGLETON_DISPOSER(CommonWindowA_00);
public:
    enum class BoundingId : u32
    {
        B_OnOff_00 = 0,
        B_OnOff_01 = 1,
        B_OnOff_02 = 2,
        B_OnOff_03 = 3,
        B_OnOff_04 = 4,
        B_OnOff_05 = 5,
        B_OnOff_06 = 6,
        Bounding_Count
    };

    enum class PaneId : u32
    {
        N_InfoParts_00      =  0,
        N_Anim_00           =  1,
        N_BtnAll_00         =  2,
        N_InfoParts_01      =  3,
        N_Anim_01           =  4,
        N_BtnAll_01         =  5,
        N_Btn_00            =  6,
        N_CommonW_00        =  7,
        N_Message4_00       =  8,
        N_BtnAll_02         =  9,
        N_Anim_02           = 10,
        N_InfoParts_02      = 11,
        N_BtnAll_03         = 12,
        N_Anim_03           = 13,
        N_InfoParts_03      = 14,
        N_BtnAll_04         = 15,
        N_Anim_04           = 16,
        N_InfoParts_04      = 17,
        N_BtnAll_05         = 18,
        N_Anim_05           = 19,
        N_InfoParts_05      = 20,
        N_FourButton_00     = 21,
        N_MessageC_00       = 22,
        N_WaitCircle_00     = 23,
        N_InfoParts_06      = 24,
        N_Anim_06           = 25,
        N_AnimY_06          = 26,
        N_BtnAll_06         = 27,
        N_CommonW_01        = 28,
        N_BalloonPosY_00    = 29,
        N_Balloon_00        = 30,
        N_Position_00       = 31,
        N_Position_01       = 32,
        N_TopCircle_00      = 33,
        N_DownCircle_00     = 34,
        N_Position_02       = 35,
        N_Position_03       = 36,
        Pane_Count
    };

    enum class PictureId : u32
    {
        P_FuchiShadow_00    =  0,
        P_BgGra_00_00       =  1,
        P_FuchiShadow_01    =  2,
        P_Yajirushi_06      =  3,
        P_YajirushiS_06     =  4,
        P_HiLight_06        =  5,
        P_PanelL2_06        =  6,
        P_CircleLU_00       =  7,
        P_CircleRU_00       =  8,
        P_CircleLD_00       =  9,
        P_CircleRD_00       = 10,
        P_YellowBase_00     = 11,
        P_BtnL_02           = 12,
        P_BtnR_02           = 13,
        P_BtnC_02           = 14,
        P_BtnL_03           = 15,
        P_BtnR_03           = 16,
        P_BtnC_03           = 17,
        P_BtnL_04           = 18,
        P_BtnR_04           = 19,
        P_BtnC_04           = 20,
        P_BtnL_05           = 21,
        P_BtnR_05           = 22,
        P_BtnC_05           = 23,
        P_PanelL_03         = 24,
        P_BtnL_01           = 25,
        P_BtnC_01           = 26,
        P_BtnR_01           = 27,
        P_Balloon_00        = 28,
        P_BalloonS_00       = 29,
        P_CircleLU_01       = 30,
        P_CircleRU_01       = 31,
        P_CircleLD_01       = 32,
        P_CircleRD_01       = 33,
        Picture_Count
    };

    enum class TextBoxId : u32
    {
        T_BtnB_00       =  0,
        T_BtnBS_00      =  1,
        T_BtnA_00       =  2,
        T_BtnAS_00      =  3,
        T_Message4_00   =  4,
        T_MenuS_02      =  5,
        T_Menu_02       =  6,
        T_MenuS_03      =  7,
        T_Menu_03       =  8,
        T_MenuS_04      =  9,
        T_Menu_04       = 10,
        T_MenuS_05      = 11,
        T_Menu_05       = 12,
        T_MessageC_00   = 13,
        T_Message4S_00  = 14,
        T_messageCS_00  = 15,
        TextBox_Count
    };

    enum class WindowId : u32
    {
        W_Fuchi_00      = 0,
        W_Shadow_00     = 1,
        W_SelectW_02    = 2,
        W_SelectW_03    = 3,
        W_SelectW_04    = 4,
        W_SelectW_05    = 5,
        W_SelectW_00    = 6,
        W_SelectW_01    = 7,
        W_SelectW_09    = 9,
        Window_Count
    };

    enum class GroupId : u32
    {
        G_CommonW_00    =  0,
        G_Parts_00      =  1,
        G_OnOff_00      =  2,
        G_OnOff_01      =  3,
        G_OnOff_02      =  4,
        G_OnOff_03      =  5,
        G_OnOff_04      =  6,
        G_OnOff_05      =  7,
        G_OnOff_06      =  8,
        G_Balloon_00    =  9,
        G_Bln_InOut_00  = 10,
        G_Loop_00       = 11,
        Group_Count
    };

    enum class AnimId : u32
    {
        W_In            =  0,
        Menu4           =  1,
        Menu3           =  2,
        Loop            =  3,
        Menu2           =  4,
        Balloon_In      =  5,
        IdleBalloon     =  6,
        Balloon_Out     =  7,
        Msg1Btn         =  8,
        Msg2Btn         =  9,
        MsgOnly         = 10,
        Msg1BtnL        = 11,
        W_Out           = 12,
        W_BackBtn_In    = 13,
        W_BackBtn_Out   = 14,
        Anim_Count
    };

    enum class Anim2Id : u32
    {
        Ng          = 0,
        On          = 1,
        Idle        = 2,
        Off         = 3,
        T_On        = 4,
        T_Idole     = 5,
        T_Off       = 6,
        Decide      = 7,
        T_Decide    = 8,
        Anim2_Count
    };

    enum class LayoutType : u8
    {
        Menu_4Button    = 0,
        Menu_3Button    = 1,
        Menu_2Button    = 2,
        Msg_2Button     = 3,
        Msg_1Button     = 4,
        Msg_1ButtonLong = 5,
        Msg_WaitCircle  = 6,
        MsgOnly         = 7
    };

public:
    CommonWindowA_00();
    ~CommonWindowA_00() override;

    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(CommonWindowA_00, hidden);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(CommonWindowA_00, appear);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(CommonWindowA_00, visible);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(CommonWindowA_00, disappear);

    void disappear() override;
    void hideLayout() override;

    DECLARE_STATE_VIRTUAL_ID_BASE(CommonWindowA_00, waitCircleIn);
    DECLARE_STATE_VIRTUAL_ID_BASE(CommonWindowA_00, waitCircleOut);
    DECLARE_STATE_VIRTUAL_ID_BASE(CommonWindowA_00, windowIn);
    DECLARE_STATE_VIRTUAL_ID_BASE(CommonWindowA_00, menu4In);
    DECLARE_STATE_VIRTUAL_ID_BASE(CommonWindowA_00, menu3In);
    DECLARE_STATE_VIRTUAL_ID_BASE(CommonWindowA_00, windowLoop);
    DECLARE_STATE_VIRTUAL_ID_BASE(CommonWindowA_00, menu2In);
    DECLARE_STATE_VIRTUAL_ID_BASE(CommonWindowA_00, balloonIn);
    DECLARE_STATE_VIRTUAL_ID_BASE(CommonWindowA_00, balloonIdle);
    DECLARE_STATE_VIRTUAL_ID_BASE(CommonWindowA_00, balloonOut);
    DECLARE_STATE_VIRTUAL_ID_BASE(CommonWindowA_00, msg1In);
    DECLARE_STATE_VIRTUAL_ID_BASE(CommonWindowA_00, msg2In);
    DECLARE_STATE_VIRTUAL_ID_BASE(CommonWindowA_00, msgOnlyIn);
    DECLARE_STATE_VIRTUAL_ID_BASE(CommonWindowA_00, msg1LongIn);
    DECLARE_STATE_VIRTUAL_ID_BASE(CommonWindowA_00, windowOut);
    DECLARE_STATE_VIRTUAL_ID_BASE(CommonWindowA_00, backBtnIn);
    DECLARE_STATE_VIRTUAL_ID_BASE(CommonWindowA_00, backBtnOut);

    void initialize();
    void setText(TextBoxId textBox, const sead::SafeString& msbtFile, const sead::SafeString& translationId, s32 argCount, ...);
    void playAnim(AnimId animId, bool isReversed);
    void setButtonDisabled(TextBoxId textBox, bool isDisabled);
    void setupMenus();
    void setupLayouts();
    TextBoxId getSelectedMenuItem();
    void initTextBoxes();
    void setButtonKeybind(TextBoxId textBox, sead::Controller::PadFlag padFlag);
    void setSelectedButton(TextBoxId textBox);
    void draw();
    void create();
    void update();
    void setLayout(LayoutType layoutType, bool backButtonEnabled = false);
    void setupAnim(AnimId animId, bool isReversed);
    void setupButton(TextBoxId textBoxId, const sead::SafeString& msbtFile, const sead::SafeString& translationId, u32 soundId, s32 argCount, ...);

    // May not belong to this class.
    static void drawInstance();

    inline void setBackgroundDim(bool enabled)
    {
        mBackgroundDim = enabled;
    }

    inline void setBalloonEnabled(bool enabled)
    {
        mBalloonEnabled = enabled;
    }

    inline void set160D(bool enabled)
    {
        _160D = enabled;
    }

private:
    /* 0x003C */  m2d::EmbedLayout_c mEmbedLayout;      //
    /* 0x0158 */  nw::lyt::Bounding* mBoundings[7];     //
    /* 0x0174 */  nw::lyt::Pane* mPanes[37];            //
    /* 0x0208 */  nw::lyt::Picture* mPictures[37];      //
    /* 0x029C */  m2d::TextBox_c mTextBoxes[16];        //
    /* 0x04DC */  nw::lyt::Window* mWindows[9];         //
    /* 0x0500 */  nw::lyt::Group* mGroups[12];          //
    /* 0x0530 */  m2d::Anm_c mAnims[15];                //
    /* 0x0788 */  TagProcessor mTagProcessor;           //
    /* 0x0794 */  ButtonRect mButtons[7];               //
    /* 0x1428 */  ButtonMenu mButtonMenu;               //
    /* 0x1608 */  LayoutType mLayoutType;               //
    /* 0x1609 */  bool mBackButtonEnabled;              //
    /* 0x160A */  bool mBackgroundDim;                  //
    /* 0x160B */  bool mWaitCircleEnabled;              //
    /* 0x160C */  bool mBalloonEnabled;                 //
    /* 0x160D */  u8 _160D;                             //
    /* 0x160E */  u8 _160E[2];                          // padding
    /* 0x1610 */  WaitParts_00 mWaitParts;              //
};

size_assert(CommonWindowA_00, 0x1864);

} // namespace Lyt
