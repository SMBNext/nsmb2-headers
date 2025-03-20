#pragma once

#include "SolidCollider.h"


class RectCollider : public SolidCollider<4>     // size: 0x270
{
public:
    struct Info
    {
        Vec2f centerOffset;
        Vec2f halfSize;
        Vec2f topLeft;
        Vec2f bottomRight;
        s32 rotation;
    };

    RectCollider();
    ~RectCollider();

    void setup(ActorBase* owner, const Info& info);
    void setBounds(const Vec2f& topLeft, const Vec2f& bottomRight);
};
