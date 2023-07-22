#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (A->rows != B->rows || A->columns != B->columns)
    return FAILURE;  // Matrices have different dimensions
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      double diff = fabs(A->matrix[i][j] - B->matrix[i][j]);
      if (diff > 0.0000001)
        return FAILURE;  // Elements are not equal up to 7 decimal places
    }
  }
  return SUCCESS;  // Matrices are equal
}
