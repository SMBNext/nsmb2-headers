#include "collider/ActorCollisionCheck.h"
#include "actors/ActorBase.h"

f32 ActorCollisionCheck::getTop()
{
    return info.centerOffset.y + owner->position.y + info.halfSize.y;
}

f32 ActorCollisionCheck::getBottom()
{
    return info.centerOffset.y + owner->position.y - info.halfSize.y;
}

f32 ActorCollisionCheck::getCenterY()
{
    return info.centerOffset.y + owner->position.y;
}

f32 ActorCollisionCheck::getRight()
{
    return info.centerOffset.x + owner->position.x + info.halfSize.x;
}

f32 ActorCollisionCheck::getLeft()
{
    return info.centerOffset.x + owner->position.x - info.halfSize.x;
}

f32 ActorCollisionCheck::getCenterX()
{
    return info.centerOffset.x + owner->position.x;
}
