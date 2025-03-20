#pragma once

#include "nn/math/Types.h"

namespace nn {
namespace ulcd {
namespace CTR {    

class StereoCamera {

public:

    // Address: 0x00163EF0
    StereoCamera();

    ~StereoCamera() {};

    // Address: 0x00163704
    void Initialize(void);

    void SetBaseFrustum(const nn::math::Matrix44 *proj)
    {
        mBaseCamera.near = proj->m[2][3] / proj->m[2][2];
        mBaseCamera.far = proj->m[2][3] / (proj->m[2][2] - 1.0f);

        f32 inverseProjX = proj->m[2][3] / (proj->m[0][0] * proj->m[2][2]);
        f32 inverseProjY = proj->m[2][3] / (proj->m[1][1] * proj->m[2][2]);

        mBaseCamera.left = (proj->m[0][2] - 1.0f) * inverseProjX;
        mBaseCamera.right = (proj->m[0][2] + 1.0f) * inverseProjX;

        mBaseCamera.top = (proj->m[1][2] + 1.0f) * inverseProjY;
        mBaseCamera.bottom = (proj->m[1][2] - 1.0f) * inverseProjY;
    }

    void SetBaseFrustum(const f32 left, const f32 right, const f32 bottom, const f32 top, const f32 near, const f32 far)
    {
        mBaseCamera.left = left;
        mBaseCamera.right = right;

        mBaseCamera.bottom = bottom;
        mBaseCamera.top = top;

        mBaseCamera.near = near;
        mBaseCamera.far = far;
    }

    // Address: 0x001637D4
    void SetBaseCamera(const nn::math::Matrix34 *view);

    void SetBaseCamera(const nn::math::Vector3 *position, const nn::math::Vector3 *rightDir,
                        const nn::math::Vector3 *upDir, const nn::math::Vector3 *targetDir)
    {
        mBaseCamera.position = *position;
        mBaseCamera.rightDir = *rightDir;
        mBaseCamera.upDir = *upDir;
        mBaseCamera.targetDir = *targetDir;
    }

    // Address: 0x00163824
    void SetLimitParallax(const f32 limit);

    // Address: 0x00163854
    void CalculateMatrices(nn::math::Matrix44* projL, nn::math::Matrix34* viewL,
                            nn::math::Matrix44* projR, nn::math::Matrix34* viewR,
                            const f32 depthLevel, const f32 factor,
                            const nn::math::PivotDirection pivot = nn::math::PIVOT_UPSIDE_TO_TOP);
    
    // Address: 0x00163B8C
    void CalculateMatricesReal(nn::math::Matrix44* projL, nn::math::Matrix34* viewL,
                                nn::math::Matrix44* projR, nn::math::Matrix34* viewR,
                                const f32 depthLevel, const f32 factor,
                                const nn::math::PivotDirection pivot = nn::math::PIVOT_UPSIDE_TO_TOP);

    // Address: 0x0048A27C
    f32 GetParallax(const f32 distance) const;

    // Address: 0x0048A2F8
    f32 GetCoefficientForParallax(void) const;

    // Address: 0x0048A2B4
    f32 GetMaxParallax(void) const;

    f32 GetLimitParallax(void) const { return mLimitParallax; }
    f32 GetDistanceToLevel(void) const { return mDepthLevel; }
    f32 GetDistanceToNearClip(void) const { return mDistanceToNearClip; }
    f32 GetDistanceToFarClip(void) const { return mDistanceToFarClip; }

private:

    struct CameraInfo
    {
        f32 left;
        f32 right;
        f32 bottom;
        f32 top;
        f32 near;
        f32 far;

        nn::math::Vector3 position;
        nn::math::Vector3 rightDir;
        nn::math::Vector3 upDir;
        nn::math::Vector3 targetDir;
    };

    CameraInfo mBaseCamera;

    f32 mLimitParallax;

    f32 mLevelWidth;
    f32 mDepthLevel;
    f32 mDistanceToNearClip;
    f32 mDistanceToFarClip;
    f32 mCameraInterval;
};

} // namespace CTR
} // namesapce ulcd
} // namespace nn

size_assert(nn::ulcd::CTR::StereoCamera, 0x60);