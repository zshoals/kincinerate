#include <kinc/pch.h>
#include <kinc/input/mouse.h>
#include <kinc/input/keyboard.h>
#include <kinc/system.h>
#include <kinc/io/filereader.h>
#include <kinc/log.h>
#include <kinc/window.h>
#include <kinc/graphics4/graphics.h>
#include <kinc/math/matrix.h>

#include "engine.h"
#include "input/keys.h"
#include "debug/log.h"
#include "utils/time.h"
#include "math/random.h"

#define BURN_LOG_MODULE_NAME "Engine"

static burn_math_random_state_t rng;

void render() {
	//PREFER KINC_TICKS over kinc_time for the actual game loop math

	burn_internal_time_update(kinc_time());
	
	burn_internal_keys_time_update(burn_time_dt_adjusted());
	//burn_log_info("\"YES\"%f %s %s %d", burn_keys_key_down_duration(BURN_KEY_E, 2.), "YUP", "HELLO", __LINE__);
	
	if (burn_keys_has_key_been_held_for(BURN_KEY_E, 2.)) kinc_internal_shutdown();

	kinc_g4_begin(0);
	kinc_g4_clear(KINC_G4_CLEAR_COLOR, 0, 0.0f, 0);
	kinc_g4_end(0);
	kinc_g4_swap_buffers(); //While vsynced this stalls this loop since swap buffers synchronizes the frame to the monitor. Keep that in mind.
}

static void burn_private_engine_gameloop(void /*update cb, render cb*/) {
	//burn_private_engine_trigger_update
	//burn_private_engine_trigger_render
	
	//Interspersed with other random engine stuff?
};

void burn_engine_ignition() {
	burn_log_info("Kincinerate initializing...");

	kinc_init("Yes", 1024, 768, NULL, NULL);

	kinc_set_update_callback(&render);
	burn_keys_start();
	burn_time_start(kinc_time());

	burn_math_random_init(&rng, 57475, 5886, 1000);

	kinc_keyboard_key_down_callback = &burn_internal_keys_set_key_down;
	kinc_keyboard_key_up_callback = &burn_internal_keys_set_key_up;
	kinc_set_background_callback(&burn_internal_keys_set_all_up);

	kinc_start();
}