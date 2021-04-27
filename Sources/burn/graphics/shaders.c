#include "shaders.h"
#include "../utils/common.h"
#include <stdlib.h>
#include <assert.h>

#define BURN_LOG_MODULE_NAME "Shaders"

void burn_shaders_init(burn_shaders_storage_t *storage, size_t temp_memory_size) {
	storage->frag_active_slots = 0;
	storage->vert_active_slots = 0;
	storage->pipelines_active_slots = 0;

	storage->memory_slab = malloc(temp_memory_size);
};
//If you're done loading shaders, you don't need the storage anymore
void burn_shaders_free_temp_storage(burn_shaders_storage_t *storage) {
	free(storage->memory_slab);
	storage->memory_slab = NULL;
};
//Bool for returning if the file failed to be loaded, in which case the process is aborted.
bool burn_shaders_load_and_store_vert_shader(burn_shaders_storage_t *storage, const char *filename, const char *new_handle);
bool burn_shaders_load_and_store_frag_shader(burn_shaders_storage_t *storage, const char *filename, const char *new_handle);
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