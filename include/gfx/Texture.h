#pragma once

#include "sead.h"
#include "gfx/GL.h"
#include "nw/gfx/res/ResTexture.h"


class TextureBase
{
    TextureBase();
    virtual ~TextureBase();

    virtual void vf8();                 // nulled
    virtual u32 getWidth() = 0;
    virtual u32 getHeight() = 0;
    virtual void* getPhysicalAddr() = 0;
    virtual u32 getFormat() = 0;
    virtual void vf1C() = 0;
};

class CtpkTexture : public TextureBase
{
public:
    CtpkTexture();
    ~CtpkTexture();

    u32 getWidth() override;
    u32 getHeight() override;
    void* getPhysicalAddr() override;
    u32 getFormat() override;
    void vf1C() override;               // nulled

    void loadFromCtpk(void* ctpkData, const sead::SafeString& identifier, u32 gpuRegion = 0);

    void loadFromRes(nw::gfx::res::ResTexture* resTexture);

    // Address: 0x0045C328
    void loadFromArchive(const sead::SafeString& path, s32 textureId, u32 gpuRegion, sead::Heap* heap);

    inline void cleanup() {
        glDeleteTextures(1, &textureGl);
    }

    u32 width;      // 4
    u32 height;     // 8
    u32 format;     // C
    u32 type;       // 10
    u32 textureGl;  // 14
    u32 mipLevel;   // 18
};
