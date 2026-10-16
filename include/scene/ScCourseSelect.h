#pragma once

#include "scene/StateScene.h"

#include "gfx/Light.h"

class ScCourseSelect : public StateScene
{
public:
    ScCourseSelect();               // 0x002F84F8
    ~ScCourseSelect() override;     // 0x002F8560

    Result onCreate() override;        // 0x002F7E98
    Result onDelete() override;        // 0x002F83D0
    Result onExecute() override;       // 0x002F824C
    Result onDraw() override;          // 0x002F7E40

    DECLARE_STATE_ID(ScCourseSelect, 1AE);      // Is empty
    DECLARE_STATE_ID(ScCourseSelect, 1AF);

    static ScCourseSelect* instance;

    u8 _3C;
    u32 totalCoinCount;
    u32 coinsGained;
    EnvironmentalLightSet light1;           // Course LUTs?
    EnvironmentalLightSet playerLight;
    EnvironmentalLightSet light3;           // Some materials (flag)
    EnvironmentalLightSet worldLight;
    u32 _F8;
    bool _FC;
    u32 _100;

};
