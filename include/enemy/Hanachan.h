#pragma once

#include "actors/ActorUniqueID.h"
#include "collider/ActorBgCollisionCheck.h"
#include "collider/ActorCollisionCheck.h"
#include "course/Profiles.h"
#include "effect/Effect.h"
#include "enemy/Enemy.h"
#include "gfx/AnimModel.h"
#include "math/Vec.h"
#include "state/FStateID.h"
#include "sys/Allocator.h"

class HanachanBodyBase     // size: 0x6C
{
public:
    // vtable: 0x005B7B20
    virtual ~HanachanBodyBase();          // 0x0031D6B4
    virtual void createModel();           // 0x00100ECF
    virtual void cleanup();               // 0x00100ECF
    virtual void vf10();                  // Deleted
    virtual void vf14();                  // Deleted
    virtual void vf18();                  // Deleted
    virtual bool vf1C();                  // 0x0031D568
    virtual void vf20();                  // Deleted
    virtual void vf24();                  // 0x0031D2A8
    virtual void vf28();                  // 0x0031D564
    virtual void vf2C();                  // 0x004A3850
    virtual void vf30();                  // 0x004A3810
    virtual void vf34();                  // 0x0031D558

    /* 0x04 */  AnimModelBase* model;     //
    /* 0x08 */  HeapAllocator allocator;  //
    /* 0x10 */  Vec3f position;           //
    /* 0x1C */  Vec3i rotation;           //
    /* 0x28 */  u8 _28[48];               //
    /* 0x58 */  ActorUniqueID parentID;   //
    /* 0x5C */  u8 _5C;                   //
    /* 0x5D */  u8 _5D[7];                //
    /* 0x64 */  u8 _64;                   //
    /* 0x65 */  bool _65;                 //
    /* 0x66 */  u8 _66[2];                //
    /* 0x68 */  HanachanBodyBase* next;   //
};

size_assert(HanachanBodyBase, 0x6C);

struct Hanachan_collisionThing     // size: 0x170
{
    /* 0x00 */  ActorCollisionCheck check1;
    /* 0xB8 */  ActorCollisionCheck check2;
};

size_assert(Hanachan_collisionThing, 0x170);

class Hanachan : public Enemy     // size: 0x1888
{
public:
    DECLARE_PROC_GLUE_CODE(Hanachan);
    static sead::SafeString resources[];
    static ActorInfo info;

    Result onCreate() override;
    Result onDelete() override;
    Result onExecute() override;
    Result onDraw() override;

    void vf110() override;
    void levelClearDeath() override;
    void doQuakeBounce() override;

    void collisionEnemy(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    void collisionPlayer(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionFireball(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionSlide(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionGroundPound(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionTanookiTail(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;

    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(Hanachan, DieFall);
    DECLARE_STATE_ID(Hanachan, Walk);
    DECLARE_STATE_ID(Hanachan, 276);
    DECLARE_STATE_ID(Hanachan, 277);
    DECLARE_STATE_ID(Hanachan, 278);

private:
    bool sub_4162B4(Vec3f* pos);

public:
    /* 0x1060 */  Vec3f initialPos;                          //
    /* 0x106C */  u8 initialDirection;                       //
    /* 0x106D */  u8 _106D[3];                               //
    /* 0x1070 */  HanachanBodyBase head;                     //
    /* 0x10DC */  f32 _10DC;                                 //
    /* 0x10E0 */  u32 _10E0;                                 //
    /* 0x10E4 */  u8 _10E4;                                  //
    /* 0x10E5 */  u8 _10E5[3];                               //
    /* 0x10E8 */  u8 _10E8[8];                               //
    /* 0x10F0 */  u16 _10F0;                                 //
    /* 0x10F2 */  u8 _10F2[2];                               //
    /* 0x10F4 */  f32 _10F4;                                 //
    /* 0x10F8 */  u8 _10F8[4];                               //
    /* 0x10FC */  Hanachan_collisionThing collisionStuff[5]; //
    /* 0x182C */  LevelEffect effect;                        //
};

size_assert(Hanachan, 0x1888);