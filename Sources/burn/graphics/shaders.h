#pragma once

#include <kinc/graphics4/shader.h>
#include <kinc/graphics4/pipeline.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_SHADERS 32
#define MAX_PIPELINES 32
#define MAX_CONSTANTS 16

typedef struct burn_shaders_shader {
	char handle[256];
	kinc_g4_shader_t *shader;
} burn_shaders_frag_t, burn_shaders_vert_t;

typedef struct burn_shaders_pipeline {
	char handle[256];
	kinc_g4_pipeline_t *pipeline;
} burn_shaders_pipeline_t;

typedef struct burn_shaders_storage {
	burn_shaders_frag_t fragment_shaders[MAX_SHADERS];
	burn_shaders_vert_t vertex_shaders[MAX_SHADERS];
	burn_shaders_pipeline_t pipelines[MAX_PIPELINES];
	uint8_t *memory_slab;
} burn_shaders_storage_t;

//Allocate a heap for temporarily holding shader data before a shader is constructed
void burn_shaders_init(burn_shaders_storage_t *storage, size_t temp_memory_size);
//Bool for returning if the file failed to be loaded, in which case the process is aborted.
bool burn_shaders_load_and_store_vert_shader(const char *filename, const char *new_handle);
bool burn_shaders_load_and_store_frag_shader(const char *filename, const char *new_handle);
kinc_g4_shader_t burn_shaders_find_vert_shader(const char *handle);
kinc_g4_shader_t burn_shaders_find_frag_shader(const char *handle);