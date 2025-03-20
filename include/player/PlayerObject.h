#pragma once

#include "player/PlayerBase.h"
#include "player/PlayerModel.h"

#include "actors/ActorBase.h"
#include "collider/ActorBgCollisionCheck.h"
#include "player/PlayerEnum.h"

class PlayerObject : public PlayerBase    // size: 0x4A78
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

    int onCreate() override;
    int onDelete() override;
    void afterExecute(int) override;
    int beforeDraw() override;
    int onDraw() override;
    void setPlayerId(s8) override;
    void vf58() override;
    u32 vf5C() override; 
    void vf60() override;
    void vfCC() override;

    void vfD8() override;
    void vfDC() override;
    u8 getSizeType(u32 powerup) override;
    void vfE8() override;
    f32 vfEC() override;
    void vfF0() override;
    void vfF4() override;
    void vfF8() override;
    f32 vfFC() override;        // returns _473C
    void vf100(const ActorCollisionCheck::Info* info) override;
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
    bool vf250() override;
    bool vf254() override;
    bool vf25C() override;
    bool vf260() override;
    bool vf264() override;
    void vf26C() override;
    bool vf270() override;
    bool vf274() override;
    bool vf278(u32 unk) override;
    void vf27C() override;
    bool vf280() override;
    bool vf284() override;

    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, Walk);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, SideSlide);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, Unk4);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, Jump);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, SitJump);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, Crouch);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, CrouchJump);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, Fall);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, Unk10);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, Cloud);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(PlayerObject, Swim);

    bool vf360() override;
    void vf364() override;
    void vf368() override;
    void vf36C() override;
    void vf370() override;
    void vf374() override;
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
    u32* vf3AC() override;
    bool vf3B0() override;
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

    inline u8 getPlayerId()
    {
        return (spriteData1 >> 8) & 0xFF;
    }

    void* _4565;
    PlayerModelMgr modelMgr;
    u32 _4570;
    u32 _4574;
    u32 _4578;
    u8 _457C;
    Powerup targetPowerup;                  // powerup gets set to this one
    u32 _4580;
    u32 _4584;                           
    ActorCollisionCheck collisionCheckA;
    ActorCollisionCheck collisionCheckB;            
    u32 _46F8;
    u32 _46FC;
    u8 _4700;
    Vec3f _4704;                             // init to this->position (may not be vec3f? is handled by fixed point registers...)
    u32 _4710;
    u8 _4714;                               // used in sub_2044E4
    u8 _4715;                               // used in sub_2044E4
    s32 _4718;
    u32 _471C;
    u32 _4720;
    u32 _4724;
    u32 _4728;
    s32 unkActorUniqueIds[2];
    f32 _4734;
    f32 _4738;
    f32 _473C;
    void* stateChangeEvent;
    u8 _4744;
    u8 _4745;
    u32 _4748;
    f32 _474C;
    u8 _4750;
    void* deathEvent;
    u8 _4758;
    u8 _4759;
    f32 _475C;
    u8 _4760;
    u8 _4761;
    u8 _4762;
    u32 _4764;
    u32 _4768;
    u32 _476C;
    u8 _4770;
    u8 _4771;
    u32 _4774;
    u8 _4778;
    u32 _477C;
    u32 _4780;
    u8 _4784[8];                               // unk
    u32 _478C;
    u32 _4790;
    u8 _4794[8];                               // unk
    u32 _479C;
    f32 _47A0;
    u8 _47A4;
    s32 _47A8;
    u8 _47AC[4];                               // unk
    f32 _47B0;
    u8 _47B4;
    u8 _47B5[3];                               // unk (padding?)
    u32 _47B8;
    f32 _47BC;
    u32 _47C0;
    u32 _47C4;
    u32 _47C8;
    u32 _47CC;
    u8 _47D0;
    u8 _47D1;
    u32 _47D4;
    Vec3f _47D8;
    u8 _47E4;
    f32 _47E8;
    f32 _47EC;
    f32 _47F0;
    f32 _47F4;
    f32 _47F8;
    u32 _47FC;
    u32 _4800;
    u8 _4804[4];                                // unk
    u32 _4808;
    u32 _480C;
    f32 _4810;
    f32 _4814;
    f32 _4818;
    u8 _481C;
    u32 _4820;
    u32 _4824;
    u32 _4828;
    u32 _482C;
    f32 _4830;
    f32 _4834;
    f32 _4838;
    f32 _483C;
    u8 _4840;
    u8 _4841;
    u32 _4844;
    u8 _4848;
    f32 _484C;
    u32 _4850;
    u32 _4854;
    u32 _4858;
    u32 _485C;
    u32 _4860;
    u32 _4864;
    u32 _4868;
    f32 _486C;
    u16 _4870;
    u16 _4872;
    u8 _4874;
    u8 _4675;
    u8 _4876;
    f32 _4878;
    u8 _487C;
    u8 _487D;
    u32 _4880;
    u32 _4884;
    u32 _4888;
    u32 _488C;
    u32 _4890;
    u32 _4894;
    u32 _4898;
    u32 _489C;
    u32 _48A0;
    f32 _48A4;
    u32 _48A8;
    f32 _48AC;
    s32 _48B0;                                  // this is some actor id
    u32 _48B4;
    u16 _48B8;
    f32 _48BC;
    f32 _48C0;
    f32 _48C4;
    u32 _48C8;
    u32 _48CC;
    f32 _48D0;
    f32 _48D4;
    UnkEffectType unkEffect1;
    UnkEffectType unkEffect2;
    Effect effectA;
    u32 _49D0;
    Effect effectB;
    u32 _4A14;
    u8 _14A18[4];
    UnkEffectType unkEffect3;

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

size_assert(PlayerObject, 0x4A78);