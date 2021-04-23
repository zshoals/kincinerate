#include <kinc/pch.h>
#include <kinc/math/core.h>

#include "math.h"

float burn_math_linedist(float x1, float y1, float x2, float y2) {
	float dx = x2 - x1;
	float dy = y2 - y1;
	return burn_math_sqrt(burn_math_pow(dx, 2) + burn_math_pow(dy, 2));
};

float burn_math_lerp(float a, float b, float ratio) {
	return a + ratio * (b - a);
};

float burn_math_remap(float value, float start1, float stop1, float start2, float stop2) {
	return start2 + (value - start1) * ((stop2 - start2) / (stop1 - start1));
};

float burn_math_deg2rad(float degrees) {
	return degrees * BURN_MATH_PI / 180;
};

float burn_math_rad2deg(float radians) {
	return radians * 180 / BURN_MATH_PI;
};

float burn_math_dotproduct(float x1, float y1, float x2, float y2) {
	return (x1 * x2) + (y1 * y2);
};

bool burn_math_equalf(float a, float b) {
	return burn_math_abs(a - b) <= BURN_MATH_EPSILON;
};

bool burn_math_equalf_custom(float a, float b, float epsilon) {
	return burn_math_abs(a - b) <= epsilon;
};

int burn_math_signof(float value) {
	return (value < 0) ? -1 : 1;
}
//============================
//============================
//============================
//Kinc Ported Stuff Below This Point
float burn_math_tan(float x) {
	return kinc_tanf(x);
};

float burn_math_cot(float x) {
	return kinc_cot(x);
};

float burn_math_sin(float value) {
	return kinc_sin(value);
};

float burn_math_cos(float value) {
	return kinc_cos(value);
};

float burn_math_round(float value) {
	return kinc_round(value);
};

float burn_math_ceil(float value) {
	return kinc_ceil(value);
};

float burn_math_pow(float value, float exponent) {
	return kinc_pow(value, exponent);
};

float burn_math_max_float(void) {
	return kinc_max_float();
};

float burn_math_sqrt(float value) {
	return kinc_sqrt(value);
};

float burn_math_abs(float value) {
	return kinc_abs(value);
};

float burn_math_asin(float value) {
	return kinc_asin(value);
};

float burn_math_acos(float value) {
	return kinc_acos(value);
};

float burn_math_atan(float value) {
	return kinc_atan(value);
};

float burn_math_atan2(float y, float x) {
	return kinc_atan2(y, x);
};

float burn_math_floor(float value) {
	return kinc_floor(value);
};

float burn_math_mod(float numer, float denom) {
	return kinc_mod(numer, denom);
};

float burn_math_exp(float exponent) {
	return kinc_exp(exponent);
};

float burn_math_min(float a, float b) {
	return kinc_min(a, b);
};

float burn_math_max(float a, float b) {
	return kinc_max(a, b);
};

int burn_math_mini(int a, int b) {
	return kinc_mini(a, b);
};

int burn_math_maxi(int a, int b) {
	return kinc_maxi(a, b);
};

float burn_math_clamp(float value, float minValue, float maxValue) {
	return kinc_clamp(value, minValue, maxValue);
};