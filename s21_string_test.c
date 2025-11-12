#include <check.h>

#include "s21_string.h"
#include <string.h>
#include <stdio.h>

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

// Strstr test
START_TEST(test_strstr) {
  // Base test
  {
    ck_assert_str_eq(s21_strstr("Hello World", "World"),
                     strstr("Hello World", "World"));
    ck_assert_str_eq(s21_strstr("Hello World", "Hello"),
                     strstr("Hello World", "Hello"));
    ck_assert_str_eq(s21_strstr("Hello World", "lo"),
                     strstr("Hello World", "lo"));
    ck_assert_str_eq(s21_strstr("Hello World", "o W"),
                     strstr("Hello World", "o W"));
  }

  // There isn't
  {
    ck_assert_ptr_eq(s21_strstr("Hello World", "XYZ"),
                     strstr("Hello World", "XYZ"));
    ck_assert_ptr_eq(s21_strstr("Hello World", "world"),
                     strstr("Hello World", "world"));
    ck_assert_ptr_eq(s21_strstr("Hello", "Hello World"),
                     strstr("Hello", "Hello World"));
  }

  // Needle is empty
  {
    ck_assert_ptr_eq(s21_strstr("Hello World", ""), strstr("Hello World", ""));
    ck_assert_ptr_eq(s21_strstr("", ""), strstr("", ""));
  }

  // Haystack is empty
  {
    ck_assert_ptr_eq(s21_strstr("", "test"), strstr("", "test"));
    ck_assert_ptr_eq(s21_strstr("", "a"), strstr("", "a"));
  }

  // Complete coincidence
  {
    ck_assert_str_eq(s21_strstr("test", "test"), strstr("test", "test"));
    ck_assert_str_eq(s21_strstr("a", "a"), strstr("a", "a"));
  }

  // Multiple
  {
    ck_assert_str_eq(s21_strstr("ababab", "ab"), strstr("ababab", "ab"));
    ck_assert_str_eq(s21_strstr("Hello Wor World", "World"),
                     strstr("Hello Wor World", "World"));
    ck_assert_str_eq(s21_strstr("mississippi", "iss"),
                     strstr("mississippi", "iss"));
  }

  // Special symbol
  {
    ck_assert_str_eq(s21_strstr("Line1\nLine2", "Line2"),
                     strstr("Line1\nLine2", "Line2"));
    ck_assert_str_eq(s21_strstr("Tab\tText", "\tT"),
                     strstr("Tab\tText", "\tT"));
    ck_assert_str_eq(s21_strstr("Test\r\nEnd", "\r\n"),
                     strstr("Test\r\nEnd", "\r\n"));
  }

  // Partial match
  {
    char *haystack = "abcabcabcd";
    char *needle = "abcabcd";
    ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
  }

  // One symbol
  ck_assert_str_eq(s21_strstr("abcdef", "c"), strstr("abcdef", "c"));
  ck_assert_str_eq(s21_strstr("abcdef", "f"), strstr("abcdef", "f"));
  ck_assert_ptr_eq(s21_strstr("abcdef", "g"), strstr("abcdef", "g"));

  // Big line
  {
    char long_str[] = "This is a very long string for testing purposes with "
                      "multiple words and patterns";
    ck_assert_str_eq(s21_strstr(long_str, "multiple"),
                     strstr(long_str, "multiple"));
    ck_assert_str_eq(s21_strstr(long_str, "patterns"),
                     strstr(long_str, "patterns"));
    ck_assert_ptr_eq(s21_strstr(long_str, "nonexistent"),
                     strstr(long_str, "nonexistent"));
  }

  // Digits
  {
    ck_assert_str_eq(s21_strstr("123456789", "456"),
                     strstr("123456789", "456"));
    ck_assert_str_eq(s21_strstr("test123test", "123"),
                     strstr("test123test", "123"));
  }

  // Mix
  {
    ck_assert_str_eq(s21_strstr("Hello123 World!@#", "World!@"),
                     strstr("Hello123 World!@#", "World!@"));
    ck_assert_str_eq(s21_strstr("Text with  spaces", "with  sp"),
                     strstr("Text with  spaces", "with  sp"));
  }
}
END_TEST

