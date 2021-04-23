#include <kinc/pch.h>
#include <kinc/input/mouse.h>
#include <kinc/input/keyboard.h>
#include <kinc/system.h>
#include <kinc/io/filereader.h>
#include <kinc/log.h>
#include <kinc/window.h>
#include <kinc/graphics4/graphics.h>

#include "burn/input/keys.h"
#include "burn/debug/log.h"

static double last_time;

void render() {
	double delta_time = kinc_time() - last_time;
	last_time = kinc_time(); //This needs positioned immediately after delta calc

	burn_internal_keys_time_update(delta_time);
	burn_log_info("\"YES\"%f %s %s %d", burn_keys_key_down_duration(KINC_KEY_E), "YUP", "HELLO", __LINE__);
	if (burn_keys_has_key_been_held_for(KINC_KEY_E, 2.)) kinc_internal_shutdown();

	kinc_g4_begin(0);
	kinc_g4_clear(KINC_G4_CLEAR_COLOR, 0, 0.0f, 0);
	kinc_g4_end(0);
	kinc_g4_swap_buffers();
}

int kickstart(int argc, char** argv) {
	kinc_framebuffer_options_t fb_options;

	fb_options.vertical_sync = true;

	//This should be loaded from some sort of config file
	kinc_init("Yes", 1024, 768, NULL, NULL);

	//The update callback seems to just run as fast as possible? Unsure what this is linked to, exactly.
	//This isn't the case if kinc_g4_swap_buffers is called
	kinc_set_update_callback(&render);
	burn_keys_start();
	kinc_keyboard_key_down_callback = &burn_internal_keys_set_key_down;
	kinc_keyboard_key_up_callback = &burn_internal_keys_set_key_up;

	last_time = kinc_time();

	//Start everything once we've loaded what we need and set up appropriate callbacks.
	//We need to set up our logic before kinc_start, once we're in kinc = RIP I guess
	kinc_start();

	return 0;
}