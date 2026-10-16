#pragma once

#include "actors/ActorBase.h"
#include "actors/AttentionLook.h"
#include "collider/ActorBgCollisionCheck.h"
#include "collider/PlayerBgCollisionCheck.h"
#include "effect/Effect.h"
#include "gfx/SimpleRenderer.h"
#include "sead/gfx/seadTexture.h"
#include "player/PlayerKey.h"
#include "player/PlayerModel.h"
#include "state/FStateMgr.h"
#include "utility/Direction.h"
#include "state/FStateStateMgr.h"
#include "state/FStateVirtualID.h"
#include "state/StateStateMgr.h"


struct UnkEffectWrapper
{
    Effect effect;
    f32 _4;
};


class PlayerBase : public ActorBase
{
    SEAD_RTTI_OVERRIDE(PlayerBase, ActorBase);

public:
    struct GravityData
    {
        /* 0x00 */ f32 _0;
        /* 0x04 */ f32 _4;
        /* 0x08 */ f32 _8;
        /* 0x0C */ f32 _C;
        /* 0x10 */ f32 _10;
        /* 0x14 */ f32 _14;
        /* 0x18 */ f32 _18;
        /* 0x1C */ f32 _1C;
        /* 0x20 */ f32 _20;
        /* 0x24 */ f32 _24;
        /* 0x28 */ f32 _28;
        /* 0x2C */ f32 _2C;
        /* 0x30 */ f32 _30;
        /* 0x34 */ f32 _34;
        /* 0x38 */ f32 _38;
        /* 0x3C */ f32 _3C;
        /* 0x40 */ f32 _40;
        /* 0x44 */ f32 _44;
    };

    struct PowerChangeSpeedData
    {
        /* 0x00 */ f32 defaultAccel;
        /* 0x04 */ f32 noInputAccel;
        /* 0x08 */ f32 turnNoInputAccel;
        /* 0x0C */ f32 turnAccel;
        /* 0x10 */ f32 verySlowAccel;
        /* 0x14 */ f32 slowAccel;
        /* 0x18 */ f32 runSlowAccel;
        /* 0x1C */ f32 mediumAccel;
        /* 0x20 */ f32 fastAccel;
    };

    struct SpeedData
    {
        /* 0x00 */ f32 lowSpeed;
        /* 0x04 */ f32 mediumSpeed;
        /* 0x08 */ f32 highSpeed;
        /* 0x0C */ PowerChangeSpeedData powerChangeNormal;
        /* 0x30 */ PowerChangeSpeedData powerChangeIce;
        /* 0x54 */ PowerChangeSpeedData powerChangeLowSlip;
    };

    struct JumpInfo
    {
        /* 0x00 */  f32 speed;
        /* 0x04 */  u8 jumpMode;
        /* 0x05 */  s8 blendMode;
    };

public:
    Result onCreate() override;            // calls vf3C0()
    bool preExecute() override;       // updates collisionCheck
    Result onExecute() override;           // calls vf3C0(), vf104(), vfD8() and other funcs
    void postExecute(Result execResult) override;
    bool preDraw() override;
    ActorBgCollisionCheck* getBgCollisionCheck() override;
    const ActorBgCollisionCheck* getBgCollisionCheck() const override;
    void executeLastAll() override;
    void powActivated() override;

