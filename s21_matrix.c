#include "s21_matrix.h"

int main() {
  return 0;
}

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = OK;
  if (rows <= 0 || columns <= 0) {
    error = ERROR_MATR;
  }
  if (error == OK) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)malloc(rows * sizeof(double *) + rows * columns * sizeof(double));
    if (!result->matrix) {
      error = ERROR_MATR;
    } else {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)(result->matrix + rows) + i * columns;
      }
      s21_clear_matrix(result);
    }
  }
  return error;
}

void s21_clear_matrix(matrix_t *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      matrix->matrix[i][j] = 0;
    }
  }
}

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL) {
    if (A->matrix != NULL) {
      free(A->matrix);
    }
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (A->rows != B->rows || A->columns != B->columns) {
    return FAILURE; // Matrices have different dimensions
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      double diff = fabs(A->matrix[i][j] - B->matrix[i][j]);
      if (diff > 0.0000001) {
        return FAILURE; // Elements are not equal up to 7 decimal places
      }
    }
  }

  return SUCCESS; // Matrices are equal
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A->rows != B->rows || A->columns != B->columns) {
    return ERROR_CALC; // Matrices have different dimensions
  }

  if (s21_create_matrix(A->rows, A->columns, result) != OK) {
    return ERROR_MATR; // Error creating result matrix
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }

  return OK;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A->rows != B->rows || A->columns != B->columns) {
    return ERROR_CALC; // Matrices have different dimensions
  }

  if (s21_create_matrix(A->rows, A->columns, result) != OK) {
    return ERROR_MATR; // Error creating result matrix
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }

  return OK;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (s21_create_matrix(A->rows, A->columns, result) != OK) {
    return ERROR_MATR; // Error creating result matrix
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = number * A->matrix[i][j];
    }
  }

  return OK;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A->columns != B->rows) {
    return ERROR_CALC; // Matrices cannot be multiplied
  }

  if (s21_create_matrix(A->rows, B->columns, result) != OK) {
    return ERROR_MATR; // Error creating result matrix
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      result->matrix[i][j] = 0;
      for (int k = 0; k < A->columns; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }

  return OK;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (s21_create_matrix(A->columns, A->rows, result) != OK) {
    return ERROR_MATR; // Error creating result matrix
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }

  return OK;
}