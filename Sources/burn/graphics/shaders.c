#include "shaders.h"
#include "../utils/common.h"
#include <stdlib.h>
#include <assert.h>
#include <kinc/io/filereader.h>
#include <kinc/graphics4/shader.h>
#include "../io/io.h"

#define BURN_LOG_MODULE_NAME "Shaders"

BURN_COMMON_CREATE_GENERIC_SEARCH_FUNCTION_FOR_HANDLE_IN_STRUCT_ARRAY(burn_shaders_frag_t);
BURN_COMMON_CREATE_GENERIC_SEARCH_FUNCTION_FOR_HANDLE_IN_STRUCT_ARRAY(burn_shaders_vert_t);
BURN_COMMON_CREATE_GENERIC_SEARCH_FUNCTION_FOR_HANDLE_IN_STRUCT_ARRAY(burn_shaders_pipeline_t);

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
	assert((storage->frag_active_slots < MAX_SHADERS) && "Too many fragment shaders added, raise the max or add less");
};

burn_shaders_pipeline_t *burn_shaders_pipeline_create(burn_shaders_storage_t *storage, const char *handle) {
	burn_shaders_pipeline_t *location = &(storage->pipelines[storage->pipelines_active_slots]);
	kinc_g4_pipeline_init(&location->pipeline);
	storage->pipelines_active_slots++;
	strcpy(location->handle, handle);

	return location;
};

void burn_shaders_pipeline_set_depth_configuration(burn_shaders_pipeline_t *pipeline, bool depth_write_enabled, kinc_g4_compare_mode_t depth_mode) {
	pipeline->pipeline.depth_write = depth_write_enabled;
	pipeline->pipeline.depth_mode = depth_mode;
};

//!TODO: bad interface? just look up from storage? Eh :/?
void burn_shaders_pipeline_set_vertex_shader(burn_shaders_pipeline_t *pipeline, burn_shaders_vert_t *shader) {
	pipeline->pipeline.vertex_shader = shader;
};

void burn_shaders_pipeline_set_fragment_shader(burn_shaders_pipeline_t *pipeline, burn_shaders_frag_t *shader) {
	pipeline->pipeline.vertex_shader = shader;
};

void burn_shaders_pipeline_set_blend_mode(burn_shaders_pipeline_t *pipeline, kinc_g4_blending_operation_t source, kinc_g4_blending_operation_t destination) {
	pipeline->pipeline.blend_source = source;
	pipeline->pipeline.blend_destination = destination;
};

void burn_shaders_pipeline_set_alpha_blend_mode(burn_shaders_pipeline_t *pipeline, kinc_g4_blending_operation_t source, kinc_g4_blending_operation_t destination) {
	pipeline->pipeline.alpha_blend_source = source;
	pipeline->pipeline.alpha_blend_destination = destination;
};

void burn_shaders_pipeline_compile(burn_shaders_storage_t *storage, burn_shaders_pipeline_t *pipeline) {

	kinc_g4_pipeline_compile(&pipeline->pipeline);
};

burn_shaders_vert_t *burn_shaders_find_vert_shader(burn_shaders_storage_t *storage, const char *handle) {
	int index = burn_search_handle_in_struct_array_burn_shaders_vert_t(storage->vertex_shaders, handle, storage->vert_active_slots, MAX_SHADERS);

	assert((index != -1) && "Could not find any shader with the provided handle.");

	return &storage->vertex_shaders[index];
};
burn_shaders_frag_t *burn_shaders_find_frag_shader(burn_shaders_storage_t *storage, const char *handle) {
	int index = burn_search_handle_in_struct_array_burn_shaders_frag_t(storage->fragment_shaders, handle, storage->frag_active_slots, MAX_SHADERS);

	assert((index != -1) && "Could not find any shader with the provided handle.");

	return &storage->fragment_shaders[index];
};
burn_shaders_pipeline_t *burn_shaders_find_pipeline(burn_shaders_storage_t *storage, const char *handle) {
	int index = burn_search_handle_in_struct_array_burn_shaders_pipeline_t(storage->pipelines, handle, storage->pipelines_active_slots, MAX_PIPELINES);
	
	assert((index != -1) && "Could not find any pipeline with the provided handle.");

	return &storage->pipelines[index];
};