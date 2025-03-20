#pragma once

#include "nw/types.h"

namespace nw { namespace ut {

} // namespace nw
} // namespace ut

namespace nw { namespace gfx {

class CalculatedTransform
{
    enum Flag
    {
        FLAG_IS_WORLDMATRIX_CALCULATION_ENABLED = 0x1 << 0,
        FLAG_IS_VALID                           = 0x1 << 1,
        FLAG_IS_IGNORE_TRANSLATE                = 0x1 << 2,
        FLAG_IS_IGNORE_SCALE                    = 0x1 << 3, 
        FLAG_IS_IGNORE_ROTATE                   = 0x1 << 4, 
        FLAG_IS_IDENTITY                        = 0x1 << 5,
        FLAG_IS_ROTATE_TRANSLATE_ZERO           = 0x1 << 6,
        FLAG_IS_ROTATE_ZERO                     = 0x1 << 7,
        FLAG_IS_TRANSLATE_ZERO                  = 0x1 << 8, 
        FLAG_IS_SCALE_ONE                       = 0x1 << 9,
        FLAG_IS_UNIFORM_SCALE                   = 0x1 << 10,
        FLAG_IS_DIRTY                           = 0x1 << 11, 
        FLAG_FORCE_VIEW_CALCULATION_ENABLED     = 0x1 << 12, 
        FLAG_CONVERTED_FOR_BLEND                = 0x1 << 30,

        FLAG_IS_IGNORE_ALL = FLAG_IS_IGNORE_SCALE | FLAG_IS_IGNORE_ROTATE | FLAG_IS_IGNORE_TRANSLATE,
        FLAG_DEFAULT = FLAG_IS_WORLDMATRIX_CALCULATION_ENABLED | FLAG_IS_DIRTY
    };

    // 0x0017A90C
    static const CalculatedTransform& Identity();

public:

    // Inlined
    CalculatedTransform(bit32 flags);

    // Inlined
    CalculatedTransform();

    // TODO: make header for ResBone
    // 0x0017A628
    // void Setup(const ResBone bone);

    // Inlined
    math::MTX34& DirectTransformMatrix() { return this->m_TransformMatrix; }

    // Inlined
    const math::MTX34& TransformMatrix() const { return this->m_TransformMatrix; }

    // Inlined
    void SetTransformMatrix(const math::MTX34& transformMatrix)
    {
        math::MTX34::copy(&m_TransformMatrix, &transformMatrix);
        m_Flags |= CalculatedTransform::FLAG_IS_DIRTY;
    }

    // Inlined
    void SetTransformMatrix(
        f32 x00, f32 x01, f32 x02, f32 x03,
        f32 x10, f32 x11, f32 x12, f32 x13,
        f32 x20, f32 x21, f32 x22, f32 x23)
    {
        m_TransformMatrix.rows[0][0] = x00;
        m_TransformMatrix.rows[1][0] = x10;
        m_TransformMatrix.rows[2][0] = x20;
        m_TransformMatrix.rows[0][1] = x01;
        m_TransformMatrix.rows[1][1] = x11;
        m_TransformMatrix.rows[2][1] = x21;
        m_TransformMatrix.rows[0][2] = x02;
        m_TransformMatrix.rows[1][2] = x12;
        m_TransformMatrix.rows[2][2] = x22;
        m_TransformMatrix.rows[0][3] = x03;
        m_TransformMatrix.rows[1][3] = x13;
        m_TransformMatrix.rows[2][3] = x23;

        m_Flags |= CalculatedTransform::FLAG_IS_DIRTY;
    }

    // Inlined
    void SetRotateMatrix(
        f32 x00, f32 x01, f32 x02,
        f32 x10, f32 x11, f32 x12,
        f32 x20, f32 x21, f32 x22)
    {
        m_TransformMatrix.rows[0][0] = x00;
        m_TransformMatrix.rows[1][0] = x10;
        m_TransformMatrix.rows[2][0] = x20;
        m_TransformMatrix.rows[0][1] = x01;
        m_TransformMatrix.rows[1][1] = x11;
        m_TransformMatrix.rows[2][1] = x21;
        m_TransformMatrix.rows[0][2] = x02;
        m_TransformMatrix.rows[1][2] = x12;
        m_TransformMatrix.rows[2][2] = x22;

        m_Flags |= CalculatedTransform::FLAG_IS_DIRTY;
    }

    // Inlined
    math::VEC3& DirectScale() { return m_Scale; }

    // Inlined
    const math::VEC3& Scale() const { return m_Scale; }

    // Inlined
    void SetScale(const math::VEC3& scale)
    {
        m_Scale = scale;
        m_Flags |= CalculatedTransform::FLAG_IS_DIRTY;
    }

    // Inlined
    void SetScale(f32 x, f32 y, f32 z)
    {
        m_Scale.set(x, y, z);
        m_Flags |= CalculatedTransform::FLAG_IS_DIRTY;
    }

    // Inlined
    void SetTranslate(f32 x, f32 y, f32 z)
    {
        m_TransformMatrix.setTranslation(x, y, z);
        m_Flags |= CalculatedTransform::FLAG_IS_DIRTY;
    }

    // Inlined
    void SetTranslate(const math::VEC3& translate)
    {
        SetTranslate(translate.x, translate.y, translate.z);
    }

    // Inlined
    void GetTranslate(math::VEC3* translate) const
    {
        translate->x = m_TransformMatrix.rows[0][3];
        translate->y = m_TransformMatrix.rows[1][3];
        translate->z = m_TransformMatrix.rows[2][3];
    }

    // Inlined
    math::VEC3 GetTranslate() const
    {
        return math::VEC3(
            m_TransformMatrix.rows[0][3],
            m_TransformMatrix.rows[1][3],
            m_TransformMatrix.rows[2][3]);
    }

    // Inlined
    void SetRotateXYZ(f32 x, f32 y, f32 z)
    {
        math::VEC3 translate;
        GetTranslate(&translate);
        m_TransformMatrix.rotate(x, y, z);
        SetTranslate(translate);
    }

    // 0x0017A034
    void SetTransform(const math::Transform3& transform);

    // 0x00179CF4
    void UpdateFlags();

    // 0x0017A26C
    void UpdateRotateFlags();

    // 0x0017A3A4
    void UpdateTranslateFlags();

    // 0x0017A370
    void UpdateCompositeFlags();

private:
    math::MTX34 m_TransformMatrix;
    math::VEC3 m_Scale;
    u32 m_Flags;
};

} // namespace gfx
} // namespace nw


