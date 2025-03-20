#pragma once

#include "actors/Enemy.h"
#include "gfx/AnimModel.h"

// Size: 0x1088
// Vtable: 0x005CAC9C
class DoorBase : public Enemy
{

    SEAD_RTTI_OVERRIDE(DoorBase, Enemy);

public:

    DoorBase();

    s32 onCreate() override;
    s32 onDelete() override;
    s32 onExecute() override;
    s32 onDraw() override;

    DECLARE_STATE_VIRTUAL_ID_BASE(DoorBase, Open);      //
    DECLARE_STATE_VIRTUAL_ID_BASE(DoorBase, Close);     //
    DECLARE_STATE_VIRTUAL_ID_BASE(DoorBase, Idle);      //
    DECLARE_STATE_VIRTUAL_ID_BASE(DoorBase, Vanish);    // Used by fake door

    virtual bool isOpenable();                  //
    virtual bool isFakeDoor();                  //
    virtual void vf20C();                       // Deleted
    virtual void vf210();                       // Deleted
    virtual void createModels();                //
    virtual void setupCollisionCheck();         // 
    virtual void vf21C();                       // Called in onCreate, used by ghost house door
    virtual void vf220();                       // Called in executeState_Idle, used by ghost house door
    virtual void setAnimOpen();                 //
    virtual void playSoundOpen();               //
    virtual void setAnimClose();                //
    virtual void playSoundClose();              //
    virtual void playSoundMove();               // 
    virtual void setAnimIdle();                 // Sets the current anim to the idle anim

    // Address: 0x0040B628
    static bool collisionCallback(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);

    // Address: 0x0040B834
    void spawnAppearEffect();

    // Address: 0x0040B888
    bool isEventActive();    

    // Address: 0x0040BD08
    void updateModelMatrix();

    // Address: 0x0040BE50
    void setupModelMatrix();    

protected:
    AnimModelBase* mModel;      //
    Resource* mResource;        //
    HeapAllocator mAllocator;   //
    s32 _1070;                  //
    s32 _1074;                  //
    s32 _1078;                  //
    bool _107C;                 // Set to True in ctor for Toride Castle and Koopa doors
    u8 _107D[3];                // Probably padding
    s32 _1080;                  //
    bool mIsVisible;            //
    u8 _1085[3];                // Probably padding
};

size_assert(DoorBase, 0x1088);