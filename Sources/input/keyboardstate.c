#include "keyboardstate.h"
#include <kinc/system.h>

static burn_keyboardstate_state_t state;

void burn_keyboardstate_start(void) {
	for (int i = 0; i < MAX_KEYS; i++) {
		double time = kinc_time();
		state.down_time[i] = time;
		state.up_time[i] = time;
		state.is_down[i] = false;
	}
}

bool burn_keyboardstate_is_key_down(int keycode) {
	return state.is_down[keycode];
}

bool burn_keyboardstate_is_key_up(int keycode) {
	return !state.is_down[keycode];
};

bool burn_keyboardstate_was_key_just_pressed(int keycode, double threshold);

bool burn_keyboardstate_was_key_just_released(int keycode, double threshold);

bool burn_keyboardstate_has_key_been_held_for(int keycode, double threshold);

bool burn_keyboardstate_has_key_been_released_for(int keycode, double threshold);

double burn_keyboardstate_key_down_duration(int keycode);

double burn_keyboardstate_key_up_duration(int keycode);

void burn_internal_keyboardstate_time_update(void);

void burn_internal_keyboardstate_set_key_down(int keycode) {
	state.is_down[keycode] = true;
}

void burn_internal_keyboardstate_set_key_up(int keycode) {
	state.is_down[keycode] = false;
}