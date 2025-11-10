#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  s21_size_t s_len = s21_strlen(str);
  while (1) {
    if (str[s_len] != (char)c) {
      s_len--;
    } else {
      return (char *)str + s_len;
    }
    if (str[s_len] == '\0') {
      break;
    }
  }
  return S21_NULL;
}