/* SPDX-License-Identifier: MIT */
/* Copyright © 2024 - Thadeu A. C. de Paula */

#include "vaux.h"
#include "vparse.h"
#include "vlex.h"


bool vparse(kstr file) {
  Lex *lex = lex_init(file);
  lex_next(lex);
  lex_finish(lex);
  return false;
}
