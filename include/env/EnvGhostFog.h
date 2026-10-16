#pragma once

#include "env/EnvEffectBase.h"
#include "sead/gfx/seadTexture.h"

// Size: 0x24
class EnvGhostFog : public EnvEffectBase
{
public:
    ~EnvGhostFog();

    void init(sead::Heap* heap) override;
    void execute() override;
    void* drawLayerC(void* buffer) override;
    void cleanup() override;
    bool canDraw() override;
    bool pauseDuringEvent() override;

private:
    /* 0x8 */  sead::TextureCtrGL mTexture;     // Texture used for the effect.
};

size_assert(EnvGhostFog, 0x24);
