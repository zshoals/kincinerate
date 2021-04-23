#include <kinc/pch.h>

#include "timer.h"

double burn_timer_init(burn_timer_t *timer, double current_time) {
	timer->now = current_time;
	timer->previous = current_time;
	timer->timescale = 1.0;
	timer->multiplier = 1.0;
};

double burn_timer_update(burn_timer_t *timer, double current_time) {
	timer->previous = timer->now;
	timer->now = current_time;
};

double burn_timer_now(const burn_timer_t *timer) {
	return timer->now;
};

double burn_timer_previous(const burn_timer_t *timer) {
	return timer->previous;
};

double burn_timer_dt_real(const burn_timer_t *timer) {
	return timer->now - timer->previous;
};

double burn_timer_dt_timescaled(const burn_timer_t *timer) {
	return burn_timer_dt_real(timer) * timer->timescale;
};

double burn_timer_dt_multiplied(const burn_timer_t *timer) {
	return burn_timer_dt_real(timer) * timer->multiplier;
};

double burn_timer_dt_adjusted(const burn_timer_t *timer) {
	return burn_timer_dt_real(timer) * timer->timescale * timer->multiplier;
};

void burn_timer_set_timescale(burn_timer_t *timer, double scale) {
	timer->timescale = scale;
};

double burn_timer_current_timescale(const burn_timer_t *timer) {
	return timer->timescale;
};

void burn_timer_set_multiplier(burn_timer_t *timer, double scale) {
	timer->multiplier = scale;
};

double burn_timer_current_multiplier(const burn_timer_t *timer) {
	return timer->multiplier;
};