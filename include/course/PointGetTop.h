#pragma once

#include "effect/Effect.h"
#include "gfx/M2d.h"
#include "math/Vec.h"
#include "state/FStateID.h"
#include "state/FStateMgr.h"
#include "types.h"


// Size: 0x284
class PointGetTop
{
public:
    enum DisplayType : u32
    {
        DISPLAY_100_POINTS = 0,
        DISPLAY_200_POINTS = 1,
        DISPLAY_400_POINTS = 2,
        DISPLAY_800_POINTS = 3,
        DISPLAY_1000_POINTS = 4,
        DISPLAY_2000_POINTS = 5,
        DISPLAY_4000_POINTS = 6,
        DISPLAY_8000_POINTS = 7,
        DISPLAY_RED_1 = 8,
        DISPLAY_RED_2 = 9,
        DISPLAY_RED_3 = 10,
        DISPLAY_RED_4 = 11,
        DISPLAY_RED_5 = 12,
        DISPLAY_RED_6 = 13,
        DISPLAY_RED_7 = 14,
        DISPLAY_RED_8 = 15,
        DISPLAY_1UP = 16,
        DISPLAY_2UP = 17,
        DISPLAY_3UP = 18,
        DISPLAY_4UP = 19,
        DISPLAY_8UP = 20,
        DISPLAY_COINS_5 = 21,
        DISPLAY_COINS_10 = 22,
        DISPLAY_COINS_15 = 23,
        DISPLAY_COINS_20 = 24,
        DISPLAY_COINS_30 = 25,
        DISPLAY_COINS_40 = 26,
        DISPLAY_COINS_50 = 27,
        DISPLAY_COINS_100 = 28,
        DISPLAY_TIMER_10 = 29,
        DISPLAY_TIMER_50 = 30,
        DISPLAY_TIMER_100 = 31,
        DISPLAY_TIMER_150 = 32,
        DISPLAY_TIMER_200 = 33,
        DISPLAY_X2 = 34,

    };

    enum class TextBoxId : u32
    {
        T_M100_00       = 0,
        T_M1000_00      = 1,
        T_M1UP_00       = 2,
        T_RedCoin_00    = 3,
        T_Coin_00       = 4,
        T_Timer_00      = 5,
        T_X2_00         = 6,
    };

    enum class PaneId : u32
    {
        N_RedCoin_00    = 0,
        N_Coin_00       = 1,
        N_Mario_00      = 2,
        N_Timer_00      = 3,
        N_X2_00         = 4,
    };

    enum class GroupId : u32
    {
        G_Out_00        = 0,
    };

    enum class AnimId : u32
    {
        Out = 0,
        In  = 1,
    };

public:
    PointGetTop();
    virtual ~PointGetTop();

    DECLARE_STATE_ID(PointGetTop, Show);
    DECLARE_STATE_ID(PointGetTop, Rise);
    DECLARE_STATE_ID(PointGetTop, Hold);
    DECLARE_STATE_ID(PointGetTop, Visible);
    DECLARE_STATE_ID(PointGetTop, Appear);
    DECLARE_STATE_ID(PointGetTop, Disappear);
    DECLARE_STATE_ID(PointGetTop, Idle);

    void build();
    void update();
    void draw();
    void reset();
    void show(const Vec3f& position, u32 type, const u8& playerId);
    void setPosition(const Vec3f& position);
    void disappear();
    bool isIdle();
    void updatePosition();
    void updatePulse();
    void createX2Effect();

public:
    /* 0x004 */  FStateMgr<PointGetTop> stateMgr;   //
    /* 0x028 */  m2d::EmbedLayout_c layout;         //
    /* 0x144 */  nw::lyt::TextBox* textBoxes[7];    //
    /* 0x160 */  nw::lyt::Pane* panes[5];           //
    /* 0x174 */  nw::lyt::Group* groups[1];         //
    /* 0x178 */  m2d::Anm_c anims[2];               //
    /* 0x1C8 */  Vec3f position;                    //
    /* 0x1D4 */  f32 _1D4;                          //
    /* 0x1D8 */  f32 riseSpeed;                     //
    /* 0x1DC */  f32 _1DC;                          //
    /* 0x1E0 */  f32 riseSlowdown;                  //
    /* 0x1E4 */  f32 _1E4;                          //
    /* 0x1E8 */  f32 riseOffset;                    //
    /* 0x1EC */  Vec2f baseScale;                   //
    /* 0x1F4 */  f32 _1F4;                          //
    /* 0x1F8 */  f32 _1F8;                          //
    /* 0x1FC */  Vec2f pulseScale;                  //
    /* 0x204 */  f32 maxY;                          //
    /* 0x208 */  DisplayType type;                  //
    /* 0x20C */  s32 holdTimer;                     //
    /* 0x210 */  s32 holdFrames;                    //
    /* 0x214 */  u32 playerId;                      //
    /* 0x218 */  s32 pulseTimer;                    //
    /* 0x21C */  u8 _21C[4];                        //
    /* 0x220 */  TextBoxId textBoxId;               //
    /* 0x224 */  bool enableDraw;                   //
    /* 0x225 */  bool inUse;                        //
    /* 0x226 */  bool isRedCoin;                    //
    /* 0x227 */  bool isPulseShrinking;             //
    /* 0x228 */  LevelEffect effect;                //
};

size_assert(PointGetTop, 0x284);
