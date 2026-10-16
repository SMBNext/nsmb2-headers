#pragma once

#include "env/EnvShaderBinding.h"

#include "sead/gfx/seadTexture.h"
#include "sead/seadVector.h"

// Size: 0xD88
class EnvEffectEmitter
{
public:
    typedef u8 Vertex[0x790];
    typedef u8 IndexStream[0xC];
    
public:
    EnvEffectEmitter();
    virtual ~EnvEffectEmitter();

    // Advances `mPhaseOffset` by `mVelocity`, wraps axes at `mViewScale * 100`,
    // increments `mTime`, and resets it when it exceeds the LCM of the period fields.
    void execute();

    // Fills buffer with GPU draw commands.
    // Returns pointer to the next index in the buffer.
    void* draw(void* buffer);

    // Allocates vertex/index data, sets up the texture command buffer, and builds shader commands.
    void init(sead::TextureCtrGL* texture, u8 enableShine, bool unk, sead::Heap* heap);

    // Frees VRAM allocations and the particle CPU-side buffer.
    void cleanup();
    
private:
    /* 0x004 */  u8 _4[256];                            // Unknown.
    /* 0x104 */  u32 _104;                              // Unknown.
    /* 0x108 */  u8 mCmdBuffer[128];                    // GPU command buffer.
    /* 0x188 */  u32 mCmdCount;                         // Number of commands in the GPU command buffer.
    /* 0x18C */  EnvShaderBinding mShaderBinding;       // Binding for the shader used when rendering.
    /* 0x518 */  bool mEnableShine;                     // Determines if the shine effect is enabled.
    /* 0x519 */
    /* 0x51A */
    /* 0x51B */
    /* 0x51C */  u32 _51C;                              // Unknown.
    /* 0x520 */  Vertex mVertex;                        // This is a nn::gr::CTR::Vertex.
    /* 0xCB0 */  IndexStream mIndexStream;              // This is a nn::gr::CTR::Vertex::IndexStream.
    /* 0xCBC */  u8 _CBC[12];                           // Unknown.
public:
    /* 0xCC8 */  u32 mTime;                             // Frame counter, resets at the LCM of `mPeriod.x, mPeriod.y, mPeriod.z`.
    /* 0xCCC */  sead::Vector3f mPhaseOffset;           // Accumulated velocity offset. Wraps at `mViewScale * 100`.
    /* 0xCD8 */  sead::TextureCtrGL mTexture;           // Particle atlas texture.
    /* 0xCF4 */  f32 mViewScale;                        // Scale factor for the emitter view space. Init to `360.0f`.
    /* 0xCF8 */  u8 mFollowCam;                         // When true the emitter position follows the camera. When false the emitter is fixed at `mFixedPos`. Init to true.
    /* 0xCF9 */
    /* 0xCFA */
    /* 0xCFB */
    /* 0xCFC */  sead::Vector3f mCenter;                // Camera-relative position offset. Init to `{ 0.0f, 0.0f, -360.0f }`.
    /* 0xD08 */  sead::Vector3f mFixedPos;              // Absolute world-space position (used when `mFollowCam` is false). Init to `{ 0.0f, 0.0f, 0.0f }`.
    /* 0xD14 */  u32 mParticleCount;                    // Maximum number of live particles (capped at `300` in draw). Init to `100`.
    /* 0xD18 */  f32 mScale;                            // Per-particle scale. Init to `10.0f`.
    /* 0xD1C */  sead::Color4f mTint;                   // Particle color tint. init to `{ 1.0f, 1.0f, 1.0f, 1.0f }`.
    /* 0xD2C */  sead::Vector3f mVelocity;              // World-space velocity applied to mPhaseOffset each frame. Init to `{ 0.0f, 0.0f, 0.0f }`.
    /* 0xD38 */  f32 mParallaxDepth;                    // Parallax depth multiplier. The camera-relative offset is scaled by -mParallaxDepth before being added to mPhaseOffset. Init to `1.0f`.
    /* 0xD3C */  sead::Vector3f mPeriod;                // Spawn-axis period parameters. Each axis uses a sinusoidal spawn pattern with an angular frequency of `2pi / (period * 0.001)`. Init to `{ 1.0f, 1.0f, 1.0f }`.
    /* 0xD48 */  f32 mSpawnPhase;                       // Velocity-phase period. Init to `0.0f`.
    /* 0xD4C */  sead::Vector3f mSpawnExtent;           // Spawn region half-extents around mCenter / mFixedPos. Init to `{ 0.0f, 0.0f, 0.0f }`.
    /* 0xD58 */  f32 mSpawnNoise;                       // Spawn noise amplitude. Init to `0.0f`.
    /* 0xD5C */  f32 mYPosMax;                          // Maximum Y position for particles. Init to `10000.0f`.
    /* 0xD60 */  u32 mSpriteCount;                      // Number of animation frames within the texture. init to `1`.
    /* 0xD64 */  f32 mDepthMin;                         // Min depth range for parallax rendering (Z offset = `value - 245`). Init to `0.0f`.
    /* 0xD68 */  f32 mDepthMax;                         // Max depth range for parallax rendering (Z offset = `value - 245`). Init to `0.0f`.
    /* 0xD6C */  f32 mShineSpread;                      // Init to `1.0f`.
    /* 0xD70 */  f32 mShineStrength;                    // The strength of the shine effect. Init to `1.0f`.
    /* 0xD74 */  u32 mShineAngleIdx;                    // The shine angle. Init to `0`.
    /* 0xD78 */  u32 mShinePeriod;                      // Shine cycle length in frames. Init to `60`.
    /* 0xD7C */  f32 mFogDensity;                       // Init to `0.0f`.
    /* 0xD80 */  f32 mFogScale;                         // Init to `1.0f`.
    /* 0xD84 */  f32 mTimeOffset;                       // Per-emitter time offset. Init to `0.0f`
};

size_assert(EnvEffectEmitter, 0xD88);
