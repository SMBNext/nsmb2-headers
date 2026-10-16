#pragma once

#include "actors/Carry.h"
#include "effect/Effect.h"
#include "gfx/AnimModel.h"
#include "sys/Allocator.h"

class Resource;

// Size: 0x1128
class Bomhei : public Carry
{
public:
    DECLARE_PROC_GLUE_CODE(Bomhei);
    static sead::SafeString resources[];
    static ActorInfo sActorInfo;

    Result onCreate() override;
    Result onDelete() override;
    bool preExecute() override;
    Result onExecute() override;
    Result onDraw() override;

    void powActivated() override;

    void collisionEnemy(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    void collisionPlayer_Awake(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    void collisionPlayer_Sleep(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionFireball(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionSlide(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionGroundPound(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionTanookiTail(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    void reactFumiProc(ActorBase* other) override;

    void createModels();
    void updateModelMatrix();

    DECLARE_STATE_ID(Bomhei, Walk);
    DECLARE_STATE_ID(Bomhei, Turn);
    DECLARE_STATE_ID(Bomhei, 0x1EC);
    DECLARE_STATE_ID(Bomhei, 0x1ED);
    DECLARE_STATE_ID(Bomhei, 0x1EE);
    DECLARE_STATE_ID(Bomhei, Explosion);
    DECLARE_STATE_ID(Bomhei, 0x1F3);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(Bomhei, Carry);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(Bomhei, Sleep);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(Bomhei, Slide);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(Bomhei, DieFumi);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(Bomhei, DieFall);

public:
    /* 0x107C */  AnimModel<1, 1, 0>* model;        //
    /* 0x1080 */  Resource* resource;               //
    /* 0x1084 */  HeapAllocator allocator;          //
    /* 0x108C */  LevelEffect effect;               // The burning effect while the fuse is lit.
    /* 0x10E8 */  u8 _10E8[4];                      //
    /* 0x10EC */  s32 bombTimer;                    // Inited to -1; counts down while the fuse is lit.
    /* 0x10F0 */  u8 _10F0[40];                     //
    /* 0x1118 */  u32 _1118;                        // Inited to 1.
    /* 0x111C */  f32 _111C;                        // Inited to 130.0.
    /* 0x1120 */  u8 _1120[4];                      //
    /* 0x1124 */  AnimModel<1, 1, 0>* paraModel;    // Uused by ParaBomhei.
};

size_assert(Bomhei, 0x1128);