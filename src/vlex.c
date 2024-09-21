/* SPDX-License-Identifier: MIT */
/* Copyright © 2024 - Thadeu A. C. de Paula */

#include "vaux.h"
#include "vlex.h"
#include <stdalign.h>
#include <ctype.h>
#define lex(c) lex_##c (L); break

#define current(L) *(L->io->ptr)
#define next(L)    vioNext((L)->io)

static void lex_number(Lex *L) {
  char n[100];
  n[0] = current(L);
  for(;;) {
    printf("|%c|\n",current(L));
    if (!next(L)) return;
  }

}

Lex *lex_init(kstr name) {
  Lex *L = memalloc(NULL, sizeof(Lex)+sizeof(VulpIO));
  *L = (Lex){0};
  L->io = (VulpIO *)(L+1);

  vioOpen(L->io, name);
  vioMore(L->io);
  return L; 
}

bool lex_next(Lex *L) {
  printf("%c\n", *L->io->ptr);
  switch( current(L) ) {
    case '1': case '2': case '3': case '4': case '5':
    case '6': case '7': case '8': case '9': case '0':
      lex(number);
      case '\0': return false;
  }
  return false;
}

void lex_finish(Lex *L) {
  vioClose(L->io);
  memfree(L);
}


//bool vlex(Lex *L) {
//  switch(sread(L)){
//    {
//      break;    
//    }
//  }
//  return true;
//}
