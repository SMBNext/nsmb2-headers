#pragma once

#include "collider/ActorBgCollisionCheckResult.h"
#include "collider/ActorBgHitCheckCallback.h"
#include "collider/BasicBgCollisionCheck.h"
#include "collider/BgCollision.h"
#include "collider/BgCollisionCategory.h"
#include "collider/BgUnitCode.h"
#include "collider/UnkCollisionClass.h"
#include "math/Vec.h"
#include "sead/container/seadSafeArray.h"
#include "sead/seadRuntimeTypeInfo.h"
#include "sys/Common.h"
#include "types.h"
#include "utility/Direction.h"
#include "utility/Angle.h"
#include "utility/BitFlag.h"

class ActorBase;

// Size: 0xDC0
class ActorBgCollisionCheck
{
    SEAD_RTTI_BASE(ActorBgCollisionCheck);
public:
    enum class ProcessFlags : u8
    {
        cSkipFoot               = 1 << 0,   // Skips collision checking for the foot sensor if set.
        cSkipHead               = 1 << 1,   // Skips collision checking for the head sensor if set.
        cSkipWall               = 1 << 2,   // Skips collision checking for the wall sensors if set.
        cUnk8                   = 1 << 3,   // Unused?
        cSkipOpposite           = 1 << 4,   // 
        cSkipFootSlopeCheck     = 1 << 5,   // Skips calls to `detectGroundDrop()` if set.
        cSkipQuicksandAdjust    = 1 << 6,   //
        cSkipWallPush           = 1 << 7    // Skips all logic related to pushing out of walls.
    };

    enum class WaterDepth : u32
    {
        cSurface    = 0,    // Depth is <= `0.0f`.
        cShallow    = 1,    // Depth is > `0.0f` && <= `8.0f`.
        cMedium     = 2,    // Depth is > `8.0f` && <= `32.0f`.
        cDeep       = 3,    // Depth is > `32.0f`.
        cNum
    };

    enum class SlopeType : u32
    {
        cNone       = 0,    // Slope angle is >= `0°` && <  `7.0175°`.
        cGentle     = 1,    // Slope angle is >= `7.0175°` && < `20.3165°`.
        cModerate   = 2,    // Slope angle is >= `20.3165°` && < `35.7990°`.
        cSteep      = 3,    // Slope angle is >= `35.7990°` && < `54.2010°`.
        cVerySteep  = 4,    // Slope angle is >= `54.2010°`.
        cNum
    };
    
public:
    // Size: 0x8
    class SensorFlag : public BitFlag<64>
    {
    public:
        enum Bit
        {
            // lo byte
            cBit_0                      =  0,   // Checked in - [0x002194F0, 0x002EEDBC]
            cEnableChikuwaCollision     =  1,   // Allows the activation donut platforms. Foot sensor only. [0x0044C8D0].
            cBit_2                      =  2,   // Checked in - [0x0049B2B8] - (Related to BgUnitCode::Type::Coin) - SENSOR_FLAG_A_COIN_FRAGMENT
            cEnableCoinCollision        =  3,   // Allows the collection coins. Any sensor. [0x0049B2B8, 0x0021C6E8, 0x002E5608, 0x0044ABB0].
            cEnableCoinOutlineCollision =  4,   // Allows the activation of coin outlines. Any sensor. [0x0049B2B8, 0x0021C6E8, 0x002E5608].
            cBit_5                      =  5,   // Checked in - [0x002EEDBC, 0x00332568, 0x00432DFC, 0x00433C74, 0x00434284, 0x0049AD18] - SENSOR_FLAG_A_HIT_BLOCK
            cEnableBlockBreakCollision  =  6,   // Allows the breaking of blocks (E.g. regular mario block hit). Any sensor. [0x0044BF88, 0x00218D70, 0x00219F88, 0x002EEE80, 0x00432DFC, 0x0x00433C74, 0x0044C8D0, 0x00433054, 0x00434284, 0x0049ABCC, 0x0049AD18]
            cEnableBlockHitCollision    =  7,   // Allows the hitting of blocks (E.g. small mario block hit). Any sensor. [0x0044BF88, 0x00218D70, 0x002EEE80, 0x00332568, 0x00432DFC, 0x0x00433C74, 0x0044C8D0, 0x00434284]
            cBit_8                      =  8,    
            cBit_9                      =  9,
            cBit_10                     = 10,
            cDisableQuicksandCollision  = 11,   // Prevents sinking in quicksand. Any sensor. [0x0021BC48, 0x0049AF0C].
            cEnableTrampolineCollision  = 12,   // Allows bouncing on trampolines. Foot sensor only. [0x0024CF78].
            cBit_13                     = 13,   // Checked in - [0x0021C098, 0x00434170] - 
            cBit_14                     = 14,   // Checked in - [0x0043406C] - 
            cBit_15                     = 15,
            cBit_16                     = 16,   // Checked in - [0x002194F0]
            cBit_17                     = 17,   // Checked in - [0x0049AD18]
            cBit_18                     = 18,
            cBit_19                     = 19,
            cBit_20                     = 20,
            cDisableDokanCollision      = 21,   // Prevents colliding with pipes, used to prevent stutter when walking into and crushing a pipe. (Requires `cEnableBreakCollision` to be enabled). Any sensor. [0x0049AD18] - 
            cBit_22                     = 22,   // Checked in - [0x0049AF0C] - 
            cBit_23                     = 23,
            cBit_24                     = 24,   // Checked in - [0x0049B2B8] - 
            cBit_25                     = 25,   // Checked in - [0x0049B2B8] - 
            cBit_26                     = 26,   // Checked in - [0x0049AF0C] - 
            cBit_27                     = 27,   // Checked in - [0x0049AF0C] - 
            cBit_28                     = 28,   // Checked in - [0x0044C8D0] - 
            cEnableBreakCollision       = 29,   // Allows breaking tiles (Blocks, Pipes etc) and crushing pipes. Any sensor. [0x00432DFC, 0x0x00433C74, 0x00433EB0, 0x0044C8D0, 0x00433054, 0x004348FC, 0x0049ABCC, 0x0049AD18, 0x0049AD18]
            cBit_30                     = 30,   // Checked in - [0x0044B7F0] - 
            cEnableExplodeCollision     = 31,   // Temporary flag enabled while performing an explosion collision. Enabled during a call to `explodeHitCheck()`. [0x0044B7F0, 0x0021916C, 0x00432DFC, 0x00433EB0, 0x00433054, 0x004348FC]

