#pragma once

#include "sead.h"

#include "course/Course.h"


class BgScrollMgr_B4  // Size 0x10
{
public:

    enum TrackingDirection : u8
    {
        TRACKING_DIR_RIGHT,
        TRACKING_DIR_LEFT,
        TRACKING_DIR_DOWN,
        TRACKING_DIR_UP,
    };

    u8 boundingBlockId;                     // 0
    u8 zoomType;                            // 1 - inited to Zone->padE[0]
    u8 zoomId;                              // 2 - inited to Zone->padE[1]
    u8 zoomChange;                          // 3 - inited to Zone->padE[2]
    u8 multiplayerTracking;                 // 4
    u8 progressPathId;                      // 5
    u8 _6;                                  // 6 - inited to Zone->pad19[0]
    u8 _7;                                  // 7
    TrackingDirection trackingDirPrimary;   // 8
    TrackingDirection trackingDirSecondary; // 9

    Course::ZoneBounding* zoneBounding;     // C
};

class BgScrollMgr_CameraStopMgr   // Size 0x538
{
public:

    class CamStopEntry  // Size 0x24
    {
    public:

        enum LimitDirection : u32
        {
            LIMIT_DIR_LEFT,
            LIMIT_DIR_RIGHT,
            LIMIT_DIR_DOWN,
            LIMIT_DIR_UP,
        };

        // u32 vtable;

        LimitDirection limitDirection;  //  4
        f32 xPosUpper;                  //  8 
        f32 xPosLower;                  //  C
        f32 yPosLeft;                   // 10
        f32 yPosRight;                  // 14
        Vec2f boundryPosition;           // 1C
        u8 multiplayerSetting;          // 1D
        u8 priority;                    // 1E
        bool isPermeable;               // 1F
        bool shouldKillInMultiplayer;   // 20
        bool isPaired;                  // 21
    };
    
    sead::BoundBox2f zoneBound;                             // 0
    sead::FixedPtrArray<CamStopEntry, 32> camStopEntries;   // 10
    u8 buffer[0x48C];                                       // 9C Unsure if correct
    f32 _528;                                               // 528 
    f32 _52C;                                               // 52C - Set to pos.x + 160 by warpCannon
    f32 _530;                                               // 530
    f32 _534;                                               // 534
};

class BgScrollMgr_ScrollViewMgr     // Size 0x1F0
{
public:

    struct scrollViewEntry   // Size 0x18
    {
        sead::BoundBox2f bounding;  // 0
        f32 ScrollDistHorizontal;   // 10 - inited to 0
        f32 ScrollDistVertical;     // 14 - inited to 0
    };

    scrollViewEntry** entryPtr;             // 0
    u32 maxEntries;                         // 4
    u32 _8;                                 // 8
    u32 entryCount;                         // C
    scrollViewEntry scrollViewEntries[20];  // 10

};

class BgScrollMgr_BoundingMgr     // Size 0x4
{
public:
    f32 verticalScrollingDistance;  // 0
};

class BgScrollMgr_C4  // Size 0x24
{
public:

    class BgScrollMgr_C4_20  // Size 0x1C
    {
    public:
        u32 vtable;

        u32 _4;             // 4
        u32 _8;             // 8
        u32 _C;             // C
        u32 _10;            // 10
        u32 _14;            // 14
        u32 _18;            // 18
    };

    u8 zoom_type;                       // 0
    u8 zoom_id;                         // 1
    u8 _2;                              // 2
    u8 _3;                              // 3
    u8 _4;                              // 4
    u8 _5;                              // 5
    u16 _6;                             // 6
    u8 _8;                              // 8
    u8 _9;                              // 9
    bool primaryTrackingIsVertical;     // A
    u8 _B;                              // B
    u8 _C;                              // C
    u8 _D;                              // D
    u8 _E;                              // E
    u8 _F;                              // F
    float _10;                          // 10
    u32 _14;                            // 14
    u32 zoomSpeed;                      // 18
    bool _1C;                           // 1C
    BgScrollMgr_C4_20 *_20;           // 20
};

class BgScrollMgr_C8  // Size 0x1C
{
public:

