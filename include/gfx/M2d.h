#pragma once

#include "math/Vec.h"
#include "nw/lyt.h"
#include "scene/MessageMgr.h"
#include "sead.h"
#include "sys/LinkedList.h"
#include "types.h"

class TagProcessor;


namespace m2d {

class TextBox_c;


// Size: 0x20
class Layout_c : public nw::lyt::Layout
{
};

size_assert(Layout_c, 0x20);


// Size: 0x2F4
class ResAcc_c
{
public:
    ResAcc_c();
    virtual ~ResAcc_c();

    bool load(const char* path, u32 alignment);
    void unload();


public:
    /* 0x004 */  nw::lyt::ArcResourceAccessor* resAccessor;     //
    /* 0x008 */  void* arcData;                                 //
    /* 0x00C */  nw::lyt::ArcResourceAccessor arcResAccessor;   //
    /* 0x14C */  u32 _14C;                                      //
    /* 0x150 */  IntrusiveList _150;                            //
    /* 0x15C */  u8 _15C;                                       //
    /* 0x15D */  u8 _15D[3];                                    // padding
    /* 0x160 */  void* fileData;                                //
    /* 0x164 */  u8 romFile[0x190];                             // RomFile
};

size_assert(ResAcc_c, 0x2F4);


// Size: 0x28
// Derives from an unmapped base class (constructor 0x0047E090, vtable 0x005D3558), not an nw::lyt class
class Anm_c
{
public:
    static constexpr u8 cFlagPlayOnce = 1 << 0;
    static constexpr u8 cFlagReverse = 1 << 1;

public:
    Anm_c();
    virtual ~Anm_c();

    bool build(const char* bclanName, ResAcc_c* resAcc);
    void setTransform(nw::lyt::AnimTransform* transform);

    void update();
    void setFrame(f32 frame);
    void setPlaybackDirection(bool isReversed);
    void setLoop(bool isLooping);

    f32 getStartFrame();
    f32 getEndFrame();
    bool isDone();
    bool checkFrame(f32 frame);


public:
    /* 0x04 */  f32 frameCount;                         //
    /* 0x08 */  f32 frame;                              //
    /* 0x0C */  f32 prevFrame;                          //
    /* 0x10 */  f32 rate;                               //
    /* 0x14 */  u8 flags;                               //
    /* 0x15 */  u8 _15[3];                              // padding
    /* 0x18 */  nw::lyt::AnimTransform* transform;      //
    /* 0x1C */  bool isBound;                           //
    /* 0x1D */  u8 _1D;                                 // padding
    /* 0x1E */  u16 animCount;                          //
    /* 0x20 */  void* animLinks;                        // nw::lyt::AnimationLink[animCount]
    /* 0x24 */  bool isDescendingBind;                  //
    /* 0x25 */  u8 _25[3];                              // padding
};

size_assert(Anm_c, 0x28);


// Size: 0x118
class EmbedLayoutBase_c : public ListNode
{
public:
    EmbedLayoutBase_c();
    virtual ~EmbedLayoutBase_c();

    virtual void draw();
    virtual void update();  // Also called once by build
    virtual bool build(const char* bclytName, ResAcc_c* resAcc, u32 cmdListBufferSize);
    virtual void setupProjectionMatrix();
    virtual void recordDrawCommands();

    void drawCmdList(nw::lyt::DrawInfo* drawInfo);
    f32 calcParallax();

    void bindAnm(Anm_c* anm, nw::lyt::Group* group, bool recursive = false);
    void unbindAnm(Anm_c* anm, nw::lyt::Group* group, bool recursive = false);
    void unbindAllAnm();
    void setGroupVisible(nw::lyt::Group* group, bool visible);

    nw::lyt::Group* getGroup(const char* name);
    nw::lyt::Pane* getPane(const char* name);
    nw::lyt::TextBox* getTextBox(const char* name);
    nw::lyt::Picture* getPicture(const char* name);
    nw::lyt::Window* getWindow(const char* name);
    nw::lyt::Bounding* getBounding(const char* name);


public:
    /* 0x00C */  u8 priority;                   //
    /* 0x00D */  u8 _D[3];                      // padding
    /* 0x010 */  Layout_c layout;               //
    /* 0x030 */  nw::lyt::DrawInfo drawInfo;    //
    /* 0x0BC */  ResAcc_c* resAcc;              //
    /* 0x0C0 */  Vec3f cameraPos;               //
    /* 0x0CC */  u32 animateOption;             //
    /* 0x0D0 */  u32 cmdList;                   //
    /* 0x0D4 */  u32 cmdBufferOffset;           //
    /* 0x0D8 */  s32 cmdBufferSize;             //
    /* 0x0DC */  u32 cmdRequestId;              //
    /* 0x0E0 */  s32 cmdRequestSize;            //
    /* 0x0E4 */  u32 cmdStateMask;              //
    /* 0x0E8 */  s32 cmdListBufferSize;         //
    /* 0x0EC */  bool cmdCopy;                  //
    /* 0x0ED */  bool isCmdListDirty;           //
    /* 0x0EE */  bool isViewMtxReady;           //
    /* 0x0EF */  bool isProjMtxReady;           //
    /* 0x0F0 */  bool isStereoEnabled;          //
    /* 0x0F1 */  u8 projectionMode;             // 1: perspective, otherwise orthographic
    /* 0x0F2 */  u8 _F2;                        //
    /* 0x0F3 */  u8 _F3;                        // padding
    /* 0x0F4 */  f32 parallax;                  //
    /* 0x0F8 */  f32 prevParallax;              //
    /* 0x0FC */  f32 perspectiveCameraZ;        //
    /* 0x100 */  u32 screen;                    // 0x400 top left, 0x410 top right, 0x401 bottom
    /* 0x104 */  bool isScissorEnabled;         //
    /* 0x105 */  u8 _105[3];                    // padding
    /* 0x108 */  f32 scissorX;                  //
    /* 0x10C */  f32 scissorY;                  //
    /* 0x110 */  f32 scissorWidth;              //
    /* 0x114 */  f32 scissorHeight;             //
};

size_assert(EmbedLayoutBase_c, 0x118);


// Size: 0x11C
class EmbedLayout_c : public EmbedLayoutBase_c
{
public:
    EmbedLayout_c();
    virtual ~EmbedLayout_c();

