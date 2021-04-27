#pragma once

/*
	Attempts to load a file and will crash if the file fails to load. Supply your own memory to write to.

	This does not clear or in any way reset your memory afterwards, so be careful.
*/
size_t burn_io_simple_asset_read(const char *filename, void *scratch_memory);