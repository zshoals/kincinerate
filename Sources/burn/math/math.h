#pragma once

#include <kinc/pch.h>
#include <kinc/math/core.h>

#define KINC_PI 3.141592654
#define KINC_TAU 6.283185307

float burn_math_sin(float value);
float burn_math_cos(float value);
float burn_math_tan(float x);
float burn_math_cot(float x);
float burn_math_round(float value);
float burn_math_ceil(float value);
float burn_math_pow(float value, float exponent);
float burn_math_max_float(void);
float burn_math_sqrt(float value);
float burn_math_abs(float value);
float burn_math_asin(float value);
float burn_math_acos(float value);
float burn_math_atan(float value);
float burn_math_atan2(float y, float x);
float burn_math_floor(float value);
float burn_math_mod(float numer, float denom);
float burn_math_exp(float exponent);
float burn_math_min(float a, float b);
float burn_math_max(float a, float b);
int burn_math_mini(int a, int b);
int burn_math_maxi(int a, int b);
float burn_math_clamp(float value, float minValue, float maxValue);