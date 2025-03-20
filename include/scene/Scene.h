#pragma once

#include "actors/dBase.h"

class Scene : public fBase      // size: 0x14
{
public:
    Scene();
    virtual ~Scene();

    int beforeCreate() override;
    void afterCreate(int) override;
    int beforeDelete() override;
    void afterDelete(int) override;
    int beforeExecute() override;
    void afterExecute(int) override;    
    int beforeDraw() override;
    void afterDraw(int) override;

    virtual void vf3C();            // deleted
    virtual s32 vf40(u32);          // does nothing


    enum TransitionType : u8
    {
        TRANSITION_FADE = 0,
        TRANSITION_FADE_SLOWER = 1,
        TRANSITION_CIRCLE = 2,
        TRANSITION_CIRCLE_PLAYER = 3,
        TRANSITION_CIRCLE_2 = 4,
        TRANSITION_HEAD = 5,
        TRANSITION_BOWSER = 6,
        TRANSITION_SWIPE_DOWN = 7,
        TRANSITION_SWIPE_UP = 8,
        TRANSITION_FADE_FASTER = 9,
        TRANSITION_INSTANT = 10,
        TRANSITION_FADE_2 = 11
    };

    static void changeScene(u32 profileId, u8 transitionType, u8 unk1, u8 unk2, u8 unk3, u32 settings);
    static void changeScene(u32 profileId, u32 settings);

    static void setTransition(u8 type, u8 unk1, u8 unk2, u8 unk3);

    static Scene* currentScene;
    static u16 nextSceneId;
    static u16 currentSceneId;
    static u16 lastSceneId;
};
