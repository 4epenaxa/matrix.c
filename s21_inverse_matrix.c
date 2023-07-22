#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (incorrect_matrix(A) || !result) return ERROR_MATR;
  if (A->rows != A->columns) return ERROR_CALC;

  int error = OK;
  double det = 0;
  s21_determinant(A, &det);
  if (det == 0) error = ERROR_CALC;
  if (!error) {
    matrix_t B, C;
    s21_calc_complements(A, &B);
    s21_transpose(&B, &C);
    s21_mult_number(&C, 1 / det, result);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
  }
  return error;
}
