#include "io.h"
#include "../debug/log.h"
#include <kinc/pch.h>
#include <kinc/io/filereader.h>
#include <assert.h>

#define BURN_LOG_MODULE_NAME "File IO"

void burn_io_simple_asset_read(const char *filename, void *scratch_memory) {
	kinc_file_reader_t reader;
	bool success = kinc_file_reader_open(&reader, filename, KINC_FILE_TYPE_ASSET);
	burn_log_warn("Loading asset: %s", filename);
	assert(success && "Couldn't open the named vertex shader. Did you provide the correct filename? Is the shader in the correct directory?");

	size_t size = kinc_file_reader_size(&reader);
	kinc_file_reader_read(&reader, scratch_memory, size);
	kinc_file_reader_close(&reader);
}