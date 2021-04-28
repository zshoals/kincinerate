#pragma once

#include <kinc/graphics4/shader.h>
#include <kinc/graphics4/pipeline.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_SHADERS 32
#define MAX_PIPELINES 32
#define MAX_CONSTANTS 16
#define MAX_HANDLE_SIZE 128

typedef struct burn_shaders_shader {
	char handle[MAX_HANDLE_SIZE];
	kinc_g4_shader_t *shader;
} burn_shaders_frag_t, burn_shaders_vert_t;

typedef struct burn_shaders_constant_location {
	char handle[MAX_HANDLE_SIZE];
	kinc_g4_constant_location_t location;
} burn_shaders_constant_location_t;

typedef struct burn_texture_unit {
	char handle[MAX_HANDLE_SIZE];
	kinc_g4_texture_impl_t texture_unit;
} burn_shaders_texture_unit_t;

typedef struct burn_shaders_pipeline {
	char handle[MAX_HANDLE_SIZE];
	//burn_shaders_constant_location_t constant_locations[16];
	//burn_shaders_texture_unit_t texture_unit[8];
	kinc_g4_pipeline_t *pipeline;
} burn_shaders_pipeline_t;

typedef struct burn_shaders_storage {
	burn_shaders_pipeline_t pipelines[MAX_PIPELINES];
	burn_shaders_frag_t fragment_shaders[MAX_SHADERS];
	burn_shaders_vert_t vertex_shaders[MAX_SHADERS];
	uint8_t *scratch_memory;
	uint8_t frag_active_slots;
	uint8_t vert_active_slots;
	uint8_t pipelines_active_slots;
} burn_shaders_storage_t;

//Allocate a heap for temporarily holding shader data before a shader is constructed
void burn_shaders_init(burn_shaders_storage_t *storage, size_t temp_memory_size);
/*
	If you're done loading shaders, you don't need the storage anymore

	Note that this cannot be undone.
*/
void burn_shaders_free_temp_storage(burn_shaders_storage_t *storage);
//Bool for returning if the file failed to be loaded, in which case the process is aborted.
void burn_shaders_load_and_store_vert_shader(const char *filename, const char *new_handle);
void burn_shaders_load_and_store_frag_shader(const char *filename, const char *new_handle);
burn_shaders_vert_t *burn_shaders_find_vert_shader(const char *handle);
burn_shaders_frag_t *burn_shaders_find_frag_shader(const char *handle);

//!TODO: Unfinished pipeline stuff
//!TODO: Set those active slots to 0
void burn_shaders_pipeline_configuration_init(burn_shaders_pipeline_t *pipeline);
void burn_shaders_pipeline_set_depth_configuration(burn_shaders_pipeline_t *pipeline, bool depth_write_enabled, kinc_g4_compare_mode_t depth_mode);
void burn_shaders_pipeline_set_vertex_shader(burn_shaders_pipeline_t *pipeline, burn_shaders_vert_t shader);
void burn_shaders_pipeline_set_fragment_shader(burn_shaders_pipeline_t *pipeline, burn_shaders_frag_t shader);
void burn_shaders_pipeline_set_blend_mode(burn_shaders_pipeline_t *pipeline, kinc_g4_blending_operation_t source, kinc_g4_blending_operation_t destination);
void burn_shaders_pipeline_set_alpha_blend_mode(burn_shaders_pipeline_t *pipeline, kinc_g4_blending_operation_t source, kinc_g4_blending_operation_t destination);
void burn_shaders_pipeline_compile_and_store(burn_shaders_pipeline_t *pipeline, const char *new_handle);
burn_shaders_pipeline_t *burn_shaders_find_pipeline(const char *handle);
//We need an abstraction for the creation of pipelines
//This is all wrong. As a user, we shouldn't even be taking shaders OUT of this...all work should be done in here!