            // hi byte
            cBit_32                     = 32,   // Bit 0 = Checked in - [0x002EEE80, 0x002EEF78, 0x00432DFC, 0x00433C74, 0x00433054, 0x0x0049AD18] - 
            cBit_33                     = 33,   // Bit 1 - Checked in - [0x0049B2B8] - (Related to BgUnitCode >= Type::Kanai && Type::Unk19 && Type::Unk1A)
            cEnableKanaiCollision       = 34,   // Bit 2 - Enables collision with BgUnitCode::Type::Kanai (and Type::Unk1A). Foot sensor only. [0x0049B2B8]
            cBit_35                     = 35,   // Bit 3 - Checked in - [0x0049B2B8] - (Related to BgUnitCode::Type::Kanai)
            cBit_36                     = 36,   // Bit 4 
            cBit_37                     = 37,   // Bit 5
            cBit_38                     = 38,   // Bit 6
            cBit_39                     = 39,   // Bit 7
            cBit_40                     = 40,   // Bit 8
            cBit_41                     = 41,   // Bit 9
            cBit_42                     = 42,   // Bit 10
            cBit_43                     = 43,   // Bit 11
            cDisableGateOnewayCollision = 44,   // Prevents colliding with flipper gates. [0x0049AD18]
            cEnableShockCollision       = 45,   // Temporary flag enabled while performing a shock collision. Enabled during a call to `shockHitCheck()`. [0x00218D70, 0x00432DFC]
            cEnableJumpBlockCollision   = 46,   // Allows bouncing on note blocks. Foot sensor only. [0x0044C8D0]
        };
    };

    size_assert(SensorFlag, 0x8);

    // Size 0xC
    struct Sensor
    {
        /* 0x0 */  f32 pos1;            // The position of one end of a sensor.
        /* 0x4 */  f32 pos2;            // The position of the other end of a sensor.
        /* 0x8 */  f32 centerOffset;    // The offset from the center point of the sensor to the actor.
    };

    size_assert(Sensor, 0xC);

