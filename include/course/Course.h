#pragma once

#include "types.h"
#include "sys/Allocator.h"
#include "sead.h"


class Course
{
public:

    struct TilesetNames
    {
        union
        {
            char names[4][32];

            struct
            {
                char standard[32];
                char stage[32];
                char background[32];
                char interactive[32];
            };
        };
    };

    struct Settings
    {
        u64 initalEventFlags;
        u16 unk8;
        u16 timeLimit;
        u8 padC;
        u8 padD[3];
        u8 levelEntranceID;
        u8 unk11;
        u8 specialLevelFlag1;
        u8 specialLevelFlag2;
        u8 coinRushTimeLimit;
        u8 pad15[2];
    };

    struct ZoneBounding
    {
        u32 upperBound;
        u32 lowerBound;
        u32 unkUpperBound;
        u32 unkLowerBound;
        u16 id;
        u16 flags;
        u8 pad14[8];
    };

    struct Unk3
    {
        u8 unk0[2];
        u16 unk2;
        u8 unk4[4];
    };

    struct ZoneBackground
    {
        u16 id;
        s16 yPosition;
        s16 xPosition;
        u8 pad6[2];
        char name[16];
        u16 unk18;
        u8 pad1A[2];
    };

    struct Unk5
    {
        u8 unk0[20];
    };

    struct Entrance
    {
        u16 x;
        u16 y;
        s16 cameraX;
        s16 cameraY;
        u8 id;
        u8 destArea;
        u8 destEntrance;
        u8 type;
        u8 padC;
        u8 zone;
        u8 padE[2];
        u16 settings;
        u8 pad12[2];
        u8 unk14;
        u8 unk15;
        u8 pad16[2];
    };

    struct Sprite
    {
        u16 type;
        u16 x;
        u16 y;
        u8 targetFlagId;
        u8 triggeringFlagId;
        u32 spriteData1;
        u32 spriteData2;
        u8 zone;
        u8 layer;
        u8 movementId;
        u8 spriteData3;
        u8 pad14[4];
    };

    struct SpriteLoad
    {
        u16 type;
        u8 pad2[2];
    };

    struct Zone
    {
        u16 x;
        u16 y;
        u16 width;
        u16 height;
        u16 unk8;
        u16 padA;
        u8 id;
        u8 boundingBlockId;
        u8 unkE;                    // Read by BgScrollMgr
        u8 unkF;                    // Read by BgScrollMgr
        u8 unk10;                   // Read by BgScrollMgr
        u8 pad11[3];
        u8 multiplayerTracking;
        u8 progressPathId;
        u8 musicId;
        u8 pad17;
        u8 backgroundBlockId;
        u8 unk19;                   // Read by BgScrollMgr
        u8 pad1A;
        u8 pad1B;
    };

    struct Location
    {
        u16 x;
        u16 y;
        u16 width;
        u16 height;
        u8 id;
        u8 pad9[3];
    };

    struct Unk11;

    struct Unk12;

    struct Path
    {
        u8 id;
        u8 pad1;
        u16 startNode;
        u16 nodeCount;
        u16 flags;
        u8 pad8[4];
    };

    struct PathNode
    {
        u16 x;
        u16 y;
        f32 speed;
        f32 accel;
        u16 delay;
        s16 rotation;
        u8 settings;
        u8 nextPathId;
        u8 pad12[2];
    };

    struct ProgressPath
    {
        u16 id;
        u16 startNode;
        u16 nodeCount;
        u8 pad6[3];
        u8 flags;
        u8 padA[2];
    };

    struct ProgressPathNode
    {
        u16 x;
        u16 y;
        u8 pad4[16];
    };


    ZoneBackground* getBackgroundById(u16 backgroundId);
    Entrance* getEntranceById(u8 entranceId);
    Zone* getZoneById(u8 zoneId, sead::BoundBox2f* boundingOut = nullptr);
    Path* getPathById(u8 pathId);
    ZoneBounding* getZoneBoundingById(u16 boundingId);
    Location* getLocationById(sead::BoundBox2f* boundingOut, u8 id);
    PathNode* getPathNodesById(u8 pathId);

    bool findLocationContainingPoint(u8* locationIdOut, const Vec2f& point, f32 marginX = 0.0f, f32 marginY = 0.0f);

