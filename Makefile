CC = gcc

CFLAGS = -Wall -Werror -Wextra -std=gnu11
CHECK_CFLAGS = -I/usr/local/Cellar/check/0.15.2/include
CHECK_LDFLAGS = -L/usr/local/Cellar/check/0.15.2/lib
TEST_FLAGS = -lcheck -lm -lpthread
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
LCOV_FLAGS = --capture --directory

#SRC_FILE = $(filter-out  test_%.c, $(wildcard *.c))
SRC_FILE = s21_strlen.c s21_strchr.c s21_strrchr.c s21_strncat.c s21_strstr.c s21_strncmp.c
OBJ_FILE = $(SRC_FILE:.c=.o)

CLANG_FORMAT = clang-format

.PHONY: all clean rebulid test gcov_report format

all: s21_string.a

s21_string.a: $(OBJ_FILE)
	@ar rcs $@ $^
	@rm -rf *.o

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

format:
	@$(CLANG_FORMAT) -i *.c *.h
	$(CLANG_FORMAT) -n *.c *.h

test: s21_string.a
	$(CC) $(CFLAGS) $(CHECK_CFLAGS) $(GCOV_FLAGS) s21_string_test.c s21_string.a $(CHECK_LDFLAGS) $(TEST_FLAGS) -o test_exec
	./test_exec

gcov_report:
	@python3 -m gcovr --html-details coverage.html

clean:
	@rm -rf *.o s21_string.a *.gcda *.gcno test.info coverage_report *.html *.css test_exec

rebuild: clean all