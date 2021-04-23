//TODO: This is just really redundant now that timer implements all of these directly

#include <kinc/pch.h>
#include <kinc/system.h>
#include "time.h"
#include "timer.h"

static burn_timer_t time;

void burn_time_start(double current_time) {
	burn_timer_init(&time, current_time);
}

double burn_time_now(void) {
	return burn_timer_now(&time);
};

double burn_time_previous(void) {
	return burn_timer_previous(&time);
};

double burn_time_immediate(void) {
	return kinc_time();
}

double burn_time_dt_real(void) {
	return burn_timer_dt_real(&time);
};

double burn_time_dt_timescaled(void) {
	return burn_timer_dt_timescaled(&time);
};

double burn_time_dt_multiplied(void) {
	return burn_timer_dt_multiplied(&time);
};

double burn_time_dt_adjusted(void) {
	return burn_timer_dt_adjusted(&time);
};

void burn_time_set_timescale(double scale) {
	burn_timer_set_timescale(&time, scale);
};

double burn_time_current_timescale(void) {
	return burn_timer_current_timescale(&time);
}

void burn_time_set_multiplier(double scale) {
	burn_timer_set_multiplier(&time, scale);
};

double burn_time_current_multiplier(void) {
	return burn_timer_current_multiplier(&time);
}

void burn_internal_time_update(double current_time) {
	burn_timer_update(&time, current_time);
}