#pragma once

//https://stackoverflow.com/a/4415646
#define NUMELEMS(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))