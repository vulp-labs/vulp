/* SPDX-License-Identifier: MIT */
/* Copyright © 2024 - Thadeu A. C. de Paula */
#ifndef vlex_h
#define vlex_h

#include "vaux.h"
#include "vconf.h"
#include "vio.h"

typedef enum {
  TK_START,
  TK_NUMBER,
  TK_STRING,
  TK_IDENTIFIER,
} Token;






typedef struct Lex Lex; struct Lex {
  Lex      *lparent, *lchild;
  VulpIO   *io;
  str       stName;
  Token     tk;
};

Lex *lex_init(kstr);
bool lex_next(Lex *);
void lex_finish(Lex *);

#endif // vlex_h
