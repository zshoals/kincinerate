#include <kinc/pch.h>
#include <math.h>
#include <memory.h>
#include "random.h"
#include "bmath.h"

void burn_math_random_init(burn_math_random_state_t *rng, uint32_t a, uint32_t b, uint32_t c) {
	rng->a_seed = a;
	rng->b_seed = b;
	rng->c_seed = c;
	rng->counter = 1;
};

int burn_math_random_get(burn_math_random_state_t *rng) {
	enum {BARREL_SHIFT = 25, RSHIFT = 8, LSHIFT = 3};
	uint32_t tmp = rng->a_seed + rng->b_seed + rng->counter++;
	rng->a_seed = rng->b_seed ^ (rng->b_seed >> RSHIFT);
	rng->b_seed = rng->c_seed + (rng->c_seed << LSHIFT);
	rng->c_seed = ((rng->c_seed << BARREL_SHIFT) | (rng->c_seed >> (32-BARREL_SHIFT))) + tmp;
	return (int)(tmp & 0x7fffffff);
};

int burn_math_random_get_range(burn_math_random_state_t *rng, int min, int max) {
	return burn_math_random_get(rng) % (max + 1 - min) + min;
};

float burn_math_random_get_float(burn_math_random_state_t *rng) {
	return burn_math_random_get(rng) / (float)0x7fffffff;
};

float burn_math_random_get_float_range(burn_math_random_state_t *rng, float min, float max) {
	return min + burn_math_random_get_float(rng) * (max - min);
};

void *burn_math_random_bulk(burn_math_random_state_t *rng, int *data, size_t size) {
	for (int i = 0; i < size; i++) {
		data[i] = burn_math_random_get(rng);
	}
};

void *burn_math_random_bulk_range(burn_math_random_state_t *rng, int *data, size_t size, int min, int max) {
	for (int i = 0; i < size; i++) {
		data[i] = burn_math_random_get_range(rng, min, max);
	}
};

void *burn_math_random_bulk_float(burn_math_random_state_t *rng, float *data, size_t size) {
	for (int i = 0; i < size; i++) {
		data[i] = burn_math_random_get_float(rng);
	}
};

void *burn_math_random_bulk_float_range(burn_math_random_state_t *rng, float *data, size_t size, float min, float max) {
	for (int i = 0; i < size; i++) {
		data[i] = burn_math_random_get_float_range(rng, min, max);
	}
};