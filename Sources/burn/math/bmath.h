#pragma once

#include <kinc/pch.h>
#include <kinc/math/core.h>

#define BURN_MATH_PI 3.141592654
#define BURN_MATH_TAU 6.283185307
#define BURN_MATH_EPSILON 0.00000001

//============================
//Custom
float burn_math_line_dist(float x1, float y1, float x2, float y2);
float burn_math_lerp(float a, float b, float ratio);
/**
 * Remaps a number from one range to another. Stolen from HaxeFlixel.
 *
 * @param 	value	The incoming value to be converted
 * @param 	start1 	Lower bound of the value's current range
 * @param 	stop1 	Upper bound of the value's current range
 * @param 	start2  Lower bound of the value's target range
 * @param 	stop2 	Upper bound of the value's target range
 * @return The remapped value
 */
float burn_math_remap(float value, float start1, float stop1, float start2, float stop2);
float burn_math_deg2rad(float degrees);
float burn_math_rad2deg(float radians);
bool burn_math_equalf(float a, float b);
bool burn_math_equalf_custom(float a, float b, float epsilon);
int burn_math_signof(float value);
float burn_math_dotproduct(float x1, float y1, float x2, float y2);

//============================
//All the Kinc ported stuff
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
//============================