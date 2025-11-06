#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
    while (1) {
        if (*str != (char)c) {
            str++;
        }else{return (char *)str;}
        if (*str == '\0'){break;}
    }
    return S21_NULL;
}