#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define OK 0         /** OK value */
#define ERROR_MATR 1 /** Error, incorrect matrix*/
#define ERROR_CALC 2 /** Calculation error  */

typedef struct matrix_struct {
  double **matrix; /** Matrix array */
  int rows;        /** Number of rows */
  int columns;     /** Number of columns */
} matrix_t;

/** Creating matrices (create_matrix) */
int s21_create_matrix(int rows, int columns, matrix_t *result);

/** Zeroing matrices (Initialize matrices with 0)*/
void s21_clear_matrix(matrix_t *matrix);

/** Cleaning of matrices (remove_matrix) */
void s21_remove_matrix(matrix_t *A);

/** Matrix comparison (eq_matrix) */
#define SUCCESS 1 /** Equal */
#define FAILURE 0 /** Not equal */
int s21_eq_matrix(matrix_t *A, matrix_t *B);

/** Adding (sum_matrix) and subtracting matrices (sub_matrix) */
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/** Matrix multiplication by scalar (mult_number).
 * Multiplication of two matrices (mult_matrix) */
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/** Matrix transpose (transpose) */
int s21_transpose(matrix_t *A, matrix_t *result);

/** Minor of matrix and matrix of algebraic complements (calc_complements) */
int s21_calc_complements(matrix_t *A, matrix_t *result);

/** Matrix determinant */
int s21_determinant(matrix_t *A, double *result);

/** Inverse of the matrix (inverse_matrix) */
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif // S21_MATRIX_H