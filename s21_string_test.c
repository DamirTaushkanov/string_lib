#include <check.h>

#include "s21_string.h"
#include <string.h>

char test1[20] = "Hello world\0";
char test2[5] = "\0";
char test3[5] = "\n\0";
char test4[20] = "Hello world\n\0";
char test5[200] = "Test string with multiple lines\n"
                  "Second line of text\n"
                  "Third line of text...";

START_TEST (test_strlen) {
    ck_assert_int_eq(s21_strlen(test1), strlen(test1));
    ck_assert_int_eq(s21_strlen(test2), strlen(test2));
    ck_assert_int_eq(s21_strlen(test3), strlen(test3));
    ck_assert_int_eq(s21_strlen(test4), strlen(test4));
    ck_assert_int_eq(s21_strlen(test5), strlen(test5));
}
END_TEST

int main() {
    Suite *s = suite_create("String test");
    TCase *tc = tcase_create("String test");

    tcase_add_test(tc, test_strlen);

    suite_add_tcase(s, tc);

    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);

    int failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return failed;
}