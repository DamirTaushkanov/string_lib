#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    if (dest == S21_NULL){return S21_NULL;}

    s21_size_t s_len = s21_strlen(src);
    while (n>0) {
        if (s_len<0) {
            *dest = 0;
        }else {
            *dest = *src;
            src++;
        dest++;
        n--;
        s_len--;
        }
    }
    return (char *)dest;
}