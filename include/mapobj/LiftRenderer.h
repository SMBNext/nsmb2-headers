#pragma once

#include "sys/ResourceMgr.h"
#include "gfx/AnimModel.h"

class LiftRenderer  // size: 0x7C
{
public:
    enum Type : u32
    {
        TYPE_HAN_WOOD = 0,
        TYPE_HAN_STONE = 1,
        TYPE_KINOKO_YOKO = 2,
        TYPE_HAN_WOOD_GHOST = 3,
        TYPE_HAN_WOOD_TOTEM = 4,
        TYPE_BOSS_KOOPA = 5,
        TYPE_KINOKO_SHISO = 6,
    };

    LiftRenderer()
        : rotation({ 0, 0, 0 }), centerBlockWidth(0.0f),
          scale(1.0f), _68(0.0f), blockWidth(0), type(0) { }

    void init();
    void cleanup();
    void execute(const Vec3f& position, f32 unk);
    void draw();

    Resource* resource;         // 0
    Model* models[3];           // 4
    HeapAllocator allocator;    // 10
    Vec3f _18;
    Vec3f _24;
    Vec3f _30;
    u8 _unk3C[0x54-0x3C];
    Vec3i rotation;             // 54
    f32 centerBlockWidth;       // 60
    f32 scale;
    f32 _68;
    u32 blockWidth;             // 6C
    u32 type;                   // 70
    u32 _74;
    u32 _78;

    static const char* LiftResources[];
    static const char* LiftSegments[];
};
