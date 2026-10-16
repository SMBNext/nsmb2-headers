#pragma once

#include "actors/ActorUniqueID.h"
#include "sys/Memory.h"
#include "types.h"

// size: 0x14
class fBase
{
public:
    enum class Lifecycle : u8
    {
        cCreating   = 0,    // The actor is being created.
        cActive     = 1,    // The actor is active and running.
        cDeleting   = 2,    // The actor is being deleted.
    };

    enum class GroupType : u8
    {
        cGeneric    = 0,    // The base is a generic process.
        cScene      = 1,    // The base is a scene.
        cActor      = 2,    // The base is an actor.
    };
    
    enum class Result : u32
    {
        cNone    = 0,   //
        cFailed  = 1,   //
        cSuccess = 2,   //
        cWait    = 3,   // This is an assumption, Result 3 is only ever referenced in `Scene::postDelete`.
    };

public:
    fBase();
    virtual ~fBase();

    virtual bool preCreate();
    virtual Result onCreate();
    virtual void postCreate(Result createResult);
    
    virtual bool preDelete();
    virtual Result onDelete();
    virtual void postDelete(Result deleteResult);
    
    virtual bool preExecute();
    virtual Result onExecute();
    virtual void postExecute(Result execResult);

    virtual bool preDraw();
    virtual Result onDraw();
    virtual void postDraw(Result drawResult);

    // Informs the Base that it is ready to be deleted.
    virtual void deleteReady();

    // Requests deletion of this actor.
    void requestDelete();

    // Returns the parent of this actor, or `nullptr` if there is no parent.
    fBase* getParent() const;

    // Returns the unique ID of this actor.
    ActorUniqueID getId() const { return uniqueId; }

    // Returns whether deletion has been requested for this actor.
    bool isDeleteRequested() const { return mDeleteRequested; }

    // Returns whether the actor is currently active.
    bool isActorActive() const { return mLifecycle == Lifecycle::cActive; }
    
private:
    // Executes the create operation via `commonPack`.
    Result createPack();

    // Executes the delete operation via `commonPack`.
    Result deletePack();

    // Executes the execute operation via `commonPack`.
    Result executePack();

    // Executes the draw operation via `commonPack`.
    Result drawPack();

    // Executes an operation.
    // Returns the result returned from `onFunc`, or `preFunc` if `onFunc` was not executed.
    Result commonPack(int (fBase::*onFunc)(), int (fBase::*preFunc)(), void (fBase::*postFunc)(Result));

    // Sets data used during creation.
    void setCreateData(u16 profileId, u32 settings, GroupType groupType);
    
public:
    /* 0x04 */  ActorUniqueID uniqueId;     // A unique identifier for this actor.
    /* 0x08 */  u32 settings;               // First 4 bytes from real sprite data, Initialized to 0.
    /* 0x0C */  u16 profileId;              // The profile ID of this actor.
protected:
    /* 0x0E */  Lifecycle mLifecycle;       // The lifecycle state of this actor.
    /* 0x0F */  bool mDeleteRequested;      // Written to by `deleteRequest`, read by `isDeleteRequested`.
    /* 0x10 */  bool mDeferExecute;         // True if the create operation completed, but execution isn't possible yet.
    /* 0x11 */  bool mDeferRetryCreate;     // True if the create operation has not completed, and rescheduling is needed.
    /* 0x12 */  GroupType mGroupType;       // The group type of this actor.
    /* 0x13 */ 
};

size_assert(fBase, 0x14);

#define DECLARE_PROC_GLUE_CODE(CLASS)   \
public:                                 \
    void* operator new(size_t size);    \
    void operator delete(void* p);      \
    static fBase* build();              \
    static void destroy(fBase* p);

#define CREATE_PROC_GLUE_CODE(CLASS)                                                \
    void* CLASS::operator new(size_t size) { return AllocFromActorHeap(size); }     \
    void CLASS::operator delete(void* p) { FreeToActorHeap(p); }                    \
    fBase* CLASS::build() { return new CLASS; }                                     \
    void CLASS::destroy(fBase* p) { if (p) delete p; }
