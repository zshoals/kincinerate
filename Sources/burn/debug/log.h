#pragma once

//This is probably a bad sign
//Strings already suck in C :)))))))
#ifndef BURN_LOGGING_DISABLED
	#define burn_log_info(format, ...) burn_internal_log_info("[INFO] " format, __VA_ARGS__)
	#define burn_log_warn(format, ...) burn_internal_log_warn("[WARNING] " format, __VA_ARGS__)
	#define burn_log_error(format, ...) burn_internal_log_error("[ERROR] " format, __VA_ARGS__)
#else
	#define burn_log_info(format, ...)
	#define burn_log_warn(format, ...)
	#define burn_log_error(format, ...)
#endif

void burn_internal_log_info(const char *format, ...);
void burn_internal_log_warn(const char *format, ...);
void burn_internal_log_error(const char *format, ...);