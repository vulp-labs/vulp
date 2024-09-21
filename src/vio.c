#include "vio.h"

bool vioOpen(VulpIO *s, kstr name) {
  s->buf[10] = '\0';
  s->name = name;
  s->fp = fopen(name, "r");
  return (NULL != s->fp);
}

// u8 vioGetc
u8 vioMore(VulpIO *s) {
  if (s->fp == NULL || (!(s->len = fread(&s->buf, 1, VP_SMALLBUFSZ, s->fp)))) {
    return '\0';
  }
  s->ptr = s->buf;
  s->len--;
  
  return (u8)*s->ptr;
  return '\0';
}

void vioClose(VulpIO *s) {
  fclose(s->fp);
}
