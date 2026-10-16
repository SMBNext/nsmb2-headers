#pragma once

#include "sead.h"

#include "course/Course.h"
#include "course/ScrollEffect.h"
#include "course/PlayerBoundMgr.h"
#include "course/ZoomEtc.h"

class BgScrollMgr_B4;
class BgScrollMgr_CameraStopMgr;
class BgScrollMgr_ScrollViewMgr;
class BgScrollMgr_BoundingMgr;
class BgScrollMgr_C4;
class AutoScrollMgr;
class ZoomEtc;
class BgScrollMgr_RailLimitMgr;

// Size: 0x3A0
class BgScrollMgr
{
    // createInstance()                             Address: 0x0021DA6C
    // deleteInstance()                             Address: 0x0021DAD0
    // sInstance                                    Address: 0x005ECF58
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x0021DC84
    // SingletonDisposer_::sStaticDisposer          Address: 0x005ECF5C
    // SingletonDisposer_::vtbl                     Address: 0x005A44D8
    SEAD_SINGLETON_DISPOSER(BgScrollMgr);

public:

    enum class CameraMode : u8
    {
        NORMAL                          = 0x0,
        Y_TRACKING_ONLY                 = 0x1,
        Y_EXPAND_ONLY                   = 0x2,
        STATIC_ZOOM                     = 0x3,
        STATIC_ZOOM_Y_TRACK_ONLY        = 0x4,
        STATIC_ZOOM_EVENT_CONTROLLED    = 0x5,
        X_TRACKING_ONLY                 = 0x6,
        X_EXPANDING_ONLY                = 0x7,
    };

    // C1: 0x0021E010
    BgScrollMgr();

    // D1: 0x0021E1E4
    // D2: 0x0021E1E0 
    virtual ~BgScrollMgr();

    // 0x0021DCD4
    void setAutoscrollSpeedAccel(f32 speed, f32 acceleration);

    // 0x0021DC70
    void initRailLimit(u8 railId, u8 limitDirection, s32 scrollOffset);

    // 0x0021D960
    void calculateViewBounds();

    // 0x00204340
    static bool playerIsClimbing();

    f32 zoom;                                       // 14
    f32 zoomPrev;                                   // 18
    sead::BoundBox2f scrollableBound;               // 1C
    sead::BoundBox2f lastScrollableBound;           // 2C
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
    Vec2f unkViewMax;                               // AC - BG parallax related
    BgScrollMgr_B4* _B4;                            // B4
    BgScrollMgr_CameraStopMgr* cameraStopMgr;       // B8
    BgScrollMgr_ScrollViewMgr* scrollViewMgr;       // BC
    BgScrollMgr_BoundingMgr* boundingMgr;           // C0
    BgScrollMgr_C4* field_C4;                       // C4
    PlayerBound* playerBound;                       // C8
    PlayerBoundMgr* playerBoundMgr;                 // CC
    AutoScrollMgr* autoScrollMgr;                   // D0
    ZoomEtc* zoomEtcMgr;                            // D4
    ScrollEffect scrollEffect;                      // D8
    BgScrollMgr_RailLimitMgr* railLimitMgr;         // 104
    u8 scrollViewUnkFlag;                           // 108
    u8 enableMovement;                              // 109
    sead::FixedPtrArray<void*, 32> _10C;            // 10C
    u8 _198[0x3A0-0x198];                        // 198
};

size_assert(BgScrollMgr, 0x3A0);


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

    Course::ScrollData* zoneBounding;     // C
};

class BgScrollMgr_CameraStopMgr   // Size 0x538
{
public:
    struct Unk528
    {
        Vec2f minStop;
        Vec2f maxStopMaybe;
    };


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
        Vec2f boundaryPosition;         // 1C
        u8 multiplayerSetting;          // 1D
        u8 priority;                    // 1E
        bool isPermeable;               // 1F
        bool shouldKillInMultiplayer;   // 20
        bool isPaired;                  // 21
    };
    
    sead::BoundBox2f zoneBound;                             // 0
    sead::FixedPtrArray<CamStopEntry, 32> camStopEntries;   // 10
    u8 _9C[996];                                            // 9C
    u32 _480;                                               // 480
    u8 _484[32];                                            // 484
    CamStopEntry* ptrBuffer[32];                            // 4A4
    u8 _524;                                                // 525
    Unk528 _528;                                            // 528
};

size_assert(BgScrollMgr_CameraStopMgr, 0x538);

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

    enum class ZoomEvent : u8
    {
        cFlagpoleZoomIn     = 0x5,
        cFlagpoleStart      = 0x6,
        cFlagpoleZoomOut    = 0x7,
        cEntryZoomOut       = 0x18,
    };


    class CameraSettings
    {
    public:
        BgScrollMgr::CameraMode cameraMode;     // 0
        u8 zoomIdx;                             // 1
        u8 zoomChange;                          // 2
        u8 _3;                                  // 3    may be padding, or belongs to BgScrollMgr_C4

        void set(BgScrollMgr::CameraMode cameraMode, u8 zoomIdx);       // 0x00457118
        f32 getUnkYExpandingFloat(bool isSecondary);
        f32 getUnkYExandingFloatInit(bool isSecondary);
    };

    size_assert(CameraSettings, 0x4);


    class DemoGoalEvent  // Size 0x1C
    {
    public:
        enum class State : u32
        {
            IDLE = 0x0,
            SLIDING_DOWN = 0x1,
            REACHED_BOTTOM = 0x2,
            ZOOM_IN = 0x3,
            ZOOM_OUT = 0x4,
        };

        State state;                    // 4
        Vec2f targetCameraPosition;     // 8
        f32 cameraPositionY;            // 10
        u32 elapsed;                    // 14
        u32 timer;                      // 18

        virtual ~DemoGoalEvent() {}

        DemoGoalEvent();                                    // 0x00287464
        void handleEvent(u8* unkZoomRelatedOut);            // 0x002871D4
    };

    size_assert(DemoGoalEvent, 0x1C);

    bool zoomToEventTarget(f32& zoom, f32& targetZoom);
    bool isCenteredZoneX();

    f32 getPlayerBoundScalar();

    BgScrollMgr::CameraMode cameraMode;     // 0
    u8 zoomIdx;                             // 1
    u8 _2;                                  // 2
    u8 _3;                                  // 3
    u8 _4;                                  // 4
    CameraSettings cameraSettings;          // 5
    u8 _9;                                  // 9
    bool primaryTrackingIsVertical;         // A
    u8 cameraFlags;                         // B        Set from zone 
    u8 executeRelatedFlag;                  // C        unused
    u8 unkLockRelatedFlag;                  // D
    u8 _E;                                  // E
    u8 _F;                                  // F
    f32 maxZoom;                            // 10
    u32 elapsed;                            // 14
    u32 eventTimer;                         // 18
    ZoomEvent zoomEventId;                  // 1C
    DemoGoalEvent* demoGoalEvent;           // 20
};

size_assert(BgScrollMgr_C4, 0x24);


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
