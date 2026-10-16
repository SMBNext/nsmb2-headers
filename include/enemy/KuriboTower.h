#pragma once

#include "collider/ActorBgCollisionCheck.h"
#include "collider/ActorCollisionCheck.h"
#include "course/Profiles.h"
#include "enemy/Enemy.h"
#include "gfx/AnimModel.h"
#include "math/Vec.h"
#include "state/FStateID.h"
#include "state/FStateVirtualID.h"
#include "sys/Allocator.h"

class Resource;

// Size: 0x1A40
class KuriboTower : public Enemy
{
    SEAD_RTTI_OVERRIDE(KuriboTower, Enemy);
public:
    DECLARE_PROC_GLUE_CODE(KuriboTower);
    static sead::SafeString resources[];
    static ActorInfo info;
    static f32 xSpeeds[2];
    static ActorCollisionCheck::CollisionData apInfo1;
    static ActorCollisionCheck::CollisionData apInfo2;

    KuriboTower();
    virtual ~KuriboTower();

    Result onCreate() override;
    Result onDelete() override;
    Result onExecute() override;
    Result onDraw() override;

    void vf110() override;                                  // Called on nearby Gold Fireball hit
    void vf114() override;                                  // Called when POW block is triggered
    bool damagePlayer(PlayerBase* player) override;
    void powActivated() override;
    void levelClearDeath() override;
    bool inBounds(const sead::BoundBox2f& bounds) const override;

    void collisionEnemy(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    void collisionPlayer(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionStarMega(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionSlide(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionGroundPound(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionPipeCannon(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionTanookiTail(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionShell(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionFireball(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;

    void onDefeatQuake(QuakeCollisionType quakeType, s8 playerId) override;
    void fumiJumpSet(PlayerBase* player) override;
    void giveScore(PlayerBase* player) override;
    void doQuakeBounce() override;

    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(KuriboTower, DieFumi);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(KuriboTower, DieFall);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(KuriboTower, DieSmoke);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(KuriboTower, DieOther);

    DECLARE_STATE_ID(KuriboTower, 2C9);
    DECLARE_STATE_ID(KuriboTower, 2CA);
    DECLARE_STATE_ID(KuriboTower, 2CB);

    virtual void vf1D4();                            // Toggles between StateID_2CB and StateID_2CA
    virtual void vf1D8(PlayerBase* player);          // Turns towards the player and toggles state
    virtual int vf1DC();                             // Spawns a stack of Kuribos
    virtual int vf1E4();                             // Returns 1

    int sub_231CDC();
    void reduceStack(int a2);
    void sub_23215C(u32 kuriboIdx, int a3);
    int sub_232234();
    int sub_232484();
    void sub_232698(int a2);
    int sub_232A18();
    void setAnim(u32 kuriboIdx, const sead::SafeString& animName, PlayPolicy playPolicy, f32 frameStep);
    int sub_232D20(sead::Vector3f* kuriboPosition, int a3);
    int sub_232E38();
    void sub_233098(u32 kuriboIdx);
    int sub_233364();
    int sub_233E70();
    int sub_2344D4(u32 kuriboIdx, int a3, const sead::Vector3f* kuriboPosition);
    void sub_2358E4(const sead::SafeString& animName, PlayPolicy playPolicy, f32 frameStep);

public:
    /* 0x1060 */  ActorBgCollisionCheck::Sensor aboveSensor;             //
    /* 0x106C */  ActorBgCollisionCheck::Sensor belowSensor;             //
    /* 0x1078 */  ActorBgCollisionCheck::Sensor sideSensor;              //
    /* 0x1084 */  AnimModelBase* model;                                  //
    /* 0x1088 */  AnimModelBase* modelGold;                              //
    /* 0x108C */  AnimModelBase* kuriboModels[8];                        //
    /* 0x10AC */  AnimModelBase* kuriboModelsGold[8];                    //
    /* 0x10CC */  AnimModelBase* _10CC[8];                               //
    /* 0x10EC */  AnimModelBase* _10EC[8];                               //
    /* 0x110C */  ActorCollisionCheck kuriboActivePhysics[8];            //
    /* 0x16CC */  Resource* resource;                                    //
    /* 0x16D0 */  Vec3f kuriboPositions[8];                              //
    /* 0x1730 */  Vec3f _1730[8];                                        //
    /* 0x1790 */  Vec3f _1790[8];                                        //
    /* 0x17F0 */  Vec3f _17F0[8];                                        //
    /* 0x1850 */  f32 _1850[8];                                          //
    /* 0x1870 */  Vec3i _1870[8];                                        //
    /* 0x18D0 */  Vec3i kuriboRotations[8];                              //
    /* 0x1930 */  u32 _1930;                                             //
    /* 0x1934 */  u32 _1934[8];                                          //
    /* 0x1954 */  u32 _1954[8];                                          //
    /* 0x1974 */  s32 _1974;                                             //
    /* 0x1978 */  s32 kuriboModelIndices[8];                             //
    /* 0x1998 */  s32 _1998;                                             //
    /* 0x199C */  HeapAllocator allocator;                               //
    /* 0x19A4 */  u8 _19A4[4];                                           //
    /* 0x19A8 */  u32 _19A8;                                             //
    /* 0x19AC */  u8 _19AC[12];                                          //
    /* 0x19B8 */  u32 _19B8;                                             //
    /* 0x19BC */  u8 _19BC[4];                                           //
    /* 0x19C0 */  s32 _19C0;                                             //
    /* 0x19C4 */  u8 _19C4[4];                                           //
    /* 0x19C8 */  u32 kuriboCount;                                       //
    /* 0x19CC */  u32 _19CC;                                             //
    /* 0x19D0 */  u32 kuriboCount2;                                      //
    /* 0x19D4 */  Direction childKillDirection;                          //
    /* 0x19D5 */  u8 _19D5;                                              //
    /* 0x19D6 */  u8 _19D6;                                              //
    /* 0x19D7 */  bool isGold;                                           //
    /* 0x19D8 */  u8 _19D8;                                              //
    /* 0x19D9 */  u8 _19D9;                                              //
    /* 0x19DA */  u8 _19DA;                                              //
    /* 0x19DB */  u8 _19DB[101];                                         //
};

size_assert(KuriboTower, 0x1A40);