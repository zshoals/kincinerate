#pragma once

#include <stdint.h>
#include "../utils/timer.h"

typedef struct burn_perf_tracker {
	float frametimes[16]; //First queue data structure incoming? Ringbuffer?
	burn_timer_t logic_timer;
	burn_timer_t render_timer;
	uint64_t framecount;
} burn_perf_tracker_t;

void burn_perf_init(burn_perf_tracker_t *tracker, double current_time);
void burn_perf_time_update_logic(burn_perf_tracker_t *tracker, double current_time);
void burn_perf_time_update_render(burn_perf_tracker_t *tracker, double current_time);
void burn_perf_frames_update_framecount(burn_perf_tracker_t *tracker);
//We need a queue structure!
//void burn_perf_frames_push_frametime(burn_perf_tracker_t *tracker);
double burn_perf_time_logic(const burn_perf_tracker_t *tracker);
double burn_perf_time_render(const burn_perf_tracker_t *tracker);
uint64_t burn_perf_frames_framecount(const burn_perf_tracker_t *tracker);
//double burn_perf_frames_average_frametime(burn_perf_tracker_t *tracker); not in yet