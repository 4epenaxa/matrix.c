#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (incorrect_matrix(A) || !result) return ERROR_MATR;
  if (A->rows != A->columns) return ERROR_CALC;
  s21_create_matrix(A->rows, A->columns, result);
  if (A->rows == 1) {
    result->matrix[0][0] = 1;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        matrix_t B;
        _create_minor(A, &B, i, j);
        double det;
        s21_determinant(&B, &det);
        result->matrix[i][j] = pow(-1, i + j) * det;
        s21_remove_matrix(&B);
      }
    }
  }
  return OK;
}

int _create_minor(matrix_t *A, matrix_t *result, int row, int column) {
  s21_create_matrix(A->rows - 1, A->columns - 1, result);
  for (int i = 0; i < result->rows; i++)
    for (int j = 0; j < result->columns; j++)
      result->matrix[i][j] = A->matrix[i + (i >= row)][j + (j >= column)];
  return OK;
}
