#pragma once

#include "math/Vec.h"
#include "nw/font/ResFont.h"
#include "sys/Common.h"
#include "types.h"

namespace nw {
namespace lyt {

class AnimResource;
class AnimTransform;
class AnimationLink;
class ResBlockSet;
class TextureInfo;

enum PaneFlag
{
    PANEFLAG_VISIBLE          = 0x0,
    PANEFLAG_INFLUENCEDALPHA  = 0x1,
    PANEFLAG_LOCATIONADJUST   = 0x2,
    PANEFLAG_USERALLOCATED    = 0x3,
    PANEFLAG_MTXCONDITION     = 0x4,
    PANEFLAG_MTXCONDITION_1   = 0x5,
    PANEFLAG_USERMTX          = 0x6,
    PANEFLAG_USERGLOBALMTX    = 0x7
};

enum TextColor
{
    TEXTCOLOR_TOP    = 0x0,
    TEXTCOLOR_BOTTOM = 0x1
};

enum ExtUserDataType : u8
{
    EXTUSERDATATYPE_STRING = 0x0,
    EXTUSERDATATYPE_INT    = 0x1,
    EXTUSERDATATYPE_FLOAT  = 0x2
};


// Size: 0x8
struct Size
{
    /* 0x0 */  f32 width;       //
    /* 0x4 */  f32 height;      //
};

size_assert(Size, 0x8);


// Size: 0x20
class TexMap
{
public:
    /* 0x00 */  u32 texObject;              //
    /* 0x04 */  void* physicalAddress;      //
    /* 0x08 */  u16 width;                  //
    /* 0x0A */  u16 height;                 //
    /* 0x0C */  u16 realWidth;              //
    /* 0x0E */  u16 realHeight;             //
    /* 0x10 */  u32 bits;                   //
    /* 0x14 */  u32 u32WrapFilter;          //
    /* 0x18 */  u32 u32WidthHeight;         //
    /* 0x1C */  u32 u32Format;              //
};

size_assert(TexMap, 0x20);


// Size: 0x50
class Material
{
public:
    virtual ~Material();

public:
    /* 0x04 */  u8 animList[0xC];       // ut::LinkList
    /* 0x10 */  Color8 colors[7];       // [0] buffer, [1] to [6] konst 0 to 5
    /* 0x2C */  u32 memCap;             // internal::MatMemNums
    /* 0x30 */  u32 memNum;             // internal::MatMemNums
    /* 0x34 */  void* mem;              //
    /* 0x38 */  char name[21];          //
    /* 0x4D */  u8 flag;                //
    /* 0x4E */  u8 padding[2];          //
};

size_assert(Material, 0x50);


// Size: 0x8C
class DrawInfo
{
public:
    DrawInfo();
    virtual ~DrawInfo();

public:
    /* 0x04 */  f32 projMtx[4][4];              //
    /* 0x44 */  f32 viewMtx[3][4];              //
    /* 0x74 */  Vec2f locationAdjustScale;      //
    /* 0x7C */  f32 globalAlpha;                //
    /* 0x80 */  void* graphicsResource;         // GraphicsResource*
    /* 0x84 */  void* layout;                   // Layout*
    /* 0x88 */  u32 flag;                       //
};

size_assert(DrawInfo, 0x8C);


// Size: 0xC
class ExtUserData
{
public:
    /* 0x0 */  u32 nameStrOffset;       //
    /* 0x4 */  u32 dataOffset;          //
    /* 0x8 */  u16 num;                 //
    /* 0xA */  ExtUserDataType type;    //
    /* 0xB */  u8 padding;              //
};

size_assert(ExtUserData, 0xC);


namespace internal {

// Size: 0xC
class PaneBase
{
public:
    virtual ~PaneBase();

public:
    /* 0x4 */  u8 link[0x8];    // ut::LinkListNode
};

size_assert(PaneBase, 0xC);

} // namespace internal


// Size: 0xD4
class Pane : public internal::PaneBase
{
public:
    virtual ~Pane();

