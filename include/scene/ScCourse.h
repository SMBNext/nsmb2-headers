#pragma once

#include "gfx/Light.h"
#include "player/PlayerStateData.h"
#include "scene/StateScene.h"

// Size: 0x18C
class ScCourse : public StateScene
{
public:
    ScCourse();
    ~ScCourse() override;

    Result onCreate() override;
    Result onDelete() override;
    Result onExecute() override;
    Result onDraw() override;
    s32 vf40() override;

    DECLARE_STATE_ID(ScCourse, unk1);   // This state is empty and never used
    DECLARE_STATE_ID(ScCourse, unk2);
    DECLARE_STATE_ID(ScCourse, unk3);
    DECLARE_STATE_ID(ScCourse, unk4);
    DECLARE_STATE_ID(ScCourse, unk5);
    DECLARE_STATE_ID(ScCourse, unk6);

    void setCollectionCoinCollected(u8 coinId);
    void giveStockItem(u8 itemId, u8 playerId);
    void setStockItemId(u8 playerId, u8 stockItemId);
    void createBsFogMgr();
    void showCourseClearMessage();
    void enableInventory(bool enabled);
    void deleteLayouts();
    void exitCourse();
    void setupEnvLight();
    void setCollectionCoinStatus(u8 coinId, bool status);
    void createLayouts();
    void doInfoMeterCollectionEffect(u8 coinId);
    void zeroTimer();
    void addCoins(s32 numCoins, s8 playerId);
    void incrementCoinCount(s8 playerId);
    void incrementLifeCount();
    void addScore(s32 numPoints, s8 playerId);
    s8* getCollectionCoinStatus();
    u8 getStockItemId(u8 playerId);
    Vec3f getCollectionCoinPanePos(u8 coinId);
    Vec3f getStockItemPanePos();

    inline static ScCourse* instance()
    {
        return sInstance;
    }

    inline u32 getTicks()
    {
        return mTicks;
    }

    inline PlayerStateData* getPlayerStateData()
    {
        return &mPlayerStateData;
    }

    inline void enable182(bool state)
    {
        _182 = state;
    }

private:

private:
    static ScCourse* sInstance;

    /* 0x03C */  fBase* mBsArea;                                //
    /* 0x040 */  void* mPlaySceneInfoMeter;                     // Lyt::PlaySceneInfoMeter_00*
    /* 0x044 */  void* mPlaySceneInfoMeter2P;                   // Lyt::PlaySceneInfoMeter_2P_00*
    /* 0x048 */  void* mPlaySceneInfoMeterCoin1P;               // Lyt::PlaySceneInfoMeterCoin1P_00*
    /* 0x04C */  void* mPlaySceneInfoMeterCoinStreetPass;       // Lyt::PlaySceneInfoMeterCoinStreetPass_00*
    /* 0x050 */  void* mCreditsFader;                           // FadeFader*
    /* 0x054 */  void* mCourseClearTop;                         // Lyt::CourseClearTop_00*
    /* 0x058 */  void* mCreditsLayout;                          // Lyt::StateLayoutType2_E*
    /* 0x05C */  PlayerStateData mPlayerStateData;              //
    /* 0x0EC */  u32 mTicks;                                    // Ticks in which actors execute
    /* 0x0F0 */  EnvironmentalLightSet mLights[3];              //
    /* 0x174 */  u8 mStockItemIds[2];                           //
    /* 0x176 */  u8 _176[2];                                    // padding
    /* 0x178 */  u32 mTotalCoinCount;                           // Capped at 9999
    /* 0x17C */  u32 mTotalCoinCountUnbounded;                  // Not capped
    /* 0x180 */  bool mDecrementTimer;                          // When set, the timer decrements that frame
    /* 0x181 */  u8 _181;                                       // Set when the Coin Rush time bonus multiplier is above 4
    /* 0x182 */  u8 _182;                                       //
    /* 0x183 */  u8 _183;                                       //
    /* 0x184 */  u8 _184;                                       //
    /* 0x185 */  u8 _185;                                       //
    /* 0x186 */  u8 _186;                                       //
    /* 0x187 */  u8 _187;                                       //
    /* 0x188 */  u32 _188;                                      //
};
