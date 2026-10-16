#pragma once

#include "enemy/Enemy.h"
#include "gfx/AnimModel.h"

// Size: 0x1088
// Vtable: 0x005CAC9C
class DoorBase : public Enemy
{
    SEAD_RTTI_OVERRIDE(DoorBase, Enemy);

public:
    enum class DoorUnkState : s32
    {
        Idle = 0x0,
        Enter = 0x1,
        Exit = 0x2,
        Player_Entered = 0x3,
    };

    DoorBase();

    Result onCreate() override;
    Result onDelete() override;
    Result onExecute() override;
    Result onDraw() override;

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
    static void collisionCallback(ActorCollisionCheck* thisCheck, ActorCollisionCheck* otherCheck);

    // Address: 0x0040B834
    void spawnAppearEffect();

    // Address: 0x0040B888
    bool isEventActive();    

    // Address: 0x0040BD08
    void updateModelMatrix();

    // Address: 0x0040BE50
    void setupModelMatrix();    

protected:
    AnimModelBase* model;       //
    Resource* resource;         //
    HeapAllocator allocator;    //
    DoorUnkState doorUnkState;  //
    s32 _1074;                  // Set to 1 when executing Open, set to 0 in finalizing Open
    s32 _1078;                  // Set to 1 when opened (is open?), set to 0 in initializing Idle
    bool doMusicFade;           // Set to True for Toride, Castle and Koopa doors
    u8 _107D[3];                // Probably padding
    s32 _1080;                  //
    bool isVisible;             //
    u8 _1085[3];                // Probably padding
};

size_assert(DoorBase, 0x1088);