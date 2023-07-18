
CC=gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -pedantic

all: s21_matrix.a

s21_matrix.a: s21_matrix.o s21_add_matrix.o
	ar -rcs s21_matrix.a s21_matrix.o s21_add_matrix.o

s21_matrix.o: s21_matrix.c s21_matrix.h
	$(CC) $(CFLAGS) -c s21_matrix.c -o s21_matrix.o

s21_add_matrix.o: s21_add_matrix.c s21_matrix.h
	$(CC) $(CFLAGS) -c s21_add_matrix.c -o s21_add_matrix.o

test: tests/tests.o tests/test_sub.o s21_matrix.a
	$(CC) $(CFLAGS) tests/tests.o tests/test_sub.o s21_matrix.a -o test $(shell pkg-config --cflags --libs check)

tests/tests.o: tests/tests.c tests/tests.h
	$(CC) $(CFLAGS) -c tests/tests.c -o tests/tests.o

tests/test_sub.o: tests/test_sub.c
	$(CC) $(CFLAGS) -c tests/test_sub.c -o tests/test_sub.o

clean:
	rm -f s21_matrix s21_matrix.a  *.o tests/*.o test
