#pragma once

#include "types.h"

class fBase         // size: 0x14
{
public:
    fBase();
    virtual ~fBase();

    virtual int beforeCreate();
    virtual int onCreate();
    virtual void afterCreate(int);
    
    virtual int beforeDelete();
    virtual int onDelete();
    virtual void afterDelete(int);
    
    virtual int beforeExecute();
    virtual int onExecute();
    virtual void afterExecute(int);

    virtual int beforeDraw();
    virtual int onDraw();
    virtual void afterDraw(int);

    virtual void onErase();

    void erase();

    fBase* getParent();
    static fBase* search(u32 unused, s32 id);                       // not part of this class
    static inline fBase* search(s32 id) { return search(0, id); }


    s32 id;         // 4    Inited to -1
    u32 settings;   // 8    First 4 bytes from real sprite data, inited to 0
    u16 profileId;  // C    Inited to 0
    u8 created;     // E    ^
    u8 erased;      // F    ^
    u8 _10;         // 10   ^   Set to 1 in ProcMgr::createAll if _1142C == 3
    u8 _11;         // 11   ^
    u8 _12;         // 12   ^
    u8 direction;   // 13   ^
};



void* AllocFromActorHeap(size_t size);
void FreeToActorHeap(void* ptr);

#define DECLARE_PROC_GLUE_CODE(CLASS)   \
    void* operator new(size_t size);    \
    void operator delete(void* p);      \
    static fBase* build();              \
    static void destroy(fBase* p);

#define CREATE_PROC_GLUE_CODE(CLASS)                                                \
    void* CLASS::operator new(size_t size) { return AllocFromActorHeap(size); }     \
    void CLASS::operator delete(void* p) { FreeToActorHeap(p); }                    \
    fBase* CLASS::build() { return new CLASS; }                                     \
    void CLASS::destroy(fBase* p) { if (p) delete p; }
