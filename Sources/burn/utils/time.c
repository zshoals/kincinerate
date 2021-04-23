#include <kinc/pch.h>
#include "time.h"

typedef struct burn_time {
	double now;
	double previous;
	double timescale;
	double multiplier;
} burn_time_t;

static burn_time_t time;

void burn_time_start(double current_time) {
	time.now = current_time;
	time.previous = current_time;
	time.timescale = 1.;
	time.multiplier = 1.;
}

double burn_time_now(void) {
	return time.now;
};

double burn_time_previous(void) {
	return time.previous;
}

double burn_time_dt_real(void) {
	return time.now - time.previous;
};

double burn_time_dt_timescaled(void) {
	return burn_time_dt_real() * time.timescale;
}

double burn_time_dt_multiplied(void) {
	return burn_time_dt_real() * time.multiplier;
};

double burn_time_dt_adjusted(void) {
	return burn_time_dt_real() * time.multiplier * time.timescale;
};

void burn_time_set_timescale(double scale) {
	time.timescale = scale;
};
void burn_time_set_multiplier(double scale) {
	time.multiplier = scale;
};

void burn_internal_time_update(double current_time) {
	time.previous = time.now;
	time.now = current_time;
}