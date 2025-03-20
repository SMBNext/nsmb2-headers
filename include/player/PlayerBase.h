#pragma once

#include "actors/ActorBase.h"
#include "collider/ActorBgCollisionCheck.h"
#include "collider/PlayerBgCollisionCheck.h"
#include "effect/Effect.h"
#include "gfx/Texture.h"
#include "player/PlayerLookTarget.h"
#include "player/PlayerInput.h"
#include "player/PlayerModel.h"
#include "state/FStateStateMgr.h"
#include "state/FStateVirtualID.h"
#include "state/StateStateMgr.h"


struct PlayerFloatStruct
{
    f32 field_0;
    f32 field_4;
    f32 field_8;
    f32 field_C;
    f32 field_10;
    f32 field_14;
    f32 field_18;
    f32 field_1C;
    f32 field_20;
    f32 field_24;
    f32 field_28;
    f32 field_2C;
    f32 field_30;
    f32 field_34;
    f32 field_38;
    f32 field_3C;
    f32 field_40;
    f32 field_44;
};

struct PlayerBase_1DC4
{
    Effect effect;
    u32 _4;
};

class PlayerBase_2074
{
    typedef u8 CourseBgMgr_624[0x1044];

public:
    void* vtable;                         ///< this is a sead::Delegate<Unk>
    PlayerBase_2074* _4;
    void* _8;
    u32 _C;                               ///< delegate ends here
    CourseBgMgr_624 _10;
    u8 _1054[528];                        ///< unk
    sead::BoundBox2f _1274;
    u8 _1284;                             ///< used in a switch case with 3 values
};



class PlayerBase : public ActorBase
{
    SEAD_RTTI_OVERRIDE(PlayerBase, ActorBase);

    typedef u8 TextureCtrGR[0x14];

public:
    int onCreate() override;            // calls vf3C0()
    int beforeExecute() override;       // updates collisionCheck
    int onExecute() override;           // calls vf3C0(), vf104(), vfD8() and other funcs
    void afterExecute(int) override;
    int beforeDraw() override;
    ActorBgCollisionCheck* getBgCollisionCheck() override;
    ActorBgCollisionCheck* getBgCollisionCheck2() override;
    void vfCC() override;               // nullsub
    void powActivated() override;

