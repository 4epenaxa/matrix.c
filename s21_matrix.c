#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0) return ERROR_MATR;
  result->rows = rows;
  result->columns = columns;
  result->matrix = (double **)malloc(rows * sizeof(double *) +
                                     rows * columns * sizeof(double));
  if (!result->matrix)
    return ERROR_MATR;
  else {
    for (int i = 0; i < rows; i++)
      result->matrix[i] = (double *)(result->matrix + rows) + i * columns;
    s21_clear_matrix(result);
  }
  return OK;
}

void s21_clear_matrix(matrix_t *matrix) {
  for (int i = 0; i < matrix->rows; i++)
    for (int j = 0; j < matrix->columns; j++) matrix->matrix[i][j] = 0;
}

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL) {
    if (A->matrix != NULL) free(A->matrix);
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
}

// additional func
int incorrect_matrix(matrix_t *A) {
  if (!A) return 1;
  // else if (A->rows < 1) return 1;
  // else if (A->columns < 1) return 1;
  // else if (!A->matrix) return 1;
  // return !A || A->rows < 1 || A->columns < 1 || !A->matrix;
  return 0;
}

void from_array_to_matrix(matrix_t *A, const double *arr) {
  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++)
      A->matrix[i][j] = arr[i * A->columns + j];
}
