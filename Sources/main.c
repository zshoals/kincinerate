#include <kinc/pch.h>
#include <kinc/input/mouse.h>
#include <kinc/input/keyboard.h>
#include <kinc/system.h>
#include <kinc/io/filereader.h>
#include <kinc/log.h>

#include "input/keys.h"

static double last_time;

void render() {
	double delta_time = kinc_time() - last_time;

	burn_internal_keys_time_update(kinc_time()); //this isn't delta time idiot
	//kinc_log(KINC_LOG_LEVEL_ERROR, "%f", kinc_time());
	if (burn_keys_has_key_been_held_for(KINC_KEY_E, 2.)) kinc_internal_shutdown();

	last_time = kinc_time();
}

int kickstart(int argc, char** argv) {

	//This should be loaded from some sort of config file
	kinc_init("Yes", 1024, 768, NULL, NULL);
	kinc_set_update_callback(&render);
	burn_keys_start();
	kinc_keyboard_key_down_callback = &burn_internal_keys_set_key_down;
	kinc_keyboard_key_up_callback = &burn_internal_keys_set_key_up;

	last_time = kinc_time();

	//Start everything once we've loaded what we need and set up appropriate callbacks.
	kinc_start();

	return 0;
}