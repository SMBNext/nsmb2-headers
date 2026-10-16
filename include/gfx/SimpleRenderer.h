#pragma once

#include "sead.h"
#include "sead/seadDelegate.h"
#include "sead/gfx/seadTexture.h"
#include "gfx/VertexBuffer.h"

// Size: 0x1278
class SimpleRenderer
{
public:
    enum class RenderLayer : u8
    {
        cOpaque         = 0,
        cTranslucent    = 1,
        cSubtractive    = 2,
        cAdditive       = 3,
    };

    // Address: 0x002F983C
    SimpleRenderer();

    // Address: 0x002F9898
    ~SimpleRenderer();

    // Address: 0x002F8D70
    void drawCircle(const Vec3f& position, u32 numSegments, const sead::Color4f& color, const Vec2f& uvOrigin, const Vec2f& uvDelta, f32 radius, f32 thickness, f32 depth);

    // Address: 0x002F8FC4
    void swapBuffers();

    // Address: 0x002F8FE0
    void draw();

    // Address: 0x002F904C
    void initialize(sead::Heap* heap, const sead::TextureCtr& texture, u32 quadCount);

    // Address: 0x002F9080
    void initialize(sead::Heap* heap, u32 quadCount);

    // Address: 0x002F90AC 
    void drawLine(const Vec3f& startPoint, const Vec3f& endPoint, const sead::Color4f& color, const Vec2f& uvOrigin, const Vec2f& uvDelta, f32 thickness, f32 depth);

    // Address: 0x002F91F4
    void drawQuad(const Vec3f& position, const Vec2f& size, const Vec3i& rotation, const Vec3f& scale, f32 depth);

    // Address: 0x002F9244
    void drawQuad(const Vec3f& position, const Vec2f& size, const Vec2f& uvOrigin, const Vec2f& uvDelta, const Vec3i& rotation, const Vec3f& scale, f32 depth);

    // Address: 0x002F95A0
    void drawQuad(const Vec3f& BL, const Vec3f& BR, const Vec3f& TL, const Vec3f& TR, const Vec2f& uvOrigin, const Vec2f& uvDelta, f32 depth);

    // Address: 0x002F97F0
    void drawQuad(const Vec3f& BL, const Vec3f& BR, const Vec3f& TL, const Vec3f& TR, f32 depth);

    inline void setColor(const sead::Color4f& color)
    {
        mColor = color;
    }

    inline const sead::Color4f& getColor() const
    {
        return mColor;
    }

    inline void setRenderLayer(RenderLayer renderLayer)
    {   
        this->renderLayer = renderLayer;
    }

private:
    // Address: 0x0024BD44
    void renderUnTextured();

    // Address: 0x0024BE78
    void renderTextured();

private:
    sead::Delegate<SimpleRenderer> mRenderDelegate;     //
    VertexBuffer mVertexBuffer;                         //
    sead::Color4f mColor;                               //
    RenderLayer renderLayer;                            //

    friend class sead::Delegate<SimpleRenderer>;
};

size_assert(SimpleRenderer, 0x1278);