#pragma once

#include "sead.h"
#include "courseselect/CourseSelect.h"

namespace course_select {
class TransitState
{
public:
    CsInfo::PointInfo::Point* prevPoint;
    CsInfo::PointInfo::Point* currentPoint;
    CsInfo::PointInfo::Point* targetPoint;
};

class TransitTracker
{
    SEAD_SINGLETON_DISPOSER(TransitTracker);
public:
    virtual ~TransitTracker();

    void init();
    void record(CsInfo::PointInfo::Point* lastPoint, CsInfo::PointInfo::Point* currentPoint, CsInfo::PointInfo::Point* targetPoint);
    f32 getTransitDistance();

    TransitState* transitStates;
    u32 numTransitStates;
    u32 offset;
    u32 currentIdx;
};
}
