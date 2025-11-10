#ifndef S21_STRING_H
#define S21_STRING_H

#define S21_NULL ((void *)0)
typedef unsigned long s21_size_t;

/*---Part1---*/
s21_size_t s21_strlen(const char *str);
char *s21_strchr(const char *str, int c);
char *s21_strrchr(const char *str, int c);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
#endif