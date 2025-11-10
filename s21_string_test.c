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
char test6[30] = "Test\0with\0nulls\0";
char test7[50] = "Line1\nLine2\r\n\0";

START_TEST(test_strlen) {
  ck_assert_int_eq(s21_strlen(test1), strlen(test1));
  ck_assert_int_eq(s21_strlen(test2), strlen(test2));
  ck_assert_int_eq(s21_strlen(test3), strlen(test3));
  ck_assert_int_eq(s21_strlen(test4), strlen(test4));
  ck_assert_int_eq(s21_strlen(test5), strlen(test5));
  ck_assert_int_eq(s21_strlen(test6), strlen(test6));
  ck_assert_int_eq(s21_strlen(test7), strlen(test7));
}
END_TEST

START_TEST(test_strchr) {
  // Positive
  ck_assert_ptr_eq(s21_strchr(test1, 'l'), strchr(test1, 'l'));
  ck_assert_ptr_eq(s21_strchr(test2, '\0'), strchr(test2, '\0'));
  ck_assert_ptr_eq(s21_strchr(test3, '\n'), strchr(test3, '\n'));
  ck_assert_ptr_eq(s21_strchr(test5, 'c'), strchr(test5, 'c'));
  ck_assert_ptr_eq(s21_strchr(test6, '\0'), strchr(test6, '\0'));

  // Negative
  ck_assert_ptr_eq(s21_strchr(test1, '2'), strchr(test1, '2'));
  ck_assert_ptr_eq(s21_strchr(test4, '\r'), strchr(test1, '\r'));
}
END_TEST

START_TEST(test_strrchr) {
  // Positive
  ck_assert_ptr_eq(s21_strrchr(test1, 'l'), strrchr(test1, 'l'));
  ck_assert_ptr_eq(s21_strrchr(test2, '\0'), strrchr(test2, '\0'));
  ck_assert_ptr_eq(s21_strrchr(test3, '\n'), strrchr(test3, '\n'));
  ck_assert_ptr_eq(s21_strrchr(test5, 'l'), strrchr(test5, 'l'));
  ck_assert_ptr_eq(s21_strrchr(test6, '\0'), strrchr(test6, '\0'));

  // Negative
  ck_assert_ptr_eq(s21_strrchr(test1, '2'), strrchr(test1, '2'));
  ck_assert_ptr_eq(s21_strrchr(test4, '\r'), strrchr(test1, '\r'));
}
END_TEST

START_TEST(test_strncat) {
  // Test case
  char dest1[20] = "Hello";
  char dest2[300] = "Test string with multiple lines\n"
                    "Second line of text\n"
                    "Third line of text";
  char dest3[20] = "\n\0";
  char dest4[50] = "Test\0with\0nulls\0";

  char src1[10] = "world";
  char src2[30] = "\nAnoter string";
  char src3[15] = "Line2\r\n";

  ck_assert_str_eq(s21_strncat(dest1, src1, 10), strncat(dest1, src1, 10));
  ck_assert_str_eq(s21_strncat(dest2, src2, 14), strncat(dest2, src2, 14));
  ck_assert_str_eq(s21_strncat(dest3, src3, 15), strncat(dest3, src3, 15));
  ck_assert_str_eq(s21_strncat(dest4, src3, 15), strncat(dest4, src3, 15));
}
END_TEST

int main() {
  Suite *s = suite_create("String test");
  TCase *tc = tcase_create("String test");

  tcase_add_test(tc, test_strlen);
  tcase_add_test(tc, test_strchr);
  tcase_add_test(tc, test_strrchr);
  tcase_add_test(tc, test_strncat);

  suite_add_tcase(s, tc);

  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);

  int failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return failed;
}