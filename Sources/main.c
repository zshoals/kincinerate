#include <kinc/pch.h>
#include "burn/debug/log.h"
#include "burn/engine.h"

#define BURN_LOG_MODULE_NAME "Main"

int kickstart(int argc, char** argv) {
	burn_engine_ignition();
	return 0;
}