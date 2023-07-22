#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (incorrect_matrix(A) || A->rows != A->columns || !result)
    return ERROR_MATR;

  int n = A->rows;
  double det = 1.0;

  // Create a copy of the input matrix to avoid modifying the original
  matrix_t copy;
  s21_create_matrix(A->rows, A->columns, &copy);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      copy.matrix[i][j] = A->matrix[i][j];
    }
  }
  for (int k = 0; k < n; k++) {
    // Find the pivot row
    int pivot_row = k;
    for (int i = k + 1; i < n; i++) {
      if (fabs(copy.matrix[i][k]) > fabs(copy.matrix[pivot_row][k])) {
        pivot_row = i;
      }
    }

    // Swap rows if necessary
    if (pivot_row != k) {
      for (int j = 0; j < n; j++) {
        double temp = copy.matrix[k][j];
        copy.matrix[k][j] = copy.matrix[pivot_row][j];
        copy.matrix[pivot_row][j] = temp;
      }
      det *= -1;
      // Change sign after row swap
    }

    // Check for singular matrix (det = 0)
    if (fabs(copy.matrix[k][k]) < 1e-10) {
      s21_remove_matrix(&copy);
      *result = 0.0;
      return OK;
    }

    // Perform row elimination
    for (int i = k + 1; i < n; i++) {
      double factor = copy.matrix[i][k] / copy.matrix[k][k];
      for (int j = k; j < n; j++)
        copy.matrix[i][j] -= factor * copy.matrix[k][j];
    }
  }

  // Calculate the determinant as the product of the diagonal elements
  for (int i = 0; i < n; i++) {
    det *= copy.matrix[i][i];
  }
  s21_remove_matrix(&copy);
  *result = det;
  return OK;
}
