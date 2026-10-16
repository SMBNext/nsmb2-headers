#pragma once

#include "gfx/M2d.h"
#include "scene/Fader.h"
#include "sys/Common.h"

class FaderMgrBase
{
public:
    enum FaderType : u8
    {
        FADER_TYPE_FADE                 = 0x0,
        FADER_TYPE_SLOW_FADE            = 0x1,
        FADER_TYPE_CIRCLE               = 0x2,
        FADER_TYPE_CIRCLE_PLAYER        = 0x3,
        FADER_TYPE_CIRCLE_CS_PLAYER     = 0x4,
        FADER_TYPE_HEAD                 = 0x5,
        FADER_TYPE_BOWSER               = 0x6,
        FADER_TYPE_SWIPE_DOWN           = 0x7,
        FADER_TYPE_SWIPE_UP             = 0x8,
        FADER_TYPE_FADE_FASTER          = 0x9,
        FADER_TYPE_INSTANT              = 0xA,
        FADER_TYPE_TYPE_MAX             = 0xB,
    };

    virtual ~FaderMgrBase();
    virtual void initialize() = 0;
    virtual void unk() = 0;
    virtual void update();
    virtual void draw();

    void setTransitionType(FaderType topType, FaderType bottomType);       // 0x002553C0
    bool startFadeOut(Screen screen, s32 fadeDuration=-1);                 // 0x00255110
    bool startFadeIn(Screen screen, s32 fadeDuration=-1);                  // 0x002551B8

    bool isFadeInComplete(Screen screen);                                  // 0x002552A8
    bool isFadeOutComplete(Screen screen);                                 // 0x00255210
    bool isFadeIn(Screen screen);                                          // 0x002552F4
    bool isFadingOut(Screen screen);                                       // 0x0025525C

    Faderunk_437BC4* activeFader[2];    // Indexed by Screen
};

size_assert(FaderMgrBase, 0xC);


class FaderMgr : public FaderMgrBase
{
public:

    void initialize() override;
    void unk() override { }

    void setColored(bool value);            // 0x0040CDE8

    static FaderMgr* instance;
    static FaderMgr* instance2;

    /*
        Faderunk_437DC4 *mFade; 
        Faderunk_2926B8 *mFadeSlower; 
        Faderunk_31862C *mFadeCircle; 
        Faderunk_346188 *mFadeCirclePlayer;
        Faderunk_39170C *mFadeCircle2; 
        Faderunk_301A48 *mFadeHead; 
        Faderunk_3014E8 *mFadeBowser; 
        Faderunk_340BC8 *mFadeDown; 
        Faderunk_340A2C *mFadeUp; 
        Faderunk_23DC24 *mFadeFaster; 
        Faderunk_1CB810 *mFadeInstant;
     */
    Faderunk_437DC4* fadersTop[11];

    // two lists of transitions? one for each screen? (2, 3, 4, 5, 6, 7, 8 do not get init to anything)
    Faderunk_437DC4* fadersBottom[11];

    u8 faderIdxTop;
    u8 faderIdxBottom;
    u8 _66;                 // Likely padding
    u8 _67;

private:
    static const char* transitionPictureNames[];
    static const u32 transitionPictureNameNum;
    static constexpr u32 cTransitionPictureNum = 36;
    static nw::lyt::Picture* transitionPictures[cTransitionPictureNum];
    static u32 transitionPicturesNum;
};

// size_assert(FaderMgr, 0x68);

class SceneTransitionSettings
{
    SEAD_SINGLETON_DISPOSER(SceneTransitionSettings);
public:
    enum class Request : u8
    {
        cNone           = 0,
        cAreaChange     = 1,
        cReloadScene    = 2,
    };

    bool shouldWaitForFade() const;     // 0x004AE028
    void clear();                       // 0x0042C21C

    Request request;                        // 10
    u8 type;                                // 11
    FaderMgr::FaderType exitFaderType;      // 12
    u32 _14;                                // 14
};

size_assert(SceneTransitionSettings, 0x18);
