#pragma once

#include "gfx/GL.h"
#include "sead.h"
#include "nw/gfx/res/ResTexture.h"

namespace sead {
class TextureCtr
{
    TextureCtr();
    virtual ~TextureCtr();

    virtual void vf8();                 // nulled
    virtual u32 getWidth() = 0;
    virtual u32 getHeight() = 0;
    virtual void* getPhysicalAddr() = 0;
    virtual u32 getFormat() = 0;
    virtual void vf1C() = 0;
};

class TextureCtrGL : public TextureCtr
{
public:
    TextureCtrGL();
    ~TextureCtrGL();

    u32 getWidth() override;
    u32 getHeight() override;
    void* getPhysicalAddr() override;
    u32 getFormat() override;
    void vf1C() override;               // nulled

    void loadFromCtpk(void* ctpkData, const sead::SafeString& identifier, u32 gpuRegion = 0);

    // Address: 0x0045C328
    void loadFromArchive(const sead::SafeString& path, s32 textureId, u32 gpuRegion, sead::Heap* heap);

    inline void cleanup() 
    {
        glDeleteTextures(1, &textureGl);
    }

    u32 width;      // 4
    u32 height;     // 8
    u32 format;     // C
    u32 type;       // 10
    u32 textureGl;  // 14
    u32 mipLevel;   // 18
};

size_assert(TextureCtrGL, 0x1C);

class TextureCtrGR : public TextureCtr
{
public:
    TextureCtrGR();
    ~TextureCtrGR();

    u32 getWidth() override;
    u32 getHeight() override;
    void* getPhysicalAddr() override;
    u32 getFormat() override;
    void vf1C() override;    
    
    void loadFromRes(nw::gfx::res::ResTexture* resTexture);

    u32 width;          // 4
    u32 height;         // 8
    u32 physicalAddr;   // C
    u8 format;          // 10
    u8 maxLodLevel;     // 14
};

size_assert(TextureCtrGR, 0x14);

}
