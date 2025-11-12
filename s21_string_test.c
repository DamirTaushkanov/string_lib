#include <check.h>

#include "s21_string.h"
#include <string.h>

// Test string
char hello_test[20] = "Hello world";
char only_end_test[5] = "";
char big_test[200] = "Test string with multiple lines\n"
                     "Second line of text\n"
                     "Third line of text...";
char mult_end_test[30] = "Test\0with\0nulls\0";
char r_test[50] = "Line1\nLine2\r\n\0";

// Strlen test
START_TEST(test_strlen) {
  // Base test
  ck_assert_int_eq(s21_strlen(hello_test), strlen(hello_test));
  ck_assert_int_eq(s21_strlen(only_end_test), strlen(only_end_test));
  ck_assert_int_eq(s21_strlen(big_test), strlen(big_test));
  ck_assert_int_eq(s21_strlen(mult_end_test), strlen(mult_end_test));
  ck_assert_int_eq(s21_strlen(r_test), strlen(r_test));

  // Empty line
  {
    char empty_str[] = "";
    ck_assert_int_eq(s21_strlen(empty_str), strlen(empty_str));
  }

  // One symbol
  {
    char single_char[] = "A";
    ck_assert_int_eq(s21_strlen(single_char), strlen(single_char));
  }

  // Whitespace
  {
    char spaces[] = "    ";
    ck_assert_int_eq(s21_strlen(spaces), strlen(spaces));
  }

  // Special symbol
  {
    char special_chars[] = "\t\n\r\0\\"; // strlen остановится на первом \0
    ck_assert_int_eq(s21_strlen(special_chars), strlen(special_chars));
  }

  // Digits
  {
    char numbers[] = "1234567890";
    ck_assert_int_eq(s21_strlen(numbers), strlen(numbers));
  }

  // Mix
  {
    char mixed[] = "Hello, World! 123 \t\n";
    ck_assert_int_eq(s21_strlen(mixed), strlen(mixed));
  }

  // Big line
  {
    char long_str[] = "This is a relatively long string for testing purposes";
    ck_assert_int_eq(s21_strlen(long_str), strlen(long_str));
  }
}
END_TEST

// Strchr test
START_TEST(test_strchr) {
  // Base test
  {
    char str[] = "Hello, World!";
    ck_assert_ptr_eq(s21_strchr(str, 'l'), strchr(str, 'l'));
    ck_assert_ptr_eq(s21_strchr(str, 'o'), strchr(str, 'o'));
  }

  // First symbol
  {
    char str[] = "Hello";
    ck_assert_ptr_eq(s21_strchr(str, 'H'), strchr(str, 'H'));
  }

  // Last symbol
  {
    char str[] = "Hello";
    ck_assert_ptr_eq(s21_strchr(str, 'o'), strchr(str, 'o'));
  }

  // There isn't symbol
  {
    char str[] = "Hello";
    ck_assert_ptr_eq(s21_strchr(str, 'x'), strchr(str, 'x'));
    ck_assert_ptr_eq(s21_strchr(str, '0'), strchr(str, '0'));
  }

  // Searching \0
  {
    char str[] = "Hello";
    ck_assert_ptr_eq(s21_strchr(str, '\0'), strchr(str, '\0'));
  }

  // Repeat symbol
  {
    char str[] = "Mississippi";
    ck_assert_ptr_eq(s21_strchr(str, 's'), strchr(str, 's'));
    ck_assert_ptr_eq(s21_strchr(str, 'i'), strchr(str, 'i'));
  }

  // Special symbol
  {
    char str[] = "Line1\nLine2\r\n";
    ck_assert_ptr_eq(s21_strchr(str, '\n'), strchr(str, '\n'));
    ck_assert_ptr_eq(s21_strchr(str, '\r'), strchr(str, '\r'));
  }

  // Empty line
  {
    char str[] = "";
    ck_assert_ptr_eq(s21_strchr(str, 'a'), strchr(str, 'a'));
    ck_assert_ptr_eq(s21_strchr(str, '\0'), strchr(str, '\0'));
  }

  // Digitsand special symbol
  {
    char str[] = "abc123!@#";
    ck_assert_ptr_eq(s21_strchr(str, '1'), strchr(str, '1'));
    ck_assert_ptr_eq(s21_strchr(str, '!'), strchr(str, '!'));
    ck_assert_ptr_eq(s21_strchr(str, '#'), strchr(str, '#'));
  }
}
END_TEST

