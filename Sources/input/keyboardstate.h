#pragma once

#include <kinc/pch.h>
#include <kinc/input/keyboard.h>
#include <stdbool.h>

#define MAX_KEYS 256

//Each array address is the related keycode.
typedef struct burn_keyboardstate_state {
	double down_time[MAX_KEYS];
	double up_time[MAX_KEYS];
	bool is_down[MAX_KEYS];
} burn_keyboardstate_state_t;

void burn_keyboardstate_start(void);

bool burn_keyboardstate_is_key_down(int keycode);
bool burn_keyboardstate_is_key_up(int keycode);
bool burn_keyboardstate_was_key_just_pressed(int keycode, double threshold);
bool burn_keyboardstate_was_key_just_released(int keycode, double threshold);
bool burn_keyboardstate_has_key_been_held_for(int keycode, double threshold);
bool burn_keyboardstate_has_key_been_released_for(int keycode, double threshold);
double burn_keyboardstate_key_down_duration(int keycode);
double burn_keyboardstate_key_up_duration(int keycode);

void burn_internal_keyboardstate_time_update(void);
void burn_internal_keyboardstate_set_key_down(int keycode);
void burn_internal_keyboardstate_set_key_up(int keycode);