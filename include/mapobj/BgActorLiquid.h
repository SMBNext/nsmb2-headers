#pragma once

#include "actors/ActorMultiState.h"
#include "collider/RectCollider.h"
#include "gfx/LiquidTopRenderer.h"
#include "gfx/Model.h"
#include "sead/seadListImpl.h"

class BgActorBase;
class LiquidSplashReq;

class LiquidTop
{
public:
    enum class Type : u8
    {
        WATER = 0,
        POISON = 1,
        LAVA = 2,
    };

    static constexpr u32 cNumRippleTypes = 13;

    static const f32 cRippleWaveCounts[cNumRippleTypes];
    static const f32 cRippleHeightScales[cNumRippleTypes];
    static const f32 cRippleSpeeds[cNumRippleTypes];            // In degrees (as float?)
    static const f32 cRippleFadeSpeeds[cNumRippleTypes];
    static const f32 cRippleFadeLimits[cNumRippleTypes];
    static const f32 cRippleFadePowers[cNumRippleTypes];
    static const f32 cRippleMinAmplitudes[cNumRippleTypes];

    class Ripple
    {
    public:
        static constexpr u32 cNumWaves = 0x40;
        static constexpr u32 cNumRipples = 0x20;

        enum class State : u8
        {
            cWaiting  = 0,              // The ripple front has not reached this column yet
            cRippling = 1,
            cDone     = 2,
        };

        f32 fade;                           // 000  Used occasionally as a pointer for some reason
        f32 amplitude[cNumWaves];           // 004
        f32 targetAmplitude[cNumWaves];     // 104
        s32 phase[cNumWaves];               // 204
        s32 center;                         // 304  Center "column"
        State state[cNumWaves];             // 308
        u32 type;                           // 348
        bool enabled;                       // 34C
        LiquidSplashReq* splash;            // 350
        f32 count;                          // 354  Half-width of the ripple, in columns / steps
        f32 heightScale;                    // 358
        s32 speed;                          // 35C
        f32 fadeSpeed;                      // 360
        f32 fadeLimit;                      // 364
        f32 fadePower;                      // 368
        f32 minAmplitude;                   // 36C
        sead::ListNode node;                // 370

        static Ripple* fromNode(sead::ListNode* node)
        {
            return reinterpret_cast<Ripple*>(reinterpret_cast<uptr>(node) - offsetof(Ripple, node));
        }
    };
    size_assert(Ripple, 0x378);

    virtual ~LiquidTop();

    LiquidTopRenderer* renderer;         // 4
    Vec3f position;                      // 8
    u32 _14;                             // 14
    u32 _18;                             // 18
    u32 _1C;                             // 1C
    Vec3f rendererPosition;              // 20
    Mtx34 rendererMtx;                   // 2C
    f32 width;                           // 5C
    f32 widthDiv8;                       // 60
    s32 widthDiv8Fixed;                  // 64
    f32 unkXScalarRelated;               // 68     If this is 0.0, the X axis scalar is clamped to 1.0
    f32 xAxisScalar;                     // 6C     Most likely supposed to always be 1.0
    u32 segmentStart;                     // 70     First visible column, set in updateWaves
    u32 segmentEnd;                       // 74     End of the visible column range, set in updateWaves
    u32 unkInnerTimer;                   // 78     Functions like a clock; when the inner timer reaches the
    u32 unkOuterTimer;                   // 7C     cap, the outer timer is updated
    s32 wavePositions[2];                // 80
    s32 wavePhases[2];                   // 88     May be wrong
    s32 waveSpeeds[2];                   // 90
    u32 _98;                             // 98
    u32 _9C;                             // 9C
    s32 waveWidths[2];                   // A0
    f32 waveHeights[2];                  // A8
    Type type;                           // B0
    bool hasZone;                        // B1
    u8 _B2[2];                           // B2
    sead::ListImpl rippleList;            // B4
    Ripple* freeRipple;                   // C0
    Ripple* ripplePool;                   // C4
    u32 ripplePoolSize;                   // C8
    Ripple ripples[Ripple::cNumRipples];  // CC
    Resource resource;                    // 6FCC
    sead::TextureCtrGR texture;           // 7180
};

size_assert(LiquidTop, 0x7194);


class BgActorBase : public ActorMultiState
{
    SEAD_RTTI_OVERRIDE(BgActorBase, ActorMultiState);

public:
    Result onExecute() override;
    Result onDraw() override;

    virtual void vf110();           // deleted
    virtual void setZPosition();
    virtual void vf118();           // deleted
    virtual void vf11C();
    virtual void vf120();
    virtual void vf124();

    HeapAllocator allocator;        // FEC
    Model* _FF4;                    // FF4
    u32 _FF8;                       // FF8
    u32 _FFC;                       // FFC
    u32 _1000;                      // 1000
    Vec3f _1004;                     // 1004
    RectCollider collider;          // 1010
    u8 _unk1280[0x12A4-0x1280];     // 1280
    u32 hasLocation;                // 12A4
    u32 _12A8;                      // 12A8
    f32 topLevel;                   // 12AC
    f32 _12B0;                      // 12B0
    f32 width;                      // 12B4
    f32 _12B8;                      // 12B8
    u32 _12BC;                      // 12BC
    u32 _12C0;                      // 12C0
    u32 _12C4;                      // 12C4
    f32 _12C8;                      // 12C8
    u32 _12CC;                      // 12CC
    u8 _12D0;                       // 12D0
    u8 _12D1;                       // 12D1
    u16 _12D2;                      // 12D2
    u8 _12D4;                       // 12D4
    bool hasCollider;               // 12D5
    bool hasTop;                    // 12D6
    LiquidTop top;                  // 12D8
    u32 allocator2[2];              // 846C
    u8 _unk8474[0x8478-0x8474];     // 8474
    u32 _8478;                      // 8478
    u32 _847C;                      // 847C
    u64 _8480;                      // 8480
    u32 _8488;                      // 8488
    u32 _848C;                      // 848C
    u32 _8490;                      // 8490
    u32 _8494;                      // 8494
    u32 _8498;                      // 8498
    u32 _849C;                      // 849C
    u16 _84A0;                      // 84A0
    u8 _84A2;                       // 84A2
    u8 _84A3;                       // 84A3
    u8 _unk84A4[0x84A8-0x84A4];     // 84A4
};

size_assert(BgActorBase, 0x84A8);
