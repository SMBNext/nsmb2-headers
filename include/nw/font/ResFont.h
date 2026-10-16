#pragma once

#include "types.h"

namespace nw {
namespace font {

struct Glyph;

typedef u16 CharCode;
typedef u16 TexFmt;

enum CharacterCode
{
    CHARACTER_CODE_UNICODE = 0x1,
    CHARACTER_CODE_SJIS    = 0x2,
    CHARACTER_CODE_CP1252  = 0x3,
    CHARACTER_CODE_MAX     = 0x4
};

// Size: 0x3
struct CharWidths
{
    /* 0x0 */  s8 left;         //
    /* 0x1 */  u8 glyphWidth;   //
    /* 0x2 */  s8 charWidth;    //
};

size_assert(CharWidths, 0x3);


// Size: 0x4
class Font
{
public:
    enum Type
    {
        TYPE_NULL     = 0x0,
        TYPE_ROM      = 0x1,
        TYPE_RESOURCE = 0x2,
        TYPE_PAIR     = 0x3
    };

public:
    virtual ~Font();

    virtual s32 GetWidth() const = 0;
    virtual s32 GetHeight() const = 0;
    virtual s32 GetAscent() const = 0;
    virtual s32 GetDescent() const = 0;
    virtual s32 GetMaxCharWidth() const = 0;
    virtual Type GetType() const = 0;
    virtual TexFmt GetTextureFormat() const = 0;
    virtual s32 GetLineFeed() const = 0;
    virtual const CharWidths GetDefaultCharWidths() const = 0;
    virtual void SetLineFeed(s32 linefeed) = 0;
    virtual void SetDefaultCharWidths(const CharWidths& widths) = 0;
    virtual bool SetAlternateChar(CharCode c) = 0;
    virtual s32 GetCharWidth(CharCode c) const = 0;
    virtual const CharWidths GetCharWidths(CharCode c) const = 0;
    virtual void GetGlyph(Glyph* pGlyph, CharCode c) const = 0;
    virtual bool HasGlyph(CharCode c) const = 0;
    virtual CharacterCode GetCharacterCode() const = 0;
    virtual s32 GetBaselinePos() const = 0;
    virtual s32 GetCellHeight() const = 0;
    virtual s32 GetCellWidth() const = 0;
    virtual void EnableLinearFilter(bool atSmall, bool atLarge) = 0;
    virtual bool IsLinearFilterEnableAtSmall() const = 0;
    virtual bool IsLinearFilterEnableAtLarge() const = 0;
    virtual u32 GetTextureWrapFilterValue() const = 0;
};

size_assert(Font, 0x4);


// Size: 0x18
class ResFontBase : public Font
{
public:
    typedef u16 GlyphIndex;

public:
    ResFontBase();
    virtual ~ResFontBase();

    s32 GetWidth() const override;
    s32 GetHeight() const override;
    s32 GetAscent() const override;
    s32 GetDescent() const override;                              // Deleted
    s32 GetMaxCharWidth() const override;                         // Deleted
    Type GetType() const override;                                // Deleted
    TexFmt GetTextureFormat() const override;                     // Deleted
    s32 GetLineFeed() const override;
    const CharWidths GetDefaultCharWidths() const override;       // Deleted
    void SetLineFeed(s32 linefeed) override;                      // Deleted
    void SetDefaultCharWidths(const CharWidths& widths) override; // Deleted
    bool SetAlternateChar(CharCode c) override;
    s32 GetCharWidth(CharCode c) const override;
    const CharWidths GetCharWidths(CharCode c) const override;
    void GetGlyph(Glyph* pGlyph, CharCode c) const override;
    bool HasGlyph(CharCode c) const override;                     // Deleted
    CharacterCode GetCharacterCode() const override;
    s32 GetBaselinePos() const override;
    s32 GetCellHeight() const override;                           // Deleted
    s32 GetCellWidth() const override;                            // Deleted
    void EnableLinearFilter(bool atSmall, bool atLarge) override; // Deleted
    bool IsLinearFilterEnableAtSmall() const override;
    bool IsLinearFilterEnableAtLarge() const override;
    u32 GetTextureWrapFilterValue() const override;

protected:
    virtual s32 GetActiveSheetNum() const;

public:
    /* 0x04 */  void* resource;             //
    /* 0x08 */  void* fontInfo;             // FontInformation*
    /* 0x0C */  void* texObjs;              // internal::TextureObject*
    /* 0x10 */  u32 wrapFilter;             //
    /* 0x14 */  CharCode lastCharCode;      //
    /* 0x16 */  GlyphIndex lastGlyphIndex;  //
};

size_assert(ResFontBase, 0x18);


// Size: 0x18
class ResFont : public ResFontBase
{
public:
    ResFont();
    virtual ~ResFont();

    bool SetResource(void* bfnt);
    void* SetDrawBuffer(void* buffer);

    static u32 GetDrawBufferSize(const void* bfnt);
};

size_assert(ResFont, 0x18);

} // namespace font
} // namespace nw
