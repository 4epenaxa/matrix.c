#include "tests.h"

START_TEST(s21_equal) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  matrix_t A, B;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = random_double();
      B.matrix[i][j] = A.matrix[i][j];
    }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_not_equal) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  matrix_t A, B;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = random_double();
      B.matrix[i][j] = A.matrix[i][j];
    }
  int rand_row = rand() % rows;
  int rand_column = rand() % columns;
  while (fabsl(A.matrix[rand_row][rand_column] -
               B.matrix[rand_row][rand_column]) < 1e-7) {
    B.matrix[rand_row][rand_column] = random_double();
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_not_equal_rows) {
  matrix_t A, B;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(2, 1, &B);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 1; j++) {
      B.matrix[i][j] = random_double();
    }
  for (int i = 0; i < 1; i++)
    for (int j = 0; j < 1; j++) {
      A.matrix[i][j] = random_double();
    }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_not_equal_columns) {
  matrix_t A, B;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 2, &B);
  for (int i = 0; i < 1; i++)
    for (int j = 0; j < 2; j++) {
      B.matrix[i][j] = random_double();
    }
  for (int i = 0; i < 1; i++)
    for (int j = 0; j < 1; j++) {
      A.matrix[i][j] = random_double();
    }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *test_equal(void) {
  Suite *s = suite_create("\033[41m-=S21_EQUAL=-\033[0m"RAINBOW_COLORS);
  TCase *tc = tcase_create("s21_equal_tc");

  srand(time(NULL));

  tcase_add_loop_test(tc, s21_equal, 0, 99);
  tcase_add_loop_test(tc, s21_not_equal, 0, 99);
  tcase_add_test(tc, s21_not_equal_rows);
  tcase_add_test(tc, s21_not_equal_columns);

  suite_add_tcase(s, tc);
  return s;
}
