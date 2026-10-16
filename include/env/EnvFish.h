#pragma once

#include "env/EnvEffectBase.h"
#include "env/EnvEffectEmitter.h"
#include "sead/gfx/seadTexture.h"

// Size: 0x44
class EnvFish : public EnvEffectBase
{
public:
    ~EnvFish();

    void init(sead::Heap* heap) override;
    void execute() override;
    void* drawLayerA(void* buffer) override;
    void* drawLayerC(void* buffer) override;
    void cleanup() override;
    bool canDraw() override;
    bool pauseDuringEvent() override;

private:
    /* 0x08 */  EnvEffectEmitter* mEmitter2;    // Emitter used for the 2nd layer.
    /* 0x0C */  sead::TextureCtrGL mTextureA;   // Texture used for the effect's first layer.
    /* 0x28 */  sead::TextureCtrGL mTextureB;   // Texture used for the effect's second layer.
};

size_assert(EnvFish, 0x44);
