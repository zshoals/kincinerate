#include <kinc/pch.h>
#include <kinc/input/mouse.h>
#include <kinc/system.h>
#include <kinc/io/filereader.h>
#include <kinc/log.h>

int kickstart(int argc, char** argv) {

	//This should be loaded from some sort of config file
	kinc_init("Yes", 1024, 768, NULL, NULL);

	//Start everything once we've loaded what we need and set up appropriate callbacks.
	kinc_start();

	return 0;
}