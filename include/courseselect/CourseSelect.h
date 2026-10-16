#pragma once

#include "gfx/Model.h"
#include "sead.h"


namespace course_select {

class Actor;

enum CsDirection : u8
{
    CS_LEFT     = 0,
    CS_RIGHT    = 1,
    CS_UP       = 2,
    CS_DOWN     = 3,
    CS_ABOVE    = 4,
    CS_BELOW    = 5,
};

enum ExitType : u8
{
    SECRET      = 0,
    NORMAL      = 1,
};

class CsInfo
{
    SEAD_SINGLETON_DISPOSER(CsInfo);
public:

    class CsvData   // size: 0x6F5F4
    {
    public:
        struct Point    // size: 0x6D8
        {
            sead::FixedSafeString<5> name;                              // 0
            sead::FixedSafeString<5> unlockedPointNames[4];             // 14
            sead::FixedSafeString<5> unlockedSecretPointNames[4];       // 64
            sead::FixedSafeString<10> pathUnlockNames[16];              // B4
            sead::FixedSafeString<10> secretPathUnlockNames[16];        // 234
            sead::FixedSafeString<10> _3B4[16];                         // 3B4
            sead::FixedSafeString<10> revealedPathConnectionNames[16];  // 534
            s32 maxConnectedDirection;                                  // 6B4
            s32 maxSecretConnectedDirection;                            // 6B8
            s32 numPathUnlocks;                                         // 6BC
            s32 numSecretPathUnlocks;                                   // 6C0
            u8 _6C4[20];                                                // 6C4
        };

        size_assert(Point, 0x6D8);

        struct SubRoute
        {
            sead::FixedSafeString<10> name;
            u32 _18;
        };

        struct DemoPoint
        {
            sead::FixedSafeString<5> _0;
            u32 _14;
        };

        virtual ~CsvData();

        static u8 movementTypes[];
        static sead::SafeString movementTypeKeys[];
        static u32 numMovementTypes;

        u32 getPointIdx(const sead::SafeString& name);

        u32 numPoints;                  // 4
        u32 numSubRoutes;               // 8
        u32 numWorldInPoints;           // C
        u32 numToCastlePoints;          // 10
        Point points[256];              // 14
        SubRoute subRoutes[256];      // 6D814
        DemoPoint worldInPoints[10];    // 6F414
        DemoPoint toCastlePoints[10];   // 6F504
    };

    size_assert(CsvData, 0x6F5F4);

    class PointInfo     // size: 0x5C08
    {
    public:
        class Point
        {
        public:
            virtual ~Point();

            enum Type
            {
                TYPE_PATH_JUNCTION  = 0,    // F0..
                TYPE_PATH_POINT     = 1,    // K...
                TYPE_STAR_COIN_SIGN = 2,    // Fg..
                TYPE_COURSE         = 3,    // W.X. X not in below
                TYPE_TOAD_HOUSE     = 4,    // W.K.
                TYPE_CANNON         = 5,    // W.P.
                TYPE_START          = 6,    // W.M.
                TYPE_PIPE           = 7,    // W.D.
                TYPE_UNKNOWN        = 8,
            };

            union Neighbors
            {
                struct 
                {
                    Point* left;
                    Point* right;
                    Point* up;
                    Point* down;
                    Point* above;
                    Point* below;
                };
                Point* points[6];

                Point*& operator[](size_t index) { return points[index]; }
                const Point* operator[](size_t index) const { return points[index]; }
            };

            sead::FixedSafeString<5> name;          // 0
            Neighbors neighbors;
            u8 _30[6];
            u8 _36;                                 // 36   Inited to 14
            u8 _37;                                 // 37   Inited to 14
            u8 _38;                                 // 38   Inited to 14
            u8 _39;                                 // 39   Inited to 14
            u8 _3A;                                 // 3A   Inited to 14
            u8 _3B;                                 // 3B   Inited to 14
            u8 _3C;                                 // 3C   Inited to 14
            Vec3f position;                         // 40
            u8 worldId;                             // 4C
            u8 courseId;                            // 4D
            u8 _4E;                                 // 4E   Inited to 0
            bool isUnlocked;                        // 4F   Is always 1 if not a course
            u8 _50;                                 // 50   Inited to 0
            bool isUnlockedCourse;                  // 51   Is always 0 if not a course
            bool isCompleted;                       // 52   Counts completing either normal or secret exit
            bool isCompletedAssist;                 // 53   Inited to 0
            s32 pointIdx;                           // 54   Index in CsvData::points, inited to 256
            u32 _58;                                // 58   Inited to 0

            inline bool isCourse()
            {
                return (isUnlocked == isUnlockedCourse);
            }
        };

        virtual ~PointInfo();

        Point points[256];
        u32 numPoints;

        Point* getPoint(s32 pointIdx);
        Point* getPoint(const sead::SafeString& name);
        Point* getPointByCourseId(u8 courseId);
    };

    class RouteInfo     // size: 0x5608
    {
    public:
        class Route     // size: 0xAC
        {
        public:
            sead::FixedSafeString<10> name;     // 4
            PointInfo::Point* points[34];       // 1C
            u32 numPoints;                      // A4
            bool isUnlocked;                    // A8
            u8 _A9;                             // A9
            u16 _AA;                            // AA

            virtual ~Route();
        };

        size_assert(Route, 0xAC);

        virtual ~RouteInfo();       // 4

        Route routes[128];         // 4
        u32 numRoutes;             // 8

        Route* getRoute(PointInfo::Point* pointA, PointInfo::Point* pointB);
        Route* getFirstRouteWithPoint(PointInfo::Point* point);

    };

    u32 _10;
    void* csvReader;
    CsvData* csvData;
    PointInfo* pointInfo;
    RouteInfo* routeInfo;
    u8 worldId;
    u8 pointId;

};

CsInfo::CsvData* getCsvData();
CsInfo::PointInfo* getPointInfo();
CsInfo::RouteInfo* getRouteInfo();

s32 getStarCoinGateIndex(s32 courseId);
u8 getToadHouseType(u32 worldId, u32 levelId);
u32 getTypeFromPointName(sead::SafeString name);
const sead::FixedSafeString<5>& getConnectedUnlockPointName(u8 courseId, u8 direction, ExitType exitType);
s32 getMaxConnectedDirection(u8 courseId, ExitType exitType);

s32 getRotation(const Vec3f& position, const Vec3f& destination);

u8 GetCurrentWorldId();
u8 GetCurrentNodeId();


}
