#pragma once

#include "actors/dBase.h"
#include "scene/FaderMgr.h"

class Scene : public fBase      // size: 0x14
{
public:
    Scene();
    virtual ~Scene();

    bool preCreate() override;
    void postCreate(Result createResult) override;
    bool preDelete() override;
    void postDelete(Result deleteResult) override;
    bool preExecute() override;
    void postExecute(Result execResult) override;    
    bool preDraw() override;
    void postDraw(Result drawResult) override;

    virtual void vf3C();            // deleted
    virtual s32 vf40();             // does nothing

    static void changeScene(u32 profileId, FaderMgr::FaderType topFaderTypeIn, FaderMgr::FaderType topFaderTypeOut, FaderMgr::FaderType bottomFaderTypeIn, FaderMgr::FaderType bottomFaderTypeOut, u32 settings);
    static void changeScene(u32 profileId, u32 settings);

    static void setTransition(u8 type, u8 unk1, u8 unk2, u8 unk3);

    static Scene* currentScene;
    static u16 nextSceneId;
    static u16 currentSceneId;
    static u16 lastSceneId;
};
