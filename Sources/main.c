#include <kinc/pch.h>
#include <kinc/graphics4/graphics.h>
#include "burn/debug/log.h"
#include "burn/engine.h"
#include "burn/input/keys.h"


#define BURN_LOG_MODULE_NAME "Main"

void update_function(double delta_time) {

}

void render_function(double extrapolation_alpha) {
	if (burn_keys_has_key_been_held_for(BURN_KEY_E, 2.)) kinc_internal_shutdown();

	kinc_g4_begin(0);
	kinc_g4_clear(KINC_G4_CLEAR_COLOR, 0, 0.0f, 0);
	kinc_g4_end(0);
	kinc_g4_swap_buffers(); //While vsynced this stalls this loop since swap buffers synchronizes the frame to the monitor. Keep that in mind.
}

int kickstart(int argc, char** argv) {
	burn_engine_window_options_t window_options;
	burn_engine_startup_options_t startup_options;

	burn_engine_window_options_init(&window_options,
		"First Kincinerate Project",
		-1, -1, 800, 600,
		BURN_WINDOW_MODE_WINDOWED, false, true, 
		true, true, true, false
	);

	burn_engine_startup_options_init(&startup_options,
		(1.0 / 60.0),
		&update_function,
		&render_function
	);

	burn_engine_ignition(&window_options, &startup_options);
	return 0;
}