    void draw() override;
    void update() override;
    void setupProjectionMatrix() override;
    void recordDrawCommands() override;

    void copyTransformFromPane(nw::lyt::Pane* pane);
    void setPosition(const Vec3f& position);
    void screenToLayoutPos(const Vec2f& screenPos, Vec2f& layoutPos);

    bool getBoundings(nw::lyt::Bounding** out, const sead::SafeString* names, const u32& count);
    bool getGroups(nw::lyt::Group** out, const sead::SafeString* names, const u32& count);
    bool getPanes(nw::lyt::Pane** out, const sead::SafeString* names, const u32& count);
    bool getPictures(nw::lyt::Picture** out, const sead::SafeString* names, const u32& count);
    bool getTextBoxes(nw::lyt::TextBox** out, const sead::SafeString* names, const u32& count);
    bool getTextBoxes(TextBox_c* out, const sead::SafeString* names, const u32& count, TagProcessor* tagProcessor, MessageMgr::Handle* handle);
    bool getWindows(nw::lyt::Window** out, const sead::SafeString* names, const u32& count);

public:
    /* 0x118 */  u8 _118;       //
    /* 0x119 */  u8 _119[3];    // padding
};

size_assert(EmbedLayout_c, 0x11C);


// Size: 0xA08
class DrawMgr_c
{
public:
    static DrawMgr_c* createInstance(sead::Heap* heap);
    static DrawMgr_c* getInstance();

    virtual ~DrawMgr_c();

    virtual void addToDrawList(EmbedLayoutBase_c* layout, Screen screen);
    virtual void drawTopLeft();
    virtual void drawTopRight();
    virtual void drawBottom();

public:
    /* 0x004 */  IntrusiveList topLayouts;          //
    /* 0x010 */  IntrusiveList bottomLayouts;       //
    /* 0x01C */  u8 graphicsResource[0x2E4];        // nw::lyt::GraphicsResource
    /* 0x300 */  u8 stereoCamera[0x60];             // nn::ulcd::CTR::StereoCamera
    /* 0x360 */  u8 drawer[0x6A4];                  // nw::lyt::Drawer
    /* 0xA04 */  bool _A04;                         //
    /* 0xA05 */  s8 _A05;                           //
    /* 0xA06 */  bool isAddEnabled;                 //
    /* 0xA07 */  bool isDrawEnabled;                //
};

size_assert(DrawMgr_c, 0xA08);


// Size: 0x24
class TextBox_c
{
public:
    // Size: 0x10
    struct Child
    {
        /* 0x0 */  nw::lyt::TextBox* textBox;   //
        /* 0x4 */  nw::lyt::Size fontSize;      //
        /* 0xC */  f32 charSpace;               //
    };
    size_assert(Child, 0x10);

public:
    TextBox_c();
    virtual ~TextBox_c();

    void build(EmbedLayout_c* layout, nw::lyt::TextBox* textBox, TagProcessor* tagProcessor, MessageMgr::Handle* handle);
    void setText(const sead::WSafeString& text, u16 dstIdx = 0);

    void setMessage(const sead::SafeString& label, s32 argCount, ...);
    void setMessage(const sead::SafeString& label, MessageMgr::Handle* handle, s32 argCount, ...);
    void setMessageV(const sead::SafeString& label, MessageMgr::Handle* handle, bool allocBuffer, s32 argCount, const u32* args);
    void setPidMessage(s32 pid, s32 argCount, ...);
    void setPidMessage(s32 pid, MessageMgr::Handle* handle, s32 argCount, ...);
    s32 getPidMessageLength(s32 pid, MessageMgr::Handle* handle);

    void allocStringBuffer(u16 length);
    void allocStringBufferForMessage(const sead::SafeString& label, MessageMgr::Handle* handle);
    void allocStringBufferForPid(s32 pid, MessageMgr::Handle* handle);
    void updateChildren();


public:
    /* 0x04 */  EmbedLayout_c* embedLayout;     //
    /* 0x08 */  nw::lyt::TextBox* textBox;      //
    /* 0x0C */  nw::lyt::Size fontSize;         //
    /* 0x14 */  f32 charSpace;                  //
    /* 0x18 */  u32 childCount;                 //
    /* 0x1C */  Child* children;                // Child[childCount]
    /* 0x20 */  MessageMgr::Handle* handle;     //
};

size_assert(TextBox_c, 0x24);


void fitTextToPane(nw::lyt::TextBox* textBox, const wchar_t* text, u32 length, const nw::lyt::Size& fontSize, f32 charSpace, f32 minScale);
f32 getTextWidth(const nw::lyt::TextBox* textBox);
Vec3f getPaneGlobalTranslation(const nw::lyt::Pane* pane);

bool isPidTextBox(nw::lyt::TextBox* textBox);
bool isCopyTextBox(nw::lyt::TextBox* textBox);
bool isPstrTextBox(nw::lyt::TextBox* textBox);
s32 getCopyToCount(nw::lyt::TextBox* textBox);
const char* getCopyToName(nw::lyt::TextBox* textBox, s32 idx);

} // namespace m2d
