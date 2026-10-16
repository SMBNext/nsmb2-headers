#include "actors/ActorState.h"

#include "course/Course.h"
#include "state/FStateStateMgr.h"


class RailParent // size: 0x68
{
public:
    FStateStateMgr<RailParent> stateMgr;
    Course::PathNode *startNode;          // maybe cur node?
    Vec3f targetRay;                      // init to (0.01, 0.0, 0.0)
    Vec2f currentPos;
    Vec2f _40;
    Vec3i _48;
    f32 velocity;
    u16 nodeCount;
    u16 curNodeID;
    u16 delayTimer;
    u16 _5E;
    u16 startNodeID;
    bool isLinearVertical;
    u8 _63;
    u8 _64;

    bool initialize(const Vec2f& targetPos, u8 pathId, bool isLinearVertical, f32 unk1, u8 unk2, u16 startNodeId, u16 unk3);
};


class RailPolyParent : public ActorState // size: 0x1060
{
public:
    RailParent railParent;
    Vec3f initialPosition;
    bool easeMovement;                    // unused (init to 0)
    u8 unkMovementId;
    u8 _105E[2];                          // unk (probably padding)

    Result onCreate() override;

    DECLARE_STATE_ID(RailPolyParent, 4B6);
    DECLARE_STATE_ID(RailPolyParent, 4B7);
};

size_assert(RailPolyParent, 0x1060);