#pragma once

#include "env/EnvEffectBase.h"
#include "env/EnvEffectEmitter.h"
#include "sead/gfx/seadTexture.h"

// Size: 0x28
class EnvSnow : public EnvEffectBase
{
public:
    ~EnvSnow();

    void init(sead::Heap* heap) override;
    void execute() override;
    void* drawLayerA(void* buffer) override;
    void* drawLayerC(void* buffer) override;
    void cleanup() override;
    bool canDraw() override;
    bool pauseDuringEvent() override;

private:
    /* 0x8 */  EnvEffectEmitter* mEmitter2;     // Emitter used for the 2nd layer.
    /* 0xC */  sead::TextureCtrGL mTexture;     // Texture used for the effect.
};

size_assert(EnvSnow, 0x28);