    virtual void* GetRuntimeTypeInfo() const;
    virtual Color8 GetVtxColor(u32 idx) const;                                                      // Deleted
    virtual void SetVtxColor(u32 idx, Color8 c);                                                    // Deleted
    virtual u32 GetColorElement(u32 idx) const;                                                     // Deleted
    virtual void SetColorElement(u32 idx, u8 c);
    virtual u32 GetVtxColorElement(u32 idx) const;                                                  // Deleted
    virtual void SetVtxColorElement(u32 idx, u8 c);
    virtual u32 GetMaterialNum() const;
    virtual Material* GetMaterial(u32 idx) const;
    virtual Pane* FindPaneByName(const char* name, bool recursive);
    virtual Material* FindMaterialByName(const char* name, bool recursive);
    virtual void Animate(u32 args);
    virtual void AnimateSelf(u32 args);
    virtual void BindAnimation(AnimTransform* animTransform, bool recursive, bool disable);
    virtual void UnbindAnimation(AnimTransform* animTransform, bool recursive);
    virtual void UnbindAllAnimation(bool recursive);                                                // Deleted
    virtual void UnbindAnimationSelf(AnimTransform* animTransform);
    virtual AnimationLink* FindAnimationLinkSelf(AnimTransform* animTransform);                     // Deleted
    virtual AnimationLink* FindAnimationLinkSelf(const AnimResource& animResource);                 // Deleted
    virtual void SetAnimationEnable(AnimTransform* animTransform, bool enable, bool recursive);     // Deleted
    virtual void SetAnimationEnable(const AnimResource& animResource, bool enable, bool recursive); // Deleted
    virtual void CalculateMtx(const DrawInfo& drawInfo);
    virtual void Draw(const DrawInfo& drawInfo);                                                    // Deleted
    virtual void DrawSelf(const DrawInfo& drawInfo);                                                // Deleted
    virtual u32* MakeUniformDataSelf(u32* cmd, DrawInfo* drawInfo, void* drawer) const;
    virtual void LoadMtx(const DrawInfo& drawInfo);                                                 // Deleted

    const ExtUserData* FindExtUserDataByName(const char* name);
    const Vec2f GetVtxPos() const;

public:
    /* 0x0C */  Pane* parent;                   //
    /* 0x10 */  u8 childList[0xC];              // ut::LinkList
    /* 0x1C */  u8 animList[0xC];               // ut::LinkList
    /* 0x28 */  Vec3f translate;                //
    /* 0x34 */  Vec3f rotate;                   //
    /* 0x40 */  Vec2f scale;                    //
    /* 0x48 */  Vec2f size;                     //
    /* 0x50 */  f32 mtx[3][4];                  //
    /* 0x80 */  f32 glbMtx[3][4];               //
    /* 0xB0 */  const void* extUserDataList;    // res::ExtUserDataList*
    /* 0xB4 */  u8 alpha;                       //
    /* 0xB5 */  u8 glbAlpha;                    //
    /* 0xB6 */  u8 basePosition;                //
    /* 0xB7 */  u8 flag;                        // PaneFlag
    /* 0xB8 */  char name[17];                  //
    /* 0xC9 */  char userData[9];               //
};

size_assert(Pane, 0xD4);


// Size: 0xD4
class Bounding : public Pane
{
};

size_assert(Bounding, 0xD4);


// Size: 0x10C
class TextBox : public Pane
{
public:
    // Size: 0x1
    struct Bits
    {
        u8 textAlignment : 2;
        u8 isPTDirty : 1;
    };
    size_assert(Bits, 0x1);

public:
    virtual ~TextBox();

    void* GetRuntimeTypeInfo() const override;
    Color8 GetVtxColor(u32 idx) const override;                                          // Deleted
    void SetVtxColor(u32 idx, Color8 c) override;                                        // Deleted
    u32 GetVtxColorElement(u32 idx) const override;                                      // Deleted
    void SetVtxColorElement(u32 idx, u8 c) override;
    u32 GetMaterialNum() const override;
    Material* GetMaterial(u32 idx) const override;
    void Draw(const DrawInfo& drawInfo) override;                                        // Deleted
    void DrawSelf(const DrawInfo& drawInfo) override;                                    // Deleted
    u32* MakeUniformDataSelf(u32* cmd, DrawInfo* drawInfo, void* drawer) const override;

    virtual void AllocStringBuffer(u16 minLen);
    virtual void FreeStringBuffer();
    virtual u16 SetString(const wchar_t* str, u16 dstIdx = 0);
    virtual u16 SetString(const wchar_t* str, u16 dstIdx, u16 strLen);

public:
    /* 0x0D4 */  wchar_t* textBuf;          //
    /* 0x0D8 */  Color8 textColors[2];      // TextColor
    /* 0x0E0 */  font::Font* font;          //
    /* 0x0E4 */  Size fontSize;             //
    /* 0x0EC */  f32 lineSpace;             //
    /* 0x0F0 */  f32 charSpace;             //
    /* 0x0F4 */  void* tagProcessor;        // TagProcessor*
    /* 0x0F8 */  u16 textBufBytes;          //
    /* 0x0FA */  u16 textLen;               //
    /* 0x0FC */  u8 textPosition;           //
    /* 0x0FD */  Bits bits;                 //
    /* 0x0FE */  u8 _FE[2];                 // padding
    /* 0x100 */  Material* material;        //
    /* 0x104 */  void* dispStringBuf;       // font::DispStringBuffer*
    /* 0x108 */  u8 _108;                   //
    /* 0x109 */  u8 _109[3];                //
};

size_assert(TextBox, 0x10C);


// Size: 0x154
class Picture : public Pane
{
public:
    virtual ~Picture();

