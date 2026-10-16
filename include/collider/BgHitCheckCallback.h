#pragma once

struct BgCollisionCheckResultPoint;
struct BgCollisionCheckResultArea;

class BgHitCheckCallback
{
public:
    virtual bool hit(const BgCollisionCheckResultPoint& hitRes) = 0;
    virtual bool hit(const BgCollisionCheckResultArea& hitRes) = 0;
};