// Strrchr test
START_TEST(test_strrchr) {
  // Base test
  {
    char str[] = "Hello, World!";
    ck_assert_ptr_eq(s21_strrchr(str, 'l'), strrchr(str, 'l'));
    ck_assert_ptr_eq(s21_strrchr(str, 'o'), strrchr(str, 'o'));
  }

  // First symbol
  {
    char str[] = "Hello";
    ck_assert_ptr_eq(s21_strrchr(str, 'H'), strrchr(str, 'H'));
  }

  // Last symbol
  {
    char str[] = "Hello";
    ck_assert_ptr_eq(s21_strrchr(str, 'o'), strrchr(str, 'o'));
  }

  // There isn't symbol
  {
    char str[] = "Hello";
    ck_assert_ptr_eq(s21_strrchr(str, 'x'), strrchr(str, 'x'));
    ck_assert_ptr_eq(s21_strrchr(str, '0'), strrchr(str, '0'));
  }

  // Searching \0
  {
    char str[] = "Hello";
    ck_assert_ptr_eq(s21_strrchr(str, '\0'), strrchr(str, '\0'));
  }

  // Repeat symbol
  {
    char str[] = "Mississippi";
    ck_assert_ptr_eq(s21_strrchr(str, 's'), strrchr(str, 's'));
    ck_assert_ptr_eq(s21_strrchr(str, 'i'), strrchr(str, 'i'));
  }

  // Special symbol
  {
    char str[] = "Line1\nLine2\r\n";
    ck_assert_ptr_eq(s21_strrchr(str, '\n'), strrchr(str, '\n'));
    ck_assert_ptr_eq(s21_strrchr(str, '\r'), strrchr(str, '\r'));
  }

  // Empty line
  {
    char str[] = "";
    ck_assert_ptr_eq(s21_strrchr(str, 'a'), strrchr(str, 'a'));
    ck_assert_ptr_eq(s21_strrchr(str, '\0'), strrchr(str, '\0'));
  }

  // Digitsand special symbol
  {
    char str[] = "abc123!@#";
    ck_assert_ptr_eq(s21_strrchr(str, '1'), strrchr(str, '1'));
    ck_assert_ptr_eq(s21_strrchr(str, '!'), strrchr(str, '!'));
    ck_assert_ptr_eq(s21_strrchr(str, '#'), strrchr(str, '#'));
  }
}
END_TEST

// Strncat test
START_TEST(test_strncat) {
  // Base test
  {
    char dest_s21[20] = "Hello, ";
    char dest_std[20] = "Hello, ";
    ck_assert_str_eq(s21_strncat(dest_s21, "World!", 6),
                     strncat(dest_std, "World!", 6));
  }

  // N is less then len src
  {
    char dest_s21[20] = "Hello, ";
    char dest_std[20] = "Hello, ";
    ck_assert_str_eq(s21_strncat(dest_s21, "Wonderful World!", 3),
                     strncat(dest_std, "Wonderful World!", 3));
  }

  // N is more then len src
  {
    char dest_s21[20] = "Hello, ";
    char dest_std[20] = "Hello, ";
    ck_assert_str_eq(s21_strncat(dest_s21, "Hi", 5),
                     strncat(dest_std, "Hi", 5));
  }

  // N == 0
  {
    char dest_s21[20] = "Hello, ";
    char dest_std[20] = "Hello, ";
    ck_assert_str_eq(s21_strncat(dest_s21, "World!", 0),
                     strncat(dest_std, "World!", 0));
  }

  // Dest is emty
  {
    char dest_s21[20] = "";
    char dest_std[20] = "";
    ck_assert_str_eq(s21_strncat(dest_s21, "Hello", 5),
                     strncat(dest_std, "Hello", 5));
  }

  // Src is empty
  {
    char dest_s21[20] = "Start";
    char dest_std[20] = "Start";
    ck_assert_str_eq(s21_strncat(dest_s21, "", 3), strncat(dest_std, "", 3));
  }

  // To the brim
  {
    char dest_s21[12] = "Hello";
    char dest_std[12] = "Hello";
    ck_assert_str_eq(s21_strncat(dest_s21, " World", 6),
                     strncat(dest_std, " World", 6));
  }

  // \0 in the middle
  {
    char src_with_null[10] = "AB\0CD";
    char dest_s21[20] = "Start";
    char dest_std[20] = "Start";
    ck_assert_str_eq(s21_strncat(dest_s21, src_with_null, 5),
                     strncat(dest_std, src_with_null, 5));
  }

  // Return
  {
    char dest_s21[20] = "Hello";
    char dest_std[20] = "Hello";
    char *result_s21 = s21_strncat(dest_s21, " Test", 5);
    char *result_std = strncat(dest_std, " Test", 5);

    ck_assert_ptr_eq(result_s21, dest_s21);
    ck_assert_str_eq(result_s21, result_std);
  }
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