#pragma once

#include "sead.h"

#include "course/Course.h"

// class BgScrollMgr;
class AutoScrollMgr;
class BgScrollMgr_C4;
class LookaheadMgr;
class PlayerBoundMgr;

class ZoomEtc // Size 0x8
{
public:
    struct EntranceCamOffset
    {
        Vec2f camOffset;
    };

    // passed for Unk4::execute(), a similar one (_A) is used for initing
    struct UnkPassdownStruct_B
    {
        sead::BoundBox2f* scrollableBound;   // Used strangely, is min X, max X, and then min Y,  max Y
        BgScrollMgr_C4* c4;
        PlayerBoundMgr* playerBoundMgr;
        AutoScrollMgr* autoScrollMgr;
        void *unk1;
        void *unk2;
        void *unk3;
        void *unk4;
    };

    class Unk4   // Size 0x40
    {
    public:

        class ZoomHolder   // Size 0x10
        {
        public:
            u32 updateCount;    // 0
            f32 lastZoom;       // 4
            f32 currentZoom;    // 8
            f32 targetZoom;     // C

            void execute(BgScrollMgr_C4* c4, PlayerBoundMgr* playerBoundMgr);
            static f32 getStep(f32 current, f32 target, f32 scalar, f32 minStep, f32 maxStep);
        };

        class TrackerX  // Size 0x10
        {
        public:
            f32 trackSubjectX;
            f32 camSpeedX;
            f32 unkBaseline;
            f32 unkXOffset;

            f32 calc(f32* centerXOut, const sead::BoundBox2f& scrollableBound, bool isEntryZoomOut, f32 viewCenterX, f32 lastZoom,
                f32 currentZoom, f32 targetZoom, f32 turnDampingFactor, f32 prevLookahead, f32 lookahead, PlayerBoundMgr* CC);
        };

        class VerticalScroll
        {
        public:
            VerticalScroll(const Course::ScrollData& scrollData);

            void update();
            f32 getDistOutside(bool applyPadding, f32 boundCenter, f32 subjectY, f32 zoom);
            void toViewSpace(f32* upperBoundOut, f32* lowerBoundOut, f32 zoom);

            void updateVerticalBounds(bool applyPadding);

            Course::ScrollData* scrollData;
            f32 upperBound;                     // Init to 64, adds from zone info
            f32 lowerBound;                     // Init to 64, subtracts from zone info
            bool doSmoothStep;                  // If set, the primary upper/lower bounds will be interpolated to target

        private:
            VerticalScroll();
        };
        size_assert(VerticalScroll, 0x10);

        class TrackerY  // Size 0x10
        {
        public:
            u8 multiplayerTrackingPrimary;
            u8 multiplayerTrackingSecondary;
            VerticalScroll* verticalScroll;
            f32 trackSubjectY;
            f32 camSpeedY;

            f32 calc(f32* centerYOut, const sead::BoundBox2f& scrollableBound, BgScrollMgr_C4* c4, f32 viewCenterY, f32 lastZoom, f32 currentZoom, 
            f32 targetZoom, f32 turnDampingFactor, f32 prevLookahead, f32 lookahead, PlayerBoundMgr* CC, bool applyPadding);
        };

        void init(f32 subjectY, f32 subjectX, const sead::BoundBox2f& scrollableBound, BgScrollMgr_C4* c4,
                 const sead::Vector2f& boundCenter, const sead::Vector2f& cameraEntranceOffset, const Course::ScrollData& scrollData);

        void initEvent(f32 subjectY, f32 subjectX, const sead::BoundBox2f& scrollableBound, BgScrollMgr_C4* c4,
                const sead::Vector2f& boundCenter, const sead::Vector2f& cameraEntranceOffset, const Course::ScrollData& scrollData);

        void execute(const UnkPassdownStruct_B& info);

        f32 getZoneCenterX();

        void setZoomToCloserTarget(f32 targetZoom, BgScrollMgr_C4* c4);
        void setWidthHeightToZoom();
        void setZoomToBoundWidth(const sead::BoundBox2f& scrollableBounds);
        void setViewYToZoneBottom();

        void clampViewToScrollableBoundX(const sead::BoundBox2f& scrollableBounds);
        void clampViewToScrollableBoundY(const sead::BoundBox2f& scrollableBounds);

        void handleDemoGoalEvent(const sead::BoundBox2f& unkBound, void* demoGoalEvent);

        static f32 getCloserZoomTarget(f32 targetZoom, BgScrollMgr_C4* c4);

        void* vtable;                           // 0     (entirely optimized away)
        f32 zoom;                               // 4
        f32 width;                              // 8
        f32 height;                             // C
        sead::BoundBox2f viewRect;              // 10
        LookaheadMgr* lookaheadMgr;             // 20
        ZoomHolder* zoomHolder;                 // 24
        TrackerX* trackerX;                     // 28
        TrackerY* trackerY;                     // 2C
        sead::BoundBox2f insetViewBounds;       // 30
    };

    size_assert(Unk4, 0x40);

    EntranceCamOffset* entranceCamOffset;       // 0
    Unk4* field_4;                              // 4
};
