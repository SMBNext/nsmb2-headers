#pragma once

#include "enemy/Enemy.h"
#include "gfx/Model.h"
#include "collider/PolylineCollision.h"


class KillerBase : public Enemy
{
    SEAD_RTTI_OVERRIDE(KillerBase, Enemy);

public:
    Result onCreate() override;
    Result onDelete() override;
    Result onExecute() override;
    Result onDraw() override;

    void levelClearDeath() override;
    void collisionEnemy(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    void collisionPlayer(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionStarMega(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionShell(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    bool collisionFireball(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck) override;
    
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(KillerBase, DieFumi);
    DECLARE_STATE_VIRTUAL_ID_OVERRIDE(KillerBase, DieFall);

    virtual void update();
    virtual void canBahp();
    virtual void removeCollisionCheckEx();
    virtual void addCollisionCheckEx();

    static KillerBase* spawnNormalKiller(const Vec3f& position, u32 spriteData, ActorBase* parent, s32 parentId, u32 maxCurrent);
    static KillerBase* spawnSearchKiller(const Vec3f& position, u32 spriteData, ActorBase* parent, s32 parentId);

    /* 0x1060 */  u8 _unk1060[0x1FD4 - 0x1060];    // Undocumented
};

size_assert(KillerBase, 0x1FD4);
