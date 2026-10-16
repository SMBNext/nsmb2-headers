#pragma once

#include "player/PlayerBase.h"
#include "player/PlayerModel.h"

#include "actors/ActorBase.h"
#include "collider/ActorBgCollisionCheck.h"
#include "event/PlayerDeathEvent.h"
#include "event/PlayerStateChangeEvent.h"
#include "player/PlayerEnum.h"
#include "sead/container/seadRingBuffer.h"
#include "sead/heap/seadExpHeap.h"
#include "sound/SoundId.h"
#include "utility/Direction.h"


class PlayerObject : public PlayerBase    // Size: 0x4A78
{
    SEAD_RTTI_OVERRIDE(PlayerObject, PlayerBase);

    static constexpr u32 POWERUP_COUNT = static_cast<u32>(Powerup::COUNT);

public:
    class SizeDefinition
    {
    public:
        class Inner
        {
        public:
            Vec3f _0;
            Vec3f _C;
            Vec3f _18;
        };

        Inner _0[5];
    };

    static sead::SafeString resources[];

    Result onCreate() override;
    Result onDelete() override;
    void postExecute(Result execResult) override;
    bool preDraw() override;
    Result onDraw() override;
    void setPlayerNum(s8 playerNum) override;
    void setCarryFall(ActorBase* actor, s32 a2) override;
    bool isSpinLiftUpEnable() override;
    void setSpinLiftUpActor(ActorBase* actor) override;
    void executeLastAll() override;

