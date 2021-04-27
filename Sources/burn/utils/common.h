#pragma once

#include <string.h>

//https://stackoverflow.com/a/4415646
#define BURN_NUMELEMS(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

/*
	Search for a string handle in an array that contains structs with a "handle" string field.

	Jesus christ this is so awful :D
*/
// #define BURN_SEARCH_HANDLE_IN_STRUCT_ARRAY(index_out, const_handle, scan_up_to, container, size) 	\
// 	index_out = -1;																					\
// 																									\
// 	for (int i = 0; i < (size) && i < (scan_up_to); ++i) {											\
// 		if (strcmp((const_handle), (container[i].handle)) == 0) {									\
// 			(index_out) = i;																		\
// 		}																							\
// 	}	

/*
	A kind of better "generic" implementation of this linear searching method

	Make sure that your struct contains "handle", a char array containing a unique identifier to strcmp against.
*/
#define BURN_COMMON_CREATE_SEARCH_FUNCTION_FOR_GENERIC_HANDLE_IN_STRUCT_ARRAY(type) \
static int burn_search_handle_in_struct_array_##type(type *storage, const char *const_handle, int scan_up_to, size_t size) {	\
	for (int i = 0; i < (size) && i < (scan_up_to); ++i) {																		\
		if (strcmp((const_handle), (storage[i].handle)) == 0) {																	\
			return i;																											\
		}																														\
	}																															\
																																\
	return -1;																													\
}