    // Size: 0x8
    class Output : BitFlag<64>
    {
    public:
        enum Bit : u32
        {   
            cOnGround           = 0,    // Standing on the ground.
            cOnSlope            = 1,    // Standing on a slope.
            cOnRide             = 2,    // Standing on ride collision (moving platforms etc). (ActorBgCollisionCheckResult._3 is set and standing?)
            cOnTrampoline       = 3,    // Standing on a trampoline.
            cOnHalf             = 4,    // Standing on semi-solid collision.
            cUnk5               = 5,    //
            cUnk6               = 6,    //
            cOnHorizontalDokan  = 7,    // Standing on a horizontal pipe.
            cOnQuicksand        = 8,    // Standing on quicksand.
            cUnk9               = 9,    //
            cHeadCollision      = 10,   // Hitting a ceiling.
            cUnk11              = 11,   //
            cUnk12              = 12,   //
            cUnk13              = 13,   // (ActorBgCollisionCheckResult._3 is set and hitting head?)
            cUnk14              = 14,   //
            cUnk15              = 15,   //
            cInQuicksand        = 16,   // Head is submerged in quicksand.
            cUnk17              = 17,   //
            cWallCollisionR     = 18,   // Colliding with a wall to the right.
            cWallCollisionL     = 19,   // Colliding with a wall to the left.
            cUnk20              = 20,   // Carry related R ?
            cUnk21              = 21,   // Carry related L ?
            cUnk22              = 22,   // Right wall related ?
            cUnk23              = 23,   // Left wall related. ?
            cUnk24              = 24,   //
            cUnk25              = 25,   //
            cUnk26              = 26,   //
            cUnk27              = 27,   // Right wall related ?
            cUnk28              = 28,   // Left wall related. ?
            cUnk29              = 29,   //
            cUnk30              = 30,   //
            cDokanCollision     = 31,   // Used when colliding with a pipe.
        };
        
    public:
        // Returns true if there was collision with the foot sensor.
        bool checkFoot() const { return isSet(Output::cOnGround); }

        // Returns true if there was collision with the head sensor.
        bool checkHead() const { return isSet(Output::cHeadCollision); }

        // Returns true if there was collision with the right wall sensor.
        bool checkWallRight() const { return isSet(Output::cWallCollisionR); }

        // Returns true if there was collision with the left wall sensor.
        bool checkWallLeft() const { return isSet(Output::cWallCollisionL); }

        // Returns true if there was collision with the wall sensor for the given `direction`.
        bool checkWall(Direction direction) const
        {
            switch (direction)
            {
                case Direction::cRight: return checkWallRight();
                case Direction::cLeft: return checkWallLeft();
                default: return false;
            }
        }

        // Returns true if standing on ride collision.
        bool checkRide() const { return isSet(Output::cOnRide); }

        // Returns true if standing on trampoline collision.
        bool checkTrampoline() const { return isSet(Output::cOnTrampoline); }

        // Returns true if standing on quicksand.
        bool checkOnQuicksand() const { return isSet(Output::cOnQuicksand); }

        // Returns true if standing in quicksand.
        bool checkInQuicksand() const { return isSet(Output::cInQuicksand); }

        // Returns true if there was collision with quicksand.
        bool checkQuicksand() const { return checkInQuicksand() || checkOnQuicksand(); }

        // Returns true if standing on a slope.
        bool checkOnSlope() const { return isSet(Output::cOnSlope); }
        
        // 
        bool checkHeadEx() const { return checkHead() && !checkInQuicksand(); }

        // 
        bool checkWallRightEx() const { return checkWallRight() || (isSet(Output::cUnk22) && !isSet(Output::cUnk28)); }

        // 
        bool checkWallLeftEx() const { return checkWallLeft() || (isSet(Output::cUnk23) && !isSet(Output::cUnk29)); }

        // 
        bool checkWallEx(Direction direction) const
        {
            return isSet(Output::cWallCollisionR + u32(direction)) || (isSet(Output::cUnk22 + u32(direction)) && !isSet(Output::cUnk28 + u32(direction)));
        }
    };

    size_assert(Output, 0x8);

public:
    using SensorArray = DirectionArray<Sensor>;
    using SensorBoolArray = DirectionArray<bool>;
    using WallSensorArray = DirectionArrayX<Sensor>;
    using WallSensorBoolArray = DirectionArrayX<bool>;

    using SensorFlagArray = DirectionArray<SensorFlag>;

    using SensorBgCollisionCatArray = DirectionArray<BgCollisionCategory>;

    using BgCheckResultArray = sead::UnsafeArray<ActorBgCollisionCheckResult, cBgCollisionCategoryCount>;
    using SensorBgCheckResultArray = DirectionArray<BgCheckResultArray>;

    using SensorHitBgCheckDataArray = DirectionArray<BgUnitCode>;
    
public:
    ActorBgCollisionCheck();
    
    virtual ~ActorBgCollisionCheck();

    // A full collision check.
    // Uses sweep-based collision checking.
    // Handles checks related to quicksand, performs slope position adjustment, and overlap resolution etc.
    virtual void checkBg();

