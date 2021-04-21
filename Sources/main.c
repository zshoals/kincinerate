#include <kinc/pch.h>
#include <kinc/input/mouse.h>
#include <kinc/input/keyboard.h>
#include <kinc/system.h>
#include <kinc/io/filereader.h>
#include <kinc/log.h>

#include "input/keys.h"

void render() {
	if (burn_keys_is_any_key_down()) kinc_internal_shutdown();
}

int kickstart(int argc, char** argv) {

	//This should be loaded from some sort of config file
	kinc_init("Yes", 1024, 768, NULL, NULL);
	kinc_set_update_callback(&render);
	burn_keys_start();
	kinc_keyboard_key_down_callback = &burn_internal_keys_set_key_down;
	kinc_keyboard_key_up_callback = &burn_internal_keys_set_key_up;

	//Start everything once we've loaded what we need and set up appropriate callbacks.
	kinc_start();

	return 0;
}