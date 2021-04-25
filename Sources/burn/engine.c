#include <kinc/pch.h>
#include <kinc/input/mouse.h>
#include <kinc/input/keyboard.h>
#include <kinc/system.h>
#include <kinc/io/filereader.h>
#include <kinc/log.h>
#include <kinc/window.h>
#include <kinc/graphics4/graphics.h>
#include <kinc/math/matrix.h>
#include <memory.h>

#include "engine.h"
#include "input/keys.h"
#include "debug/log.h"
#include "utils/time.h"
#include "math/random.h"

#define BURN_LOG_MODULE_NAME "Engine"

static burn_engine_window_options_t window_state;
static burn_engine_startup_options_t engine_state;

static void burn_private_engine_gameloop(void) {
	//Internal Kincinerate updates
	{
		burn_internal_time_update(kinc_time());
		burn_internal_keys_time_update(burn_time_dt_adjusted());
	}
	engine_state.update_callback(engine_state.logic_fixed_update_rate);
	engine_state.render_callback(0.0);
	//burn_private_engine_trigger_render
	
	//Interspersed with other random engine stuff?
};

static void burn_private_engine_initialize_keyboard(void) {
	burn_keys_start();
	kinc_keyboard_key_down_callback = &burn_internal_keys_set_key_down;
	kinc_keyboard_key_up_callback = &burn_internal_keys_set_key_up;
}

static void burn_private_engine_initialize_time(void) {
	burn_time_start(kinc_time());
}

static void burn_private_engine_initialize_background_callbacks(void) {
	kinc_set_background_callback(&burn_internal_keys_set_all_up); //allow other people to hook into this?
}

static kinc_window_options_t burn_private_engine_construct_window_options(burn_engine_window_options_t *options) {
	kinc_window_options_t wo;
	wo.title = options->title;
	wo.x = options->position_x;
	wo.y = options->position_y;
	wo.width = options->width;
	wo.height = options->height;
	wo.mode = options->mode;

	int resizable = (options->resizable) ? KINC_WINDOW_FEATURE_RESIZEABLE : 0;
	int minimizable = (options->minimizable) ? KINC_WINDOW_FEATURE_MINIMIZABLE : 0;
	int maximizable = (options->maximizable) ? KINC_WINDOW_FEATURE_MAXIMIZABLE : 0;
	int borderless = (options->borderless_window) ? KINC_WINDOW_FEATURE_BORDERLESS : 0;
	int on_top = (options->always_on_top) ? KINC_WINDOW_FEATURE_ON_TOP : 0;
	
	int features = resizable | minimizable | maximizable | borderless | on_top;

	wo.window_features = features;

	//The following are not relevant to Kincinerate at this time. Leave at defaults.
	wo.display_index = 0;
	wo.visible = true;

	return wo;
}

static kinc_framebuffer_options_t burn_private_engine_construct_framebuffer_options(burn_engine_window_options_t *options) {
	kinc_framebuffer_options_t fbo;
	//We don't care about a lot of the framebuffer settings atm.
	kinc_internal_init_framebuffer_options(&fbo);

	fbo.vertical_sync = options->vertical_synced;

	return fbo;
}

void burn_engine_ignition(burn_engine_window_options_t *window_options, burn_engine_startup_options_t *startup_options) {
	burn_log_info("Kincinerate initializing...");

	kinc_window_options_t wo = burn_private_engine_construct_window_options(window_options);
	kinc_framebuffer_options_t fbo = burn_private_engine_construct_framebuffer_options(window_options);
	kinc_init(wo.title, wo.width, wo.height, &wo, &fbo);

	{
		memcpy(&window_state, window_options, sizeof(*window_options));
		memcpy(&engine_state, startup_options, sizeof(*startup_options));
		kinc_set_update_callback(&burn_private_engine_gameloop);
		burn_private_engine_initialize_keyboard();
		burn_private_engine_initialize_time();
		burn_private_engine_initialize_background_callbacks();
	}

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

