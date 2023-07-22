#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (incorrect_matrix(A) || incorrect_matrix(B)) return ERROR_MATR;
  if (A->columns != B->rows)
    return ERROR_CALC;  // Matrices cannot be multiplied
  // if (s21_create_matrix(A->rows, B->columns, result) != OK)return ERROR_MATR;
  // // Error creating result matrix
  s21_create_matrix(A->rows, B->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      result->matrix[i][j] = 0;
      for (int k = 0; k < A->columns; k++)
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
    }
  }
  return OK;
}