    // Clears the state used for collision checking.
    virtual void clearBg();

    // Called at the begging of a frame to handle start-of-frame updates, such as copying current state into previous buffer.
    virtual void atFrameStart();

    // Returns the `ActorBase` to use with direction-reverse callbacks.
    virtual ActorBase* getOwnerAtRevCheck(f32 collisionYPos) const = 0;

    // Returns the `ActorBase` that triggered the collision.
    virtual ActorBase* getOwnerAtHit(const BgCollision& collision, Direction direction) const = 0;

    // Returns pointer to the playerNum for the given `collisionYPos`.
    virtual s8* getPlayerNum(f32 collisionYPos) = 0;

    // Builds the per-frame list of nearby `BgCollision` used during sweeps.
    virtual void buildBgCollisionList();

    // Sweeps foot sensor against tile grid + BgCollision list for ground contact.
    // Combines tile `sweepTileCollisionFoot()` and actor `sweepActorCollision()` results, picks the lowest contact.
    void sweepCollisionFoot();

    // Sweeps head sensor against tile grid + BgCollision list for ceiling contact.
    // Combines tile `sweepTileCollisionHead()` and actor `sweepActorCollision()` results, picks the highest contact.
    void sweepCollisionHead();

    // Sweeps wall sensor against tile grid + BgCollision list for side contact.
    // Combines tile `sweepTileCollisionWall()` and actor `sweepActorCollision()` results, picks the most extreme X offset.
    void sweepCollisionWall(Direction direction);

    // --REIMPLEMENTED -- Returns the liquid type at the provided `checkPos`.
    // Optionally returns the liquid's Y position via `levelOut`.
    static u8 checkWater(f32* levelOut, const Vec3f& checkPos);

    // Initializes the CollisionCheck with the provided `owner` and `Sensor` data.
    void set(ActorBase* owner, const Sensor* foot, const Sensor* head, const Sensor* wall);

    // A simplified lightweight collision check.
    // Uses simple snap-based collision checking, rather than full sweeps.
    // Does not do checks related to quicksand, slope adjustment, overlap resolution etc.
    void checkBgSimplified();

    // Snaps the Actor's Y position to the foot contact point if foot was hit and head doesn't take priority.
    void applyFootSnap();

    // Performs a hit check against `BgCollision` with the ray (`RayStart` - `RayEnd`).
    // Checks are performed against the tile layer `layer`.
    // The provided `hitDirMask` determines which sides of the collision count as valid hits.
    // Returns `true` if a hit occurs.
    // Optionally returns `hitPosOut`, `surFaceAngleOut`, `bgUnitCodeOut` and `bgCollisionOut`.
    static bool hitCheck(Vec2f* hitPosOut, Angle* surfaceAngleOut, BgUnitCode* bgUnitCodeOut, BgCollision* bgCollisionOut, const Vec2f& rayStart, const sead::Vector2f& rayEnd, u8 layer, DirectionMask hitDirMask);

    // Applies correction to an actor's Y position when a wall pushes the actor against a slope.
    // The `originalPosition` is the actor's position prior to having wallPushback applied, used to calculate a delta.
    void adjustYForWallSlope(const Vec2f& originalPosition);

    // Applies correction to an actor's X position when a wall pushes the actor.
    // The `primaryDirection` is used to determine what wall is being pushed against.
    // The `inverseDirection` is used during squash checking.
    virtual void applyWallPushback(Output& unusedFlags, Direction primaryDirection, Direction inverseDirection);

    // Updates each of the bounding boxes used during sweep checking, `this->mBoundsWorld`, `this->mBoundsWorldPrev` and `this->mBoundsSwept`.
    // Triggers a recalculation of `this->mBoundsLocal` via `computeSensorBounds()` if bounds are flagged as dirty. 
    void updateBounds();

    // Performs a hit check on a grid centered on `centerPoint` with the given `radius`.
    // Triggers shock behavior at any valid hits (Aka POW Block/Gold Fireball hit). 
    // The `radius` determines the width & height of the grid. `width = (radius * 2) + 1`.
    // If `perimeterOnly` is true, only collisions with the perimeter of the radius are triggered.
    // If `rounded` is true the corners of the radius are rounded. Rounding is only applied with a radius of 5 or less.
    void shockHitCheck(const Vec2f& centerPoint, u32 radius, bool perimeterOnly, bool rounded);

    // Performs a hit check within the rect `topLeft` to `bottomRight`.
    // Triggers explosion behavior at any valid hits (Aka Bob-omb hit).
    // The direction `hitDirection` is used to determine which side of an actor the collision occurred.
    void explodeHitCheck(const Vec2f& topLeft, const Vec2f& bottomRight, Direction hitDirection);

