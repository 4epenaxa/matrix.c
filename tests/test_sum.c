#include "tests.h"

START_TEST(test_sum_ok) {
  matrix_t A, B, C, RES;
  int cols = rand() % 100 + 1;
  int rows = rand() % 100 + 1;
  s21_create_matrix(rows, cols, &A);
  s21_create_matrix(rows, cols, &B);
  s21_create_matrix(rows, cols, &RES);

  for (int i = 0; i < A.rows; i++)
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i + j;
      B.matrix[i][j] = i - j;
    }
  for (int i = 0; i < RES.rows; i++)
    for (int j = 0; j < RES.columns; j++) RES.matrix[i][j] = i * 2;
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &C), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &RES), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&RES);
}
END_TEST

// START_TEST(test_sum_uninitialized) {
//   matrix_t A;
//   s21_create_matrix(2, 2, &A);
//   ck_assert_int_eq(s21_sum_matrix(NULL, NULL, &A), ERROR_MATR);
//   ck_assert_int_eq(s21_sum_matrix(NULL, &A, NULL), ERROR_MATR);
//   ck_assert_int_eq(s21_sum_matrix(&A, NULL, NULL), ERROR_MATR);
//   s21_remove_matrix(&A);
// }
// END_TEST

START_TEST(test_sum_rows) {
  matrix_t A, B, C;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(3, 2, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &C), ERROR_CALC);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sum_cols) {
  matrix_t A, B, C;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 3, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &C), ERROR_CALC);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *test_sum(void) {
  Suite *s = suite_create("\033[41m-=S21_ADDING=-\033[0m"RAINBOW_COLORS"test_sum_uninitialized");
  TCase *tc = tcase_create("s21_sum_tc");

  srand(time(NULL));

  tcase_add_loop_test(tc, test_sum_ok, 0, 97);
//   tcase_add_test(tc, test_sum_uninitialized);
  tcase_add_test(tc, test_sum_rows);
  tcase_add_test(tc, test_sum_cols);

  suite_add_tcase(s, tc);
  return s;
}
