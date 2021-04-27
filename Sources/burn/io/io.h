#pragma once

/*
	Attempts to load a file and will crash if the file fails to load. Supply your own memory to write to.
*/
void burn_io_simple_asset_read(const char *filename, void *scratch_memory);