    virtual void executeMain();          // nullsub
    virtual void updatePowerupRelated() = 0;
    virtual u8 getSizeType(Powerup powerup) = 0;
    virtual const Vec3f& getScoreDisplayOffset() const;
    virtual void vfE8() = 0;
    virtual f32 vfEC() = 0;
    virtual void vfF0();                // nullsub
    virtual void vfF4();
    virtual void clearJumpActionInfo();  // nullsub
    virtual f32 vfFC();                  // returns 0.0f
    virtual void initCollision(const ActorCollisionCheck::CollisionData& reactInfo, const ActorCollisionCheck::CollisionData& attackInfo);
    virtual void vf104();               // removes all 3 ActorCollisionChecks from the list
    virtual void vf108();
    virtual bool vf10C();               // adds all 3 ActorCollisionChecks from the list, returns 1
    virtual void vf110() = 0;
    virtual void vf114() = 0;
    virtual bool vf118() = 0;
    virtual void vf11C(u32* unk1, u32 unk2, u32 unk3);
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();               // nullsub
    virtual void vf12C();               // nullsub
    virtual void vf130(u32 unk);
    virtual void vf134();
    virtual void vf138();
    virtual void vf13C();
    virtual void vf140();               // nullsub
    virtual void vf144(u32 unk);        // nullsub
    virtual void vf148();               // nullsub
    virtual void vf14C();               // nullsub
    virtual void vf150();               // nullsub
    virtual void vf154();               // nullsub
    virtual void vf158(u32 unk);

    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoUnk1);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoUnk2);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoUnk3);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoGoal);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoUnk5);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoWait);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoInDokanU);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoInDokanD);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoInDokanR);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoInDokanL);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoOutDokanU);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoOutDokanD);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoOutDokanR);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoOutDokanL);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoInDoor);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoOutDoor);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoUnk17);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoNextGotoBlock);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Down);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoWarpJump);

    virtual void vf24C();           // nullsub
    virtual bool isChange();        // returns 0 (default false; overridden by PlayerObject)
    virtual bool vf254() = 0;
    virtual s32 vf258();            // returns -1
    virtual bool vf25C();           // returns 0 or 1
    virtual bool vf260();           // deleted
    virtual bool vf264();           // returns 0
    virtual void vf268();           // deleted
    virtual void vf26C();
    virtual bool vf270();           // returns 0
    virtual bool isEnableDokanInStatus();
    virtual bool vf278(u32 unk);    // returns 0 or 1
    virtual void vf27C();
    virtual bool setJump(f32 jumpSpeed, f32 speedX, bool allowSteer, u32 keyMode, u32 jumpMode, bool unk);
    virtual bool _setJump(f32 jumpSpeed, f32 speedX, bool allowSteer, u32 keyMode, u32 jumpMode, bool unk);

    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, None);    // starting with vf288()
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Walk);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, SideSlide);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Slip);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Jump);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, HipAttack);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Crouch);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, SitJump);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Fall);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, SlowSwim);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Cloud);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Swim);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, JumpDai);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, PlayerJumpDai);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, WaitJump);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Unk16);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Unk17);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Unk18);   // up to vf35C()

    virtual bool vf360();           // returns 0
    virtual void setWaitActionAnim(int blendMode);
    virtual void vf368();           // nullsub
    virtual void walkActionInit_Wait(u32 blendMode);
    virtual void vf370();           // deleted
    virtual void walkActionInit_Move(int blendMode);
    virtual void vf378();
    virtual bool vf37C();           // returns 0
    virtual void vf380() = 0;
    virtual bool vf384() = 0;
    virtual void vf388();
    virtual void vf38C();
    virtual bool vf390();           // returns 0
    virtual bool vf394();           // returns 0 or 1
    virtual void vf398() = 0;
    virtual void vf39C() = 0;
    virtual bool vf3A0();           // returns 0 or 1
    virtual void vf3A4();
    virtual void vf3A8();           // deleted
    virtual GravityData* getGravityData();   // returns gravityData
    virtual bool isCarry();         // returns false
    virtual bool vf3B4();           // returns 0
    virtual bool vf3B8();           // deleted
    virtual bool vf3BC();           // returns 0
    virtual void setZPosition();
    virtual void setZPosition(f32 zPos);
    virtual void setZPositionDirect(f32 zPos);
    virtual void offZPosSetNone();
    virtual void vf3D0();                               // sets _20 to descent rate
    virtual bool vf3D4();                               // returns 0
    virtual bool vf3D8();                               // deleted
    virtual bool setDamage(ActorBase* other, DamageType type);
    virtual bool setForcedDamage(ActorBase* other, DamageType type);
    virtual bool vf3E4(u32 unk);                        // returns 0 or 1
    virtual bool vf3E8() = 0;
    virtual bool setDamage2(ActorBase* other, DamageType type);
    virtual void vf3F0();
    virtual void vf3F4();
    virtual void vf3F8(u32 unk);
    virtual void vf3FC();                       // nullsub
    virtual bool hasStar();
    virtual void vf404();                       // nullsub
    virtual void vf408();                       // deleted
    virtual s8 vf40C();                         // returns 0
    virtual void vf410();                       // deleted
    virtual void vf414();                       // nullsub
    virtual void vf418();                       // nullsub
    virtual void vf41C();                       // deleted

    inline const bool isStatus(u32 flag) { return status.isSet(flag); }
    inline const void onStatus(u32 flag) { status.enable(flag); }
    inline const void offStatus(u32 flag) { status.clear(flag); }

    inline const bool isNowBgCross(u32 flag) { return nowBgCross.isSet(flag); }
    inline const void onNowBgCross(u32 flag) { nowBgCross.enable(flag); }
    inline const void offNowBgCross(u32 flag) { nowBgCross.clear(flag); }

    inline const bool isOldBgCross(u32 flag) { return oldBgCross.isSet(flag); }
    inline const void onOldBgCross(u32 flag) { oldBgCross.enable(flag); }
    inline const void offOldBgCross(u32 flag) { oldBgCross.clear(flag); }

    inline SpeedData* getSpeedData(){ return hasStar() ? speedDataStar : speedDataNormal; }
    inline const bool isTanooki() { return powerup == Powerup::cTanooki || powerup == Powerup::cWhiteTanooki; }
    inline const bool isQuicksand() { return isNowBgCross(BgCross::cInQuickSand) || isNowBgCross(BgCross::cInQuickSand); }

    void changeState(const StateID& stateID, u32 unk, void* arg);
    void changeState(const StateID& stateID, u32 unk);

    inline bool isState(const StateID& stateID) const
    {
        return *stateMgr.getStateID() == stateID;
    }

    inline bool isLastState(const StateID& stateID) const
    {
        return *stateMgr.getOldStateID() == stateID;
    }

    inline bool isNextState(const StateID& stateID) const
    {
        const StateID* newStateID = stateMgr.getNewStateID();
        return newStateID != nullptr && *newStateID == stateID;
    }

    bool isOnGroundDemo();
    void changeStateDemo(const StateID& stateID, u32 unk);
    bool freezeDemo();
    void restoreFromDemo();
    void checkDisplayOutDead();
    void checkDispOver();
    bool initDemoGoalBase();

    bool isDemo();  // 0x00499E7C

    void playSfx(u32 soundId, u32 suppressionMode);       // 0x001F4060
    void playVoiceSfx(u32 soundId, u32 suppressionMode);  // 0x001F4098
    void doDiveInWaterEffect();                           // 0x001F5BB0
    void doSplashOutWaterEffect();                        // 0x001F6C2C

    bool spawnBigChangeEffect();

    void spawnDashAddEffect();                                     // 0x001F52B0
    void spawnDashStartEffect();                                   // 0x001F74D4
    void spawnJumpNoteEffect();                                    // 0x001F6650
    void spawnLandEffect();                                        // 0x001F7640
    void setStartJumpEffect();                                     // 0x001F7558
    void holdSoundArg(u32 soundId, u32 arg, u32 suppressionMode);  // 0x001F29F0
    void playFootstepSound(s32 soundId);                           // 0x001FA378

    void calcAccelOnIceLift();  // 0x001F42A0
    void calcSpeedOnIceLift();  // 0x001F7078
    void calcPlayerSpeedXY();

    bool calcCollisionCheckPlayerRev(f32* outShiftX);      // 0x001F36E4
    void posMoveAnglePlayer(const sead::Vector3f& speed);  // 0x001F5FEC
    void setSandEffect();                                  // 0x001F23D4

    void setAddLiftSpeedF();                      // 0x001FD4D8
    void setGravity();                            // 0x001F2C9C
    void setJumpGravity();                        // 0x001F2D8C
    void setMaxFallSpeed();                       // 0x001F9144
    void setSimpleMoveSpeed();                    // 0x001F7778
    void setMoveSpeed();                          // 0x001F16C8
    void setAirPower();                           // 0x001F0C98
    void setPower();                              // 0x001F1B7C
    void normalPowerSet();                        // 0x001F2EF8
    s32 getPowerChangeType(int affectPenguin);    // 0x00499C34
    bool turnAngle();                             // 0x001EF364
    bool checkSlip();                             // 0x001EF0D8
    bool checkTurn();                             // 0x001F27D4
    void getScalar148C(Vec3f* out);               // 0x00499E10
    bool checkJumpTrigger();                      // 0x001F47EC
    bool checkStandUpRoof();                      // 0x001F4830
    bool executeDemoState();                      // 0x001F4B44
    void updateLiquidEffects();                   // 0x001FAC94
    void calcReductionScale();                    // 0x001F6ED8
    void setFootSound();                          // 0x001F163C
    void updateEffects();                         // 0x001F7D24
    void createGoldSuperTanookiEffects();         // 0x001F63B4
    void spawnTailWhiteEffect();                  // 0x001FB194
    void sub_1F431C();                            // 0x001F431C
    void sub_1FE908();                            // 0x001FE908
    bool setDelayHelpJump();                            // 0x001F5370
    void sub_1F90CC(f32 a2, f32 a3);              // 0x001F90CC
    bool moveTowardsDemoTargetX(f32 speed, f32 tolerance);  // 0x001F2A28
    bool moveTowardsDemoTargetY(f32 speed, f32 offsetY);    // 0x001F2ACC
    void updateCollisionCheckStarWhiteTanooki();  // 0x001F0E50
    void setCollisionCheckTanukiShake();          // 0x001F0E80
    void bgCheck(int flag);                       // 0x001FF210
    void checkLiquid();                           // 0x001EF3AC
    s32 getSideDirectionAngle(Direction direction);   // 0x001F7250
    s32 getYRotation(Direction direction);        // 0x004996E0
    void spawnRotateTailEffect();                 // 0x001F9234
    void spawnDashSmokeEffect();                  // 0x001F7AB0
    void resetCollisionCheck1Data();              // 0x001F230C

