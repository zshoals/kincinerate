#pragma once

#include <kinc/system.h>
#include <kinc/window.h>
#include <stdbool.h>

typedef enum {
	BURN_WINDOW_MODE_WINDOWED = KINC_WINDOW_MODE_WINDOW,
	BURN_WINDOW_MODE_FULLSCREEN = KINC_WINDOW_MODE_FULLSCREEN,
	BURN_WINDOW_MODE_EXCLUSIVE_FULLSCREEN = KINC_WINDOW_MODE_EXCLUSIVE_FULLSCREEN
} burn_window_mode;

typedef struct burn_engine_window_options {
	const char *title;
	
	int position_x;
	int position_y;
	int width;
	int height;
	int display_index;

	burn_window_mode mode;
	bool borderless_window;
	bool vertical_synced;

	bool resizable;
	bool minimizable;
	bool maximizable;
	bool always_on_top;
	//bool visible; //We don't support this feature
} burn_engine_window_options_t;

typedef struct burn_engine_startup_options {
	//!TODO: Change this to ticks eventually, only compute delta time as a double at the last moment
	double logic_fixed_update_rate; 
	void (*update_callback)(double delta_time);
	void (*render_callback)(double extrapolation_alpha);
} burn_engine_startup_options_t;

void burn_engine_ignition(burn_engine_window_options_t *window_options, burn_engine_startup_options_t *startup_options);

void burn_engine_window_options_init(burn_engine_window_options_t *options,
	const char *title, 
	int position_x, int position_y, int width, int height,
	burn_window_mode mode, bool borderless_window, bool vertical_sync,
	bool resizable, bool minimizable, bool maximizable, bool always_on_top
);

void burn_engine_startup_options_init(burn_engine_startup_options_t *options, 
	double logic_fixed_update_rate,
	void (*update_callback)(double delta_time),
	void (*render_callback)(double extrapolation_alpha)
);