    // Tests whether the right wall sensor overlaps a full-solid tile.
    // Used by squeeze detection in checkBg to confirm the actor is actually embedded in solid collision.
    bool isOverlappingRight();

    // Casts a downward ray between the previous and current foot-sensor positions to detect descending terrain.
    // Updates the value of `this->mFloorSnapOffset` to allow position adjustments to be applied.
    void detectGroundDrop();

    // Returns true if the foot sensor is colliding with a surface that is visually lower than it's collision.
    // This can be used to apply minor visual offsets when an actor is standing on surfaces such as horizontal pipes.
    bool isOnLowerVisualSurface();

    // Sets the `sensor` to use for the given `direction`.
    // Providing `nullptr` will disable the sensor slot.
    void setSensor(const Sensor* sensor, Direction direction);

    // Moves `start` toward `target` by `stepSize` without overshooting.
    // Returns `true` when `target` is reached.
    bool stepTowards(f32* start, f32 target, f32 stepSize);

    // Returns the depth of the water at the position (`posX`, `posY`) for the specified `layer`.
    static WaterDepth checkWaterDepth(f32 posX, f32 posY, u8 layer);

    // Sweeps `this->mBgList` for a given sensor `direction`.
    // Performs interaction filtering & hit testing for each collider in the list.
    // Updates `resultsArray` with the results of the best collision.
    // Returns `true` if any hit was found.
    bool sweepActorCollision(BgCheckResultArray& resultsArray, Direction direction);

    // Performs simple foot collision checking by snapping foot sensor against a single tile.
    // Uses single-tile `checkGroundTileCollision()` and per-category `ActorBgCollisionMgr->findBestCollision()`, picks the lowest contact.
    void snapCollisionFoot();

    // Performs a hit check at the position `checkPos`.
    // Triggers block hit/break behavior at any valid hits (Aka Player hit a block).
    // The direction `hitDirection` is used to determine which side of an actor the collision occurred.
    void blockHitCheck(const Vec2f& checkPos, Direction hitDirection);
    
    // Performs simple wall collision checking by snapping foot sensor against a single tile.
    // Uses single-tile `checkWallTileCollision()` and per-category ``ActorBgCollisionMgr->findBestCollision()`, picks the most extreme X offset.
    void snapCollisionWall(Direction direction);

    // Creates a trimmed wall sensor for the sensor in the given `direction`.
    // Trims the sensor to match the ground shape and avoid false wall collisions terrain such as slopes.
    // Trimmed sensors are stored in `this->mTrimmedSensor`.
    void trimWallSensor(Direction direction);

    // Sweeps the tile grid for the foot sensor.
    // Performs interaction filtering & hit testing for each collider.
    // Updates `checkResult` with the results of the best collision.
    // Returns `true` if any hit was found.
    bool sweepTileCollisionFoot(ActorBgCollisionCheckResult& checkResult);

    // Sweeps the tile grid for the head sensor.
    // Performs interaction filtering & hit testing for each collider.
    // Updates `checkResult` with the results of the best collision.
    // Returns `true` if any hit was found.
    bool sweepTileCollisionHead(ActorBgCollisionCheckResult& checkResult);

    // Sweeps the tile grid for the wall sensor in the given `direction`.
    // Performs interaction filtering & hit testing for each collider.
    // Updates `checkResult` with the results of the best collision.
    // Returns `true` if any hit was found.
    bool sweepTileCollisionWall(ActorBgCollisionCheckResult& checkResult, Direction direction);

    // Resets the state of `this->mBgCheck`.
    void resetBgCheck();

    // Computes a bounding box that encompasses all of this CollisionCheck's sensors.
    // The resulting bounding box is stored into `this->mBoundsLocal`. 
    void computeSensorBounds();

    // Processes the result of foot sensor checks.
    // Updates output flags for the foot sensor and handles calling collision callbacks.
    void processResultFoot();

    // Processes the result of head sensor checks.
    // Updates output flags for the head sensor and handles calling collision callbacks.
    void processResultHead();

    // Processes the result of wall sensor checks for the given `direction`.
    // Updates output flags for the wall sensor and handles calling collision callbacks.
    void processResultWall(Direction direction);

    // Copies `this->mWorkSensor` into `this->mWorkSensorPrev`.
    // Rebuilds `this->mWorkSensor` from `this->mSensor` if sensors are flagged as dirty.
    void updateSensors();

