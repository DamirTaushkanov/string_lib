CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=gnu11
CHECK_CFLAGS = -I/usr/local/Cellar/check/0.15.2/include
CHECK_LDFLAGS = -L/usr/local/Cellar/check/0.15.2/lib
TEST_FLAGS = -lcheck -lm -lpthread

#SRC_FILE = $(filter-out  test_%.c, $(wildcard *.c))
SRC_FILE = s21_strlen.c
OBJ_FILE = $(SRC_FILE:.c=.o)

.PHONY: all clean rebulid test

all: s21_string.a

s21_string.a: $(OBJ_FILE)
	@ar rcs $@ $^
	@rm -rf *.o

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

test: s21_string.a
	$(CC) $(CFLAGS) $(CHECK_CFLAGS) s21_string_test.c s21_string.a $(CHECK_LDFLAGS) $(TEST_FLAGS) -o test_exec
	./test_exec

clean:
	@rm -rf *.o s21_string.a

rebuild: clean all