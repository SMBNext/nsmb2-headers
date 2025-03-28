#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define M_E		    2.7182818284590452354   // e
#define M_LOG2E	    1.4426950408889634074   // log_2 e
#define M_LOG10E	0.43429448190325182765  // log_10 e
#define M_LN2		0.69314718055994530942  // log_e 2
#define M_LN10		2.30258509299404568402  // log_e 10
#define M_PI		3.14159265358979323846  // pi
#define M_PI_2		1.57079632679489661923  // pi/2
#define M_PI_4		0.78539816339744830962  // pi/4
#define M_1_PI		0.31830988618379067154  // 1/pi
#define M_2_PI		0.63661977236758134308  // 2/pi
#define M_2_SQRTPI  1.12837916709551257390  // 2/sqrt(pi)
#define M_SQRT2	    1.41421356237309504880  // sqrt(2)
#define M_SQRT1_2	0.70710678118654752440  // 1/sqrt(2)

float sinf(float x);
float cosf(float x);
float tanf(float x);
float acosf(float x);
float atan2f(float y, float x);
float fmodf(float x, float d);
float powf(float b, float e);

inline float absf(float x) { return (x >= 0) ? x : -x; }

inline float sqrtf(float x)
{
    float result;
    asm("vsqrt.f32 %0, %1" : "=w" (result) : "w" (x));
    return result;
}

#ifdef __cplusplus
}
#endif
