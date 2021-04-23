#include <kinc/pch.h>
#include <kinc/log.h>
#include <string.h>

#include "log.h"

//TODO: Actually change how output strings are handled with some sort of tag
//like [INFO], [WARN], [ERROR] etc.
void burn_internal_log_info(const char *format, ...) {
	va_list args;
	va_start(args, format);
	kinc_log_args(KINC_LOG_LEVEL_INFO, format, args);
	va_end(args);
};
void burn_internal_log_warn(const char *format, ...) {
	va_list args;
	va_start(args, format);
	kinc_log_args(KINC_LOG_LEVEL_WARNING, format, args);
	va_end(args);
};
void burn_internal_log_error(const char *format, ...) {
	va_list args;
	va_start(args, format);
	kinc_log_args(KINC_LOG_LEVEL_ERROR, format, args);
	va_end(args);
};