    u16 _0;     // 0
    u32 _4;     // 4
    f32 _8;     // 8  - Player X pos
    f32 _C;     // C  - Player X pos copy
    f32 _10;    // 10 - Player Y pos
    f32 _14;    // 14 - Player Y pos copy
    u8 _18;     // 18
    u8 _19;     // 19
};


class BgScrollMgr_CC  // Size 0x94
{
public:
    u16 _0;     // 0
    u32 _4;     // 4
    f32 _8;     // 8
    f32 _C;     // C
    f32 _10;    // 10
    f32 _14;    // 14
    u32 _18;    // 18
    u32 _1C;    // 1C
    u32 _20;    // 20
    f32 _24;    // 24
    u32 _28;    // 28
    u32 _2C;    // 2C
    u32 _30;    // 30
    f32 _34;    // 34
    u32 _38;    // 38
    u32 _3C;    // 3C
    u32 _40;    // 40
    f32 _44;    // 44
    u32 _48;    // 48
    u32 _4C;    // 4C
    u32 _50;    // 50
    f32 _54;    // 54
    u32 _58;    // 58
    u32 _5C;    // 5C
    u32 _60;    // 60
    u32 _64;    // 64
    u32 _68;    // 68
    u32 _6C;    // 6C
    u32 _70;    // 70
    u32 _74;    // 74
    u32 _78;    // 78
    f32 _7C;    // 7C
    f32 _80;    // 80
    f32 _84;    // 84
    f32 _88;    // 88
    f32 _8C;    // 8C
    f32 _90;    // 90
};

class BgScrollMgr_AutoScrollMgr   // Size 0x1C
{
public:

    struct BgScrollMgr_AutoScrollMgr_10   // Size 0xC
    {
        u8 _0;      // 0
        u32 _4;     // 4
        u32 _8;     // 8
    };

    struct BgScrollMgr_AutoScrollMgr_14   // Size 0x50
    {
        Course* course;                 // 0
        Course::Path* path;             // 4
        Course::PathNode** pathNodes;   // 8
        u32 _C;                         // C
        f32 speed;                      // 10
        u32 nextNodeID;                 // 14
        u32 prevNodeID;                 // 18
        Vec2f currentPos;                // 1C
        Vec2f nextNodePos;               // 24
        Vec2f prevNodePos;               // 2C
        u32 _34;                        // 34
        f32 _38;                        // 38
        f32 _3C;                        // 3C
        u8 _40;                         // 40
        u8 _41;                         // 41
        u8 _42;                         // 42
        f32 _44;                        // 44
        f32 _48;                        // 48
        u8 _4C;                         // 4C
    };

    u8 pathId;                              // 0
    u8 _1;                                  // 1
    u8 _2;                                  // 2
    u8 _3;                                  // 3
    u32 _4;                                 // 4
    u8 checkpointEntranceNode;              // 8
    u8 startingEntranceID;                  // 9
    u8 startingEntranceNode;                // A
    u8 _B;                                  // B
    bool autoscrollActive;                  // C
    u8 _D;                                  // D
    u8 _E;                                  // E
    BgScrollMgr_AutoScrollMgr_10* _10;    // 10
    BgScrollMgr_AutoScrollMgr_14* _14;    // 14
    u8 _18;                                 // 18
};

class ZoomEtc // Size 0x8
{
public:

    class Unk4   // Size 0x40
    {
    public:

        struct ZoomHolder   // Size 0x10
        {
            u32 updateCount;    // 0
            f32 lastZoom;       // 4
            f32 currentZoom;    // 8
            f32 targetZoom;     // C
        };

        struct Unk28  // Size 0x10
        {
            u8 _0;      // 0
            f32 _4;     // 4
            f32 _8;     // 8
            f32 _C;     // C
        };

        struct Unk2C  // Size 0x10
        {
            u8 _0;      // 0
            f32 _4;     // 4
            f32 _8;     // 8
            f32 _C;     // C
        };

