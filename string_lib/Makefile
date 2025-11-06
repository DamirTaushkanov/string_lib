CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=gnu11

SRC_FILE = $(filter-out  test_%.c, $(wildcard *.c))
OBJ_FILE = $(SRC_FILE:.c=.o)

.PHONY: all clean rebulid test

all: s21_string.a

s21_string.a: $(OBJ_FILE)
	@ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf *.o s21_string.a

rebuild: clean all