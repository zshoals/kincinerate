#include <kinc/pch.h>
#include <kinc/input/mouse.h>
#include <kinc/input/keyboard.h>
#include <kinc/system.h>
#include <kinc/io/filereader.h>
#include <kinc/log.h>
#include <kinc/window.h>
#include <kinc/graphics4/graphics.h>
#include <kinc/math/matrix.h>

#include "burn/input/keys.h"
#include "burn/debug/log.h"
#include "burn/utils/time.h"
#include "burn/math/random.h"

static burn_math_random_state_t rng;
static int storage[256];

#define BURN_LOG_MODULE_NAME "Main"

void render() {
	burn_internal_time_update(kinc_time());

	burn_internal_keys_time_update(burn_time_dt_adjusted());
	burn_log_info("\"YES\"%f %s %s %d", burn_keys_key_down_duration(BURN_KEY_E, 2.), "YUP", "HELLO", __LINE__);
	
	if (burn_keys_has_key_been_held_for(BURN_KEY_E, 2.)) kinc_internal_shutdown();

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
	burn_time_start(kinc_time());

	burn_math_random_init(&rng, 57475, 5886, 1000);

	kinc_keyboard_key_down_callback = &burn_internal_keys_set_key_down;
	kinc_keyboard_key_up_callback = &burn_internal_keys_set_key_up;
	kinc_set_background_callback(&burn_internal_keys_set_all_up);


	//Start everything once we've loaded what we need and set up appropriate callbacks.
	//We need to set up our logic before kinc_start, once we're in kinc = RIP I guess
	kinc_start();

	return 0;
}