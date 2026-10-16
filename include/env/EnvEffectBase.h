#pragma once

#include "sead/heap/seadHeap.h"
#include "env/EnvEffectEmitter.h"

// Size: 0x8
class EnvEffectBase
{
public:
    virtual ~EnvEffectBase() = default;

    // Used to initialize any state and resources (e.g. textures & emitters).
    virtual void init(sead::Heap* heap);

    // Per frame update function.
    virtual void execute() = 0;

    // Render callback for the first draw layer.
    // Exact purpose unknown.
    // Draws below tiles.
    virtual void* drawLayerA(void* buffer);

    // Render callback for the second draw layer.
    // Exact purpose unknown.
    // Draws above tiles.
    virtual void* drawLayerB(void* buffer);

    // Render callback for the third draw layer.
    // Exact purpose unknown.
    // Draws above tiles.
    virtual void* drawLayerC(void* buffer);

    // Used to cleanup and delete any resources (e.g. textures & emitters).
    virtual void cleanup() = 0;

    // Used to determine if the effect should draw for the current frame.
    virtual bool canDraw() = 0;

    // Used to determine if the effect should pause during an event (E.g. player hit).
    virtual bool pauseDuringEvent() = 0;

    // Spawns a burst of 4 particles at a world position with random
    // velocities.  Used by EnvEffectHolder::createKillerSmoke etc.
    void emitBurst(const sead::Vector3f& position);

protected:
    /* 0x4 */  EnvEffectEmitter* mEmitter;      // Pointer to the emitter used for the effect.
};

size_assert(EnvEffectBase, 0x8);
