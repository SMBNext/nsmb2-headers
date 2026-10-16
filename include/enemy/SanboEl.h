#pragma once

#include "gfx/AnimModel.h"
#include "effect/Effect.h"
#include "collider/ActorCollisionCheck.h"

class Sanbo;
class SanboEl;
class SanboRenderer;

// Size: 0x28
class SanboElCtrl
{
public:
    using Func = void (SanboElCtrl::*)();

public:
    enum class Mode : u8
    {
        IDLE        = 0,
        STILL       = 1,
        REMOVED     = 2,
        FALL        = 3,
        UNK_4       = 4,
    };

    // Address: 0x002493C8
    void setMode(Mode mode);

public:
    Vec3f positionOffset;
    u32 _C;
    u32 _10;
    s32 rotation;
    SanboElCtrl::Func curFunc;
    SanboElCtrl::Mode curMode;
    u8 direction;
    u8 _22;                               // some kind of status flag, is set to 1 on first pass of a state, and 2 in the setState func if some condition is met
    u8 _23;                               // unk
    SanboEl* parent;
};

size_assert(SanboElCtrl, 0x28);


// Size: 0x188
class SanboEl
{
public:
    struct Transform
    {
        Vec3f position;
        Vec3f rotation;
        Vec3f scale;
    };

    enum class ElementType : u8
    {
        BODY  = 0,
        HEAD  = 1,
    };

public:
    SanboEl() = default;

    virtual ~SanboEl() = default;

    // Address:
    virtual ElementType getElementType() = 0;

    SanboRenderer *model;
    HeapAllocator allocator;
    SanboElCtrl ctrl;
    Transform transform;                  // position, rotation, scale
    u8 _5C[4];                            // unk
    u32 initialIndex;                     // the initial index of this element within the Sanbo
    u32 unkIndex;                         // set in 0x3F6F3C
    u32 currentIndex;                     // the current index of this element
    bool isAlive;                         // isAlive?
    u8 _6D[3];                            // unk
    ActorCollisionCheck collisionCheck;
    Sanbo *parent;
    UnkEffectType sandEffect;
};

size_assert(SanboEl, 0x188);


// Size: 0x14
// Vtable: 0x005AF32C
class SanboRenderer
{
public:
    // Address: 0x002A6E64
    SanboRenderer();

    // Address: 0x002A6E88
    virtual ~SanboRenderer();

    // Address: 0x002A6CFC
    virtual bool vf8();

    virtual bool createModels() = 0;
    virtual bool destroyModels() = 0;

    // Address: 0x002A6E34
    void drawModel();

    // Address: 0x002A6D00
    void setTransform(const SanboEl::Transform& transform);

    // Address: 0x002A6CC0
    void setDeathDepth();

public:
    Resource* resource;
    AnimModel<0,0,0>* model;                    // AnimModel<0,0,0>
    HeapAllocator allocator;
};

size_assert(SanboRenderer, 0x14);
