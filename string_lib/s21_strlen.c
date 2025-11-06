#include "s21_string.h"

s21_size_t strlen(const char *str) {
    const char *end = str;
    while (*end != '\0') {
        end++;
    }
    return end-str;
}