// Strncmp test
START_TEST(test_strncmp) {
  // Base test
  {
    ck_assert_int_eq(s21_strncmp("abc", "abc", 3), strncmp("abc", "abc", 3));
    ck_assert_int_eq(s21_strncmp("Hello", "Hello", 5),
                     strncmp("Hello", "Hello", 5));
    ck_assert_int_eq(s21_strncmp("", "", 1), strncmp("", "", 1));
  }

  // Different line
  {
    ck_assert_int_eq(s21_strncmp("abc", "abd", 3), strncmp("abc", "abd", 3));
    ck_assert_int_eq(s21_strncmp("abd", "abc", 3), strncmp("abd", "abc", 3));
    ck_assert_int_eq(s21_strncmp("abc", "abC", 3), strncmp("abc", "abC", 3));
  }

  // First symbol diff
  {
    ck_assert_int_eq(s21_strncmp("abc", "xbc", 3), strncmp("abc", "xbc", 3));
    ck_assert_int_eq(s21_strncmp("xbc", "abc", 3), strncmp("xbc", "abc", 3));
  }

  // N limit
  {
    ck_assert_int_eq(s21_strncmp("abc", "abd", 2), strncmp("abc", "abd", 2));
    ck_assert_int_eq(s21_strncmp("abcdef", "abcxyz", 3),
                     strncmp("abcdef", "abcxyz", 3));
    ck_assert_int_eq(s21_strncmp("Hello", "Help", 3),
                     strncmp("Hello", "Help", 3));
  }

  // N = 0
  {
    ck_assert_int_eq(s21_strncmp("abc", "xyz", 0), strncmp("abc", "xyz", 0));
    ck_assert_int_eq(s21_strncmp("anything", "different", 0),
                     strncmp("anything", "different", 0));
  }

  // Different line len
  {
    ck_assert_int_eq(s21_strncmp("ab", "abc", 3), strncmp("ab", "abc", 3));
    ck_assert_int_eq(s21_strncmp("abc", "ab", 3), strncmp("abc", "ab", 3));
    ck_assert_int_eq(s21_strncmp("a", "", 2), strncmp("a", "", 2));
    ck_assert_int_eq(s21_strncmp("", "a", 2), strncmp("", "a", 2));
  }

  // Special symbol
  {
    ck_assert_int_eq(s21_strncmp("\t\n", "\t\n", 3),
                     strncmp("\t\n", "\t\n", 3));
    ck_assert_int_eq(s21_strncmp("a\tb", "a\tc", 3),
                     strncmp("a\tb", "a\tc", 3));
    ck_assert_int_eq(s21_strncmp("test\n", "test\r", 5),
                     strncmp("test\n", "test\r", 5));
  }

  // Digits
  {
    ck_assert_int_eq(s21_strncmp("123", "123", 3), strncmp("123", "123", 3));
    ck_assert_int_eq(s21_strncmp("123", "124", 3), strncmp("123", "124", 3));
    ck_assert_int_eq(s21_strncmp("test123", "test124", 7),
                     strncmp("test123", "test124", 7));
  }

  // N len more than lines
  {
    ck_assert_int_eq(s21_strncmp("short", "short", 10),
                     strncmp("short", "short", 10));
    ck_assert_int_eq(s21_strncmp("a", "b", 10), strncmp("a", "b", 10));
    ck_assert_int_eq(s21_strncmp("abc", "abd", 10), strncmp("abc", "abd", 10));
  }

  // Big N
  {
    ck_assert_int_eq(s21_strncmp("identical", "identical", 100),
                     strncmp("identical", "identical", 100));
  }

  // Empty lines
  {
    ck_assert_int_eq(s21_strncmp("", "", 0), strncmp("", "", 0));
    ck_assert_int_eq(s21_strncmp("", "", 1), strncmp("", "", 1));
    ck_assert_int_eq(s21_strncmp("", "", 10), strncmp("", "", 10));
  }
}
END_TEST