        u32 vtable;
        f32 zoom;                   // 4
        f32 width;                  // 8
        f32 height;                 // C
        f32 x;                      // 10
        f32 y;                      // 14
        Vec2f field_18;              // 18
        void* field_20;             // 20
        ZoomHolder* zoomHolder;     // 24
        Unk28* field_28;            // 28
        Unk2C* field_2C;            // 2C
        f32 centerX;                // 30
        f32 centerY;                // 34
        f32 field_38;               // 38
        f32 field_3C;               // 3C
    };

    Vec2f* entranceCamOffset;    // 0
    Unk4* field_4;              // 4
};

class BgScrollMgr_RailLimitMgr    // Size 0x214
{
public:

    Course* course;             // 0
    bool isActive;              // 4
    u32 nodeCount;              // 8
    Vec2f nodePositions[64];     // C
    u32 scrollOffsetX;          // 20C
    u8 limitDirection;          // 210
};

class BgScrollMgr // Size 0x3A0
{
    // createInstance()                             Address: 0x0021DA6C
    // deleteInstance()                             Address: 0x0021DAD0
    // sInstance                                    Address: 0x005ECF58
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x0021DC84
    // SingletonDisposer_::sStaticDisposer          Address: 0x005ECF5C
    // SingletonDisposer_::vtbl                     Address: 0x005A44D8
    SEAD_SINGLETON_DISPOSER(BgScrollMgr);

public:

    // C1: 0x0021E010
    BgScrollMgr();

    // D1: 0x0021E1E4
    // D2: 0x0021E1E0 
    virtual ~BgScrollMgr();

    // 0x0021DCD4
    void setAutoscrollSpeedAccel(f32 speed, f32 acceleration);

    // 0x0021DC70
    void initRailLimit(u8 railId, u8 limitDirection, s32 scrollOffset);

    f32 zoom;                                       // 14
    f32 lastZoom;                                   // 18
    sead::BoundBox2f zoneBound;                     // 1C
    sead::BoundBox2f lastZoneBound;                 // 2C
    sead::BoundBox2f viewBound;                     // 3C
    sead::BoundBox2f lastViewBound;                 // 4C
    sead::BoundBox2f viewRect;                      // 5C
    f32 screenWidth;                                // 6C - in world space
    f32 screenHeight;                               // 70 - in world space
    f32 screenLeft;                                 // 74 - in world space
    f32 screenCenterX;                              // 78 - in world space
    f32 screenRight;                                // 7C - in world space
    f32 screenTop;                                  // 80 - in world space
    f32 screenCenterY;                              // 84 - in world space
    f32 screenBottom;                               // 88 - in world space
    sead::BoundBox2f camRect;                       // 98
    sead::BoundBox2f lastCamRect;                   // A8
    Vec2f _AC;                                      // AC - BG Related
    BgScrollMgr_B4* _B4;                            // B4
    BgScrollMgr_CameraStopMgr* cameraStopMgr;       // B8
    BgScrollMgr_ScrollViewMgr* scrollViewMgr;       // BC
    BgScrollMgr_BoundingMgr* boundingMgr;           // C0
    BgScrollMgr_C4* field_C4;                       // C4
    BgScrollMgr_C8* field_C8;                       // C8 - playerPos stuff
    BgScrollMgr_CC* field_CC;                       // CC
    BgScrollMgr_AutoScrollMgr* autoScrollMgr;       // D0
    ZoomEtc* zoomEtcMgr;                            // D4
    f32 _D8;                                        // D8
    f32 _DC;                                        // DC - inited to _80
    f32 _E0;                                        // E0 - inited to zoom
    f32 _E4;                                        // E4
    f32 _E8;                                        // E8
    f32 _EC;                                        // EC
    f32 _F0;                                        // F0
    f32 _F4;                                        // F4
    f32 _F8;                                        // F8
    f32 _FC;                                        // FC
    f32 _100;                                       // 100
    BgScrollMgr_RailLimitMgr* railLimitMgr;         // 104
    u8 _108;                                        // 108
    u8 _10C;                                        // 10C
    sead::FixedPtrArray<void*, 32> _110;            // 110
    u8 _19C[0x208];                                 // 19C
};

size_assert(BgScrollMgr, 0x3A0);