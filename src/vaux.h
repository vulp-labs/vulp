/* SPDX-License-Identifier: MIT */
/* Copyright © 2024 - Thadeu A. C. de Paula */

#ifndef vaux_h
#define vaux_h

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include "vconf.h"


typedef int8_t       i8;
typedef uint8_t      u8;
typedef int32_t      i32;
typedef uint32_t     u32;
typedef char *       str;
typedef const char * kstr;

#define memalloc(ptr,bytes) realloc(ptr,bytes)
#define memfree(ptr) (ptr && (free(ptr),true))
#define INLINED(f) inline static f __attribute__((always_inline))


#endif
