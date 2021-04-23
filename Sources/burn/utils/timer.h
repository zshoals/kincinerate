#pragma once

#include <kinc/pch.h>

typedef struct burn_timer {
	double now;
	double previous;
	double timescale;
	double multiplier;
} burn_timer_t;

double burn_timer_init(burn_timer_t *timer);

double burn_timer_update(burn_timer_t *timer, double current_time);

/*
	The current state of Kincinerate's time since the most recent update.
*/
double burn_timer_now(burn_timer_t *timer);
/*
	The state of Kincinerate's time before the current update.
*/
double burn_timer_previous(burn_timer_t *timer);
/*
	The actual current time, as accurate as that may be.
*/
double burn_timer_immediate(burn_timer_t *timer);
/*
	Unadjusted delta time between successive updates.
*/
double burn_timer_dt_real(burn_timer_t *timer);
/*
	Adjusted delta time, modified by a timescale factor.
*/
double burn_timer_dt_timescaled(burn_timer_t *timer);
/*
	Adjusted delta time, modified by an arbitrary "result multiplier", which has no implicit meaning.
*/
double burn_timer_dt_multiplied(burn_timer_t *timer);
/*
	Adjusted delta time, modified by a timescale factor and a "result multiplier".

	Generally speaking, use this delta time function over the other available options.
*/
double burn_timer_dt_adjusted(burn_timer_t *timer);

/*
	A timescale factor that is applied to the time delta.
*/
void burn_timer_set_timescale(burn_timer_t *timer, double scale);

/*
	The current timescale.
*/
double burn_timer_current_timescale(burn_timer_t *timer);

/*
	The current arbitrary time multiplier.
*/
double burn_timer_current_multiplier(burn_timer_t *timer);

/*
	An arbitrary multiplier factor that is applied to the time delta.
*/
void burn_timer_set_multiplier(burn_timer_t *timer, double scale);
