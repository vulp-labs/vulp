/* SPDX-License-Identifier: MIT */
/* Copyright © 2024 - Thadeu A. C. de Paula */
#ifndef vio_h
#define vio_h

#include "vaux.h"

typedef struct VulpIO {
  FILE *fp;
  kstr  name;
  char  buf[VP_SMALLBUFSZ];
  char *ptr;
  size_t len;
} VulpIO;

bool vioOpen  (VulpIO*, kstr);
void vioClose (VulpIO*); 
u8   vioMore  (VulpIO*);

#define vioNext(s)    \
  (((s)->len--) > 0 ? (u8)*((s)->ptr++) : vioMore(s))

#endif