    void getZoneRect(sead::BoundBox2f* boundingOut, const Zone& zone, f32 margin = 0.0f);
    bool findZoneContainingPoint(u8* zoneIdOut, const Vec2f& point, f32 margin = 0.0f);
    bool findZoneContainingRect(u8* zoneIdOut, const sead::BoundBox2f& bounding, f32 margin = 0.0f);


    u32 areaId;

    union
    {
        struct
        {
            TilesetNames* tilesets;
            Settings* settings;
            ZoneBounding* boundings;
            Unk3* unk3;
            ZoneBackground* backgrounds;
            Unk5* unk5;
            Entrance* entrances;
            Sprite* sprites;
            SpriteLoad* spriteLoads;
            Zone* zones;
            Location* locatons;
            Unk11* unk11;
            Unk12* unk12;
            Path* paths;
            PathNode* pathNodes;
            ProgressPath* progressPaths;
            ProgressPathNode* progressPathNodes;
        };
        void* blocks[17];
    };

    union
    {
        struct
        {
            u32 tilesetsSize;
            u32 settingsSize;
            u32 boundingsSize;
            u32 unk3Size;
            u32 backgroundsSize;
            u32 unk5Size;
            u32 entrancesSize;
            u32 spritesSize;
            u32 spriteLoadsSize;
            u32 zonesSize;
            u32 locatonsSize;
            u32 unk11Size;
            u32 unk12Size;
            u32 pathsSize;
            u32 pathNodesSize;
            u32 progressPathsSize;
            u32 progressPathNodesSize;
        };
        u32 blockSizes[17];
    };

    union
    {
        struct
        {
            u32 tilesetsCount;
            u32 settingsCount;
            u32 boundingsCount;
            u32 unk3Count;
            u32 backgroundsCount;
            u32 unk5Count;
            u32 entrancesCount;
            u32 spritesCount;
            u32 spriteLoadsCount;
            u32 zonesCount;
            u32 locatonsCount;
            u32 unk11Count;
            u32 unk12Count;
            u32 pathsCount;
            u32 pathNodesCount;
            u32 progressPathsCount;
            u32 progressPathNodesCount;
        };
        u32 blockCounts[17];
    };

    Sprite* zonesFirstSprite[64];
    u32 zonesSpriteCount[64];
    u32 zonesFirstSpriteIdx[64];
};

// Size 0xF50
class CourseData
{
    // createInstance()                             Address: 0x001CEA80
    // deleteInstance()                             Address: 0x001CEAF0
    // sInstance                                    Address: 0x005E9AA8
    // SingletonDisposer_::~SingletonDisposer_()    Address: 0x001CEC88
    // SingletonDisposer_::sStaticDisposer          Address: 0x005E9AAC
    // SingletonDisposer_::vtbl                     Address: 0x0059F198
    SEAD_SINGLETON_DISPOSER(CourseData);

public:
    // Address: 0x001CEB30
    void load();

    // Address: 0x001CECBC
    Course* getFile(u8 id);

    // Address: 0x001CEBD8
    bool getCourseName(sead::FixedSafeString<8>* nameOut, u8 gameMode, u8 worldId, u8 levelId);

private:
    Course mFiles[4];
};

size_assert(CourseData, 0xF50);

// TODO: Maybe move somewhere else and choose better name?
struct StageInfo : public sead::IDisposer   // size: 0x20
{

    enum EntranceType : u8
    {
        NONE                = 0,
        FROM_LEVEL_START    = 1,
        FROM_CHECKPOINT     = 2,
        MID_LEVEL_WARP      = 3,
    };

    static StageInfo* instance;

    u8 mode;                    // 0: Normal, 1: Debug, 2: DLC (Debug-DLC in non Gold-Edition)
    u8 world;                   // Same as in level names minus 1
    u8 level;                   // Same as in level names minus 1
    u8 area;                    // Inited to 0x00
    u8 entrance;                // Inited to 0xFF
    u8 zone;                    // Inited to 0x00
    EntranceType entranceType;  // Inited to 0x00
    u8 _17;                     // Inited to 0x00
    u8 destWorld;               // Inited to 0x00
    u8 destLevel;               // Inited to 0x00
    u8 destArea;                // Inited to 0x00
    u8 destEntrance;            // Inited to 0xFF
    u8 _1C;                     // Inited to 0x00

    u8 _unk1D[3];               // Padding
};