    virtual void vfD8();                // nullsub
    virtual void vfDC() = 0;
    virtual u8 getSizeType(u32 powerup) = 0;
    virtual u32* vfE4();
    virtual void vfE8() = 0;
    virtual f32 vfEC() = 0;
    virtual void vfF0();                // nullsub
    virtual void vfF4();
    virtual void vfF8();                // nullsub
    virtual f32 vfFC();                 // returns 0.0f
    virtual void vf100(const ActorCollisionCheck::Info* info);      // Inits all 3 ActorCollisionChecks with the struct
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
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, DemoUnk6);
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
    virtual bool vf250();           // returns 0
    virtual bool vf254() = 0;
    virtual s32 vf258();            // returns -1
    virtual bool vf25C();           // returns 0 or 1
    virtual bool vf260();           // deleted
    virtual bool vf264();           // returns 0
    virtual void vf268();           // deleted
    virtual void vf26C();
    virtual bool vf270();           // returns 0
    virtual bool vf274();           // returns 0 or 1
    virtual bool vf278(u32 unk);    // returns 0 or 1
    virtual void vf27C();
    virtual bool vf280();           // returns 0
    virtual bool vf284();           // returns 0

    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, None);    // starting with vf288()
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Walk);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, SideSlide);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Unk4);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Jump);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, SitJump);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Crouch);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, CrouchJump);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Fall);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Unk10);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Cloud);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Swim);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, JumpDai);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Unk14);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Unk15);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Unk16);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Unk17);
    DECLARE_STATE_VIRTUAL_ID_BASE(PlayerBase, Unk18);   // up to vf35C()

    virtual bool vf360();           // returns 0
    virtual void vf364();           // nullsub
    virtual void vf368();           // nullsub
    virtual void vf36C();           // nullsub
    virtual void vf370();           // deleted
    virtual void vf374();           // deleted
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
    virtual u32* vf3AC();           // returns _11E0
    virtual bool vf3B0();           // returns 0
    virtual bool vf3B4();           // returns 0
    virtual bool vf3B8();           // deleted
    virtual bool vf3BC();           // returns 0
    virtual void vf3C0();
    virtual void vf3C4();
    virtual void vf3C8();
    virtual void vf3CC();
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
    virtual bool vf400();                       // returns 0 or 1
    virtual void vf404();                       // nullsub
    virtual void vf408();                       // deleted
    virtual s8 vf40C();                         // returns 0
    virtual void vf410();                       // deleted
    virtual void vf414();                       // nullsub
    virtual void vf418();                       // nullsub
    virtual void vf41C();                       // deleted


    void changeState(const StateID& stateID, u32 _15B4, u32 _15B0);
    void changeState(const StateID& stateID, u32 _15B4);

    PlayerModelMgr* modelMgrPtr;
    f32 _1CC;
    f32 _1D0;
    f32 _1D4;
    PlayerBgCollisionCheck bgCollisionCheck;
    PlayerInput input;
    u32 _1178;                                          // Status Flags
    MoveStatus movementStatus;                          // seems to be mMovementFlags [see @00256488 for specifics...]
    u32 _1180;              
    u32 _1184;              
    u32 _1188;              
    u32 _118C;                                          // some bitflag, 0x4000 is set by NextGotoBlock (0x29EE98)
    u32 _1190;                                          // Status Flags end
    f32 height;                                         // inited to 16.0
    u8 _1198;
    f32 _119C;
    f32 _11A0;
    f32 _11A4;
    f32 _11A8;
    f32 _11AC;
    f32 _11B0;
    f32 _11B4;
    f32 _11B8;
    u8 _11BC;
    u8 _11BD;
    Vec3f _11C0;
    f32 _11CC;
    f32 _11D0;
    f32 _11D4;
    u32 _11D8;
    u32 _11DC;
    PlayerFloatStruct* _11E0;
    u32 _11E4;
    f32 _11E8;
    u8 _11EC;
    u8 playerId;                                        // set to playerId in PlayerObject ctor
    u8 comboRelated;                                    // counts up when stomping multiple enemies without touching ground?
    u8 _11EF;
    bool isLuigi;                                       // inited to spritedata1 <<20 >> 28
    Powerup powerup;                                    // inited to spriteData1 << 24 >> 28
    u32 _11F4;
    u32 _11F8;
    u32 _11FC;
    ActorBgCollisionCheck::Sensor bgCollisionSensorA;
    ActorBgCollisionCheck::Sensor bgCollisionSensorB;
    ActorBgCollisionCheck::Sensor bgCollisionSensorC;
    u32 liquidRelatedFlags;                             // may be more than just liquid, & 0x40000 is related to being in/standing in water
    u32 _1228;
    u32 _122C;
    u32 _1230;
    u32 _1234;
    u32 _1238;
    u32 _1240[10];                                      // UNK
    u32 _1264;                                          // inited to position.y
    f32 _1268;
    u8 _126C;
    u32 _1270;
    u32 _1274;
    u32 _1278;
    u32 _127C;
    GroundType groundType;                              // used to index footstep sound + effects ect (this enum should probably not be scoped under PlayerBase...)
    f32 _1284;
    f32 _1288;
    f32 _128C;
    u8 _1290;
    u8 _1291;
    f32 _1294;
    f32 _1298;
    f32 _129C;
    f32 _12A0;
    u8 _12A4;
    u32 _12A8;
    u32 _12AC;
    u32 _12B0;                                          // some listnode maybe
    u32 _12B4;
    u32 _12B8;
    s32 unkActorIds[2];
    u32 _12C4;
    f32 _12C8;
    f32 _12CC;
    f32 _12D0;
    f32 _12D4;
    u32 _12D8;
    f32 _12DC;
    ActorCollisionCheck collisionCheck1;
    ActorCollisionCheck collisionCheck2;
    u32 _1450;
    u32 _1454;
    u32 _1458;
    u32 _145C;
    u32 _1460;
    u32 _1464;
    f32 _1468;
    f32 _146C;
    f32 _1470;
    f32 _1474;
    u8 _1478;
    u8 _1479;
    u32 _147C;
    s32 _1480;
    u8 _1484;
    u32 _1488;
    f32 _148C;
    u32 _1490;
    u32 _1494;
    u8 _1498;
    u8 _1499;
    f32 _149C;
    f32 _14A0;
    f32 _14A4;
    f32 _14A8;
    f32 _14AC;
    f32 _14B0;
    u32 _14B4;
    FStateStateMgr<PlayerBase> demoStateMgr;            // this is probably part of a bigger struct (e..g. a playerDemoController)
    u32 goalSubStateId;
    u32 unkDemoSubStateId;                              // this is a substate id used by statesDemo
    u32 _14E8;
    u8 _14EC;
    s32 _14F0;
    u32 _14F4;
    u8 _14F8;
    u8 _14F9;
    u8 _14FA[2];                                        // unk (probably padding)
    f32 _14FC;              
    u8 _1500[4];                                        // unk
    f32 _1504;              
    u8 _1508[4];                                        // unk
    Vec3f _150C;
    f32 _1518;
    f32 _151C;
    f32 _1520;
    s32 _1524;
    s32 _1528;
    f32 _152C;
    s32 _1530;
    s32 _1534;
    u8 _1538[12];                                       // unk
    u8 _1544;
    f32 _1548;
    u8 _154C;
    u8 _154D;
    u8 _154E[2];                                        // unk (probably padding)
    Vec3f _1550;
    Vec3f _155C;
    u8 _1568;
    f32 _156C;
    f32 _1570;
    u32 _1574;
    u32 _1578;
    f32 _157C;
    f32 _1580;
    u8 _1584;
    u8 _1585;
    u32 _1588;
    FStateStateMgr<PlayerBase> stateMgr;
    u32 _15B4;
    u32 substateJump;
    u32 _15BC;
    u32 _15C0;
    s32 jugemCloudId;                                   // may be used for more than just cloud, unsure
    u32 _15C8;
    u8 _15CC;
    u32 _15D0;
    u32 _15D4;
    u32 _15D8;
    u8 _15DC;
    f32 _15E0;
    Vec3f _15E4;
    u8 _15F0[12];                                       // UNK
    u8 _15FC;
    u8 _15FD;
    f32 _1600;
    u32 _1604;
    u32 _1608;
    u8 _160C;
    u32 hasStar;                                        // mthis ay be a counter?
    u32 streakIdx;                                      // used to index combo sfx etc
    Effect effectA;
    u32 _1658;
    Effect effectB;
    u32 _169C;
    Effect rotateTailEffect;
    u32 _16E0;
    UnkEffectType unkEffectA;                            // used for numb effect + wallSmoke effect + electric effect
    UnkEffectType slipEffect;
    UnkEffectType dashBrakeEffect;
    UnkEffectType dashSmokeEffect;
    UnkEffectType unkEffectE;
    UnkEffectType unkEffectF;
    UnkEffectType unkEffectG;
    UnkEffectType unkEffectH;
    UnkEffectType unkEffectI;
    UnkEffectType unkEffectJ;
    UnkEffectType tailWhiteEffect;
    UnkEffectType tailEffect;
    UnkEffectType tailOutEffect;
    UnkEffectType unkEffectN;
    UnkEffectType unkEffectO;
    UnkEffectType waterWalkEffect;
    UnkEffectType unkEffectQ;
    UnkEffectType swimEffect;
    u32 _1D5C;
    UnkEffectType unkEffectS;
    u32 _1DBC;
    u32 _1DC0;
    PlayerBase_1DC4 waterEffects[3];                           // these may be wrong?
    PlayerBase_1DC4 _1E90[3];
    PlayerBase_1DC4 _1F5C[3];
    u32 _2028;
    u32 _202C;                                                 // indexes _1F5C
    PlayerLookTarget unkLookTarget;
    u8 _275C;
    TextureCtrGR shadowTexture;
    PlayerBase_2074 _2074;
    PlayerBase_2074 _32EC;
};

size_assert(PlayerBase, 0x4564);