    // Checks for a tile at the foot sensor with a hit type of `BgUnitCode::HitType_cFull` or `BgUnitCode::HitType_cHalf`.
    // Updates `checkResult` with the results of the collision.
    // Returns `true` if a hit was found.
    bool checkGroundTileCollision(ActorBgCollisionCheckResult& checkResult);

    // Checks for a tile at the wall sensor in the given `direction` with a hit type of `BgUnitCode::HitType_cFull`.
    // Updates `checkResult` with the results of the collision.
    // Returns `true` if a hit was found.
    bool checkWallTileCollision(ActorBgCollisionCheckResult& checkResult, Direction direction);

    // Returns the current conveyor belt speed for the given `direction`.
    // Only supports left & right directions.
    static f32 getConveyorSpeed(Direction direction);

    // Sets the current conveyor belt speed for the given `direction` to `speed`.
    // Only supports left & right directions.
    static void setConveyorSpeed(Direction direction, f32 speed);

    // Casts a ray at `position.x + xOffset` from `position.y + rayTopYOffset` to `position.y + rayBottomYOffset`.
    // Returns `true` if the ray intersects with solid ground.
    bool checkForSuitableGround(const Vec2f& position, f32 xOffset, f32 rayTopYOffset, f32 rayBottomYOffset);

    // Returns the direction of a the current floor slope.
    Direction getSakaDirection() const;

    // Returns true if `position` is contained within climbable fence collision.
    bool checkOnNet(const Vec2f& position) const;

    // Returns the angle of the wall in the given `direction`.
    Angle getWallAngle(Direction direction) const;

    // Returns true if the provided `flag` is set for the wall sensor.
    bool isFlagSetWall(SensorFlag::Bit flag) const;

    // Returns the angle of the floor that collided with the foot sensor.
    Angle getFootAngle() const;

    // Returns the angle of the ceiling that collided with the head sensor.
    Angle getHeadAngle() const;

    // Returns a pointer to the `ActorBgCollisionCheckResult` for the sensor in `direction`.
    ActorBgCollisionCheckResult* getCollisionCheckResult(Direction direction) const;

    // Returns a pointer to the `BgCollision` that collided with the foot sensor.
    BgCollision* getCollisionOwnerFoot() const;

    // Returns a pointer to the `BgCollision` that collided with the head sensor.
    BgCollision* getCollisionOwnerHead() const;

    // Returns a pointer to the `BgCollision` that collided with the wall sensor in the given `direction`.
    BgCollision* getCollisionOwnerWall(Direction direction) const;

    // Returns `true` if the sensor in `direction` has the necessary flags required to break the given `collision`. 
    bool canBreakCollision(const BgCollision& collision, Direction direction) const;

    // Returns the `SlopeType` for the given `slopeAngle`.
    SlopeType getSlopeType(Angle slopeAngle) const;

    // Unknown. Checks if collision with `bgCollision` by checking a variety of sensor flags the sensor in `direction`.
    bool sub_49AD18(const BgCollision& bgCollision, Direction direction) const;

    // Unknown. Checks if collision with `bgCollision` by checking a variety of sensor flags the sensor in `direction`.
    bool sub_49AF0C(const BgCollision& bgCollision, Direction direction) const;

    // Builds a set of world space points from `prevSensor` and `currSensor` for a given `direction`.
    // Returns the previous frame's world space sensor position via `sensorPosPrevOut`.
    // Returns the current frame's world space sensor position via `sensorPosCurOut`.
    // Returns the offset from the center point of the sensor to the actor's position via `sensorCenterOffsetOut`.
    void buildSensorQueryPoints(Vec2f& sensorPosPrevOut, Vec2f& sensorPosCurOut, Vec2f& sensorCenterOffsetOut, const Sensor& prevSensor, const Sensor& curSensor, Direction direction) const;

    // Returns the angle of the floor that collided with the foot sensor on the previous frame.
    Angle getFootAnglePrev() const;

    // Returns the angle of the floor that collided with the foot sensor, rotated by 180° if `direction` is `Direction::cLeft`.
    Angle getFootAngle(Direction direction) const;

    // Returns a pointer to the `BgCollision` that collided with the foot sensor on the previous frame.
    BgCollision* getCollisionOwnerFootPrev() const;

    // Returns a pointer to the `ActorBgCollisionCheckResult` for the foot sensor.
    ActorBgCollisionCheckResult* getCheckResultFoot() const;

    // Returns a pointer to the `ActorBgCollisionCheckResult` for the head sensor.
    ActorBgCollisionCheckResult* getCheckResultHead() const;