// Strtok test
START_TEST(test_strtok) {
  // Base test 
  {
    char str1_std[] = "Hello,World,Test";
    char str1_s21[] = "Hello,World,Test";
    
    char *token_std = strtok(str1_std, ",");
    char *token_s21 = s21_strtok(str1_s21, ",");
    ck_assert_str_eq(token_s21, token_std);
    
    token_std = strtok(NULL, ",");
    token_s21 = s21_strtok(NULL, ",");
    ck_assert_str_eq(token_s21, token_std);
    
    token_std = strtok(NULL, ",");
    token_s21 = s21_strtok(NULL, ",");
    ck_assert_str_eq(token_s21, token_std);
    
    token_std = strtok(NULL, ",");
    token_s21 = s21_strtok(NULL, ",");
    ck_assert_ptr_eq(token_s21, token_std);
  }

  // Multiple delim
  {
    char str_std[] = "  Hello, World!  ";
    char str_s21[] = "  Hello, World!  ";
    
    char *token_std = strtok(str_std, " ,!");
    char *token_s21 = s21_strtok(str_s21, " ,!");
    ck_assert_str_eq(token_s21, token_std);
    
    token_std = strtok(NULL, " ,!");
    token_s21 = s21_strtok(NULL, " ,!");
    ck_assert_str_eq(token_s21, token_std);
    
    token_std = strtok(NULL, " ,!");
    token_s21 = s21_strtok(NULL, " ,!");
    ck_assert_ptr_eq(token_s21, token_std);
  }
  
  // Consecutive delim
  {
    char str_std[] = "Hello,,,World,,Test";
    char str_s21[] = "Hello,,,World,,Test";
    
    char *token_std = strtok(str_std, ",");
    char *token_s21 = s21_strtok(str_s21, ",");
    ck_assert_str_eq(token_s21, token_std);
    
    token_std = strtok(NULL, ",");
    token_s21 = s21_strtok(NULL, ",");
    ck_assert_str_eq(token_s21, token_std);
    
    token_std = strtok(NULL, ",");
    token_s21 = s21_strtok(NULL, ",");
    ck_assert_str_eq(token_s21, token_std);
    
    token_std = strtok(NULL, ",");
    token_s21 = s21_strtok(NULL, ",");
    ck_assert_ptr_eq(token_s21, token_std);
  }
  
  // Only delim
  {
    char str1_std[] = ",,,,";
    char str1_s21[] = ",,,,";
    
    char *token_std = strtok(str1_std, ",");
    char *token_s21 = s21_strtok(str1_s21, ",");
    ck_assert_ptr_eq(token_s21, token_std);
    
    token_std = strtok(NULL, ",");
    token_s21 = s21_strtok(NULL, ",");
    ck_assert_ptr_eq(token_s21, token_std);
  }

  // Empty str
  {
    char str_std[] = "";
    char str_s21[] = "";
    
    char *token_std = strtok(str_std, ",");
    char *token_s21 = s21_strtok(str_s21, ",");
    ck_assert_ptr_eq(token_s21, token_std);
    
    token_std = strtok(NULL, ",");
    token_s21 = s21_strtok(NULL, ",");
    ck_assert_ptr_eq(token_s21, token_std);
  }

  // There isn't delim
  {
    char str_std[] = "HelloWorld";
    char str_s21[] = "HelloWorld";
    
    char *token_std = strtok(str_std, ",");
    char *token_s21 = s21_strtok(str_s21, ",");
    ck_assert_str_eq(token_s21, token_std);
    
    token_std = strtok(NULL, ",");
    token_s21 = s21_strtok(NULL, ",");
    ck_assert_ptr_eq(token_s21, token_std);
  }
  
  // Special symbol
  {
    char str_std[] = "Line1\nLine2\tLine3\rLine4";
    char str_s21[] = "Line1\nLine2\tLine3\rLine4";
    
    char *token_std = strtok(str_std, "\n\t\r");
    char *token_s21 = s21_strtok(str_s21, "\n\t\r");
    ck_assert_str_eq(token_s21, token_std);
    
    token_std = strtok(NULL, "\n\t\r");
    token_s21 = s21_strtok(NULL, "\n\t\r");
    ck_assert_str_eq(token_s21, token_std);
    
    token_std = strtok(NULL, "\n\t\r");
    token_s21 = s21_strtok(NULL, "\n\t\r");
    ck_assert_str_eq(token_s21, token_std);
    
    token_std = strtok(NULL, "\n\t\r");
    token_s21 = s21_strtok(NULL, "\n\t\r");
    ck_assert_str_eq(token_s21, token_std);
    
    token_std = strtok(NULL, "\n\t\r");
    token_s21 = s21_strtok(NULL, "\n\t\r");
    ck_assert_ptr_eq(token_s21, token_std);
  }
  
  // Delim at the end
  {
    char str_std[] = "Hello,World,";
    char str_s21[] = "Hello,World,";
    
    char *token_std = strtok(str_std, ",");
    char *token_s21 = s21_strtok(str_s21, ",");
    ck_assert_str_eq(token_s21, token_std);
    
    token_std = strtok(NULL, ",");
    token_s21 = s21_strtok(NULL, ",");
    ck_assert_str_eq(token_s21, token_std);
    
    token_std = strtok(NULL, ",");
    token_s21 = s21_strtok(NULL, ",");
    ck_assert_ptr_eq(token_s21, token_std);
  }

  // Change delim
  {
    char str_std[] = "Hello,World;Test";
    char str_s21[] = "Hello,World;Test";
    
    char *token_std = strtok(str_std, ",");
    char *token_s21 = s21_strtok(str_s21, ",");
    ck_assert_str_eq(token_s21, token_std);
    
    token_std = strtok(NULL, ";");
    token_s21 = s21_strtok(NULL, ";");
    ck_assert_str_eq(token_s21, token_std);
    
    token_std = strtok(NULL, ";");
    token_s21 = s21_strtok(NULL, ";");
    ck_assert_ptr_eq(token_s21, token_std);
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
  tcase_add_test(tc, test_strstr);
  tcase_add_test(tc, test_strncmp);
  tcase_add_test(tc, test_strtok);

  suite_add_tcase(s, tc);

  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);

  int failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return failed;
}