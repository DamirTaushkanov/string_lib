#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *last = '\0';
  char *st = S21_NULL;
  if (str) {
    last = str;
  }
  
  if (last != S21_NULL && *last != '\0') {
    char *c = last;
    while (s21_strchr(delim, *c)) {
      c++;
    }
    if (*c != '\0') {
      st = c;
      while (*c != '\0' && s21_strchr(delim, *c) == 0) {
        c++;
      }
      if (*c == '\0') {
        last = c;
      } else {
        *c = '\0';
        last = c + 1;
      }
    }else {
        return S21_NULL;
    }
  }
  return st;
}