    // Returns a pointer to the `ActorBgCollisionCheckResult` for the wall sensor in the given `direction`.
    ActorBgCollisionCheckResult* getCheckResultWall(Direction direction) const;

    // Returns `true` if collision with `bgCollision` is possible.
    // Checks that `BgUnitCode::HitType` is not `HitType_cNone`, that `bgCollision` is active and that it is not in the ignore list.
    bool canCollideWith(const BgCollision& bgCollision) const;

    // Returns `true` if interaction with `bgCollision` is possible.
    // Checks several sensor flags for the sensor in `direction` to determine if interaction is possible.
    bool canInteractWith(const BgCollision& bgCollision, Direction direction) const;

    // Returns a pointer to the `ActorBgCollisionCheckResult` for the foot sensor from the previous frame.
    ActorBgCollisionCheckResult* getCheckResultFootPrev() const;

    // Returns a pointer to the `ActorBgCollisionCheckResult` for the head sensor from the previous frame.
    ActorBgCollisionCheckResult* getCheckResultHeadPrev() const;

    // Returns a pointer to the active work sensor for the given `direction`.
    // Returns either `this->mWorkSensor` or `this->mTrimmedSensor` depending on which is active.
    Sensor* getWorkSensor(Direction direction) const;

    // Unknown. Wall related.
    // Returns `true` if output bit `18 + direction` is set and bit `27 + direction` is unset.
    bool sub_49B4D0(Direction direction) const;

    // Unknown. Wall related.
    // Returns the equivalent of `sub_49B4D0(Direction::cLeft) || sub_49B4D0(Direction::cRight)`.
    bool sub_49B4D0() const;

    // Returns a pointer to the owner of this Collision check.
    inline ActorBase* getOwner() const
    { 
        return mOwnerPtr;
    }

    // Returns a copy of the sensor in the given `direction`.
    inline Sensor getSensor(Direction direction) const
    {
        if (direction >= Direction::cDirNum || mIsSensorNull[direction])
            return {};
        
        return mSensor[direction];
    }

    // Returns the output of the collision check.
    Output& getOutput()
    { 
        return mOutput;
    }

    // Returns the output of the collision check.
    const Output& getOutput() const
    { 
        return mOutput;
    }

    // Returns true if there was collision with the head sensor.
    bool isCollidedHead() const
    {
        return getOutput().checkHeadEx();
    }
    
    // Returns true if there was collision with the foot sensor.
    bool isCollidedFoot() const
    {
        return getOutput().checkFoot();
    }

    // Returns true if there was wall collision with a wall sensor.
    bool isCollidedWall() const
    {
        return getOutput().checkWallLeftEx() || getOutput().checkWallRightEx();
    }

    // Returns true if there was collision with the wall sensor for the given `direction`.
    bool isCollidedWall(Direction direction) const
    {
        return getOutput().checkWallEx(direction);
    }

    // Returns true if there was wall collision with the right wall sensor.
    bool isCollidedWallRight() const
    {
        return getOutput().checkWallRightEx();
    }

    // Returns true if there was wall collision with the left wall sensor.
    bool isCollidedWallLeft() const
    {
        return getOutput().checkWallLeftEx();
    }
    
    // Returns true if there was collision with a slope.
    bool isOnSlope() const
    {
        return getOutput().checkOnSlope();
    }
    
public:
    using List = LineNodeMgr<ActorBgCollisionCheck>;
    
