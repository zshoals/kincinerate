#include <kinc/pch.h>
#include <kinc/system.h>
#include <assert.h>
#include <kinc/log.h>
#include "keys.h"

//TODO:
//Figure out how to handle standard typing via events
//We still need to support entering a character name, for instance
//And doing that via checking the down keys is weird I think?

typedef struct burn_keys_state {
	double down_time[MAX_KEYS];
	double up_time[MAX_KEYS];
	bool is_down[MAX_KEYS];
	int count_of_keys_down;
	bool enable_input;
} burn_keys_state_t;

static burn_keys_state_t state;
static bool initialized;

void burn_keys_start(void) {
	assert(!initialized);

	for (int i = 0; i < MAX_KEYS; i++) {
		state.down_time[i] = 0.;
		state.up_time[i] = 0.;
		state.is_down[i] = false;
	}

	state.count_of_keys_down = 0;
	state.enable_input = true;

	initialized = true;
};

void burn_keys_enable_input(void) {
	state.enable_input = true;
};

//TODO: Consider clearing all active inputs too?
void burn_keys_disable_input(void) {
	state.enable_input = false;
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
	kinc_log(KINC_LOG_LEVEL_ERROR, "%f", state.down_time[keycode]);
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

//TODO: Make sure that the value passed in here is the actual delta time and not kinc_time raw
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
	assert(initialized);

	if (!state.enable_input) 
		return;

	state.is_down[keycode] = true;
	state.up_time[keycode] = 0.;
	state.count_of_keys_down++; //There's no way you can set a key down twice in a row without setting it up, right?
};

void burn_internal_keys_set_key_up(int keycode) {
	assert(keycode < MAX_KEYS);
	assert(initialized);

	if (!state.enable_input)
		return;

	state.is_down[keycode] = false;
	state.down_time[keycode] = 0.;
	state.count_of_keys_down--;
};