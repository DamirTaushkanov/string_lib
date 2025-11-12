#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  if (needle == S21_NULL || *needle == '\0') {
    return (char *)haystack;
  }

  if (haystack == S21_NULL) {
    return S21_NULL;
  }

  s21_size_t h_len = s21_strlen(haystack);
  s21_size_t n_len = s21_strlen(needle);

  if (h_len < n_len) {
    return S21_NULL;
  }

  for (s21_size_t i = 0; i < h_len; i++) {
    s21_size_t j;
    for (j = 0; j < n_len; j++) {
      if (haystack[i + j] != needle[j]) {
        break;
      }
    }
    if (j == n_len) {
      return (char *)(haystack + i);
    }
  }
  return S21_NULL;
}