#include <kinc/pch.h>
#include <kinc/system.h>
#include <assert.h>
#include "../debug/log.h"
#include "keys.h"

#define BURN_LOG_MODULE_NAME "Keys"

//!TODO:
//Figure out how to handle standard typing via events
//We still need to support entering a character name, for instance
//And doing that via checking the down keys is weird I think?

//The answer is an event queue that gets processed by whatever 

//Each array address is the related keycode.
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
	burn_log_info("Kincinerate keyboard state initialized at %f seconds", kinc_time());
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

void burn_keys_disable_input(void) {
	state.enable_input = false;
};

void burn_keys_disable_input_and_set_keys_up(void) {
	burn_keys_disable_input();
	burn_internal_keys_set_all_up();
}

bool burn_keys_is_key_down(int keycode) {
	return state.is_down[keycode];
};

bool burn_keys_is_key_up(int keycode) {
	return !state.is_down[keycode];
};

//!NOTE: Worst case scenario, do a linear scan over the array to check if any key is down.
//Only necessary if the "keys down counter" is not viable in practice.
bool burn_keys_is_any_key_down(void) {
	return (state.count_of_keys_down != 0);
};

bool burn_keys_was_key_just_pressed(int keycode, double threshold) {
	double current_time = state.down_time[keycode];
	return (current_time <= threshold);
};

bool burn_keys_was_key_just_released(int keycode, double threshold) {
	double current_time = state.up_time[keycode];
	return (current_time <= threshold);
};

//!TODO: Evaluate if this actually works as I expect, the threshold timing might result in bad behavior?
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
	
	//Fix for degenerate case of sending a key up event after resetting all keys to up.
	if (state.count_of_keys_down > 0)
		state.count_of_keys_down--;
};

/*
	Necessary due to the fact that input events can be skipped if the program is not in focus.

	Best used with some sort of focus lost callback, or as part of disabling input.
*/
void burn_internal_keys_set_all_up(void) {
	assert(initialized);
	burn_log_info("Window focus lost; all keys set up"); //This kind of shouldn't know that window focus was lost?

	for (int i = 0; i < MAX_KEYS; ++i) {
		burn_internal_keys_set_key_up(i);
	}
}