    void* GetRuntimeTypeInfo() const override;
    Color8 GetVtxColor(u32 idx) const override;                                          // Deleted
    void SetVtxColor(u32 idx, Color8 c) override;                                        // Deleted
    u32 GetVtxColorElement(u32 idx) const override;                                      // Deleted
    void SetVtxColorElement(u32 idx, u8 c) override;
    u32 GetMaterialNum() const override;
    Material* GetMaterial(u32 idx) const override;
    void Draw(const DrawInfo& drawInfo) override;                                        // Deleted
    void DrawSelf(const DrawInfo& drawInfo) override;                                    // Deleted
    u32* MakeUniformDataSelf(u32* cmd, DrawInfo* drawInfo, void* drawer) const override;

    virtual void Append(const TexMap& texMap); // Deleted

public:
    /* 0x0D2 */  bool isTexCoordInited;         //
    /* 0x0D3 */  u8 _D3;                        // padding
    /* 0x0D4 */  u32 uniformTexCoordNum;        //
    /* 0x0D8 */  Vec4f uniformTexCoords[6];     //
    /* 0x138 */  Material* material;            //
    /* 0x13C */  Color8 vtxColors[4];           //
    /* 0x14C */  u8 texCoordAry[8];             // internal::TexCoordAry
};

size_assert(Picture, 0x154);


// Size: 0x10
struct InflationLRTB
{
    /* 0x0 */  f32 l;       //
    /* 0x4 */  f32 r;       //
    /* 0x8 */  f32 t;       //
    /* 0xC */  f32 b;       //
};

size_assert(InflationLRTB, 0x10);


// Size: 0x10
struct WindowFrameSize
{
    /* 0x0 */  f32 l;       //
    /* 0x4 */  f32 r;       //
    /* 0x8 */  f32 t;       //
    /* 0xC */  f32 b;       //
};

size_assert(WindowFrameSize, 0x10);


// Size: 0x16C
class Window : public Pane
{
public:
    // Size: 0x18
    struct Content
    {
        /* 0x00 */  Color8 vtxColors[4];    //
        /* 0x10 */  u8 texCoordAry[8];      // internal::TexCoordAry
    };
    size_assert(Content, 0x18);

    // Size: 0x8
    struct Frame
    {
        /* 0x0 */  u8 textureFlip;          //
        /* 0x1 */  u8 _1[3];                // padding
        /* 0x4 */  Material* material;      //
    };
    size_assert(Frame, 0x8);

public:
    virtual ~Window();

    void* GetRuntimeTypeInfo() const override;
    Color8 GetVtxColor(u32 idx) const override;                                          // Deleted
    void SetVtxColor(u32 idx, Color8 c) override;                                        // Deleted
    u32 GetVtxColorElement(u32 idx) const override;                                      // Deleted
    void SetVtxColorElement(u32 idx, u8 c) override;
    u32 GetMaterialNum() const override;
    Material* GetMaterial(u32 idx) const override;
    Material* FindMaterialByName(const char* name, bool recursive) override;
    void DrawSelf(const DrawInfo& drawInfo) override;                                    // Deleted
    u32* MakeUniformDataSelf(u32* cmd, DrawInfo* drawInfo, void* drawer) const override;

