#pragma once

#include <kinc/pch.h>
#include <kinc/input/keyboard.h>
#include <stdbool.h>

#define MAX_KEYS 256

//Each array address is the related keycode.
typedef struct burn_keys_state burn_keys_state_t;

void burn_keys_start(void);
void burn_keys_enable_input(void);
void burn_keys_disable_input(void);

bool burn_keys_is_key_down(int keycode);
bool burn_keys_is_key_up(int keycode);
bool burn_keys_is_any_key_down(void);
bool burn_keys_was_key_just_pressed(int keycode, double threshold);
bool burn_keys_was_key_just_released(int keycode, double threshold);
bool burn_keys_did_key_just_transition(int keycode, double threshold);
bool burn_keys_has_key_been_held_for(int keycode, double threshold);
bool burn_keys_has_key_been_released_for(int keycode, double threshold);
double burn_keys_key_down_duration(int keycode);
double burn_keys_key_up_duration(int keycode);

void burn_internal_keys_time_update(double delta);
void burn_internal_keys_set_key_down(int keycode);
void burn_internal_keys_set_key_up(int keycode);