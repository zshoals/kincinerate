#include "shaders.h"
#include "../utils/common.h"
#include <stdlib.h>
#include <assert.h>
#include <kinc/io/filereader.h>
#include <kinc/graphics4/shader.h>
#include "../io/io.h"

#define BURN_LOG_MODULE_NAME "Shaders"

void burn_shaders_init(burn_shaders_storage_t *storage, size_t temp_memory_size) {
	storage->frag_active_slots = 0;
	storage->vert_active_slots = 0;
	storage->pipelines_active_slots = 0;

	storage->scratch_memory = malloc(temp_memory_size);
};
//If you're done loading shaders, you don't need the storage anymore
void burn_shaders_free_temp_storage(burn_shaders_storage_t *storage) {
	free(storage->scratch_memory);
	storage->scratch_memory = NULL;
};


void burn_shaders_load_and_store_vert_shader(burn_shaders_storage_t *storage, const char *filename, const char *new_handle) {
	size_t size = burn_io_simple_asset_read(filename, storage->scratch_memory);
	kinc_g4_shader_init(storage->vertex_shaders[storage->vert_active_slots].shader, storage->scratch_memory, size, KINC_G4_SHADER_TYPE_VERTEX);
	strcpy(storage->vertex_shaders[storage->vert_active_slots].handle, new_handle);

	storage->vert_active_slots++;
	assert((storage->vert_active_slots < MAX_SHADERS) && "Too many vertex shaders added, raise the max or add less");
};

void burn_shaders_load_and_store_frag_shader(burn_shaders_storage_t *storage, const char *filename, const char *new_handle) {
	size_t size = burn_io_simple_asset_read(filename, storage->scratch_memory);
	kinc_g4_shader_init(storage->fragment_shaders[storage->frag_active_slots].shader, storage->scratch_memory, size, KINC_G4_SHADER_TYPE_FRAGMENT);
	strcpy(storage->fragment_shaders[storage->frag_active_slots].handle, new_handle);

	storage->frag_active_slots++;
	assert((storage->frag_active_slots < MAX_SHADERS) && "Too many vertex shaders added, raise the max or add less");
};

burn_shaders_vert_t *burn_shaders_find_vert_shader(burn_shaders_storage_t *storage, const char *handle) {
	int index;
	BURN_SEARCH_HANDLE_IN_STRUCT_ARRAY(index, handle, storage->vert_active_slots, storage->vertex_shaders, MAX_SHADERS);
	
	assert((index != -1) && "Could not find any shader with the provided handle.");

	return &storage->vertex_shaders[index];
};
burn_shaders_frag_t *burn_shaders_find_frag_shader(burn_shaders_storage_t *storage, const char *handle) {
	int index;
	BURN_SEARCH_HANDLE_IN_STRUCT_ARRAY(index, handle, storage->frag_active_slots, storage->fragment_shaders, MAX_SHADERS);

	assert((index != -1) && "Could not find any shader with the provided handle.");

	return &storage->fragment_shaders[index];
};
burn_shaders_pipeline_t *burn_shaders_find_pipeline(burn_shaders_storage_t *storage, const char *handle) {
	int index;
	BURN_SEARCH_HANDLE_IN_STRUCT_ARRAY(index, handle, storage->pipelines_active_slots, storage->pipelines, MAX_PIPELINES);

	assert((index != -1) && "Could not find any pipeline with the provided handle.");

	return &storage->pipelines[index];
};