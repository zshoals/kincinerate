#include "performance.h"
#include "../utils/timer.h"
#include "log.h"
#include "../utils/common.h"

#define BURN_LOG_MODULE_NAME "Performance"

void burn_perf_init(burn_perf_tracker_t *tracker, double current_time) {
	burn_log_info("A performance tracker was initialized at %f seconds", current_time);

	burn_timer_init(&tracker->logic_timer, current_time);
	burn_timer_init(&tracker->render_timer, current_time);

	tracker->framecount = 0;
	
	for (int i = 0; i < BURN_NUMELEMS(tracker->frametimes); ++i) {
		tracker->frametimes[i] = 0.0;
	}
};

void burn_perf_time_update_logic(burn_perf_tracker_t *tracker, double current_time) {
	burn_timer_update(&tracker->logic_timer, current_time);
};

void burn_perf_time_update_render(burn_perf_tracker_t *tracker, double current_time) {
	burn_timer_update(&tracker->render_timer, current_time);
};

void burn_perf_frames_update_framecount(burn_perf_tracker_t *tracker) {
	tracker->framecount++;
};

double burn_perf_time_logic(const burn_perf_tracker_t *tracker) {
	return burn_timer_dt_real(&tracker->logic_timer);
};

double burn_perf_time_render(const burn_perf_tracker_t *tracker) {
	return burn_timer_dt_real(&tracker->render_timer);
};

uint64_t burn_perf_frames_framecount(const burn_perf_tracker_t *tracker) {
	return tracker->framecount;
};

