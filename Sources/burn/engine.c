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

void burn_engine_ignition(burn_engine_window_options_t *window_options, burn_engine_startup_options_t *startup_options) {
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
};

void burn_engine_window_options_init(
burn_engine_window_options_t *options, 
const char *title, 
int position_x, int position_y, int width, int height,
burn_window_mode mode, bool borderless_window, bool vertical_sync,
bool resizable, bool minimizable, bool maximizable, bool always_on_top) {
	options->title = title;
	options->position_x = position_x;
	options->position_y = position_y;
	options->width = width;
	options->height = height;
	options->mode = mode;
	options->borderless_window = borderless_window;
	options->vertical_synced = vertical_sync;
	options->resizable = resizable;
	options->minimizable = minimizable;
	options->maximizable = maximizable;
	options->always_on_top = always_on_top;
};

void burn_engine_startup_options_init(
burn_engine_startup_options_t *options,
double logic_fixed_update_rate,
void (*update_callback)(double delta_time),
void (*render_callback)(double extrapolation_alpha)) {
	options->logic_fixed_update_rate = logic_fixed_update_rate;
	options->update_callback = update_callback;
	options->render_callback = render_callback;
}