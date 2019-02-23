#ifndef CRC32_HELPER_H
#define CRC32_HELPER_H

#include <stdio.h>
#include <stdint.h>
#include <zlib.h>

uint64_t fsize(FILE *file);
uint32_t fcrc32(FILE *file);

#endif
