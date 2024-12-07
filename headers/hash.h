#ifndef HASH_INCLUDED
#define HASH_INCLUDED

#include <stdint.h>

/// @brief calculates 32-bit MurMur hash for the data
uint32_t MurMur32Hash(const void * data, size_t len, uint32_t seed);

#endif
