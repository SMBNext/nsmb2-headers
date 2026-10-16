#pragma once

#include "actors/ActorState.h"
#include "math/Vec.h"
#include "types.h"

// Size: 0xFEC
class LiftBase : public ActorState
{
public:
    LiftBase();

    // Updates the state of `this->inLiquid` and creates a liquid splash effect when entering liquid.
    virtual void updateLiquid(f32 xPos);

    // Called in `onCreate` for multiple lift types.
    // Initializes `scale` to `{0.5f, 0.5f, 0.5f}` and `depth` to `400.0f`.
    static void initScaleAndDepth(Vec3f& scale, f32& depth);

    // Returns true if at least `minPlayers` players are on the lift.
    // If `minPlayers` is <= 0, `minPlayers` is treated as 1.
    bool hasPlayersOn(const BgCollision& collision, s8 minPlayers = 1);

    // Returns a bitmask encoding which players are on the lift.
    u32 getPlayerOnMask(const BgCollision& collision);

    // Returns the number of players on the lift.
    u32 getPlayerOnCount(const BgCollision& collision);

    // Creates a break effect at the given position.
    // `platformWidth` should be the width of the platform in tiles.
    void createBreakEffect(Vec3f& position, f32 platformWidth);
    
public:
    /* 0xFE8 */  bool inLiquid;     // Whether the lift is currently in liquid.
};

size_assert(LiftBase, 0xFEC);
