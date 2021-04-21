#include <kinc/pch.h>
#include <kinc/system.h>
#include <assert.h>
#include "keys.h"

typedef struct burn_keys_state {
	double down_time[MAX_KEYS];
	double up_time[MAX_KEYS];
	bool is_down[MAX_KEYS];
	int count_of_keys_down;
} burn_keys_state_t;

static burn_keys_state_t state;
static bool initialized;

void burn_keys_start(void) {
	assert(!initialized);

	for (int i = 0; i < MAX_KEYS; i++) {
		double time = kinc_time();
		state.down_time[i] = time;
		state.up_time[i] = time;
		state.is_down[i] = false;
	}

	state.count_of_keys_down = 0;

	initialized = true;
};

bool burn_keys_is_key_down(int keycode) {
	return state.is_down[keycode];
};

bool burn_keys_is_key_up(int keycode) {
	return !state.is_down[keycode];
};

bool burn_keys_is_any_key_down(void) {
	if (state.count_of_keys_down != 0)
		return true;
	else
		return false;
};

bool burn_keys_was_key_just_pressed(int keycode, double threshold) {
	double current_time = state.down_time[keycode];
	return (current_time <= threshold);
};

bool burn_keys_was_key_just_released(int keycode, double threshold) {
	double current_time = state.up_time[keycode];
	return (current_time <= threshold);
};

//TODO: Evaluate if this actually works as I expect, the threshold timing might result in bad behavior?
bool burn_keys_did_key_just_transition(int keycode, double threshold) {
	return (burn_keys_was_key_just_pressed(keycode, threshold) || burn_keys_was_key_just_released(keycode, threshold));
}

bool burn_keys_has_key_been_held_for(int keycode, double threshold) {
	double current_time = state.down_time[keycode];
	return (current_time > threshold);
};

bool burn_keys_has_key_been_released_for(int keycode, double threshold) {
	double current_time = state.up_time[keycode];
	return (current_time > threshold);
};

double burn_keys_key_down_duration(int keycode) {
	return state.down_time[keycode];
};

double burn_keys_key_up_duration(int keycode) {
	return state.up_time[keycode];
};

void burn_internal_keys_time_update(double delta) {
	for (int i = 0; i < MAX_KEYS; i++) {
		if (state.is_down[i])
			state.down_time[i] += delta;
		else
			state.up_time[i] += delta;
	}
};

void burn_internal_keys_set_key_down(int keycode) {
	assert(keycode < MAX_KEYS);
	state.is_down[keycode] = true;
	state.up_time[keycode] = 0.;
	state.count_of_keys_down++; //There's no way you can set a key down twice in a row without setting it up, right?
};

void burn_internal_keys_set_key_up(int keycode) {
	assert(keycode < MAX_KEYS);
	state.is_down[keycode] = false;
	state.down_time[keycode] = 0.;
	state.count_of_keys_down--;
};