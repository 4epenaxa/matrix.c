# зададим переменную для компилятора:
CC=gcc
# зададим переменную для наших будущих флагов, пока минимальный набор:
CFLAGS = -Wall -Wextra -Werror -std=c11 -pedantic

all: s21_matrix

s21_matrix: s21_matrix.o s21_add_matrix.o
	$(CC) $(CFLAGS) s21_matrix.o s21_add_matrix.o -o s21_matrix

s21_matrix.o: s21_matrix.c s21_matrix.h
	$(CC) $(CFLAGS) -c s21_matrix.c -o s21_matrix.o

s21_add_matrix.o: s21_add_matrix.c s21_matrix.h
	$(CC) $(CFLAGS) -c s21_add_matrix.c -o s21_add_matrix.o

clean:
	rm -f s21_matrix  *.o
