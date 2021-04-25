#pragma once

#include <kinc/system.h>
#include <kinc/window.h>
#include <stdbool.h>
kinc_framebuffer_options_t yeha;
kinc_window_options_t wut;

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

	bool resizable;
	bool minimizable;
	bool maximizable;
	bool always_on_top;
	//bool visible; //We don't support this feature
} burn_engine_window_options_t;

//void burn_engine_ignition(void/* Needs like, framebuffer options, window options, update rate, update loop callback (takes dt), render loop callback (takes accum remainder)*/);
void burn_engine_ignition();