    virtual void DrawContent(const DrawInfo& drawInfo, const Vec2f& basePt, const WindowFrameSize& frameSize, u8 alpha);                     // Deleted
    virtual void DrawFrame(const DrawInfo& drawInfo, const Vec2f& basePt, const Frame& frame, const WindowFrameSize& frameSize, u8 alpha);   // Deleted
    virtual void DrawFrame4(const DrawInfo& drawInfo, const Vec2f& basePt, const Frame* frames, const WindowFrameSize& frameSize, u8 alpha); // Deleted
    virtual void DrawFrame8(const DrawInfo& drawInfo, const Vec2f& basePt, const Frame* frames, const WindowFrameSize& frameSize, u8 alpha); // Deleted

public:
    /* 0x0D2 */  bool isTexCoordInited;             //
    /* 0x0D3 */  u8 _D3;                            // padding
    /* 0x0D4 */  u32 uniformTexCoordNum;            //
    /* 0x0D8 */  Vec4f uniformTexCoords[6];         //
    /* 0x138 */  InflationLRTB contentInflation;    //
    /* 0x148 */  Content content;                   //
    /* 0x160 */  Frame* frames;                     //
    /* 0x164 */  u8 frameNum;                       //
    /* 0x165 */  u8 _165[3];                        // padding
    /* 0x168 */  Material* material;                //
};

size_assert(Window, 0x16C);


// Size: 0x2C
class Group
{
public:
    virtual ~Group();

public:
    /* 0x04 */  u8 link[0x8];               // ut::LinkListNode
    /* 0x0C */  u8 paneLinkList[0xC];       // ut::LinkList
    /* 0x18 */  char name[17];              //
    /* 0x29 */  u8 userAllocated;           //
    /* 0x2A */  u8 _2A[2];                  // padding
};

size_assert(Group, 0x2C);


// Size: 0xC
class GroupContainer
{
public:
    /* 0x0 */  u8 groupList[0xC];       // ut::LinkList
};

size_assert(GroupContainer, 0xC);


typedef u32 ResType;
typedef const void* FontKey;

// Size: 0x8
class ResourceAccessor
{
protected:
    ResourceAccessor();

public:
    virtual ~ResourceAccessor();

    virtual void* GetResource(ResType resType, const char* name, u32* pSize = nullptr) = 0;
    virtual font::Font* GetFont(const char* name) = 0;
    virtual const TextureInfo GetTexture(const char* name) = 0;

protected:
    virtual const TextureInfo LoadTexture(const char* name);
    virtual font::Font* LoadFont(const char* name);

public:
    /* 0x4 */  u8 _4;       //
    /* 0x5 */  u8 _5[3];    //
};

size_assert(ResourceAccessor, 0x8);


// Size: 0x140
class ArcResourceAccessor : public ResourceAccessor
{
public:
    ArcResourceAccessor();

    void* GetResource(ResType resType, const char* name, u32* pSize = nullptr) override;
    font::Font* GetFont(const char* name) override;
    const TextureInfo GetTexture(const char* name) override;

    FontKey RegistFont(const char* name, font::Font* pFont);
    void UnregistFont(FontKey key);

public:
    /* 0x008 */  u8 arcHandle[0x1C];        // ARCHandle
    /* 0x024 */  void* arcBuf;              //
    /* 0x028 */  u8 fontList[0xC];          // FontContainer
    /* 0x034 */  u8 textureList[0xC];       // TextureContainer
    /* 0x040 */  wchar_t resRootDir[64];    //
    /* 0x0C0 */  wchar_t resNameWork[64];   //
};

size_assert(ArcResourceAccessor, 0x140);


// Size: 0x20
class Layout
{
public:
    Layout();
    virtual ~Layout();

    virtual bool Build(const void* data, ResourceAccessor* resAcc);
    virtual AnimTransform* CreateAnimTransform();
    virtual AnimTransform* CreateAnimTransform(const void* data, ResourceAccessor* resAcc);
    virtual AnimTransform* CreateAnimTransform(const AnimResource& animRes, ResourceAccessor* resAcc);
    virtual void DeleteAnimTransform(AnimTransform* animTransform);                                    // Deleted
    virtual void BindAnimation(AnimTransform* animTrans);                                              // Deleted
    virtual void UnbindAnimation(AnimTransform* animTrans);
    virtual void UnbindAllAnimation();
    virtual bool BindAnimationAuto(const AnimResource& animRes, ResourceAccessor* resAcc);             // Deleted
    virtual void SetAnimationEnable(AnimTransform* animTrans, bool enable);                            // Deleted
    virtual void Animate(u32 args);
    virtual void CalculateMtx(const DrawInfo& drawInfo);
    virtual void Draw(const DrawInfo& drawInfo);                                                       // Deleted
    virtual void SetTagProcessor(void* tagProcessor);                                                  // Deleted
    virtual Pane* BuildPaneObj(s32 type, const void* data, const ResBlockSet& resBlockSet);

public:
    /* 0x04 */  u8 animTransList[0xC];              // ut::LinkList
    /* 0x10 */  Pane* rootPane;                     //
    /* 0x14 */  GroupContainer* groupContainer;     //
    /* 0x18 */  Vec2f layoutSize;                   //
};

size_assert(Layout, 0x20);

} // namespace lyt
} // namespace nw
