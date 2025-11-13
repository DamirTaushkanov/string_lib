#include "s21_string.h"
#include <stdlib.h>

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *last_ch_dest = dest + s21_strlen(dest);

  while (n != 0 && *src != '\0') {
    *last_ch_dest++ = *src++;
    n--;
  }

  *last_ch_dest = '\0';
  return (char *)dest;
}