public:
    PlayerModelMgr* modelMgrPtr;
    /* 0x01CC */  f32 _1CC;
    /* 0x01D0 */  f32 _1D0;
    /* 0x01D4 */  f32 _1D4;
    /* 0x01D8 */  PlayerBgCollisionCheck bgCollisionCheck;
    /* 0x10E0 */  PlayerKey key;
    /* 0x1178 */  PlayerStatus status;
    /* 0x1194 */  f32 height;                                        // inited to 16.0
    /* 0x1198 */  Direction prevDirection;
    /* 0x119C */  f32 _119C;
    /* 0x11A0 */  f32 _11A0;
    /* 0x11A4 */  f32 _11A4;
    /* 0x11A8 */  f32 _11A8;
    /* 0x11AC */  f32 _11AC;
    /* 0x11B0 */  f32 _11B0;
    /* 0x11B4 */  f32 _11B4;
    /* 0x11B8 */  f32 _11B8;
    /* 0x11BC */  u8 _11BC;
    /* 0x11BD */  u8 _11BD;
    /* 0x11C0 */  Vec3f positionDelta;
    /* 0x11CC */  Vec3f lastSpeed;
    /* 0x11D8 */  SpeedData* speedDataNormal;
    /* 0x11DC */  SpeedData* speedDataStar;
    /* 0x11E0 */  GravityData* gravityData;
    /* 0x11E4 */  u32 noGravityTimer;
    /* 0x11E8 */  f32 _11E8;
    /* 0x11EC */  u8 _11EC;
    /* 0x11ED */  u8 playerId;                                      // set to playerId in PlayerObject ctor
    /* 0x11EE */  u8 comboCounter;
    /* 0x11EF */  u8 _11EF;
    /* 0x11F0 */  bool isLuigi;                                     // inited to spritedata1 <<20 >> 28
    /* 0x11F1 */  Powerup powerup;                                  // inited to spriteData1 << 24 >> 28
    /* 0x11F4 */  u32 _11F4;
    /* 0x11F8 */  u32 _11F8;
    /* 0x11FC */  u32 _11FC;
    /* 0x1200 */  ActorBgCollisionCheck::Sensor bgCollisionSensorHead;
    /* 0x120C */  ActorBgCollisionCheck::Sensor bgCollisionSensorFoot;
    /* 0x1218 */  ActorBgCollisionCheck::Sensor bgCollisionSensorWall;
    /* 0x1224 */  BgCross nowBgCross;
    /* 0x1230 */  BgCross oldBgCross;
    /* 0x123C */  u32 oldBgCrossFoot[10];
    /* 0x1264 */  f32 _1264;                            // inited to position.y
    /* 0x1268 */  f32 kaniPosY;                         // likely unused leftover (NSMB2 does not have cliff ledges)
    /* 0x126C */  u8 slopeType;
    /* 0x1270 */  s32 speedSlopeAngle;
    /* 0x1274 */  s32 speedSlopeAnglePrev;
    /* 0x1278 */  s32 baseSlopeAngle;
    /* 0x127C */  s32 baseSlopeAnglePrev;
    /* 0x1280 */  GroundType groundType;                // used to index footstep sound + effects ect (this enum should probably not be scoped under PlayerBase...)
    /* 0x1284 */  s32 wallAngle;
    /* 0x1288 */  f32 liquidLevel;
    /* 0x128C */  f32 liquidLevelPrev;
    /* 0x1290 */  u8 liquidType;
    /* 0x1291 */  u8 waterDepthType;
    /* 0x1294 */  f32 quicksandHeight;
    /* 0x1298 */  f32 _1298;
    /* 0x129C */  f32 _129C;
    /* 0x12A0 */  f32 _12A0;
    /* 0x12A4 */  u8 _12A4;
    /* 0x12A8 */  u32 _12A8;
    /* 0x12AC */  u32 _12AC;
    /* 0x12B0 */  u32 _12B0;                          // some listnode maybe
    /* 0x12B4 */  u32 _12B4;
    /* 0x12B8 */  u32 _12B8;
    /* 0x12BC */  ActorUniqueID unkActorIds[2];
    /* 0x12C4 */  f32 _12C4;
    /* 0x12C8 */  f32 _12C8;
    /* 0x12CC */  f32 _12CC;
    /* 0x12D0 */  f32 _12D0;
    /* 0x12D4 */  f32 _12D4;
    /* 0x12D8 */  u32 windGroundTimer;
    /* 0x12DC */  f32 windSpeed;
    /* 0x12E0 */  ActorCollisionCheck collisionCheck1;
    /* 0x1398 */  ActorCollisionCheck collisionCheck2;
    /* 0x1450 */  u32 invulnTimer;                    // skips setting flag 0x10000000 on _1184 every 4th or 8th frame while timer is >= 60
    /* 0x1454 */  u32 demoTimer1;
    /* 0x1458 */  u32 demoTimer2;
    /* 0x145C */  u32 demoTimer3;
    /* 0x1460 */  u32 demoTimer4;
    /* 0x1464 */  u32 demoTimer5;
    /* 0x1468 */  f32 _1468;
    /* 0x146C */  f32 _146C;
    /* 0x1470 */  f32 _1470;
    /* 0x1474 */  f32 _1474;
    /* 0x1478 */  u8 _1478;
    /* 0x1479 */  u8 _1479;
    /* 0x147C */  u32 _147C;
    /* 0x1480 */  ActorUniqueID _1480;
    /* 0x1484 */  u8 squishState;
    /* 0x1488 */  u32 squishKeyframeIdx;
    /* 0x148C */  f32 squishScale;
    /* 0x1490 */  u32 squishNoMoveTimer;
    /* 0x1494 */  u32 squishCooldownTimer;
    /* 0x1498 */  u8 _1498;
    /* 0x1499 */  u8 _1499;
    /* 0x149C */  f32 _149C;
    /* 0x14A0 */  f32 _14A0;
    /* 0x14A4 */  f32 _14A4;
    /* 0x14A8 */  f32 _14A8;
    /* 0x14AC */  f32 _14AC;
    /* 0x14B0 */  f32 _14B0;
    /* 0x14B4 */  u32 _14B4;
    /* 0x14B8 */  FStateMgr<PlayerBase> demoStateMgr;
    /* 0x14DC */  u32 demoStateArg;
    /* 0x14E0 */  u32 demoSubState;
    /* 0x14E4 */  u32 demoState;                                  // this is a substate id used by statesDemo
    /* 0x14E8 */  u32 demoTimer;
    /* 0x14EC */  bool isInDemo;
    /* 0x14F0 */  ActorUniqueID demoActorID;
    /* 0x14F4 */  u32 entranceID;
    /* 0x14F8 */  u8 entranceType;
    /* 0x14F9 */  u8 _14F9;
    /* 0x14FA */  u8 _14FA[2];                                     // unk (probably padding)
    /* 0x14FC */  f32 _14FC;
    /* 0x1500 */  u8 _1500[4];                                     // unk
    /* 0x1504 */  f32 _1504;
    /* 0x1508 */  u8 _1508[4];                                     // unk
    /* 0x150C */  Vec3f entryPositionMaybe;
    /* 0x1518 */  f32 _1518;
    /* 0x151C */  f32 _151C;
    /* 0x1520 */  f32 _1520;
    /* 0x1524 */  s32 _1524;
    /* 0x1528 */  s32 _1528;
    /* 0x152C */  f32 _152C;
    /* 0x1530 */  s32 unkTimer1530;
    /* 0x1534 */  s32 _1534;
    /* 0x1538 */  u8 _1538[12];                                    // unk
    /* 0x1544 */  u8 kimePoseMode;
    /* 0x1548 */  f32 _1548;
    /* 0x154C */  u8 _154C;
    /* 0x154D */  u8 _154D;
    /* 0x154E */  u8 _154E[2];                                     // unk (probably padding)
    /* 0x1550 */  Vec3f demoTargetPosition;
    /* 0x155C */  Vec3f _155C;
    /* 0x1568 */  u8 _1568;
    /* 0x156C */  f32 demoTargetOffsetY;
    /* 0x1570 */  f32 demoTargetToleranceX;
    /* 0x1574 */  u32 _1574;
    /* 0x1578 */  u32 _1578;
    /* 0x157C */  f32 _157C;
    /* 0x1580 */  f32 _1580;
    /* 0x1584 */  u8 _1584;
    /* 0x1585 */  u8 _1585;
    /* 0x1588 */  u32 _1588;
    /* 0x158C */  FStateMgr<PlayerBase> stateMgr;
    /* 0x15B0 */  void* stateArg;
    /* 0x15B4 */  u32 stateArg2;
    /* 0x15B8 */  u32 substate;
    /* 0x15BC */  u32 substateTimer;
    /* 0x15C0 */  u32 substateValue;
    /* 0x15C4 */  ActorUniqueID rideActorId;                       // may be used for more than just cloud, unsure
    /* 0x15C8 */  u32 unkTimer15C8;
    /* 0x15CC */  u8 walkAnimState;
    /* 0x15D0 */  u32 jumpDaiTimer;
    /* 0x15D4 */  u32 _15D4;
    /* 0x15D8 */  u32 unkTimer15D8;
    /* 0x15DC */  u8 _15DC;
    /* 0x15E0 */  f32 _15E0;
    /* 0x15E4 */  Vec3f _15E4;
    /* 0x15F0 */  u8 _15F0[12];                                     // UNK
    /* 0x15FC */  u8 _15FC;
    /* 0x15FD */  u8 _15FD;
    /* 0x1600 */  f32 _1600;
    /* 0x1604 */  u32 followMameKuribo;
    /* 0x1608 */  u32 _1608;
    /* 0x160C */  u8 _160C;
    /* 0x1610 */  u32 starTimer;
    /* 0x1614 */  u32 starKillCombo;                                // used to index combo sfx etc
    /* 0x1618 */  Effect effectA;
    /* 0x1658 */  u32 _1658;
    /* 0x165C */  Effect effectB;
    /* 0x169C */  u32 _169C;
    /* 0x16A0 */  Effect powerupRelatedEffect;
    /* 0x16E0 */  u32 _16E0;
    /* 0x16E4 */  UnkEffectType unkEffectA;                         // used for numb effect + wallSmoke effect + electric effect
    /* 0x1740 */  UnkEffectType slipEffect;
    /* 0x179C */  UnkEffectType dashBrakeEffect;
    /* 0x17F8 */  UnkEffectType dashSmokeEffect;
    /* 0x1854 */  UnkEffectType groundEffect;
    /* 0x18B0 */  UnkEffectType unkEffectF;
    /* 0x190C */  UnkEffectType unkEffectG;
    /* 0x1968 */  UnkEffectType unkEffectH;
    /* 0x19C4 */  UnkEffectType unkEffectI;
    /* 0x1A20 */  UnkEffectType unkEffectJ;
    /* 0x1A7C */  UnkEffectType tailWhiteEffect;
    /* 0x1AD8 */  UnkEffectType tailEffect;
    /* 0x1B34 */  UnkEffectType tailOutEffect;
    /* 0x1B90 */  UnkEffectType unkEffectN;
    /* 0x1BEC */  UnkEffectType unkEffectO;
    /* 0x1C48 */  UnkEffectType waterWalkEffect;
    /* 0x1CA4 */  UnkEffectType unkEffectQ;
    /* 0x1D00 */  UnkEffectType swimEffect;
    /* 0x1D5C */  u32 _1D5C;
    /* 0x1D60 */  UnkEffectType unkEffectS;
    /* 0x1DBC */  u32 _1DBC;
    /* 0x1DC0 */  u32 _1DC0;
    /* 0x1DC4 */  UnkEffectWrapper waterEffects[3];                 // these may be wrong?
    /* 0x1E90 */  UnkEffectWrapper _1E90[3];
    /* 0x1F5C */  UnkEffectWrapper _1F5C[3];
    /* 0x2028 */  u32 _2028;
    /* 0x202C */  u32 _202C;                                       // indexes _1F5C
    /* 0x2030 */  AttentionLook unkLookTarget;
    /* 0x205C */  u8 _275C;                                         // 0x205C, despite the IDB name
    /* 0x2060 */  sead::TextureCtrGR shadowTexture;
    /* 0x2074 */  SimpleRenderer flyingMeterRenderer;
    /* 0x32EC */  SimpleRenderer shadowRenderer;

    // BR_Mr_DiveInWater_s_2, BR_Mr_DiveInWater_s_1, BR_Mr_DiveInWater_s
    static const u16 splashOutWaterEffects[3];

    // BR_Mr_DiveInWater_3, BR_Mr_DiveInWater_s_4, BR_Mr_DiveInWater_s_3
    static const u16 splashOutWaterShallowEffects[3];

    // 21.0, 11.0, 0.0, 0.0
    static const f32 powerupChangeYPosTable[4];

    static const u8 powerupHeightConversionRelated[4][4];
    static const Vec3f playerMegaConversionScaleTable[12][2];
};

size_assert(PlayerBase, 0x4564);
size_assert(PlayerBase::GravityData, 0x48);
size_assert(PlayerBase::PowerChangeSpeedData, 0x24);
size_assert(PlayerBase::SpeedData, 0x78);
