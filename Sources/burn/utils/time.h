#pragma once

#include <kinc/pch.h>

/*
	Initializes Kincinerate's time tools. Provide your own time mechanism and make sure it has been initialized.

	This tool is intended to be synchronized with each **logical step**.
*/
void burn_time_start(double current_time);

/*
	The current state of Kincinerate's time since the most recent update.
*/
double burn_time_now(void);
/*
	The state of Kincinerate's time before the current update.
*/
double burn_time_previous(void);
/*
	The actual current time, as accurate as that may be.
*/
double burn_time_immediate(void);
/*
	Unadjusted delta time between successive updates.
*/
double burn_time_dt_real(void);
/*
	Adjusted delta time, modified by a timescale factor.
*/
double burn_time_dt_timescaled(void);
/*
	Adjusted delta time, modified by an arbitrary "result multiplier", which has no implicit meaning.
*/
double burn_time_dt_multiplied(void);
/*
	Adjusted delta time, modified by a timescale factor and a "result multiplier".

	Generally speaking, use this delta time function over the other available options.
*/
double burn_time_dt_adjusted(void);

/*
	A timescale factor that is applied to the time delta.
*/
void burn_time_set_timescale(double scale);

/*
	The current timescale.
*/
double burn_time_current_timescale(void);

/*
	The current arbitrary time multiplier.
*/
double burn_time_current_multiplier(void);

/*
	An arbitrary multiplier factor that is applied to the time delta.
*/
void burn_time_set_multiplier(double scale);

void burn_internal_time_update(double current_time);