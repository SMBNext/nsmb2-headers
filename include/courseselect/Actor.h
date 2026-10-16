#pragma once

#include "actors/dBase.h"
#include "courseselect/CourseSelect.h"
#include "math/Vec.h"

#include "gfx/AnimModel.h"
#include "utility/Direction.h"

namespace course_select {
class Actor : public dBase
{
public:

    struct CreateInfo   // size: 0x3C, seems to somewhat match ActorBase::CreateInfo
    {
        u16 profileId;  // 0
        u32 settings;   // 4
        u32 _unk8;      // 8
        u32 _unkC;      // C
        fBase* parent;  // 10
        u32 _unk14;     // 14
        u32 _unk18;     // 18
        Vec3f position;  // 1C
        u32 _unk28;     // 28
        u8 _unk2C;      // 2C
        u8 worldId;     // 2D
        u8 nodeId;      // 2E
        u8 _unk2F;      // 2F
        u32 _unk30;     // 30
        u32 _unk34;     // 34
        u32 _unk38;     // 38
    };

    class ActorUnkStruct
    {
    public:
        u8 unk1;
        u8 unk2;
        u8 unk3;
        u8 unk4;
        bool disableScript;
        u8 unk5;
        u8 unk6;
        u8 unk7;
        u8 unk8;
    };

public:
    Actor();
    virtual ~Actor();

    void postCreate(Result createResult) override;     // does nothing
    void postDelete(Result deleteResult) override;     // does nothing
    bool preExecute() override;
    void postExecute(Result execResult) override;    // does nothing
    bool preDraw() override;          // checks for _76
    
    virtual void vf40();                // deleted
    virtual void vf44();                // deleted

    static Actor* create(CreateInfo* info);

    void applyYAcceleration(f32 acceleration, f32 minimumSpeed);
    void updatePlanarSpeed();   // Calculates x/z speed based on planar speed and heading

    CsDirection direction;  // 13
    Vec3f acceleration;     // 14
    f32 planarSpeed;        // 20
    Vec3f speed;            // 24
    Vec3f minSpeed;         // 30
    Vec3f position;         // 3C
    Vec3f scale;            // 48
    Vec3i rotation;         // 54
    u32 _60;                // Inited to 0
    s32 headingAngle;       // Inited to 0
    u32 _68;                // Inited to 0
    u8 worldId;             // 6C
    u8 courseId;            // 6E
                            // Padding?
    u32 actorSettings;      // 70   Same as fBase::settings
    u8 _74;                 // Inited to 0    (maybe actor type?)
    bool execute;           // 75
    bool visible;           // 76   If set to false, onExecute() will not run
                            // Padding?
    f32 _78;                // Inited to 0.0f
    f32 _7C;                // Inited to 0.0f
    f32 _80;                // Inited to 0.0f
    Vec3f startPosition;    // Inited to 0.0f, then pulled from CreateInfo->position

};
}