    /* 0x004 */  BasicBgCollisionCheck mBgCheck;                    // A basic check object used to perform simple collision hit tests.
    /* 0x050 */  ActorBgHitCheckCallback mBgHitCheckCallback;       //
    /* 0x058 */  sead::FixedPtrArray<BgCollision, 512> mBgList;     // List of all BgCollision that intersect with `mBoundsSwept`.
    /* 0x864 */  List::Node mListNodeFoot;                          // A list node used to insert this Collision Check into the foot list of a `BgCollision` the foot sensor has collided with.
    /* 0x870 */  List::Node mListNodeHead;                          // A list node used to insert this Collision Check into the head list of a `BgCollision` the head sensor has collided with.
    /* 0x87C */  List::Node mListNodeWallR;                         // A list node used to insert this Collision Check into the right wall list of a `BgCollision` the right wall sensor has collided with.
    /* 0x888 */  List::Node mListNodeWallL;                         // A list node used to insert this Collision Check into the left wall list of a `BgCollision` the left wall sensor has collided with.
    /* 0x894 */  ActorBase* mOwnerPtr;                              // Pointer to the actor that owns this collision check.
    /* 0x898 */  ActorBase* mIgnoreActor;                           // An actor to ignore collision with during collision checking.
    /* 0x89C */  FollowArg mFollowArg;                              // Used to track actor and adjust the position of an actor.
    /* 0x8AC */  Vec2f mBgSpeed;                                    // Accumulated speed of the tile. (Used by conveyer belts, quicksand etc).
    /* 0x8B4 */  f32 mFloorSnapOffset;                              // Offset applied when checking ground collision to account for slope.
    /* 0x8B8 */  Direction mWallBiasDirection;                      // Used to bias wall collisions in a specific direction. Set to the inverse of the direction of `this->mOwnerPtr` in `checkBg()`.
    /* 0x8B9 */  u8 _8B9;                                           // Unused?
    /* 0x8BA */  bool mIsInitialized;                               // True when this collision check has been initialized.
    /* 0x8BB */  bool mSensorsDirty;                                // True when the sensor data has changed and needs updating.
    /* 0x8BC */  bool mBoundsDirty;                                 // True when the bound box needs recalculating.
    /* 0x8BD */  SensorBoolArray mIsSensorDirty;                    // Whether a sensor has been changed and needs updating. Indexed by direction.
    /* 0x8C1 */  SensorBoolArray mIsSensorNull;                     // Whether a sensor was explicitly set to null. Indexed by direction.
    /* 0x8C5 */  SensorBoolArray mHasWorkSensor;                    // If a working copy of primary sensor has been made. Indexed by direction.
    /* 0x8CC */  SensorArray mSensor;                               // The sensor data set by the actor. Indexed by direction.
    /* 0x8FC */  SensorArray mWorkSensor;                           // The working copy of the sensor data (Modified during collision checks). Indexed by direction.
    /* 0x92C */  SensorArray mWorkSensorPrev;                       // The previous frame's working copy of the sensor data. Indexed by direction.
    /* 0x95C */  WallSensorArray mTrimmedSensor;                    // Trimmed wall sensors for when wall sensors are partially obstructed. (E.g. when standing on a slope).
    /* 0x974 */  WallSensorBoolArray mHasTrimmedSensor;             // Whether the trimmed sensor has been set.
    /* 0x976 */  WallSensorBoolArray mHasTrimmedSensorPrev;         // Whether the trimmed sensor was set on the previous frame.
    /* 0x978 */  SensorFlagArray mSensorFlag;                       // Flags set on each sensor. Indexed by direction.
    /* 0x998 */  ProcessFlags mProcessFlags;                        // Flags used to enable/disable parts of the check process.
    /* 0x999 */  u8 _999;                                           // Unused?
    /* 0x99A */  SensorBgCollisionCatArray bgCheckResultIdx;        // 
    /* 0x99E */  SensorBgCollisionCatArray bgCheckResultIdxPrev;    //
    /* 0x9A2 */  u8 _9A2[6];                                        // Unused?
    /* 0x9A8 */  SensorBgCheckResultArray mBgCheckResults;          //
    /* 0xB68 */  SensorBgCheckResultArray mBgCheckResultsPrev;      // copy of _9A8 (prev _9A8 ?)
    /* 0xD28 */  SensorHitBgCheckDataArray mBgCheckData;            //
    /* 0xD48 */  SensorHitBgCheckDataArray mBgCheckDataPrev;        //
    /* 0xD68 */  ActorBgCollisionCheck::Output mOutput;             // Holds the resulting output flags from collision checking.
    /* 0xD70 */  ActorBgCollisionCheck::Output mOutputPrev;         // Holds the resulting output flags from collision checking from the previous frame.
    /* 0xD78 */  sead::BoundBox2f mBoundsLocal;                     // A BoundBox encompassing all of the sensors. In local space.
    /* 0xD88 */  sead::BoundBox2f mBoundsSwept;                     // A BoundBox encompassing both the current and previous frame's bounds. In world space.
    /* 0xD98 */  sead::BoundBox2f mBoundsWorld;                     // A BoundBox encompassing all of the sensors. In world space.
    /* 0xDA8 */  sead::BoundBox2f mBoundsWorldPrev;                 // A copy of `this->mBoundsWorld` from the previous frame.
    /* 0xDB8 */  u8 _DB8;                                           // Unused?
    /* 0xDB9 */
    /* 0xDBA */
    /* 0xDBB */
    /* 0xDBC */  f32 _DBC;                                          //
};

ENUM_CLASS_ENABLE_FLAGS(ActorBgCollisionCheck::ProcessFlags, u8);

size_assert(ActorBgCollisionCheck, 0xDC0);