    void executeMain() override;
    void updatePowerupRelated() override;
    u8 getSizeType(Powerup powerup) override;
    void vfE8() override;
    f32 vfEC() override;
    void vfF0() override;
    void vfF4() override;
    void clearJumpActionInfo() override;
    f32 vfFC() override;        // returns _473C
    virtual void initCollision(const ActorCollisionCheck::CollisionData& reactInfo, const ActorCollisionCheck::CollisionData& attackInfo) override;
    void vf104() override;
    void vf108() override;
    bool vf10C() override;
    void vf110() override;
    void vf114() override;
    bool vf118() override;
    void vf11C(u32* unk1, u32 unk2, u32 unk3) override;
    void vf120() override;
    void vf124() override;
    void vf128() override;
    void vf12C() override;
    void vf130(u32 unk) override;
    void vf134() override;
    void vf138() override;
    void vf13C() override;
    void vf140() override;
    void vf144(u32 unk) override;
    void vf148() override;
    void vf14C() override;
    void vf150() override;      // nullsub
    void vf154() override;      // nullsub
    void vf158(u32 unk) override;

    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, DemoGoal);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, DemoInDoor);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, DemoOutDoor);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, Down);

    void vf24C() override;
    bool isChange() override;
    bool vf254() override;
    bool vf25C() override;
    bool vf260() override;
    bool vf264() override;
    void vf26C() override;
    bool vf270() override;
    bool isEnableDokanInStatus() override;
    bool vf278(u32 unk) override;
    void vf27C() override;
    bool setJump(f32 jumpSpeed, f32 speedX, bool allowSteer, u32 keyMode, u32 jumpMode, bool unk) override;
    bool _setJump(f32 jumpSpeed, f32 speedX, bool allowSteer, u32 keyMode, u32 jumpMode, bool unk) override;

    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, Walk);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, SideSlide);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, Slip);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, Jump);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, HipAttack);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, Crouch);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, SitJump);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, Fall);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, SlowSwim);      // Use unknown
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, Cloud);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, Swim);

    bool vf360() override;
    void setWaitActionAnim(int blendMode) override;
    void vf368() override;
    void walkActionInit_Wait(u32 blendMode) override;
    void vf370() override;
    void walkActionInit_Move(int blendMode) override;
    void vf378() override;
    bool vf37C() override;
    void vf380() override;
    bool vf384() override;
    void vf388() override;
    void vf38C() override;
    bool vf390() override;
    void vf39C() override;
    void vf3A4() override;
    void vf3A8() override;
    GravityData* getGravityData() override;
    bool isCarry() override;
    bool vf3B4() override;
    bool vf3B8() override;
    bool vf3BC() override;
    void vf3D0() override;
    bool vf3D4() override;
    bool vf3D8() override;
    bool setDamage(ActorBase* other, DamageType type) override;
    bool setForcedDamage(ActorBase* other, DamageType type) override;
    bool vf3E4(u32 unk) override;
    bool vf3E8() override;
    bool setDamage2(ActorBase* other, DamageType type) override;
    void vf3FC() override;
    void vf404() override;
    void vf408() override;
    s8 vf40C() override;
    void vf410() override;
    void vf414() override;
    void vf418() override;
    void vf41C() override;

    void changeInitProc();

    bool checkCanPowerUp(Powerup itemId);

    void setCenterOffset();                             // 0x002683D8
    bool updateChange();                                // 0x0026C9B0
    void calcStarTimer();                               // 0x00265D00
    void sub_26B0E0();                                  // 0x0026B0E0
    void checkSpawnStockItem();                         // 0x00267778
    void calcMegaTimer();                               // 0x002659B0
    void calcTimerProc();                               // 0x00265DE4
    void hatenaCapExec();                               // 0x0026577C
    void sub_264A10();                                  // 0x00264A10
    void setCollisionCheckData();                       // 0x002626B4
    void updateCollisionCheckMega();                    // 0x00263D40
    void clearMegaTimerFlag();                          // 0x00266638
    void setBgCollisionCheckData(int flag);             // 0x0027C30C
    void bgCollisionCrouchRelated();                    // 0x0026E658
    void sub_26B40C();                                  // 0x0026B40C

    void setNormalWalkAnim(int blendMode, f32 frameStep);

    bool isPMeterCharged();                           // 0x0049E008
    bool isPMeterMaxSpeed();                          // 0x0049E39C
    bool canUseStockItem();                           // 0x0049E234
    bool canUseTouchButtons();                        // 0x0049E434
    bool isMoveOntolift();                            // 0x0049DD3C
    void setTurnPower();                              // 0x00265288
    void setWaterWalkFlag();                          // 0x0026AF90

    ActorBase* getRidePlayer();
    void setEatDieHide();                  // Requires putting the player into DemoEatDie using `setDamage()` first
    void setEatDieScreamVoice();           // Requires putting the player into DemoEatDie using `setDamage()` first
    void setPowerupDemo(u8 powerup);
    bool isDemoDokanCannonDone();

    void initPlayerDownCommon();
    void executeState();
    void resetTanukiData();
    void setTanukiTailRotation();
    void releaseCarryActor2(s32 unk);
    void endStar();
    void removeHatenaCap(bool unk1, bool unk2);
    void makeHatenaCapVisible();              // 0x00263C98
    void hideHatenaCap();                     // 0x00264578

    void jumpExec();                              // 0x0026B004
    void jumpExecAir();
    void sub_26D8D4();                          // 0x0026D8D4

    void startJumpAnim(s32 jumpType, s32 blendMode);   // 0x002634A4
    void initTanukiJump();                    // 0x00267904
    void setJumpInfo(PlayerBase::JumpInfo* jumpInfo);    // 0x0027C0E0
    bool sub_274584();                        // 0x00274584
    bool checkCrouch();                       // 0x002689B0

    void selectAction();
    bool setBalloonAction();
    bool setQuakeAction();
    bool setVineAction();
    bool setPoleAction();
    bool setHangAction();
    bool checkWallJump();
    bool setTanukiJumpAction();
    bool setFireBallAction();
    bool setTanukiShakeAction();
    bool spinLiftUp(ActorBase* actor, s32 unk);
    void setSpinLiftUpReserve();
    void releaseCarryActor(ActorBase* heldObject);
    bool setSwimSpeed(f32 speedY, f32 speedX);            // 0x0026518C
    bool setSwimAction();
    bool setTarzanRopeAction();

    inline u8 getPlayerId()
    {
        return (spriteData1 >> 8) & 0xFF;
    }

    DECLARE_STATE_ID(PlayerObject, DemoInJump);
    DECLARE_STATE_ID(PlayerObject, DemoEatDie);
    DECLARE_STATE_ID(PlayerObject, DemoOutRainbow);
    DECLARE_STATE_ID(PlayerObject, DemoDokanCannon);
    DECLARE_STATE_ID(PlayerObject, DemoDown);
    DECLARE_STATE_ID(PlayerObject, DemoFallDown);
    DECLARE_STATE_ID(PlayerObject, DemoFireDown);
    DECLARE_STATE_ID(PlayerObject, DemoInVine);
    DECLARE_STATE_ID(PlayerObject, TanukiJump);
    DECLARE_STATE_ID(PlayerObject, Balloon);
    DECLARE_STATE_ID(PlayerObject, KaniJump);       // Unused, used when jumping from a cliff in NSMBWii/U
    DECLARE_STATE_ID(PlayerObject, Vine);
    DECLARE_STATE_ID(PlayerObject, Hang);
    DECLARE_STATE_ID(PlayerObject, Landing);
    DECLARE_STATE_ID(PlayerObject, Pole);
    DECLARE_STATE_ID(PlayerObject, Quake);
    DECLARE_STATE_ID(PlayerObject, Fire);
    DECLARE_STATE_ID(PlayerObject, Throw);
    DECLARE_STATE_ID(PlayerObject, LiftUp);
    DECLARE_STATE_ID(PlayerObject, WallJump);
    DECLARE_STATE_ID(PlayerObject, None3);
    DECLARE_STATE_ID(PlayerObject, RollSlip);       // Unused, used when throwing players in NSMBWii/U
    DECLARE_STATE_ID(PlayerObject, FlyDamage);
    DECLARE_STATE_ID(PlayerObject, Stone);
    DECLARE_STATE_ID(PlayerObject, ElectricShock);
    DECLARE_STATE_ID(PlayerObject, CannonJump);
    DECLARE_STATE_ID(PlayerObject, CannonWarp);
    DECLARE_STATE_ID(PlayerObject, JumpUnk);
    DECLARE_STATE_ID(PlayerObject, TarzanRope);
    DECLARE_STATE_ID(PlayerObject, None2);
    DECLARE_STATE_ID(PlayerObject, TanukiShake);
    DECLARE_STATE_ID(PlayerObject, HatenaCapGet);
    DECLARE_STATE_ID(PlayerObject, CannonFly);
    DECLARE_STATE_ID(PlayerObject, WallSlide);

    /* 0x4564 */  sead::ExpHeap* flyingMeterHeap;
    /* 0x4568 */  PlayerModelMgr modelMgr;
    /* 0x4570 */  ActorBgCollisionCheck::Sensor bcSensorVine;
    /* 0x457C */  Powerup unkPowerup;
    /* 0x457D */  Powerup targetPowerup;                 // powerup gets set to this one
    /* 0x4580 */  u32 _4580;
    /* 0x4584 */  u32 _4584;
    /* 0x4588 */  ActorCollisionCheck collisionCheckA;
    /* 0x4640 */  ActorCollisionCheck collisionCheckB;
    /* 0x46F8 */  u32 megaTimerFlag;
    /* 0x46FC */  u32 _46FC;
    /* 0x4700 */  u8 _4700;
    /* 0x4704 */  Vec3f entrancePos;                     // init to this->position (may not be vec3f? is handled by fixed point registers...)
    /* 0x4710 */  u32 unkTimer4710;
    /* 0x4714 */  u8 scrollMode;
    /* 0x4715 */  bool isLeader;                         // used in sub_2044E4
    /* 0x4718 */  ActorUniqueID carryActor;
    /* 0x471C */  sead::RingBuffer<ActorUniqueID> carryActorList;
    /* 0x472C */  ActorUniqueID unkActorIds[2];
    /* 0x4734 */  f32 _4734;
    /* 0x4738 */  f32 _4738;
    /* 0x473C */  f32 _473C;
    /* 0x4740 */  PlayerStateChangeEvent* stateChangeEvent;
    /* 0x4744 */  bool isChangeActive;
    /* 0x4745 */  u8 _4745;
    /* 0x4748 */  u32 _4748;
    /* 0x474C */  f32 _474C;
    /* 0x4750 */  u8 _4750;
    /* 0x4754 */  PlayerDeathEvent* deathEvent;
    /* 0x4758 */  bool isOnlyAlivePlayer;
    /* 0x4759 */  u8 _4759;
    /* 0x475C */  f32 _475C;
    /* 0x4760 */  u8 _4760;
    /* 0x4761 */  Direction projectileDirection;         // updates later than direction, when fully turned
    /* 0x4762 */  u8 _4762;
    /* 0x4764 */  u32 waitElapsed;
    /* 0x4768 */  u32 idleTransitionTimer;
    /* 0x476C */  u32 waterSplashTimer;
    /* 0x4770 */  u8 _4770;
    /* 0x4771 */  u8 jumpCounter;
    /* 0x4774 */  u32 jumpComboTimer;
    /* 0x4778 */  u8 _4778;
    /* 0x477C */  u32 unkTimer477C;
    /* 0x4780 */  u32 _4780;
    /* 0x4784 */  u8 _4784[8];                           // unk
    /* 0x478C */  u32 _478C;
    /* 0x4790 */  u32 _4790;
    /* 0x4794 */  u8 _4794[8];                           // unk
    /* 0x479C */  u32 unkTimer479C;
    /* 0x47A0 */  f32 _47A0;
    /* 0x47A4 */  Direction wallSlideDirection;
    /* 0x47A8 */  ActorUniqueID carryReserveActor;
    /* 0x47AC */  f32 carryReserveXOffset;
    /* 0x47B0 */  f32 liftUpOffsetRatio;
    /* 0x47B4 */  u8 _47B4;
    /* 0x47B5 */  u8 _47B5[3];
    /* 0x47B8 */  u32 _47B8;
    /* 0x47BC */  f32 _47BC;
    /* 0x47C0 */  u32 unkTimer47C0;
    /* 0x47C4 */  u32 _47C4;
    /* 0x47C8 */  u32 _47C8;
    /* 0x47CC */  u32 _47CC;
    /* 0x47D0 */  u8 _47D0;
    /* 0x47D1 */  u8 _47D1;
    /* 0x47D4 */  u32 _47D4;
    /* 0x47D8 */  Vec3f cannonLaunchStartPos;
    /* 0x47E4 */  u8 _47E4;
    /* 0x47E8 */  f32 _47E8;
    /* 0x47EC */  f32 _47EC;
    /* 0x47F0 */  f32 _47F0;
    /* 0x47F4 */  f32 _47F4;
    /* 0x47F8 */  f32 _47F8;
    /* 0x47FC */  u32 _47FC;
    /* 0x4800 */  u32 _4800;
    /* 0x4804 */  u8 _4804[4];                           // unk
    /* 0x4808 */  u32 _4808;
    /* 0x480C */  u32 _480C;
    /* 0x4810 */  f32 unkTimer4810;
    /* 0x4814 */  Vec2f _4814;
    /* 0x481C */  u8 _481C;
    /* 0x4820 */  u32 _4820;
    /* 0x4824 */  u32 _4824;
    /* 0x4828 */  u32 unkCrouchSwimTimer;
    /* 0x482C */  u32 _482C;
    /* 0x4830 */  f32 _4830;
    /* 0x4834 */  f32 _4834;
    /* 0x4838 */  f32 _4838;
    /* 0x483C */  f32 _483C;
    /* 0x4840 */  u8 _4840;
    /* 0x4841 */  u8 _4841;
    /* 0x4844 */  u32 _4844;
    /* 0x4848 */  u8 _4848;
    /* 0x484C */  f32 _484C;
    /* 0x4850 */  u32 _4850;
    /* 0x4854 */  u32 _4854;
    /* 0x4858 */  u32 unkTimer4858;
    /* 0x485C */  u32 _485C;
    /* 0x4860 */  u32 _4860;
    /* 0x4864 */  u32 _4864;
    /* 0x4868 */  u32 _4868;
    /* 0x486C */  f32 _486C;
    /* 0x4870 */  u16 _4870;
    /* 0x4872 */  u16 _4872;
    /* 0x4874 */  u8 _4874;
    /* 0x4875 */  u8 _4875;
    /* 0x4876 */  u8 _4876;
    /* 0x4878 */  f32 _4878;
    /* 0x487C */  u8 _487C;
    /* 0x487D */  u8 _487D;
    /* 0x4880 */  u32 crouchTimerMaybe;
    /* 0x4884 */  u32 pMeterCharge;
    /* 0x4888 */  u32 pMeterHoldTimer;
    /* 0x488C */  u32 flightTimer;
    /* 0x4890 */  u32 _4890;
    /* 0x4894 */  u32 _4894;
    /* 0x4898 */  u32 flightGroundTimer;
    /* 0x489C */  u32 unkTimer489C;
    /* 0x48A0 */  s32 megaTimer;
    /* 0x48A4 */  f32 _48A4;
    /* 0x48A8 */  u32 _48A8;
    /* 0x48AC */  f32 _48AC;
    /* 0x48B0 */  ActorUniqueID hatenaCapID;
    /* 0x48B4 */  u32 _48B4;
    /* 0x48B8 */  u16 hatenaCapCoinsRemaining;
    /* 0x48BC */  f32 _48BC;
    /* 0x48C0 */  f32 _48C0;
    /* 0x48C4 */  f32 _48C4;
    /* 0x48C8 */  u32 _48C8;
    /* 0x48CC */  u32 _48CC;
    /* 0x48D0 */  f32 _48D0;
    /* 0x48D4 */  f32 _48D4;
    /* 0x48D8 */  UnkEffectType unkEffect1;
    /* 0x4934 */  UnkEffectType unkEffect2;
    /* 0x4990 */  Effect effectA;
    /* 0x49D0 */  u32 _49D0;
    /* 0x49D4 */  Effect effectB;
    /* 0x4A14 */  u32 _4A14;
    /* 0x4A18 */  u8 _4A18[4];
    /* 0x4A1C */  UnkEffectType unkEffect3;

    static const SizeDefinition sizeDefinitionSmall;
    static const SizeDefinition sizeDefinitionNormal;
    static const SizeDefinition sizeDefinitionMini;
    static const SizeDefinition sizeDefinitionMega;

    static const u8 sizeTypes[POWERUP_COUNT];
    static const SizeDefinition* sizeDefinitions[POWERUP_COUNT];
    static const f32 heights[POWERUP_COUNT];
    static const u32 blockHeights[POWERUP_COUNT];
    static const f32 unkOffsets1[POWERUP_COUNT];
    static const f32 unkOffsets2[POWERUP_COUNT];
    static const f32 unkOffsets3[POWERUP_COUNT];
    static const u8 rendererModes[POWERUP_COUNT];
    static const ActorBgCollisionCheck::Sensor sensors[POWERUP_COUNT];
};
