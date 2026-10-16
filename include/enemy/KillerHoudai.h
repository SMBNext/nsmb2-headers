#pragma once

#include "enemy/Enemy.h"
#include "gfx/Model.h"
#include "collider/RectCollider.h"


class KillerHoudai : public Enemy
{
    SEAD_RTTI_OVERRIDE(KillerHoudai, Enemy);

public:
    DECLARE_PROC_GLUE_CODE(KillerHoudai);
    static sead::SafeString resourcesNormal[];
    static ActorInfo infoNormal;
    static sead::SafeString resourcesMag[];
    static ActorInfo infoMag;
    static sead::SafeString resourcesUpDown[];
    static ActorInfo infoUpDown;

    KillerHoudai();
    virtual ~KillerHoudai();

    Result onCreate() override;
    Result onDelete() override;
    Result onExecute() override;
    Result onDraw() override;

    void initUpDown();

    bool checkShoot();
    bool checkShootUpDown();
    void canSpawnForCurrentView();
    bool updateShootAnimation();

    void createModelsNormal();
    void createModelsMag();
    void createModelUpDown();

    void drawNormal();
    void drawMag();
    void drawUpDown();
    void drawBroken();

    void drawModelA(const Mtx34& transformMatrix);
    void drawModelB(const Mtx34& transformMatrix);
    void drawModelC(u32 modelIndex, const Mtx34& transformMatrix);

    static void topCallback(BgCollision* colliderSelf, ActorBgCollisionCheck* otherMgr);
    static void sideCallback(BgCollision* colliderSelf, ActorBgCollisionCheck* otherMgr);

    DECLARE_STATE_ID(KillerHoudai, Normal);
    DECLARE_STATE_ID(KillerHoudai, UpDown);
    DECLARE_STATE_ID(KillerHoudai, Break);

    Model* modelA;
    Model* modelB;
    Model* modelGoldA;
    Model* modelGoldB;
    Resource* resouce;
    HeapAllocator allocator;
    Model* modelsC[16];
    Model* modelsGoldC[16];
    u8 _unk10FC[4];
    RectCollider collider;
    s32 spawnedKillerIds[20];
    u32 _13C0;
    u32 _13C4;
    u32 _13C8;
    Vec3f _13CC;
    Vec3f _13D8;
    Vec3f stemPartPositions[16];
    Vec3f _14A4;
    Vec3f _14B0;
    Vec3f _14BC[16];
    u32 _157C;
    u32 _1580;
    u32 _1584;
    u32 _1588;
    u32 _158C;
    u32 _1590;
    Vec3f _1594[16];
    Vec3f _1654;
    Vec3f _1660;
    Vec3f _166C;
    u32 _1678;
    u32 _167C;
    u32 _1680;
    f32 _1684;
    f32 upDownTopHeight;
    f32 upDownBottomHeight;
    f32 upDownCurrentHeight;
    f32 upDownSpeed;
    u32 isUpsideDown;
    u32 shootDelay;
    u32 isSearchKiller;
    u32 isSearchKillerExplode;
    u32 type;
    u32 _16AC;
    u32 stemPartCount;
    u32 shootDirection;
    u32 _16B8_nybble5related;
    u32 _16BC;
    u8 _16C0;
    bool isShootAnimationUpdateEnabled;
    u16 breakEraseTimer;
    u8 _16C4;
    bool isCullCheckDisabled;
    u8 _16C6;
    u8 upDownShootMask;
    bool isGoldRingActive;
    u8 _unk16C9[7];
};
