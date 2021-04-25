#pragma once

#include <stdint.h>

typedef struct burn_math_random_state {
	uint32_t a_seed;
	uint32_t b_seed;
	uint32_t c_seed;
	uint32_t counter;
} burn_math_random_state_t;

void burn_math_random_init(burn_math_random_state_t *rng, uint32_t a, uint32_t b, uint32_t c);
int burn_math_random_get(burn_math_random_state_t *rng);
int burn_math_random_get_range(burn_math_random_state_t *rng, int min, int max);
float burn_math_random_get_float(burn_math_random_state_t *rng);
float burn_math_random_get_float_range(burn_math_random_state_t *rng, float min, float max);

void *burn_math_random_bulk(burn_math_random_state_t *rng, int *data, size_t size);
void *burn_math_random_bulk_range(burn_math_random_state_t *rng, int *data, size_t size, int min, int max);
void *burn_math_random_bulk_float(burn_math_random_state_t *rng, float *data, size_t size);
void *burn_math_random_bulk_float_range(burn_math_random_state_t *rng, float *data, size_t size, float min, float max);


