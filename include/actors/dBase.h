#pragma once

#include "actors/fBase.h"
#include "course/Profiles.h"
#include "types.h"

extern bool isPaused;


// size: 0x14
class dBase : public fBase
{
public:
    dBase();
    virtual ~dBase();

    bool preCreate() override;
    void postCreate(Result createResult) override;
    bool preDelete() override;
    void postDelete(Result deleteResult) override;
    bool preExecute() override;
    void postExecute(Result execResult) override;
    bool preDraw() override;
    void postDraw(Result drawResult) override;

    // Deleted.
    virtual void vf3C();

    // Creates a child under the given `parent`.
    static dBase* createChild(u16 profileId, dBase* parent, u32 param);
};

size_assert(dBase, 0x14);
